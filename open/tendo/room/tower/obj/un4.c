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
           set_name(na+"[1;37m¡õ[1;33m»Æ½ğÖ¸»·[0m",({"ring"}));
        else
         { set_name("[1;33m»Æ½ğÖ¸»·[0m",({"ring"})); }
        seteuid(getuid());
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        ÉÏ¹ÅÉñÃØ±øÆ÷Ö®Ò»µÄ¡«¡«»Æ½ğÖ¸»·¡«¡«!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "gold");
        set("wield_msg", "$N´÷ÉÏ$n£¬ö®Ê±¼äÄã¾õµÃÁ¦Á¿ÌáÉıÁËÊı±¶¡£\n");
        }
        init_unarmed(65);
        setup();
}
int query_autoload() { return 1; }

