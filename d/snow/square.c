// Room: /d/snow/square.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ¹ã³¡");
  set ("long", @LONG
ÕâÀïÊÇÑ©Í¤ÕòÕòÇ°¹ã³¡µÄ¿ÕµØ£¬µØÉÏÕûÆëµØÆÌ×Å´óÊ¯°å¡£¹ã³¡ÖĞÑëÓĞ
Ò»¸öÄ¾Í·´îµÄ¼Ü×Ó£¬¾­¹ı¶àÄêµÄ·ç´µÈÕÉ¹ÓêÁÜ£¬¿´À´·Ç³£ÆÆ¾É¡£ËÄÖÜ½¨Öş
ÁÖÁ¢¡£ÍùÎ÷Äã¿ÉÒÔ¿´µ½Ò»¼ä¿ÍÕ»£¬¿´À´ÉúÒâËÆºõºÜºÃ¡£
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sroad1",
  "west" : __DIR__"inn",
  "north" : __DIR__"mstreet1",
  "east" : __DIR__"temple",
]));
  set("outdoors", "snow");

  setup();
}
