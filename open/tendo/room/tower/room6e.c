#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short","八卦阵");
          set("long",@LONG
这里就是五行八卦阵的八卦阵了，在此处你看到了满地的武器，
四周漆黑如夜，伸手不见五指，远远望去，一道光线迎面而来，令你
想立刻飞奔过去，只见一阵阵的阴风扑面而来，此时才发觉有许多鬼
影向你这奔来。

LONG);
        set("exits", ([
		"north":__DIR__"room6f",
		"south":__DIR__"room6a",
		"west":__DIR__"room6f",
		"east":__DIR__"room6d",
        ]) );
set("objects", ([ /* sizeof() == 2 */
"/open/tendo/room/tower/npc/genies.c" : 2,
]));
          set("no_transmit",1);    
        setup();
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 6,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR"～鬼影幢幢～你觉得胸中一阵翻滚，忽然一道血箭从你的嘴里喷了出来。\n"NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 6,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}


