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
set_name(na+"[1;37m¡õµÄÂ«½£[0m",({"sword"}));
        else
{ set_name("[1;37mµÄÂ«½£[0m",({"sword"})); }
        seteuid(getuid());
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        Ò»°Ñ¾«ÖÆµÄ³¤½£, Öı½£Ê¦¸µÒÔÆä¾«Õ¿µÄÊÖÒÕ½«½£ÈĞµÄÁ½²à
        ´ò±¡, ½åÒÔÌá¸ß´Ë½£µÄÕ¶ÇĞÄÜÁ¦!!ÊÇÒ»°Ñ²»¿É¶àµÃµÄºÃ½£!!


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
        init_sword(50);
        setup();
}
int query_autoload() { return 1; }



