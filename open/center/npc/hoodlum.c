// 改写自 bandit.c
// hoodlum.c by powell

#include "/open/open.h"
inherit NPC;

void create()
{
        set_name("流氓", ({ "Hoodlum", "hoodlum" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
            "这家伙突然转过头来瞪了瞪你, 一付要把你吃下去的样子, 还是别惹他的好。\n"
            "他常常在妓院逗留，目的就是专门想敲凯子的竹杠。\n"
        );

        set("combat_exp",390);
        set("score", 1);
        set("attitude", "peaceful");
        set_skill("dodge", 10);
        set("inquiry", ([
            "移花宫"    :       "听说移花宫清一色是女人，而且是个个绝代佳人呢!",
            "妓女"      :       "年轻人，先缴点钱再找妓女吧。",
            "保护费"    :       "算了，今天大爷心情好，放过你一马。",
            "缴点钱"    :       "缴钱? 直接给我就好了嘛。",
            "缴钱"      :       "缴钱? 直接给我就好了嘛。",
            "恶人谷"    :       "这我只听京里的兄弟提过，详情就不得而知了。",
            "老鸨"      :       "她是我大姊头，我在这儿也只是收收保护费罢了。",
            "水仙姑娘"  :       "她最可恶了，看都不看我一眼。",
            "哥儿们"    :       "谁是你的哥儿们啊，少臭美了。",
            "英俊的哥儿们":     "谁谁谁? 你这是在说我吗?",
        ]) );

        setup();
        add_money("silver", 3);
        carry_object(CENTER_OBJ"club1")->wield();
        carry_object(CENTER_OBJ"belt1")->wear();
}
