#include <room.h>
#include "dunno.h"

inherit ROOM;

void create ()
{
  set ("short", "洞穴");
  set ("long", @LONG
这里是洞穴的内部，在西面的石壁(wall)
上似乎勉强可以看到几个字：
 
    「仙剑无极，魔刀莫测”
 
                  独孤愁
 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hole.c",
  "up" : __DIR__"hole10",
]));

  setup();
}
void init()
{
      add_action("do_look","l");
           add_action("do_look","look");
        add_action("do_key","key");
}
int do_look(string str)
{
      if(str!="wall") return 0;
	tell_object(this_player(),"你发现墙上有一块石板(board)。\n");
       return 1;
}
int do_key(string str)
{
	if( str != KEY_WORD+" on board" ) return 0;
		tell_object( this_player() , "结果「喀”的一声，你打开了石璧的门。\n");
         tell_object(this_player(),"你进入了密室。\n");
 this_player()->move("/open/gblade/room/secret.c");
tell_room(environment(this_player()),sprintf ("%s打开石室的门，走了进来。\n",
this_player()->short()),this_player());
         return 1;
}
