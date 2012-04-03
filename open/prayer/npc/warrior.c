#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_man()
{
        object ob=this_player();
       if( ob->query_temp("high-man") == 1 )
       {
       ob->set_temp("high-man", 2);
       return("\nÎÒÓëÒåĞÖÊÇÔÚ 30 ÄêÇ°ÏàÊ¶µÄ, µ±Ê±ËûÔøÓëÎÒ¹²×íÒĞºìÂ¥!!ÓÉÓÚĞÔÇéÏàÍ¶, ÎÒÃÇ¾Í½á°İÎªĞÖµÜÁË!!ËûÒş¾ÓÖ®ºó, ËÄ´¦Îª¼Ò, 3 ÄêÇ°ÎÒ½Ì³¤ÀÏÔø¼ûµ½ËûÒ»Ãæ!!\n");
       }
       else
       {
       return("\nÕâÎ»Ğ¡ÅóÓÑ, ÄÑµÀÄãÖªµÀ [µ¶Éñ½£ÏÉÊ®Èı±Ş] ÏÖÏÂÓÚºÎ´¦Âä½ÅÂğ??\n");
       }
}




void create()
{
        set_name("³ÂÈÙÖÓ", ({"warrior cheng","warrior","cheng"}));
        set("long",@LONG

        Ê¥»ğ½ÌµÄ¸±½ÌÖ÷£¬½ÌÍ½ÃÇ³ÆºôËûÎª[ÎäĞÇ¾ı]£®ËûÉí³¤
        °Ë³ß£¬Å¨Ã¼´óÑÛ£¬ÓÈÆäÊÇËûÄÇÒ»Á³µÄÂäÈùºú£¬¸üÊÇ³Ä
        ÍĞ³öËûÄÇ¾¼¾¼ÓĞÁ¦µÄÄ£Ñù£®ÊÇ½ÌÖ÷µÄ×óÓÒÊÖÖ®Ò»£¬¶Ô
        ÓÚÎäÑ§µÄÑĞ¾¿ÔòÊÇ¼¸ºõÒÑ¾­µ½ÁË·¢³ÕµÄµØ²½ÁË£¡

LONG);
        set("nickname","ÎäĞÇ¾ı");
        set("gender","ÄĞĞÔ");
        set("class","prayer");
        set("family/master_name","ÁÖºêÉı");
        set("combat_exp",2000000);
        set("attitude","heroism");
        set("age",65);
        set("title","Ê¥»ğ½Ì¸±½ÌÖ÷");
        set("kee",6000);
        set("max_kee",6000);
        set("force",10000);
        set("max_force",10000);
        set("force_factor",25);
        set_skill("cure", 60);
        set_skill("superforce", 95);
        set_skill("holy-force", 100);
        set_skill("dodge", 85);
        set_skill("force",95);
        set_skill("move", 85);
        set_skill("parry", 85);
        set_skill("unarmed",80);
        set_skill("fire-array",80);
        set_skill("array",80);
        set_skill("literate",60);
        set_skill("canon",100);
        set_skill("shift-steps",80);
        set_skill("universe",100);
        map_skill("array","fire-array");
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("inquiry",([
        "ÒåĞÖ":(: ask_man :),
        ]));
        set("functions/goldsun/level",60);
        set("chat_chance_combat", 40);
                set("chat_msg_combat", ({
                (: exert_function("goldsun") :),
                (: perform_action("force.sun1") :),
                (: perform_action("force.sun2") :),
        }));
        setup();
    add_money("gold",20);
    carry_object("/open/prayer/obj/dragon-robe")->wear();
    carry_object("/open/prayer/obj/dragon-hat")->wear();
    carry_object("/open/prayer/obj/dragon-hands")->wear();
    carry_object("/open/prayer/obj/dragon-legging")->wear();
    carry_object("/open/prayer/obj/dragon-ring")->wear();
        create_family("Ê¥»ğ½Ì",2,"¸±½ÌÖ÷");
}

int accept_fight(object who)
{
return notify_fail("¸±½ÌÖ÷ËµµÀ: È¥ÕÒ±ğÈË°É!!\n");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_12"))
        {
        command("say Ã»ÓĞ½ÌÖ÷µÄÍ¬Òâ,ÎÒ²»¸ÒÉÃ×Ô×öÖ÷ÊÕÄãÎªÈëÊÒµÜ×Ó!");
        return 0;
        }
        command("smile");
        command("say ¹ş¹ş¹ş!¸ú×ÅÎÒÑ§Îä,ÄãÒ»¶¨²»»áºó»ÚµÄ!!");
        command("say àÅ!ÀÏ·òËùÉæÁÔµÄÎäÑ§Éõ¶à!!Ğ¡×Ó¿ÉÒªºÃºÃµÄÑ§Ñ½!!");
        command("recruit "+ob->query("id"));
        ob->set("marks/ÎÄÎäĞÇ¾ı",1);
        this_player()->set("title","Ê¥»ğ½ÌÎäĞÇ¾ıµÃÒâÃÅÉú");
}

// by ACKY
int accept_kill(object ob)
{
        int i;
        object ob1, hu_fa;
        ob1 = this_object();

        if( !present("hu-fa", environment(ob)) ) {
        tell_room(environment(ob),HIW"\nÍ»È»£¡³å³öÁ½Î»»¤·¨!!\n\n"NOR);
        for(i=0;i<2;i++)
        {
        hu_fa = new("/open/prayer/npc/hu_fa");
        hu_fa->move(environment(ob));
        hu_fa->command("guard warrior");
        hu_fa->command("follow "+ob->query("id"));
        hu_fa->kill_ob(ob);
        }}
        if( ob->query_temp("warrior") > 3 ) {
		command("say ºß, ÏëÌÓ? Ã»ÄÇÃ´ÈİÒ×£¡\n" );
		ob->delete_temp("warrior");
		ob->start_busy(1);
	}
	ob->add_temp( "warrior", 1 );
           message_vision(HIR "»¤·¨×İÉí·ÉÆË¹ıÀ´½ĞµÀ£º´óµ¨¿ñÍ½£¡¸±½ÌÖ÷Ò®£¡£¡\n" NOR,ob);
        return 1;
}
void greeting(object ob)
{
        if (ob->query("age") < 16 && (int)ob->query("cor") > 25 && (int) ob->query("con") > 25 )
        {
        write("\n[36mÄãÓĞÃ»ÓĞÌıÈËËµ¹ı[µ¶Éñ½£ÏÉÊ®Èı±Ş]Õâ¸öÍâºÅ??[0m\n");
        write("\n[36mËûÊÇÎÒµÄÒåĞÖ!!Òş¾ÓÁËºÜ¾ÃÁË!!ÏÖÔÚÎÒÒ²²»ÖªµÀËûÔÆÓÎºÎ·½ÁË!![0m\n");
        ob->set_temp("high-man", 1);
        return;
        }

        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
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

void die()
{
	object winner = query_temp("last_damage_from");
	int j;

        if(!winner)
	{
	::die();
	return ;
        }

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {
	  new("/open/sky/obj4/growth_shells")->move(environment(winner));
	  message_vision(HIM"\n´Ó³ÂÈÙÖÓµÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/growth_shells",sprintf("%s(%s) ÈÃ³ÂÈÙÖÓµôÏÂÁË³É³¤Ö®±´¿ÇÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj4/growth_shells")->move(environment(winner));
	  message_vision(HIM"\n´Ó³ÂÈÙÖÓµÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/growth_shells",sprintf("%s(%s) ÈÃ³ÂÈÙÖÓµôÏÂÁË³É³¤Ö®±´¿ÇÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();
}
