inherit ROOM;
void create()
{
  set ("short", "走廊");
  set ("long", @LONG
由于杀手们长年追杀他人，导致仇家不少，总坛自然成了最佳的避风港。
为了方便长期躲藏，特地派专人运补粮草，北方就是杀手的专卖室。
西边是杀手专用的炼丹房，据说杀手密药就是在哪里调制的。
LONG);
   set("exits", ([
   "east"   : __DIR__"floorm.c",
   "west"   : __DIR__"pillrm.c",
   "north"  : __DIR__"sellrm.c",
  ]));
   set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  set("light_up", 1);
  setup();
} 
