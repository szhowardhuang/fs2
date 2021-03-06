// consult.c
// by airke 1998


#include <spell_from.h>
#include <spell_level.h>
#include <spell_basic.h>
#include <skill.h>

string *reject_msg = ({
  "说道：您太客气了，这怎么敢当？\n",
  "像是受宠若惊一样，说道：请教？这怎么敢当？\n",
  "笑着说道：您见笑了，我这点雕虫小技怎够资格「指点”您什么？\n",
});

varargs int main(object me, string arg)
{
  string spell, teacher,sp_from;
 
  object ob;

  seteuid(getuid());
  

  if(!arg || sscanf(lower_case(arg), "%s from %s", spell, teacher)!=2 )
    return notify_fail("指令格式：consult <法术> from <某人>\n");

  if (spell=="hellfire") return notify_fail("这个法术不能这样学喔");

  if( me->query("spells/"+spell+"/level") )
    return notify_fail("你早就会这项法术了，不必再学。\n");
  
  if( me->is_fighting() )
    return notify_fail("临阵磨枪？来不及啦。\n");

  if( !(ob = present(teacher, environment(me))) || !ob->is_character())
    return notify_fail("你要向谁求教？\n");
  
  if( !living(ob) )
    return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");
  
  if(wizardp(ob))
    return notify_fail("不能跟巫师学法术。\n");
  
  if ( !ob->query("spells/"+spell+"/level") )
    return notify_fail("对方不会这项法术，请用spells <人名> 查看。\n");
  
  if ( !spell_from[spell] )
    return notify_fail("没有这种法术!!\n");

    if ( !me->is_apprentice_of(ob) ) {
      if ((string)me->query("family/family_name") !=
	  (string)ob->query("family/family_name") ||
	  (int)ob->query("family/privs") != -1)
      {
        if(me->query("class") != ob->query("class") ||
 	  !me->query("class") || !ob->query("class") )
        {
          notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
          if( !(ob->recognize_apprentice(me)) ) return 0;
        }
      }
    }
    else {
      if( me->query("class") != ob->query("class") ||
         !me->query("class") || !ob->query("class") )
      {
  	return notify_fail(ob->query("name")+"说：\n"+
 		 "你和我是不同的职业，恕我不能教你。\n");
      }
    }
    if (!ob->query("guild_master") && !me->is_apprentice_of(ob) && 
      !(ob->query("env/传授/all/all") || ob->query("env/传授/all/"+spell) ||
       ob->query("env/传授/"+me->query("id")+"/all") || 
       ob->query("env/传授/"+me->query("id")+"/"+spell)))
    return notify_fail("对方看起来并不想教你这项法术！\n");

  
  sp_from = spell_from[spell];
  if ( me->query_skill(spell_basic[sp_from]) < spell_level[spell] )
    return notify_fail(ob->query("name")+"说道: 你的"+to_chinese(sp_from)+"知识仍嫌不足，无法领会此法精妙所在。\n");
  if (userp(ob))
    tell_object(ob, sprintf("%s向你请教有关「%s”的技巧。\n",
    	me->name(), to_chinese(spell)));
  printf("你向%s请教「%s”的技巧。\n", ob->name(), to_chinese(spell));
  printf("\n听了%s一番解说后，\n你终于领悟了「%s”施法诀窍!!\n", ob->name(),to_chinese(spell));
        
  me->set("spells/"+spell+"/level",1);
    
   
  return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : consult <法术> from <某人>
指令说明 :
           这个指令可以让你向别人请教有关某一种法术的施法技巧
     对于已对法术有相当了解的你来言，这个指令则是将你所学的法
     术知识，加以实际化的的指令，透过跟大师级的求教，你将学会
     法力的使用，而不光只是纸上谈兵而已。      
         
           至于如何知道你能从对方学到什么技能，如果对方是你
     的师父，可以用 spells 指令直接查看，如果不是你的师父，
     那么通常会有其他的提示，你只好自己想办法。
其他参考 :
           practice、study、learn、cast、conjure
HELP );
        return 1;
}
