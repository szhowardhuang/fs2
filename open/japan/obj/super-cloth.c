// ph_hat.c
#include <armor.h>
#include <ansi.h>
object user;
inherit EQUIP;

void create()
{
	set_name( HIG "雀皇飞云裳" NOR ,({"super cloth","cloth"}));
	set_weight(1000);
        set("armor_type","body");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("value",100000);
                set("material","cloth");
		set("armor_prop/armor",50);
               set("armor_prop/dodge", 10);
                set("armor_prop/move", 10);
                                             
        }
        setup();
}
int init()
{
    add_action("do_wear","wear");
}    
int do_wear(string str)
{
::wear();
 if( query("equipped") )
 {
   user = this_player();
   message_vision(HIG"$N暗运内劲,身上雀皇凌空变形成雀皇飞云裳护体,在$N四周升起淡淡的绿色光罩.\n"NOR,user);
   set_heart_beat(1);
 }
}   
void heart_beat()
{
 if( user->is_fighting() && query("equipped"))
{
 if( random(100) > 80)
   {
     user->receive_curing("kee",30);
     user->receive_heal("kee",30);
     message_vision(HIG+"雀皇飞云裳散出一道光圈护住$N的全身,$N的伤势渐渐复原中.\n"+NOR,user);
     }
       }
   }

