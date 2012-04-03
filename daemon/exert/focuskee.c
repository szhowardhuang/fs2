// focuskee.c
#include <ansi.h>
int exert(object me)
{
	object weapon;
	if(me->query("class") != "blademan")
	return notify_fail("Ö»ÓĞµ¶¿Í²ÅÄÜ½«ÕæÁ¦¹àÈëµ¶Éí¡£\n");
	if(me->query("force")<me->query_skill("blade")/10+50)
	  return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if(!objectp(weapon=me->query_temp("weapon"))
	|| (string)weapon->query("skill_type")!="blade")
	  return notify_fail("ÒªÓĞµ¶²ÅÄÜÓÃ¾ÛÆøµ¶Êõ¡£\n");
	if(weapon->query_temp("focuskee")==1)
	  return notify_fail("ÄãÒÑ¾­ÔÚÓÃÁË¡£\n");
 if(me->query_temp("usebladekee"))
 return notify_fail("ÄãÒÑ¾­ÔÚÓÃÁË¡£\n");  
	me->add("force",-50-me->query_skill("blade")/10);
	message_vision(
	HIR "$N·¢³öÒ»Õó¿ñºğ£¬½«ÕæÁ¦¹áÈëÊÖÖĞµÄ[0m$n[1;31m£¬Ê¹[0m$n[1;31m·¢³öÒ»ÕóÇá±¬Éù¡£\n" NOR,me,weapon);
me->set_temp("usebladekee",1);
	me->add_temp("apply/damage",me->query_skill("force")/10+me->query_skill("blade")/5+15);
	weapon->set_temp("focuskee",1);
	me->start_call_out( (: call_other,__FILE__,"remove_effect",weapon,me :),me->query_skill("force")/2);
	return 1;
}
void remove_effect(object weapon,object me)
{
    if(!me || !weapon) return ;
	me->add_temp("apply/damage",-me->query_skill("force")/10-me->query_skill("blade")/5-15);
	weapon->delete_temp("focuskee");
 me->delete_temp("usebladekee");
message_vision("[36m$NÊÖÖĞµÄ[0m$n[36mËùÉ¢·¢³öµÄ°ÔÆøÏûÊ§ÁË¡£[0m\n",me,weapon);
}
