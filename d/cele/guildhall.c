inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m Ë®ÑÌ¸óÇ°");
  set ("long", @LONG
    ÕâÀïÊÇË®ÑÌ¸óµÄÕıÌü£¬¼òµ¥µÄ³ÂÉèÖĞÍ¸³öÒ»¹É×ğ¹ó²»·²µÄÆøÅÉ£¬Ò»
ÕÅ÷îºÚµÄÌ«Ê¦ÒÎ¶Ë×øÔÚ´óÌüÖĞÑë£¬ÕâÀïÍ¬Ê±Ò²ÊÇ¡¸ÎäÕß¡±ÃÇÒéÊÂµÄËùÔÚ
£¬Ã¿ÄêµÄÕıÔÂÊ®Æß¶¼ÒªÔÚË®ÑÌ¸óÍâµÄ¡¸ºçÌ¨¡±ÍÆÑ¡ÎäÁÖÃËÖ÷£¬È»ºóÔÚÕâ
Àï¾ÙĞĞµÇÎ»´óµä¡£

LONG);

  set("outdoors", "cele");
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south": "/d/cele/enter",
]));

        set("objects", ([
                "/d/cele/npc/champion":1,
                "/d/cele/npc/master":1
        ]) );


  setup();
}
