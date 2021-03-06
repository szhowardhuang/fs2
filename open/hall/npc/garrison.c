#include <ansi.h>

inherit NPC;

void create()
{
        set_name("衙门守卫", ({ "hall garrison", "hall", "garrison" }) );
        set("long",@LONG
这是个正在执行公务的县城官兵，虽然和许多武林人物比起来，官
兵们的武功实在稀松平常，但是他们是有组织、有纪律的战士，谁也不
轻易地招惹他们。
LONG);
        set("attitude", "peaceful");
//      set("vendetta_mark", "authority");
        set("pursuer", 1);

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp",20000);

        set("chat_chance", 10);
        set("chat_msg", ({
                "衙门守卫说: 唉～真无聊...\n",
                "衙门守卫说: 整天呆在这里, 真闷死人了! 好想去吃刷羊肉喔!\n",
                "衙门守卫说: 真羡慕那些可以出去抓凶手的弟兄们...\n",
                "衙门守卫说: 真无聊，上次有个人拿份地图来问我一个叫哭什么坡的。\n"+
                "衙门守卫说: 虽然我跟他标了个记号, 可惜他依然找不到是在哪儿。\n",
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "衙门守卫喝道：还不快放下武器束手就缚？\n",
                "衙门守卫喝道：大胆刁民竟敢拒捕？反了！反了！\n"
        }) );

        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
}
