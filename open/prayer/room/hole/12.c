///open/prayer/room/hole/12.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	四周墙壁坑坑洞洞，还有一些生锈的兵刃插在上面，显然这里曾经
	有过激烈的打斗．地上全是一沱一沱的的粪便，红红绿绿怪恐怖的
	，天啊!!难道这些怪物有毒??唉哟!!那你岂不是已经中毒了??

LONG	);
 
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/ditail-snake2" : 1,		//双头响尾蛇
]));

	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"5",
  "south" : __DIR__"9",
  "west":__DIR__"10",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}