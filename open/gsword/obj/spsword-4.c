// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
	set_name("[1;32m¡õ[1;33mH[1;32m¡õ[1;33m¡õ[1;32m¡õ[1;33mC[0m",({"han_thon_sword","sword"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("value",20000);
		set("material", "steel");
                set("wield_msg", "ÄÃ×Å$n,$NÁ³ÉÏ¹îÒìµÄĞ¦ÁËĞ¦\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n²åÈëÑü¼äµÄ½£ÇÊ¡£\n");
	}
	init_sword(110);
	setup();
}
