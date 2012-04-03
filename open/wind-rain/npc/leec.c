inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
	set_name("林静诗", ({"lin chin-shin", "lin"}));
	set("long","
    她就是金风细雨楼副楼主，人称江湖第一美人的林静诗。
林静诗的外表，迷倒了多少江湖侠士，他那一双眼眸，比灯还亮
仿佛像一个深湖，浮漾着千古流云的梦。\n");
	set("gender","女性");
	set("combat_exp",1000000);
        set("attitude","heroism");
	set("age",21);
	set("class","swordsman");
	set("title","仙剑派第四代女剑侠");
        set("nickname",HIW"东城飞雪"NOR);
	create_family("仙剑派",4,"弟子");
	set("score",100000);
        set("kee",3000);
        set("max_kee",3000);   
	set("force",13000);
    set("max_force",6000);
	set("force_factor",10);
	set_skill("literate",100);
	set_skill("parry",120);
	set_skill("dodge",90);
        set_skill("sha-steps",1000);
	set_skill("force",50);
	set_skill("sword",80);
	set_skill("move",80);
	set_skill("array",70);
	set_skill("cure",50);
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        map_skill("force","shaforce");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("array","sha-array");
	set("str",30);
        set("cor",30);
	set("per",30);
	set("int",40);
	set("cps",30);
	set("con",30);
	set("spi",35);
	set("kar",30);
	setup();
//carry_object("/open/capital/wind-rain/obj/butterfly-cloth")->wear();
        //carry_object("/open/gsword/obj/may_ring")->wear();
	add_money("gold",5);
}
int accept_fight(object me)
{
  if((int)me->query("combat_exp")<=60000)
 {
    command("say 身体发肤,受之父母,要好好爱惜啊!");
    return 0;
 }
    command("say 点到为止唷...");
    return 1;
}
