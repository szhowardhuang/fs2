// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","一楼长廊");
        set ("long","四周似乎还潜伏着什么妖魔鬼怪,令人心里惶惶不安。地板是由已腐旧的的木板
钉成,走在上面不停的发出嘎吱嘎吱的声音。

                      ～嘎吱～嘎吱～

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "west" :  __DIR__"room21",
            "east"  : __DIR__"room23",
            
       ]));
       set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/older" : 1,
      ]));
        

        setup();
}
