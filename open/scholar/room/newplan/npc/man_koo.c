//by sueplan
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_ans1();
string do_ans2();
string do_ans3();
string do_ans4();
string do_boot1();


void create() {
        set_name("»ÆÊ¯¹«",({"old-man koo","koo","old-man"}));
        set("class","scholar");
        set("nickname","$HIC$²ßÄ±×ÚÊ¦$NOR$");
        set("title","[1;37mÆæÂÔ[0m");
        set("long",
"»ÆÊ¯¹«Îªµ±´úÖøÃûÖ®±ø·¨¼Ò, ×ÅÓĞÁùèºÒ»Êé, 
Ó°ÏìºóÊÀÉõÉî, ²»¹ı¿´ËûºÃÏñÓĞµã·³ĞÄÊÂà¸¡£
");
        set("inquiry", ([
        "Áùèº"       : (: do_ans1 :),
        "²»¹ı"       : (: do_ans2 :),
        "Ì«¹«Íû"     : (: do_ans3 :),
        "ÔÆÉ½"       : (: do_ans4 :),
      "·³ĞÄÊÂ"     : (: do_boot1 :),
]));
        set("str",40);
        set("cor",25);
        set("gender","ÄĞĞÔ");
        set("attitude","heroism");
        set("family/family_name","ÈåÃÅ");
        set("max_gin",5000);
        set("max_kee",8000);
        set("max_sen",8000);
        set("max_force",8000);
        set("force",2000);
        set("force_faxtor",20);
        set("combat_exp",5000000);
        set_skill("stabber",120);
        set_skill("dodge",120);
        set_skill("move",120);
        set_skill("parry",120);
        set_skill("stabber",200);
        set_skill("knowpen",100);
        set_skill("god-plan",100);
        set_skill("plan",120);
        set_skill("force",200);
        set_skill("poetforce",150);
        set_skill("winter-steps",100);
        map_skill("plan","god-plan");
        map_skill("dodge","winter-steps");
        map_skill("move","winter-steps");
        map_skill("stabber","knowpen");
        map_skill("parry","knowpen");
        set("functions/movedown/level",100);
        set("functions/finger/level",100);
set("chat_chance_combat", 100);
set("chat_msg_combat",({
(: perform_action("stabber.movedown") :),
(: perform_action("stabber.finger") :),
}));
        set("chat_chance",50);
        set("chat_msg",({
        }));
        setup();
       carry_object("/open/scholar/obj/silver-pen")->wield();
       add_money("gold",50);
 }
string do_boot1()
{
        object me=this_player();
        if(me->query("family/family_name")=="ÈåÃÅ")
          {
	     if( me->query_temp("get_boots")==3)
                {
                 return("¨ß..Ã»ÊÂÇéÀ²!!");
         }
               if( me->query_temp("get_boots")==1)
	        {
                 return("ÄÜÔÚ°ïÎÒÄÃÒ»´ÎĞ¬Âğ??ÔÚÍ¬Ò»¸öµØ·½");
	        }
             if( me->query_temp("get_boots")==2)
	        {
                 return("ÄÜÔÚ°ïÎÒÄÃµÚÈı´ÎĞ¬Âğ??ÔÚÍ¬Ò»¸öµØ·½");
	        }
             if( !me->query_temp("get_boots"))
		{
          me->set_temp("ask_thing_ok",1);
	        return("ÄãÄÜ°ïÎÒÄÃÎÒµÄĞ¬×ÓÂğ?ÎÒµÄĞ¬×ÓµôÁË!!");
		}
        }
        else
          return("¨ß??Äã²»ÊÇÈåÃÅµÄ°É??");
}
string do_ans1()
{
        object me=this_player();
        if(me->query("combat_exp")<7000000)
        {
        return "ÄãµÄ¾­ÑéÖµÒªµ½Æß°ÙÍò²ÅÄÜÖªµÀÓĞ¹ØÁùèºµÄÊÂÇé";
        }
        if( me->query("family/family_name")=="ÈåÃÅ" && me->query_temp("get_boots")==3)
        {
          me->set_temp("six_ask",1);
        return("
          ÁùèºÄËÊÇÎÒÊÕ¼¯´ºÇïÕ½¹ú¸÷´óÕ½²ßÆæÄ±
          ÀïÃæ¼Ç×Å²»ÉÙµÄÖØÒª±ø·¨, ²»¹ı....¡£");
}
else
        return("Á¬Áùèº¶¼²»ÖªµÀ??±ğÔÚºÍÎÒËµ»°À²....");
}
string do_ans2()
{
        object me=this_player();
        if(me->query_temp("six_ask")==1)
        {
          me->set_temp("six_ask",2);
          return("
          Õâ±¾ÊéÏÖÔÚ²»ÔÚÎÒÕâ±ß, ÎÒ°ÑËûÔùËÍÓÚ
          ×ãÖÇ¶àÄ±µÄ¾üÊ¦½ª×ÓÑÀ - Ì«¹«ÍûÁË¡£
          ");
        }
        else
          return("ÕâÊÂºÍÄãÎŞ¹Ø°É??");
}          
string do_ans3()
{
        object me=this_player();
        if( me->query_temp("six_ask")==2)
        {
          me->set_temp("six_ask",3);
          return("
          ËûÊÇÎÒËù¿´ÖĞµÄÌì²Å²ßÄ±¼Ò, ÄÜÁ¦¸üÔÚ
          ÎÒÖ®ÉÏÁ¨, ÎÒµÄÁùèº½»¸øËûÖ®ºó, Ëü²»
          µ«½«ËùÓĞµÄ²ßÄ±¿´¹ıºó²¢¼ÓÒÔ¸ÄÁ¼, ±È
          ±ÈÎÒËùÖøÖ®Áùèº¸üÎªÓĞÓÃ, Ëû°ïÖÜÍõ³¯
          Æ½¶¨½­É½ºó, ¾ÍÒş¾ÓÓÚÔÆÉ½ÖĞ¡£");
        }
        else
          return("ÍôÍô??ÊÇ¹·Âğ???");
}
string do_ans4()
{
        object me=this_player();
        if( me->query_temp("six_ask")==3)
        {
          me->set_temp("six_ask",4);
          return("
          ÄêÇáÈË, Äã²»ÖªµÀÔÆÉ½ÔÚÄÇÂğ? ºÃ°É!!
          ÔÆÉ½ÊÇÔÚ³¤É³³Ç¸½½üµÄµØ·½, ÄãÈ¥ÕÒÕÒ
          °É¡£");
        }
        else
          return("¿´ÈÕ³ö??¡£");
}
int accept_object(object me, object obj)
{
        if( obj->query("id") == "small boots" )
        {
          command("pat "+getuid(me));
          command("say Ì«ºÃÁË, °ïÎÒ¼ñÁËĞ¬×Ó, Ğ»ÁË¡£");
        if( me->query("family/family_name") == "ÈåÃÅ" || me->query_temp("get_boots")<3)
          {
            command("say ºÇºÇ, ÕæµÄ¸ĞĞ»Äã†ª, ÒÔºóÇëÄã¶à¶à°ïÎÒ¼ñĞ¬×Ó¡£");
            write(this_object()->query("name")+"¿´×ÅĞ¬×Ó»º»º´©ÉÏ¡£\n\n"+
            "²»¹ıÁ³ÉÏÈ´³öÏÖÁËÓĞµã¶ñ×÷¾çµÄ±íÇé¡£\n\n");
            me->add_temp("get_boots",1);
          }
          else
          {
          command("say ÎÒ¿É²»ÒªÄÇÃ´¶àĞ¬×Óà¸!!");
          }
          destruct(obj);
        }
        else
        {
        command("say ¸ÉÂï??");
        }
        return 1;
}
void init()
{
                object ob;
        ::init();
if(interactive(ob =this_player()) && !is_fighting() ) {
//             remove_call_out("greeting");
//             call_out("greeting",2,ob);
        }
add_action("do_nod","nod");
}
int do_nod()
{
        object ob = this_object() , me = this_player();
        if( me->query_temp("get_boots")==3) return 0;
        if( me->query("family/family_name")!="ÈåÃÅ") return 0;
        if(!me->query_temp("ask_thing_ok")) return 0;
        if(me->query_temp("get_boots")==3) return 0;
        command("say ÎÒµÄĞ¬×ÓµôÔÚ¶«ÄÏ·½µÄÇÅÏÂ, ÇëÄã°ïÎÒ¼ñ»ØÀ´¡£");
         me->set_temp("can_get",1);
        message_vision("$N¶Ô$nÎ¢Î¢Ğ¦×Å¡£\n",ob,me);
        return 1;
}
void greeting(object ob)
{
  if(ob->query_temp("get_boots")==3)
  {
        command("hmm");
        command("say ÄêÇáÈË, ÄãÕæµÄºÜÓĞÄÍĞÔ!!");
        command("say ÄãÒªÎÊÎÒÊ²Ã´ÊÂÄØ??");
  }
}
