//bun.c

#include <../capital.h>

inherit NPC;

void create()
{
	set_name("»ïÊ³¹Ù",({"food officer","officer"}));
	set("gender","ÄÐÐÔ");
	set("officer_type","food");
	set("class","officer");
	set("officer_class","»ïÊ³¹Ù");
	set("combat_exp",270);
	set_skill("unarmed",10);
	set_skill("dodge",10);
	set("officer_power",5);
	set("max_officer_power",5);
	set("age",43);
	setup();
}
