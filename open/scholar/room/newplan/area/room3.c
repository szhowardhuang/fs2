// Room: /u/s/sueplan/newplan/area/room3
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÌ«Ñô[1;33mÐÇ[0m");
  set ("long", @LONG
ÒóÄ©µÄæûÍõËäÈ»ÊÇÒ»¸ö²ÐÅ°µÄ±©¾ý£¬µ«ÊÇËûµÄÖÜÎ§Ò²ÓÐÁË²»ÉÙµÄÖÒ
³¼¡£ÆäÖÐÓÐÒ»Î»×îÖøÃûµÄ¾¡ÖÒÖ¾ÍÁÃû½Ð±È¸É¡£æûÍõÕý³è°®æ§¼º£¬²»¹ËÕþ
ÊÂÊ±£¬±È¸É±ãÍ¦ÉíÏàÈ°¡£µ«ÊÇÒ»µ©ÃÔÓÚÉ«ÏãµÄæûÍõ£¬×°×ÅÂí¶ú¶«·ç£¬ÖÃ
Ö®²»Àí¡£±È¸É²»ÅÂ±©¾ýÉúÆø£¬¾­³£¿à¿ÚÈ°ËûÎªÃñÊ©Õþ¡£Òò´Ë£¬·´±»æûÍõ
ÒÉÎª¼é³¼¡£ÕâÊ±£¬±È¸ÉÈÔÊÇ²»Å­²»ºÞµØËµµÀ£º¡®Èç¹û±ÝÏÂ²»ÏàÐÅÎÒ£¬Ö»
ºÃ°ÑÎÒµÄÐÄÏ×¸øÄú¿´¡£¡¯
    Ëµ°Õ£¬°Î½£´ÌÐØ£¬ÍÚ³ö×Ô¼ºµÄÐÄÔà¸øæûÍõ¿´£¬È»ºó´ÓÈÝËÀÈ¥£¬Ì«°×
½ðÐÇ·Ç¸Ð¶¯±È¸ÉÉáÉúÈ¡ÒåµÄÖÒÁÒ¾«Éñ£¬±ãÕÐ»ØËûµÄÁé»êÓÀ×¤Ìì½çµÄÌ«Ñô
ÐÇ£¬ÆäÇëËûÕÆ¹ÜÌìµØ¼äµÄ¡®¹âÃ÷Õý´ó¡¯¡£

LONG);

  set("light_up", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"room2.c",
  "north" : __DIR__"room4.c",
]));

  setup();
}
