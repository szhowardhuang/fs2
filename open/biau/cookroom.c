// Room: /u/o/onion/room/cookroom.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里到处摆着许多炊具,大火在火炉底下燃燃的发出炽热的火光,使的空气闷热不堪.
厨子忙碌的走来走去,忙的满头大汗.厨房的正中央放了一张桌子(table),上面摆着热腾
腾的菜,似乎是已经做好的,香味便是从这儿传出的.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
         "west" : __DIR__"room4",
	]));
        set("item_desc", ([ /* sizeof() == 1 */
       "table" : "一张坚硬的木桌,上头放满了各式各样的菜,真想偷吃一口...:P\n"
        ]));
                            	
        
	setup();
	
}
