
inherit ROOM;
void create()
{
  set ("short", "交叉口");
  set ("long","
    在这里往难看过去灯火通明似乎很热闹，在你右边有
间大厅，这一路走来总觉的神神秘密的，机关一大堆眼看
大厅就在旁边而已，不过又看到另一边灯火通明想过去凑
热闹，赶快决定吧～

 ");
   set("exits", ([
   "jump"       : __DIR__"r14.c",
   "east"       : __DIR__"r18.c",
   "south"      : __DIR__"r21.c",
  ]));      
  set("light_up", 1);
  setup();
} 

