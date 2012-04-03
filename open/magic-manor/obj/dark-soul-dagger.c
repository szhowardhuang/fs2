#include <weapon.h>
#include <ansi.h>

inherit DAGGER;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
     set_name(RED"阎匕影螫魂"NOR,({"dark-soul-dagger","dagger"}) );
     set_weight(10000);
     if( clonep() ) 
            set_default_object(__FILE__);
     else {
            set("long","柔媚生所使用的武器，为一神秘铸将精心铸造的「八色灵器”之一，匕身\n散出阵阵白雾，煞是好看。\n");
            set("unit", "把");             
            set("value",20000);
            set("sharp",9);
 			set("material","blacksteel");
			set("e-weapon",1);
			set("no_give",1);
 			set("no_steal",1);
			}
	init_dagger(100);
  	set("wield_msg",RED"$N"RED"拿出$n"RED"，$n"RED"周身泛起一阵白色的光雾!!\n"NOR);
        set("unwield_msg","$N收藏好$n，$n周身的光雾随即消散。\n"NOR);


          setup();
}                   


void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wield","wield");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{
	int uexp;
//	::wield();
	if( !query("equipped") )
	{
	user = this_player();
	uexp = user->query("combat_exp");
	  if( uexp < 3000000 )
	  {
	  message_vision("$N的经验并不足以完全支配这样的神兵利器!!\n"NOR,user);
	  set_heart_beat(0);
	  }else{
//	  message_vision(RED"$N"RED"拿出$n"RED"，$n"RED"周身泛起一阵白色的光雾!!\n"NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="dark-soul-dagger" || str=="dagger" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N收藏好$n，$n周身的光雾随即消散。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="dark-soul-dagger" || str=="dagger" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$N收藏好$n，$n周身的光雾随即消散。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="dark-soul-dagger" || str=="dagger" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N收藏好$n，$n周身的光雾随即消散。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}
void heart_beat()
{
	object *enemy;
	int i;

	if( !objectp(user) )
	{
	set_heart_beat(0);
	return;
	}

	if( user->query_skill("dagger") )
	{
	be = user->query_skill("dagger",1);
	}else{
	be = random(120);
	}

	k = user->query("int",1);
	sp = user->query("spi",1);
	co = user->query("cor",1);
	st = user->query("str",1);
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
	if( user->query("class") == "killer" )
	{
	qq = qq*1.2;
	be = be*0.8;
	}

	if( user->is_fighting() && query("equipped") )
	{
	  if( be > random(500) )
	  {
	  enemy=user->query_enemy();
	  if(!enemy) return ;
	  i=random(sizeof(enemy));
	  if( environment(user) == environment(enemy[i]) )
	  if( random(300) > random(enemy[i]->query_skill("dodge",1)) )
	  {
	  message_vision(HIB"只见"NOR"$n"HIB"的匕刃锋缘冲出一道白影直冲$N"HIB"致命要穴!!\n"NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU"$N"BLU"见状，从容得体的避开这道白影!!\n"NOR,enemy[i],ob);
	  }
	}
	return;
}

