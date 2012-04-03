


// guard.c

#include <ansi.h>

inherit NPC;
void create()
{
        set_name("农夫", ({ "farmer" }) );
        set("gender", "男性" );
        set("age",65);
        set("str", 27);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "一位久居于此的老农夫.\n");
        set("combat_exp",120000);
        set("attitude", "peaceful");
        set("chat_chance", 35);
        set("chat_msg", ({
             "农夫说: 有位姓颜的剑客曾经来过这, ,像是在找人!!\n",
             "农夫说: 岛上那座火山 ,听说住了神龟呀!! 不知道是真是假 .\n",
             "农夫说: 传闻神龟怕雷响 ,所以从来没有出现过!!\n",
             (: "random_move" :),
        }) );
        set_skill("dodge", 120);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("gold", 5);
}


