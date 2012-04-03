// buffalo.c by oda
// loto.c    by powell

inherit NPC;

void create()
{
        set_name("骆驼", ({ "Camel", "camel" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "这只骆驼正优闲地躺在地上, 咀嚼着饲料。\n");

        set("str",25);
        set("con",20);
        set("max_gin",140);
        set("max_kee",240);
        set("max_sen", 100);

        set("limbs", ({ "身体", "头部", "前脚", "后腿", }) );
        set("verbs",({"hoof","bite"}) );

        set("combat_exp", 250);

        setup();
}
