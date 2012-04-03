#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ÃÅ¿Ú");
        set("long", @LONG
[1;37m
          ¨X¨T¨[  ¨X¨T¨T¨[     ¨X¨T¨[     ¨[    ¨X¨T¨T¨[¨X¨T¨T¨[
        ¨X¨a  ¨^¨[¨U¨X¨T¨g   ¨X¨a  ¨^¨[   ¨U    ¨d¨T¨T¨U¨d¨T¨T¨U
        ¨U¨T¨j¨T¨U¨U¨^¨a¨U   ¨U¨T¨j¨T¨U ¨T¨p¨T  ¨d¨T¨T¨a¨^¨T¨T¨g
        ¨U¨T¨p¨T¨U¨d¨T¨T¨a   ¨U¨T¨p¨T¨U   ¨U    ¨U            ¨U
        ¨a¨[¨U¨X¨^¨U¨T¨[¨a   ¨a¨[¨U¨X¨^   ¨U    ¨U            ¨U
        ¨T¨m¨m¨m¨T¨^¨T¨^¨T   ¨T¨m¨m¨m¨T   ¨U    ¨^            ¨a
[0m
LONG
        );
        set("light_up", 1);
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 2 */

      "south" : __DIR__"d2",
      "north" : __DIR__"2-door",
]));
        set("no_clean_up", 0);

        setup();
        }


