// Room: /u/s/sueplan/newplan/area/room6
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÁ®Õê[1;33mĞÇ[0m");
  set ("long", @LONG
¼ÙÈçæûÍõµÄÖÜÎ§È«¶¼ÊÇ¾¡ÖÒ°®¹úµÄÖ¾Ê¿£¬¿ÉÄÜÒ²²»»áµ¼ÖÂÒó³±µÄÃğ
Íö¡£Ò²¿ÉÒÔËµ£¬ÊÇĞí¶à¼é³¼Öú³¤Ëûº¦ÈËº¦¼ºµÄ¡£ÆäÖĞÓĞÒ»¸ö½Ğ·ÑÖÙµÄ´ó
¼é³¼£¬ÎÜº¦ÁË²»ÉÙ³¯ÄÚµÄĞí¶àÖÒ³¼ÏÍÊ¿£¬·î³ĞæûÍõ£¬×¨ºáÈ¨ÊÆ¡£
    Òó³¯ÃğÍöºó£¬·ÑÖÙ±»½ªÉĞËù²¶¡£½ªÉĞ·Ç³£Ñá¶ñÕâÖÖ·ÇÈËµÄĞóÉú£¬ÓÚ
ÊÇÏÂÕ¶Ê×·ÑÖÙ¡£Ì«°×½ğĞÇÖªµÀÌì½çµÄÉñ²»×ã£¬¼´ÕÙ·ÑÖÙµÄÁé»êÈ¥×¡Á®Õê
ĞÇ£¬·âÎªĞ°¶ñÖ®Éñ£¬×¨¹Ü¡®ÍáÇú¡¯¡£ÕâµÈÓÚ»ù¶½½ĞÖĞµÄËùÎ½¡®Ä§¹í¡¯¡£ 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_yea.c" : 1,
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room7.c",
  "south" : __DIR__"room5.c",
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
