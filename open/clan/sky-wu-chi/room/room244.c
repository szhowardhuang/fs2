inherit ROOM;
void create() {
	set( "short", "至尊殿" );
	set( "owner", "shih" );
	set( "object", ([
		"amount5"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file10"   : "/daemon/class/blademan/obj/shield",
		"amount2"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mon/obj/ghost-claw",
		"amount1"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
	]) );
	set( "build", 10086 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room282",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
青阳县南有九子山，山高数十丈，上有九峰如莲花，按图征名，
无所依据。太史公南游，略而不书，事不经古老之口，复阙名贤之纪
，虽灵异往复，而赋咏罕闻。李白乃削其旧号，加以九华之目……
──妙有分二气，灵山开九华，层标过迟日，半璧明朝霞，积雪曜阴
壑，飞流韵阳崖，青莹玉树色。飘渺羽人家。拐筑小步踏苍台上遥指
青山云正开，滴水松风听不绝，又教童子抱琴来。
    至尊殿建筑在天台峰，也是九华山风景最佳的地方，一条清冷的
闵溪横贯其中，水流云汞，万山丛叠，石质黝黑，嶙峋奇巧，耸削壁
立，纵横数丈，如人工堆叠而成，妙的是石纹裂处间以青松，精巧如
盆景。
    峰上有摩崖，大书「非人间”三字，这其实有仙境意思，可是在
中原武林中人眼中，现在却是无疑暗示「此乃魔界”。至尊殿的殿已
完成，绝对称得上雄奇，只是兴周围景物格格不入，仿佛就是天外飞
来。西方建筑出现在东方名山，到底是有些怪异，却是想不到人在这
座建筑物之前，除了怪异还有一种压迫的感觉。
LONG);
	setup();
	replace_program(ROOM);
}
