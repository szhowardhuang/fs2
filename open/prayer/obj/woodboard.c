#include <command.h>
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
     set_name("[36mÊ¥»ğ½ÌµÄÁîÅÆ[0m",({"wood board","board"}) );
     set_weight(1000);
     if( clonep() ) 
     set_default_object(__FILE__);
     else 
     {
     set("long",@LONG

     Ê¥»ğ½ÌÍ½µÄĞÅÎïÖ®Ò», ´ËÄ¾ÅÆÊÇÒÔèíÄ¾µñ³É, ²¢ÔÚÆäÉÏ¿ÌÒÔÏóÕ÷
     Ê¥»ğ½ÌµÄÊ¥»ğÍ¼Ñù!!³ıÁË×öÎªÊ¥»ğ½ÌÃÅÍ½µÄ±æÈÏÖ®Íâ, ¸ü¿ÉÒÔ½«
     ËüÎÕÔÚÊÖÖĞ×öÎªÍ½ÊÖ¹¦»÷µÄÎäÆ÷¡£
 
LONG);
     set("unit", "Ö»");             
     set("value",60);
     set("no_sell",1);
     set("no_give",1);
     set("no_auc",1);
     set("no_drop",1);
     set("material","wood");
     }
     init_unarmed(15);
 
     setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  this_object()->set_name(""+(string)this_player()->name(1)+"µÄ"HIC"ÁîÅÆ"NOR,({"wood board","board"}));
}

                   