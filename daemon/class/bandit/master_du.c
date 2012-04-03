// dusa.c by oda

#include </open/open.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string do_ask();
string do_ask2();

void create()
{
        set_name("¶ÅÉ±", ({ "du sa", "du", "sa" }) );
        set("nickname", "ÑªÊÖ");
        set("title", "¶ñÈË¹È´óÍ·Ä¿");
        set("gender", "ÄĞĞÔ");
        set("age", 41);
        set("class", "bandit");
        set("guild_master", 1);
        set("bellicosity", 2500);
        set("attitude", "badman");
        set("combat_exp", 3000000);
        set("long","Õâ¸öÈËÉí×ÓÓÖÊİÓÖ³¤£¬Ò»ÉíÑ©°×µÄ³¤ÅÛ£¬ËûµÄÁ³¾Í¸úËûµÄÒÂ·şÒ»Ñù²Ô°×¡£
×ĞÏ¸Ò»¿´£¬Äã²Å·¢ÏÖËûµÄ×óÊÖÒÑ¾­¶ÏÁË£¬²¢ÇÒ×°ÉÏÁËÒ»¸ö·æÀûµÄ¸Ö¹³¡£Ëû¾ÍÊÇ¶ñÈË¹ÈÖĞ
×îÁîÈËÎ·¾åµÄÊ®´ó¶ñÈËÖ®Ê×£­¡¸ÑªÊÖ¡±¶ÅÉ±¡£");

        set("str", 40);
        set("cor", 40);
        set("int", 24);
        set("spi", 22);
        set("cps", 30);
        set("con", 30);
        set("per", 16);
        set("max_gin", 10000);
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("gin", 10000);
        set("kee", 10000);
        set("sen", 10000);
        set("max_force",5000);
        set("force",5000);
        set("force_factor", 10);

        set_skill("array",80);
        set_skill("magic",20);
        set_skill("spells",20);
        set_skill("bad-array",100);
        set_skill("change",100);
        set_skill("dodge", 80);
        set_skill("sword",80);
        set_skill("ghost-steps",100);
        set_skill("force", 70);
        set_skill("badforce",100);
    set_skill("counter",80);
        set_skill("move", 80);
        set_skill("parry",70);
        set_skill("unarmed",80);
        set_skill("cure",50);
        set_skill("badstrike",100);
        set_skill("gamble", 50);
        set_skill("literate",30);
        map_skill("unarmed", "badstrike");
        map_skill("array", "bad-array");
        map_skill("parry", "badstrike");
        map_skill("force", "badforce");
        map_skill("dodge", "ghost-steps");
        map_skill("move", "ghost-steps");
        set("quests/badroar",1);
        set("functions/evil-blade/level",100);
        set("functions/badroar/level",50);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.evil-blade" :),
        (: perform_action, "unarmed.badroar" :),
        }) );
        set("inquiry",([
        "×óÊÖ" : (: do_ask :),
        "¶ñÈËÉ­ÁÖ" : (: do_ask2 :),
        ]));

        setup();
        create_family("¶ñÈË¹È",1,"´óÍ·Ä¿");
        set("family/next_title", "Ğ¡à¶à¶");
        add_money("gold", 10);
        carry_object(BAD_OBJ"badhelmet")->wear();
        carry_object(BAD_OBJ"evil_claw.c")->wield();
}

void init()
{
        add_action("do_join", "join");
}

int accept_fight(object who)
{
        message_vision("¶ÅÉ±ÀäÀäµÄÃéÁË$NÒ»ÑÛ¡£\n", who);
        command("say ºß£¬²»×ÔÁ¿Á¦µÄ¼Ò»ï¡£\n");
        return 1;
}

void attempt_apprentice(object who)
{
        if( !who->query("class") ) {
                command("shake "+who->query("id"));
                command("say µÈÄã¼ÓÈë(join)µÁÔôÕâÒ»ĞĞÔÙËµ°É¡£");
                return;
        }
        if( who->query("class")!="bandit" ) {
                command("stare "+who->query("id"));
                command("say ¶ñÈË¹ÈÊÇ¸ÉÇ¿µÁµÄ£¬ÄãÃÇÕâĞ©ÉÆÁ¼ÀÏ°ÙĞÕ»¹ÊÇ¿ì¹ö°É£¡");
                return;
        }
        if(!who->query("quests/badman_license")) {
                tell_object(who,"¶ÅÉ±ÀäÀäµÄ¿´×ÅÄãËµ£º¾ÍÆ¾ÄãÒ²Ïë¼ÓÈë¶ñÈË¹È£¿µÈÄã³ıµôÑàÄÏÌìÕâ¼Ò»ïÔÙËµ°É£¡\n");
                who->delete_temp("pending/apprentice");
                return;
        }
        command("look "+who->query("id"));
        command("say ºÃ£¡ÎÒ¾ÍÊÕÄãÕâ¸öÍ½µÜ¡£");
        command("recruit "+who->query("id"));
        tell_object(who,"¶ÅÉ±ËµµÀ£º¼Ç×¡£¬¶ñÈË¹ÈÈÏÖ¤²»ÈÏÈË£¬ÒªÊÇ¶ñÈËÖ¤ÒÅÊ§µÄ»°¾ÍÔÙÈ¥ÕÒÄãÊ¦ĞÖË¾ÂíÑÌÄÃ¡£\n");
        command("say ²»¹ı¼ÈÈ»Äã¼ÓÈëÁË¶ñÈË¹È£¬¾ÍÓÀÔ¶±ğÏëÍÑÀëÕâÀï£¬·ñÔò....");
        command("hehe "+who->query("id"));
    if (who->query("quests/badroar",1))
    {
       tell_object(who,"àÅ ,µ××Ó²»´íÂï !ºÃ ,Äã¿ÉÒÔ²»ÓÃ´Ó»ù²ã¸ÉÆğ!!!\n");
       who->set("title","[33m´ó[31m»µ[32mµ°[0m");
       return;
    }
}

int do_join()
{
        object who;
        who = this_player();

    if( who->query("class"))
    return notify_fail("Òª¼ÓÈë¹¤»á¾ÍÈ¥ÕÒÀÏ´óµãÍ·!\n");

   return 1;

/*
        if( who->query("class") )
                return notify_fail("ÄãÒÑ¾­¼ÓÈëÆäËû¹¤»áÁË¡£\n");
        who->set("class", "bandit");
        message("system", HIW"¶ÅÉ±ÑöÌì¿ñĞ¥£ºÔÛÃÇµÁÔôÓÖ¶àÁËÒ»¸ö¼«¶ñÖ®Í½£­"HIR+who->query("name")+HIW"\n´ó¼ÒÒªĞ¡ĞÄÀ²£¡¹ş¹ş¹ş¹ş£¡\n"NOR, users());

        return 1;
*/
}


void die()
{
/*
        object weapon;
        weapon = present("hook", this_object());
        destruct(weapon);
*/
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
          new("/open/sky/obj2/soil_stone")->move(environment(winner));
          message_vision(HIM"\n´Ó¶ÅÉ±µÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/soil_stone",sprintf("%s(%s) ÈÃ¶ÅÉ±µôÏÂÁËµØ×ğÊ¯ÓÚ %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }else{
        j=random(12000);
          if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
          {      
          new("/open/sky/obj2/soil_stone")->move(environment(winner));
          message_vision(HIM"\n´Ó¶ÅÉ±µÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/soil_stone",sprintf("%s(%s) ÈÃ¶ÅÉ±µôÏÂÁËµØ×ğÊ¯ÓÚ %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }
        tell_object(users(),"
"RED"¶ñÈË¹È"HIY"´«À´ËºÌìÁÑµØµÄÅ­ºğ£º\n
                   "HIY"¡¸"HIR"ÌìÄ§Ë«µ¶ÑªÁ¢½¦£¬»ìÉ±Ò»ºğ»ê·ÉÃğ£¡"HIY"¡±\n
                ¡¡°¦¡«¡«ÏëÎÒ¡¸"HIR"ÑªÊÖ"HIY"¡±"HIG"¶ÅÉ±"HIY"´³µ´½­ºşÈıÊ®ÓàÄê...\n
                         Ò»ÉúËùÉ±Ö®ÈËÒÑ²»¿É¼ÆÊı...\n
                  ¶ø½ñÈÕÈ´Ê§ÊÖÃüÔáÓÚ"HIW+winner->query("family/family_name")+HIY"Ğ¡Ôô£­"+HIC+winner->query("name")+HIY+"Ö®ÊÖ...\n
                     "RED"Ò»ÊÀ¶ñÃû"HIY"Èç½ñ»ÙÓÚÒ»µ©£¬ÕæÊÇ¿ÉºŞ°¡£¡\n"NOR);
        ::die();
}

int accept_object(object me,object ob)
{
  if(ob->query("id")=="sa`s hand")
   {
     if(me->query("quests/badroar"))
      {
       command("say ÎÒ²»ÊÇ´«Äã»ìÉ±ºğÁËÂğ ?»¹ÏëÒªĞ»Àñ°¡ !");
        destruct(ob);
       return 1;
      }
    if(me->query("class")!="bandit")
    {
        kill_ob(this_player());
        destruct(ob);
        command("say Äã²»ÔÛ¶ñÈË¹ÈµÄ ,ÔõÃ´ÄÜµ½É­ÁÖÈ¥ÕÒÎÒµÄ×óÊÖ!?");
    }
   if (me->query_temp("marks/allow")!=1)
    {
     destruct(ob);
     command("say à¸,Ğ»À²!²»¹ıÏÂ´Î±ğÔÙËæ±ãÂÒÅÜ½ûÇø!!!");
    }
  else {
  command("nod "+me->query("id"));
  me->set("quests/badroar",1);
  destruct(ob);
command("say ²»À¢\ÊÇÔÛÃÇ¶ñÈË¹ÈµÄÄ£·¶ !ÕâÑù°É ,ÎÒÒ²Ã»Ê²Ã´ºÃ¶«Î÷ÄÜ¸øÄã ,±ã´«Äã\nÎÒÃÇ¶ñÈËÔÚÍâĞĞ×ß½­ºşµÄ¿Ú¾÷--ÇîĞ×¶ñ¼« ,Éñ¿Ş¹íº¿....¾ÍÕâÑù ,\nÎÒÁ©ÒÔºó¿É»¥²»ÏàÇ·£¡");
  tell_object(me,"ÄãÉÔÎ¢ÁìÎòÁËÕâ°Ë×ÖµÄÒâÒå ,ĞÄÖĞÉ±ÆøÒ»¾Û ,»ìÉ±ºğ(badroar)µÄ¹¦Á¦Ôö¼ÓÁË!!\n");
  me->set("title","[33m´ó[31m»µ[32mµ°[0m");
        }
  return 1;
    }
}
string do_ask()
{
  int me;
  object who;
  who = this_player();
  if(who->query("quests/badroar")!=1)
  {
  if(who->query_temp("marks/hand_again")!=1)
  {
   who->set_temp("marks/hand",1);
   return "ÄãÕâ¸ö»ìµ° !ÇøÇøÒ»¸öĞ¡†ªà¶»¹¸Ò¹Ü±¾´óÒ¯ÏĞÊÂ !»¹²»¿ì¹ö ?\n";
  }
  else
  {
   who->set_temp("marks/allow",1);
    return "Ã»Ïëµ½ÄãµÄÒâÖ¾ÕâÃ´¼á¶¨ .ºÃ°É ,¾Í¸æËßÄã .ÎÒµÄ×óÊÖÊÇµ±³õÎÒÃÇ¶ñÈË¹ÈÖÚ¶à¶ñÈË½«ÑàÄÏÌìÒıÓÕµ½¶ñÈËÉ­ÁÖÊ± ,²»Ğ¡ĞÄ±»ÑàÄÏÌì¸ø¿³¶ÏµÄ .Ö»ÊÇÃ»Ïëµ½ËûÈ´±»ÄãÕâÃ´Ò»¸öĞ¡»ï×Ó¸øÉ±ÁË....¶ÔÁË !¼ÈÈ»ÄãÄÜ½«ÑàÄÏÌì¸øÉ±ÁË ,ÄÇÕÒ»ØÎÒÄÇÖ»¶ÏÊÖÓ¦¸ÃÒ²²»ÊÇÄÑÊÂ°É ?ÖÁÓÚÔÚÄÄÀïÂï....Äã¾ÍÈ¥ÎÊÎÊÄÇ¸öÖ»»á×öÒ©µÄÀÏÍ·×Ó°É .\n";
  }
  }
  else
  {
   return "Äã²»ÊÇÄÃ»ØÀ´ÁË..?»¹Ïë¸ÉÂï..?\n";
  }
}
string do_ask2()
{
  int me;
  object who;
  who = this_player();
  if(who->query("quests/badroar")!=1)
  {
    return "Ò»¸öĞ¡†ªà¶»¹Ïëµ½É­ÁÖÈ¥ ?ËÍËÀ°¡!?\n";
  }
  else
  {
    who->set_temp("marks/allow",1);
    return "ÏëÈ¥É­ÁÖ ?ºÃ ,Ã»ÎÊÌâ !È¥¸úĞùÔ¯Èı¹âÄÇ¶Ä¹íËµ°É !\n";
  }
}

