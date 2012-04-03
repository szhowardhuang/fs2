#include <ansi.h>

inherit NPC;

void create()
{
        set_name("山贼头头", ({ "bandit king", "bandit", "king"}) );
        set("long",
             "[C山贼的头头,在下山抢劫行动中失败了,回山寨的时候,无意间走到此处却迷路了,虽然派人去找出路,可是内心的紧张还是完全的表露在脸上。\n");
        set("attitude", "heroism");

	set("combat_exp", 12975);
        set("chat_chance",6);
	set_skill("sword",60);
	set_skill("dodge",60);
	set_skill("parry",60);
	set("random_move",4);
       set("chat_msg",({
          (:this_object(),"random_move":),
}));
        setup();
	carry_object("/obj/longsword")->wield();
}
