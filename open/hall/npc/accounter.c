inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
set_name("神算子", ({ "accounter"}));
        set("title", "衙门师爷");
        set("gender", "男性" );
        set("nickname",HIY"九面玲珑"NOR);
        set("age", 46);
        set("str", 50);
        set("cor", 50);
        set("cps", 50);
        set("int", 50);
        set("spi", 50);
        set("kar", 50);
        set("per", 50);
        set("con", 50);

        set("max_atman", 5000);
        set("max_force", 5000);
        set("max_mana", 5000);
        set("atman", 5000);
        set("force", 5000);
        set("mana", 5000);
        set("force_factor", 5);

        set("long",
        "人称黑脸包公的就是他, 据说他断案如神, 公私分明。所以这里的百姓\n"
        "都很尊敬他。也因为他的丰功伟业, 皇上特赐其一柄尚方宝剑。\n");


	set("combat_exp", 1658290);
        set("score", 130000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        "嘿嘿....凭你这两下子!!只有见阎王的份!!\n",
        "不知天高地厚的小子!!受死吧!!\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("literate", 90);

        set("inquiry", ([
                "机器人" : "哼!! 谁被我抓到是机器人的话, 立斩!!",
                "accuse" : "想缉捕机器人的话, 请先到门口击鼓申冤(accuse)。",
        ]) );

        setup();
     carry_object(__DIR__"obj/o_cloth")->wear();
}
