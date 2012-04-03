// neverend_b.c
inherit BULLETIN_BOARD;

void create()
{
	set_name("[1;36m×ÔÓÉ[1;32mËæ·ç[0m", ({"dream board","dream","board"}));
	set("location","/u/n/neverend/workroom");
	set("board_id","neverend_b");
	set("long","[1;33m×ÔÓÉµÄĞÄ  ÈÎÓÉÆ®µ´ ¡«\n\t[1;36m×ÔÔÚµÄĞÄ  ÈÎÓÉÁ÷×ª ¡«\n\t\t[1;33mÓ­×Å·ç  ×ÔÓÉ×ÔÔÚ ¡«\n\t\t\t[1;36mËæ×ÅÂÌ  Æ®µ´Á÷×ª ¡« \n[0m\n");
	setup();
	set("capacity", 500);
	set("master",({"neverend"}));
}
