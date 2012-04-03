inherit NPC;

void create()
{
        set_name("肥遗", ({ "curious snake","snake" }) );
        set("race", "野兽");
        set("age", 630);
   set("long", "
相传：首生盘古，垂死化身，气为风，声为雷，目瞳为电，身成万物，
而肥遗即为其所化之蛇，六足四翼，见则天下大旱。
");
	 set("str", 40);
        set("con", 45);
        set("kee",4500);
        set("max_kee",4500);
        set("verbs", ({ "bite","claw"}));
        set("limbs", ({ "头部", "翅膀","六足"  }) );
	 set("attitude","peaceful");
        set("combat_exp",30000);
	set_temp("apply/attack",60);
	set_temp("apply/dodge",60);
        set("chat_chance",10);
        set("chat_msg", ({
        "肥遗对着你张牙舞爪。\n",
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
	if(ob->query("pass_gblade")<2)
        this_object()->kill_ob(ob);
}
void die()
{
        object ob;
        ob= this_object()->query_temp("last_damage_from");
	if(ob&&userp(ob)&&ob->query("pass_gblade")<2)
	ob->set("pass_gblade",2);
::die();
}
