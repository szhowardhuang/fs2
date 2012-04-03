#include </open/open.h>
inherit NPC;
void create()
{
        set_name("段家第十一代弟子",({"disciple"}));
         set("long","这是一名精壮的汉子, 正在和同伴练习六脉神剑的功夫。\n");
        set("gender","男性");
        set("class","scholar");
        set("combat_exp", 10000);
        set("attitude","peaceful");
        set("age",23);
        set("force",200);
        set("max_force",200);
        set("force_factor", 3);
        set_skill("force",20);
        set_skill("unarmed",30);
        set_skill("sunforce",20);
        set_skill("linpo-steps",30);
        set_skill("six-fingers",30);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("unarmed","six-fingers");
        set_temp("apply/dodge",30);
        setup();
        add_money("silver",20);
}
