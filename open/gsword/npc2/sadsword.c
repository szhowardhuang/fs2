#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
seteuid(getuid());
set_name("[1;31mÄ§½£[1;37mÌìéä[0m",({"Sad sword","sword"}));
set_weight(10000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "°Ñ");
set("value",20000);
set("material", "steel");
  set("no_get", 1);
                set("wield_msg", "ÄÃ×Å$n,$NÁ³ÉÏ¹îÒìµÄĞ¦ÁËĞ¦\n");
set("unwield_msg", "$N½«ÊÖÖĞµÄ$n²åÈëÑü¼äµÄ½£ÇÊ¡£\n");  
set("weapon_prop/sword",10);                                                                              }
init_sword(99);
setup();

}
