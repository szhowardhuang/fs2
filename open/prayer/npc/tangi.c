#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
inherit SSERVER;
object ob1=this_object();
string do_crystal();
string do_help()
{
    object ob2=this_player();
    if( !ob2->query_temp("É±º¦ÈË·¸") && !ob2->query_temp("can_tell",1)  )
    {
    return(" [36m¸óÏÂ²¢·ÇÎÒÊ¥»ğ½ÌµÄÖ´·¨Õß, Ë¡ÔÚÏÂÉõÄÑ´ÓÃü!![0m\n");
    }
    ob2->delete_temp("can_tell");
    ob2->set_temp("can_go",1);
    return(" ºß!Ëûº¦ÎÒÒò´ËÎŞ·¨Íê³É½ÌÖ÷½»´ıµÄÈÎÎñ,ÎÒÊµÔÚÎŞ·¨Ô­ÁÂËû..\n
    ³ı·Ç.........\n");
}

string do_else()
{
    object ob2=this_player();
    if( !ob2->query_temp("can_go",1) && !ob2->query_temp("É±º¦ÈË·¸") )
    {
    return("  ÔÚÏÂ²»Ô¸¶àÌ¸´ËÊÂ!!¸óÏÂÇë»Ø°É!!");
    }
    ob2->delete_temp("can_go");
    ob2->set_temp("will_go",1); 
    return(" ÄãÈ¥°ïÎÒÍê³ÉÕâ¸öÈÎÎñ,ÎÒ¾Í·ÅÁËËû!!Ô¸ÒâÂğ(nod)??\n");
} 

string ask_water()
{
    object ob=this_player();
    if(!ob->query_temp("ask_hurted") && !ob->query_temp("can_pass"))
    {
    return(" ÇëË¡ÔÚÏÂÎŞÀñ!!¸óÏÂËÆºõÎŞÈ¨¹ıÎÊÎÒ½ÌÖĞÎäÑ§Ö®ÊÂ!!\n");
    }
    ob->delete_temp("ask_hurted");
    ob->set_temp("can_take",1);
    return(" ½ÌÖ÷·Ô¸ÀÒªÎÒÈ¥½«°×Ë®¾§´Óàòàô³ØÖĞÄÃ³öÀ´!!\n");
}

string do_crystal()
{
    object ob2=this_player();
    object ob3;
    if( ob2->query("quests/white-crystal",1) && !present("white-crystal",ob2) )
    {
    ob3=new("/open/prayer/obj/crystal1");
    ob3->move(this_player());
    return("°×Ë®¾§ÊÇÄãÕÒ»ØÀ´µÄ, ½ÌÖ÷ÌØµØÆÆÀıÈÃÄãÑ§Ñ§ÉÏÃæµÄĞÄ·¨!!\n");
    } 
    else
    {
    return("°¦!!°×Ë®¾§µ½ÏÖÔÚ»¹ÊÇÏÂÂä²»Ã÷°¡!!ÕæÊÇ¼±ËÀÎÒÁË!!");
    }
} 

void create()
{
        set_name("Ë¾Âí½õ", ({"sema ching","ching"}));
        set("long",@LONG

        Ìì»úÃÅµÄÃÅÖ÷£¬ÔÚÊ¥»ğ½ÌÖĞËØÀ´ÓĞ        [ÎäÑ§Ææ²Å]µÄ³ÆºÅ£®ºÃÑ§
        ²»¾ë£¡¶ÔÓÚ¸÷ÖÖµÄÊé¼®¾ùºÃÉæÁÔ£¡¸öĞÔ³ÁÎÈ£¬ÄÚĞÄÏ¸Äå£¬ÊÇ°Ë
        ÌìÃÅ¸÷ÃÅÖ÷Ëù¹«ÈÏµÄ´ó¸ç£®ÎäÑ§Ëù¼°£¬¶ÔÓÚÍâ¼Ò±øÆ÷ÓëÄÚ¹¦¾ù
        ÓĞËù³¤£®

LONG);
        set("gender","ÄĞĞÔ");
        set("class","prayer");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",48);
        set("nickname","ÎäÑ§Ææ²Å");
        set("title","Ìì»úÃÅÖ÷");
        set("kee",4500);
        set("max_kee",4500);
        set("force",9000);
        set("max_force",9000);
        set("force_factor",5);
        set("max_gin",3500);
        set("max_sen",3500);
        set_skill("holy-force", 70);
        set_skill("superforce", 80);
        set_skill("cure", 40);
        set_skill("dodge", 70);
        set_skill("force",70);
        set_skill("canon",70);
        set_skill("move", 50);
        set_skill("parry", 70);
        set_skill("unarmed",70);
        set_skill("literate",60);
        set_skill("shift-steps",70);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/black/level",40);
        set("inquiry",([
        "ÈË·¸":"ÄÇÃûÈË·¸¾¹¸ÒÉÃ×Ô½«ÈË·¸Å°´ıÖÁËÀ,ËùÒÔ±»ÎÒ¹ØÔÚµØÀÎÖ®ÄÚ·´Ê¡!!\n",
        "ÇóÇé":(: do_help :),
        "³ı·Ç":(: do_else :),
        "È­Ê¦":"È­Ê¦ÊÇÎÒÅÉÈ¥¶´¿ßµÄ, ÒòÎª½ÌÖ÷¸øÁËÎÒÒ»¸öÈÎÎñ!!\n",
        "ÈÎÎñ":"ÊÇÄÃÒ»¸ù»ëÌìË®¾§!!\n",
        "»ëÌìË®¾§":"ÊÇ°×É«µÄ»ëÌìË®¾§, ÉÏÃæÊÇ¼ÇÔØ»ù±¾ĞÄ·¨µÄ!!\n",
        "°×Ë®¾§":(: do_crystal :),
        "àòàô³Ø":(: ask_water :),
        ]));
        set("chat_chance",3);
        set("chat_msg", ({
        HIC+"Ë¾Âí½õÀÊµÀ:ÁÙÃû¶øÈÃÃû¡«ÇóÃûµ±ÇóÍòÊÀÃû¡«!!\n\n"+NOR
        HIC+"ÁÙÀû¶øÈÃÀû¡«¼ÆÀûµ±¼ÆÌìÏÂÀû¡«!!\n\n"+NOR,
        HIC+"½äÉ÷¿Ö¾å¡«¾ÓÍò³¾¶ø²»È¾Ò»³¾¡«!!\n\n"+NOR
        HIC+"ÁÙÔ¨ÂÄ±¡¡«ÀíÍòÀí¶ø²»Ê§Ò»»ú¡«!!\n\n"+NOR,
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("black") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    add_money("gold",5);
    create_family("Ê¥»ğ½Ì",5,"Ìì»úÃÅÖ÷");
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

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_1"))
        {
        command("say Ã»ÓĞ½ÌÖ÷µÄÍ¬Òâ,ÎÒ²»¸ÒÉÃ×Ô×öÖ÷ÈÃÄã½øÃÅ!");
        return 0;
        }
        command("smile");
        command("say ¼ÈÈ»ÊÇ½ÌÖ÷µÄÒâË¼,ÒÔºóÄã¾Í¸úÎÒºÃºÃÑ§°É!");
        command("recruit "+ob->query("id"));
        ob->set("marks/Ê¥»ğ°ËÌìÃÅ",1);
        this_player()->set("title","Ê¥»ğ½ÌÌì»úÃÅË×¼ÒµÜ×Ó");
}

int do_nod()
{
  object ob2=this_player();
  if( !ob2->query_temp("will_go",1))
  {
  return 0;
  }
  else
  {
  ob2->delete_temp("will_go");
  ob2->set_temp("can_pass",1);
  write(" Š…È¥ÕÒÂôÓãµÄÀÏ¸¾°É!!Ëı»á½ÌÄãÈçºÎ½øÈë¶´¿ßµÄ!!\n");
  return 1;
  }
}

void greeting(object ob)
{
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
            
