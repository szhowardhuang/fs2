#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ÁÖºêÉı",({"master lin","master","lin"}));
	set("long","Ã»ÓĞÈËÖªµÀËûµÄÀ´Àú£¬Ò²Ã»ÈËÖªµÀËûµÄÎä¹¦ÓĞ¶àÉî£»ÊÇÒ»¸öÉñÃÜÄª²âµÄÈËÎï£¬"+
"ÔÚÈıÄêÇ°Òò·çÔÆ¼Ê»á£¬Ê¹Ëû´´Á¢ÁË¡²Ê¥»ğ½Ì¡³£¬Ò²²»ÖªËûÊÇÓÃºÎ·½·¨½¨Á¢Õâ¸öÅÓ´óµÄ×éÖ¯£¬"+
"Ò²ÒòÎªÈç´Ë, Ëû±»½­ºşÉÏµÄÈË³ÆÎª¡²ÎäÁÖÉñ»°¡³¡£\n");
	set("gender","ÄĞĞÔ");
	set("class","prayer");
 	set("nickname","ÎäÁÖÉñ»°");
        set("title","Ê¥»ğ½Ì»Ê¡«¡«");
        set("combat_exp",5000000);
        set("attitude","heroism");
	set("age",75);
        set("max_kee",10000);
	set("str", 50);
	set("cor", 50);
	set("cps", 45);
	set("per", 30);
	set("int", 42);
	set("force",20000);
	set("max_force",20000);
	set("force_factor", 100);
        set("max_gin",2800);
        set("max_sen",2800);
        	set_skill("superforce", 180);
        	set_skill("cure", 120);
        	set_skill("dodge", 150);
	set_skill("force",180);
        	set_skill("move", 150);
        	set_skill("parry", 150);
        	set_skill("stick",150);
        	set_skill("unarmed",150);
        	set_skill("array",150);
        	set_skill("literate",150);
	set_skill("fire-catch",150);
	set_skill("shift-steps",150);
        	set_skill("universe",150);
        	map_skill("force","superforce");
	map_skill("dodge","shift-steps");
	map_skill("move","shift-steps");
	map_skill("parry","universe");
        	map_skill("stick","fire-catch");
        	map_skill("unarmed","universe");
        	set("functions/blood/level",60);
	set("chat_chance_combat", 40);
        	set("chat_msg_combat", ({
		(: perform_action("force.ball") :),
		(: perform_action("force.hand") :),
		(: perform_action("force.sword") :),
		(: exert_function("blood") :),
        }));
	setup();
	carry_object("/u/k/kael/fire-cmd");
	add_money("thousand-cash",10);
	create_family("Ê¥»ğ½Ì",1,"½Ì»Ê");
}

void init()
{
     	add_action("do_join","join");
    	add_action("do_select","select");
            add_action("do_verify","verify");
}

int do_verify(string arg)
{
 object me,ob;
me=this_player();
ob=new("open/sword/obj/b1");
if( arg!="prayer")
  {
    write("ÄãÒªÉêÇëÊ²Ã´\n");
    return 1;
   }
if(me->query("family/family_name")!="Ê¥»ğ½Ì")
  {
    write("Ö»ÓĞÊ¥»ğ½ÌÍ½²Å»áÓĞĞÅÎï\n");
    return 1;
  }

 if( present(ob,me) )
  {
    write("ÄãÒÑ¾­ÉêÇë¹ıÁË\n");
      return 1;
   }
   else
    {
     write("ÕâÊÇÊ¥»ğ½ÌµÄĞÅÎï ,ÍûÄãºÃºÃ±£´æ ,ÇĞÎğÒÅÊ§ÁË\n");
      ob->move(me);
         return 1;
         }
     }

void attempt_apprentice(object ob)
{
	if(ob->query("marks/Ê¥»ğ°ËÌìÃÅ")==1)
	{
	if((int)this_player()->query("combat_exp")<=500000)
     	return notify_fail(command("say ºÃºÃ¸ú×ÅÄã×Ô¼ºµÄÊ¦¸¸¶àÑ§¼¸Äê°É!"));
	command("look "+ob->query("id"));
	command("pat");
	command("say ºÃ,Äã¹ûÈ»ÊÇ¿ÉÔìÖ®²Å,Äã¿ÉÒÔÈ¥ÕÒÈıÎ»³¤ÀÏ×÷ÎªÄãÎäÑ§µÄÖ¸µ¼!");
	ob->delete("family");
	command("say ÄãÏëÑ¡Ôñ(select)ÄÄÒ»Î»³¤ÀÏÄØ?");
	command("say ´«¹¦³¤ÀÏ(gonfu_elder)£¬Ö´·¨³¤ÀÏ(lawyer_elder)»¹ÊÇ½äÂÉ³¤ÀÏ(behavior_elder)£¿");
	ob->set_temp("allow_select",1);
	return 1;
            }
	if(ob->query("marks/Ê¥»ğÈı³¤ÀÏ")==1)
	{
	if((int)this_player()->query("combat_exp")<=1800000)
     	return notify_fail(command("say ÒÔÄãµÄ³Ì¶È»¹²»¹»×Ê¸ñ¸úÎÒÑ§Ï°ÎäÑ§Óë½ÌÎñµÄ´¦Àí°É!"));
	command("look "+ob->query("id"));
	command(":)");
	command("say ºÃ,Äã¹ûÈ»²»ÊÇ·º·ºÖ®±²,Äã¿ÉÒÔÈ¥ÕÒ½ÌÄÚµÄÎÄÎäĞÇ¾ı×÷ÎªÄãÎäÑ§µÄÖ¸µ¼!");
	ob->delete("family");
	command("say Äã¿ÉÒÔÑ¡ÔñÎäĞÇ¾ı(warrior)»òÊÇÎÄĞÇ¾ı(literate)");
	ob->set_temp("allow_select",1);
	return 1;
            }
	if(ob->query("marks/ÎÄÎäĞÇ¾ı")==1)
	{
	if((int)this_player()->query("combat_exp")<=3500000)
     	return notify_fail(command("say ºÃºÃ¸ú×ÅÎÄÎäĞÇ¾ı¶àÄ¥Á·Ä¥Á·°É!"));
	command("look "+ob->query("id"));
	command("pat"+ob->query("id"));
	command("say ºÃ,Äã¹ûÈ»ÊÇ¿ÉÔìÖ®²Å,´Ó½ñºó¾ÍÓÉ±¾½ÌÖ÷Ç××Ô½Ìµ¼!");
	ob->delete("family");
	command("recruit "+this_player()->query("id"));
	message("mud",HIW"¡²Ê¥»ğ½Ì»Ê¡³ÁÖºêÉıĞ¦µÀ:\n 
	¹ş¹ş¹ş¹ş....±¾½ÌÖ÷ÊµÔÚÌ«¸ßĞËÀ²!\n
	Ê¥»ğ½ÌÍ½,"+this_player()->name()+": ½ñºó¾Í¸ú×Å±¾½ÌÖ÷ºÃºÃÑ§Ï°ÈçºÎ¹ÜÀí½ÌÎñ°É.\n"NOR,users());
	ob->set("marks/Ê¥»ğ½ÌÖ÷",1);
      ¡¡ob->set("title","[31mÊ¥»ğ½ÌµÕ´«µÜ×Ó[0m");
	return 1;
	}
        command("hmm");
	command("say ÎÒ½ÌÎñ·±Ã¦ ,ÄãÈ¥ÕÒÊ¥»ğ°ËÌìÃÅµÄÃÅÖ÷°É !");
	command("say ÄãÏë½øÈë(select)ÄÄÒ»ÃÅÄØ?");
	command("say Äã¿ÉÒÔÑ¡ÔñÌì»úÃÅ(tangi)£¬ÌìÊàÃÅ(tanshu)£¬ÌìÈ¨ÃÅ(tanchun)");
	command("say Äã¿ÉÒÔÑ¡ÔñÌìè¯ÃÅ(tanshun)£¬ÓñºâÃÅ(uhen)£¬¿ªÑôÃÅ(kiyan)");
	command("say Äã¿ÉÒÔÑ¡ÔñÑş¹âÃÅ(youkoun)£¬ÕóÊÆÃÅ(zhenche)");
	ob->set_temp("allow_select",1);
            }

int do_join()
	{
	if(this_player()->query("class"))
		return notify_fail("ÄãÒÑ¾­¼ÓÈëÆäËû¹¤»áÁË¡£\n");
	this_player()->set("class","prayer");
	message("mud",HIW "ÁÖºêÉı×İÉù´óºô :\n
	»¶Ó­" +this_player()->name()+"¼ÓÈëÊ¥»ğ½Ì¹«»á!!\n\n"NOR,users());
	return 1;
}
int do_select(string str)
	{
	object who;
	who=this_player();
	if(!who->query_temp("allow_select"))
	{
	command("say ÎÒÓÖÃ»´ğÓ¦ÈÃÄãÌô? ");
	return 1;
	}
	if(who->query_temp("have_say")==1)
	{
	message_vision(sprintf(HIC"$NËµµÀ£º"+str+"\n"NOR),who);
	command("say Äã²»ÊÇÌô¹ıÁË?");
	return 1;
	}
	if(str=="Ìì»úÃÅ" ||  str == "tangi")
        {
	 message_vision(HIC"$NËµµÀ£ºÌì»úÃÅ\n"NOR,who);
	this_player()->set_temp("allow_1",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÈ¥¼ÓÈëÌì»úÃÅ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "ÌìÊàÃÅ" || str == "tanshu")
	{
	message_vision(HIC"$NËµµÀ£ºÌìÊàÃÅ\n"NOR,who);
	this_player()->set_temp("allow_2",1);
	command("smile");
	command("say àÅ ,Äã¾Í¼ÓÈëÌìÊàÃÅ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "ÌìÈ¨ÃÅ" || str == "tanchun")
	{
	message_vision(HIC"$NËµµÀ£ºÌìÈ¨ÃÅ\n"NOR,who);
	this_player()->set_temp("allow_3",1);
	command("smile");
	command("say àÅ ,Äã¾Í½øÈ¥ÌìÈ¨ÃÅĞŞÁ·°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "Ììè¯ÃÅ" || str == "tanshun")
	{
	message_vision(HIC"$NËµµÀ£ºÌìè¯ÃÅ\n"NOR,who);
	this_player()->set_temp("allow_4",1);
	command("smile");
	command("say àÅ ,Äã¾Íµ½Ììè¯ÃÅºÃºÃÄ¥Á·°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "ÓñºâÃÅ" || str == "uhen")
	{
	message_vision(HIC"$NËµµÀ£ºÓñºâÃÅ\n"NOR,who);
	this_player()->set_temp("allow_5",1);
	command("smile");
	command("say àÅ ,Äã¾Í¼ÓÈëÓñºâÃÅ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "¿ªÑôÃÅ" || str == "kiyan")
	{
	message_vision(HIC"$NËµµÀ£º¿ªÑôÃÅ\n",who);
	this_player()->set_temp("allow_6",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÇ°Íù¿ªÑôÃÅÑ§Ï°°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "Ñş¹âÃÅ" || str == "youkoun")
	{
	message_vision(HIC"$NËµµÀ£ºÑş¹âÃÅ\n"NOR,who);
	this_player()->set_temp("allow_7",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÇ°È¥Ñş¹âÃÅ°İÊ¦Ñ§ÒÕ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "ÕóÊÆÃÅ" || str == "zhenche")
	{
	message_vision(HIC"$NËµµÀ£ºÕóÊÆÃÅ\n"NOR,who);
	this_player()->set_temp("allow_8",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÇ°È¥ÕóÊÆÃÅ°İÊ¦Ñ§ÒÕ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "´«¹¦³¤ÀÏ" || str == "gonfu" || str == "gonfu_elder")
	{
	message_vision(HIC"$NËµµÀ£º´«¹¦³¤ÀÏ\n"NOR,who);
	this_player()->set_temp("allow_9",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÈ¥´«¹¦³¤ÀÏÄÇ¶ùÑ§ÒÕ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "Ö´·¨³¤ÀÏ" || str == "lawyer" || str == "lawyer_elder")
	{
	message_vision(HIC"$NËµµÀ£ºÖ´·¨³¤ÀÏ\n"NOR,who);
	this_player()->set_temp("allow_10",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÈ¥Ö´·¨³¤ÀÏÄÇ¶ùÑ§ÒÕ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "½äÂÉ³¤ÀÏ" || str == "behavior" || str == "behavior_elder")
	{
	message_vision(HIC"$NËµµÀ£º½äÂÉ³¤ÀÏ\n"NOR,who);
	this_player()->set_temp("allow_11",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÈ¥½äÂÉ³¤ÀÏÄÇ¶ùÑ§ÒÕ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "ÎäĞÇ¾ı" || str == "warrior")
	{
	message_vision(HIC"$NËµµÀ£ºÎäĞÇ¾ı\n"NOR,who);
	this_player()->set_temp("allow_12",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÈ¥ÎäĞÇ¾ıÄÇ¶ùÑ§ÒÕ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "ÎÄĞÇ¾ı" || str == "literate")
	{
	message_vision(HIC"$NËµµÀ£ºÎÄĞÇ¾ı\n"NOR,who);
	this_player()->set_temp("allow_13",1);
	command("smile");
	command("say àÅ ,Äã¾ÍÈ¥ÎÄĞÇ¾ıÄÇ¶ùÑ§ÒÕ°É!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	command("say Ã»ÕâÈË!");
	return 1;
	}
void greeting(object ob)
{
	if (ob->query_skill("coldpoison", 1))
//	if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
      {
       command("say ½ÌÖ÷ÓĞÁî£¡£¡·²ÊÇÑ§ÓĞ¶¾ÊõÖ®ÈË£¬É±ÎŞë·£¡£¡");
        kill_ob(ob);
     }
       if( ob->query("class")=="dancer")
        {
        command("say ½ÌÖ÷ÓĞÁî£¬¼ûµ½ÎèÕß-----¸ñÉ±ÎğÂÛ£¡£¡");
        kill_ob(ob);
     }
    return;
}
  
