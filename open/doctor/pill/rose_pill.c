inherit COMBINED_ITEM;
void create()
{
        set_name("»ðÃµ¹å½âÒ©", ({"rose_medicine"}) );
        set("long",
"ÕâÊÇÒ»¿ÅÓÃÀ´½â»ðÃµ¹å¶¾µÄÒ©Íè\n");
        set("base_unit", "Á£");
        set("unit", "Á£");
        set("no_sell",1);
        set("value",2500);
        set_amount(1);
        setup();
}
void init()
{
                add_action("eat_pill", "eat");
}
int eat_pill(string arg)
{
	object ob,me=this_player();
        	if( !arg )                     
	 	return 0;
	if( !ob = present(arg,me) )     
		return 0;
        	if( ob != this_object() )       
		return 0;
        	message_vision("$N³ÔÏÂ»ðÃµ¹å½âÒ©.\n", me);
      	me->apply_condition("rose_poison", 0);
        	add_amount(-1);
        	return 1;
}
