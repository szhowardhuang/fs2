// by onion
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("¾¢ÔÆÑ¥", ({ "cloud boots", "boots" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "Çá±ãÇÒÊæÊÊµÄÑ¥×Ó, Á½ÅÔ¸÷Ğå×ÅÒ»¶äÔÆ²Ê¡£\n");
	  set("unit", "Ë«");
	  set("value", 2000);
	  set("material", "linen");
          set("armor_prop/armor", 4);
	}
	setup();
}

