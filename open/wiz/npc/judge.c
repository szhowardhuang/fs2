//judge.c

#include <login.h>
#include <ansi.h>

inherit NPC;

int	n = 0;

void create()
{
	set_name( "冰判官", ({ "judge ice","ice","judge" }) );
	set( "long",
		"这是一位审查玩家是否为笨蛋的审判官，你必须连续答对(answer)他三个问题才能\n"
		"脱离他的魔掌。\n\n");
	set("nickname", HIB"冷血无情"NOR);
	set("title","专门对付笨蛋的审判官");
	set("gender", "男性");
	set("no_lyssa",1);
	set("age",40);
	set("no_kill",1);
	setup();
}

void init()
{
	object me;

	seteuid( geteuid (this_player()));
	me = this_player();
	me->set_temp( "old_startroom", me->query("startroom") );
	me->set( "startroom", ROBOT_CHECK );
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action( "do_answer", "answer" );
	add_action( "babe_jail", "", 1) ;
	call_out( "judge", 1, me );
}

int babe_jail() // 新增强力判断 action 防止玩家乱搞 by ACKY
{
	object ob = this_player();
	if( ((string)query_verb()=="recall") ||
		((string)query_verb() =="perform") ||
		((string)query_verb() =="practice") ||
		((string)query_verb() =="exert") ||
		((string)query_verb() =="cast") ||
		((string)query_verb() =="conjure") ||
		((string)query_verb() =="do") ||
		((string)query_verb() =="c_in") ||
		((string)query_verb() =="c_home")
		) {
		write (HIY"冰判官说道:「在这儿除了回答问题, 你还想干嘛?”\n"NOR);
		return 1;
	}
	if( ((string)query_verb()=="ct") ||
		((string)query_verb() =="tell") ||
		((string)query_verb() =="gt") ||
		((string)query_verb() =="reply") ||
		((string)query_verb() =="shout") ||
		((string)query_verb() =="war") ||
		((string)query_verb() =="dead") ||
		((string)query_verb() =="chat") ||
		((string)query_verb() =="rumor") ||
		((string)query_verb() =="music") ||
		((string)query_verb() =="chat") ||
		((string)query_verb() =="ht") ||
		((string)query_verb() =="cb") ||
		((string)query_verb() =="mud") ||
		((string)query_verb() =="es")
		) {
		write (HIY"冰判官说道:「想搬救兵? 门儿都没有!”\n"NOR);
		return 1;
	}
	return 0;
}

string color()
{
	if( ++n>7 )
		n=1;
	switch(n) {
	case 1: return HIR;
	case 2: return HIB;
	case 3: return HIY;
	case 4: return HIG;
	case 5: return HIY;
	case 6: return HIM;
	case 7: return HIW;
	}
}
// by ACKY
// 新的判定方式, 好算但尽量防止zmud
void judge( object me )
{
	int a, b, c, d, answer;
	string name, oper, tmp;

	a = random(20) + 1;
	b = random(20) + 1;
	c = random(20) + 1;
	if( b > a ) {
		d = a;
		a = b;
		b = d;
	}
	name = me->query("name") + "(" + me->query("id") + "), ";

	switch(random(5)) {
	case 0:
		tmp = random(2) ? "加" : "加上";
		answer = a + b;
		oper = chinese_number(a) + tmp + chinese_number(b) + "等于多少?";
		break;
	case 1:
		tmp = random(2) ? "加" : "加上";
		answer = a + b + c;
		oper = chinese_number(a) + tmp + chinese_number(b) + "再加" + chinese_number(c) + "等于多少?";
		break;
	case 2:
		answer = a - b;
		tmp = random(2) ? "减去" : "减掉";
		oper = chinese_number(a) + tmp + chinese_number(b)+ "等于多少?";
		break;
	case 3:
		tmp = random(2) ? "乘以" : "乘上";
		if( a * b <= 100 ) {
			answer = a * b;
			oper = chinese_number(a) + tmp + chinese_number(b)+ "等于多少?";
		} else {
			answer = (a * b) % 10;
			oper = chinese_number(a) + tmp + chinese_number(b)+ "，个位数等于多少?";
		}
		break;
	case 4:
		answer = a % b;
		oper = chinese_number(a) + "除以" + chinese_number(b)+ "余多少?";
		break;
	}
	if( random(2) )
		tell_room( environment(), HIY"冰判官问道:「" + color() + name + oper + HIY"”\n"NOR );
	else
		tell_object( me, HIY"冰判官问道:「" + color() + oper + HIY"”\n"NOR );
	call_out( "say_answer", 20+random(6), me );
	me->set_temp( "quiz/q", answer );
}

void say_answer( object me )
{
	string name, ans;

    if(!me) return ;
	ans = chinese_number( me->query_temp("quiz/q") );
	name = me->query("name") + "(" + me->query("id") + ")";

	if( !undefinedp(me->query_temp("quiz/q")) ) {
		tell_object( me, "冰判官说道:「" + name + ", 这么简单都不会? 答案等于" + ans + "。”\n" );
		if( !wizardp(me) ) {
			command( "say 「" + name + ", 你反应太慢了喔! 给我小心一点!”" );
			me->add_temp( "quiz/a", -1 );
			if( me->query_temp( "quiz/a" ) <= -5 ) {
				command( "say 「" + name + ", 你再发呆啊! 再迟钝啊! 先滚回去睡十分钟吧!”\n" );
				me->do_command( "sleep 0 10 0 0" );
			}
		}
	}
    if(me)
	if( environment(me) == environment() )
		call_out( "judge", 1, me );
}

int do_answer( string arg )
{
	string s, name;
	object me;
	int ans;

	me = this_player();
	if( undefinedp(me->query_temp("quiz/q")) )
		return notify_fail( "必须等下一题。\n" );
	notify_fail( "请回答一组数字。\n" );
	if( !arg ) return 0;

	tell_object( me, CYN"你答道: " + arg + "\n"NOR );
	name = me->query("name") + "(" + me->query("id") + ")";
	if( sscanf( arg, "%d", ans )==1 ) {
		if( ans==me->query_temp("quiz/q") ) {
			me->add_temp( "quiz/a", 1 );
			me->delete_temp("quiz/q");
			command( "say " + name + "答对了!" );
			command( "pat " + me->query("id") );
			if( me->query_temp("quiz/a") >= 3 ) {
				command( "say 「很好，"+ name + ", 你看起来不像笨蛋，你可以回家了。”\n" );
				me->delete_temp("quiz");
				me->set( "startroom", STARTROOM );
				me->move(STARTROOM);
			}
		}
		else {
			command( "say " + name + "答错了!" );
			me->add_temp( "quiz/a", -1 );
			if( me->query_temp("quiz/a") <= -5 ) {
				command( "say 「" + name + ", 你再给我乱猜啊! 笨蛋! 先滚回去睡十分钟吧!”\n" );
				if( !wizardp(me) )
					me->do_command( "sleep 0 10 0 0" );
			}
		}
	}
	else
		return 0;
	return 1;
}

void die()
{
	object ob;
	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob )
		return;
	write( HIW"冰判官冷笑道:「连我你也敢杀。”\n"NOR );
	tell_object( users(), "【"HIC"闲聊"NOR"】"HIC"冰判官(judge)说道: 心狠手辣的" + ob->query("name") + "竟敢将我杀害, 快通知 wiz 帮我报仇!\n"NOR );
}
