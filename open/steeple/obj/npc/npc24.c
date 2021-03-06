#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_special_fight();
void create()
{
        set_name("王元霸",({"master ba","ba","master"}));
        set("long","他就是名震江湖的金刀无敌王元霸。\n");
        set("gender","男性");
        set("class","blademan");
        set("nickname","金刀无敌");
        set("combat_exp",9000000);
	    set("title",HIW"～幻影～"NOR);
        set("attitude","heroism");
        set("env/连击","YES");
        set("age", 50);
        set("str", 45);
        set("cor", 30);
        set("cps", 30);
        set("per", 20);
        set("int", 40);
        set("max_gin", 1000);
        set("gin", 1000);
        set("max_kee", 10000);
        set("kee", 10000);
        set("max_sen", 1000);
        set("sen", 1000);
        set("force",100000);
set("functions/gold-dest/level",100);
set("functions/fast-dest/level",100);
        set_skill("literate",40);
        set("max_force",100000);
        set_skill("magic",20);
        set_skill("spells",20);
        set_skill("move",60);
        set_skill("force",90);
        set_skill("dodge",60);
        set_skill("parry",90);
        set_skill("blade",150);
        set_skill("riding",40);
        set_skill("fly-steps",100);
        set_skill("gold-blade",100);
        set_skill("sixforce",100);
        set_skill("cure", 60);
        set_skill("fast-blade", 100);
        map_skill("blade","fast-blade");
        map_skill("parry","gold-blade");
        map_skill("dodge","fly-steps");
        map_skill("move","fly-steps");
        map_skill("force","sixforce");
        set_temp("apply/armor",100);
        set("force_factor",15);
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
        (: do_special_fight :),
    }));
        setup();
        create_family("金刀门",5,"门主");
        carry_object("/daemon/class/blademan/obj/gold-blade")->wield();
        add_money("gold",10);
}


string do_special_fight()
{

        if( query_skill_mapped("blade") == "fast-blade" ) {
            command("perform blade.fast-dest");
            map_skill("blade", "gold-blade");
        }
        else if( query_skill_mapped("blade") == "gold-blade" ) { 
            command("perform blade.gold-dest");
            map_skill("blade", "fast-blade");
        }
        command("perform blade.gold-dest");
        return "\n";
}

void heart_beat()
{
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
        command("perform blade.gold-dest");
        }
        :: heart_beat();
}


int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系统：战斗停止，$N回收中，。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系统：由于你没携带晶片，所以无法记录战绩。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系统：由于你没有正式登记，资料无法传输。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 25)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第二十四层试炼□塔"HIG"’"HIY"通过！！

"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第二十五层试炼□塔"HIG"’"HIW"。
	"NOR,me);
	me->set("quest/start_game",25);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
}
}