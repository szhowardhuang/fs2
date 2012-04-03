// made by ccat
inherit COMBINED_ITEM;
void create()
{
        set_name("雪莲丹", ({"force pill","pill"}) );
	set("long",
"此物乃蜀中将军自天山绝顶采来之神药,可以恢复大量内力.\n"+
"此要须经药师调配(check item),方得食用(eat pill).\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("no_sell",1);
set("value",7000);
        set("base_weight", 50);
	set_amount(1);
	setup();
}

void init()
{
	if( this_player()==environment() )
	{
		add_action("eat_pill", "eat");
	}	
}

int eat_pill(string arg)
{      

        object ob,me=this_player();
	int max_force,force;
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
	message_vision("$N吃下一粒雪莲丹.\n", me);
        max_force = me->query("max_force");
        force = me->query("force");
        force = force + 500;
        if( force > max_force )
            force = max_force;
	me->set("force",force);
	add_amount(-1);
        return 1;
}

              
                           
