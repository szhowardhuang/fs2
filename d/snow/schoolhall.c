// Room: /d/snow/schoolhall.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ´¾·çÎä¹İ´óÌü");
  set ("long", @LONG
ÕâÀïÊÇ´¾·çÎä¹İµÄÕıÌü£¬ÎåÕÅÌ«Ê¦ÒÎÒ»×ÖÅÅ¿ªÃæ¶Ô×ÅÃÅ¿Ú£¬ÕâÊÇÎä
¹İÖĞËÄÎ»´óÊ¦¸µÓë¹İÖ÷Áø´¾·çµÄ×ùÎ»£¬ºÍÒ»°ãÎä¹İ²»Í¬µÄÊÇ£¬Ç½ÉÏ¾¹È»
¹Ò×Å¼¸·ù·ç¹ÇÆÄÎª²»Ë×µÄÊé»­£¬ÏÔÊ¾ÕâÀïµÄÖ÷ÈË²¢·Ç´ó×Ö²»Ê¶µÄ´Öºº£¬
¶øÊÇÎÄÎäË«È«µÄ¸ßÈË¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"school2",
  "east" : __DIR__"inneryard",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/swordsman" : 1,
]));
  set("valid_startroom", 1);

  setup();
}
