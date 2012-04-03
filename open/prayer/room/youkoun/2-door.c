//open/prayer/room/youkoun/2-door.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","´óÃÅ");
        set("long",@LONG

                ,,;,                ,,              ,;;;;;,,   ,,,,,,,,
            ,,;;;  ';;,          ,  ;'              ;;,,,,;;   ;,,,,,;;
 ,;;;;;;, '';,, ';,,;'       ,,;;'  ;   ;;;,,       ;;'''';;   ;''''';;
     ;       ;;;;''                 ;               ;;,,,,;;   ;,,,,,;;
  ,,,;,,,';;';;,,,,,,,     ,,;;;;;;;;;;;;;;;;;      ;;'''''          ;;
 '''';'''   ,'  ';                ;; ;              ;'               ;;
     ;    ,,,,,;;;';,,,,,       ,;'  ;             ;;                ;;
 ,,,;;;;;   ,,   ;   ,,       ,;'    ;            ,;'                ;;
 ''         ;;  ,;,,,;;   ,,;;'      ';,,,,,,,;;';;'                 ';,
             '''''''''    '''             '''''  ''                   ''

LONG);
     set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"20",            //Á·Îä³¡
        "east":"/open/prayer/room/westarea/road34",     //ÂíÂ·
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/door-looker1" : 2,            //´óÃÅÊØÎÀ 
                
]));
        set("light_up", 1);
        create_door("north","Ê¥»ğ¿ÌÎÆ¾«¸Ö´óÃÅ", "south",DOOR_CLOSED);
  setup();
}

int valid_leave(object me, string dir)
{

  if(dir=="north" && me->query("gender")== "ÄĞĞÔ" && !present("board",me))
      return notify_fail("[36mÄĞÈËÊÇÎŞ·¨½øÈëÑş¹âÃÅµÄ!³ı·ÇÄãÓĞ½ÌÖ÷µÄÁîÅÆ!![0m\n");
  
      return ::valid_leave(me,dir);
}
    
