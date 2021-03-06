// master.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

// 此 npc 为门派 master 请勿随意更动  (fund)
void create()
{
        set_name("神秘老人",({"oldman"}));
	set("gender", "男性" );
	create_family("魔刀莫测",1," ");
            set("title","");
         set("age",70);
      set("str",30);
	set("cor", 30);
	set("cps", 27);
	set("int", 24);

	set("max_force",2000);
	set("force",2000);
           set("force_factor",10);


       set("long","一个看起来全身脏盻盻的老人，脚上还有一个脚铐，看起来像是被关在这里的。\n");

	set_skill("force",70);
            set_skill("blade",100);
	set_skill("unarmed",60);
	set_skill("dodge",70);
             set_skill("literate",60);
	set_skill("powerforce",100);
	set_skill("dragon-blade",120);
	map_skill("blade","dragon-blade");
	map_skill("force","powerforce");

	set("combat_exp", 1000000);
	set("score", 200000);
	set("chat_chance_combat",60);
	set_temp("apply/armor",80);
	set_temp("apply/damage",80);
         set("chat_msg_combat",({
	(: perform_action, "blade.power-dest" :),
      }));




	set("inquiry", ([
	    "独孤愁":  "这个老贼用暗招，把我关在这十几年，这个仇....我一定要报！\n",
	    "脚铐": "这个脚铐是用千年寒铁石打造的，一般兵器是砍不断的。\n",
	    "千年寒铁石": "这是经过千年孕育而成的坚硬石块，除非有神兵利器，不然无法砍断。\n",
	    "神兵利器": "听说人间至宝「金鳞蟒邪”配上「天邪石”可以毁灭千年寒铁石。\n",
	    "金鳞蟒邪":  "听说金鳞蟒邪好像落在茅山派手上。\n",
	    "天邪石":   "天邪石在独孤愁这个老贼手里！！！\n",
	]) );

	setup();
	carry_object("/open/snow/obj/poor_blade")->wield();
}

void init()
{
     add_action("do_learn","learn");
}
void attempt_apprentice(object ob,string str)
{
         if(this_player()->query("can_apprentice")==2)
         {
             command("say 你我无缘，你走吧！");
             return;
         }
	if(this_player()->query("can_apprentice")!=1)
          {
          command("say 滚！你给我滚开！\n");
          return;
          }
           command("say 凡我门徒，不得将我绝学再传他人。");
	command("recruit "+this_player()->query("id"));
              this_player()->set("family/master_name","莫测");
              this_player()->set("title","魔刀传人");
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
            ob->set("class","blademan");
}
int accept_object(object who,object ob)
{
    string ob_id;
    ob_id=ob->query("id");
      if(this_player()->query("can_apprentice")!=0)
                  return 1;
      if(ob_id=="snake sword")
     {
        command("hmm");
             this_player()->set("give_1",1);
     }
        if(ob_id=="stone")
         {
             command("hmm");
            this_player()->set("give_2",1);
         }
       if(who->query("give_1")==1&&who->query("give_2")==1)
        {
            command("say 太好了！");
            message_vision(
             HIY "$n将天邪石的神力注入金鳞蟒邪之中，然后运劲一砍，将脚铐砍断。\n" NOR,this_player(),this_object());
            shout(HIR "远处传来魔刀莫测的大喝：\n\n我自由了！哈哈哈哈！！！\n\n独孤愁！你这个老贼等者吧！我要一雪这十几年禁锢之恨！\n" NOR);
       if(who->query("kar")>25)  who->set("can_apprentice",1);
           else who->set("can_apprentice",2);
         command("say 非常感谢你帮我重获自由。");
       if(this_player()->query("can_apprentice")==1)
             command("say 莫某愿将毕生所学传与你。\n");
      if(this_player()->query("can_appentice")==2||this_player()->query("id")=="per")
       {
           command("say 但莫某觉的我俩并不有缘");
           command("say 好吧！我将部分内力传给你。");
           this_player()->add("max_force",100);
           this_player()->add("force",100);
        }
            }
          return 1;
}
