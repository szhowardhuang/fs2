#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"的流星爪",({"star claw","claw"}));
        else
         { set_name("流星爪",({"star claw","claw"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	上古神秘兵器之一的～～流星爪～～!!装备在手上后, 
	连挥出来的拳头都会与流星一般的快速无定!!
	
LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
//      set("wield_msg", "$N从刀鞘将$n拔出来之后，寒光四射。\n");
//      set("unwield_msg", "$N用衣服将$n包了起来，其红色的豪光被布包给遮蔽了。\n");
        }
        init_unarmed(40);
        setup();
}               
int query_autoload() { return 1; }

      
