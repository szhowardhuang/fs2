#include <room.h>
inherit ROOM;

void create()
{
        set("short", "天险");
        set("long", @LONG
从奔云阶拾级而上，你来到了一座巨大的城池门口，这整座城池往左
右延伸了大约两公里，而眼前的城门也让你目瞪口呆，这扇城门宽度约十
五公尺，高度约二十公尺，门的两旁各有一座奇怪的石像 (statue) ，除
了一路走来的阶梯以及眼前的城池，四周围都是渺茫一片，一个失足便可
能摔到百尺之下的平原。
LONG
        );
        set("exits", ([
           "north": __DIR__"n5",
]));
        set("outdoors",1);
        set("objects", ([
]));
        set("item_desc", ([
        "statue":"奇怪的雕刻，看起来不像是人间的生物，右边石像的胸口有个菱形的凹陷(section)。\n",
        "section":"一个呈菱形的凹陷块，看起来可以嵌入些甚么。\n",
        ]) );

        setup();
}

void check_trigger()
{
        object room;
        if( (int)query("door_open")==1
        &&      !query("exits/south") ) {
                message("vision", "\n随着轰轰的声响，天界之城的大门打开来了。\n",this_object());
                set("exits/south", __DIR__"land_square");
                if( room = find_object(__DIR__"land_square") ) {
                        room->set("exits/north",__DIR__"land_gate");
                message("vision", "\n随着轰轰的声响，天界之城的大门打开来了。\n",room);
                }
                delete("door_open");
                call_out("close_passage", 10);
        }
}

void close_passage()
{
        object room;

        if( !query("exits/south") ) return;
        message("vision", "\n随着轰轰的声响，天界之城的大门关起来了。\n",this_object() ); 
        if( room = find_object(__DIR__"land_square") ) {
                room->delete("exits/north",__DIR__"land_gate");
        message("vision", "\n随着轰轰的声响，天界之城的大门关起来了。\n",room);
        }
        delete("exits/south");
}

void reset()
{
        ::reset();
        delete("door_open");
}

void init()
{
        add_action("do_insert", "insert");
}

int do_insert(string arg)
{
        string dir;
        object medal;
        medal = (present("dragon-medal",this_player()));

   if ( arg=="medal" || arg=="dragon-medal" ){
        if(present("dragon-medal",this_player())){
        message_vision("喀喳一声，$N将手上的龙涎嵌入石像。\n",this_player());
        add("door_open",1);
        check_trigger();
        return 1;
        }
        write("你想将什么崁入石像？\n",this_player());
        return 1;
        }
        return 0;
}

