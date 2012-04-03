// Room: /open/soulin/room/big.c

inherit ROOM;

void create()
{
    set("short", "少林大雄宝殿");
	set("long", @LONG
	一个非常宽广的大殿，殿内有一尊十分庞大的如来佛
	像，大概有六、七人高，令人叹为观止。
	寺内除了僧人们低沈的诵经声外，听不到其他的声音
	，仿佛如针般细微的东西落地也能够听见。


LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"s07",
]));
	set("light_up", "1");
set("valid_startroom", 1);
	set("objects", ([ /* sizeof() == 1 */
 "/daemon/class/bonze/master" : 1,
]));
	set("no_magic", "1");

	setup();
call_other("/obj/board/bonze_b","???");
}
