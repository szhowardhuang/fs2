// 网聚奖品by cgy(22/10/00)
#include <armor.h>
#include <ansi.h>
inherit ARMBANDS;
object me=this_player();
void create()
{
        set_name(HIR"女王拉姆暴力臂环 "NOR,({"Lum_armband","armband"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","个");
        set("value",0);
        set("long","这是一套拉姆皮鞭幻化的臂环，拥有超乎常理的功效。\n");
set("wear_msg","$N将$n往手臂一套，顿时一股强大的力量充斥手臂。\n");
set("remove_msg","$N脱下了$n，仿佛看到拉姆拿着蜡烛和皮鞭打量着$n。\n");
        set("material","steel");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 6);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",6);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",6);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",6);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",6);
        this_object()->set("armor_prop/armor", 10);
        this_object()->set("armor_prop/force", 6);
        this_object()->set("armor_prop/parry", 6);
        this_object()->set("armor_prop/dodge", 6);
}

