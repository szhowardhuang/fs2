inherit ITEM;

void create()
{
	set_name("驱觢木",({"chu-wood","wood"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",100);
		set("unit","根");
		set("long","邪灵界用来驱除鼓蜂的木头，木头本身会散发出一种令鼓蜂讨厌的气味。\n");
	}
	setup();
}