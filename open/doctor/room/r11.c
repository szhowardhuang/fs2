inherit ROOM;
void create()
{
        set("short", "药圃");
        set("long", @LONG

    这里是园地内较高的坡地，所以在这里建
    了一座高台，用来晒晒刚采下的药材。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"r11-1",
  "south" : __DIR__"r10",
  "east" : __DIR__"r8",
]));
        set("can_search",1);
        set("no_clean_up", 0);
        set("outdoors", 1);

        setup();
        }


