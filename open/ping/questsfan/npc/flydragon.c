//上官残心 by dhk 2000.5.17
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
set_name("上官残心",({"angryrain flydragon","angryrain","flydragon"}));
set("long","他就是武林第一家上官家族第二代传人 :  上官残心。
同时身为天界九龙族之一。近十余年来，因武林传言近
期异族蠢蠢欲动，故族长遂命他到武林中明查暗访．另
有一武林传言，他并非天生左手残废，听说是被一名武
林名宿所误伤。\n");
        set("gender","男性");
        set("class","swordsman");
        set("nickname",""HIM"怒雨飞龙"NOR"");
            set("family/family_name","仙剑派");
            set("combat_exp",1400000);
            set("attitude","heroism");
            set("dragon-sword",1);
            set("bellicosity", 490);
            set("age",76);
            set("title","上官家族第二代传人");
            set("str", 44);
            set("cor", 42);
            set("cps", 18);
            set("con", 24);
            set("int", 42);
            set("max_gin", 4000);
            set("gin",4000);
            set("max_kee", 5900);
            set("kee",5900);
            set("s_kee",1000);
            set("max_s_kee",1000);
            set("sec_kee","god");
            set("force",4400);
            set("max_force",4400);
            set("functions/sha_kee/level",100);
            set_skill("literate",40);
            set_skill("cure",50);
            set_skill("magic",20);
            set_skill("spells",20);
            set_skill("shasword",100);
            set_skill("shaforce",80);
            set_skill("sha-steps",100);
            set_skill("sha-array",100);
        set_skill("array",100);
        set_skill("move",80);
        set_skill("force",50);
        set_skill("dodge",80);
        set_skill("parry",120);
        set_skill("sword",120);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        set("force_factor",29);
        set("get_sha_sp", 1);
        set("bounds", 4000000);
        set("chat_chance_combat",90);

        set("chat_msg_combat",({
        (: perform_action,"sword.sha_kee" :)
        }));
        setup();
        carry_object("/open/gsword/obj/dragon-sword.c")->wield();
        add_money("gold",10);
        create_family("仙剑派",3,"第子");
}

void init()
{
  set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
                else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}
int accept_fight(object who)
{
        command("say 让你知道我‘雨中斩’的厉害！\n");
        fight_ob(who);
        command("perform sword.sha_kee");
        return 1;
}

int accept_kill(object who)
{
        command("say 让你知道我‘雨中斩’的厉害！\n");
        kill_ob(who);
        command("perform sword.sha_kee");
        carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
        return 1;

}
void die()
{
        object winner = query_temp("last_damage_from");
        object sky;
        sky=new("/u/d/dhk/questsfan/npc/sky.c");
                tell_object(users(),"\n\n"HIY"天皇长吟道："NOR"\n\n      "HIR"‘"NOR"\n\t  "HIC"天敌降世，一夕水火风雷；"NOR"
          "HIC"宇瀚五岳，万年春夏秋冬；"NOR"\n\t  "HIC"魔界入口，步入阴阳逆转；"NOR"\n\t  "HIC"神封五皇，掌管日月循环。"NOR"\n\t                          "HIR" ’"NOR"\n        ");
        tell_object(users(),"\n"HIG"    因"HIG"～"HIW"  飞龙折翼，吾  闭门悔悟"NOR"\n\t"HIY"    叹"HIY"～"HIW"  残废残心，吾  重出江湖"NOR"\n\n"HIM"    无奈～ ～无奈～ ～无奈呀 ! ! !"NOR"\n");
        if(sky)
        sky->move("/u/d/dhk/workroom.c");
        :: die();
}


