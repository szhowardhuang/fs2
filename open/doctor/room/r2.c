inherit ROOM;
void create()
{
        set("short", "药圃");
        set("long", @LONG

    靠着弯延的小路你来到了这里，发觉这里的药草
    与中土的不大一样，抬头看了看挂在树上的指标
    ，上面写的:

          一号栽种区: 南蛮药草试种实验地区。
                                                          
LONG
        );
        set("can_search",1);
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r5.c",
  "south" : __DIR__"r3.c",
  "north" : __DIR__"r1.c",
]));
        set("no_clean_up", 0);

        setup();
        }


