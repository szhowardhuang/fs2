
inherit NPC;
void create()
{
        set_name("九天应龙", ({ "dragon" }) );
        set("race", "野兽");
        set("age", 650);
        set("long", "
九天应龙的两颗巨眼直盯着你瞧，巨大的爪子，似乎随时要挥下来打你
打碎，口中不时喷出一道火焰，照的漆黑的地道一片光亮。
");
        set("str", 65);
        set("con", 55);
	set("kee",8000);
	set("max_kee",8000);
        set("verbs", ({ "bite","claw"}));
        set("limbs", ({ "头部", "利爪","尾巴"  }) );
        set("attitude","peacful");
	set("combat_exp",1000000);
	set_temp("apply/attack",100);
	set_temp("apply/dodge",100);
        set("chat_chance",10);
        set("chat_msg", ({
        "九天应龙从口中喷出一道火焰，差点把你的眉毛都烧掉了。\n",
	"九天应龙的爪子一拍，地动山摇，头上的岩石应声落下好几块来。\n",
        }) );
       setup();
}
void init()
{
        object ob;
        ::init();
        if(interactive(ob=this_player()) && !is_fighting())
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        }
}
void greeting(object ob)
{
if(ob->query("pass_gblade")<7)
        this_object()->kill_ob(ob);
}
void die()
{
        object ob;
        ob= this_object()->query_temp("last_damage_from");
	if(ob&&userp(ob)&&ob->query("pass_gblade")<7)
	ob->set("pass_gblade",7);
::die();
}

