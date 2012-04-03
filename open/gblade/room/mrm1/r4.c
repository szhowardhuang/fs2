// Room: /u/m/moner/water/mblade/r4.c
inherit ROOM;

void create ()
{
  set ("short", "ÃÜÊÒ");
  set ("long", @LONG

ÕâÊÇÒ»¼äÃÜÊÒ£¬ËÄÖÜ¹âÏß¼«Èõ£¬ÑÛÇ°ÓĞÒ»Î»°×·¢Æ®É¢£¬ÑÛÉñÁè
Á¢µÄÈË£¬¿ÉÊÇ´ËÊÒÉ¢·¢³öÄÑÎÅ³ôÎ¶£¬ÑÛÇ°µÄÈËËÆºõ±»¹ØÔÚÕâ¡£

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"r3.c",
]));
set("objects",([
"/daemon/class/blademan/npc/old-man.c":1,
]));
set("no_transmit", 1);
  setup();
}
void init()
{
add_action("do_jump","to-jump");
}
int do_jump(string str)
{
  object me;
  me=this_player();
if(me->query_temp("can_jump")!=1)
return notify_fail("Ìø....Ìø....ÄãÒªÌøºÓÑ½£¡\n");
  if( str != "hole" )
return notify_fail("²»ÒªÔÚµØÉÏÂÒÅÀÀ²£¿\n");
message_vision("[1;34mÄãÕÒµ½Ò»¸öÃØ¶´£¬¾Í·ÜÁ¦Íù¶´ÄÚÒ»Ìø£¡\n[0m",me);
me->move("/daemon/class/blademan/bladeroom.c");
me->set_temp("can_jump",0);
  return 1;
}
