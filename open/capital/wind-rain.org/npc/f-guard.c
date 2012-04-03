#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("山寨守卫", ({ "guard" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long", @LONG
山寨守卫在这里负责进出人员的检查.
想进入山寨?先问问他吧!
LONG);
	set("attitude","heroism");
        set("combat_exp",100000);
         set_skill("dodge",60);
	set_skill("blade",60);
	set_skill("parry",50);
	set_skill("unarmed",60);
	set("chat_chance",10);
	set("chat_msg",({
	}));
	set("greeting_msg", ({
            "山寨守卫大喝 : 站住!! 你是什么人? 在这里鬼鬼祟祟的!!\n",
	    	}) );
	setup();
        carry_object("/open/ping/obj/guard_blade")->wield();
        add_money("gold",1);
	
}
