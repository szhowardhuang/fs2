inherit NPC;
void create()
{
    set_name("邪恶毛毛虫",({"demon bug","bug"}) );
    set("gender", "男性");
    set("age",1);
   set("attitude","aggressive");
    set("long", "魔界跑出来的毛毛虫, 长相丑恶, 让人想要一拳打扁他 \n");
    set("kee",600);
    set("max_kee",600);
    set("combat_exp",800);
    setup();
}
