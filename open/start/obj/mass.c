 
inherit ITEM;
 
void create()
{
        set_name("璐璐翡翠粽", ({ "little mass" , "mass" }) );
        set_weight( 90 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "小小的一颗菜粽, 通体碧绿, 里面包的是芦笋, 莲子, 菱角等爽口的材料, 在炎炎夏日中为您带来一阵清凉。\n");
                set("unit", "粒");
                set("value", 75);
                set("食物", ([
                        "剩" : 5,
                        "供应": 45,
                ]) );
        }
        setup();
}
