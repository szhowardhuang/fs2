#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        seteuid(getuid());
        set_name("[31mºìÔ½£[0m",({"red-sword","sword"}));
        set_weight(35000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

	¿ªÑôÃÅÖ÷ÇØÒäÊ«µÄÅå½££¬Ò»°ÑÒÔºìÌú´òÖÆµÄ¶Ì½££¬½£µÄÁ½²à¼ÓÉÏ
	Ï¸Ï¸µÄ¾â³İ£¬½åÒÔÌá¸ßÉ±ÉËÁ¦£®Í¬Ê±Õâ°Ñ½£Ò²ÊÇÓñÅ®ÅÉÕÆÃÅÈËµÄ
	Åå½£, ÓëÌìÅ®É¢»¨½£·¨ÅäºÏÊ¹ÓÃºó, ÍşÁ¦±¶Ôö!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);

        set("material", "iron");
        set("wield_msg", "$N´Ó½£ÇÊÒ»°Î³ö$n£¬[31mºì¹âËÄÉä[0m¡£\n");
        set("unwield_msg", "$NÓÃÒÂ·ş½«$n°üÁËÆğÀ´£¬ÆäºìÉ«µÄºÀ¹â±»²¼°ü¸øÕÚ±ÎÁË¡£\n");
        }
        init_sword(100);
        setup();
}                            
