inherit BULLETIN_BOARD;

void create()
{
	set_name("面包版", ({ "board" }) );
	set("location", "/u/w/wade/room/talkroom");
	set("board_id", "wade_talk_b");
	set("long",	"天听自我民听，众朋友有话就留，没话快滚\n");
	setup();
	set("capacity", 30);
}
