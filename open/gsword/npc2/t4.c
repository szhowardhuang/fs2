inherit NPC;
#include <ansi.h>
#include "/open/open.h"
string test();
void create()
{
        set("title",HIR"第三试炼者"NOR),
        set_name(HIC"仙剑武神"NOR,({"gman"}));
        set("class","swordsman");
        create_family("仙剑派",2,"长老");
        set("family/master_name","逍遥子");
        set("family/family_name","仙剑派");
        set("attitude","heroism");
        set("env/连击","YES");
        set("gender","男性");
        set("age",200);
        set("str",40);
        set("con", 50);
        set("int", 30);
        set("cps", 40);
        set("cor", 40);
        set("kar",50);
        set("long","仙剑试炼之最终武者,据说乃由天地灵气所化之幻影,你必须通过他的测试(test_accept)才能完成仙剑最终试炼。\n");
        set("combat_exp",4000000);
        set("max_gin",10000);
        set("gin",10000);
        set("max_kee",25000);
        set("max_force",30000);
        set("force",30000);
        set("kee",25000);
        set("max_sen",10000);
        set("sen",10000);
        set("bellicosity",3000);
        set("functions/swordkee/level",100);
        set("functions/godsub/level",100);
        set("functions/sha_kee/level",100);
        set("functions/sunswordkee/level",100);
        set_skill("dodge",150);
        set_skill("unarmed",200);
        set_skill("parry",120);
        set_skill("sword",170);
        set_skill("shasword",150);
        set_skill("sha-steps",100);
        set_skill("fireforce",250);
        set_skill("sun_fire_sword",100);
        set_skill("force",300);
        set_skill("array",100);
        set_skill("sha-array",100);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("force","fireforce");
        map_skill("sword","shasword");
        map_skill("parry","sun_fire_sword");
        set("force_factor",20);
        set("inquiry",([
  "试炼" : (:test:),
]));
set("get_sha_sp", 1);
set("quests/sunfire",1);
set("quest/new_gold_fire",1);
set("chat_msg_combat",({
 (: perform_action,"sword.sha_kee" :)
  }));
setup();
carry_object("/u/a/appo/obj/sadsword.c")->wield();
carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
carry_object("/open/gsword/obj1/ring.c")->wear();

        add_money("gold",5);
}
int accept_fight(object who)
{
  object ob = this_object() , me = this_player();
  command("say 注意来...");
  fight_ob(who);
  me->delete_temp("3rdtest");
  command("perform sun_fire_sword.sunswordkee");
return 1;
}
int accept_kill(object who)
{
  object ob = this_object() , me = this_player();
  command("say 注意来...");
  kill_ob(me);
  me->delete_temp("3rdtest");
  command("perform sun_fire_sword.sunswordkee");
  return 1;
}
void init() 
{

  object obj;
  ::init();
  if(interactive(obj=this_player()) && !is_fighting())
     {
      remove_call_out("greeting");
      call_out("greeting",1,obj);
     }
add_action("do_test","test_accept");
}

void greeting(object ob)
{
        command("wear all");
}
int do_test()
{
  object ob = this_object() , me = this_player();
  if( !is_fighting() )
  {
   if(ob->query("eff_kee") < ob->query("max_kee")/2 )
  {
  command("say 让我休息一下吧");
  }
  else
  {
  command("say 注意来...");
  me->set_temp("3rdtest",1);
  kill_ob(me);
  }
  }
  else
  {
  command("say 烦阿.一直来...看我的");
  kill_ob(me);
  me->delete_temp("3rdtest");
  command("perform sun_fire_sword.sunswordkee");
  }
  return 1;
}

string test()
{
   tell_object(this_player(),HIW"此关在测试你的武术基础..你得打败我.才能过关。\n"NOR);
   return("你可以利用test_accept来向我挑战");
}
void heart_beat()
{
        if( !is_fighting() ) {
                if( query("sen") < query("eff_sen") ) // 125
                        command( "exert refresh" );
                if( query("force") < query("max_force") ) // 1 -> 5.035
                        command( "ex 400" );
                if( query("eff_kee") < query("max_kee") ) // 35
                        command( "20 exert heal" );
                if( query("gin") < query("eff_gin") ) // 125
                        command( "exert regenerate" );
                if( query("kee") < query("eff_kee") ) // 125 -> 300
                        command( "7 exert recover" );

        }
        ::heart_beat();
}
void unconcious ()
{
   object winner = query_temp("last_damage_from");
    if(!winner) :: unconcious();
    {
       if(winner->query_temp("/3rdtest")==1)
       {
       winner->set("quests/yan",5);
       tell_object(winner,HIW"你已经通过仙剑试炼了..我直接将你送回蜀山。\n"NOR);
       message("system",this_player()->name()+HIY"已通过仙剑试炼,成为一代宗师。\n"NOR,users());
       winner->set("title","[1;36m仙剑圣者[0m");
       winner->move("/open/gsword/room/su3");
       destruct (this_object ());
       }
       else
       {
       tell_object(winner,HIW"哈哈~~~你用投机的方式是无法得到我的认同的。\n"NOR);
       destruct (this_object ());
       }
    }
 ::die();
}
