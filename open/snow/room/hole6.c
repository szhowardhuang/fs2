#include <room.h>

inherit ROOM;

void create()
{
        set("short","¶´Ñ¨");
        set("long","ÕâÊÇÒ»¼ä·ÏÆúµÄ[2~·¿¼ä,ÓÉµØÉÏµÄ»Ò³¾¿ÉÒÔ¿´³ö,½ü¼¸ÄêÀ´,ºÜÉÙÈËÀ´¹ıÕâÀïÁË¡£\n");

        set("item_desc", ([ /* sizeof() == 1 */  "west" : (: look_door, "west":),
]));

        set("exits", ([
          "west":__DIR__"hole7",
          "east":__DIR__"hole4",
          "south":__DIR__"hole8",
          "north":__DIR__"hole9",
        ]) );

        create_door("west","ÆáºÚÀÎÃÅ", "east",DOOR_CLOSED);

        setup();
}
