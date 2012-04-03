#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_study()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="Ë¾Í½ÈÙ" && (int)ob2->query("combat_exp") >= 300000 )
    {
    ob2->set("can_study",1);
    return("ÕâÊÇÎÒ´«¼Ò¾øÒÕ!!ÄãÊ×ÏÈÒªºÃºÃµØÁ·Ï°»ù±¾¼¼ÇÉ²ÅĞĞ......\n");
    }
    else
    {
    return("[36mÎÒ²»ÄÜÈÃÄãÑ§Ï°ÕâÌ×ÕÆ·¨!![0m");
    }
}

string ask_test1()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="Ë¾Í½ÈÙ" && ob2->query("can_study",1) )
    {
    ob2->set("can_test1",1);
    ob2->set_skill("test1",1);
    return("»ù±¾¼¼ÇÉ--²åÌúÉ³, ÊÇÒªÁ·´ËÕÆ·¨Ö®ÈËÏÈ¶ÍÁ·×Ô¼ºµÄË«ÕÆÇ¿¶È, \n
    È»ºó²ÅÄÜÁ¦±£¹¥µĞÖ®Ê±, ÕÆ¾¢ÄÜÍ¸µĞÖ®Ìå, ÉËµĞÖ®Âö!!ÏÈ½«µÈ¼¶Ìá¸ß°É!!\n");
    }
    else
    {
    return("[36mÎÒ²»ÄÜÈÃÄãÑ§Ï°ÕâÌ×ÕÆ·¨!![0m");
    }
}

string ask_test2()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="Ë¾Í½ÈÙ" && ob2->query_skill("test1",1) >=30 )
    {
    ob2->set("can_test2",1);
    ob2->set_skill("test2",1);
    return("»ù±¾¼¼ÇÉ--ÅÄÊ¯±®, ÊÇÒªÁ·´ËÕÆ·¨Ö®ÈËÔÚ¶ÍÁ·×Ô¼ºµÄË«ÕÆÇ¿¶Èºó, \n
    ÕÆÎÕ³öÕÆÊ±µÄ¾¢µÀ, ²ÅÄÜ¶ÔÓÚÕÆ¾¢×öµ½ÊÕ·¢×ÔÈçµÄ¾³½ç!!¼ÌĞø¼ÓÓÍ!!\n");
    }
    else
    {
    return("[36mÎÒ²»ÄÜÈÃÄãÑ§Ï°ÕâÌ×ÕÆ·¨!![0m");
    }
}

string ask_test3()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="Ë¾Í½ÈÙ" && ob2->query_skill("test2",1) >= 30 )
    {
    ob2->set("can_test3",1);
    return("²âÑéËùÖ¸µÄ, ÄËÊÇ½øÈëÁ·¹¦·¿ÖĞ, Õë¶ÔÌØÖÆµÄÊ¯ÈË½øĞĞ¶Ô´ò, Ö»ÒªÄÜ¹»»÷°ÜÊ¯ÈË
,±ã¿ÉÒÔÍ¨¹ı²âÊÔ, Ï°µÃÌúÉ³ÕÆµÄÈëÃÅÎäÑ§!!\n");
    }
    else
    {
    return("[36mÎÒ²»ÄÜÈÃÄãÑ§Ï°ÕâÌ×ÕÆ·¨!![0m");
    }
}

string ask_test4()
{
    object ob2=this_player();
    if( ob2->query_temp("win_stone",1) && ob2->query("can_test2",1) )
    {
    ob2->set_skill("ironhand",10);
    ob2->delete("can_test1");
    ob2->delete("can_test2");
    ob2->delete_skill("test1");
    ob2->delete_skill("test2");
    ob2->set("study/ironhand",1);
    ob2->set("quests/ironhand",1);
    return("ºÜºÃ, ÄãÍ¨¹ıÁË²âÊÔ, ÎÒÕâ¾Í´«Äã»ù±¾µÄÌúÉ³ÕÆ·¨!!\n");
    }
}

string ask_book()
{
    object ob2=this_player();
    object ob3=new("/open/prayer/obj/ironbook");
    if( ob2->query("quests/ironhand",1) && !present("ironbook",ob2) )
    {
    ob3->move(this_player());
    return "ÄãÎñ±ØÒªºÃºÃµÄÑ§Ï°ÎÒ¼Ò´«µÄ¾øÒÕ!!\n";
    }
    else
    {
    return("[36mÎÒ²»ÄÜÈÃÄãÑ§Ï°ÕâÌ×ÕÆ·¨!![0m");
    }
}   

void create()
{
        set_name("Ë¾Í½ÈÙ", ({"se-tu rong","se-tu","rong"}));
        set("long",@LONG

        ÌìÈ¨ÃÅµÄÃÅÖ÷£¡ÓëÆäÆŞË¾Í½Öª»ªÁ½ÈË·Ö±ğ³ÉÎªÊ¥»ğ½Ì°ËÌìÃÅ
        µÄÃÅÖ÷£®¶ìöøÇéÉî£¬É½ÃËº£ÊÄ£®Ë¾Í½ÈÙ±¾ÉíËùĞŞÁ·µÄÎäÑ§Îª
        Íâ¼Ò±øÆ÷£¬²»¹ıËûµÄÏÈÌìÇ¬À¤¹¦Óë½ÌÖ÷ËùÑ§È´Ò²Ïà²îÎŞ¼¸!

LONG);
        set("gender","ÄĞĞÔ");
        set("class","prayer");
        set("family/master_name","ÁÖºêÉı");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",45);
        set("title","ÌìÈ¨ÃÅÖ÷");
        set("kee",4700);
        set("max_kee",4700);
        set("force",9000);
        set("max_force",9000);
        set("force_factor",5);
        set("max_gin",2700);
        set("max_sen",2700);
        set_skill("superforce", 80);
        set_skill("holy-force", 50);
        set_skill("cure", 40);
        set_skill("dodge", 60);
        set_skill("force",50);
        set_skill("move", 50);
        set_skill("parry", 90);
        set_skill("canon",80);
        set_skill("unarmed",60);
        set_skill("literate",40);
        set_skill("shift-steps",60);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/black/level",50);
        set("inquiry",([
        "ÌúÉ³ÕÆ·¨":"ÕâÊÇÎÒ¼Ò´«ÎäÑ§, Ò»¹²·Ö³É°ËÊ½!!ÄãÏëÒªÑ§Ï°Âğ??\n",
        "Ñ§Ï°":(: ask_study :),
        "»ù±¾¼¼ÇÉ":"»ù±¾¼¼ÇÉ·Ö±ğÊÇ[²åÉ³]Óë[ÅÄÊ¯], ×îºóÔÙÍ¨¹ı[²âÑé]¾Í¿ÉÒÔÁ·³É!!\n",
        "²åÉ³":(: ask_test1 :),
        "ÅÄÊ¯":(: ask_test2 :),
        "²âÑé":(: ask_test3 :),
        "Í¨¹ı":(: ask_test4 :),
        "È­Æ×":(: ask_book :),
        ]));
        set("chat_chance",10);
        set("chat_msg", ({
        HIC+"Ë¾Í½ÈÙÒ÷µÀ:ÒÔÎŞÎªÓĞ¡«ÒÔÍËÎª½ø¡«ÒÔ¿ÕÎªÀÖ¡«ÒÔÖÚÎªÎÒ¡«!!\n"+NOR,
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("black") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    carry_object("/open/prayer/obj/speed-ring")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    create_family("ÌìÈ¨ÃÅ",5,"ÃÅÖ÷");
    add_money("gold",5);
}

int accept_kill(object ob2)
{
        ob2->set_temp("É±·òÖ®³ğ",1);
        command("say ºß!!"+ob2->name()+"ÎÒÆŞ×Ó»áÌæÎÒ±¨³ğµÄ¡£");
        return 1;
}

void attempt_apprentice(object ob2)
{
        if(!ob2->query_temp("allow_3"))
        {
        command("say Ã»ÓĞ½ÌÖ÷µÄÍ¬Òâ,ÎÒ²»¸ÒÉÃ×Ô×öÖ÷ÈÃÄã½øÃÅ!");
        return 0;
        }
        command("smile");
        command("say ¼ÈÈ»ÊÇ½ÌÖ÷µÄÒâË¼,ÒÔºóÄã¾ÍÓÃĞÄµØºÃºÃ¸úÎÒÑ§Îä°É!!");
        command("recruit "+ob2->query("id"));
        ob2->set("marks/Ê¥»ğ°ËÌìÃÅ",1);
        this_player()->set("title","Ê¥»ğ½ÌÌìÈ¨ÃÅË×¼ÒµÜ×Ó");
        }

void greeting(object ob2)
{
    if( ob2->query("family/master_name") =="Ë¾Í½ÈÙ" && (int)ob2->query("combat_exp") > 300000 )
    {
    command("pat "+getuid(ob2));
    command("say ÎÒ¿´ÄãµÄ×ÊÖÊÆÄ¼Ñ, ÎÒÓĞÒâ´«ÊÚÄãÎÒ¼Ò´«µÄ[ÌúÉ³ÕÆ·¨]!!\n");
    return;
    }

    if(ob2->query_temp("É±ÆŞÖ®³ğ",1))
    {
    command("angry "+getuid(ob2));
    command("say »¹ÎÒÏÍÆŞ[Ë¾Í½Öª»ª]µÄÃüÀ´!!!!");
    kill_ob(ob2);
    return;
    }

    if (ob2->query_skill("coldpoison", 1))
//      if ((present("five poison", ob2)) || (present("dark poison", ob2)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
    {
    command("say ½ÌÖ÷ÓĞÁî£¡£¡·²ÊÇÑ§ÓĞ¶¾ÊõÖ®ÈË£¬É±ÎŞë·£¡£¡");
    kill_ob(ob2);
    return;
    }
    if( ob2->query("class")=="dancer")
    {
    command("say ½ÌÖ÷ÓĞÁî£¬¼ûµ½ÎèÕß-----¸ñÉ±ÎğÂÛ£¡£¡");
    kill_ob(ob2);
    return;
    }
    return ;
}


