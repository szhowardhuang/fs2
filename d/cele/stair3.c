inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m °×Ê¯½×Ìİ");
  set ("long", @LONG
    ÄãÏÖÔÚÕı×ßÔÚÒ»Ìõ³¤³¤µÄ°×Ê¯½×ÌİÉÏ£¬½×ÌİËæ×ÅÉ½·åòêÑÑÅÌĞı£¬Íğ
ÈçÒ»Ìõ°×Áú£¬Ë®ÑÌ¸ó¾Í´£Á¢ÔÚ±±±ßµÄÉ½·å¶¥ÉÏ£¬¼´Ê¹ÊÇ´ÓÕâÃ´½üµÄ¾àÀë
ÄãÈÔÈ»¸Ğ¾õÕâ×ùÂ¥¸óÆ®Æ®ÃìÃì£¬ÄÑÒÔ×½Ãş¡£

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "northup"  : "/d/cele/frontyard",
  "eastdown": "/d/cele/stairtop",
]));


  setup();
}
