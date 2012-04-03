#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;
string ask_reason()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="ÇØÒäÊ«" )
    {
    ob2->set_temp("can_ask",1);
    return("ÕâÊÇÎÒÓñÅ®ÅÉµÄ½£·¨!!ÎÒÄËÊÇ[32mÓñÅ®ÅÉ[0m[36mµÄÕÆÃÅÈË......\n
    ¿ÉÊÇ×Ô´ÓÎÒµÄÊ¦½ã[32mÂ½ç²Ü½[36mÒõÄ±¶áÈ¡½£Æ×Ö®ºó.....\n");
    }
    else
    {
    return("[36mÕâÎ»ÏÀÊ¿¿´À´²¢·Ç±¾ÃÅµÄµÜ×Ó, Çë»Ø°É!![0m");
    }
}

string ask_lu()
{
    object ob2=this_player();
    if( (ob2->query("family/master_name") =="ÇØÒäÊ«") && ob2->query_temp("can_ask",1) )
    {
    ob2->delete_temp("can_ask");
    ob2->set_temp("can_kill",1);
    return("[36mÊ¦½ãÂ½ç²Ü½ËýÉè¼ÆÏÝº¦ÎÒ, Ê¹µÃÎÒ±»ÃÅÈË[Îó»á].....\n
    ²»µÃÒÑÖ»ºÃ´ø×ÅÁíÒ»Î»Ð¡Ê¦ÃÃÔ¶×ßÎ÷Óò.....[0m\n");
    }
    else
    {
    return("[36mÕâÎ»ÏÀÊ¿¿´À´²¢·Ç±¾ÃÅµÄµÜ×Ó, Çë»Ø°É!![0m");
    }
}

string ask_misunder()
{
    object ob2=this_player();
    if( (ob2->query("family/master_name") =="ÇØÒäÊ«") && ob2->query_temp("can_kill") )
    {
    return("[36mÏÖÔÚ¶àËµÒ²Ã»ÈË»áÏàÐÅÁË, ²»¹ýÈç¹ûÄÜÉ±ÁËÊ¦½ãÂ½ç²Ü½, ¾Í¿ÉÏûÎÒÐÄÍ·Ö®Ô¹ÁË.\n
    È¥ÕÒÎÒµÄÁíÒ»¸ö[Ð¡Ê¦ÃÃ], Ëý»á¸æËßÄãÊ¦½ãµÄ²ØÉí´¦µÄ!![0m\n");
    ob2->delete_temp("can_kill");
    ob2->set_temp("go_kill",1);
    }
}

string ask_book()
{
    object ob2=this_player();
    object ob3=new("/open/prayer/obj/girlbook");
    if( ob2->query("quests/girlsword",1) && !present("girlbook",ob2) )
    {
    ob3->move(this_player());
    return "ÄãÎñ±ØÒªºÃºÃµÄÑ§Ï°ÓñÅ®ÅÉµÄ½£·¨!!\n";
    }
    else
    {
    return "½£Æ×ÎÒ²ØÆðÀ´ÁË!!²»¹ýÕÆÃÅÅå½£[31m[ºìžÔ½£][36mÎÒ·ÅÔÚ¿ªÑôÃÅµÄÄ³Ò»¸öµØ·½!!\n";
    }


}   

void create()
{
        set_name("ÇØÒäÊ«", ({"chi i-zhi","chi","i-zhi"}));
        set("long",@LONG

        ¿ªÑôÃÅµÄÃÅÖ÷£¡Ô­±¾ÊÇÖÐÔ­ÎäÁÖµÄÒ»Î»Ð¡Ê¦Ì«£¬¹óÎª¸ÃÅÉµÄ
        ÕÆÃÅÈË, ¿ÉÊÇ²»ÖªÎªºÎÅÜµ½Î÷ÓòÀ´¼ÓÈëÊ¥»ð½Ì, Ò»ÊÖÌìÅ®É¢
        »¨½£·¨³öÉñÈë»¯, ¶øÊ¥»ð½ÌµÄÈý´ó¾øÑ§ÖÐ, ËýÒ²ÊÇÊôÓÚÒ»µÈ
        Ò»µÄºÃÊÖ!!

LONG);
        set("gender","Å®ÐÔ");
        set("class","prayer");
        set("family/master_name","ÁÖºêÉý");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",28);
        set("title","¿ªÑôÃÅÖ÷");
        set("kee",5000);
        set("max_kee",5000);
        set("force",9000);
        set("max_force",9000);
        set("max_gin",4000);
        set("max_sen",4000);
        set("force_factor",5);
        set_skill("holy-force", 50);
        set_skill("superforce", 80);
        set_skill("cure", 40);
        set_skill("dodge",60);
        set_skill("force",50);
        set_skill("canon",80);
        set_skill("move", 40);
        set_skill("parry", 80);
        set_skill("unarmed",80);
        set_skill("literate",40);
        set_skill("shift-steps",60);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/bluesea/level",40);
        set("inquiry",([
        "ÌìÅ®É¢»¨½£·¨":"µ±³õÊÇÒòÎªÄ³ÖÖ[32mÔ­Òò[36m, ËùÒÔ²»µÃÒÑ²ÅÂÙÂäµ½Î÷ÓòµÄ!!\n",
        "Ô­Òò":(: ask_reason :),
        "Â½ç²Ü½":(: ask_lu :),
        "ÓñÅ®ÅÉ":"ÓñÅ®ÅÉÊÇÖÐÔ­µÄÒ»¸öÐ¡ÃÅÅÉ, ¿ÉÊÇ½£·¨ÄËÊÇ¸ßÈËËù´´, ÒòÎªÊ¦¸¸´«Î»ÓÚÎÒ, ËùÒÔ[32m½£Æ×[36mÒ²´«¸øÁËÎÒ!!\n",
        "½£Æ×":(: ask_book :),
        "ºìžÔ½£":"ÊÇÕÆÃÅÈË×¨ÓÃµÄ±¦½£, Óë½£·¨ÅäºÏ»¥Ê¹µÄ»°, É±ÉËÁ¦±¶Ôö!!\n",
        "Îó»á":(: ask_misunder :),
        ]));
        set("chat_chance",5);
        set("chat_msg", ({
        HIC+"ÇØÒäÊ«ÇáÒ÷:ÈËÉÆÑøÐÄ¡«¶øÐÄÈçð©ÔÂÇå·ç¡«!!\n\n"+NOR
        HIC+"ÊÂÉÆÐÞÉí¡«¶øÉíËÆÐÐÔÆÁ÷Ë®¡«!!\n\n"+NOR,
        HIC+"ÎäÁÖÍòÎï¡«½ÔÎªÉú¶øÂÖ»Ø¡«!!\n\n"+NOR
        HIC+"°Ù¼Ò±øÆ÷¡«¶À±¾½£µÃ¾«Ëè¡«!!\n\n"+NOR,
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action("force.bluesea1") :),
        (: perform_action("force.bluesea2") :),
        (: exert_function("bluesea") :),
        }));
        setup();
    add_money("gold",5);
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    create_family("¿ªÑôÃÅ",5,"ÃÅÖ÷");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_6"))
        {
        command("say Ã»ÓÐ½ÌÖ÷µÄÍ¬Òâ,ÎÒ²»¸ÒÉÃ×Ô×öÖ÷ÈÃÄã½øÃÅ!");
        return 0;
        }
        command("smile");
        command("say ¼ÈÈ»ÊÇ½ÌÖ÷µÄÒâË¼,ÄÇÄã¾Í½øÈëÎÒ¿ªÑôÃÅ°É!");
        command("say Ê¥»ð½ÌµÄ¾øÑ§²©´ó¾«Éî,¿É²»ÊÇÄÇÃ´ºÃÑ§µÄ!");
        command("say ÏëÑ§µÃ¸Ç\ÊÀÎäÑ§¾ÍµÃºÃºÃÐÞÏ°ÄÚ¹¦µÄ»ù´¡!");
        command("recruit "+ob->query("id"));
        ob->set("marks/Ê¥»ð°ËÌìÃÅ",1);
        this_player()->set("title","Ê¥»ð½Ì¿ªÑôÃÅË×¼ÒµÜ×Ó");
        }

void greeting(object ob)
{
        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
      {
       command("say ½ÌÖ÷ÓÐÁî£¡£¡·²ÊÇÑ§ÓÐ¶¾ÊõÖ®ÈË£¬É±ÎÞë·£¡£¡");
        kill_ob(ob);
     }
       if( ob->query("class")=="dancer")
        {
        command("say ½ÌÖ÷ÓÐÁî£¬¼ûµ½ÎèÕß-----¸ñÉ±ÎðÂÛ£¡£¡");
        kill_ob(ob);
     }
    return;
}

int accept_object(object ob2, object obj, object ob3)
{
        if( obj->query("name") == "Óñç‡" )
        {
          command("pat "+getuid(ob2));
          command("say Ì«ºÃÁË, ÄãÕæµÄ½«ÎÒÊ¦½ãÉ±ËÀÁË!!Ð»ÁË¡£");
          if( ob2->query("family/master_name") == "ÇØÒäÊ«" && !ob2->query("marks/girlsword") && ob2->query_temp("will_kill") )
          {
          command("say ¼ÈÈ»Äã°ïÎÒÇå³ýÃÅÄÚÅÑÄæ, ÎÒ±ã½«´Ë½£Æ×´«ÊÚÓëÄã°É¡£");
          write(this_object()->query("name")+"¿´×ÅÃØóÅËæÊÖÑÝÁ·ÁËÒ»±é¸øÄã¿´¡£\n\n"+
          "Äã¾õµÃ´ËÒ»½£·¨ËÆºõÒì³£µØÊÊºÏÄã, ÄãµÄÎäÑ§ÐÞÑøÓÖ¿ÉÒÔ¸ü½øÒ»²ãÁË¡£\n\n"+
          "[36mÄãÑ§»áÁËÓñÅ®ÅÉµÄ[32m¡¸ÌìÅ®É¢»¨½£·¨¡±[0m¡£\n\n");
              ob2->set_skill("girlsword",10);
              ob2->set("quests/girlsword",1);
              ob3=new("/open/prayer/obj/girlbook");
              ob3->move(this_player());
          }
          destruct(obj);
        }
        else
        command("? "+getuid(ob2));
        return 1;
}
