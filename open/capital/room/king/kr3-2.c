// Room: /open/capital/room/king/kr3-2
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "皇城禁地");
  set ("long", @LONG
这儿就是大内皇城禁地, 在此地不得大肆喧哗, 在附近时常有禁卫
军在巡逻, 北边不远处可看到慈禧殿的一角,往南走可通往东厂.
LONG);

  set("outdoors", "/open/capital");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/capital/room/king/kr4-2",
  "north" : "/open/capital/room/king/kr2-2",
  "east" : "/open/capital/room/king/kr3-3",
]));
  set("file_name", "/open/capital/room/king/kr3-2");

  setup();
}
int valid_leave(object who,string dir)
{
  if(dir && present("soldier",environment(who)))
  {
        if((who->query("class")=="officer" && who->query_temp("can_in")==1) || (who->query("class")=="taigan"))
        {
        return :: valid_leave(who,dir);
        }
        else
        {
  return notify_fail("皇城禁卫军说道:你想跑?!跑得掉吗?\n");
        }
  }
        return :: valid_leave(who,dir);
}
void init()
{
        add_action("do_exert","exert");
}
int do_exert(string str)
{
 object me;
 me=this_player();
 if(str=="roar"){
 message_vision(HIC"皇宫守卫大声的对你说:皇城禁地岂容你大声喧哗，还不快滚!!!\n"NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}
