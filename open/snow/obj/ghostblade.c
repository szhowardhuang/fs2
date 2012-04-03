// blade.c
#include <weapon.h>
inherit BLADE;

void create()
{
set_name("[1;34m¹íÓ°²Ğ·çµ¶[0m",({"ghost blade","blade"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
     set ("unit","±ú");
          set("value", 10000);
		set("material", "iron");
set("long","ÕâÊÇÒ»°ÑÉñ±øÀûÆ÷¡®¹íÓ°²Ğ·çµ¶¡¯¡£\n");
          set("wield_msg", "$N×°±¸$n¡£\n");
		set("unequip_msg", "$N½«ÊÖÖĞµÄ$n²åÈëÑü¼äµÄµ¶ÇÊ¡£\n");
	}
          set("armor_prop/blade",10);
          init_blade(80);
	setup();
}
