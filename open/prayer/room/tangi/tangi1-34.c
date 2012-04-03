
//open/prayer/room/tangi/tangi1-34.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","大门");
        set("long",@LONG
	
                             ,,         ,           ,;;;;;,,   ,,,,,,,,
     '''''';;''''''          ;;   ,;;, ;; ,,;,      ;;,,,,;;   ;,,,,,;;
           ;;             ,,,;;,,';,,;';; ;,,;'     ;;'''';;   ;''''';;
     ,,,,,,;;,,,,,           ;;  ,;'';;'; ,;';,     ;;,,,,;;   ;,,,,,;;
     '''''';;'''''          ,;;;, ''''  ; '';',;    ;;'''''          ;;
          ,;;;,           ,;';; ',,,,,,,;;,,,,;,,   ;'               ;;
        ,;'   ';,,       ;;' ;;    ,;    ;, ,;,    ;;                ;;
     ,,;'       ';;,,        ;;   ,;;;,,  ;;;'    ,;'                ;;
 ,;;;''           ';;;;,,    ;; ,;;'   ',;'';;,,,;;'                 ';,
  '                  '''     ''         '     '''''                   ''

LONG);
        set("item_desc", ([ /* sizeof() == 1 */
        "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"tangi1-31",		//练武场
        "east":"/open/prayer/room/westarea/road10",	//马路
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/door-looker" : 2,		//大门守卫 
   		
]));
        set("light_up", 1);
        create_door("north","圣火刻纹精钢大门", "south",DOOR_CLOSED);
  setup();
}
