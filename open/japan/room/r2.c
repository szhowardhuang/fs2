// Room: /open/japan/room/r2
inherit ROOM;

void create()
{
  set ("short", "东瀛岛入口");
  set ("long", @LONG
这是一个神秘的岛屿,岛上居民与中原武林有极大的差异
                         ....未完工^_^
LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  setup();
}
