// by roger 加上 war by ACKY
inherit ROOM;
#include <ansi.h>
void create () {
	set( "short" , HIR"焚天魔殿"NOR);
	set( "long"  , "
    这里就是魔王的所在! 这里非常的宽敞, 所有的布置都呈现火
红色, 甫进门就觉得一股灼热的气息扑面袭来, 当中的宝座上坐着
一个全身散发着火焰的人, 全身盔甲护身, 最奇异的是他那对眼睛
竟然分别射出金光和银光, 透着无比的威严, 令人不禁心生畏惧, 
气势为之大挫!
");

        set("evil", 1);
        set("king-room",1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ 
            "west"  : __DIR__"room63",
            "north"  : __DIR__"room66",
            "south"  : __DIR__"room65",
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/fire-king" : 1,
      ]));

        setup();
}

int valid_leave(object me, string dir)

{
        if(dir=="north"&&present("king",environment(me)))
  {

message_vision(HIY"焚天魔王喝道:「竟敢在我眼前放肆！”\n"NOR,me);

return 0;
}
return 1;
}

void war_start()
{
	shout( HIR"\n\n\n\t魔界众魔因焚天魔王之死开始忿怒\n\n"+
		  "\t众魔们杀气腾腾\n\n"+
		  "\t群魔离开魔界朝人间杀去!\n\n\n\n"NOR );

	new("/open/mogi/dragon/npc/dragon-gold.c") ->move("/open/capital/room/r70");
	new("/open/mogi/castle/npc/seven-dark-4.c")->move("/open/capital/room/r70");
	new("/open/mogi/castle/npc/seven-dark-5.c")->move("/open/capital/room/r70");
	new("/open/mogi/castle/npc/seven-dark-6.c")->move("/open/capital/room/r70");
	new("/open/mogi/castle/npc/black-ghost.c" )->move("/open/gsword/room/su3");
	new("/open/mogi/castle/npc/seven-dark-1.c")->move("/open/gsword/room/su3");
	new("/open/mogi/castle/npc/seven-dark-2.c")->move("/open/gsword/room/su3");
	new("/open/mogi/castle/npc/seven-dark-3.c")->move("/open/gsword/room/su3");
	new("/open/mogi/castle/npc/white-ghost.c" )->move("/open/start/room/s5.c");
	new("/open/mogi/castle/npc/seven-dark-4.c")->move("/open/start/room/s5.c");
	new("/open/mogi/castle/npc/seven-dark-5.c")->move("/open/start/room/s5.c");
	new("/open/mogi/castle/npc/seven-dark-6.c")->move("/open/start/room/s5.c");
	new("/open/mogi/castle/npc/black-ghost.c" )->move("/open/ping/room/road4");
	new("/open/mogi/castle/npc/seven-dark-4.c")->move("/open/ping/room/road4");
	new("/open/mogi/castle/npc/seven-dark-5.c")->move("/open/ping/room/road4");
	new("/open/mogi/castle/npc/seven-dark-6.c")->move("/open/ping/room/road4");
	new("/open/mogi/castle/npc/white-ghost.c" )->move("/open/port/room/r3-1");
	new("/open/mogi/castle/npc/seven-dark-1.c")->move("/open/port/room/r3-1");
	new("/open/mogi/castle/npc/seven-dark-2.c")->move("/open/port/room/r3-1");
	new("/open/mogi/castle/npc/seven-dark-3.c")->move("/open/port/room/r3-1");	
}

