// Room: /open/ping/room/graveyard.c

#include <ansi.h>

inherit ROOM;

void create ()
{
	set( "short", HIB"︿"HIG"□GRN"□HIG"□GRN"□HIG"□GRN"^"HIB"︿"NOR );
	set( "long", @LONG

    四周一片漆黑, 隐约可以看见几棵枯萎的白杨树, 狂风吹过树梢, 发出
凄厉的啸声。到处都是倾倒的墓碑, 在崩塌的坟墓上还有惨绿的燐火在半空
中飘荡, 从淡淡的绿光中隐约可以看到从坟墓中露出一角的棺材里面隐隐传
出阵阵地哭嚎声, 让人毛骨悚然, 在这乱葬岗的下头不知藏着什么秘密。这
里妖魔鬼怪混杂, 秩序紊乱, 任谁也不想在这多待一秒, 但在这却站了一位
神秘老者。       

LONG);

	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"road12",
	]));
	set("outdoors", "/open/ping");
	set("objects", ([ /* sizeof() == 1 */
		"/open/ping/npc/death" : 1,
]));
	setup();
	replace_program(ROOM);
}

                               