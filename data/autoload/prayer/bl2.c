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
           set_name(na+"µÄ[31m»ğÑæµ¶[0m",({"fire blade","blade"}));
        else
         { set_name("[31m»ğÑæµ¶[0m",({"fire blade","blade"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

	Ò»°Ñºì¹âö°ö°µÄ´óµ¶, Öıµ¶Ê¦¸µÒÔÆä¾«Õ¿µÄÊÖÒÕ½«µ¶ÖıÔì
	³É¾ßÓĞ»ğÑæµÄÈÈ¶È, ½åÒÔÌá¸ß´Ëµ¶µÄÉËº¦Á¦!!ÊÇÒ»°Ñ²»¿É
	¶àµÃµÄºÃµ¶!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
        set("wield_msg", "[36m$N´Óµ¶ÇÊ½«$n°Î³öÀ´Ö®ºó£¬[31m»ğ¹âËÄÒç[0m¡£\n");
        set("unwield_msg", "[36m$NÓÃÒÂ·ş½«$n°üÁËÆğÀ´£¬Æä[31mºìÉ«µÄºÀ¹â[36m±»²¼°ü¸øÕÚ±ÎÁË[0m¡£\n");
        }
        init_blade(85);
        setup();
}               
int query_autoload() { return 1; }

      