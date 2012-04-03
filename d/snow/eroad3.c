// Room: /d/snow/eroad3.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m É½Â·");
  set ("long", @LONG
ÕâÊÇÒ»ÌõËµ¿í²»¿í£¬ËµÕ­µ¹Ò²²»Õ­µÄÉ½Â·£¬Â·ÃæÓÃ¼¸¿éÉúÂúÇàÌ¦µÄ
´óÊ¯ÆÌ³É£¬Î÷ÃæÊÇÒ»¶ÎÆÂµØ£¬´ÓÕâÀï¿ÉÒÔÍû¼ûÎ÷±ßÓĞ¼¸¼ä·¿Îİ´íÂäÔÚÁÖ
Ä¾¼ä£¬¶«ÃæÔòÊÇÉ½±Ú£¬É½Â·ÍùÎ÷ÄÏÏÎ½ÓÒ»Ìõ»ÆÍÁĞ¡¾¶¡£

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"eroad2",
]));
  set("outdoors", "snow");

  setup();
}
