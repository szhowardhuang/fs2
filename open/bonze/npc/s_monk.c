inherit NPC;
 
void create()
{
        set_name("少林小僧",({"soulin monk","monk"}));
        set("long","一个努力练功的小和尚，看来肌肉颇为健壮 .\n");
        set("gender","男性");
        set("combat_exp",10000);
        set("attitude","peaceful");
        set("age",22);
        set("class","soldier");
        set_skill("unarmed",45);
        set_skill("dodge",30);
        set_skill("parry",40);
        set("chat_chance",10);
        set("chat_msg",({
        }));
        setup();
        add_money("silver",1);
}
