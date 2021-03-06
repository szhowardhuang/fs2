inherit NPC;

void create() 
{
        set_name("飞刺鸟",({"fly-bird","bird"}));
        set("long","
它是穿梭于幻结界的生物之一，一闻到生人气息就蹦出来吃人。
但是如今她身处于琰扬湖内，受到水邪将--水柔缠的感化，暴戾
之气以消失殆尽。\n");
        set("age",1937);
        set("str",30);
        set("cor",30);
        set("race","野兽");
        set("gender","雄性");
        set("max_gin",6000);
        set("max_kee",6000);
        set("max_sen",6000);
        set("max_force",20000);
        set("force",20000);
        set("force_factor",20);
        set("combat_exp",800000);
        set_skill("unarmed",300);
        set_skill("dodge",300);
        set_skill("move",300);
        set_skill("parry",300);
        set_skill("force",250);
        set("limbs",({"头部","尾部","翅膀","爪子"}));
        set("verbs",({"dunt","claw","poke"}));
        set_temp("apply/armor",100);
        set_temp("apply/damage",100);
        setup();
}

void die()
{
object ob,me,obj;
        ob=this_object();
        me=ob->query_temp("last_damage_from");
        me->add_temp("evil/water/killed",1);
::die();
}
