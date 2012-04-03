// Room: /open/dancer/room/roomse3.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "花园小径");
  set ("long", @LONG
这是一条小径，两旁长满了各式的鲜花，令人目不暇给，
芬芳的花香令人流连忘返，美丽的鲜花令人不禁想近而亵玩焉
东边是凉亭池而西边则是喷水池。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/dancer/room/roomse2.c",
  "east" : "/open/dancer/room/roomse4.c",
]));

  set("light_up", 0);

  setup();
}
