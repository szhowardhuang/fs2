inherit ROOM;

void create()
{  
   
   set("short","农庄别院");
   set ("long", @LONG
你来到一个小农庄，这似乎是整座岛上唯一的建
筑物，屋内是极为清幽的摆设，住在这的老农夫
像是知道些什么．
                     
LONG);
   set("light_up", 1);
set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/hen" : 2,
  "/open/island/npc/farmer" : 1,
]));
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */
 
   "south" : "/open/island/room/i12",
    

]));
  

 setup();
}

