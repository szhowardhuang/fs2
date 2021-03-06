#include <weapon.h>
inherit SWORD;
object ob=this_object();
void create()
{
	set_name("神剑‘血河’",({"blood-river sword","sword"}));
	set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","把");
	  set("long","\n‘血河’，剑身凹凸不平，剑锋其钝无比，剑脊弯曲，剑尖歪斜，如果说有出色之处，便是这把剑隐隐透出红光。\n");
          set("value", 10);
          set("material","blacksteel");
        }
	init_sword(1);      
        setup();
}
void init()
{
	add_action("do_blood","blood");
	set_heart_beat(1);
}
void heart_beat()
{
        int i,exp;
        object me=environment(this_object());
        object *enemy;
        if( me->is_fighting() && ob->query("equipped")=="wielded" && ob->query("blooded") )
	{
	  enemy=me->query_enemy();
          i=random(sizeof(enemy));
	  exp=me->query("combat_exp")-enemy[i]->query("combat_exp");
	  if(exp<=0)	exp=5000;
	  else		exp=5000+exp/10;
	  if( random(exp) > random(20000) && random(4)==0 && me->query("kar")>random(30) )
	  {
            message_vision("\n[31m$N手中 [0;5m"+ob->query("name")+" [31m突然化成满室耀眼红光笼罩住$n。[0m\n\n",me,enemy[i]);
            enemy[i]->add("kee",-100);
            COMBAT_D->report_status(enemy[i]);
	  }
	}
}
int do_blood(string str)
{
	object me=this_player();
	string name=ob->query("name");
	if( str != ob->query("id") )
	  return notify_fail("请键入武器全名。\n");
	if( ob->query("blooded") )
	  return notify_fail("这把武器已得到你的牺牲。\n");
	if( ob->query("equipped") == "wielded" )
	  return notify_fail("请先将武器卸下。\n");
	message_vision("[31m$N缓缓的用"+name+"往手腕处一划, 鲜血如泉涌般淋遍整把"+
	name+"。\n不一会儿, 鲜血已被"+name+"吸干殆尽, 而"+name+"也旦然的发出"+
	"一阵耀眼的[1;5;33m光芒[0;31m。[0m\n",me);
	set_name("[1m神剑[1;31m‘血河’[0m",({"blood-river sword","sword"}));
	set("weapon_prop/damage",99);
	set("value", 100000);
	set("wield_msg","\n$N缓缓的拔出$n，剑作龙吟，清脆悦耳。一种乍看令人心动，细看足以让人心血贲动的红光，自剑身透了出来。\n\n");
	set("unwield_msg","\n$N将$n收入厚套古鞘之内，霎那间有如太阳西下般，满地红光但然消失。\n只见剑鞘却隐然透漾着血红，一如人体里的血脉一般流动。\n\n");
	set("blooded",1);
	setup();
	call_out("wake_up",4);
	me->unconcious();
	return 1;
}
void wake_up()
{
	object who=this_player();
	who->remove_call_out("revive");
	who->revive();
}