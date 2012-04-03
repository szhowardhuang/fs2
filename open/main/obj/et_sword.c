// Et-sword.c by Casey
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
object user;
int sp;
void create()
{
     set_name(HIB"连鞘古剑"NOR,({"old sword","sword"}) );
     set_weight(5000);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","\n这是一柄连鞘的古剑 ,古朴的剑鞘中闪烁着异样的寒光.\n");
            set("unit", "把");
            set("sharp",10);
            set("value",100000);
            set("no_steal",1);
			set("no_sell",1);
            set("no_put",1);
            set("material","crimsonsteel");
            set("rigidity",200);
        }
        init_sword(110);
        setup();
}
void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}

int do_wield(string str)
{
     int my_spi,my_exp;
     ::wield();
     if( query("equipped") )
     {
        user = this_player();
       my_spi = user->query("spi",1);
        my_exp = user->query("combat_exp");
             // 表示神兵利器 ,所以提高条件...Daniel
         if( my_exp * my_spi < 10000000 )
        {
          message_vision("$N的灵性与经验,并不足以使用此剑.\n",user);
          set_heart_beat(0);
        }else{
          message_vision(HIW"鞘中之剑感受到$N的灵性,随着一道青光洒然扬出,原来正是闻名天下的"HIC"倚天剑"NOR".\n"NOR,user);

          set_name(HIC"倚天剑"NOR,({"et-sword","sword"}) );

 set("long","\n倚天剑传闻是以寒湖玄铁打制,其锋芒足可分金断玉,在武林与屠龙刀并列.\n");
          sp = my_spi;
          set_heart_beat(1);
        }
     }
}

int do_drop(string str)
{
   if( str=="all" || str=="sword" || str=="et-sword")
    if( query("equipped") )
     {    message_vision("$N轻轻巧巧的把剑收回腰际.\n",user);
        set_name(HIB"连鞘古剑"NOR,({"old sword","sword"}) );
set("long","\n这是一柄连鞘的古剑 ,古朴的剑鞘中闪烁着异样的寒光.\n");

        set_heart_beat(0);
     }
}

 int do_give(string str)
{
   if( str=="all" || str=="sword" || str=="et-sword")
     if( query("equipped") )
     {  
  message_vision("$N轻轻巧巧的把剑收回腰际.\n",user);
        set_name(HIB"连鞘古剑"NOR,({"old sword","sword"}) );
set("long","\n这是一柄连鞘的古剑 ,古朴的剑鞘中闪烁着异样的寒光.\n");

        set_heart_beat(0);
     }
}

int do_unwield(string str)
{
   if( str=="all" || str=="sword" || str=="et-sword")
     if( query("equipped") )
     {
        message_vision("$N轻轻巧巧的把剑收回腰际.\n",user);
set("long","\n这是一柄连鞘的古剑 ,古朴的剑鞘中闪烁着异样的寒光.\n");
       set_name(HIB"连鞘古剑"NOR,({"old sword","sword"}) );
        set_heart_beat(0);
     }
}

int do_auc(string str)
{
   if( str=="all" || str=="sword" || str=="et-sword")
     if( query("equipped") )
     {    message_vision("$N轻轻巧巧的把剑收回腰际.\n",user);
        set_name(HIB"连鞘古剑"NOR,({"old sword","sword"}) );
set("long","\n这是一柄连鞘的古剑 ,古朴的剑鞘中闪烁着异样的寒光.\n");
        set_heart_beat(0);
     }
}

void heart_beat()
{
	string wo,oo,wn,on;
	object *enemy,ob,obj,bk;
	int i,j,wm,om,ws,os,wd,od,qq;

	obj=this_object();

	if( !objectp(user) )
	{
	set_heart_beat(0);
	return;
	}

	if( user->is_fighting() && query("equipped") )
	{
	enemy=user->query_enemy();
	i=random(sizeof(enemy));
	  if(!enemy) return ;
	  ob=enemy[i]->query_temp("weapon");
	  if( !ob )	return ;
	  if( !ob->query("material") )
	  ob->set("material","iron");
	  if( !ob->query("sharp") )
	  ob->set("sharp",6);
	  if( !ob->query("bname") )
	  {
	  on = ob->query("name");
	  ob->set("bname",on);
	  }
	  if( random(sp+100)> 100 )
	  {
	    if( !ob || random(10) > 6 )
	    {
	    message_vision("$N大喊"HIY"【 "HIB"倚天不出  谁与争锋 !! "HIY"】\n"NOR,user);
	      for(j=0;j<=2;j++)
	      COMBAT_D->do_attack(user,enemy[i],user->query_temp("weapon"),2);
	      return;
	    }
	  }else{
	    if( environment(user) == environment(enemy[i]) )
	    {
	    oo = ob->query("material");
	    os = ob->query("sharp");

	    switch(oo)
	    {
	    case "crimsonsteel": om=100;  break;
	    case "blacksteel":   om=90;   break;
	    case "gem":          om=80;   break;
	    case "gold":         om=70;   break;
	    case "silver":       om=60;   break;
	    case "steel":        om=50;   break;
	    case "copper":       om=40;   break;
	    case "iron":         om=30;   break;
	    case "wood":         om=25;   break;
	    case "bone":         om=20;   break;
	    case "leather":      om=15;   break;
	    case "fur":          om=10;   break;
	    case "cloth":        om=5;    break;
	    default:             om=1;    break;
	    }

	    od = om * os;
	    if( od > 1000 ) od=1000;
	    qq = random( 1000-od );

	    if( random(10) > 5 && (1000 - od > 850) )
	    {
	    message_vision(HIC"只听到 __ㄎㄤ__ 一声，$n"HIC"的"+ob->query("bname")+HIC"已被倚天剑斩成两段!!\n"NOR,user,enemy[i]);
	    ob->unequip();

		bk=new("/open/main/obj/broken");
	    bk->set("name", "(断毁两段)" + ob->query("bname"));
	    bk->set("id", ob->query("id"));
	    bk->move(environment(enemy[i]));
	    destruct(ob);
		enemy[i]->reset_action();
	    }else{
	      if( qq > 280 && (1000-od < 850 && 1000-od > 400) )
	      {
	      ob->unequip();
	      message_vision(HIR"$N的"NOR+obj->name()+HIR"把$n"HIR"的"NOR+ob->query("bname")+HIR"重重的砍出了一个严重的缺口!!\n"NOR,user,enemy[i]);
	      ob->add("bad",2);
	        if( ob->query("bad") >= 11 )
	        ob->set("name", "(极尽崩碎)" + ob->query("bname"));
	        if( ob->query("bad") == 10 )
	        ob->set("name", "(严重损坏)" + ob->query("bname"));
	        if( ob->query("bad") == 9 )
	        ob->set("name", "(残破不堪)" + ob->query("bname"));
	        if( ob->query("bad") == 8 )
	        ob->set("name", "(不堪使用)" + ob->query("bname"));
	        if( ob->query("bad") == 7 )
	        ob->set("name", "(崩碎多处)" + ob->query("bname"));
	        if( ob->query("bad") == 6 )
	        ob->set("name", "(尚堪使用)" + ob->query("bname"));
	        if( ob->query("bad") == 5 )
	        ob->set("name", "(多处裂痕)" + ob->query("bname"));
	        if( ob->query("bad") == 4 )
	        ob->set("name", "(小有裂痕)" + ob->query("bname"));
	        if( ob->query("bad") == 3 )
	        ob->set("name", "(轻微裂痕)" + ob->query("bname"));
	        if( ob->query("bad") == 2 )
	        ob->set("name", "(轻微缺口)" + ob->query("bname"));
	        if( ob->query("bad") == 1 )
	        ob->set("name", "(轻微受损)" + ob->query("bname"));
	        if( ob->query("weapon_prop/damage") > 10 && ob->query("bad") < 12 )
	        {
	        ob->add("weapon_prop/damage",-10);
	        ob->wield();
	        }else{
	        message_vision(RED"$n"RED"的"+ob->query("bname")+RED"再也承受不住"HIC"倚天剑"RED"的攻击而完全断毁了!!\n"NOR,user,enemy[i]);

			bk=new("/open/main/obj/broken");
	        bk->set("name", "(完全断毁)" + ob->query("bname"));
	        bk->set("id", ob->query("id"));
	        bk->move(environment(enemy[i]));
	        destruct(ob);
			enemy[i]->reset_action();
	        }
	      }else{
	        if( qq > 150 && (1000-od < 400 && 1000-od > 200) )
	        {
	        ob->unequip();
	        message_vision(HIY"$N"HIY"的"NOR+obj->name()+HIY"把$n"HIY"的"NOR+ob->query("bname")+HIY"轻轻的砍出了一个小缺口!!\n"NOR,user,enemy[i]);
	        ob->add("bad",1);
	          if( ob->query("bad") >= 11 )
	          ob->set("name", "(极尽崩碎)" + ob->query("bname"));
	          if( ob->query("bad") == 10 )
	          ob->set("name", "(严重损坏)" + ob->query("bname"));
	          if( ob->query("bad") == 9 )
	          ob->set("name", "(残破不堪)" + ob->query("bname"));
	          if( ob->query("bad") == 8 )
	          ob->set("name", "(不堪使用)" + ob->query("bname"));
	          if( ob->query("bad") == 7 )
	          ob->set("name", "(崩碎多处)" + ob->query("bname"));
	          if( ob->query("bad") == 6 )
	          ob->set("name", "(尚堪使用)" + ob->query("bname"));
	          if( ob->query("bad") == 5 )
	          ob->set("name", "(多处裂痕)" + ob->query("bname"));
	          if( ob->query("bad") == 4 )
	          ob->set("name", "(小有裂痕)" + ob->query("bname"));
	          if( ob->query("bad") == 3 )
	          ob->set("name", "(轻微裂痕)" + ob->query("bname"));
	          if( ob->query("bad") == 2 )
	          ob->set("name", "(轻微缺口)" + ob->query("bname"));
	          if( ob->query("bad") == 1 )
	          ob->set("name", "(轻微受损)" + ob->query("bname"));
	          if( ob->query("weapon_prop/damage") > 5 && ob->query("bad") < 12 )
	          {
	          ob->add("weapon_prop/damage",-5);
	          ob->wield();
	          }else{
	          message_vision(RED"$n"RED"的"+ob->query("bname")+RED"再也承受不住"HIC"倚天剑"RED"的攻击而碎裂断毁了!!\n"NOR,user,enemy[i]);

			  bk=new("/open/main/obj/broken");
	          bk->set("name", "(碎裂断毁)" + ob->query("bname"));
	          bk->set("id", ob->query("id"));
	          bk->move(environment(enemy[i]));
	          destruct(ob);
			  enemy[i]->reset_action();
	          }
	        }else{
	          if( qq > 75 && (1000-od < 200 && 1000-od > 100) )
	          {
	          message_vision(HIG"$n"HIG"只觉得手中"NOR+ob->query("bname")+HIG"被"NOR+obj->name()+HIG"一震，险些脱手飞出!!\n"NOR,user,enemy[i]);
		      }else{
		        if( qq > 25 && (1000-od < 100 && 1000-od > 50) )
		        {
	            message_vision(HIW"$N"HIW"的"NOR+obj->name()+HIW"和$n"HIW"的"NOR+ob->query("bname")+HIW"相击，冒出点点的火星。\n"NOR,user,enemy[i]);
	            }else{
	              if( random(10) > 5 && (1000 == od) )
	              {
	              message_vision(HIM"$N"HIM"的"NOR+obj->name()+HIM"和$n"HIM"的"NOR+ob->query("bname")+HIM"相击，发出响亮清脆的声音。\n"NOR,user,enemy[i]);
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
  }

	return;
}
   
