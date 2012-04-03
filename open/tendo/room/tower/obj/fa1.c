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
           set_name(na+"[1;37m¡õ[1;32mÇåĞäÉÈ[0m",({"fan"}));
        else
         { set_name("[1;32mÇåĞäÉÈ[0m",({"fan"})); }
        seteuid(getuid());
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        ÉÈĞÎ±øÆ÷Ö®Ò»µÄ[ÇåĞäÉÈ]!!ÒÔÌúÎªÉÈ¹Ç, ¿ÉÒÔ×öÎª´òÑ¨
        ·¢Éä°µÆ÷µÄÎäÆ÷!!ÉÏÍ·ÓĞÉ½Ë®ÑùÍ¼, ¸øÈËÒ»ÖÖÎÄÈËÊéÉú
        µÄÆøÖÊ!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_put",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
        set("wield_msg", "$N´Ó»³ÖĞÌÍ³öÒ»°Ñ$nÄÃÔÚÊÖÖĞ¡£\n");
        }
         init_stabber(50);
        setup();
}

int query_autoload() { return 1; }



