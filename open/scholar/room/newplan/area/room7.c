// Room: /u/s/sueplan/newplan/area/room7
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÌì¸®[1;33mÐÇ[0m");
  set ("long", @LONG
æûÍõ»¹Ã»È¢æ§¼ºÎªµÚ¶þ·òÈËÒÔÇ°£¬ÓÐ¸öÕýÊ½µÄ½ª»Êºó¡£½ª»ÊºóÒ»Î»
ÏÍ»ÛµÄ¸¾ÈË£¬¾ßÓÐ²ÅÄÜ£¬Ð­Öú·ò¾ýÖÎºÃÒó³¯Ò»Ê±¡£²»¹ý£¬×Ô´Óæ§¼º·î¾Å
ÌìÐþÅ®Ö®Ãü»ì½ø¹¬ÖÐºó£¬æûÍõµÄ³è°®×ÔÈ»ÇãÏòæ§¼ºÒ»ÈËÉíÉÏ¡£½ª»ÊºóÒ²
ÎÞÐÎÖÐÊ§È¥È¨Á¦£¬ºóÀ´ÓÖÊÜÁËæ§¼º¼µ¶ÊÐÄ¶ø²ÒÔâÉ±º¦¡£            
    ½ª»ÊºóµÄ¼ÒÏç£¬Îï²ú·á¸»¡£µ±ËýÈÎ»ÊºóÒÔºó£¬Ëý³ý´È±¯´ýÈËÍâ£¬»¹
¹±Ï××Ô¼ºÓÅÔ½µÄ²ÅÄÜºÍµØ·½·á¸»µÄÎï²ú¡£Òò´Ë£¬½ª»ÊºóËÀºó£¬ËýÁé»ê±»
ÕÙÈ¥ÓÀ×¤Ìì¸®ÐÇ£¬ÕÆ¹Ü¡®²ÅÄÜ¡¯¡¢¡®Îï²ú¡¯¡¢¡®´È±¯¡¯¡£  

LONG);

  set("no_transmit", 1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"room6.c",
  "north" : __DIR__"room8.c",
]));

  setup();
}
