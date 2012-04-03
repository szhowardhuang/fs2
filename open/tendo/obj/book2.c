//book.c

inherit ITEM;

void create()
{
	set_name("庄子",({"book"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
	"一本老子所著的道德经。\n");
		set("value",800);
		set("material", "paper");
		set("skill", ([
	"name":     "taoism",
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

int valid_learn(object me)
{
	if(me->query("family/family_name")!="天道派")
          return -1;
        return 1;
}
