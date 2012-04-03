#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"[1;37m¡õ[1;34mÆßĞÇ½£[0m",({"sword"}));
        else
         { set_name("[1;34mÆßĞÇ½£[0m",({"sword"})); }
        seteuid(getuid());
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        ÉÏ¹ÅÉñÃØ±øÆ÷Ö®Ò»µÄ¡«¡«ÆßĞÇ½£¡«¡«!!


LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "silver");
        set("wield_msg", "$N¡¸à§¡±µØÒ»Éù³é³öÒ»°Ñ$nÎÕÔÚÊÖÖĞ¡£\n");
        }
        init_sword(60);
        setup();
}
int query_autoload() { return 1; }



