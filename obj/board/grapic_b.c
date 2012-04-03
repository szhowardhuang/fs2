inherit BULLETIN_BOARD;

void create()
{
     set_name("[1;33mÍ¼ĞÎMUDÌÖÂÛ°å[0m", ({"board"}));
    set("location","/u/w/wade/grapic_room.c");
    set("board_id","grapic_b");
    set("long","Í¼ĞÎMUDÌÖÂÛ°å\n");
	setup();
	set("capacity", 300);
	// ÉèÕâÑù¾ÍÄÜÈÃÄÇĞ©ÈË discard post †ª
    set("master", ({"wade"}));
}
