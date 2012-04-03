#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("ÁÖºêÉı",({"pope lin","pope","lin"}));
        set("long",@LONG

        Ã»ÓĞÈËÖªµÀËûµÄÀ´Àú£¬Ò²Ã»ÈËÖªµÀËûµÄÎä¹¦ÓĞ¶àÉî£»ÊÇÒ»¸öÉñÃÜÄª
        ²âµÄÈËÎï£¬ÔÚÈıÄêÇ°Òò·çÔÆ¼Ê»á£¬Ê¹Ëû´´Á¢ÁË¡²Ê¥»ğ½Ì¡³£¬Ò²²»Öª
        ËûÊÇÓÃºÎ·½·¨½¨Á¢Õâ¸öÅÓ´óµÄ×éÖ¯£¬Ò²ÒòÎªÈç´Ë, Ëû±»½­ºşÉÏµÄÈË
        ³ÆÎª¡²ÎäÁÖÉñ»°¡³¡£

LONG);
        set("gender","ÄĞĞÔ");
        set("clan_kill",1);
        set("class","prayer");
        set("nickname","ÎäÁÖÉñ»°");
        set("title","Ê¥»ğ½Ì»Ê¡«¡«");
        set("combat_exp",7000000);
        set("attitude","heroism");
        set("age",75);
        set("max_kee",15000);
        set("str", 50);
        set("cor", 50);
        set("cps", 45);
        set("per", 30);
        set("int", 42);
        set("marks/tengin",1);
        set("force",50000);
        set("max_force",50000);
        set("force_factor", 40);
        set("max_gin",10000);
        set("max_sen",10000);
        set_skill("cure", 120);
        set_skill("superforce", 150);
        set_skill("dodge", 120);
        set_skill("force",150);
        set_skill("move", 120);
        set_skill("literate",120);
        set_skill("parry", 130);
        set_skill("array",130);
        set_skill("fire-array",130);
        set_skill("unarmed",130);
        set_skill("canon",150);
        set_skill("literate",120);
        set_skill("shift-steps",150);
        set_skill("universe",140);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("array","fire-array");
        map_skill("unarmed","universe");
        set("functions/blood/level",60);
        set("functions/tengin/level",120);
        set("chat_chance", 1);                                                  
        set("chat_msg", ({                                                      
                CYN"½Ì»ÊÒ÷µÀ£º¡¸Óûº£¸¡ÉòÃûÀûÕù£¬µç¹â»ğÊ¯´Ë²½Éú£»\n
                        ºì³¾ÊÀÊÂ»Ó²»¾¡£¬¶ÉÊÀ²»Ğ¦ÊÇ³ÕÈË¡£¡±\n"NOR,                                                          
                CYN"½Ì»ÊĞ¦µÀ£º¡¸¹Â×äÔ¡Ñª¶·Ö¾¸ß£¬ÏÍÊËÉÆÄ±ÄÔÖĞ¼Æ£¬\n
                        Ò»ÅÚºä¿ªÏÕ¹ØµÀ£¬µ¥³µ»¤Ë§Ô½ÌìºÓ¡£¡±\n"NOR,                                                          
                CYN"½Ì»ÊÌ¾µÀ£º¡¸ÍòÀïĞÛ±øÆøÈçºç£¬Ç§Çï¶¨ÂÛÄÑÕù·å£»\n
                        ê»ÈÕÏÔÕÕĞÇ¹âÑÚ£¬°Ù´¨»ã×ÚË­Óë¹²¡£¡±\n"NOR,                                                          
                CYN"½Ì»ÊÀÖµÀ£º¡¸°ÙÄêÊÀÊÂ¿Õ»ªÀï£¬Ò»Æ¬ÉíĞÄË®ÔÂ¼ä£»\n
                        ¶ÀĞíÍòÉ½ÉîÃÜ´¦£¬Öç³¤õÃ×øÑÚËÉ¹Ø¡£¡±\n"NOR,                                                          
                CYN"½Ì»Ê±¯µÀ£º¡¸ÃüÀïÓĞÊ±ÖÕĞëÓĞ£¬·²ÊÂ²»¿ÉÇ¿Çó£»\n
                        Ê±ÖÁÔË¾Íµ½£¬²ÔÌì²»»á¹¼¸º¿àĞÄÈË°¡¡£¡±\n"NOR,                                                          
                CYN"½Ì»ÊÄîµÀ£º¡¸Ò¹Á¹¸§ÇÙÇ§É½ÔÂ£¬Â·Ò£ÃÔÈËÇ§ÖÖ»¨£»\n
                        Æå°Õ²»ÖªÈË»»ÊÀ£¬¾ÆÀ¸ÎŞÄÎ¿Í¶÷¼Ò¡£¡±\n"NOR,                                                          
                CYN"½Ì»ÊÉòÒ÷µÀ£º¡¸Òş¾ÓÓÄÁé¹Å¶´Ìì£¬¿àÑ§ÃØóÅÎŞÏŞÄê£»\n
                        Ë­Èô³¬Ô½Ò»Ïß½ç£¬Ğİ¹ÖÆø¹¦´©ÄÔÌï¡£¡±\n"NOR,                                                          
                CYN"½Ì»ÊËµµÀ£º¡¸¾²ÔÂ½ûµØÊÇÏÉ¾³£¬ĞİÍûÇÖ·¸È¡ÔÂÁé£»\n
                        ÈôÒª³ÑÇ¿²»ÌıÈ°£¬ÉÁµçÅùö¨¶áĞÔÃü¡£¡±\n"NOR,                                                          
        }) );                                                                   
        set("chat_chance_combat",40);
                set("chat_msg_combat", ({
                (: perform_action, "universe.tengin" :),
//              (: exert_function, "blood" :),
//              (: perform_action, "force.blood1" :),
//              (: perform_action, "force.blood2" :),
                (: perform_action, "force.blood3" :),
        }));
        setup();

        add_money("thousand-cash",20);
        carry_object("/open/prayer/obj/boris-boots")->wear();
        carry_object("/open/prayer/obj/boris-cloth")->wear();
        carry_object("/open/prayer/obj/boris-hat")->wear();
        carry_object("/open/prayer/obj/boris-hands")->wear();
        carry_object("/open/prayer/obj/kylin-belt")->wear();
        carry_object("/open/prayer/obj/dragon-icer")->wield();
        create_family("Ê¥»ğ½Ì",1,"½Ì»Ê");
        carry_object("open/prayer/obj/lin-head");

}

void init()
{
        add_action("do_join","join");
        add_action("do_select","select");
        add_action("do_verify","verify");
}

int accept_fight(object who)
{
return notify_fail("½Ì»ÊÀäÀäµÄµÀ : È¥.È¥..È¥...ÉÙÀ´·³ÎÒ¡£\n");
}

int do_verify(string arg)
{
object me,ob,ob1;
me=this_player();
ob=new("open/prayer/obj/woodboard");
ob1=new("open/prayer/obj/ironboard");
if( arg!="board")
  {
    write("ÄãÒªÉêÇëÊ²Ã´\n");
    return 1;
   }
if(me->query("family/family_name")!="Ê¥»ğ½Ì")
  {
    write("Ö»ÓĞÊ¥»ğ½ÌÍ½²Å»áÓĞĞÅÎï\n");
    return 1;
  }

 if( present("wood board",me) || present("iron board",me) )
  {
    write("ÄãÒÑ¾­ÉêÇë¹ıÁË\n");
    return 1;
  }
  
 if ( me->query("marks/ÎÄÎäĞÇ¾ı") )
    {
    write("ÕâÊÇÊ¥»ğ½Ì¸É²¿µÄ×¨ÓÃÌúÅÆ!!¿É²»ÒªµôÁË!!\n");
    ob1->move(me);
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
        if((int)this_player()->query("combat_exp")<=200000)
        {
        command("? " +ob ->query("id"));
        command("say Äã²»ÊÇ°İ¹ı°ËÌìÃÅµÄÃÅÖ÷ÁËÂğ?");
        command("say ÒÔÄãµÄ³Ì¶È»¹²»¹»×Ê¸ñ¸úÎÒÑ§Ï°ÎäÑ§Óë½ÌÎñµÄ´¦Àí°É!");
        command("say ºÃºÃ¸ú×ÅÄã×Ô¼ºµÄÊ¦¸¸¶àÑ§¼¸Äê°É!");
        return 0;
        }
        command("look "+ob->query("id"));
        command("pat");
        command("say ºÃ,Äã¹ûÈ»ÊÇ¿ÉÔìÖ®²Å,Äã¿ÉÒÔÈ¥ÕÒÈıÎ»³¤ÀÏ×÷ÎªÄãÎäÑ§µÄÖ¸µ¼!");
        ob->delete("family");
        command("say ÄãÏëÑ¡Ôñ(select)ÄÄÒ»Î»³¤ÀÏÄØ?");
        command("say ´«¹¦³¤ÀÏ(gonfu_elder)£¬Ö´·¨³¤ÀÏ(lawyer_elder)»¹ÊÇ½äÂÉ³¤ÀÏ(behavior_elder)£¿");
        ob->set_temp("allow_select",1);
        }
        if(ob->query("marks/Ê¥»ğÈı³¤ÀÏ")==1)
        {
        if((int)this_player()->query("combat_exp")<=900000)
        {
        command("? " +ob ->query("id"));
        command("say Äã²»ÊÇÒÑ¾­°İ¹ıÈıÎ»³¤ÀÏ×÷ÎªÀÏÊ¦ÁËÂğ?");
        command("say ÒÔÄãµÄ³Ì¶ÈÀ´¿´£¬Ä¿Ç°»¹²»¹»×Ê¸ñ¸úÎÒÑ§Ï°ÎäÑ§Óë½ÌÎñµÄ´¦Àí°É!");
        command("say ºÃºÃ¸ú×Å³¤ÀÏÃÇÔÙ¶àÑ§¼¸Äê°É!");
        return 0;
        }
        command("look "+ob->query("id"));
        command("pat");
        command("say ºÃ,Äã¹ûÈ»²»ÊÇ·º·ºÖ®±²,Äã¿ÉÒÔÈ¥ÕÒ½ÌÄÚµÄÎÄÎäĞÇ¾ı×÷ÎªÄãÎäÑ§µÄÖ¸µ¼!");
        ob->delete("family");
        command("say Äã¿ÉÒÔÑ¡ÔñÎäĞÇ¾ı(warrior)»òÊÇÎÄĞÇ¾ı(literate)");
        ob->set_temp("allow_select",1);
        }
        if(ob->query("marks/ÎÄÎäĞÇ¾ı")==1)
        {
        if((int)this_player()->query("combat_exp")<=2500000)
        {
        command("? " +ob ->query("id"));
        command("say Äã²»ÊÇÒÑ¾­ÊÇÎÄÎäĞÇ¾ıµÄÈëÊÒµÜ×ÓÁËÂğ?");
        command("say ÒÔÄãµÄ³Ì¶È»¹²»¹»×Ê¸ñ¸úÎÒÑ§Ï°ÎäÑ§Óë½ÌÎñµÄ´¦Àí°É!");
        command("say ºÃºÃ¸ú×ÅÎÄÎäĞÇ¾ı¶àÄ¥Á·Ä¥Á·°É!");
        return 0;
        }
        command("look "+ob->query("id"));
        command("pat");
        command("say ºÃ,Äã¹ûÈ»ÊÇ¿ÉÔìÖ®²Å,´Ó½ñºó¾ÍÓÉ±¾½ÌÖ÷Ç××Ô½Ìµ¼!");
        ob->delete("family");
        command("recruit "+this_player()->query("id"));
        this_player()->set("title","[31mÊ¥»ğ½ÌµÕ´«µÜ×Ó[0m");
        message("mud","[36mÊ¥»ğ½Ì»Ê¡«¡«ÁÖºêÉı·ÅÉù´óĞ¦: \n
        ¹ş¹ş¹ş¹ş....±¾½ÌÖ÷ÊµÔÚÌ«¸ßĞËÀ²£¡£¡\n
        [5m[33m"+this_player()->name()+"[0m[36m½ñºóÊ¥»ğ½ÌµÄÖØµ£¾ÍÂäÔÚÄãµÄ¼çÉÏÁË£¬\n
                        ºÃºÃ¸É°É!!ÀÏ·ò²»»á¿÷ÊÌÄãµÄ!![0m\n",users());
        return ;
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
        if(this_player()->query("officer_class"))
                return notify_fail("½Ì»ÊÀäÀäµÄËµµÀ£ºÄãÔÚÖĞÔ­¼ºµ±¹ı¹ÙÁË£¬ÎÒÊ¥»ğ½Ì²»»¶Ó­Äã!!\n");
        this_player()->set("class","prayer");
        message("mud","\n[33mÊ¥»ğ½Ì»Ê¡«¡«ÁÖºêÉı : ¹ş.¹ş..¹ş...\n
¸÷Î»Ê¥»ğ½ÌµÄµÜ×ÓÃÇ£¬\n
ÈÃÎÒÃÇ»¶Ó­[32m" +this_player()->name()+"[33m¼ÓÈëÎÒ[31mÊ¥»ğ½Ì[33m!![0m\n\n",users());
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
        if(this_player()->query("gender") != "Å®ĞÔ")
        command("say Äã²»ÊÇÅ®ĞÔ, Ñş¹âÃÅ¿ÖÅÂ²»»áÊÕÄãµÄ! ÁíÑ¡Ò»¸ö°É!");
        else
        {
        this_player()->set_temp("allow_7",1);
        command("smile");
        command("say àÅ ,Äã¾ÍÇ°È¥Ñş¹âÃÅ°İÊ¦Ñ§ÒÕ°É!");
        this_player()->set_temp("have_say",1);
        }
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
int accept_kill(object ob)
{
        int i;
        object ob1, hu_fa;
        ob1 = this_object();
        command("exert blood");
        if( !present("hu-fa", environment(ob)) ) {
        tell_room(environment(ob),HIW"\nÍ»È»£¡³å³öÁ½Î»»¤·¨!!\n\n"NOR);
        for(i=0;i<3;i++)
        {
        hu_fa = new("/open/prayer/npc/hu_fa");
        hu_fa->move(environment(ob));
        hu_fa->command("guard pope");
        hu_fa->command("follow "+ob->query("id"));
        hu_fa->kill_ob(ob);
        }}
        write("»¤·¨×İÉí·ÉÆË¹ıÀ´½ĞµÀ£ºÊÄËÀ±£»¤½ÌÖ÷£¡£¡\n");
        write("ÁÖºêÉıÂúÁ³É±ÆøµÄËµµÀ£º¡¸ÎŞÖªĞ¡±²!!ÊÜËÀ°É!!!¡±\n");
        kill_ob(ob);
        command("perform universe.tengin");
        return 1;
}
void greeting(object ob)
{
        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
        {
        command("say ±¾½ÌÖ÷Ò»Éú¹âÃ÷ÀÚÂä£¡£¡×îÍ´ºŞÑ§ÓĞ¶¾ÊõÖ®ÈË£¡£¡");
        kill_ob(ob);
        }
        if( ob->query("class")=="dancer")
        {
        command("say ±¾½ÌÖ÷×îºŞÄÇĞ©ÀûÓÃÃÀÉ«Ö®ÈË£¡£¡");
        kill_ob(ob);
        }
    return;
}
void die()
{

   object winner = query_temp("last_damage_from");
   string name = winner->query("name");
   tell_object(users(),HIR"
       Ô¶´ÓÎ÷Óò´«À´Ò»ÉùÅ­ºğ!!¡®Ê¥»ğ½ÌÖ÷¡¯ÁÖºêÉı²»¹ËÉËÊÆ!!Ç¿ÔËÉíÉÏÄÚÁ¦,Ê¹³öÁË
      "+HIW+"ÏÈÌìÇ¬À¤¹¦µÚÆß¾ø
                          ¡®"+HIC+"Ìì"+HIG+"¾ª"+YEL+"µØ"+BLU+"¶¯"+HIW+"¡¯"HIR"
       Ò»Ê±Ö®¼ä£¬ÌìµØ±äÉ«!!¿ñ·çÅ­Ğ¥!!¾ÅÌìÕæÆø¡¢¾ÅµØÕæÆø£¬ÆëÓ¿ÖÁÁÖºêÉıÖ®ÌåÄÚ!!!
       ºöÈ»¼ä!!ºä~~Ò»Éù¾ŞÏì!!!ÁÖºêÉıÎŞ·¨¼İÊ»ÉíÉÏµÄ¾ÅÌìÕæÆø!!ÕæÆø±¬Ìå¶ø³ö!!ÑªÈâÄ£ºı!!

     "+HIC+"´óÏÀ"+HIY+name+HIC+"ÔÚÅÔĞ¦µÀ£ºÊ¥»ğ½ÌÆøÊıÒÔ¾¡!!½ñºóÊÇÎÒ³Æ°ÔµÄÊ±´úÁË!!¹ş¹ş!!"NOR);
  :: die();
}


void heart_beat()
{
 object me=this_object();
 if(random(100) < 20 && is_fighting()) {
   command("perform universe.tengin");
   me->delete_busy();
   me->clear_condition();
 }
 if( random(100) < 10)
 {
  if( is_fighting() )
  {
   if( query("kee") < query("max_kee") )
    message_vision(HIR"\nÁÖºêÉı³ö»ëÌìĞÄ·¨Ö®±ùĞÄ¾÷£¬ÉíÉÏµÄÉË¿ÚÆæ¼£Ê½ÓúºÏÁË\n"NOR,me);
    me->receive_heal("kee",1000);
    me->receive_heal("gin",200);
    me->receive_heal("sen",200);
    me->delete_busy();
    me->clear_condition();
  }
 }
::heart_beat();
}
