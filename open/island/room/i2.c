inherit ROOM;

void create()
{  
   
   set("short","望天崖");
   set ("long", @LONG
这里是神仙岛的最北端，由此地望去，只见海天
一色，碧蓝的海上缀着点点粼光，偶尔有几只海鸥悠
然的从天上滑过，带着咸味的海风，自你的脸上轻拂
而过，令人心旷神怡．                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */

   "southwest" : "/open/island/room/i1",
    "south" : "/open/island/room/i3",
  "southeast" : "/open/island/room/i15",
]));
   set("outdoors", "/open/main");

 setup();
}


