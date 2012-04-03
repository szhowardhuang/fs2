//open/prayer/room/punch1 

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "Ê¥»ğ½Ì×ÜÌ³");
	set( "build", 7 );
  set("valid_startroom",1);
  set ("long", @LONG

    ÕâÕıÊÇÎäÁÖÖĞ´«ËµµÄ¡¸Ê¥»ğ½Ì×ÜÌ³¡±£¬ÄãÑöÍ·Ò»¿´ÉÏ·½ÓĞÒ»¿é£¬ÓÃ½ğ
µ×ºì×ÖµÄÅÅØÒ£¬ÉÏÍ·Ğ´×Å[31m¡®Ê¥»ğ½Ì¡¯[37m£¬ÄãÍûÁËËÄÖÜ¿´µ½µÄÊÇÒ»¸ö¿í³©ÎŞ±È
¼°ÆÇÁ¦Ê®×ãµÄ¹¬µî£¬½öÓĞËÄÖ§ÇæÌì°ãµÄÅÌÁú´óÖùÖ§˜û×Å£¬ÇÒÔÚºìµØÌºµÄÁ½
¶ËÓĞÁ½¸öÉí²Ä¿ıÎäµÄ×ó£®ÓÒ»¤·¨£¬ÔÚºìµØÌºµÄ¾¡Í·£¬ÓĞ¸öÈË×øÔÚÍõ×ùÉÏ£¬
¸øÈËÒ»ÖÖ»ÊÕß°ãµÄÑ¹Á¦£¬¸øÈËÒ»ÖÖ²»º®¶øÀõµÄ¸Ğ¾õ¡£

LONG);
  set("objects", ([ /* sizeof() == 3 */
  "/open/prayer/npc/left1" : 1,        	//»¤·¨
  "/open/prayer/npc/right1" : 1,		//»¤·¨
  "/open/prayer/npc/pope" : 1,          //½ÌÖ÷
]));
  set("exits", ([ /* sizeof() == 4 */
    "up" : "/open/prayer/room/prayer_talk",
	"south" : "/open/prayer/room/punch1-2",		//´óÌı
	"east" : "/open/prayer/room/punch1-3",		//¸±°ïÖ÷
	"west" : "/open/prayer/room/punch1-4",		//¾üÊ¦
]));
   set("light_up", 1);

  setup();
}
 
int valid_leave(object me, string dir)
{
if (dir == "up" && me ->query("class") != "prayer")
     return notify_fail(HIY"ÁÖºêÉıËµµÀ:ÔÚÎÒÊ¥»ğ½ÌÄÚÂÒ´³,ÏëËÀÂğ..\n"NOR);
     return :: valid_leave(me, dir);
}
