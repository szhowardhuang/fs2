
// keng_kee.c

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object ob;
        string *name;

        if( !target ) target = offensive_target(me);

        if(me->query_skill("dragonfist",1) < 50 )
              return notify_fail("��Ľ�����ѧ�������죬�޷��۾���ָ\n");
if((string)me->query_skill_mapped("force")!="siseforce")
                return notify_fail("ս��ָ�������ϴ�辭�����á�\n");
         
      if(!(ob=me->query_temp("weapon"))) 
        { if(me->query_temp("secondary_weapon"))
return notify_fail("Ҫ���ֲ���ʹ��ս��ָ!!!\n");}
        if(ob=me->query_temp("weapon")) 
        {
if((string)ob->query("skill_type") != "unarmed")
return notify_fail("Ҫ���ֲ���ʹ��ս��ָ!!!!\n");

          }
          if(me->query("force")<400)
                           return notify_fail("�������������\n");
                  if(me->query("kee")<200)
                           return notify_fail("�����������\n");

        if(!me->is_fighting())  
        {
                tell_object(me,"ս��ָֻ��ս���в���ʹ�á�\n");
                return 0;
        }
        message_vision(
         HIB"$N��Ȼ�������ǣ�ʹ��������ѧ�е�"RED"��ս��ָ��"HIB"ֻ��$N��������ŭ�Σ������������$N��ָ��\n"NOR,me,target);
        {
        message_vision(
            HIW"
        $N�ͺ�һ�������ε�ָ����$n�������!!\n"
        "
        ָ���ڰ���б������γ�������$n��ȥ\n\n"




                              ��
                            ��  ��
                          ��      ��
                  �ЩЩЩ�          ��ЩЩ�
                    ��                  ��
                      ��              ��
                        ��          ��
                      ��              ��
                    ��                  ��
                  �ةةة�          ��ةة�
                          ��      ��
                            ��  ��
                              ��

                              ��
                            ����
                          ������
                  �ЩЩЩ�������ЩЩ�
                    ������������
                      ����������
                        ��������
                      ����������
                    ������������
                  �ةةة�������ةة�
                          ������
                            ����
                              ��
                              ��
                            ����
                          ������
                  �ЩЩЩ�������ЩЩ�
                    ������������
                      ����������
                        ��������
                      ����������
                    ������������
                  �ةةة�������ةة�
                          ������
                            ����
                              ��

               NOR,me,target);
            me->add("kee",-30);
             me->add("force",-(100 - ((int)me->query_skill("dragonforce",1)))*3);
        if(random(me->query_skill("unarmed")+20)>random(target->query_skill("dodge")))
        {
                message_vision(
                 HIR"\n$n��ܲ�����ָ�����У���ʱ$N���ھ���$n�����Ҵܣ�ʹ���쳣��\n"NOR,me,target);
                message_vision( NOR,me);
                  target->receive_wound("kee",me->query_skill("dragonfist",1)*3+random(me->query_skill("dragonforce",1)*2));
                COMBAT_D->report_status(target);
        }
        else
      {
                message_vision(
                HIW"$n������ָ����,ǧ��һ��һ��,�����ս��ָ������!!\n"NOR,me,target);
                message_vision( NOR,me);
       }
        message_vision(
            "��ս��ָ�������$N����ھ����˹���Ϣ���޷��ƶ�\n",me,target);
        me->start_busy(2);
        me->kill_ob(target);
          function_improved("kang_strike",random(me->query("force")/10));
        message_vision( NOR,me);
        return 1;
  }
}