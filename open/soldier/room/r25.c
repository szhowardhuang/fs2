
inherit ROOM;
void create()
{
  set ("short", "大通铺");
  set ("long","
    这边已经算是反乱军们睡的地方了由于经费不足所以
大伙睡的地方挤了点，在这里以依稀可以听到水稀稀的声
音，在你旁边有扇门漏出一点光线，地上还溅初一滩水出
来，过去看看有啥好看的吧。

 ");
   set("exits", ([
   "south"   : __DIR__"r30.c",
   "west"    : __DIR__"r26.c",
   
  ]));      
  set("light_up", 1);
  setup();
} 
