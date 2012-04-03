inherit ROOM;

void create()
{
   set("short","石室");
   set("long",@LONG
这里是当年郑士欣闭关研究武学所建成的石室，在这四周的墙壁上，
刻了无数的人形，每个人形都有着不同的姿势，像是在舞剑一般，当你注
视着这些人形时，犹如望见郑士欣的身影一般，所用武功皆是惊世之武学
，令你不禁拔起了剑，随着那身影舞动了起来，不知不觉间，你的剑法已
更上一层楼。
 

LONG);
  
   set("exits", ([ /* sizeof() == ? */
   "leave" : "/open/gsword/room/h-3.c",
   ]));
   
   set("valid_startroom", 1);
   set("no_clean_up",1);
       set("no_transmit", 1);


set("objects", ([ /* sizeof() == 1 */
   "/open/gsword/npc1/yan" :1,
]));
   set("light_up",10);
   setup();
}
      
