// doctor_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW"杏林交流版"NOR,({ "board" }) );
        set("board_id", "doctorr_b");
set("location", "/open/doctor/room/2");
        set("long","\t这是一个让医者医术交流的留言版\n");
        setup();
        set("capacity", 100);
}


