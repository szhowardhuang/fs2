inherit ROOM;
void create()
{
        set("short", "药圃");
  set ("long", @LONG

              大内药物培植地
   这里有着整齐的花圃，正是银针门的栽种区..
LONG);
        set("can_search",1);
        set("outdoors",1);

        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r11",
  "east" : __DIR__"r9",
]));
        set("no_clean_up", 0);

        setup();
        }


