#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","银狼组组");
  set ("long", @LONG
这里是黑牙联总坛大厅左翼，也是黑牙联最狡诈的银狼暗杀组的所在地。
韦亦玄在此处，策画黑牙连的所有暗杀计画，并且训练暗杀人员。
各大门派有不少人，被银狼组所设下的圈套所杀害。
如果没事还是不要在此处乱走，以免遭到杀害。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "eastup":__DIR__"ru9.c",
  "west":__DIR__"silr2",
  "south":__DIR__"silr4",
]));

  set("objects",([
        "/open/killer/npc/silnpc1.c" : 2,
        ]));  
  setup();
}