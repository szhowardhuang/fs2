//book.c

inherit ITEM;

void create()
{
	set_name("易经",({"book"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
	"一本以楷书写成的易经，里面记载着关于法术和养生之道的知识。\n");
		set("value",800);
		set("material", "paper");
		set("skill", ([
		"name":		"spells",
											// to learn this skill.
	"sen_cost":   10, // gin cost every time study
			"difficulty":	20,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
	"max_skill": 40,
											// from this object.
		]) );
	}
        setup();
}
