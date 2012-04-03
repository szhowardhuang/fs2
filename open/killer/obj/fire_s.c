#include <weapon.h>
#include <ansi.h>

inherit SWORD;
object user;
int be,bb,inn,sp,qq;
void create()
{
        seteuid(getuid());
        set_name(HIR"»ğÄ§½£"NOR,({"iceger"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
        set("long","´ËÄËÖÁÈÈÖ®Îï,ÄÜ¸øÓèµĞÈËÖÂÃüÉËº¦£®\n");

                set("value",10000);
                set("material", "steel");
                set("no_sell",1);
        }
        init_sword(255);
        setup();
}
void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{
     ::wield();
     if( query("equipped") )
     { 
        user = this_player();
        message_vision(HIR"$N½«»ğÄ§½£ÎÕÔÚÊÖÉÏ£¬È«ÉíÒÑ±»Ñ×ÆøÁıÕÖ¡£\n"NOR,user);
        set_heart_beat(1);
     }
}
int do_drop(string str)
{
   if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision("$NÄã¾ÓÈ»Å×Æú»ğÄ§Éñ-ÒÁ·ğÁ¦ÌØ£¿",user);
        set_heart_beat(0);
     }
}
 int do_give(string str)
{
  if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision("[1m[31m$NÔËÆğÌåÄÚĞÜĞÜÕæÆø,ÊÖÖĞ[37mÆÆ±ù[31mÒÔÏûÊ§ÎŞ×Ù¡£[0m\n",user);
        set_heart_beat(0);
     }
}
int do_unwield(string str)
{
   if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision(HIY"$N»­³öÒ»µÀ½£»¨£¬½£¹é½£ºĞ¡£"NOR,user);
        set_heart_beat(0);
     }
}
int do_auc(string str)
{
  if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision(HIY"$N»­³öÒ»µÀ½£»¨,ÊÖÖĞ»ğÄ§½£ÏûÊ§ÎŞ×Ù¡£"NOR,user);
        set_heart_beat(0);
     }
}

void heart_beat()
{
  object *enemy,who;
  int i;
//  be = user->query("bellicosity",1);
  be = 1000;
  bb = (be/20);
  inn= user->query("int",1);
  sp = user->query("spi",1);
qq=(inn +sp) *2 /30;
 if ( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }
 if( user->is_fighting() && query("equipped") )
  {
    if( be > random(300) )
    {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
     if( environment(user) == environment(enemy[i]) )
      if( random(5000) > enemy[i]->query_skill("dodge") )
     {
      message_vision(HBRED"»ğÄ§Éñ--*ÒÁ·ğÁ¦ÌØ*£¬»Ø¸´Ô­ĞÎ,Ö±½Ó³åÏò$N£¬Ë²¼äÏİÈëÒ»Æ¬»ğº£!!!"NOR,enemy[i]);
      enemy[i]->receive_damage("kee",qq+bb,user);
      COMBAT_D->report_status(enemy[i], 0);
     }else
      message_vision("[1m[33mÒ»µÀ»ğÑæÓÉ»ğÄ§½£¼¤·¢¶ø³ö,¿ÉÏ§±»$NÌåÄÚÕæÆøËù×èµ²..[0m\n",enemy[i]);
     }
  }
  return;
}
