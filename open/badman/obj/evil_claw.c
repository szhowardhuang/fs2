#include <weapon.h>
#include <ansi.h>
// QC By Swy 98/6/3
inherit UNARMED;

void create()
{
  seteuid(getuid());
  set_name(MAG"魔星爪"NOR,({"evil claws","evil","claws"}));
  set_weight(4500);
  if( clonep() )
                set_default_object(__FILE__);
        else {
  set("unit", "副");
  set("long","这是一把传说中接受魔星--天狼--之诅咒的爪子 ,.据说其威力足以开天辟地 !\n");
  set("value",12000);
  set("material","ironsteel");
  set("ski_type","unarmed");
  set("wield_msg",HIM"$N将魔星爪套在手中 ,你感到有股邪气正从爪中传到$N身上 !\n"NOR);
  set("unwield_msg",HIC"$N将魔星爪拆了下来 ,身上的邪气也已不复见 .\n"NOR);
  }
  init_unarmed(50);
  setup();
}
