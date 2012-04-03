#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_lover()
{
    object ob=this_player();
    if( ob->query("family/family_name") =="Ê¥»ğ½Ì" && ob->query_temp("youkoun") >= 1 )
    {
    ob->set_temp("youkoun", 2);
    return("[36mËû½ĞÑàÊ®Ò», ÊÇÏ¼É½ÅÉµÄµÜ×Ó, Ò²¾ÍÊÇÎÒµÄ¾ÈÃü¶÷ÈË!!Îä¹¦¸ßÇ¿, ËùÒÔÎÒ¾Í....
¿ÉÊÇÎÒµÄ[ÇéµĞ]È´×èÄÓÁËÎÒ¸úËûµÄÊÂ!![0m\n");
    }
    else
    {
    return("[36mÎÒ¸ÉÂïÒª»Ø´ğÄãµÄÎÊÌâÑ½!![0m\n");
    }
}

string ask_emery()
{
    object ob=this_player();
    if( ob->query_temp("youkoun") >= 2 )
    {
    ob->set_temp("youkoun", 3);
    return("[36mËı½Ğ×ö[ºì¹Ã], ÊÇËûµÄĞÄÉÏÈË, Ò²ÊÇËûµÄÊ¦½ã!!ËäÈ»Ëû±»ÎÒ¹ØÔÚ[ĞÌ·¿]¶àÄê
¿ÉÊÇ»¹ÊÇÄîÄî²»ÍüËı!!ÕæÊÇÆøÈË!![0m\n");
    }
    else
    {
    return("[36mÎÒ¸ÉÂïÒª»Ø´ğÄãµÄÎÊÌâÑ½!![0m\n");
    }
}

string ask_room()
{
    object ob=this_player();
    if( ob->query_temp("youkoun") >= 3 )
    {
    ob->set_temp("youkoun", 4);
    return("[36mËäÈ»ÎÒ°ÑËû¸øÇÀÁË¹ıÀ´, ¿ÉÊÇËûÖªµÀËı»¹Ã»ËÀ, Òò´ËĞÄÀïÍ·¾Í¸üÃ»ÓĞÎÒÁË!!
ËùÒÔÎÒ¾ÍË½ÉèÁËÒ»¸öĞÌ·¿, Ã¿Ìì¿½´òËû, Ï£ÍûËûÊÜ²»ÁËÆ¤ÈâÖ®¿à¶øÇóÎÒ!!¶øÇÒÔÚÕâ¼¸ÄêÖĞ, 
ÎÒÒ²×Ô´´ÁËÒ»Ì×[Ñ±ÊŞÊõ]!!ËãÊÇÒ»¸öĞ¡ÊÕ»ñ°É!![0m\n");
    }
    else
    {
    return("[36mÎÒ¸ÉÂïÒª»Ø´ğÄãµÄÎÊÌâÑ½!![0m\n");
    }
}

string ask_skill()
{
    object ob=this_player();
    if( ob->query_temp("youkoun") >= 4 )
    {
    ob->set_temp("youkoun", 5);
    return("[36mÑ±ÊŞÊõ??à¸!!ÄÇÊÇÎÒ³¤ÄêÔÚĞÌ·¿ÖĞÁèÅ°ÄĞÈËËùÎò³öÀ´µÄÒ»ÖÖÌØÒìÎäÑ§!!
È»ºóËüÊ¹½«ÔÚÖÆ·şÒ°ÊŞµÄÓÃÍ¾ÉÏ, Ò²ÌØ±ğµØÓĞĞ§¹û!![0m\n");
    }
    else
    {
    return("[36mÎÒ¸ÉÂïÒª»Ø´ğÄãµÄÎÊÌâÑ½!![0m\n");
    }
}

string ask_red()
{
    object ob=this_player();
    if( ob->query_temp("youkoun") >= 3 )
    {
    ob->set_temp("youkoun", 6);
    return("[36mÖ»ÒªÄÜ½«Ëı½â¾öµô, Ò»¶¨ÄÜÈÃÑà¸ç¸ç»ØĞÄ×ªÒâµÄ!!ÄãÔ¸Òâ(nod)°ïÕâ¸öÃ¦Âğ??[0m\n");
    }
    else
    {
    return("[36mÎÒ¸ÉÂïÒª»Ø´ğÄãµÄÎÊÌâÑ½!![0m\n");
    }
}

string ask_book()
{
    object ob=this_player();
    object ob3=new("/open/prayer/obj/trainbook");
    if( ob->query("quests/trainbeast",1) && !present("trainbook",ob) )
    {
    ob3->move(this_player());
    return "Äã×Ô¼ººÃºÃµØ´§Ä¦´§Ä¦°É!!\n";
    }
    else
    {
    return "¼ÇµÃÑ±ÊŞÊõÖ»¶ÔÒ°ÊŞÓĞĞ§ÓÃ¶øÒÑà¸!!\n";
    }
}   


void create()
{
        set_name("ÖÜ¬Lò¯", ({"chou shou-chin","chou","shou-chin"}));
        set("long",@LONG

        Ñş¹âÃÅµÄÃÅÖ÷£¡ÉúĞÔ¹ÖÒì£¬Ëä¹óÎªÊ¥»ğ°ËÌìÃÅµÄÃÅÖ÷
        , ¿ÉÊÇÈ´¼«¶ÈµÄÌÖÑáÄĞĞÔ, ÈçÎŞ½ÌÖ÷µÄÁîÅÆ, ÈÎºÎÄĞ
        ĞÔ¶¼²»µÃ½øÈëÑş¹âÃÅ, ·ñÔò±ØËÀÎŞÒÉ!!ËùĞŞÏ°µÄÄÚ¹¦
        ¹¦Á¦·Ç³£Éîºñ!!

LONG);
        set("gender","Å®ĞÔ");
        set("class","prayer");
        set("family/master_name","ÁÖºêÉı");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",34);
        set("title","Ñş¹âÃÅÖ÷");
        set("kee",5900);
        set("max_kee",5900);
        set("force",9000);
        set("max_force",9000);
        set("max_gin",3900);
        set("max_sen",3900);
        set("force_factor",10);
        set_skill("holy-force", 90);
        set_skill("superforce", 80);
        set_skill("cure", 20);
        set_skill("dodge",70);
        set_skill("canon",80);
        set_skill("force",90);
        set_skill("move", 40);
        set_skill("parry",70);
        set_skill("unarmed",60);
        set_skill("literate",40);
        set_skill("shift-steps",60);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("inquiry",([
        "ĞÌ·¿":(: ask_room :),
        "°®ÈË":(: ask_lover :),
        "ÇéµĞ":(: ask_emery :),
        "ºì¹Ã":(: ask_red :),
        "ÃÜóÅ":(: ask_book :),
        "Ñ±ÊŞÊõ":(: ask_skill :),
        ]));
        set("functions/bluesea/level",40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action("force.blue1") :),
        (: perform_action("force.blue2") :),
        (: exert_function("blue") :),
        }));
        setup();
    add_money("gold",5);
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
        create_family("Ñş¹âÃÅ",5,"ÃÅÖ÷");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_7"))
        {
        command("say Ã»ÓĞ½ÌÖ÷µÄÍ¬Òâ,ÎÒ²»¸ÒÉÃ×Ô×öÖ÷ÈÃÄã½øÃÅ!");
        return 0;
        }
        command("smile");
        command("say ¼ÈÈ»ÊÇ½ÌÖ÷µÄÒâË¼,ÄÇÄã¾Í½øÈëÎÒÑş¹âÃÅ°É!");
        command("say Ê¥»ğ½ÌµÄ¾øÑ§²©´ó¾«Éî,¿É²»ÊÇÄÇÃ´ºÃÑ§µÄ!");
        command("say ÏëÈëÎÒÑş¹âÃÅ¾ÍÒªÍÙÆúÄĞÈË!!ÖªµÀÂğ??");
        command("recruit "+ob->query("id"));
        ob->set("marks/Ê¥»ğ°ËÌìÃÅ",1);
        this_player()->set("title","Ê¥»ğ½ÌÑş¹âÃÅË×¼ÒµÜ×Ó");
        }

void init()
{
        object ob;
        ::init();
        if(interactive(ob =this_player()) && !is_fighting() )
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        add_action("do_nod","nod"); 
        }
}

int do_nod()
{
        object ob=this_player();
        if( ob->query_temp("youkoun") < 6  )
        {
        return 0;            
        }
        else
        {
        ob->set_temp("kill_red",1);
        write("[36mÄÇ¾Í°İÍĞÄãÈ¥×öÁË!!ÊÂ³ÉÖ®ºó, ÎÒ»á¸øÄãºÃ´¦µÄ!![0m\n");
        return 1;
        }

}

void greeting(object ob)
{
    if(!ob) return ;

        if( ob->query_temp("ÉÃ´³ĞÌ·¿",1) && ob->query("class") == "prayer" )
        {
          if((int)ob->query("combat_exp") > 300000)
          {
          command("tender "+getuid(ob));
          write("[36mÖ»ÓĞÅ®ÈË²Å»áÁË½âÅ®ÈËµÄĞÄÊÂ!!!![0m\n");
          write("[36mÄĞÈËÄÇÄÜÌå»áÊ§È¥[°®ÈË]µÄĞÄÇéÄØ??[0m\n");
          ob->set_temp("youkoun",1);
          return;
          }
          else
          {
          write("[31m´óµ¨Ğ¡±², ¾¹¸ÒÉÃ×Ô½øÈë±¾ÃÅÖ÷µÄĞÌ·¿!![0m\n");
          ob->set_temp("youkoun",1);
          kill_ob(ob);
          return;
          }
        }

        if (ob->query_temp("kill_red") >= 2 && !ob->query_temp("kill_eleven") )
        {
        write("\n[36mĞ»Ğ»Äã°ïÁËÎÒÕâ¸öÃ¦!!ÎÒ¾Í½ÌÄã[Ñ±ÊŞÊõ]×öÎª½±Àø°É!![0m\n");
        ob->delete_temp("youkoun");
        ob->set_skill("train-beast",5);
        ob->set("quests/trainbeast", 1);
        ob->add("max_force",50);
        return;
        }

        if ( ob->query("kill_eleven") && ob->query("family/master_name") != "ÖÜ¬Lò¯")
        {
        write("[36mÎÒ¼ÇµÃÄãµÄÑù×Ó, ¾ÍÊÇÄã, Äã¾¹È»¸ÒÉËº¦ÎÒµÄÑà¸ç¸ç!![0m\n");
        kill_ob(ob);
        return;
        }

        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
        {
        write("[33m½ÌÖ÷ÓĞÁî£¡£¡·²ÊÇÑ§ÓĞ¶¾ÊõÖ®ÈË£¬É±ÎŞë·£¡£¡[0m\n");
        kill_ob(ob);
        return;
        }
        if( ob->query("class")=="dancer")
        {
        command("say ½ÌÖ÷ÓĞÁî£¬¼ûµ½ÎèÕß-----¸ñÉ±ÎğÂÛ£¡£¡");
        kill_ob(ob);
        return;
        }
    return;
}

void die()
{

    object ob;
    ob= this_object()->query_temp("last_damage_from");
    if( ob && userp(ob) ) 
    {
    ob->delete_temp("kill_red");
    ob->set_temp("kill_youkoun", 1);
    write("[36mÄã..............[0m\n");
    }
    ::die() ;
}
