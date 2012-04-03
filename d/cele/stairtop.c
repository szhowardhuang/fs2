inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m Ë®ÑÌ¸ó°ëÉ½Í¤");
  set ("long", @LONG
    ÕâÀïÊÇÒ»¸öÓÃ°×Ê¯Æö³ÉµÄÍ¤×Ó£¬Í¤×ÓµÄ¶«ÃæºÍ±±Ãæ¶¼ÊÇÉî²»¼ûµ×µÄ
ĞüÑÂ£¬´ÓÕâÀïÍû³öÈ¥Ö»¼ûÒ»Æ¬ÔÆÎíÖ®ÖĞÍ»³ö¼¸×ùÉ½·å£¬ÔÆÎíÖ®ÖĞÒşÒş¿É
ÒÔ¿´µ½ºÃËÆË®²¨µÄÎ¢¹â£¬Ê¹ÄãÒ»Ê±Ö®¼ä·Â·ğÒÔÎªÕâ×ùÍ¤×ÓÊÇ½¨ÔÚÒ»¸öºş
ÖĞ£¬ÍùÎ÷±±ÍûÈ¥¿ÉÒÔ¿´µ½Ë®ÑÌ¸óÆ¯¸¡ÔÚÔÆÎíÖ®ÖĞ¡£

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "westup" : "/d/cele/stair3",
  "southdown"  : "/d/cele/stair2",
]));

        set("objects", ([
                "/d/cele/npc/watcher": 1,
                "/d/cele/npc/cele_tiger": 1 ]) );

  setup();
}
