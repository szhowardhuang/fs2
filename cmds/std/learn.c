// learn.c 修正 by babe

#include <ansi.h>
#include <basic_skill.h>
#include <skill.h>

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点”您什么？\n",
});

varargs int main( object me, string arg, int repeat )
{
	string skill, teacher, master,my_class;
	string record;
	mapping level;
	object ob;
	int master_skill, my_skill, gin_cost;
	int i, r = 0;

	seteuid(getuid());

        if( !arg || sscanf( lower_case(arg), "%s from %s", skill, teacher )!=2 )
                return notify_fail( "指令格式：learn <技能> from <某人>\n" );

    if( sscanf( skill, "%d %s", repeat, skill) != 2 )
		arg = skill;                                                         
	if( skill=="sun_fire_sword" ) {
		return notify_fail( "此技能只能用读的！\n" );
	}
	if( skill=="paull-steps" && me->query("class") != "dancer" && (int)(me->query_skill("paull-steps", 1))==100)
	  { return notify_fail( "你不是舞者不能再往上学了！\n" );
	}
    if( skill=="nine-steps" && me->query("class") != "poisoner" && (int)(me->query_skill("nine-steps", 1))==100)   
	  { return notify_fail( "你不是魔教徒不能再往上学了！\n" );
	}
	if( me->is_fighting() )
		return notify_fail( "临阵磨枪? 来不及啦。\n" );
	if( !( ob = present( teacher, environment(me) ) ) || !ob->is_character() )
		return notify_fail( "你要向谁求教?\n" );
     if( ob->query("make_clan") || ob->query("clan_make"))
		return notify_fail( "请勿向 clan_npc 求教, 这是bug!\n" );
	if( ob->query("no_learn")==1 )
		return notify_fail( "请勿向 clan_npc 求教, 这是bug!\n" );
	if( ob->query("master") )
		return notify_fail( ob->query("name")+"无法教你这个技能。\n" );
	if( me->query("horse")==1 || ob->query("horse")==1 )
		return notify_fail( "马不能学习。\n" );
	if( !living(ob) )
		return notify_fail( "嗯.. 你得先把" + ob->name() + "弄醒再说。\n" );
	if( wizardp(ob) )
		return notify_fail( "不能跟巫师学技能。\n" );
	if( !mapp(basic_skill[skill]) ) {
		if( !me->is_apprentice_of(ob) ) {
			if( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ||
			    (int)ob->query("family/privs") != -1)
				if( me->query("class") != ob->query("class") ||
				    !me->query("class") || !ob->query("class") ) {
					notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
					if( !(ob->recognize_apprentice(me)) )
						return 0;
				}
		}
		else
			if( me->query("class") != ob->query("class") || !me->query("class") || !ob->query("class") )
				return notify_fail(ob->query("name")+"说：\n你和我是不同的职业，恕我不能教你。\n");
	}
	if( skill == basic_skill[skill] ) {
		if( !ob->query("guild_master") && !me->is_apprentice_of(ob) )
			return notify_fail( "基本技能只能跟工会老大学,\n或是跟你的师父学。\n" );
	}
	else
		if( ob->query("family/family_name") != me->query("family/family_name") )
			return notify_fail( "特殊技能只能向同门派的人学。\n" );

	if( !me->is_apprentice_of(ob) && skill=="spiritism" )
		return notify_fail( "御魂术只能向师父求教, 或是自行修练。\n" );

 	if( !ob->query("guild_master") && !me->is_apprentice_of(ob) &&
	    !( ob->query("env/传授/all/all") || ob->query("env/传授/all/"+skill) ||
	    ob->query("env/传授/"+me->query("id")+"/all") || 
	    ob->query("env/传授/"+me->query("id")+"/"+skill) ) )
		return notify_fail( "对方看起来并不想教你这个技能！\n" );

	if( !master_skill = ob->query_skill( skill, 1 ) )
		return notify_fail( "这项技能你恐怕必须找别人学了。\n" );
	if( !SKILL_D(skill)->valid_learn(me) )
		return notify_fail( "依你目前的能力，没有办法学习这种技能。\n" );
	gin_cost = 150 / (int)ob->query("int") + 150 / (int)me->query("int");

	if( userp(ob) )
		tell_object( ob, sprintf( "%s向你请教有关「%s”的问题。\n",
			me->name(), to_chinese(skill)) );
	printf( "你向%s请教有关「%s”的疑问。\n", ob->name(), to_chinese(skill) );

	if( repeat==0 )
		repeat = 1;
    if(repeat > 500) repeat=500;

	for( i=0; i<repeat; i++ ) {
		my_skill = me->query_skill( skill, 1 );
		if( my_skill >= master_skill )
			return notify_fail( "这项技能你的程度已经不输此人了。\n" );
		if( !my_skill ) {
			gin_cost *= 2;
			me->set_skill( skill, 0 );
		}
		if( (int)me->query("learned_points") >= (int)me->query("potential") )
			return notify_fail( "你的潜能已经发挥到极限，没有办法再成长。\n" );
		if( (int)me->query("gin") > gin_cost ) {
			if( (string)SKILL_D(skill)->type()=="martial"  &&
			    ( my_skill*my_skill*my_skill/300 )*my_skill>me->query("combat_exp") )
				return notify_fail( "由于缺乏实战经验，你无法领会"+ob->name()+"的教导。\n" );
			else {
				r = 1;
				me->add( "learned_points", 1 );
				me->improve_skill( skill, random(me->query("int") + ob->query_skill(skill,1)/5) );
				/*if( random(1000) < 1 ) {
					ob->improve_skill( skill, random(ob->query("int")) );
					tell_object( ob, sprintf( HIC"在你教导%s有关「%s”的同时, 突然悟出「%s”更深一层的奥秘。\n"NOR,
							me->name(), to_chinese(skill), to_chinese(skill) ) );
				}*/
			}
			me->receive_damage( "gin", gin_cost );
		}
		else
			return notify_fail ("你今天太累了，结果什么也没有学到。\n");
	}

	if( r == 1 )
		printf( "你听了%s的指导，似乎有些心得。\n", ob->name() );

	return 1;
}

int help( object me )
{
        write(@HELP
指令格式 : learn <技能> from <某人>
指令说明 :
           这个指令可以让你向别人请教有关某一种技能的疑难问
     题，当然，你请教的对象在这项技能上的造诣必须比你高，而
     你经由这种方式学习得来的技能也不可能高于你所请教的人，
     然而因为这种学习方式相当于一种「经验的传承”，因此学习
     可以说是熟悉一种新技能最快的方法。
           通常，一个人刚学到一种新技能是不会有什么疑难问题
     的，而是经由实际上的应用中遭遇问题，这些问题对于学习一
     种新技能的过程是很重要的，尤其是各种作为其他技能基础的
     基本技能，更需要经由「发现问题─解决问题”的过程才能得
     到较好的效果。因此我们将这种发现问题的过程用「潜能”的
     观念表示，一个人能够自己发现某些问题，表示他(她)有解决
     这项问题的潜能，当你具有这样的潜能时就可以利用这个指令
     来向其他人请教，而获得进步。
           学习需要消耗一些精力，而消耗的精力跟你自己、与你
     学习对象的悟性有关。
           至于如何知道你能从对方学到什么技能，如果对方是你
     的师父，可以用 skills 指令直接查看，如果不是你的师父，
     那么通常会有其他的提示，你只好自己想办法。
其他参考 :
           practice、study
     补充说明:你可以打learn 10 技能名称 from master......
         其效果相等于learn force from master...十次.....
         可以节省系统资源........

HELP );
        return 1;
}
