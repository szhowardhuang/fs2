// trainee.c
// 武馆教头
inherit NPC;
void create()
{
        set_name("武馆教头", ({ "trainer" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long", "你看到一位年约二十教头正在教导着泷山弟子。\n");
        set("combat_exp",100000);
        set_skill("unarmed",30);
        set_skill("dodge",30);
        set_skill("parry",30);
        set_skill("force",30);
        set_skill("haoforce",30);
        set_skill("lungshan",40);
        set_skill("henma-steps",30);
        map_skill("dodge","henma-steps");
        map_skill("unarmed","lungshan");
        map_skill("force","haoforce");
        setup();
        carry_object("/open/wu/obj/claw.c")->wield();
        carry_object(__DIR__"obj/linen")->wear();
        add_money("gold", 5);
}
