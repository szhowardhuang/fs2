#include <weapon.h>
#include <ansi.h>

inherit STABBER;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"[1;37m¡õ[1;37mÁ÷ĞÇÉÈ[0m",({"fan"}));
        else
         { set_name("[1;37mÁ÷ĞÇÉÈ[0m",({"fan"})); }
        seteuid(getuid());
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        ÉÏ¹ÅÉñÃØ±øÆ÷Ö®Ò»µÄ¡«¡«Á÷ĞÇÉÈ¡«¡«!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "steel");
        set("wield_msg", "$N´Ó»³ÖĞÌÍ³öÒ»°Ñ$nÄÃÔÚÊÖÖĞ¡£\n");
        }
        init_stabber(55);
        setup();
}
int query_autoload() { return 1; }


