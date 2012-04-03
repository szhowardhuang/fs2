//dragon-kee.c
//������ by Dico

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;

int perform(object me, object target)
{
 int skill,funlv,siseforce,temp;

 if(me->query("force")<50+(int)query_function("dragon-kee")*5)
        return notify_fail("��������������޷�������������\n");
 if(me->query("family/family_name") != "ؤ��")
        return notify_fail("�㲻��ؤ����ӣ��޷���Ԧ����������\n");
 if((string)me->query_skill_mapped("unarmed") != "dragonfist")
        return notify_fail("��������������Ͻ�����ѧ���ɷ��ӡ�\n");
 if(me->query_temp("dragon-kee")==1)
        return notify_fail("���Ѿ������ˡ�\n");

 temp=me->query("functions/dragon-kee/level","dragon-kee");
 skill = temp;
 siseforce=me->query_skill("siseforce",1);
 funlv=(int)me->query("functions/snow-powerup/level");
 me->add("force",-(50+skill*3));
 me->set_temp("dragon-kee",1);

 if(skill < 25)
 {
  message_vision("		 $N����ϴ�辭��һ�㹦��"HIW"����"HIR"���Σ���������"HIW"����"NOR"��������ȫ����֫�ٺ�\n"
"		 $Nֻ�������ޱȣ�����ԴԴ������ӿ��\n",me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        if(skill < siseforce)
        function_improved("dragon-kee",random(skill*20)+100);
        return 1;
 } else if ( skill < 50 )
 {
  message_vision("		 $N����ϴ�辭�ڶ��㹦��"HIW"����"HIG"��ŭ����������\"HIW"����"NOR"������������ʮ����Ѩ\n"
"                $N��ʱͨ���泩���ھ�ԴԴ������ӿ��\n",me);
        me->add_temp("apply/attack",skill);
        me->add("force_factor",skill/10);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        if(skill < siseforce )
        function_improved("dragon-kee",random(skill*18)+100);
        return 1;
 } else if ( skill < 75 )
 {
  message_vision("                $N����ϴ�辭�����㹦��"HIW"����"HIY"������������"HIW"����"NOR"�������ȫ����֫�ٺ�\n"
"                $Nֻ����������������ԴԴ������ӿ��\n",me);
        me->add_temp("apply/attack",skill);
        me->add("force_factor",skill/10);
        me->add_temp("apply/defense",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        if(skill < siseforce )
        function_improved("dragon-kee",random(skill*16)+100);
        return 1;
 } else if ( skill >= 100 )
 {
  message_vision("                $N����ϴ�辭���ϳ˹���"HIW"����"HIB"��������������"HIW"����"NOR"�������������������\n"
"                $N����������Χ��ȫ��ҪѨ��������������ס\n",me);
        me->add_temp("apply/attack",skill);
        me->add("force_factor",skill/10);
        me->add_temp("apply/defense",skill);
        me->add_temp("apply/unarmed",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        if(skill < siseforce )
        function_improved("dragon-kee",random(skill*14)+100);
        return 1;
 }
}

void remove_effect(object me, int skill)
{
 me->delete_temp("dragon-kee");
 message_vision("$N��"HIC"������"NOR"��ʼ������ɢ�ˡ�\n"NOR,me);
 if(skill<25)
 {
 me->add_temp("apply/attack",-skill);
 } else if(skill<50)
 {
 me->add_temp("apply/attack",-skill);
 me->set("force_factor",10);
 } else if(skill<75)
 {
 me->add_temp("apply/attack",-skill);
 me->set("force_factor",10);
 me->add_temp("apply/defense",-skill);
 } else
 {
 me->add_temp("apply/attack",-skill);
 me->set("force_factor",10);
 me->add_temp("apply/defense",-skill);
 me->add_temp("apply/unarmed",-skill);
 }
}