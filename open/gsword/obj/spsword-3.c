// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
	set_name("[1;31m¡õ[1;35ml[1;31m¡õ[1;35m¡õ[1;31m¡õ[1;35mC[0m",({"hon_water_sword","sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("value",10000);
		set("material", "steel");
                set("wield_msg", "ÄÃ×Å$n,$NËÆºõ¼¤·¢³öÎŞÏŞµÄÁ¦Á¿.\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n²åÈëÑü¼äµÄ½£ÇÊ¡£\n");
	}
	init_sword(95);
	setup();
}
