// Room: /u/s/sueplan/newplan/area/room8
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÌ«Òõ[1;33mÐÇ[0m");
  set ("long", @LONG
æûÍõÊÖÏÂÓÐ¸ö¾¡ÖÒµÄ»Æ·É»¢½«¾ü¡£»Æ·É»¢µÄÆÞ×ÓÄêÇáÃ²ÃÀ£¬ÔÚÒó³¯
µÄÌìÏÂÊÇÎ¨Ò»ÄÜºÍæ§¼ºÏà±ÈµÄÃÀÈË¡£Òò´Ë£¬æ§¼ºÐÄ°§ºÜ²»¸ßÐË¡£»Æ·É»¢
µÄÌ«Ì«ÓÖ±»³Æ¼ÖÅ®ÈË¡£                        
    Òó³¯Ê±´ú£¬Ã¿·ê¹ýÄêÄÇÒ»Ìì£¬Öî´ó³¼ºÍ½«¾ü¶¼±ØÐë·òÆÞÍ¬ÐÐ£¬½ø¹¬
Ïò¾ýÖ÷°ÝÄê¡£×·ÊÇÒ»ÖÖ´«Í³µÄ¹ßÀý¡£¼Ö·òÈËÒ²¸úËæ»Æ·É»¢½«¾ü½ø¹¬°ÝÄê
¡£ÕâÊ±£¬æ§¼º¶ÙÆðÐ°Äî£¬¿ÒÇëæûÍõ×¼ÐíËûºÍ¼Ö·òÈËÁô¹¬ÁÄÌì¡£»Æ½«¾ü±ã
¶À×ÔÏÈ»Ø¼ÒÁË¡£                                                    
    æ§¼ºÓÕ¼Ö·òÈËµÇÉÏ¹¬ÖÐ¸ßÂ¥£¬È»ºóÔì³É»ú»á£¬Ê¹¼Ö·òÈËµ¥¶ÀºÍæûÍõ
Ãæ¶ÔÀÖÑç¡£æûÍõÒ»ºÈ¾Æ£¬±ãÊ§È¥ÂñÖÇ£¬ÆðÁËºÃÉ«µÄ±¾ÐÔ£¬Ïë·ÇÀñÕâÎ»¾ø
ÊÀÃÀÈË¡£Ã²ÃÀµÄ¼Ö·òÈËÓÖÊÇÒ»Î»Õê½ÚÎÅÃûµÄÅ®ÐÔ£¬µ±È»ÍÆ´Ç¾Ü¾øæûÍõµÄ
ÒùÑÔÂÒÐÐ¡£æûÍõÆ¾½å¾ÆÊÆ£¬¶«×·Î÷×¥£¬Ê¹¼Ö·òÈË±¼ÅÜ¶ã¿ª¶øÊ§×ã¶éÂä¡£
Õê½Ú¾ÜÒùµÄ¼Ö·òÈËÒ»×¹±ãËÀ¡£Ì«°×½ðÐÇ¼ûËýÕê½Ú³¬ÈË£¬¾Í°ÑËûµÄÁé»ê´ø
»ØÌì½ç¡£                  
    ¼Ö·òÈË³ýÕê½ÚÍâ£¬»¹¾ßÓÐ½à°×µÄ¸öÐÔ¡£ÎÞÂÛ¸øËýÄÇÒ»ÐÇ×ù£¬Ëý×ÜÊÇ²»
±íÊ¾Í¬Òâ¡£Ì«°×½ðÐÇ²»µÃ²»ÇëËý×¡ÔÚÇåÓÄµÄÔÂÇòÉÏ£¬°ÑÔÂÇò½Ð×öÌ«ÒõÐÇ¡£
ÔÚÔÂÇòÉÏµÄ¡®Ì«Òõ¡¯Éñ¼Ö·òÈË±ã´Ó´ËÕÆ¹Ü¡®Çå½à¡¯ºÍ¡®×¡Õ¬¡¯¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_hace.c" : 1,
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room9.c",
  "south" : __DIR__"room7.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="enter"&&present("scholar",environment(me)))
  {
  return notify_fail("Äã·¢¾õÓÐÈËµ²ÔÚÄãÃæ, ²»ÈÃÄã¹ý!!!\n");
  }
  return 1;
}
