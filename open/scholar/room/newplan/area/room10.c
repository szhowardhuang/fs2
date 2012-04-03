// Room: /u/s/sueplan/newplan/area/room10
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÌìÏà[1;33mĞÇ[0m");
  set ("long", @LONG
    æûÍõÊÖÏÂÓĞĞí¶àÖÒ³¼£¬ÆäÖĞÓĞÒ»Î»ÎÅÌ«Ê¦£¬È´ÊÇ²»ÄÜ±»ÒÅÍüµÄ
´æÔÚ¡£¡®Ì«Ê¦¡¯¼´ÎªÊ×Ïà£¬ÈçÎÒ¹úµÄĞĞÕşÔº³¤¡£ÎÅÌ«Ê¦²»µ«ÕÆÎÕÈ«¹úĞĞ
Õş£¬¶øÇÒ¼æÈÎ´óÔªË§¡£
    ¿É×ãÎÅÌ«Ê¦ÔÚÒó¡¢ÖÜ×îºóÒ»³¡´ó¾öÕ½ÖĞ£¬±»ÖÜ¾ü¹¦»÷¹¥»÷¶øÕ½ËÀ¡£
Ì«°×½ğĞÇ¸Ğ¶¯ËûµÄÖÒÓÂ¾«Éñ£¬¾ÍÒı»êµ½Ìì½ç£¬ÇëËûÓÀ×¡ÌìÏàĞÇ¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_houng.c" : 1,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room9.c",
  "ÕóĞÄ" : __DIR__"jroom.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="ÕóĞÄ"&&present("scholar",environment(me)))
  {
  return notify_fail("Äã·¢¾õÓĞÈËµ²ÔÚÄãÃæ, ²»ÈÃÄã¹ı!!!\n");
  }
  return 1;
}
