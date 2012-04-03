#include <weapon.h>
#include <ansi.h>
inherit UNARMED;
object user=this_player();
int be,bb,k,sp,qq;
void create()
{
        seteuid(getuid());
        set_name("[1;32m¡õ[1;34md[1;32m¡õ[1;34mh[1;32m¡õ[1;34m¡õ[1;32m¡õ[1;34mW[0m",({"sob"}));
        set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        set("unit", "¼ş");
        set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñ²É¼¯´óµØÖ®¾«»ª¶ÍÔì¶ø³ÉµÄÎäÆ÷¡£\n");
        set("value",20000);
        set("material", "steel");
        }
        init_unarmed(50);
        setup();
}
int query_autoload()
{
 return 1;
}
void init()
{
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
message_vision(HIY"$N½«[1;32m¡õ[1;34md[1;32m¡õ[1;34mh[1;32m¡õ[1;34m¡õ[1;32m¡õ[1;34mW[0m"HIY"ÔØÉÏ,ĞÄÖĞÓ¿³öÎŞÊıµÄ±¯ÉËÀëÀëÖ®Çé,\n"NOR,user);
        set_heart_beat(1);
     }
}
 int do_give(string str)
{
  if(str=="sob" || str=="all")
     if( query("equipped") )
     {
message_vision(HIY"$N½«[1;32m¡õ[1;34md[1;32m¡õ[1;34mh[1;32m¡õ[1;34m¡õ[1;32m¡õ[1;34mW[0m"HIY"È¡ÏÂ,ĞÄÖĞµÄ°§ÆàÖ®Çé,ËæÖ®É¢È¥¡£!!!\n"NOR,user);
        set_heart_beat(0);
     }
}
int do_unwield(string str)
{
   if(str=="sob" || str=="all")
     if( query("equipped") )
     {
message_vision(HIY"$N½«[1;32m¡õ[1;34md[1;32m¡õ[1;34mh[1;32m¡õ[1;34m¡õ[1;32m¡õ[1;34mW[0m"HIY"È¡ÏÂ,ĞÄÖĞµÄ°§ÆàÖ®Çé,ËæÖ®É¢È¥¡£!!!\n"NOR,user);
        set_heart_beat(0);
     }
}
void heart_beat()
{
  object *enemy;
  int i;
be = user->query("bellicosity",1);
  bb = (be/15);
  k = user->query("int",1);
  sp = user->query("spi",1);
  qq = (k+sp)^2 / 30;
  if ( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }
 if( user->is_fighting() && query("equipped") )
  {
    if( be > random(5000) )
    {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
     if( environment(user) == environment(enemy[i]) )
      if( random(300) > enemy[i]->query_skill("dodge") )
     {
message_vision(HIY"$N¸ĞÊÜµ½[1;32m¡õ[1;34md[1;32m¡õ[1;34mh[1;32m¡õ[1;34m¡õ[1;32m¡õ[1;34mW[0m"HIY"±¯ÉËÖ®ÆøÏ¢,ĞÄÖĞÊÜµ½¸Ğ¶¯,²»½û±¯´ÓÖĞÀ´,Õ½Òâ´ó¼õÉíĞÎÎªÖ®Ò»¶Ù¡£\n"NOR,enemy[i]);
      enemy[i]->start_busy(1);
     }else
message_vision("[1;32m¡õ[1;34md[1;32m¡õ[1;34mh[1;32m¡õ[1;34m¡õ[1;32m¡õ[1;34mW[0m"HIW"µÄ±¯ÉËÖ®ÆøÏ¢Ïò$NÏ®È¥,µ«$NµÄ¶¨Á¦³¬·²Ë¿ºÁ²»ÎªËù¶¯¡£\n"NOR,enemy[i]);
  }
  return;
}
}
