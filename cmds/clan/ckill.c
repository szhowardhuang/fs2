// 帮派杀手指令 by Chan 10/30/98
// 只能由阶级一、二的人使用
// 取消杀手的部份...改由所属的帮派人物自动攻击
#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me,string str )
{
  int cgold;
  object ob,killer;
  if( !sizeof(str) )
    return notify_fail( "输入格式错误!!请打help ckill\n" );
  if(!me->query("clan"))
    return 0;
  if(me->query("clan/rank") > 3)
    return notify_fail("你的阶级不够,不能使用追杀令!!!\n");
  ob=find_player(str);
  if(!ob) ob=find_living(str);
  if(!ob) ob=LOGIN_D->find_body(str);
  if(!ob)
     return notify_fail("你想追杀的人不在线上哦???\n");
	 if(wizardp(ob)) // cgy 只改自己的..?_?...by avgirl..pig..av妳改错了..反正ppl都只看我而已
     return notify_fail("你想追杀的人不在线上哦???\n");
  if(!userp(ob))
     return notify_fail("你只能追杀线上玩家哦!!!!\n");
  
  if(ob==me)
      return notify_fail("你想追杀自己呀!!!有没有搞错呀???\n");
  if( ob->query("ckill"))
    return notify_fail("他以经被追缉了。\n");
  if((me->query("clan/name")==ob->query("clan/name"))&&(me->query("clan/rank")>ob->query("clan/rank")))
    return notify_fail("你无法追杀自己的帮派老大!!\n");

    message_vision("$N发出帮派追杀令,倾所有帮派弟子全力追杀$n为\n",me,ob);
    CHANNEL_D->do_channel(me, "shout", "我"+me->query("clan/name")+"的"+me->query("clan/title")+"发出帮派追杀令,倾全帮全力追杀"+ob->query("name") +"!!" );

    ob->set("ckill",1);
    ob->set("ckill_id",me->query("clan/name"));
// ckill不收钱?!...改收钱 by avgirl 00/10/03
    CLAN_D->add_money(me->query("clan/id"),-(ob->query("combat_exp")/1000));
  return 1;
}

int help( object me )

{
    write(@HELP

格式说明:ckill <ID> 追缉指定的人 (限阶级一、二及三的人使用)
指令说明:
  这是发出帮派的追杀令并花帮派的钱请暗杀组识派杀手去追杀指定的人,暗杀组识
会根据要杀的人的经验值决定价码!!!
ps:1.被追杀的人只限玩家。
   2.被追杀的人没有安全区域,连格斗场也一样照死。
   3.被追缉的人要解除追缉只有死及被帮主赦免。
   4.替身在被追缉时有用。
   5.杀死追缉的人有钱可以拿。
   6.追缉的人可以quit。
   7.一个玩家只能由一个帮派发追缉令。
   8.只能在玩家线上时才能发出。
   9.非玩家的帮众会自动去擒杀被追杀的人。
  10.缺钱的人可以考虑去杀追缉犯有钱可以拿。
  11.who - k是表示线上被追缉的人犯。
相关指令:help cforgive
HELP
    );
 return 1;
}

