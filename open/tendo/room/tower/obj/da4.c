#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"[1;37m¡õ[1;34m»¢Ö®Ø°[0m",({"dagger"}));
        else
         { set_name("[1;34m»¢Ö®Ø°[0m",({"dagger"})); }
        seteuid(getuid());
        set_weight(1000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        ÉÏ¹ÅÉñÃØ±øÆ÷Ö®Ò»µÄ¡«¡«»¢Ö®Ø°¡«¡«!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "gold");
        set("wield_msg", "$N´Ó»³ÖĞÃş³öÒ»°Ñ$nÎÕÔÚÊÖÖĞ¡£\n");
        }
        init_dagger(65);
        setup();
}
int query_autoload() { return 1; }




