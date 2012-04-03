// sword.c : an example weapon
#include <ansi.h>
#include <weapon.h>

inherit STABBER;

void create()
{
    set_name("[1;37mÄæ÷ëÒø±Ê[0m",({"scale pen","pen"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("value",30000);
		set("material", "steel");
        set("wield_msg", "[1;37m$NÄÃÆğ$n, [1;37mÉíÉÏÉ¢·¢×ÅÒø¹â!![0m\n");
        set("unwield_msg", "$N½«ÊÖÖĞµÄ$n²åÈëÑü¼ä¡£\n");
	}
    init_stabber(100);
	setup();
}
