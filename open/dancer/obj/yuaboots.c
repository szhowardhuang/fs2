//dancerboots//
#include <ansi.h>
inherit EQUIP;
object me=this_player();
void create()
{
        set_name(MAG "凤舞靴" NOR,({"boots"}) );
        set_weight(2000);
		
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("long","
这是月牙儿专用的舞靴，相传为傅剑寒所赠的凤羽所制，非但外观极其
美丽，相传更有不可思议之效。\n");
                set("unit","双");
                set("value",20000);
				set("no_save",1);
                set("armor_prop/armor",30);
                set("armor_prop/move",10);
                set("material","leather");
				set("gender_only","女性");
				                set("armor_type","boots");
            
               
        }
		setup();
      
	  
}
void init()
{
     add_action("do_wear","wear");
     add_action("do_remove","remove");
}
int do_wear(string str)
{
     if(str=="all" || str=="boots")
{
      ::wear();
	  if( query("equipped") )
     {
if(!me) me=environment();
if(!living(me)) me=this_player();
if(!me) me=previous_object();
if(me)
message_vision(HIM"$N穿上凤舞靴忽然感到身子轻盈了起来，好似要飞一般。\n"NOR,me);
        
     }
	 if(me)
	  if(!me->query_temp("have_wear_boots"))
	  {
	  if(me->query("class")=="dancer")  me->add_temp("apply/unarmed", 5);
      if(me->query("class")=="dancer")  me->add_temp("apply/dodge",10);
	  me->set_temp("have_wear_boots",1);
	  }
	  
}
}

int do_remove(string str)
{
     if(str=="boots"||str=="all") 
	 { if( query("equipped") )
     {
if(!me) me=environment();
if(!living(me)) me=this_player();
if(!me) me=previous_object();
if(me)
message_vision(YEL"$N将凤舞靴脱了下来，感到身体一沉，又恢复原状了。\n"NOR,me);
        
     }
	 if(me->query_temp("have_wear_boots")==1)
	  {
	  if(me->query("class")=="dancer")  me->add_temp("apply/unarmed", -5);
      if(me->query("class")=="dancer")  me->add_temp("apply/dodge",-10);
	  me->delete_temp("have_wear_boots");
	  }
	  
	 }
}



