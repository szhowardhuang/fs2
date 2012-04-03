inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m Ë®ÑÌ¸ó´óÃÅ");
  set ("long", @LONG
    ÕâÀïÊÇË®ÑÌ¸óµÄÕıÃÅ£¬Ò»¹ÉÇßÈËĞÄÆ¢µÄÌ´ÏãÊ¹Äã¾«ÉñÎªÖ®Ò»Õñ£¬Õı
ÃÅ¹²·ÖÈı½ø£¬È«²¿¶¼ÊÇÉÏµÈµÄÌ´Ä¾µñ³É£¬×îÀïµÄÃÅÉÏĞü×ÅÒ»¿éØÒ¶î£¬ÉÏ
ÃæÁú·É·ïÎèµØĞ´×Å¼¸¸ö´ó×Ö£¬¿ÉÊÇÄãÈ«È»¿´²»³öµ½µ×ÊÇÊ²Ã´×Ö¡£

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "north"  : "/d/cele/guildhall",
  "south": "/d/cele/frontyard",
]));


  setup();
}
