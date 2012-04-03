#include <command.h>
#include <ansi.h>
#include <combat.h>
#include <skill.h>
inherit F_FUNCTION;
inherit SSERVER;
int fun;
void damage_msg(int damage,object me, object target);
int perform(object me, object target)
{
  int ski_value,damage;
  string msg;
  fun=me->query("functions/badroar/level");
  ski_value=random(fun+me->query_skill("badstrike",1))+1;
  damage=ski_value*((fun/10));
  if( !target ) target = offensive_target(me);
  if(!target) return notify_fail("你找不到敌人!!\n");
  if (me->query_skill_mapped("force")!="badforce" || me->query_skill_mapped("unarmed")!="badstrike")
return notify_fail("不用恶化魔功和恶霸掌怎能发挥混杀吼的功力?\n");
        if(!me->is_fighting(target))
        return notify_fail("你又没在战斗 ,吓鬼啊!?\n");
  if( me->query_skill("badstrike",1) < 30 )
  return notify_fail("没底子还想唬人 ,去练练吧 !\n");
  if( me->query_skill("badforce",1) < 50 )
  return notify_fail("起码也要有点气势才能吓人啊 ,你看看你!!\n");
  if(me->query("force")<300)
  return notify_fail("没内力 ,回家吃屎吧 !\n");
  if(me->query("quests/badroar") != 1)
  return notify_fail("你在干嘛啊...乱吼乱吼的...?\n");
  if( me->query("class")!="bandit")
  return notify_fail("你又不怎么邪恶 ,怎么会用这等邪招 ?\n");
if( target->is_busy() ) 
return notify_fail("敌人 busy 中，快攻击吧。\n"); 
  message_vision(HIY"$N紧闭双眼，整个身体散发出不可思议的气息！\n"NOR,me,target);
if(80>random(100)) {
if(ski_value>=195 && me->query("force")>=2500)
  {
me->add("force",-3000);
target->receive_wound("gin",(target->query("gin")*1/3));
target->receive_wound("kee",(target->query("kee")*1/3));
target->receive_wound("sen",(target->query("sen")*1/3));
message_vision(HIW"\n\t$N身子忽然一顿，双手飞舞，步法急转，"HIC"\n\n\t使出的正是恶人谷不传绝学----"HIM"天魔乱舞"HIB"\n\n\t但见$N趁$n正竭力闪躲群魔刀舞时，
"HIY"\n\t倏地转至$n身前，口中不住地唸唸有词："HIG"\n\n\t\t穷凶恶极，神哭鬼嚎"HIC"\n\n\t使出的正是恶人谷不传秘诀----"HIM"混沌气杀"HIW"
\n\t只见$n连受$N两大绝技所伤，身体承受不住强大伤害，全身喷出道道血柱！"HIR"
\n\t这招正是恶人极杀技----"MAG"天魔混杀击"HIR"！\n\n"NOR,me,target);
    write(HIW"你使尽全力使出恶人极杀，感到全身虚弱，毫无力气。\n"NOR);
    message_vision(RED"$n中了$N的"HIR"天魔混杀击"RED" ,全身鲜血直流!!!!\n"NOR,me,target);
    target->apply_condition("bleeding",10);
  }
  else if ( ski_value < 7 )
  {
     me->add("force",-50);
     write(HIM"你忽然发现苗头不对 ,整个身体又像泄了气的皮球一样 ,毫无半分神气\n"NOR);
     say( GRN"你看见"+me->query("name")+"的脸忽圆忽扁 ,脸蛋红通通的 ,不禁笑了出来\n"NOR);
  }
  else if ( ski_value < 30 )
          {
           me->add("force",-100);
           target->receive_damage("sen",damage);
           write(HIB"你喝然摆\出一付小喽啰的样子 ,试着将对手吓倒!\n"NOR,me,target);
           say(MAG"你看到了"+me->query("name")+"一付小喽啰的神态 ,不禁怔了一下 !\n"NOR);
   }
  else if ( ski_value < 60 )
   {
     me->add("force",-150);
     target->receive_damage("sen",damage);
     write(HIB"你双手一张 ,嘴唇微翘 ,试着用个十足小瘪三的模样唬住对手 .\n"NOR,me,target);
     say(MAG"你看到了"+me->query("name")+"那一脸小瘪三的神情 ,不禁被那气息迷住 .\n"NOR);
  }
  else if ( ski_value < 90 )
  {
    me->add("force",-200);
    target->receive_damage("sen",damage);
write(HIB"你整个身子一摆\ ,双眼微凸 ,装出一付土霸王的威势 !\n"NOR,me,target);
    say(MAG"你看到了"+me->query("name")+"那付土霸王的威势 ,身上鸡皮疙瘩都冒了出来!\n"NOR);
  }
  else if ( ski_value < 120 )
  {
    me->add("force",-250);
    target->receive_damage("sen",damage);
    write(HIB"你身上杀气散发 ,两眼直瞪对手 ,那付神情 ,活像要把对手吃了下去 !\n"NOR,me,target);
    say(MAG"你看到了"+me->query("name")+"那付恶贯满盈的气势 ,不禁冷汗直流 ,全身发抖!!!!\n"NOR);
  }
  else if ( ski_value < 150 )
  {
    me->add("force",-300);
    target->receive_damage("sen",damage);
   write(HIB"\n\n\t你将隐藏在你身体中的杀气悉数放了出来 ,"HIY"\n\n\t然后用那邪恶的眼神横扫对手 ,"HIW"\n\n\t这付邪恶的模样 ,仿佛连神 ,连鬼都要惧怕三分!!!!!!\n\n"NOR,me,target);
    say(MAG"你看到了"+me->query("name")+"那全身的邪气 ,不禁为那"HIM"神"RED"鬼"HIW"皆惧"MAG"的样子吓的全身无力 ,毫无作战意志 !\n"NOR);
  }
  else
  {
   me->add("force",-400);
   target->receive_damage("sen",damage);
write(HIB"\n\n\t你忽然领悟到"HIW"穷凶恶极 ,神哭鬼嚎"HIB"的精义"HIC"\n\n\t于是闭眼吸气 ,体内真气及杀气围绕在你的四周 ,\n\n\t看来有如天神下凡般神秘 ,却又有如魔鬼出窍般恐怖!!!!"HIY"
\n\t忽然你双眼一睁 ,四周气氛大变 ,风雨交加!!"HIG"\n\n\t你大喝一声 ,一道光芒朝你的对手射去!!!!!!!\n\n"NOR,me,target);
say(MAG"\n\n\t你看到"+me->query("name")+"那四周的异变 ,不觉身子已被吓住 ,动弹不得"HIR"\n\n\t忽然只看见"+me->query("name")+"双眼一睁 ,只觉自己身处地狱深处 ,又觉自己正站在天堂之中!!"HIM"
\n\n\t忽然又听见"+me->query("name")+"大喝一声 ,心中一怔 ,你已感到头昏脑胀 ,身心俱裂!!!!!!\n\n"NOR);
   }
  if ( ski_value < 7 )
  {
   message_vision(HIW"$N跟本吓唬不了$n!!!\n"NOR,me,target);
   }
  else if (damage < 250 )
    message_vision(HIC"$N的模样稍微让$n怔了一下 !\n"NOR,me,target);
  else if (damage < 500 )
    message_vision(HIM"$N的模样确实地吓到了$n!!\n"NOR,me,target);
  else if (damage < 750 )
    message_vision(HIB"$n被$N的壮大气势给唬住了!!!\n"NOR,me,target);
  else if (damage < 1000 )
    message_vision(HIY"$n感染了$N所散发出的王者架势 ,吓的神智不清!!!!\n"NOR,me,target);
  else if (damage < 1250 )
    message_vision(HIG"$N所展现的王者风范吓的$n六神无主!!!!!\n"NOR,me,target);
  else if (damage < 1500 )
    message_vision(HIR"结果$n仿佛看到恶鬼般 ,浑身无力 ,毫无作战意志!!!!!!\n"NOR,me,target);
  else if (damage < 1750 )
    message_vision(MAG"结果$n像是刚从地狱回来般 ,丝毫提不起精神!!!!!!!\n"NOR,me,target);
  else if (damage < 1950 )
    message_vision(BLU"$n被$N吓的魂魄尽失 ,面貌仿佛老去了一大半!!!!!!!!\n"NOR,me,target);
  else message_vision(RED"$n被$N吓的魂飞魄散 ,整个人失去了生命力!!!!!!!!!\n"NOR,me,target);
  if(!target->is_busy())
target->start_busy(2);
} else {
message_vision(HIW"结果被$n闪了过去。\n"NOR,me,target);
}
  if ( fun < 100 || random(100)> 70) {
  function_improved("badroar",random(me->query("max_force")/10));
  }
  me->start_busy(1);
  return 1;
}
