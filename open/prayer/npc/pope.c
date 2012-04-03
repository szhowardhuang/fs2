#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string do_tengin();
string magic_manor1();
string magic_manor2();
string magic_manor3();

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
        set("score",1000000);
        set("age",75);
        set("max_kee",15000);
        set("str", 50);
        set("cor", 50);
        set("cps", 45);
        set("int", 42);
        set("marks/tengin",1);
        set("force",50000);
        set("max_force",50000);
        set("force_factor", 40);
        set("max_gin",10000);
        set("max_sen",10000);
        set_skill("cure", 120);
        set_skill("superforce", 250);
        set_skill("dodge", 120);
        set_skill("force",150);
        set_skill("move", 120);
        set_skill("literate",120);
        set_skill("parry", 120);
        set_skill("array",130);
        set_skill("fire-array",130);
        set_skill("unarmed",120);
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
        set("functions/blood/level",200);
        set("functions/tengin/level",100);
        set("functions/bluesea/level",120);
        set("inquiry",([
        "Ìì¾ªµØ¶¯"      :       (: do_tengin :),
        "¾ÛÁéÒı"        :       (: magic_manor1 :),
        "¾ÛÁéÉ½×¯"      :       (: magic_manor2 :),
        "Èı¼şÊÂ"        :       (: magic_manor3 :),
        ]));
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
                set("chat_chance_combat",50);
                set("chat_msg_combat", ({
                (: perform_action, "force.blood3" :),
                (: perform_action, "force.bluesea3" :),
        }));
        setup();

        add_money("cash",20);
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
      if(ob->query("combat_exp")<=200000)
      {
        command("? " +ob ->query("id"));
        command("say Äã²»ÊÇ°İ¹ı°ËÌìÃÅµÄÃÅÖ÷ÁËÂğ?");
        command("say ÒÔÄãµÄ³Ì¶È»¹²»¹»×Ê¸ñ¸úÎÒÑ§Ï°ÎäÑ§Óë½ÌÎñµÄ´¦Àí°É!");
        command("say ºÃºÃ¸ú×ÅÄã×Ô¼ºµÄÊ¦¸¸¶àÑ§¼¸Äê°É!");
        return 0;
      }
      else
      {
        command("look "+ob->query("id"));
        command("pat");
        command("say ºÃ,Äã¹ûÈ»ÊÇ¿ÉÔìÖ®²Å,Äã¿ÉÒÔÈ¥ÕÒÈıÎ»³¤ÀÏ×÷ÎªÄãÎäÑ§µÄÖ¸µ¼!");
        ob->delete("family");
        command("say ÄãÏëÑ¡Ôñ(select)ÄÄÒ»Î»³¤ÀÏÄØ?");
        command("say ´«¹¦³¤ÀÏ(gonfu_elder)£¬Ö´·¨³¤ÀÏ(lawyer_elder)»¹ÊÇ½äÂÉ³¤ÀÏ(behavior_elder)£¿");
        ob->set_temp("allow_select",1);
      }
    }
    if(ob->query("marks/Ê¥»ğÈı³¤ÀÏ")==1)
    {
      if(ob->query("combat_exp")<=900000)
      {
        command("? " +ob ->query("id"));
        command("say Äã²»ÊÇÒÑ¾­°İ¹ıÈıÎ»³¤ÀÏ×÷ÎªÀÏÊ¦ÁËÂğ?");
        command("say ÒÔÄãµÄ³Ì¶ÈÀ´¿´£¬Ä¿Ç°»¹²»¹»×Ê¸ñ¸úÎÒÑ§Ï°ÎäÑ§Óë½ÌÎñµÄ´¦Àí°É!");
        command("say ºÃºÃ¸ú×Å³¤ÀÏÃÇÔÙ¶àÑ§¼¸Äê°É!");
        return 0;
      }
      else
      {
        command("look "+ob->query("id"));
        command("pat");
        command("say ºÃ,Äã¹ûÈ»²»ÊÇ·º·ºÖ®±²,Äã¿ÉÒÔÈ¥ÕÒ½ÌÄÚµÄÎÄÎäĞÇ¾ı×÷ÎªÄãÎäÑ§µÄÖ¸µ¼!");
        ob->delete("family");
        command("say Äã¿ÉÒÔÑ¡ÔñÎäĞÇ¾ı(warrior)»òÊÇÎÄĞÇ¾ı(literate)");
        ob->set_temp("allow_select",1);
      }
    }
    if(ob->query("marks/ÎÄÎäĞÇ¾ı")==1)
    {
      if(ob->query("combat_exp")<=2500000)
      {
        command("? " +ob ->query("id"));
        command("say Äã²»ÊÇÒÑ¾­ÊÇÎÄÎäĞÇ¾ıµÄÈëÊÒµÜ×ÓÁËÂğ?");
        command("say ÒÔÄãµÄ³Ì¶È»¹²»¹»×Ê¸ñ¸úÎÒÑ§Ï°ÎäÑ§Óë½ÌÎñµÄ´¦Àí°É!");
        command("say ºÃºÃ¸ú×ÅÎÄÎäĞÇ¾ı¶àÄ¥Á·Ä¥Á·°É!");
        return 0;
      }
      else
      {
        command("look "+ob->query("id"));
        command("pat");
        command("say ºÃ,Äã¹ûÈ»ÊÇ¿ÉÔìÖ®²Å,´Ó½ñºó¾ÍÓÉ±¾½ÌÖ÷Ç××Ô½Ìµ¼!");
        ob->delete("family");
        command("recruit "+ob->query("id"));
        ob->set("title","[31mÊ¥»ğ½ÌµÕ´«µÜ×Ó[0m");
        message("mud","[36mÊ¥»ğ½Ì»Ê¡«¡«ÁÖºêÉı·ÅÉù´óĞ¦: \n
        ¹ş¹ş¹ş¹ş....±¾½ÌÖ÷ÊµÔÚÌ«¸ßĞËÀ²£¡£¡\n
        [5m[33m"+ob->name()+"[0m[36m½ñºóÊ¥»ğ½ÌµÄÖØµ£¾ÍÂäÔÚÄãµÄ¼çÉÏÁË£¬\n
                        ºÃºÃ¸É°É!!ÀÏ·ò²»»á¿÷ÊÌÄãµÄ!![0m\n",users());
        return ;
      }
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
       who->set_temp("allow_1",1);
       command("smile");
       command("say àÅ ,Äã¾ÍÈ¥¼ÓÈëÌì»úÃÅ°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "ÌìÊàÃÅ" || str == "tanshu")
    {
      message_vision(HIC"$NËµµÀ£ºÌìÊàÃÅ\n"NOR,who);
      who->set_temp("allow_2",1);
      command("smile");
      command("say àÅ ,Äã¾Í¼ÓÈëÌìÊàÃÅ°É!");
      who->set_temp("have_say",1);
      return 1;
    }
    if(str == "ÌìÈ¨ÃÅ" || str == "tanchun")
    {
       message_vision(HIC"$NËµµÀ£ºÌìÈ¨ÃÅ\n"NOR,who);
       who->set_temp("allow_3",1);
       command("smile");
       command("say àÅ ,Äã¾Í½øÈ¥ÌìÈ¨ÃÅĞŞÁ·°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "Ììè¯ÃÅ" || str == "tanshun")
    {
       message_vision(HIC"$NËµµÀ£ºÌìè¯ÃÅ\n"NOR,who);
       who->set_temp("allow_4",1);
       command("smile");
       command("say àÅ ,Äã¾Íµ½Ììè¯ÃÅºÃºÃÄ¥Á·°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "ÓñºâÃÅ" || str == "uhen")
    {
       message_vision(HIC"$NËµµÀ£ºÓñºâÃÅ\n"NOR,who);
       who->set_temp("allow_5",1);
       command("smile");
       command("say àÅ ,Äã¾Í¼ÓÈëÓñºâÃÅ°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "¿ªÑôÃÅ" || str == "kiyan")
    {
       message_vision(HIC"$NËµµÀ£º¿ªÑôÃÅ\n",who);
       who->set_temp("allow_6",1);
       command("smile");
       command("say àÅ ,Äã¾ÍÇ°Íù¿ªÑôÃÅÑ§Ï°°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "Ñş¹âÃÅ" || str == "youkoun")
    {
      message_vision(HIC"$NËµµÀ£ºÑş¹âÃÅ\n"NOR,who);
      if(who->query("gender") != "Å®ĞÔ")
        command("say Äã²»ÊÇÅ®ĞÔ, Ñş¹âÃÅ¿ÖÅÂ²»»áÊÕÄãµÄ! ÁíÑ¡Ò»¸ö°É!");
      else
      {
        who->set_temp("allow_7",1);
        command("smile");
        command("say àÅ ,Äã¾ÍÇ°È¥Ñş¹âÃÅ°İÊ¦Ñ§ÒÕ°É!");
        who->set_temp("have_say",1);
      }
      return 1;
    }
    if(str == "ÕóÊÆÃÅ" || str == "zhenche")
    {
       message_vision(HIC"$NËµµÀ£ºÕóÊÆÃÅ\n"NOR,who);
       who->set_temp("allow_8",1);
       command("smile");
       command("say àÅ ,Äã¾ÍÇ°È¥ÕóÊÆÃÅ°İÊ¦Ñ§ÒÕ°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "´«¹¦³¤ÀÏ" || str == "gonfu" || str == "gonfu_elder")
    {
       if(who->query("combat_exp") < 200000){
         command("say ÄãÕâ¼Ò»ï¾­Ñé²»×ã£¬È¥°ËÌìÃÅ¶àÑ§µã¶«Î÷°É!!");
         return 1;
       }
       if(!who->query("marks/Ê¥»ğ°ËÌìÃÅ")){
         command("say Á¬°ËÌìÃÅ¶¼Ã»È¥¹ı£¬»¹ÏëÈ¥³¤ÀÏÄÇÑ§Ï°??ÄãÕâ½Ğ³ÕĞÄÍıÏë!!");
         return 1;
       }
       message_vision(HIC"$NËµµÀ£º´«¹¦³¤ÀÏ\n"NOR,who);
       who->set_temp("allow_9",1);
       command("smile");
       command("say àÅ ,Äã¾ÍÈ¥´«¹¦³¤ÀÏÄÇ¶ùÑ§ÒÕ°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "Ö´·¨³¤ÀÏ" || str == "lawyer" || str == "lawyer_elder")
    {
       if(who->query("combat_exp") < 200000){
         command("say ÄãÕâ¼Ò»ï¾­Ñé²»×ã£¬È¥°ËÌìÃÅ¶àÑ§µã¶«Î÷°É!!");
         return 1;
       }
       if(!who->query("marks/Ê¥»ğ°ËÌìÃÅ")){
         command("say Á¬°ËÌìÃÅ¶¼Ã»È¥¹ı£¬»¹ÏëÈ¥³¤ÀÏÄÇÑ§Ï°??ÄãÕâ½Ğ³ÕĞÄÍıÏë!!");
         return 1;
       }
       message_vision(HIC"$NËµµÀ£ºÖ´·¨³¤ÀÏ\n"NOR,who);
       who->set_temp("allow_10",1);
       command("smile");
       command("say àÅ ,Äã¾ÍÈ¥Ö´·¨³¤ÀÏÄÇ¶ùÑ§ÒÕ°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "½äÂÉ³¤ÀÏ" || str == "behavior" || str == "behavior_elder")
    {
       if(who->query("combat_exp") < 200000){
         command("say ÄãÕâ¼Ò»ï¾­Ñé²»×ã£¬È¥°ËÌìÃÅ¶àÑ§µã¶«Î÷°É!!");
         return 1;
       }
       if(!who->query("marks/Ê¥»ğ°ËÌìÃÅ")){
         command("say Á¬°ËÌìÃÅ¶¼Ã»È¥¹ı£¬»¹ÏëÈ¥³¤ÀÏÄÇÑ§Ï°??ÄãÕâ½Ğ³ÕĞÄÍıÏë!!");
         return 1;
       }
       message_vision(HIC"$NËµµÀ£º½äÂÉ³¤ÀÏ\n"NOR,who);
       who->set_temp("allow_11",1);
       command("smile");
       command("say àÅ ,Äã¾ÍÈ¥½äÂÉ³¤ÀÏÄÇ¶ùÑ§ÒÕ°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "ÎäĞÇ¾ı" || str == "warrior")
    {
       if(who->query("combat_exp") < 900000){
         command("say ÄãÕâ¼Ò»ï¾­Ñé²»×ã£¬È¥³¤ÀÏÄÇÑ§µã¶«Î÷°É!!");
         return 1;
       }
       if(!who->query("marks/Ê¥»ğÈı³¤ÀÏ")){
         command("say Á¬³¤ÀÏÄÇ¶¼Ã»È¥¹ı£¬»¹ÏëÈ¥ÎÄÎäĞÇ¾ıÄÇÑ§Ï°??ÄãÕâ½Ğ³ÕĞÄÍıÏë!!");
         return 1;
       }
       message_vision(HIC"$NËµµÀ£ºÎäĞÇ¾ı\n"NOR,who);
       who->set_temp("allow_12",1);
       command("smile");
       command("say àÅ ,Äã¾ÍÈ¥ÎäĞÇ¾ıÄÇ¶ùÑ§ÒÕ°É!");
       who->set_temp("have_say",1);
       return 1;
    }
    if(str == "ÎÄĞÇ¾ı" || str == "literate")
    {
       if(who->query("combat_exp") < 900000){
         command("say ÄãÕâ¼Ò»ï¾­Ñé²»×ã£¬È¥³¤ÀÏÄÇÑ§µã¶«Î÷°É!!");
         return 1;
       }
       if(!who->query("marks/Ê¥»ğÈı³¤ÀÏ")){
         command("say Á¬³¤ÀÏÄÇ¶¼Ã»È¥¹ı£¬»¹ÏëÈ¥ÎÄÎäĞÇ¾ıÄÇÑ§Ï°??ÄãÕâ½Ğ³ÕĞÄÍıÏë!!");
         return 1;
       }
       message_vision(HIC"$NËµµÀ£ºÎÄĞÇ¾ı\n"NOR,who);
       who->set_temp("allow_13",1);
       command("smile");
       command("say àÅ ,Äã¾ÍÈ¥ÎÄĞÇ¾ıÄÇ¶ùÑ§ÒÕ°É!");
       who->set_temp("have_say",1);
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
        ob = this_player();
        command("exert blood");
        if( !present("hu-fa", environment(ob1)) ) {
        tell_room(environment(ob1),HIW"\nÍ»È»£¡³å³öÁ½Î»»¤·¨!!\n\n"NOR);
        for(i=0;i<2;i++)
        {
        hu_fa = new("/open/prayer/npc/hu_fa");
        hu_fa->move(environment(ob1));
        hu_fa->kill_ob(ob);
        }}
        write("»¤·¨×İÉí·ÉÆË¹ıÀ´½ĞµÀ£ºÊÄËÀ±£»¤½ÌÖ÷£¡£¡\n");
        write("ÁÖºêÉıÂúÁ³É±ÆøµÄËµµÀ£º¡¸ÎŞÖªĞ¡±²!!ÊÜËÀ°É!!!¡±\n");
        kill_ob(ob);
        command("perform unarmed.tengin");
        return 1;
}

void greeting(object ob)
{
        ob=this_player();
        if ( ob->query_skill("coldpoison",1) )
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
        object winner=query_temp("last_damage_from");
        string name1;
        int j;
        if(!winner)
        {
        ::die();
        return ;
        }
        name1 = winner->query("name");

        // by ACKY
        if( winner->query("clan/id") && userp(winner) )
                CLAN_D->add_clanset( winner->query("clan/id"), "develop" , 5 );

        tell_object(users(),HIR"
   Ô¶´ÓÎ÷Óò´«À´Ò»ÉùÅ­ºğ!!¡®Ê¥»ğ½ÌÖ÷¡¯ÁÖºêÉı²»¹ËÉËÊÆ!!Ç¿ÔËÉíÉÏÄÚÁ¦,Ê¹³öÁË
                    "+HIW+"ÏÈÌìÇ¬À¤¹¦µÚÆß¾ø
                                   ¡®"+HIC+"Ìì"+HIG+"¾ª"+YEL+"µØ"+BLU+"¶¯"+HIW+"¡¯"HIW"
   Ò»Ê±Ö®¼ä£¬ÌìµØ±äÉ«!!¿ñ·çÅ­Ğ¥!!¾ÅÌìÕæÆø¡¢¾ÅµØÕæÆø£¬ÆëÓ¿ÖÁÁÖºêÉıÖ®ÌåÄÚ!!!
"HIR"ºöÈ»¼ä!!ºä~~Ò»Éù¾ŞÏì!!!ÁÖºêÉıÎŞ·¨¼İÔ¦ÉíÉÏµÄ¾ÅÌìÕæÆø!!ÕæÆø±¬Ìå¶ø³ö!!ÑªÈâÄ£ºı!!

    "+HIC+"´óÏÀ"+HIY+name1+HIC+"ÔÚÅÔĞ¦µÀ£ºÊ¥»ğ½ÌÆøÊıÒÔ¾¡!!½ñºóÊÇÎÒ³Æ°ÔµÄÊ±´úÁË!!¹ş¹ş!!\n"NOR);
        if(winner->query("family/family_name")=="ÏÉ½£ÅÉ" && winner->query("killyao")==1 && winner->query("bloodsword")==1)
        {
        object ob;
        ob=new("/open/gsword/obj1/eyes.c");
        tell_object(winner,HIR"Äã´ÓÁÖºêÉıµÄÊ¬ÌåÉÏÍÚ³öÁËÒ»¶ÔÑÛ¾¦..\n"NOR);
        winner->set_temp("swordeyes",1);
        ob->move(winner);
        }
        if ( winner->query_temp("bless")==1 )
        {
        j=random(6000);
          if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
          {
          new("/log/sky/emperor_stone")->move(environment(winner));
          message_vision(HIM"\n´ÓÁÖºêÉıµÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/emperor_stone",sprintf("%s(%s) ÈÃÁÖºêÉıµôÏÂÁË»ÊÕßÊ¯ÓÚ %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }else{
        j=random(12000);
          if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
          {
          new("/log/sky/emperor_stone")->move(environment(winner));
          message_vision(HIM"\n´ÓÁÖºêÉıµÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/emperor_stone",sprintf("%s(%s) ÈÃÁÖºêÉıµôÏÂÁË»ÊÕßÊ¯ÓÚ %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }
        ::die();
}

void heart_beat()
{
 object me=this_object();
 if(random(100) < 20 && is_fighting()) {
   command("perform unarmed.tengin");
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

string do_tengin()
{
object who=this_player();
if(who->query("class")=="prayer")
{
if(who->query("combat_exp") > 3500000 )
{
if(who->query("marks/tengin") != 1 )
{
command("say Äã½­ºşÀúÁ·ÒÑ¹»£¬ÇÒÎªÎÒµÕ´«µÜ×Ó¡£");
command("say ºÃ°É£¡ÎÒ´«Äã¡®Ìì¾ªµØ¶¯¡¯£¡");
who->set("marks/tengin",1);
return ":)";
} else {
command("say ÎÒÒÑ´«ÄãÁË£¬ºÃºÃÔËÓÃ°É£¡");
return ":)";
}} else {
command("say Äã½­ºşÀúÁ·²»×ãµÈ 350 ÍòÔÙÀ´°É£¡");
return ":)";
}
} else {
command("say ÎÒ²»ÖªµÀ£¡");
return ":)";
}
}

string magic_manor1()
{
        object me;
        me=this_player();
        if(!present("magic sign",me) && me->query("quests/can_go_magic-manor"))
        {
        command("say ÕâÃ´ÖØÒªµÄ¶«Î÷ÄãÔõÃ´Åª¶ªÁË!!");
        command("say ĞÒºÃÕâ¶«Î÷Èô·ÇÎÒ´«ÊÚÊ¹ÓÃ·½·¨£¬ÊÇÎŞ·¨Ê¹ÓÃµÄ£¬ÎÒÔÙÄÃÒ»¸ö¸øÄã°É¡£");
        new("/open/magic-manor/obj/magic-sign")->move(this_player());
        return "ÏÂ´Î¼ÇµÃĞ¡ĞÄĞ©£¬±ğÔÙÅª¶ªÁË!!";
        }

        if(present("magic sign",me) && me->query("quests/can_go_magic-manor"))
        {
        command("say ¾ÛÁéÒıÒÑ¾­¸øÄãÁË£¬ºÃºÃÊ¹ÓÃ°É£¬ÇĞÄªÒÅÊ§ÁË¡£");
        return "¾ÛÁéÉ½×¯µÄÈë¿ÚÎ»ÖÃ¾ÍÔÚ·çÔÆÕò¶«·½²»Ô¶´¦µÄÃÜÁÖÄÚ¡£\n";
        }

        else if( me->query_temp("quests/magic-maonr-02") > 2 )
        {
        return "ÏÈ°ÑÎÒ½»´ıµÄÈÎÎñÍê³É°É!!";
        }

        else if( me->query_temp("quests/magic-maonr-02") && me->query_temp("quests/magic-maonr-02") <= 2 )
        {
        return "¿´À´ÄãÖªµÀµÄ²»ÉÙÁË£¬×íÎÊÌìÒ²ÕæÊÇµÄ£¬ËµÕâÃ´¶à×÷Ê²Ã´ ...@#$Q%";
        }

        else
        {
        return "ÎŞ¶Ë¶ËµÄÎÊÎÒÕâ×öÊ²Ã´£¬¿ì¹ö¿ª!!\n";
        }
}

string magic_manor2()
{
        object me;
        me=this_player();

        if( me->query("quests/can_go_magic-manor") )
        {
        return "×î½üÉ½×¯ÕæÊÇ±ä»¯ºÃ´ó£¬ºÃÏë»ØÈ¥Ò»ÌË¿´¿´Ñ½!!";
        }

        else if( me->query_temp("quests/magic-manor-02") == 2 )
        {
        me->set_temp("quests/magic-manor-02",3);
        return "¾ÛÁéÉ½×¯ÏÊÉÙÔÚ½­ºşÉÏ»î¶¯£¬ËùÒÔÖªµÀµÄÈËÓĞÏŞ¡£\n"
        +"            ²»Â÷Äã£¬ÎÒÒ²ÔøÊÇ¾ÛÁéÉ½×¯µÄÒ»·İ×Ó¡£\n"
        +"            Èç¹ûÄãÏëÒª½øÈë¾ÛÁéÉ½×¯£¬ÎÒ¿ÉÒÔÖúÄãÒ»±²Ö®Á¦¡£\n"
        +"            ²»¹ı......ÄãÒªÏÈÌæÎÒÍê³ÉÈı¼şÊÂ²ÅĞĞ¡£\n";
        }

        else
        {
        return "¾ÛÁéÉ½×¯£¬´«ËµÊÇ¸öÉñÃØµÄµØ·½£¬ÎÒÖªµÀµÄÒ²²»¶à!!";
        }
}

string magic_manor3()
{
        object me;
        me=this_player();

        if( me->query("quests/can_go_magic-manor") )
        {
        return "¶à¿÷ÄãÍê³ÉÕâÈı¼şÊÂ£¬ÈÃÊ¥»ğ½ÌÔÚ½­ºşµÄµØÎ»ÓÖ¸ü¼Ó³ç¸ßÁË¡£\n";
        }

        else if( me->query_temp("quests/magic-manor-02") == 3 )
        {
        command("hmm");
        call_out("three_check1",3,me);
        return "´ıÎÒÏëÒ»ÏÂ£¬ÒªÈÃÄãÍê³ÉµÄÈı¼şÊÂ¡£\n";
        }

        else if( me->query_temp("quests/magic-manor-02") && me->query_temp("quests/magic-manor-02") < 3 )
        {
        return "ºÙºÙ£¬ÄãµÄ½ø¶ÈÒ²Î´ÃâÌ«¿ìÁË°É!!\n";
        }

        else
        {
        return "Ê²Ã´Èı¼şÊÂÑ½£¬Ìı²»¶®À²!!\n";
        }
}

int three_check1()
{
        object me,ob;

        me=this_player();
        ob=this_object();

        if( me->query_temp("quests/magic-manor-02") == 3 && !me->query("quests/can_go_magic-manor") )
        {
        command("say ºÃÁË£¬ÎÒÏëºÃÁË!!");
        command("say µÚÒ»¼şÊÂÇé£º´«Ëµ³¤°×É½ÓĞÒ»¸öÇ§ÄêÊ÷Ñı£¬ÇëÄã´ø»ØËûµÄÒ»Æ¬Ê÷Ò¶¡£");
        command("say ´ËÑıµÄ·¨Êõ·Ç³£À÷º¦£¬Á¬ÎÒ¶¼°ÜÔÚËûÊÖÏÂ¡£");
        command("say µÈÄãÄÃµ½ÁË£¬ÎÒÔÙ¸æËßÄãµÚ¶ş¼şÊÂÇé°É!!");
        me->set_temp("quests/magic-manor-02",4);
        }else{
        command("say àÅ!!");
        }
        return 1;
}

int three_check2()
{
        object me,ob;

        me=this_player();
        ob=this_object();

        if( me->query_temp("quests/magic-manor-02") == 5 && !me->query("quests/can_go_magic-manor") )
        {
        command("say ºÃÁË£¬ÎÒÏëºÃÁË!!");
        command("say µÚ¶ş¼şÊÂÇé£ºÉßÕ¯Õ¯Ö÷µÄÏîÉÏÈËÍ·¡£");
        command("say ¾İËµ´ËÈËÉúĞÔ²Ğ±©£¬ÊÇ·Ç²»·Ö£¬Õ¼¾İÉßÕ¯ÎªÍõ, »¹ËÄ´¦¼éÒùÂ°ÂÓ£¬ÎŞ¶ñ²»×÷¡£");
        command("say µÈÄãÄÃµ½ÁË£¬ÎÒÔÙ¸æËßÄãµÚÈı¼şÊÂÇé°É!!");
        me->set_temp("quests/magic-manor-02",6);
        }else{
        command("say àÅ!!");
        }
        return 1;
}

int three_check3()
{
        object me,ob;

        me=this_player();
        ob=this_object();

        if( me->query_temp("quests/magic-manor-02") == 7 && !me->query("quests/can_go_magic-manor") )
        {
        command("say ºÃÁË£¬ÎÒÏëºÃÁË!!");
        command("say ÕâÊÇ×îºóÒ»¼şÁË£ºÎÒÒªÒ»¸ö·ÙÌìÄ§ÍõµÄÈËÍ·¡£");
        command("say Ä§½çµÄÍõÕßÖ®Íõ£¬Èç¹ûÄãÄÜ´ò°ÜËû£¬×ãÖ¤Ã÷ÄãµÄÄÜÁ¦¡£");
        command("say ¾ÍµÈÄãµÄºÃÏûÏ¢ÁË!!");
        me->set_temp("quests/magic-manor-02",8);
        }else{
        command("say àÅ!!");
        }
        return 1;
}

int magic_sign()
{
        object me,obj;

        me=this_player();

        if( me->query_temp("quests/magic-manor-02") == 9 && !me->query("quests/can_go_magic-manor") )
        {
        command("say ÎÒ³öµÄÈı¼şÊÂÆäÊµÊÇÒª¿¼ÑéÄãµÄÄÜÄÍ¡¢Æ·ĞÔºÍºÏÈºĞÔµÄ¡£");
        command("say ¾ÛÁéÉ½×¯ÕıĞèÒªÏñÄãÕâÑùµÄÈË²Ä£¬ÎÒ¹ûÕæÊÇÃ»ÓĞ¿´´íÄã¡£");
        command("say Õâ¿é¾ÛÁéÒı£¬¾Í½»¸øÄãÁË£¬Ê¹ÓÃµÄ·½·¨ºÜ¼òµ¥£¬ÎÒÕâ¾Í½ÌÄã.......¡£");
        command("say ÕâÑù×ÓÄã¶®ÁË°É£¬Ö»Òª×ßÔÚÕıÈ·µÄÎ»ÖÃ£¬Ëü¾Í»áÒıµ¼ÄãÁË¡£");
        me->delete_temp("quests/magic-manor-01");
        me->delete_temp("quests/magic-manor-02");
        me->set("quests/can_go_magic-manor",1);
        obj=new("/open/magic-manor/obj/magic-sign");
        obj->move(me);
        message_vision("ÁÖÉıºê½»¸ø$NÒ»¿é$n¡£\n",me,obj);
        command("say ½ÓÏÂÀ´ÎÒÔÙ´«Ò»µã¹¦Á¦¸øÄã°É!!");
        command("say Ï£ÍûÄãÄÜÎª¾ÛÁéÉ½×¯¶à¾¡Ò»µãĞÄÁ¦¡£");
        me->start_busy(15);
        message_vision(HIY"ÁÖºêÉı½«Ë«ÊÖÖÃÓÚ$N°Ù»áÓëëşÖĞÁ½´óÑ¨£¬Ò»¹ÉÄÚ¾¢ÓÉÁÖºêÉıµÄÊÖÕÆ×êÈë$NÌåÄÚ¡£\n"NOR,me);
        call_out("trans_force",10,me);
        }else{
        command("say àÅ!!");
        }
        return 1;
}

int trans_force()
{
        object me;
        int force;
        me=this_player();
        force=me->query_skill("force",1);
        {
        message_vision(HIY"Ö»¼ûÁÖºêÉıÁ³¼ÕÉÏÂúÊÇº¹Ë®£¬²»Ò»»á¶ù£¬ĞĞ¹¦Íê±Ï¡£\n"NOR,me);
        tell_object(me,HIC"ÄãÖ»¾õÈ«Éí¾«ÆøÉñ±¥Âú£¬ÉíÉÏµÄ½îÂö»íÈ»¹áÍ¨£¬ÄÚÁ¦¸üÊÇÓĞËù³¤½ø¡£\n"NOR);
        me->set_skill("force",force+30);
        me->delete_busy();
        }
        return 1;
}

int accept_object(object me,object ob)
{
        int om,ot;
        me=this_player();
        om=ob->query("magic-manor");
        ot=me->query_temp("quests/magic-manor-02");

        if( !ot )
        {
          if( om == 2 )
          {
          command("say Õâ·âĞÅÊÇÄÇÀ´µÄÑ½£¿¿´À´ÄãÒ²·ÇÊÇÉÆÁ¼ÈËÊË!!");
          command("say ¾ÍÈÃ±¾½Ì»ÊÎªÎäÁÖ³ıº¦°É!!");
                  destruct(ob);
          kill_ob(me);
          }else{
          command("say ±¾½Ì»ÊÕıÔÚÃ¦!!   È¥! È¥!! È¥!!!");
          destruct(ob);
          return 0;
          }
        }else{
          if( ot == 1 && om == 2)
          {
          command("say àÅ£¬Õâ·âĞÅ´óÓĞÀ´Àú£¬ÊÇ×íÎÊÌìÇ×±ÊËùĞ´µÄÃ»´í!!");
          command("say ÄÜÈÃ×íÎÊÌì¿´µÄÆğµÄÈË£¬¿´À´ÄãµÄ±¾ÊÂ¿É²»Ğ¡à¸!!");
          command("say Ëµ°É£¡ÄãÀ´ÕÒÎÒÊÇ²»ÊÇÏëÎÊÓĞ¹Ø¾ÛÁéÉ½×¯µÄÊÂÑ½£¿");
                  destruct(ob);
          me->set_temp("quests/magic-manor-02",2);
          return 1;
          }else{
            if( ot == 4 && om == 3 && me->query_temp("quests/kill-dance") == 1 )
            {
            me->set_temp("quests/magic-manor-02",5);
            me->delete_temp("quests/kill-dance");
            command("hmm");
                        destruct(ob);
            call_out("three_check2",3,me);
            return 1;
            }else{
              if( ot == 4 && om == 3 && me->query_temp("quests/kill-dance") != 1 )
              {
              command("say ¿´ÄãÒ»¸±¾«Éñ±¥ÂúµÄÑù×Ó£¬ÕâÆ¬Ò¶×Ó²»ÊÇÄãÇ×ÊÖÄÃµ½µÄ°É£¿");
              destruct(ob);
              return 1;
              }else{
                if( ot == 6 && om == 4 && me->query_temp("quests/kill-snake") == 1 )
                {
                me->set_temp("quests/magic-manor-02",7);
                me->delete_temp("quests/kill-snake");
                command("hmm");
                                destruct(ob);
                call_out("three_check3",3,me);
                return 1;
                }else{
                  if( ot == 6 && om == 4 && me->query_temp("quests/kill-snake") != 1 )
                  {
                  command("say Õâ¸ö......ÉßÀÉ¾ı²»ÊÇÄãÇ×ÊÖÉ±ËÀµÄ°É£¿");
                  destruct(ob);
                  return 1;
                  }else{
                    if( ot == 8 && om == 5 )
                    {
                    me->set_temp("quests/magic-manor-02",9);
                    call_out("magic_sign",1,me);
                                        destruct(ob);
                    return 1;
                    }else{
                    command("say ÎÒÏÖÔÚÓÖÃ»ÓĞÒªÕâ¸ö¶«Î÷£¬ÄãÄÃ¸øÎÒ×öÊ²Ã´£¿");
                    destruct(ob);
                    }
                  }
                }
              }
            }
          }
        }
        return 1;
}
