// mob4.c by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;

int kill_him(object);

void create() {
        
        set_name("八指飞魔",({"eight-fingers ghost","ghost"}));
        set("long",
            "\n镇守孤身不过廊的厉害妖魔。\n");

        set("age",3321);
        set("str",35);
        set("cor",30);
        set("race","野兽");
        set("gender","雄性");
        set("attitude","aggressive");
        set("max_gin",2800);
        set("max_kee",10000);
        set("max_sen",3300);
        set("max_force",16000);
        set("force",16000);
        set("force_factor",30);
        set("combat_exp",3200000);
        set_skill("unarmed",120);
        set_skill("dodge",110);
        set_skill("nine-steps",120);
        set_skill("move",30);
        set_skill("parry",100);
        set_skill("mogi-strike1",120);
        map_skill("unarmed", "mogi-strike1");
        map_skill("dodge","nine-steps");
        map_skill("parry","hell-evil");
        map_skill("move","nine-steps");
        set("limbs",({"头部","胸部","背部","腰部","八根手指"}));
        set("verbs",({"bite","claw"}));
        setup();
        carry_object(C_OBJ"/ghost-legging")->wear();
        add_money("gold",15);
 }

void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting()) {
           remove_call_out("kill_him");
           call_out("kill_him",0,obj);
        }
 }

/*   此先暂时不用  int kill_him(object obj) {
//        if(obj->query("race") == "妖怪") return 1;
        if(obj->query("race") == "野兽") return 1;
        if(obj->query("max_force") > 999 ||
           obj->query("combat_exp") > 299999)
           command("kill "+obj->query("id"));
        return 1;
}*/
