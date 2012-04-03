// Room: /u/s/sueplan/newplan/area/room4
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÎäÇú[1;33mĞÇ[0m");
  set ("long", @LONG
ÎäÍõ¾ÍÎ»ºó£¬Ò»Ãæ»ı¼«´Ó´ÓÊÂÃğÒó¸´³ğ£¬Ò»ÃæÊ©ĞĞµÂÕş£¬Ê¹ÈËÃñ°²
¾ÓÀÖÒµ£¬×Ô¼ºÒ²ÏíÌìÊÙºó²ÅÈ¥ÊÀ¡£Ì«°×½ğĞÇºÜÅå·şÎäÍõÌÖæûµÄÓ¢ÓÂÎä¹¦
£¬±ãÇëËûµÄÁé»êÓÀ×¡ÎäÇúĞÇ£¬ÕÆ¹Ü¡®²Æ¸»¡¯ºÍ¡®ÎäÓÂ¡¯¡£ÒòÎªËûÔÚÊÀÆÚ
¼äÎä¹¦¼ÈºÃ£¬ÓÖ»ı¼«Ä±ÇóÈËÃñµÄ²Æ¸»¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_show.c" : 1,
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room5.c",
  "south" : __DIR__"room3.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="enter"&&present("scholar",environment(me)))
  {
  return notify_fail("Äã·¢¾õÓĞÈËµ²ÔÚÄãÃæ, ²»ÈÃÄã¹ı!!!\n");
  }
  return 1;
}
