// cast.c
//fix by airke

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spell, spl, trg, str;
	int number=1;
	object target;
 
	seteuid(getuid());
    if(me->is_busy())
    return notify_fail("你一时无法聚集法力。\n");
  if(me->query("mana") < 0) {
  me->set("mana",0);
tell_object(me,"没法力了用什呀?\n"); 
return 1;
  }
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("这里不准念咒文。\n");

	if( !arg )
		return notify_fail("指令格式：cast <法术> [on <目标>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("这里没有 " + trg + "。\n");
	if( !living(target) ) return notify_fail("他不是生物。\n");
	        
        } 
// 召唤术专用格式--------------- by airke
	else if( sscanf(arg, "%d %s invocation", number, str)==2 
		 || sscanf(arg, "%s invocation",str)==1) {
	       if(stringp(spell = me->query_skill_mapped("spells")) )
		 return (int)SKILL_D(spell)->cast_invocation(me, number, str);
	       return notify_fail("你请先用 enable 指令选择你要使用的咒文系。\n");
	}
//------------------------------
        else {
		spl = arg;
	if( !target = "/std/sserver"->offensive_target(me) )
			return notify_fail("你没有对象可以让你打。\n");
              
	}
	
	spl = replace_string( spl, " ", "_");
	
	if(stringp(spell = me->query_skill_mapped("spells")) )
		return (int)SKILL_D(spell)->cast_spells(me, spl, target, number);
	
		
	return notify_fail("你请先用 enable 指令选择你要使用的咒文系。\n");
}

int help (object me)
{
        write(@HELP
指令格式 : cast <咒文名称> [on <施咒对象>]
指令说明 :
           使用本命令施放法术，你必需要指定 <咒文名称>，<施咒对象>则
         可有可无。
           在你使用某一个咒文之前，你必须先用 enable  指令来指定你要
         使用的咒文系。
特别注意 :
           如果你改变自己的咒文系，你原本蓄积的法力并不能直接转换过去，
         必须从 0 开始。
HELP
        );
        return 1;
}
