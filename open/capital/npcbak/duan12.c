// 段家 门人 made by onion
#include </open/open.h>
inherit NPC;
void create()
{
        set_name("萧临风",({"shiao"}));
	set("long","萧临风是段云的第十二个弟子, 他专程来京城采办一些必需品。\n");
	set("gender","男性");
	set("class","scholar");
        set("combat_exp", 4000);
        set("attitude","heroism");
	set("age",18);
	set("force",100);
	set("max_force",100);
	set_skill("force",20);
        set_skill("unarmed",30);
	set_skill("sunforce",20);
        set_skill("linpo-steps",20);
        set_skill("six-fingers",20);
        map_skill("force","sunforce");
	map_skill("dodge","linpo-steps");
	map_skill("move","linpo-steps");
        map_skill("unarmed","six-fingers");
        set("force_factor", 3);
	setup();
        carry_object(CAPITAL_OBJ"cloth0")->wear();
        carry_object(CAPITAL_OBJ"wrists0")->wear();
	add_money("coin",100);
	create_family("段家",11,"弟子");
}

