//Written By AceLan 98.7.22 �û���֮��...

#include <ansi.h>

int perform(object me, object target)
{
   if( !target ) return notify_fail("��Ҫ��˭�üƣ�\n");

   if( !target->is_fighting() || !target->is_killing())
      return notify_fail("�û���֮��ֻ�ܳõ�������Σս֮ʱ�����䲻��������������\n");

   if( me->is_fighting() || me->is_killing())
      return notify_fail("�����������������ѱ��ˣ���ô�������������û����أ�\n");

   if( me->query("sen") < 20 )
      return notify_fail("��ľ������������޷��üơ�\n");

if(target->query_temp("rob")==1)
return notify_fail("ͬһ��ıֻ����һ�Σ���\n");
   if( me->query_skill("plan",1) < 30)
      return notify_fail("���ı������������\n");
// ��������
   if( me->query("family/family_name") != "����")
    return notify_fail("�������������������֣���^_^\n");
   me->add("sen",-20);
   target->start_busy(3);
  target->set_temp("rob",1);
      message_vision(HIY"$Nʹ���û���֮��, �õ�֮Σ, ����ȡ��, ����˷����͹�\n"NOR, me);
      me->fight_ob( target);
   return 1;
}