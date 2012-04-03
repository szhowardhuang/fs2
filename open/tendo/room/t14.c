// Room: /open/tendo/room/t06.c

inherit ROOM;

void create()
{
	set("short", "修行房");
	set("long", @LONG
草席上摆放着许许多多的蒲团，一位天道的老者
坐在正前方讲解天道法术和老庄的思想。不少的天道
弟子和远道前来求仙的人，正坐在这里心无旁贷地听
讲，似乎完全没注意到你的出现。

LONG
	);
	set("objects",([
	"/open/tendo/npc/chin" : 1,
	"/open/tendo/npc/truin" : 1,
	"/open/tendo/npc/gechin" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"t12",
]));
	set("light_up",1);
	setup();
}
