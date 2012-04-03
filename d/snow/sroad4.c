// Room: /d/snow/sroad4.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ÇàÊ¯¹ÙµÀ");
  set ("long", @LONG
ÕâÊÇÒ»Ìõ¿í³¨¼áÊµµÄÇàÊ¯°å´óµÀ£¬´óµÀÁ½ÅÔÖÖ×ÅÕûÆëµÄ»¨Ä¾£¬´ÓÕâ
ÀïÍù±±µÄÂ·´ø×ÅÒ»µãëüëÊ£¬ÍùÄÏÔòÊÇÏÎ½ÓÑ©Í¤Õò½ÖµÀµÄÂ·¿Ú¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sroad3",
  "north" : "/d/cele/sroad1",
]));
  set("outdoors", "snow");

  setup();
}
