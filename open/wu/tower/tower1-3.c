// Room: /u/p/pokai/room/wu/tower1-3
inherit ROOM;

void create ()
{
  set ("short", "武威七杀塔一楼");
  set ("long", @LONG
一进到这儿，你就被突如其来的的敌人所攻击。你定了定神后，注意到这间房间
到处都是干掉的血渍，四周的墙壁也都布满了打斗过的痕迹。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tower1-2",
  "climb" : __DIR__"tower2-1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"killer1-1" : 4,
]));

  setup();
}

int valid_leave(object me, string dir) {
  if(dir=="climb"&&present("tower guard",environment(me))) {
  return notify_fail("塔底守卫大叫：想上去！先杀了我们再说！\n");
  } 
 return 1;
}
