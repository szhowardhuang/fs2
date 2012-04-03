#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"[1;37m°ı[1;37m∞‘µ∂[0m",({"blade"}));
        else
         { set_name("[1;37m∞‘µ∂[0m",({"blade"})); }
        seteuid(getuid());
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "∞—");
        set("long",@LONG

        ∞‘µ∂!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "gem");
        set("wield_msg", "$N°∏‡ß°±µÿ“ª…˘≥È≥ˆ“ª∞—$nŒ’‘⁄ ÷÷–°£\n");
        }
        init_blade(85);
        setup();
}
int query_autoload() { return 1; }



