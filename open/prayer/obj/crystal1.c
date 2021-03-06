//浑天水晶(1~5层基本心法)
#include <command.h>

inherit ITEM;

void create()
{
        set_name("白水晶", ({ "white-crystal","crystal" }));
        set("title", "浑天心法之");
        set_weight(400);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "根");
          set("long","这是一根会发光的水晶, 里面刻有[36m浑天宝鉴基础心法[0m的练功口诀。\n");
          set("value", 500);
          set("material", "gem");
          set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("no_give", 1);
          set("skill", ([
          "name" : "superforce",    // name of the skill
          "exp_required" :  5000,  // to learn this skill.
          "sen_cost" : 25,              // gin cost every time study this
          "difficulty" : 10,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill":  50
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="圣火教")
          return -1;
        return 1;
}
