inherit NPC;

void create()
{
	set_name("ºûµû", ({ "butterfly" }) );
	set("race", "Ò°ÊŞ");
	set("age", 1);
	set("long", "Ò»Ö»ôæôæ·ÉÎèµÄ²Êµû.\n");
	set("str", 15);
	set("cor", 25);
	set("limbs", ({ "Í·²¿", "ÉíÌå", "³á°ò", "´¥½Ç" }) );
        set("verbs", ({ "bite" }) );
	set("combat_exp",118);
	set_temp("apply/armor", 10);
	set("chat_chance",10);
	set("chat_msg", ({
	    (: this_object(),"random_move" :),
	               }) );
	set_skill("dodge",5);
	setup();               
	add_money("coin",10);

}

