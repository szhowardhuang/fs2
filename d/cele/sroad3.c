inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ÇàÊ¯¹ÙµÀ");
  set ("long", @LONG
    ÕâÊÇÒ»Ìõ¿í³¨¼áÊµµÄÇàÊ¯´óµÀ£¬´óµÀÑØ×ÅÉ½ÑüÍù¶«ÏòÉ½ÏÂÑÓÉì£¬Ò»
µÀ³¤³¤µÄ°×Ê¯½×Ìİ´ÓÕâÀïÍù±±±ßÉÏÉ½£¬´ÓÕâÀïÑöÍû½×ÌİµÄ¾¡Í·ÓĞÒ»×ùĞÛ
Î°µÄÂ¥¸ó£¬ÄÇ¾ÍÊÇÖøÃûµÄ¡¸Ë®ÑÌ¸ó¡±¡£

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/cele/sroad2",
  "northup"  : "/d/cele/stair1",
]));

        set("objects", ([
                "/d/cele/npc/guard": 2 ]) );

  setup();
}
