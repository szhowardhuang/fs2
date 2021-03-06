// trainee.c
// 武馆弟子
inherit NPC;
void create()
{
        set_name("武馆弟子", ({ "trainee" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long", "你看到一位身材高大的汉子，正在辛苦地操练着。\n");
        set("combat_exp",180000);
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("force",50);
        set_skill("haoforce",60);
        set_skill("lungshan",60);
        set_skill("henma-steps",60);
        map_skill("dodge","henma-steps");
        map_skill("unarmed","lungshan");
        map_skill("force","haoforce");
        setup();
        carry_object("/open/wu/obj/claw.c")->wield();
        carry_object(__DIR__"obj/linen")->wear();
}
