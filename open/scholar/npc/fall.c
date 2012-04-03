//written by AceLan..../u/a/acelan/npc/fall.c
//Rewrite By AceLan fall.c 98.7.16...¼ÓÇ¿ËûµÄÎä¹¦¶à±äĞÔ...
//Motify by AceLan 98/11/1 Ôö¼Ó¹­¼ıµÄÖÆÔì

#include "/open/open.h"
#include <ansi.h>

inherit F_VENDOR;

string make_weapon();
int init_weapon();
int about_weapon();
int in_combat();
int scholar_finger();
object reload_weapon( object);

void create()
{
   object ob;
   
   set_name("³şÊ¤Çï",({"zhu fall", "zhu", "fall"}));
   set("long", @LONG
ÃÔÑùÖ®ÎäÁÖ¸ßÊÖ, ÒÔ(ÖÆ×÷ÎäÆ÷)ÎÅÃû½­ºş¡£¾İËµËûÔøÒÔ(ÈåÃÅ)Ê§´«
ÒÑ¾ÃÖ®¾øÕĞÓëÈË¶Ô¾öÕ½, ´ó°ÜÆä¶ÔÊÖ¡£
LONG);
   set("nickname", "¹í¸«Éñ¹¤");
   set("race","ÈËÀà");
   set("gender","ÄĞĞÔ");
   set("combat_exp",500000);
   set("attitude","friendly");
   set("age",50);
   set("force_factor", 10);

   set("max_gin", 2000);
   set("eff_gin", 2000);
   set("gin", 2000);
   set("max_kee", 2000);
   set("eff_kee", 2000);
   set("kee", 2000);
   set("max_sen", 2000);
   set("eff_sen", 2000);
   set("sen", 2000);
   set("max_force", 2000);
   set("force", 2000);
   set("max_atman", 2000);
   set("atman", 2000);
   set("max_mana", 2000);
   set("mana", 2000);

   set("str", 30);
   set("cor", 30);
   set("per", 30);
   set("int", 30);
   set("cps", 30);
   set("con", 30);
   set("spi", 30);
   set("kar", 30);
   set("family/family_master", "Ğ¡µ°µ°");
   set("family/family_name", "ÈåÃÅ");

   set_skill("force", 100);
   set_skill("dodge", 100);
   set_skill("move", 100);
   set_skill("parry", 100);
   set_skill("magic", 100);
   set_skill("unarmed", 100);
   set_skill("stabber", 100);
   set_skill("sword", 100);
   set_skill("blade", 100);
   set_skill("dagger", 100);
   set_skill("plan", 100);

   //ÈåÃÅ
   set_skill("literate", 100);                  //ÉíÎªÈåÃÅ, ²»»á¶ÁÊéÔõĞĞ...
   set_skill("knowpen", 100);
   set_skill("poetforce", 100);
   set_skill("winter-steps", 100);
   set_skill("god-plan", 100);
   //ÏÉ½£
   set_skill("shasword", 100);
   set_skill("shaforce", 100);
   set_skill("sha-steps", 100);
   //¾©³Ç
   set_skill("dragon-dagger", 100);
   set_skill("oneforce", 100);
   set_skill("chen-steps", 100);
   //½ğµ¶
   set_skill("fast-blade", 100);
   set_skill("gold-blade", 100);
   set_skill("fly-steps", 100);
   set_skill("sixforce", 100);
   //¶Î¼Ò
   set_skill("six-fingers", 100);
   set_skill("sunforce", 100);
   set_skill("linpo-steps", 100);
   //¶ñÈË
   set_skill("badstrike", 100);
   set_skill("badforce", 100);
   set_skill("ghost-steps", 100);
   //Ñ©²Ô
   set_skill("snow-martial", 100);
   set_skill("snowforce", 100);
   set_skill("black-steps", 100);
   //Â¤É½
   set("functions/kang_kee/level", 50);

   set_skill("lungshan", 100);
   set_skill("haoforce", 100);
   set_skill("henma-steps", 100);
   //µÀ¼Ò
   set_skill("necromancy", 100);
   set_skill("gwhip", 100);
   set_skill("gforce", 100);
   set_skill("g-steps", 100);


   //ÒòÎªÊÇÈåÃÅµÄ ËùÒÔÏÈÉè³ÉÈåÃÅÎä¹¦...
   map_skill("force", "poetforce");
   map_skill("parry", "knowpen");
   map_skill("dodge", "winter-steps");
   map_skill("move", "winter-steps");
   map_skill("stabber", "knowpen");
   map_skill("plan", "god-plan");

   set("vendor_goods", ({
       GS_OBJ"woodsword",
       GS_OBJ"sword",
       GS_OBJ"woodblade",
       "/obj/example/dagger",
       "/open/gblade/obj/blade",
       "/open/ping/obj/fan-2",
       "/open/poison/obj/longwhip",
       "/open/gblade/obj/pen",
   }) );

   set("inquiry", ([
       "µÃÒâ¾øÕĞ"    :    @LONG
ÀÏÊ¦¸µµÄµÃÒâ¾øÕĞ¾ÍÊÇ¡¸ÈåÃÅ»ÃÖ¸¡±¨Ú, µ±Äê³ÉÁ¢(ÎåÈåÉú)Ö®Ê±
, ÀÏÊ¦¸µÔø½ÌÁËÎÒÒ»Á½ÊÖ¡£
LONG,
       "ÎåÈåÉú"      :    @LONG
µ±ÄêÀÏÊ¦¸µÒò×Ô¼ºÊÇÎäÁÖËÄ´ó¸ßÊÖÖ®Ò», Òò´ËÏë½å´ËÀ´×³´óÈåÃÅ
, ÌØ½«ÎÒÓëÆäËûËÄÎ»Ê¦ĞÖµÜ×é³ÉÁËÎåÈåÉú, ¸÷Á·¾ÍÒ»Éí²»Í¬µÄÎä¹¦¡£
LONG,
       "ÈåÃÅ"        :    @LONG
°¦...ÎªºÎ×ÜÒªÎÒ¾É»°ÖØÌáÄØ...Ïëµ±ÄêÀÏÊ¦¸µ´ıÎÒ²»±¡, Ã»Ïëµ½
ÀÏÊ¦¸µ¾¹»áÔâµ½²»²â, ÖÂÊ¹ËûµÄ(µÃÒâ¾øÕĞ)Òò´Ë¶øÊ§´«ÁË, ÎÒÎªÁË×·
²éÉ±ËÀÀÏÊ¦¸µµÄĞ×ÊÖ, ÒÑ¾­ÔÚ´ËÒşĞÕÂñÃûÁËºÃ¼¸ÄêÁË, ÎŞÄÎÈ´Á¬Ò»µã
Í·ĞòÒ²Ã»ÓĞ...
LONG,
       "ÖÆ×÷ÎäÆ÷"    :    (: make_weapon :),
       "²ÄÁÏ"        :    @LONG
ÉÏ¼ÑµÄ²ÄÁÏ, Ê×ÍÆ½­ºşÉÏ¼«ÎªÄÑµÃµÄ(ÓîÄÚÎåÇİ), ÖÆÔìÎäÆ÷µÄ²Ä
ÁÏÖ»ĞèÒªÎåÇİÉíÌåµÄÈÎºÎÒ»²¿·İ, ÔÙ¼ÓÉÏÒ»(ÌØÊâµÄ¿óÊ¯)¾Í¿ÉÒÔÁË¡£
LONG,
       "ÌØÊâµÄ¿óÊ¯"  :    "ËùÎ½ÌØÊâµÄ¿óÊ¯¾ÍÊÇÖ¸(ÓîÄÚÎåÕä)Âï¡£",
       "ÊıÄ¿"        :    @LONG
Ã÷ÈË²»Ëµ°µ»°, ÎÒÒ²ÀÏÁË, ´òËãÏ´ÊÖ²»¸ÉÁË, ÈôÊÇÄãÄÜ¸¶ÎÒ»Æ½ğ
°ÙÁ½ÒÔÉÏ, ÎÒ¾ÍÌæÄã´òÔìÒ»°Ñ·æÀûÎŞÅú, ¶ÀÒ»ÎŞ¶şµÄÎäÆ÷¡£
LONG,
       "ÓîÄÚÎåÇİ"    :    @LONG
¡®ÓîÄÚÎåÇİ¡¯ËùÖ¸µÄ¾ÍÊÇÎåÖÖÕäÇİÒìÊŞ, °üÀ¨×¡ÔÚÄ§½çÖĞµÄËÄÉñ
ÊŞÁú¡¢·ï¡¢¹ê¡¢÷è÷ëµÈËÄÖÖ, ÁíÍâ»¹¼ÓÉÏÒ»Ö»ĞĞ¶¯Èç·ç¡¢¾ÓÎŞ¶¨Ëù¼«
ÎªÄÑµÃÒ»¼ûµÄÌìÉ½ÉñÓ¥¡£
LONG,
       "ÓîÄÚÎåÕä"    :    @LONG
¡®ÓîÄÚÎåÕä¡¯Ö¸µÄ¾ÍÊÇ¶«º£±ù¾§, Æß²ÊÓñÊ¯, °ÙÁ¶µ¤½ğ, ÍòÄêº®
±ù, ¼°Ä§ôä´äµÈÎåÑù¡£
LONG,
   ]));

   set("chat_chance",20);
   set("chat_msg",({
      (: about_weapon :)
   }));
   set("chat_chance_combat",20);
   set("chat_msg_combat",({
      (: in_combat :)
   }));
   setup();

}

void init()
{
   add_action("do_select", "select");
   add_action("do_set_name", "set_name");
   add_action("do_vendor_list", "list");
}

int in_combat()
{
   object weapon, fall= this_object();
// ¸úÈË¼Ò´ò¼ÜÃ»ÄÃÎäÆ÷ÔõĞĞ...
   if( !present("m_weapon", this_object()))
   {
      init_weapon();
      weapon= new("/obj/m_weapon.c");            //²»¼Ó wield...

// ÕæÊÇÂé·³...ÎäÆ÷×¥²»µ½ NPC µÄÉè¶¨....
      reload_weapon( weapon);

      weapon->move( fall);
      command("wield m_weapon");                          //Õâ±ßÔÙ wield...
   }

   //ÏÉ½£
   (: perform_action,"sword.sha_kee" :);
   //½ğµ¶...
   (: perform_action,"blade.gold-dest" :);
   (: perform_action,"blade.fast-dest" :);
   //¶ñÈË...
   (: perform_action,"unarmed.evil-blade" :);
   //¶Î¼Ò...
   (: perform_action,"stabber.handwriting" :);
   //ÈåÃÅ...
   (: perform_action,"stabber.movedown" :);
   (: perform_action,"plan.lock-link" :);
   (: perform_action,"plan.ghost" :);
   (: perform_action,"plan.fire" :);
   (: perform_action,"plan.fish" :);
   scholar_finger();                                    //À´ÕĞÈåÃÅ»ÃÖ¸°É..

   return 1;
}

int about_weapon()
{
   object weapon, fall= this_object();
   int chance= random( 10);

//Èç¹ûÉíÉÏÓĞ m_weapon Ôò½«ËûÉ¾µô....±íÊ¾¸Õ¸ÕÓĞÈË¸úËû´ò¹ı...
   if( weapon= present("m_weapon", this_object()))
      destruct( weapon);

   if( chance == 7)
      command("say ¹ş¹ş¹ş...Õâ°ÑĞÂ±øÆ÷´òÔìµÄÕæÊÇºÃ¨Ú...");
   if( chance == 8)
      message_vision("·ç³µ:ºôºôºô...ÌúÕè:¨ÎÒ»¨ä...¨ÎÒ»¨ä...¨ÎÒ»¨ä...\n", this_object());
   if( chance == 9)
      message_vision("Ñ×ÈÈµÄÌú¹¤·¿È¼ÉÕ×ÅÆæÌØ»ğÑæµÄ´ó»ğ...\n", this_object());

   return 1;
}

int init_weapon()
{
   object fall= this_object();

   switch( random( 10))
   {
      case 0:                                           //ÏÉ½£
         fall->map_skill("sword", "shasword");
         fall->map_skill("parry", "shasword");
         fall->map_skill("dodge", "sha-steps");
         fall->map_skill("move", "sha-steps");
         fall->map_skill("force", "shaforce");

         fall->set("weapon/type", "sword");
         fall->set("weapon/e_type", "sword");
         fall->set("weapon/c_type", "½£");
         fall->set("weapon/name", "¶À¹Â¾Å½£");
         break;
      case 1:                                           //¾©³Ç
         fall->map_skill("dagger", "dragon-dagger");
         fall->map_skill("parry", "dragon-dagger");
         fall->map_skill("dodge", "chen-steps");
         fall->map_skill("move", "chen-steps");
         fall->map_skill("force", "oneforce");

         fall->set("weapon/type", "dagger");
         fall->set("weapon/e_type", "dagger");
         fall->set("weapon/c_type", "Ø°Ê×");
         fall->set("weapon/name", "½¦ÑªØ°");
         break;
      case 2:                                           //½ğµ¶
         fall->map_skill("blade", "fast-blade");
         fall->map_skill("parry", "gold-blade");
         fall->map_skill("dodge", "fly-steps");
         fall->map_skill("move", "fly-steps");
         fall->map_skill("force", "sixforce");

         fall->set("weapon/type", "blade");
         fall->set("weapon/e_type", "blade");
         fall->set("weapon/c_type", "µ¶");
         fall->set("weapon/name", "¿ªÉ½µ¶");
         break;
      case 3:                                           //¶Î¼Ò
         fall->map_skill("unarmed", "six-fingers");
         fall->map_skill("stabber", "six-fingers");
         fall->map_skill("parry", "six-fingers");
         fall->map_skill("dodge", "linpo-steps");
         fall->map_skill("move", "linpo-steps");
         fall->map_skill("force", "sunforce");

         fall->set("weapon/type", "stabber");
         fall->set("weapon/e_type", "fan");
         fall->set("weapon/c_type", "ÉÈ");
         fall->set("weapon/name", "µç·çÉÈ");
         break;
      case 4:                                           //¶ñÈË
         fall->map_skill("unarmed", "badstrike");
         fall->map_skill("parry", "badstrike");
         fall->map_skill("dodge", "ghost-steps");
         fall->map_skill("move", "ghost-steps");
         fall->map_skill("force", "badforce");

         fall->set("weapon/type", "unarmed");
         fall->set("weapon/e_type", "ring");
         fall->set("weapon/c_type", "Ö¸»·");
         fall->set("weapon/name", "½á»é×ê½ä");
         break;
      case 5:                                           //Ñ©²Ô
         fall->map_skill("unarmed", "snow-martial");
         fall->map_skill("dodge", "black-steps");
         fall->map_skill("move", "black-steps");
         fall->map_skill("force", "snowforce");

         fall->set("weapon/type", "unarmed");
         fall->set("weapon/e_type", "armband");
         fall->set("weapon/c_type", "±Û»·");
         fall->set("weapon/name", "ÖĞÑëÔ²»·");
         break;
      case 6:                                           //Â¤É½
         fall->map_skill("unarmed", "lungshan");
         fall->map_skill("dodge", "henma-steps");
         fall->map_skill("move", "henma-steps");
         fall->map_skill("force", "haoforce");

         fall->set("weapon/type", "unarmed");
         fall->set("weapon/e_type", "armband");
         fall->set("weapon/c_type", "±Û»·");
         fall->set("weapon/name", "ÏÄÍşÒÄ»¨È¦");
         break;
      case 7:                                           //ÈåÃÅ
      case 8:
      case 9:
         fall->set("weapon/type", "stabber");
         fall->set("weapon/e_type", "pen");
         fall->set("weapon/c_type", "±Ê");
         fall->set("weapon/name", "Ğ¡µ°µ°×¨ÓÃ±Ê");

         break;
   }
   fall->set("weapon/source1", "µ°¿Ç");                 //ccc...
   fall->set("weapon/source2", "µ°»Æ");                 //hoho...
   fall->set("weapon/value", 100);

   return 1;
}

int scholar_finger()
{
   object me= this_object();
   object corpse, target, *enemy= me->query_enemy();
   string weakest;
   int i, enemy_num= sizeof( enemy);
   int gin, kee, sen;

   int literate, force_lv;
   for( i= 0; i< enemy_num; i++)
   {
      target= enemy[ i];
      gin= target->query("gin");
      kee= target->query("kee");
      sen= target->query("sen");

      literate= target->query_skill("literate");
      force_lv= target->query_skill("force");

      if( gin < kee && gin < sen)
         weakest= "gin";
      if( kee < gin && kee < sen)
         weakest= "kee";
      if( sen < gin && sen < kee)
         weakest= "sen";

      message_vision(@LONG
[1;37m$NË«ÊÖÒ»ºÏ, ¿ÚÖĞÄîÄîÓĞ´Ê, Í»È»Ä¿¹â¾«¹âËÄÉä, ´Ó$nÉíÉÏµçÉ¨¶ø¹ı
                Ê©Õ¹³öÈåÃÅÊ§´«ÒÑ¾Ã¶À²½ÎäÁÖÖ®

[5;32m£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½
£½£½£½£½£½£½£½£½£½£½£½£½£½[1;37m¡®[1;31mÈåÃÅ»ÃÖ¸[1;37m¡¯[5;32m£½£½£½£½£½£½£½£½£½£½£½£½£½£½
£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½£½[0m
LONG, me, target);

      if( random( literate+ force_lv) < 150)
      {
         message_vision(@LONG
[1;34m¾ÍÔÚÇ§¾ûÒ»·¢µÄ×îºóÒ»¿Ì, $N×ß²îÁËÆø, ÖÂÊ¹ÈåÃÅ»ÃÖ¸´òÆ«ÁË,
´òÖĞÂ·ÅÔ¿´Ï·µÄÂ·ÈË¼× + Â·ÈËÒÒ & Â·ÈË±û....
LONG, me, target);

         corpse= new("/obj/corpse");
         corpse->move( environment( target));
      }
      else
      {
         message_vision("
[1;31mÖ»¼û$NÈ«ÉíËÆºõÊÇ×ÅÁË»ğËÆµÄ, ÖÜÉíÈ¼ÆğÁËÕóÕóµÄ¸ÕÆø,
\n
ÊÖÖĞµÄ"+ me->query("weapon/name")+ "µç¹âËÄÉä, ÕĞÕĞ¶¼ÉäÖĞÁË$nµÄÖÜÉí´óÑ¨...[0m
\n
", me, target);
         message_vision("\n[1;37m¿´À´$nÒÑ¾­ÊÜµ½ÑÏÖØµÄ´´ÉË, ÒÑ¾­¿ìÒª²»ĞĞÁË¡£\n[0m", me, target);
      }

      target->add( weakest, -me->query_skill("stabber")/ 2);
   }
   return 1;
}

object reload_weapon( object weapon)
{
   object fall= this_object();
   string c_unit, wield_part, weapon_type= fall->query("weapon/e_type");

   if( weapon_type == "whip")
   {
      c_unit= "±ú";
      wield_part= "ÊÖÖĞ";
   }
   else if( weapon_type == "pen")
   {
      c_unit= "Ö»";
      wield_part= "ÊÖÖĞ";
   }
   else if( weapon_type == "ring")
   {
      c_unit= "Ö»";
      wield_part= "Ö¸ÉÏ";
   }
   else if( weapon_type == "armband")
   {
      c_unit= "¸ö";
      wield_part= "±ÛÉÏ";
   }
   else                                      // Ê£ÏÂµÄÎª ½£ µ¶ Ø°Ê× ·÷³¾ ÉÈ
   {
      c_unit= "°Ñ";
      wield_part= "ÊÖÖĞ";
   }

   weapon->set_name( fall->query("weapon/name"),({"special "+ fall->query("weapon/e_type"), fall->query("weapon/e_type"), "m_weapon"}) );
   weapon->init_sword( fall->query("weapon/value"));
   weapon->set("skill_type", fall->query("weapon/type"));
   if( fall->query("weapon/type") == "stabber" || fall->query("weapon/type") == "unarmed")
   {
      weapon->set("wield_msg", HIW"Ö»¼û$N´óºÈÒ»Éù, Ò»µÀ°×¹âÑ¸ËÙÓÉ$N»³ÖĞ´Ü³ö, \nÔÚ¿ÕÖĞÅÌ»¸ÈıÈ¦ºóÍ£ÔÚ$NµÄ"+wield_part+"»¯³ÉÒ»"+c_unit+"¶ÀÌØµÄ"+ fall->query("weapon/name")+"¡£\n"NOR);
weapon->set("unwield_msg", HIW"Í»È»¼ä$NµÄĞØ¸¹Ö®¼äÎü×ãÁËÆø, ³¯"+wield_part+"µÄ$nÇáÇáÒ»´µ, Ö»¼û$nÂıÂıµÄ»¯×÷Ò»µÀ¹âÃ¢ÒşÃ»ÔÚ$NµÄĞØ¸¹Ö®¼ä¡£\n"NOR);
   }
   else // if( c_unit == "°Ñ" || c_unit == "±ú")// Ö¸ ½£ µ¶ Ø°Ê× ·÷³¾...ÉÈ×Ó²»»á³öÏÖ
   {
      weapon->set("wield_msg", HIW"$NÇáÇáµÄ½«"+ fall->query("weapon/name")+"ÓÉ±³ºó³é³ö, Ö»¼ûÒ»µÀÒ«ÑÛ¶ø¹îÒìµÄ¹âÃ¢×¢ÈëÁË$NÉíÉÏ¡£\n"NOR);
      weapon->set("unwield_msg", HIW"$N½«ÊÖÖĞµÄ$nËæÊÖÍùÌìÉÏÒ»¶ª, Ö»¼ûËüÇÉÃîµÄÂä»ØÁË±³ºó¡£\n"NOR);
   }
   return weapon;
}

int accept_fight( object ob)
{
   object weapon, fall= this_object();
   command("say ¹ş¹ş¹ş...Ì«ºÃÁË, ÀÏ·òÕı³îÃ»ÈËÄÜÀ´ÊÔÊÔÎÒĞÂ´òÔìµÄ±øÆ÷ÄØ...");
   command("say ÄÇÀÏ·ò¾ÍÓÃËüÀ´ÓëÄã¹ı¹ıÕĞ°É...Ğ¡ĞÄÁË...");

   init_weapon();

   weapon= new("/u/a/acelan/weapon/m_weapon.c");       //²»¼Ó wield...

// ÕæÊÇÂé·³...ÎäÆ÷×¥²»µ½ NPC µÄÉè¶¨....
   weapon= reload_weapon( weapon);

   weapon->move( fall);
   command("wield m_weapon");                     //Õâ±ßÔÙ wield...
   return 1;
}

int accept_kill(object ob)
{
   object fall= this_object();
   object weapon;
   command("say ÏëÉ±ÎÒ...Ö»ÅÂÄã»¹Ã»Õâ¸ö·İÁ¿...");

   init_weapon();

   fall->set("weapon/value", 200);                      //ÍµÍµµ÷¸ßÒ»µã...
   fall->set("force_factor", 50);

   weapon= new("/u/a/acelan/weapon/m_weapon.c");       //²»¼Ó wield...

// ÕæÊÇÂé·³...ÎäÆ÷×¥²»µ½ NPC µÄÉè¶¨....
   reload_weapon( weapon);

   weapon->move( fall);
   command("wield m_weapon");                     //Õâ±ßÔÙ wield...
   return 1;
}

string make_weapon()
{
   object me= this_player();
   if( present( "m_weapon", me) )
      return("ÀÏ·òÖ»°ïÈË×öÒ»´ÎÎäÆ÷, ÀÏ·òÒÑ¾­°ïÄã×÷¹ıÁË, ÄãÇë»Ø°É¡£");
   me->set_temp("accept_obj", 1);
   return (@LONG
ÀÏ·ò²»°ï±ğÈË×öÎäÆ÷ÒÑ¾­ºÜ¾ÃÁË, ³ı·ÇÄãÄÜÄÃ³ö°ÙÄêÄÑµÃÒ»¼û
µÄ(²ÄÁÏ), ¼°Ò»±ÊÎªÊı¿É¹ÛµÄ(ÊıÄ¿), ·ñÔòÃâÌ¸¡£
LONG);
}

int do_set_name( string arg)
{
   object weapon;
   object me= this_player();
// ÅĞ¶ÏÊÇ·ñÔÊĞíÃüÃû...
   if( me->query_temp("allow_name") != 1)
   {
      command("? "+ me->query("id"));
      command("say ÄãÒª¸ÉÂï¨Ú.....");
      return 1;
   }
// ÊÇ·ñÓĞ¼Ó²ÎÊı...
   if( !arg)
   {
      command("say ÎªÄãµÄ"+ me->query_temp("weapon_type")+"ÃüÃûÓĞÕâÃ´À§ÄÑÂğ? ¿ì×ö¾ö¶¨°É¡£");
      return 1;
   }
// ½«Ò»Ğ©Éè¶¨Ğ´Èë data
   arg = trans_color(arg);
   me->set("weapon/name", arg+NOR);
   me->set("weapon/source1", me->query_temp("weapon_source1"));
   me->set("weapon/source2", me->query_temp("weapon_source2"));
   me->set("weapon/c_type", me->query_temp("weapon_type"));


   switch( me->query_temp("weapon_type"))
   {
      case "½£":
      {
         me->set("weapon/type", "sword");
         me->set("weapon/e_type", "sword");
         me->set("weapon/c_type", "½£");
         break;
      }
      case "µ¶":
      {
         me->set("weapon/type", "blade");
         me->set("weapon/e_type", "blade");
         me->set("weapon/c_type", "µ¶");
         break;
      }
      case "ÉÈ":
      {
         me->set("weapon/type", "stabber");
         me->set("weapon/e_type", "fan");
         me->set("weapon/c_type", "ÉÈ");
         break;
      }
      case "±Ê":
      {
         me->set("weapon/type", "stabber");
         me->set("weapon/e_type", "pen");
         me->set("weapon/c_type", "±Ê");
         break;
      }
      case "Ö¸»·":
      {
         me->set("weapon/type", "unarmed");
         me->set("weapon/e_type", "ring");
         me->set("weapon/c_type", "Ö¸»·");
         break;
      }
      case "±Ş":
      {  
         me->set("weapon/type", "whip");
         me->set("weapon/e_type", "whip");
         me->set("weapon/c_type", "±Ş");
         break;
      }
      case "·÷³¾":
      {  
         me->set("weapon/type", "whip");
         me->set("weapon/e_type", "whip");
         me->set("weapon/c_type", "·÷³¾");
         break;
      }
      case "Ø°Ê×":
      {
         me->set("weapon/type", "dagger");
         me->set("weapon/e_type", "dagger");
         me->set("weapon/c_type", "Ø°Ê×");
         break;
      }
      case "¹­":
      {
         me->set("weapon/type", "archery");
         me->set("weapon/e_type", "bow");
         me->set("weapon/c_type", "¹­");
         break;
      }
   }

   new("/obj/m_weapon.c")->move( me);
   command("say ºÃÁË, Õâ°Ñ"+ me->query_temp("weapon_type")+ "ÒÑ¾­ÖÆ×÷Íê³ÉÁË, ÇëÊÕÏÂ°É¡£");
   message_vision("³şÊ¤Çï¸øÁËÄãÒ»°Ñ"+ arg+ "\n", me);
// ½«ËùÓĞ temp É¾³ı...
   me->delete_temp("give_money");
   me->delete_temp("allow_name");
   me->delete_temp("weapon_source1");
   me->delete_temp("weapon_source2");
   me->delete_temp("weapon_type");
   me->delete_temp("allow_select");
   me->delete_temp("accept_obj");
   return 1;
}

int do_select( string arg)
{
   object me= this_player();
// ¼ì²éÊÇ·ñÔÊĞíÑ¡Ôñ ÎäÆ÷ĞÍÌ¬
   if( !me->query_temp("allow_select") )
   {
      command("? "+ this_player()->query("id"));
      command("say Ñ¡Ê²Ã´...Ë­ËµÒªÈÃÄãÑ¡ÁË...");
      return 1;
   }
// Ã»¼Ó²ÎÊı...
   if( !arg)
   {
      command("say ÀÏ·ò»áÖÆÔìµÄÎäÆ÷ÓĞ µ¶ ÉÈ ±Ê ½£ ¹­ Ö¸»· ±Ş ·÷³¾ ¼° Ø°Ê×");
      command("say ¿ìÑ¡Ôñ(select)°É...");
      return 1;
   }
// ÊÇ·ñÔÚÉè¶¨ĞÍÌ¬ÖĞ
   if( arg != "½£" && arg != "ÉÈ" && arg != "±Ê" && arg != "µ¶" && arg != "Ö¸»·" && arg != "±Ş" && arg != "·÷³¾" && arg != "Ø°Ê×" && arg != "¹­")
   {
      command("say ºÜ±§Ç¸, ÀÏ·òÄÜÁ¦ÓĞÏŞ, ²»»áÖÆ×÷ÕâÖÖÎäÆ÷...");
      command("say ÇëÖØĞÂÑ¡Ôñ...");
      return 1;
   }

// ................
   me->set_temp("weapon_type", arg);
   command("say Òª×ö"+ arg+"ÊÇ°É! ºÃ, Ã»ÎÊÌâ...");

   message_vision("Ö»Ìı¼û³şÊ¤ÇïÔÚºóÔºÁ¶ÌúÂ¯ÅÔÇÃÇÃ´ò´òµÄÉùÒô, \n²»¾Ã¾Í¼ûËûÄÃ³öÁËÒ»°ÑÉãÈËÆøÆÇµÄ"+ arg+ "³öÀ´¡£\n", me);
   command("say ¹ş¹ş...ÕæÊÇÒ»°ÑºÃ"+ arg+".....¡£");
   command("say ÇëÎªÕâ°Ñ"+ arg+ "ÃüÃû(set_name)°É¡£");
   me->set_temp("allow_name", 1);

   return 1;
}

int accept_object(object me, object obj)
{
   string obj_name= obj->query("name");
   string weapon_type= me->query_temp("weapon_type");
// ÏÈÅĞ¶ÏÊÇ·ñÒÑ¾­ÎÊ¹ıÒª ÖÆ×÷ÎäÆ÷ ÁË
   if( me->query_temp("accept_obj"))
   {
// ÅĞ¶ÏÊÇ·ñÓîÄÚÎåÇİ
      if( obj_name == "Õæ¹êÑª¾§" || obj_name == HIY"Ä§ÁúÁÛ"NOR)
      {
         command("pat "+getuid(me));
         command("say Ì«ºÃÁË, ÕâÊÇÉÏ¼ÑµÄ"+ obj_name+ "¡£");
// ÊÇµÄ»°Éè¶¨ temp weapon_source1, destruct( obj)...
         me->set_temp("weapon_source1", obj_name);
         destruct(obj);
// ÅĞ¶ÏÊÇ·ñÓĞ¸ø¹ıÎåÕä, ÈôÎŞÔò return...
         if( !me->query_temp("weapon_source2"))
         {
            command("say ¿ì½«¡®ÓîÄÚÎåÕä¡¯ÄÃ¸øÎÒ, ºÃÈÃÎÒ°ïÄã´òÔìÎäÆ÷...");
            return 1;
         }
// ÒÑ¸ø¹ı ÎåÕä ÎåÇİ ÅĞ¶ÏÊÇ·ñÓĞ¸øÇ®...
         if( !me->query_temp("give_money"))
         {
            command("say ²»¹ı.........ÇëÏÈ¸¶¿î........");
            return 1;
         }
// ÒÑ¸ø¹ı ÎåÕä ÎåÇİ & Ç®......ÒªÇóÑ¡ÔñÎäÆ÷ĞÍÌ¬ set_temp("allow_select", 1)
         command("say ÇëÑ¡Ôñ(select)ÄãÒªµÄÎäÆ÷ĞÍÌ¬¡£");
         me->set_temp("allow_select", 1);
         return 1;
      }

// ÅĞ¶ÏÊÇ·ñÓîÄÚÎåÕä
      if( obj_name == "¶«º£±ù¾§" || obj_name == "°ÙÁ¶µ¤½ğ")
      {
         command("pat "+getuid(me));
         command("say Ì«ºÃÁË, ÕâÊÇÉÏ¼ÑµÄ"+ obj_name+ "¡£");
// ÊÇµÄ»°Éè¶¨ temp weapon_source2, desturct( obj)...
         me->set_temp("weapon_source2", obj_name);
         destruct(obj);
// ÅĞ¶ÏÊÇ·ñÓĞ¸ø¹ıÎåÇİ, ÈôÎŞÔò return...
         if( !me->query_temp("weapon_source1"))
         {
            command("say ¿ì½«¡®ÓîÄÚÎåÕä¡¯ÄÃ¸øÎÒ, ºÃÈÃÎÒ°ïÄã´òÔìÎäÆ÷...");
            return 1;
         }
// ÒÑ¸ø¹ı ÎåÕä ÎåÇİ ÅĞ¶ÏÊÇ·ñÓĞ¸øÇ®...
         if( !me->query_temp("give_money"))
         {
            command("say ²»¹ı.........ÇëÏÈ¸¶¿î........");
            return 1;
         }
// ÒÑ¸ø¹ı ÎåÕä ÎåÇİ & Ç®......ÒªÇóÑ¡ÔñÎäÆ÷ĞÍÌ¬ set_temp("allow_select", 1)
         command("say ÇëÑ¡Ôñ(select)ÄãÒªµÄÎäÆ÷ĞÍÌ¬¡£");
         me->set_temp("allow_select", 1);
         return 1;
      }

// ÅĞ¶ÏÊÇ·ñ¸øÇ®...
      if( obj_name == "»Æ½ğ")
      {
// ÅĞ¶ÏÊÇ·ñ³¬¹ı°Ù½ğ
         if( obj->value() < 1000000)
         {
            command("? "+ getuid(me));
            command("say ÊıÄ¿ºÃÏñÓĞµã²»¶ÔÅ¶..., Çë´ÕÆë°Ù½ğÖ®ºóÔÙÀ´...");
            command("say »Æ½ğÊıÄ¿Ö»ÓĞ"+ obj->value()/10000);
            obj->move( me);
            message_vision("³şÊ¤Çï½«"+ obj->query("name")+ "»¹¸øÁË$N¡£\n", me);
            return 0;
         }
// ³¬¹ı°Ù½ğ...set_temp("give_money", 1), set("weapon/value", gold/5)
         message_vision("Ö»¼û³şÊ¤Çï½«»Æ½ğÄÃÆğÀ´Ò§ÁËÒ»Ò§¡£\n", me);
         command("say ºÃ, Õâ¹ûÈ»ÊÇÕæµÄ»Æ½ğ...");
         me->set_temp("give_money", 1);
// ´óÓÚ 500 gold
         if( obj->value()/ 10000 > 500)
            me->set("weapon/value", 100);
         else
            me->set("weapon/value", obj->value()/50000);

         destruct(obj);

// ¼ì²éÊÇ·ñÓĞ¸ø¹ı ÎåÇİ
         if( !me->query_temp("weapon_source1"))
         {
            command("say ¿ì½«¡®ÓîÄÚÎåÇİ¡¯ÄÃÀ´°É, ºÃÈÃÀÏ·ò¸Ï¿ì¶¯¹¤¡£");
            return 1;
         }
// ¼ì²éÊÇ·ñÓĞ¸ø¹ı ÎåÕä
         if( !me->query_temp("weapon_source2"))
         {
            command("say ¿ì½«¡®ÓîÄÚÎåÕä¡¯ÄÃÀ´°É, ºÃÈÃÀÏ·ò¸Ï¿ì¶¯¹¤¡£");
            return 1;
         }
// ÒÑ¸ø¹ı ÎåÕä ÎåÇİ & Ç®......ÒªÇóÑ¡ÔñÎäÆ÷ĞÍÌ¬ set_temp("allow_select", 1)
         command("say ÇëÑ¡Ôñ(select)ÄãÒªµÄÎäÆ÷ĞÍÌ¬¡£");
         me->set_temp("allow_select", 1);
         return 1;
      }
   }
// ÉĞÎ´ÎÊ¹ı ÖÆ×÷ÎäÆ÷
   else
   {
      command("? "+getuid(me));
      command("say ¸øÎÒÕâÖÖ¶«Î÷¸ÉÂé...");
      obj->move( me);
      message_vision("³şÊ¤Çï½«"+ obj->query("name")+ "»¹¸øÁË$N¡£\n", me);
      return 1;
   }
}
