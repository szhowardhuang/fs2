// board.c
inherit BULLETIN_BOARD;
 
void create()
{
    set_name("拉姆□涂鸦版版", ({ "board" }) );
    set("location", "/u/l/lum/room2");
    set("board_id", "board");
    set("long", "有事找我请写下来，我会看喔!! =^.^=\n" );
    setup();
    set("capacity", 20);
    set("master",({ "lum" }) );
}
