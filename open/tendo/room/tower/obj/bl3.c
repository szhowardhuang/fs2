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
           set_name(na+"[1;37m¡õ[1;33m¿ñµ¶[0m",({"blade"}));
        else
         { set_name("[1;33m¿ñµ¶[0m",({"blade"})); }
        seteuid(getuid());
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        Ò»°ÑÌúÖÆµÄ´óµ¶, Öıµ¶Ê¦¸µÔÚÖıÔìµÄ¹ı³ÌÖĞ¼ÓÈëÁË°×Òø
        Ìá¸ßÁË´Ëµ¶µÄÓ²¶È, ÃÜ¶ÈÓëÇ¿¶È!!

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
        init_blade(75);
}
int query_autoload() { return 1; }



