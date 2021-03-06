// human.c
// A normal human is at least 40 kg weight
// 修正 精、气、神的长度改由用经验值来看
// by chan
// 三百万以上设限..
// 加上限....
// 改变增加的级数,使之合理化 
#define BASE_WEIGHT 40000

inherit F_DBASE;
int exp,exp_base,exp_add,exp_value,man_base,man_value,man_add,level,cla;

mapping *combat_action = ({
        ([      "action":               "$N挥拳攻击$n的$l",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N往$n的$l一抓",
                "damage_type":  "抓伤",
        ]),
        ([      "action":               "$N往$n的$l狠狠地踢了一脚",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N提起拳头往$n的$l捶去",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N对准$n的$l用力挥出一拳",
                "damage_type":  "瘀伤",
        ]),
});

void create()
{
        seteuid(getuid());
        set("unit", "位");
        set("gender", "男性");
        set("can_speak", 1);
        set("attitude", "peaceful");
        set("limbs", ({
                "头部", "颈部", "胸口", "后心", "左肩", "右肩", "左臂",
                "右臂", "左手", "右手", "腰间", "小腹", "左腿", "右腿",
                "左脚", "右脚"
        }) );
}

void setup_human(object ob)
{
        mapping my;
        my = ob->query_entire_dbase();
        exp=ob->query("combat_exp");
		cla=ob->query("class");
        level=exp;
        ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
        
        if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;
        if( undefinedp(my["str"]) ) my["str"] = random(21) + 10;
        if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 10;
        if( undefinedp(my["int"]) ) my["int"] = random(21) + 10;
        if( undefinedp(my["spi"]) ) my["spi"] = random(21) + 10;
        if( undefinedp(my["cps"]) ) my["cps"] = random(21) + 10;
        if( undefinedp(my["per"]) ) my["per"] = random(21) + 10;
        if( undefinedp(my["con"]) ) my["con"] = random(21) + 10;
        if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 10;
        switch(ob->query("combat_exp"))
        {
         case 0..1000:
              exp_base=0;
              exp_value=level*10;
              exp_add=25;
              man_base=0;
              man_value=exp_value;
              man_add=50;
         break;
         case 1001..10000:
              exp_base=400;
              exp_value=level-1000;
              exp_add=90;
              man_base=200;
              man_value=level-1000;
              man_add=180;
         break;
         case 10001..100000:
              exp_base=500;
              exp_value=level-10000;
              exp_add=900;
              man_base=250;
              man_value=level-10000;
              man_add=1800;
         break;
         case 100001..1000000:
              exp_base=600;
              exp_value=level-100000;
              exp_add=2000;
              man_base=300;
              man_value=level-100000;
              man_add=2000;
         break;
         default:
              exp_base=1050;
              exp_value=level-1000000;
              exp_add=7000;
              man_base=750;
              man_value=level-1000000;
              man_add=4000;
         break;

        }
//初期时由于新手的血(100)很少,造成易死的情况常常发生,因此我将气的部份小小提高到 220左右//

        if( userp(ob) || undefinedp(my["max_gin"]) ) {
                if( my["age"] <= 14 ) my["max_gin"] = 150; //从 100 -> 150
//              else if( my["age"] <= 20 ) my["max_gin"] = 100 + (my["age"] - 14) * 20;
              else if( my["age"] <= 20 ) my["max_gin"] = 150 + (my["age"] - 14) * 40;
                else if( my["age"] <= 30 ) my["max_gin"] = 390;
                else if( my["age"] <= 60 ) my["max_gin"] = 390 - (my["age"] - 30) * 5;
                else my["max_gin"] = 120;
//              else my["max_gin"] = 70;
                if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 10;
                if(exp >0) my["max_gin"] += (man_base + (man_value/man_add));
				
        }
        if( userp(ob) || undefinedp(my["max_kee"]) ) {
                if( my["age"] <= 14 ) my["max_kee"] = 220; // 从 100 -> 220
//              else if( my["age"] <= 20 ) my["max_kee"] = 100 + (my["age"] - 14) * 20;
                else if( my["age"] <= 20 ) my["max_kee"] = 220 + (my["age"] - 14) * 40;
//              else my["max_kee"] = 220;
                else my["max_kee"] = 460; //从 340 -> 400 
//                if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] / 4;
                if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] * 2 / 3 ;
// 以上是年纪及内力的部份....
                if(exp >0) my["max_kee"] += (exp_base + (exp_value/exp_add));
// 经验值的部份.......
        }
        if( userp(ob) || undefinedp(my["max_sen"]) ) {
                if( my["age"] <= 30 ) my["max_sen"] = 150; //从100 -> 150
                else my["max_sen"] = 150 + (my["age"] - 30) * 5;
//              if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"] / 4;
              if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"] / 10;
              if(exp >0) my["max_sen"] += (man_base + (man_value/man_add));
        }

        ob->set_default_object(__FILE__);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
