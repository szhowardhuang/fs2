#include <ansi.h>

inherit NPC;
void create()
{
        set_name("老人", ({ "man" }) );
        set("gender", "男性" );
        set("age",65);
        set("str", 17);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "生长在风云镇的一位普通的老人。\n");
        set("combat_exp",2000);
        set("attitude", "peaceful");

        set("chat_chance", 15);
	set("chat_msg",({
	(: random_move :),
        }));

        set_skill("dodge", 20);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 35);
                
}
