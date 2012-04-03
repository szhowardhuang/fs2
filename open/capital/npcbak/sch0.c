#include </open/open.h>

inherit NPC;
void create()
{
        set_name("¿Ó–„≤≈", ({ "scholar lee","lee","scholar" }) );
	set("race", "»À¿‡");
	set("class","scholar");
	set("age", 33);
	set("long","À˚ «“ªŒª”∆”Œ”⁄Œ‰¡÷¿Ôµƒ È…˙, ø¥À˚–¶»›¬˙√Êµƒ—˘◊”, "+
	"¥Û∏≈»’◊”ªππ˝µƒ≤ª¥Ì∞…°£\n");

        set("chat_chance",10);
        set("chat_msg", ({
"¿Ó–„≤≈“˜µ¿:        °∏—Ó¡¯«‡«‡Ω≠ÀÆ∆Ω£¨Œ≈¿…Ω≠…œ≥™∏Ë…˘°£\n                    ∂´±ﬂ»’≥ˆ£¨Œ˜±ﬂ”Í£¨µ¿ «Œﬁ«Á£¨ªπ”÷«Á£ø°±\n",
"¿Ó–„≤≈“˜µ¿:        °∏ÕÚ¿Ô«ÂΩ≠ÕÚ¿ÔÃÏ£¨“ª¥Â…£Ëœ“ª¥Â—Ã°£\n                    ”ÊŒÃ◊Ì◊≈Œﬁ»ÀªΩ£¨π˝ŒÁ–—¿¥—©¬˙¥¨°£°±\n",
"¿Ó–„≤≈“˜µ¿:	  °∏«ÿ¬•º∏“π„´–ƒ∆⁄£¨≤ª¡œœ…¿…”–±¿Î°£\n                    ÀØæıƒ™—‘‘∆»•¥¶£¨≤–µ∆“ª’µ“∞∂∑…°£°±\n",
	}));                                            	         

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        "¿Ó–„≤≈µ¿£∫≥ˆÕ‚Ω≠∫˛∫Œ±ÿ»Á¥À∂Ø∆¯ƒÿ?!\n",
	 }) );
		
	set_skill("dodge",40);
	set_skill("parry",20);
	set_skill("stabber",40);
	set("combat_exp",4000);
	setup();
        add_money("coin",500);
        carry_object(CAPITAL_OBJ"fan0")->wield();
        carry_object(CAPITAL_OBJ"head0")->wear();
        carry_object(CAPITAL_OBJ"stabber_book");
}

void defeated_enemy(object ob)
{
	say("[36m¿Ó–„≤≈Œ¢Œ¢“æ¡À“ªπ™µ¿ : ≥–»√≥–»√°£[0m\n");
        remove_killer(ob);
}        
