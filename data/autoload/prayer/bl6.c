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
           set_name(na+"µÄ[32mÁú¹ÇÊ¥µ¶[0m",({"dragon-bone blade","blade"}));
        else
         { set_name("[32mÁú¹ÇÊ¥µ¶[0m",({"dragon-bone blade","blade"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

	Áú¹ÇÊ¥µ¶, ÄËµ±ÊÀÊ®°ËÉñ±øÖ®Ò», µ¶±úÉÏËùÏâµÄÈı¸ö 
	±¦Ê¯¸üÊÇ²ÓÀÃÒ«ÑÛ, Ö»¼ûµ¶ÉÏÒşÒşÍ¸³ö°ÔÍõÖ®Æø, Õæ
	ÊÇÁíÈË°®²»ÊÍÊÖ!!ÄÃÔÚÊÖÉÏ¾ÍÈçÍ¬Ò»´úèÉĞÛÒ»°ã, Íş
	·ç°ËÃæ!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
//       set("wield_msg", "$N´Óµ¶ÇÊ½«$n°Î³öÀ´Ö®ºó£¬»ğ¹âËÄÒç¡£\n");
//      set("unwield_msg", "$NÓÃÒÂ·ş½«$n°üÁËÆğÀ´£¬ÆäºìÉ«µÄºÀ¹â±»²¼°ü¸øÕÚ±ÎÁË¡£\n");
        }
        init_blade(115);
        setup();
}               
int query_autoload() { return 1; }

      