#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "荒舞修罗道");
        set("long", @LONG
这里是通往天界之城的必经之地，也是介于人类与神族之间的悲剧族
群 -- 修罗出没的地方，由于天界众神与魔界之间长年的征战，使得天界
元气大伤，也让修罗日渐坐大，虎视眈眈的想占领天界之城，如果你想踏
进这块危机四伏的区域，得先作好心里准备。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sky1",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);

        setup();
        }
