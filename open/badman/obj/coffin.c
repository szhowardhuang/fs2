// coffin.c by powell

#include <ansi.h>
#include </open/open.h>

inherit ITEM;

void create()
{
	set_name(YEL "棺木" NOR,({"coffin"}) );
	set("long", "一口长满青苔的棺木, 似忽已摆\在这有好多年了。\n"+
	            "也许你想移开(move)棺盖\, 瞧一瞧里面有甚么, 不过"+
	            "很有可能有未知的"+HIR+"危险"+NOR+"喔。\n");
	set("unit", "口");
	set_weight(5000000);
	set("value",1);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
	int maxf,killair,check;
	object who;
	who = this_player();
	maxf = who->query("max_force");
	killair = who->query("bellicosity");
	check = who->query_temp("coffin");
	if ( arg == "coffin" ) {
	if ( killair > 100 && check !=1 ) {
	message_vision( "突然, 你感觉到四周有点说不出的诡异....\n"+
			"一个影子由模糊而清晰的出现在$N的面前。\n\n",who);
	tell_object( who,"恶人守护灵邪恶的对着你笑道：\n"+
		         "你真的想要搬动这个棺木吗?\n\n");
	message_vision( "影子对着$N说了句话后, 就再次由清晰而模糊, "+
	                "最后消失不见。\n",who);
	who->set_temp("coffin",1);
	return 1;
	}	         			
			
	message_vision( "$N用力搬开棺盖\, 一股浊黑的污气向着$N的脸上喷去。\n",
			who );
	tell_object( who, "你感到身体十分不适, 全身虚弱。\n");
	if ( maxf > 50 ) {
	who->add("max_force",-50);
	return 1;
	}
	who->set("kee",1);
	who->set("gin",1);
	who->set("sen",1);
	return 1;
	}
	tell_object( who, "你想要搬动甚么???\n" );
	return 1;
}

