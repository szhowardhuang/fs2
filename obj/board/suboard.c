// common_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("蜀中城公告", ({ "board" }));
        set("location","/open/gsword/room/suking");
        set("board_id","suboard");
        set("long","任何对蜀中城的建意与公告,都可以在此留言.\n");
	setup();
	set("capacity", 30);
}
