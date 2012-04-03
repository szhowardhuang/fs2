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
           set_name(na+"[1;37m¡õ[1;31m¹öÌÃµ¶[0m",({"blade"}));
        else
         { set_name("[1;31m¹öÌÃµ¶[0m",({"blade"})); }
        seteuid(getuid());
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        Ò»°Ñ¾«ÖÆµÄ´óµ¶, Öıµ¶Ê¦¸µÒÔÆä¾«Õ¿µÄÊÖÒÕ½«µ¶ÈĞ´ò±¡,
        ½åÒÔÌá¸ß´Ëµ¶µÄÕ¶ÇĞÄÜÁ¦!!ÊÇÒ»°Ñ²»¿É¶àµÃµÄºÃµ¶!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
        set("wield_msg", "$N¡¸à§¡±µØÒ»Éù³é³öÒ»°Ñ$nÎÕÔÚÊÖÖĞ¡£\n");
        }
        init_blade(65);
        setup();
}
int query_autoload() { return 1; }



