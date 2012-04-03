#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"[1;37m¡õ[1;33m½ğÁú±Ş[0m",({"whisk"}));
        else
         { set_name("[1;33m½ğÁú±Ş[0m",({"whisk"})); }
        seteuid(getuid());
        set_weight(2000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        ÉÏ¹ÅÉñÃØ±øÆ÷Ö®Ò»µÄ¡«¡«½ğÁú±Ş¡«¡«!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "gold");
        set("wield_msg", "$N´Ó±³ºó°Î³ö$nÎÕÔÚÊÖÖĞ¡£\n");
        }
        init_whip(65);
        setup();
}
int query_autoload() { return 1; }



