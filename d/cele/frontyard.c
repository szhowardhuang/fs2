inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ýÈ¥Ê±¿Õ[0m Ë®ÑÌ¸óÇ°");
  set ("long", @LONG
    ÄãÏÖÔÚÕýÕ¾ÔÚÒ»×ù¸ß´óµÄÂ¥¸ó£¬Ë®ÑÌ¸óÇ°£¬ÁðÁ§É«µÄÎÝÍßºÍ°×Óñ°ã
µÄ°×Ê¯×©Ê¹µÃË®ÑÌ¸óÔÚ³çÉ½¾þÁëÖÐÏÔµÃÊ®·ÖÇÀÑÛ£¬Õâ×ùÂ¥¸ó×îÔçµÄÖ÷ÈË
¾ÝËµÊÇÓÐ¡¸ÎäÊõÖ®Éñ¡±³ÆºÅµÄÌ«ÑôÉñ¾ý¡¸è½Ó¹¡±£¬ºóÀ´±»µ±×÷Àú´úÎäÁÖ
ÃËÖ÷µÄ¾ÓËù£¬¿ÉËµÊÇÑ§ÎäÖ®ÈËµÄ³¯Ê¥µØ£¬Ò»Ìõ°×Ê¯½×ÌÝÑØ×ÅÉ½ÑüÍùÄÏ¶ø
ÏÂ£¬Ë®ÑÌ¸óµÄ´óÃÅ¾ÍÔÚÄãµÄ±±·½¡£

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "north"  : "/d/cele/enter",
    "southdown": "/d/cele/stair3",
  "west"     : "/d/cele/path1",
]));


  setup();
}
