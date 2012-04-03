//Ñ×ÁúÎäÊ¿ make by poloer


inherit NPC;


void create()
{
        set_name("Ñ×ÁúÎäÊ¿",({"fire-dragon guard","guard"}));
        set("gender","ÄÐÐÔ");
        set("age",25);
set("class","fighter");
        set("str",25);
set("long","Ñ×Áú¹ÈµÄÃÅ¿ÚÊØÎÀ¡£\n");

set("max_kee",1500);
set("kee",1500);
set("combat_exp",1100000);
set("force",1500);
set("max_force",1500);
set("force_factor",10);
set_skill("parry",100);
set_skill("dodge",100);
set_skill("hell-evil", 100);
set_skill("nine-steps", 90);
        set_skill("sixforce",40);
set_skill("unarmed",90);
        map_skill("dodge","nine-steps");
        map_skill("move","nine-steps");
map_skill("unarmed","hell-evil");
        setup();

}
int accept_fight(object who)
{
return notify_fail("Ñ×ÁúÎäÊ¿ËµµÀ : ¶Ô²»Æð , ÎÒÃ»¿ÕÅãÄãÄ¥¹½¡£\n");
}

void heart_beat()
{
        if( random(5) < 2 ){
        if(!is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
            if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
                           }
        }
        :: heart_beat();
}       
