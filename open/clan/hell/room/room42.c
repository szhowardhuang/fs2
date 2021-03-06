inherit ROOM;
void create() {
	set( "short", "$HIW$长庚医院$HIR$急诊室$NOR$" );
	set( "object", ([
		"amount4"  : 127,
		"file7"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/doctor/pill/human_pill",
		"amount1"  : 415,
		"amount8"  : 125,
		"file5"    : "/open/scholar/obj/icefan",
		"amount2"  : 1003,
		"amount5"  : 1,
		"file1"    : "/open/doctor/pill/gnd_pill",
		"amount10" : 151,
		"amount6"  : 1,
		"file8"    : "/open/doctor/item/ground_item",
		"file10"   : "/open/doctor/item/sky_item",
		"file2"    : "/open/doctor/pill/sky_pill",
		"amount3"  : 273,
		"file6"    : "/open/scholar/obj/icefan",
		"amount9"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/doctor/item/human_item",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "item_desc", ([
		"registration" : @ITEM

         挂号方式 : 
                       外科 : tell hamster heal代号gin
                       内科 : tell hamster heal代号kee
                      精神科: tell hamster heal代号sen
                      消防科: tell hamster deffire

         PS:请排队看诊, 每次看诊需时两秒

ITEM,
	]) );
	set( "build", 10120 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room80",
		"north"     : "/open/clan/hell/room/hall",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
在魑魅魍魉横行, 妖魔鬼怪充斥的阴曹地府内, 还是和阳间一样需要医生的,
因为阴间和人间的区别, 仅在于地上地下, 阴阳日夜之差别而已, 众鬼怪喽啰还是
会有七情六欲, 有生老病死, 因此水月立志要当个在阴间行医济世的医生, 还特别
针对地府众弟兄怕光怕热的习性, 研究出了一套独特的防火医术, 如果你怕光怕热,
或者身体违和的话, 记得向水月医生挂号看病唷~~~

    挂号单(Registration)
LONG);
	setup();
	replace_program(ROOM);
}
