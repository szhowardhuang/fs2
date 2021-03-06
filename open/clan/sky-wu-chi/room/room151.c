inherit ROOM;
void create() {
	set( "short", "霸气堂" );
	set( "owner", "miffy" );
	set( "light_up", 1 );
	set( "build", 12120 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room142",
		"down"      : "/open/clan/sky-wu-chi/room/room143.c",
		"west"      : "/open/clan/sky-wu-chi/room/room78.c",
		"south"     : "/open/clan/sky-wu-chi/room/room152.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room137",
		"north"     : "/open/clan/sky-wu-chi/room/room144.c",
	]) );
	set( "long", @LONG
你走进了霸气堂里头，看到了一幅红底金字的牌匾写着‘气吞山河’。
坐在正中的则是这个地方的主人‘空瓶子’。你的眼睛就一直看着他，想着
他到底有何能耐能以霸气自居。当你看到他的手的同时你吓到了，因为一边
是结着冰霜一边则是燃烧着火焰。看他的样子似乎是要修练一种不知道怎样
的武功，他的护身气劲居然有七重。且你看他运到第七重的同时，只听见他
大喝一声‘般若气吞七重劲’。没想到他居然把这七重劲同时运出也同时融
合。也眼神也爆露出凶光。
LONG);
	setup();
	replace_program(ROOM);
}
