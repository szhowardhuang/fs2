// 网聚奖品by cgy(22/10/00)
#include <ansi.h>
#include <armor.h>
inherit WRISTS;
object me=this_player();
void create()
{
     set_name(HIC"漂漂玟玟祝福玉镯"NOR , ({"Swy_bracelet","bracelet"}) );
     set_weight(2000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "只");
            set("value", 0);
            set("material", "steel");
            set("long","这是一只漂漂玟玟打造的玉镯，散发出七色光芒。\n");
        set("no_auc",1);
        set("no_give",1);
        set("no_sell",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
            set("wear_msg", "$N套上$n，受到漂漂玟玟的祝福，胆识大增。\n");
			set("remove_msg", "$N脱下了$n，好像看到不可思议的怪事。\n");
     }
            setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 5);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",5);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",5);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",5);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",5);
            this_object()->set("armor_prop/dodge",4);
            this_object()->set("armor_prop/force",4);
            this_object()->set("armor_prop/parry",4);
            this_object()->set("armor_prop/armor",9);
}
