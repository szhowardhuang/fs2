//87.10.11  改成使用hit_ob来驱动特攻，
//		所以把heart_beat拿掉！
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
object user=this_player();
void create()
{
        seteuid(getuid());
        set_name(HIR"绝"+HIY"世"+HIG"匕"+HIC"首"NOR,({"world"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
       {
 	set("unit", "把");
        	set("long","匕首上刻有四门之图腾，整支匕首散发出无比的力量．\n");
                 	set("value",20000);
	set("material", "steel");
                	set("no_sell",1);
	set("no_auc",1);
	set("no_drop",1);
	set("no_steal",1);
	set("no_give",1);
        }
       set("wield_msg",HIR"$N将绝世匕首握在手上，全身充满着无限的力量。\n"NOR);
       set("unwield_msg",HIY"$N画出一道银花，将$n放回身边小袋中。"NOR);
        init_dagger(95);
        setup();
}

mixed hit_ob( object victim,object me)
{
  object user;
  int a,b,c,i,bell,shalv,maglv,doglv,cor;
  int chiso,world_choice;

  user=this_player();
  bell  = user->query("bellicosity");
  shalv = user->query_skill("shadow-kill",1);
  maglv = user->query_skill("magic",1);
  doglv = user->query_skill("dodge",1);
   cor  = user->query("cor");

 if( user->is_fighting() && query("equipped") )
 {
   //代表魔气杀最少要有60级以上，才有机会驱动四神合一第一式
  //目前也只写第一，二式
  if (random(user->query("functions/manakee/level") ) > 60)
  {//如果玩家练魔气杀练到LV 100的话，发动机率约为40％
   //但是，一般而言目前最多都没练到LV 60
   //但为避免还是有人练到，导致威力太强，所以在加上一个机率
   if(random(user->query_skill("rain-throwing",1)) >  80)
   {//因为，rain-throwing的等级最高100，所以max机率将是 0.4*0.2=0.08
     message_vision(HIR"\n            四   "+HIG"神   "+HIY"合   "+ HIC"一   "+HIW"!"NOR,victim);
     message_vision(HBMAG"\n                       ■四☆★☆神☆★☆暴☆★☆走■\n"NOR,victim);
     message_vision(HBYEL"\n匕首中窜出一道玄武幻影，包围$N！\n"NOR,victim);
     message_vision(HBCYN"\n匕首中窜出数十道白虎幻影，牵制$N的攻势\n"NOR,victim);
     message_vision(HBGRN"\n青龙由匕首上冲出，直接冲向$N!!\n"NOR,victim);
     message_vision(HBRED"\n巨大的火凤凰飘然降临，$N四周仿佛扬起地狱的业火\n"NOR,victim);
     //玄武的
     chiso=random(cor+doglv);
     victim->add("gin",-chiso);
     victim->add("sen",-chiso);
     user->add("kee",chiso);
     //白虎的
     victim->start_busy(2);
     //青龙的
     victim->add("gin",-((cor+maglv)*3));
     victim->add("sen",-((cor+maglv)*3));
     //朱雀的
     victim->receive_damage("kee",random(shalv*2.8),user);
     //玩家所必须付出的代价
     user->add("bellicosity",-(user->query("bellicosity")/10));
     user->add("atman",-(user->query("atman")/3));
     user->add("force",-(user->query("force")/8));
     return ;
   }
  }
//四神合一第二式，发动最基本条件，阎影匕首 lv 70,魔气杀lv 80
//阎影匕首最高lv90，魔气杀是func且不是内力型，一定要打敌人练，蛮难练的
//manakee目前玩家最高练到60左右
//若以魔气杀第二段限制lv 100与阎影匕首最高lv 90来算
//最高机率是 (90-70)/90 * 0.2=0.22*0.2=0.044=4.4%的发动机率
//至于玩家所需付出的代价，因为都是四神合一，所以一样
//代价：内力的1/8，杀气的1/10，灵力的1/3，可以说是用自己的生命去换取胜利
//伤害是看发动哪一位霸主，每一个都有所不同
  if (random(user->query("functions/manakee/level") ) > 80)
  {//如果玩家练魔气杀练到LV 100的话，发动机率约为20％
   //但是，一般而言目前最多都没练到LV 50
   //但为避免还是有人练到，导致威力太强，所以在加上一个机率
   if(random(user->query_skill("shadow-kill",1)) >  70)
   {
     message_vision(HIR"\n            四   "+HIG"神   "+HIY"合   "+ HIC"一   "+HIW"!"NOR,victim);
     message_vision(HBMAG"\n                       ■四☆★☆神☆★☆霸☆★☆主■\n"NOR,victim);
     world_choice=random(4);
     switch(world_choice)
     {
	case 0: //玄武霸主
	{
	  message_vision(HBYEL"\n◎◎◎◎◎◎▁▂▃▄▅▆▇█▇▆▅▄▃▁◎◎◎◎◎◎\n"NOR,victim);
     	  message_vision(HBYEL"\n玄武称霸四神，化身成为玄武霸主，笼罩住$N四周！\n"NOR,victim);
	  message_vision(HBYEL"\n$N感到全身的精力似乎被玄武霸主所剥夺！！\n"NOR,victim);
	  message_vision(HBYEL"\n玄武霸主由$N回到四神匕首，你感到全身精神为之一振！！\n"NOR,victim);
	  message_vision(HBYEL"\n◎◎◎◎◎☆◎★◎↑↓←→↖↗↙↘◎★◎☆◎◎◎◎◎\n"NOR,victim);	
          //玄武霸主的伤害
	     chiso=random(cor+doglv);
	     victim->add("gin",-(chiso*3));
	     victim->add("sen",-(chiso*3));
	     user->add("gin",chiso*2);
	     user->add("sen",chiso*2);
	  break;
	}
	case 1://白虎霸主
	{
   	  message_vision(HBCYN"\n◎◎◎◎◎◎▁▂▃▄▅▆▇█▇▆▅▄▃▁◎◎◎◎◎◎\n"NOR,victim);
	  message_vision(HBCYN"\n白虎称霸四神，化身成为白虎霸主，牵制$N的攻势\n"NOR,victim);
	  message_vision(HBCYN"\n$N的攻势为之一滞，似乎施展不开来。。。\n"NOR,victim);
          message_vision(HBCYN"\n$N强硬摆\脱白虎霸主的控制，身体受到严重的创伤\n"NOR,victim);
	  message_vision(HBCYN"\n◎◎◎◎◎☆◎★◎↑↓←→↖↗↙↘◎★◎☆◎◎◎◎◎\n"NOR,victim);
          //白虎霸主的伤害
   	  victim->start_busy(2);
	  victim->add("kee",-(cor*3));
          break;
        }
	case 2://青龙霸主
	{
	  message_vision(HBGRN"\n◎◎◎◎◎◎▁▂▃▄▅▆▇█▇▆▅▄▃▁◎◎◎◎◎◎\n"NOR,victim);
          message_vision(HBGRN"\n青龙称霸四神，化身成为青龙霸主，冲向$N，透体而过!!\n"NOR,victim);
	  message_vision(HBGRN"\n$N感到一阵排山倒海的压力迎面而来，宛如世界末日一般！\n"NOR,victim);
          message_vision(HBGRN"\n青龙霸主的强大威力，令$N精神受到严重打击!\n"NOR,victim);
	  message_vision(HBGRN"\n◎◎◎◎◎☆◎★◎↑↓←→↖↗↙↘◎★◎☆◎◎◎◎◎\n"NOR,victim);	
          //青龙霸主的伤害
	  victim->add("gin",-random((cor+maglv)*5));
	  victim->add("sen",-random((cor+maglv)*5));
          break;
        }
	case 3://朱雀霸主
	{
	  message_vision(HBRED"\n◎◎◎◎◎◎▁▂▃▄▅▆▇█▇▆▅▄▃▁◎◎◎◎◎◎\n"NOR,victim);
	  message_vision(HBRED"\n朱雀称霸四神，化身成为朱雀霸主＝＝幻之火凤凰，$N看呆\n"NOR,victim);
	  message_vision(HBRED"\n$N四周扬起地狱的业火，熊熊的烈火环绕身躯\n"NOR,victim);
          message_vision(HBRED"\n地狱般的业火，在$N身上熊熊的燃烧着！！！！！\n"NOR,victim);
	  message_vision(HBRED"\n这种痛苦的感觉另$N感到身上的一切似乎已不再属于自己！！！\n"NOR,victim);
	  message_vision(HBRED"\n◎◎◎◎◎☆◎★◎↑↓←→↖↗↙↘◎★◎☆◎◎◎◎◎\n"NOR,victim);	
          //朱雀霸主的伤害
	  victim->receive_damage("kee",random(shalv*5),user);
          break;
        }
     }  //switch block的外围，由case里面的break将会跳到这里
     //玩家所必须付出的代价
     user->add("bellicosity",-(user->query("bellicosity")/15));
     user->add("atman",-(user->query("atman")/3));
     user->add("force",-(user->query("force")/10));
     return ;
   }
  }
   
  //上面是属于四神合一的特攻阶段
  if(random(100) > 80)   //新玄武特攻，土系，吸收型  30％发动成功
  {
   message_vision(HBYEL"\n由绝世匕首中窜出一道玄武幻影，包围$N！\n"NOR,victim);
   message_vision(HBYEL"\n巨大的玄武幻影，将$N吞噬！\n"NOR,victim);
   message_vision(HIM"$n被$N的玄武幻影所侵袭,精神流失被$N所吸收"NOR"\n",user,victim);
//表闪躲能力越好，被打中的％越少
   chiso=random((cor*2)+(doglv/2));
   victim->add("gin",-chiso);
   victim->add("sen",-chiso);
   user->add("kee",chiso);
   user->add("gin",chiso);
   user->add("sen",chiso);
   COMBAT_D->report_status(victim);
   //防止吸超过上限
   if(user->query("sen") > user->query("max_sen"))
   {
    a=user->query("max_sen");
    user->set("sen",a);
   }
   if(user->query("gin") > user->query("max_gin"))
   {
    b=user->query("max_gin");
    user->set("gin",b);
   }
   if(user->query("kee") > user->query("max_kee"))
   {
    c=user->query("max_kee");
    user->set("kee",c);
   }
   return ;          //因为已经发动这一项，所以不可以在发动其他特攻	
  }//以上是玄武特攻的发动设定 

  if(random(100) > 80)  //新白虎特攻，冰系，牵制型 30%发动成功
  {
     message_vision(HBCYN"\n由绝世匕首中窜出数十道白虎幻影，牵制$N的攻势\n"NOR,victim);
     message_vision(HBCYN"白虎幻影干扰着$N的视线，致使攻势为之一滞\n"NOR,victim);
     if (doglv > victim->query_skill("dodge",1))
      	victim->start_busy(2);
     else 
      	victim->start_busy(1);
      message_vision(HIC"$N受到白虎幻影的牵制，而无法行动\n"NOR,victim);
     return ;
  }//以上是白虎特攻的发动设定

  if(random(100) > 80)  //新青龙特攻，风系，精神伤害系 30%发动成功
  {
     message_vision(HBGRN"\n青龙由匕首上冲出，直接冲向$N!!\n"NOR,victim);
     message_vision(HBGRN"青龙幻影穿身而过，对$N的精神上以造成强大伤害!!\n"NOR,victim);	
     if( bell > 4000)
     {//代表具有强大的杀气，可以对精神上造成更大的伤害
	victim->add("gin",-(cor*5));
	victim->add("sen",-(cor*5));
	message_vision(HBGRN"$N精神上受到非常严重的创伤!!\n"NOR,victim);	
        return ;
     }
     if( bell > 2000)
     {//代表具有强大的杀气，可以对精神上造成更大的伤害
	victim->add("gin",-(cor*4));
	victim->add("sen",-(cor*4));
	message_vision(HBGRN"$N精神上受到严重的创伤!!\n"NOR,victim);	
        return ;
     }
     if( bell > 1000)
     {//代表具有强大的杀气，可以对精神上造成更大的伤害
	victim->add("gin",-(cor*3));
	victim->add("sen",-(cor*3));
	message_vision(HBGRN"$N精神上受到普通的创伤!!\n"NOR,victim);	
        return ;
     }		
     if( bell > 100)
     {//代表具有强大的杀气，可以对精神上造成更大的伤害
	victim->add("gin",-(cor*2));
	victim->add("sen",-(cor*2));
	message_vision(HBGRN"$N精神上受到轻微的创伤!!\n"NOR,victim);	
        return ;
     }
     return ;
  }//以上是青龙的发动设定

  if(random(100) > 70)  //新朱雀特攻，火系，肉体伤害型 40%发动成功
  {
      if (shalv >80)
      {//阎影匕首越强，威力越大，LV最高90所以最高是 252点伤害
	message_vision(HBRED"\n巨大的火凤凰飘然降临，$N四周仿佛扬起地狱的业火\n"NOR,victim);
	message_vision(HBRED"$N被地狱的业火所灼，肉体遭到非常严重的伤害\n"NOR,victim);
                  victim->receive_damage("kee",random(shalv*2.8),user);
	COMBAT_D->report_status(victim);
	return ;
      }
      if (shalv >60)
      {//阎影匕首越强，威力越大
	message_vision(HBRED"\n$N四周扬起地狱的业火，熊熊的烈火将四周包围\n"NOR,victim);
	message_vision(HBRED"在烈火中传出$N凄厉的哀嚎声，其肉体遭到严重的创伤\n"NOR,victim);
        victim->receive_damage("kee",random(shalv*2.2),user);
	COMBAT_D->report_status(victim);
	return ;
      }
      if (shalv >40)
      {//阎影匕首越强，威力越大
	message_vision(HBRED"\n朱雀所扬起的熊熊烈火，在$N四周燃烧着\n"NOR,victim);
	message_vision(HBRED"$N一不小心被烈火所伤，身体受到不少烧伤\n"NOR,victim);
        victim->receive_damage("kee",random(shalv*1.6),user);
	COMBAT_D->report_status(victim);
	return ;
      }
      if (shalv > 1)
      {//阎影匕首越强，威力越大
	message_vision(HBRED"\n绝世匕首发出刺眼的火光，令$N眼睛受到伤害\n"NOR,victim);
	message_vision(HBRED"$N攻势为之一滞，且眼睛也受到伤害了。\n"NOR,victim);
                 victim->receive_damage("kee",random(shalv),user);
      	victim->start_busy(1);
	COMBAT_D->report_status(victim);
	return ;
      }
      if (shalv <= 1)
      {//考虑到目前world是开放的，所以，有些门派没有shadow-kill
	message_vision(HBRED"\n绝世匕首发出刺眼的火光，令$N眼睛受到伤害\n"NOR,victim);
	message_vision(HBRED"$N攻势为之一滞。\n"NOR,victim);
      	victim->start_busy(1);
	COMBAT_D->report_status(victim);
	return ;
      }
   } //以上是朱雀的发动设定
  //代表发动失败
	tell_object(user,"\n四神均毫无动静!!\n");
  
	return;
 } //这是检查有没也在战斗中的那一个if的block
}  //函示结束的block
