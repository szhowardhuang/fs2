#include <ansi.h>
#include <armor.h>
inherit EQUIP;
object user;
int kar;
void create()
{
set_name("[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37mP[1;33m¡õ[1;37m¡õ[0m",({"purple neck","neck"}));
   set_weight(5000);
   if ( clonep() )
       set_default_object(__FILE__);
   else {
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñ²É¼¯ÏÈÌìÁéÆøËùÁ¶Ôì¶ø³ÉµÄÏÉÁ¶¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô,$NÉíÉÏµÄ$nËùÉ¢·¢µÄÁéÆøËæÖ®ÊÅÈ¥¡£\n");
   set("armor_prop/armor",7);
   set("armor_prop/dodge",3);
   set("unit", "Ìõ");
   set("armor_type", "neck");
   set("value", 30000);
   set("no_sell",1);
   set("no_auc",1);
   set("no_drop",1);
     }
   setup();
}
int query_autoload()
{
 return 1;
}
int init()
{
    add_action("do_wear","wear");
}
int do_wear(string str)
{
::wear();
 if( query("equipped") )
 {
   user = this_player();
message_vision("$N½«[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37mP[1;33m¡õ[1;37m¡õ[0m´©ÉÏ£¬[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31mP[1;33m¡õ[1;31m¡õ[0mµÄÏÉÆø¹á×¢ÔÚ$NÉíÖĞ¡£\n",user);
   kar=user->query("kar");
   set_heart_beat(1);
 }
}
void heart_beat()
{
  object *enemy,who;
  int i,dodge;
  if( !objectp(user) )
  { set_heart_beat(0);
     return;
  }
  if( user->is_fighting() && query("equipped") )
  {
    if( random(kar+70) > 70)  // ÔËÆø¸ß,»úÂÊ¸ß
    {
     user->receive_curing("kee",30);
     user->receive_heal("kee",30);
message_vision(HIY"[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37mP[1;33m¡õ[1;37m¡õ[0m"HIY"É¢³öµ­µ­µÄÏÉÆø,$NÔÚÏÉÆøãåÔ¡ÏÂ,$NËùÊÜµÄ´´ÉË»Ö¸´ÁË.\n"NOR,user);
      }
  }
  return;
}
