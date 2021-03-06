// poison book by ACKY

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name( HIM"药王神篇"NOR, ({ "antidotal book", "book" }) );
	set( "long", HIM"里面记载着各种解毒的秘方(use box)。"NOR );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set( "weight", 100 );
		set( "unit", "本" );
	}
	setup();
}

void init()
{
	if( !present( this_object(), this_player() ) )
		return;
	add_action( "do_use", "use" );
}

int do_use( string arg )
{
	object	me, ob, sex;
	string	str;
	mapping	en;

	if( !arg || sscanf( arg, "%s", str ) != 1 )
		return 0;
	if( str != "book" )
		return 0;

	me = this_player();
	ob = this_object();
	en = me->query_skill_map();
	
	me->clear_condition();
	me->clear_condition("mogi");
	me->clear_condition("lyssa");
	me->set( "force", 0 );

	message_vision( "$N赶紧拿出" + ob->name() + "翻阅\。\n", me );
	write( YEL"上头写着:「吾毕身苦思各种解毒之道, 晚年终于找到一种克治所有奇毒之法,\n"NOR );
	write( YEL"           其实也什么特别之处, 只消......”\n"NOR );
	message_vision( HIC"\n$N照著书上的步骤, 赶紧蹲下脱裤子, 运起" +
		( undefinedp(en["force"]) ? "内功心法" : to_chinese(en["force"]) ) + "...\n\n", me );
	message_vision( HIR"四周烟雾弥漫, $N全身不断散发出阵阵恶臭, 汗流浃背。\n\n"NOR, me );
	message_vision( HIM"$N「嗯!”地一声, 终于大出一坨紫黑色的粪便。\n"NOR, me );


	destruct(ob);

	return 1;
}

