
inherit ROOM;
void create()
{
  set ("short", "大澡堂");
  set ("long","
    稀哩哗啦的声音一堆，原来这里是大澡堂，在旁边衣
物架中还堆满了一些内衣裤在你旁边还有人在赶着洗澡，
好像赶着要做啥事一样，更里面那间还有人在唱歌咧，听
了就想过去杀死他咧。

 ");
   set("exits", ([
   "north"   : __DIR__"r25.c",
   "west"    : __DIR__"r31.c",
   
  ]));      
  set("light_up", 1);
  setup();
} 

