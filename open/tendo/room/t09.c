// Room: /open/tendo/room/t09.c

inherit ROOM;

void create()
{
	set("short", "炼丹房");
	set("long", @LONG
终年热呼呼的炼丹房，这里可以让你炼制保命的丹药但你必须先
学会炼丹术及备有适合的材料。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"t10",
]));
        set("objects",([
		"open/tendo/npc/chinshi" : 1,
        ]));
	set("light_up",1);
	setup();
}
void init()
{

add_action("do_made","made");
}

int do_made(string arg)
{
  object ob,pi,me=this_player();
		if(me->query("class")!="taoist")
		return 0;
        if( !arg )                      return 0;
		if(arg !="fruit") {
		write("你要炼啥东东?\n");
		return 0;
		}
        arg=lower_case(arg);
		if( !ob = present(arg,me) ) {
		write("你身上没那东东啦\n");
		return 1;
		}
destruct(ob);

pi = new("/open/tendo/obj/manapill");
pi->add_amount(15);
pi->move(this_player());
write("经过一番努力，终于炼出了丹药。\n");
return 1;
}
