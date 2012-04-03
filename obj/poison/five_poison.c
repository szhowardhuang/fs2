// dust.c

inherit COMBINED_ITEM;

void create()
{
	set_name("Îå¶¾",({"five poison","five","poison"}));
	set("unit", "°ü");
	set("base_unit", "·Ý");
	set("base_weight", 1);
	set("poison_type","five_poison");
    set("can_throw",1);  
     set("poison_power", 3);
        set("poison" , 50);
	set_amount(1);
	setup();
}
