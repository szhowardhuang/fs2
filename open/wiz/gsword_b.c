inherit BULLETIN_BOARD;
								
void create()
{
	set_name("œ…Ω£≈…¡Ù—‘∞Ê",({"gsword board", "board"}));
set("location","/open/wiz/gswordroom");
	set("board_id","gsword");
	set("long",	"œ…Ω£≈…¡Ù—‘∞Ê°£\n");
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
							
