//皇拳 by bss
//皇城mob专用，不开放
//借用roger && taifar所写sun_fire_sword的连击程式
#include <ansi.h>
#include <combat.h>
inherit SKILL;
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);
void sp_attack(object me,object victim,object weapon,int damage);
void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);

string *taiganfist = ({
"$N使出"HIC"阴"HIR"阳"NOR"掌法中"HIC"阴"NOR"招的起手式"HIC"「苍松迎客”"NOR"，右掌平推而出，一道寒风由$N掌中拍出，令人不禁打起冷颤。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中"HIR"阳"NOR"招的起手式"HIR"「开门辑盗”"NOR"，左掌由上而下猛劈而出，一股热风随着$N的掌势而出，使人有种不舒服的闷热感。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中的"HIC"阴"NOR"招"HIC"「梅雪争春”"NOR"，右掌如雪花翻飞击向$n。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中的"HIR"阳"NOR"招"HIR"「梅雪逢夏”"NOR"，左掌如连珠般向$n拍出了一十二掌。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中的"HIC"阴"NOR"招"HIC"「老枝横斜”"NOR"，左掌平举，右掌由左胁下斜穿而出，击向$n的$l。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中的"HIR"阳"NOR"招"HIR"「长者折枝”"NOR"，左掌高举，迅速地下拍击向$n的$l。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中的"HIC"阴"NOR"招"HIC"「明驼西来”"NOR"，右掌并指成剑，迅雷般刺向$n的$l。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中的"HIR"阳"NOR"招"HIR"「千钧压驼”"NOR"，左掌撮指成刀，疾电般劈向$n的$l。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中的"HIC"阴"NOR"招"HIC"「风沙莽莽”"NOR"，右掌掌势似有狂风黄沙之重压，教$n透不过气来。\n",
"$N使出"HIC"阴"HIR"阳"NOR"掌法中的"HIR"阳"NOR"招"HIR"「大海沉沙”"NOR"，左掌掌势如有怒海洪涛之汹涌，教$n心惊胆颤。\n",
});

string *fon_un = ({
HIW"\n风云连续掌第一式"HIB"‘行云流水’"HIW"，招式有如流水般朝$n攻去，使人目不暇己\n"NOR,
HIW"\n风云连续掌第二式"HIB"‘披星戴月’"HIW"，右手中指忽然朝$n直刺过去，刺中了$n身上几大要穴\n"NOR,
HIW"\n风云连续掌第三式"HIB"‘翻云覆雨’"HIW"，$N双掌如风车般在$N身旁转了起来，$n被招式所产生的\n\n螺漩气流所侵，受了重伤\n"NOR,
HIW"\n风云连续掌第四式"HIB"‘排山倒海’"HIW"，$N将双掌插入土地，跟着用力拔起，随掌势而飞起的土石\n\n击中了$n\n"NOR,
HIW"\n风云连续掌第五式"HIB"‘重云深锁’"HIW"，$N双掌$n身上画了十几个小圆圈，$n\n\n忽然身体一震，动弹不得\n\n"NOR,
HIW"\n风云连续掌第六式"HIB"‘风卷残楼’"HIW"，$N拔身而起，身体圆转，如一道龙卷风般朝$n攻去\n"NOR,
HIW"\n风云连续掌第七式"HIB"‘狂风暴雨’"HIW"，招式连绵不绝的朝$n攻去，使$n身受重创\n"NOR,
HIW"\n风云连续掌第八式"HIB"‘神风怒嚎’"HIW"，右掌撮指成刀在空间中快速的砍劈，使四周产生了巨大的破空声\n"NOR,
HIW"\n风云连续掌第九式"HIB"‘撕天排云’"HIW"，$N双掌合并，将高度集中的劲气聚在掌心，忽然向外一推，\n\n一道惊人气劲朝$n攻去。\n"NOR,
HIW"\n风云连续掌第十式"HIB"‘云海波涛’"HIW"，劲气如巨浪狂涌而至，$n连闪避的机会也没有\n"NOR,
HIW"\n风云连续掌第十一式"HIB"‘殃云天绛’"HIW"，$N跃至空中，双掌朝$n用力下拍，掌气充斥着这整个空间\n"NOR,
});


mapping *action = ({
(["action":
HIY"$N"HIY"身形立定，使出皇拳第一式"HIC"「君臣之礼”"HIY"，$N"HIY"弓身，曲膝，身子如一只箭般朝$n射去，
，正当$n摆\好姿势想要闪躲$N"HIY"这致命一击时，$N"HIY"的身体忽然违反常理的停在半空中，变成
头上脚下，双手往地上用力一撑，右脚向上猛踢，眼看就要击中$n的下巴了"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "踢伤",
        "post_action":          (: sp_attack:),
]),
(["action":
HIY"$N"HIY"暗运心法，使出皇拳第二式"HIC"「天下大道”"HIY"，双手合十，将高度集中的劲气聚在双手掌
心，双手向外一推，一股排山倒海的劲气袭向$n，正当$n气集双臂准备硬接这股要人命的
劲气时，$N"HIY"忽然在$n的右方出现，右脚往$n的小腹猛踹"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "踹伤",
]),
(["action":
HIY"$N"HIY"紧握双拳，使出皇拳第三式"HIC"「问鼎中原”"HIY"，双拳猛力地往地面一击，使地面不住的震
动，$n立足不稳，竟被这由地面传出的劲气震到了空中，$N"HIY"全身劲力一提，有如炮弹一
般地击向$n，$n因身在半空中无处着力，眼看就要被击中了"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "掌伤",
        "post_action":          (: sp_attack:),
]),
(["action":
HIY"$N"HIY"化拳为掌，使出皇拳第四式"HIC"「千军万马”"HIY"，一个巨大掌影铺天盖\地的向$n袭去，刹时
，$n有一种置身在于漩涡内的眩然感觉，$n身形立定，举臂格档，就在巨掌快要击中
$n的刹那，$N"HIY"的巨灵一掌，竟突然急转为细如毛针般的乱空掌影，一时$n的四面八方都
是疾涌狂飙的掌影"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "掌伤",
        "post_action":                (: sp_attack5 :),
]),
(["action":
HIY"$N"HIY"眼中精光暴放，使出皇拳第五式"HIC"「黄袍加身”"HIY"，猛烈的近乎异常的劲气，朝$n袭去，
那样的猛烈拳势，仿佛真能裂石崩山，强厉的气劲，似乎要将人活生生撕碎的涌往$n"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "掌伤",
        "post_action":  (:sp1:),
]),
(["action":
HIY"$N"HIY"使出皇拳第六式"HIC"「雄霸天下”"HIY"，双拳如连珠般连续不断的击出，乍看之下全无章法，
但每拳都从$n想都想不到得地方击出，充满了天马行空的想法，使$n愈抵挡愈心惊，逐
渐地丧失了信心"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "掌伤",
        "post_action":                (: sp_attack0 :),
]),
(["action":
HIY"$N"HIY"缓缓闭上双眼，刹那间进入了万里空晴的心法最高境界，使出皇拳第七式"HIC"「九五之尊”"HIY"
，$N"HIY"清楚的知道了$n的强弱，看准了时机，一拳击出，$n哈哈大笑道：「尔等技止于此啦
”，正欲变招反击，没想到$N"HIY"只是虚招，真正的杀手却在$N"HIY"的右脚，$n脸色大变，因为此
脚击出的角度及时机均是$n想都没想到的"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "踢伤",
]),
(["action":
HIY"$N"HIY"向前大跨一步，杀气从$N"HIY"的身后涌出，使出了皇拳第八式"HIC"「震怒龙颜”"HIY"，只见$N"HIY"劲贯
右臂，大喝一声：「龙拳暴发”，右拳猛力朝$n击出，拳劲化为一只神龙，如龙卷风般向
着$n卷去，四周空气受到拳劲影响也激起了大大小小不同的旋风，使得$n难以动弹"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "击伤",
        "post_action":  (:sp2:),
]),
});
int valid_learn(object me)
{
        return 1;
}
int valid_enable(string usage)
{
        return (usage=="unarmed");
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
void sp1(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("kingfist", 1);
   message_vision("$N被招式所带起的上升气流，卷至空中并被撕裂开来\n",victim);
   victim->receive_damage("kee", (skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("kingfist",1)/5));
   COMBAT_D->report_status(victim);
   victim->start_busy(2);
}
void sp2(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("kingfist", 1);
   if(70 > random(100))
   {
   message_vision(HIY"
                  _-~~~~~~-_/|          ._---;/^ ^   `./|
           v     /^^ v  ^^  ~/|         (( );/^     > > `/|
   \\     (:)   /^ ^(:)  ^  >>`/|          ,/ ^^  >    > >`/|
    \\    (::) /   (::) ;> / >>`/|        ,/^^^   ,-.   > >>`/|
     \\   (::),~~~.(::)/`/   >>>`/|      ,/^^   ^;   `.   > >`/|
       \\  <_):::::(_>/ /`._--.  `/|     ;/^  ^  ;-_.  `.. >  >`/|
        \\ \\|:::|:::|/ /   ( ))  >`/|   ,/^ ^   ;( ))     ;  >> `/
         \\  \\_:|:_/  /    `.     >`/| ,/^^   ^ ;          ;>  > /;
          \\ \\@, .@/ /      `.  > > `-- ^  ^   ;           :  > /.'
           \\ \\=:=/ /       _`.    >  > >  >  ;           ,` >  /;
            \\\\=:=//       ((,`.> >    > > _/           ,' > > /'
            < o_o >           ~`-__ > ___-~          _,' > > /;
                                  ~~~     ~~_-~=--~~ >> /_;/
                                          _~   _~--____-~



   气劲化成的巨龙，竟然缠绕住$N的身体，使$N完全无法动弹，任人宰割。\n"NOR,victim);
   victim->receive_damage("kee", (skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("kingfist",1)/5));
   COMBAT_D->report_status(victim);
   victim->start_busy(5);
   }
   else
   {
   message_vision("$N急运身法，才堪堪避过了这致命的一击。\n",victim);
   }
}
void sp_attack0(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;

  force=me->query("force",1);
  enemy = me->query_enemy();
  i=random(sizeof(enemy));


  if( 21 > random(30) && me->query("force") > 360 && !me->query_temp("con_ti",1)) {

message_vision(HIM"
$N脸上紫气浮现，全身劲气扩张，身体腾空而起，大喝一声:
「"HIB"阴"HIR"阳"HIG"连续掌!!!”"HIM"，以及快的速度拍出
令人至命的掌法!!!
\n"NOR,me,victim);

    for(j=0; j < 10; j++) {
       do_action = taiganfist[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision(HIR"\n$N闪躲不及，被重重得击中。\n"NOR , enemy[i]);
        enemy[i]->receive_damage("kee",50,me);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N，展开身形， 惊险地闪过了这一招。\n" , enemy[i]);
                             }

        me->add("force",-100);
        message_vision("\n$N使完「"HIB"阴"HIR"阳"HIG"连续掌"NOR"!!!”后，由于定力不足，体内真气一时无以为继\n",me);
        me->start_busy(1);
                                                          }

}
void sp_attack5(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;

  force=me->query("force",1);
  enemy = me->query_enemy();
  i=random(sizeof(enemy));


  if( 21 > random(30) && me->query("force") > 510 && !me->query_temp("con_ti",1)) {
message_vision(BLINK+HIG"
\n$N忽然眼放精光，大喝一声「风云连续掌”，刹那间四周涌起一道黑云，使$n完全失去$N的踪影!!\n\n
\n$N以传音之术对$n说到:「接招吧”，招式如狂风般朝$n袭至!!\n\n
"NOR,me,victim);
    for(j=0; j < 11; j++) {
       do_action = fon_un[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision(HIR"\n$N闪躲不及，惨叫一声，被重重的拍到。\n"NOR , enemy[i]);
        enemy[i]->receive_damage("kee",50,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N人比招快，惊险地闪过了这一招。\n" , enemy[i]);
                             }

        me->add("force",-100);
        message_vision("\n$N使完「风云连续掌”后，由于定力不足，体内真气一时无以为继\n",me);
        me->start_busy(1);
                                                  }

}
void sp_attack(object me,object victim, object weapon,int damage)
{
 int i,j;
 if(80 > random(100)&& !me->query_temp("conti")){
message_vision(HIY"\n$N杀的兴起，眼中血光一现，有如神龙般使出连击技。\n"NOR,me,weapon);
  me->set_temp("conti",1);
  victim->start_busy(2);
  switch(random(5)){
        case 1:
                j=4;
                break;
        case 2:
                j=5;
                break;
        case 3:
                j=6;
                break;
        case 4:
                j=7;
                break;
        case 5:
                j=8;
                break;
        default:
                j=6;
                break;
     }
   for(i=0;i<j;i++)

    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

    me->delete_temp("conti");
                     }
}
