// Room: /open/capital/room/r55.c

inherit ROOM;

void create ()
{
  set ("short", "ÔÆÑó´ó½Ö");
  set ("long", @LONG
ÄãÀ´µ½ÁËÕòÔ¶ºî¸®ÃÅ¿Ú£¬Ò»ÉÈÓÉÌìÉ½Ñ©Ä¾ÖÆ³ÉµÄ´óÃÅ¼°Á½ÅÔèòèòÈç
ÉúÊ¯Ê¨£¬ÏÔÊ¾ÁËÕòÔ¶ºî²»·²µÄÆøÊÆÓë¸ÕÕıµÄĞÔ¸ñ¡£
    ±±±ßÃÅÉÏµÄØÒ¶îÓĞ»ÊµÛÇ×ÌâµÄËÄ¸ö×Ö£º¡¸fl;[4DÕòÔ¶ºî¸®fcm[4D¡±

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/capital/room/general",
  "west" : "/open/capital/room/r54",
  "east" : "/open/capital/room/r56",
]));

  set("outdoors", "/open/capital");

  setup();
}
