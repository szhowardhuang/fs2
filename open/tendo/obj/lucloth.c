// cloth.c
// by airke
#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name( MAG"紫绶仙衣" NOR ,({"silk cloth","cloth"}));
	set("long","以紫色丝绸制成，上面还绣了幅老君太极图\n");
	set_weight(1500);
        set("armor_type","cloth");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("value",60000);
                set("material","cloth");
		set("armor_prop/armor",30);
set("no_get",1);
set("no_give",1);
                set("armor_prop/spell", 10);
		set("wear_msg","$N装备上$n，四周极光笼罩，$N只觉得体力充沛，说不出的受用。\n"NOR);
                set("remove_msg",HIW"$N脱下$n"HIW"，身旁的光芒慢慢地黯淡下来。\n"NOR);
	}
        setup();
}



int wear(){

  int val=this_player()->query("kar")*10;
  object me = this_player();
  // 这if 很重要.....否则wear all 会出现没穿这cloth却加max_kee的情形
  if( !me->query_temp("armor/cloth") ) {
  	me->add("max_kee",val);
  	me->set_temp("silk_cloth",val);
//	me->add_temp("apply/name",({me->name()+HIW"(仙绶之衣)"NOR}));
  }
  return ::wear();
}



int unequip(){

  object me=this_player();
int valu = me->query_temp("silk_cloth");

me->add("max_kee",-valu);
me->add("eff_kee",-valu);
  me->delete_temp("silk_cloth");
// me->delete_temp("apply/name");
  return ::unequip();
}





