// guard.c

#include <ansi.h>

inherit NPC;
void create()
{
        set_name("民女", ({ "woman" }) );
        set("gender", "女性" );
        set("age",35);
        set("str", 17);
        set("cor",35);
	set("cps", 25);
	set("int", 15);
	set("long",
                "一位普通的妇女.\n");
        set("combat_exp",100);
	set("attitude", "peaceful");
        set("chat_chance", 30);
        set("chat_msg", ({
             "妇女说: 客栈老板每晚都在洗地板,不知到在洗甚么?\n",
             "妇女说: 贪财小剑童身上似忽有些密秘.\n",
             "妇女说: 辽倒剑士每晚都对着一本书练武\n",
             (: random_move :),
        }) );
        set_skill("dodge", 5);
	setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 15);
}
