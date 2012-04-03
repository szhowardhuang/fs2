//Ôö¼Óppl expÕì²â£¬·¿Ö¹pplÀûÓÃfollowÁï½øÀ´
//modify by cyw at 91/04/02
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[0;1;31m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mt[0m");
  set ("long", @LONG
ÕâÀïÊÇ½á½çµÄ±ßÔµ, ÕâÀïµÄÄ§·¨Á¦¾ÍÃ»ÄÇÃ´µÄÇ¿ÁÒÁË, ÌìºòÎÂ¶È¸úÆ½
³£Ò»Ñù, µ«»¹Î´Àë¿ª»Ã½çµÄ¿ØÖÆ·¶Î§, ÕâÀïÓĞÒ»¸ùÖ±´ïÔÆ¼Ê, Ê®·ÖÆæ¹ÖµÄ
¾ŞÊ¯, Õâ¸öÒ²ÊÇÄÃÀ´¹®¹Ì½á½çÓÃµÄ°É! 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/fire-hole/f-3.c",
  "southwest" : __DIR__"f-2.c",
]));
  set("outdoors", 1);

  setup();
}
void init()
{
      call_out("do_check",1,this_player()); 
}
void do_check(object me)
{
      if(me->query("combat_exp" ) < 5000000 && userp(me) && living(me)) {
        message_vision(HIR"$NµÖ¿¹²»ÁË»ğÁú»Ã½çµÄÈÈ¶È£¬±»ÌìÉñ´«ËÍ»ØÆğµã£¡\n"NOR,me);
        me->move(me->query("startroom"));
        me->set( "clan/out","/open/center/room/inn");
      }else  
      me->set_temp("check_ok",1);
}
int valid_leave(object who, string dir)
{
	if (dir == "southwest" || dir == "southeast")
	{
		if(!who->query_temp("check_ok",1))
		  return notify_fail(HIY"¸Ï×ÅÈ¥ËÀÒ²²»ÓÃ³åÕâÃ´¿ì°É!!\n"NOR);     
	        who->delete_temp("check_ok",1);
        }
        return :: valid_leave(who,dir);
}
