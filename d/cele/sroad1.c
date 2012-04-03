
inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ýÈ¥Ê±¿Õ[0m ÇàÊ¯¹ÙµÀ");
  set ("long", @LONG
    ÕâÊÇÒ»Ìõ¿í³¨¼áÊµµÄÇàÊ¯°å´óµÀ£¬´ÓÕâÀïÒÑ¾­¿ÉÒÔÍû¼û±±±ßÉ½ÑüÉÏ
Ë®ÑÌ¸óÁðÁ§É«µÄÎÝÍß£¬Ó³×ÅÉ½ÉÏÃ¯ÃÜµÄ·ãÊ÷ÁÖ£¬ÏÔµÃÊ®·ÖÊ«Çé»­Òâ£¬ÓÉ
ÓÚÕâÌõÂ·ÊÇ½û±øÍ³ÁìÇ××Ô¶½Ôì£¬Òò´ËÔìµÃ¸ñÍâÆ½Õû£¬´ÓÕâÀï¿ªÊ¼ÒÑ¾­½ø
ÈëÓÉÀú´úË®ÑÌ¸óÖ÷ÈËËù¹ÜÏ½µÄ·âµØ£¬¼´Ê¹ÊÇ¹Ù¸®Ò²²»ÄÜ¹ýÎÊÕâÆ¬ÍÁµØÉÏ
·¢ÉúµÄÊÂ£¬Òò´ËÄã×îºÃÐ¡ÐÄÒ»µã¡£

LONG);
  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/cele/sroad2",
  "south" : "/d/snow/sroad4",
]));

  setup();
}
