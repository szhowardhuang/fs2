inherit ROOM;

void create()
{  
   
   set("short","活火山");
   set ("long", @LONG
四周温度渐渐高了起来，走没几分钟便汗下
如雨，跟岛上其它处的美景相较，这里仿佛是地
狱一般．                    
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */

 
  "south" : "/open/island/room/m2",  

]));
  
  set("outdoors", "/open/main"); setup();
}

