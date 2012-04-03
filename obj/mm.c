// /u/a/acelan/eqs/m_weapon.c ÍòÓÃÎäÆ÷ written by AceLan.............97.11.10
// Modify By AceLan 98.7.13 ÈÃÍòÓÃ¸üÓĞ¿´Í·...ccc....
// Modify By AceLan 98/11/1 Ôö¼Ó¹­µÄ²¿·Ö

#include <ansi.h>
#include <weapon.h>

// ¹­Ì«¸´ÔÓÁË so Ö±½Ó inherit
inherit "/std/weapon/m_bow.c";

void create()
{
   object me= this_player();
   string c_unit, wield_part, weapon_type= me->query("weapon/e_type"); // new

   set_name( me->query("weapon/name"),({"special "+me->query("weapon/e_type"), me->query("weapon/e_type"), "m_weapon"}) );
   set_weight(1000);
   if( clonep() )
      set_default_object(__FILE__);
   // ÏÂÎªĞÂÔö²¿·İ...
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

   set("long","Õâ"+c_unit+me->query("weapon/c_type")+"ÊÇÒÔ[1;37m"+ me->query("weapon/source1")+"[0mÅäºÏ[1;37m"+ me->query("weapon/source2")+"[0mËùÖı³ÉµÄ, ËüÕıÉÁË¸×ÅÒì¹â¡£");
   set("unit", "°Ñ");
   set("value",0);                           // ÎŞ¼ÛÖ®±¦...ccc....
   set("material","steal");

   // ¼ÓÇ¿ÁË×°±¸ÎäÆ÷¼°Ğ¶ÏÂÎäÆ÷µÄÑ¶Ï¢...
   // Ö¸ ÉÈ ±Ê Ö¸»· ±Û»·
   if( me->query("weapon/type") == "stabber" || me->query("weapon/type") == "unarmed")
   {
      set("wield_msg", HIW"Ö»¼û$N´óºÈÒ»Éù, Ò»µÀ°×¹âÑ¸ËÙÓÉ$N»³ÖĞ´Ü³ö, \nÔÚ¿ÕÖĞÅÌ»¸ÈıÈ¦ºóÍ£ÔÚ$NµÄ"+wield_part+"»¯³ÉÒ»"+c_unit+"¶ÀÌØµÄ"+ me->query("weapon/name")+"¡£\n"NOR);
      set("unwield_msg", HIW"Í»È»¼ä$NµÄĞØ¸¹Ö®¼äÎü×ãÁËÆø, ³¯"+wield_part+"µÄ$nÇáÇáÒ»´µ, \nÖ»¼û$nÂıÂıµÄ»¯×÷Ò»\ÂÆ\Çá\ÑÌ, ÒşÃ»ÔÚ$NµÄĞØ¸¹Ö®¼ä¡£\n"NOR);
   }
   else // if( c_unit == "°Ñ" || c_unit == "±ú")// Ö¸ ½£ µ¶ Ø°Ê× ·÷³¾...ÉÈ×Ó²»»á³öÏÖ
   {
      set("wield_msg", HIW"$NÇáÇáµÄ½«"+ me->query("weapon/name")+"ÓÉ±³ºó³é³ö, Ö»¼ûÒ»µÀÒ«ÑÛ¶ø¹îÒìµÄ¹âÃ¢×¢ÈëÁË$NÉíÉÏ¡£\n"NOR);
      set("unwield_msg", HIW"$N½«ÊÖÖĞµÄ$nËæÊÖÍùÌìÉÏÒ»¶ª, Ö»¼ûËüÇÉÃîµÄÂä»ØÁË±³ºó¡£\n"NOR);
   }

   set("no_drop", 1);
   set("no_give", 1);
   set("no_get", 1);
   set("no_auc", 1);

   init_bow( me->query("weapon/value"));
   set("skill_type", me->query("weapon/type"));
   setup();
}

int query_autoload()
{
   return 1;
}
¡õvoid init()
{
// ÎäÆ÷²»ÊÇ¹­µÄ»° ¾Í½« add_action disable µô
   if( this_player()->query("weapon/type") == "archery");
   {
      add_action("do_holdwith", "holdwith");
      add_action("do_unhold", "unhold");
      add_action("do_checkbow", "checkbow");
   }
}
¡õ