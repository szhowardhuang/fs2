#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "地牢");
  set ("long", @LONG
又湿又黑的地牢中 ,真是不太好过 ,满地的积水 ,随便一动就踩的满
脚污泥 ,再加上那些恶心至极的小生物 ,令你不得不为那些整日关在
这不适人居的地方的人难过 .你忽然感到四周有异 ,可以用(search)
看看哪里有问题 .


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room21.c",
  "west" : __DIR__"path13.c",
]));
  create_door("east",HIY "黄色铁门"NOR, "west", DOOR_CLOSED);

  set("light_up", 0);
  set("valid_startroom", 1);

  setup();

}

void init()
{
        add_action("do_search", "search");
}

int do_search()
{
        object who;
        who = this_player();

        tell_object(who,"\n你脚底突然开了一个大洞 ,你一不小心 ,摔了下去。\n\n");
     who->move("/open/poison/room/room23.c");
        tell_room(this_object(),who->query("name")+"不知启动了什么机关, 突然消失
在地牢之中。\n");
        return 1;
}
