#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"µÄ[36m¹ÅÎÄÖ®ÕÈ[0m",({"archaic stick","stick"}));
        else
         { set_name("[36m¹ÅÎÄÖ®ÕÈ[0m",({"archaic stick","stick"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

	ÉÏ¹ÅÉñÃØ±øÆ÷Ö®Ò»µÄ¡«¡«[36m¹ÅÎÄÖ®ÕÈ[0m¡«¡«!! 
	
LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
//      set("wield_msg", "$N´Óµ¶ÇÊ½«$n°Î³öÀ´Ö®ºó£¬º®¹âËÄÉä¡£\n");
//      set("unwield_msg", "$NÓÃÒÂ·ş½«$n°üÁËÆğÀ´£¬ÆäºìÉ«µÄºÀ¹â±»²¼°ü¸øÕÚ±ÎÁË¡£\n");
        }
        init_stick(50);
        setup();
}               

int query_autoload() { return 1; }
      
