//七星阵
// by airke

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "七星阵"MAG"天机"NOR);
	set("long", @LONG
附近云雾缭绕，一片雾茫茫的景色。完全无法看清楚四周的景物，似乎是有人
故意摆阵于此，防止旁人随意经过。旁边还有一个奇怪的石头(stone)。

LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
	"stone" : "上面刻着:       \n"+
		  "\n误入此阵者，可拍(touch)石而出。\n\n",
	]));
	set("exits", ([ /* sizeof() == 3 */
]));
	
	set("light_up",1);
	setup();
}

void init()
{
  object ob;
  if( interactive( ob= this_player()))
   {
      remove_call_out("greeting");
	call_out("greeting", 0, ob);
   }

	add_action("do_touch","touch");
}

int do_touch()
{
  object who=this_player();
  
  who->move(__DIR__"c0");
  tell_room(this_object(),who->query("name")+"呼的一声消失无踪了。\n");
  return 1;
}

int greeting (object who)
{
  object room=this_object();
  object mob;
  int i;
  int edir=2+random(5);
  int wdir=2+random(5);
  int ndir=2+random(5);
  int sdir=2+random(5);

  if(wdir!=6&&edir!=6&&ndir!=6&&sdir!=6)
    edir=6;

  room->set("exits/west",__DIR__"d"+wdir);
  room->set("exits/east",__DIR__"d"+edir);
  room->set("exits/north",__DIR__"d"+ndir);
  room->set("exits/south",__DIR__"d"+sdir);

  if(who->query("bellicosity") > 500+random(100)) {
    message_vision("	阵中云雾感到邪气逼近，瞬间汇聚成形...\n",who);
    message_vision(HIR"\n\n	一声狂吼，数条狂暴的云龙奔腾而出，向$N冲来！！！\n"NOR,who);
    seteuid(getuid());
    i=random(3)+1;
    while(i--) {
      mob=new(__DIR__"npc/cl_dragon");
      mob->move(room);
      mob->callset(who);
      mob->kill_ob(who);
    }
  }

  return 1;

}
