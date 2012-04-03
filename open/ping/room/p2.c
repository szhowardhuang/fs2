// Room: /open/ping/room/p2
inherit ROOM;

void create ()
{
  set ("short", "³¤ÀÈ");
  set ("long", @LONG
×ß½øÕâÀï, ÊÇÒ»Ìõ³¤ÀÈ, ÍùÇ°Í¨Íù´óÌü, ¶øÍùÁ½ÅÔÒ²¸÷ÓĞÒ»Ìõ×ßµÀ
³¤ÀÈÉÏÆÌ×ÅÉÏºÃµÄ´óºìµØÌº, ³ÄÍĞ³öÒ»¹É×¯ÑÏµÄÆø·Õ¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"p1",
  "west" : __DIR__"p3",
  "out" : __DIR__"pingking",
  "east" : __DIR__"p5",
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
         if( dir=="east" && me->query("family/family_name")!="¶Î¼Ò" )
         if(!wizardp(me))
      return notify_fail("Ñó´ĞĞ¡Íè×ÓËÆĞ¦·ÇĞ¦µÄ¶ÔÄãËµ: [1;36m²»¸ø½ø¡£[0m\n");
        return ::valid_leave(me, dir);
}

