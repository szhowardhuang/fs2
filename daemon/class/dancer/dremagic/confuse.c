#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
int conjure(object me, object target)
{
        string msg;
        int k;
	fun=me->query("spells/confuse/level");
	if(fun<=35) k=1;
	if(fun>=36&&fun<=70) k=2;
	if(fun>=71) k=3;
     if (!me->query("spells/confuse/level"))
     return 0;
        if( !target ) target = offensive_target(me);

        if(!target) return notify_fail("ÄãÕÒ²»µ½µÐÈË!!\n");
        if(!me->is_fighting(target))
                return notify_fail("ÃÎ»ÃÖ®ÎèÎ¨ÔÚÕ½¶·ÖÐ²ÅÄÜÊ¹ÓÃ¡£\n");

  if( target->is_busy() )
 return notify_fail("ÄãµÄ·¨ÊõÕýÃÔ»Ã×ÅµÐÈË£¬¼ÌÐø¹¥»÷°É!\n");

if(me->query("family/family_name")!="Ò¹ÃÎÐ¡Öþ")
return notify_fail("Ö»ÓÐÎèÕß²ÅÄÜÊ¹ÓÃ¡£\n");
        if((int)me->query("atman") < 75 )
                return notify_fail("ÄãµÄ·¨Á¦²»¹»£¡\n");
        if((int)me->query("gin") < 30 )
                return notify_fail("ÄãµÄ¾«ÉñÃ»ÓÐ°ì·¨ÓÐÐ§¼¯ÖÐ£¡\n");

        me->add("atman", -70);
        me->receive_damage("gin", 10);

         write("[1;32m\n                    Š…ºöÈ»ÁìÎòÁËÒ¹ÃÎÌìÎèÖÐÃÎ»ÃÖ®ÎèµÄ¾øÑ§¡£\n[0m");
         msg = HIC "\n                     $NºöÈ»ôæÈ»ÆðÎè£¬ÑÛÇ°Ö»¼û$NÄÇÃÀÀöµÄÉíÓ°»Ã" NOR;
         msg += HIC "\n                     »¯³öÎÞÊýÃÀÃîµÄÎè²½£¬ÁîÈË¿´µÃÈç³ÕÈç×í£¬ºÃ" NOR;
         msg += HIC "\n                          ËÆÌìÏÉÏÂ·²£¬ÓÌÈçÉí´¦»ÃÃÎÖ®ÖÐ¡£\n\n" NOR;
         message_vision(msg, me, target);
if(80>random(100)) {
                        write("[1;32m\n                     ½á¹û³É¹¦µÄÊ©Õ¹³öÃÎ»ÃÖ®Îè¡£\n[0m");
                        say( "[1;35m                     "+target->query("name")+"Â¶³öÈç³ÕÈç×íµÄ±íÇé£¬Õû¸öÈËÏñÊ§ÁË»êËÆµÄ!!\n[0m");
                        target->start_busy(k);
                        me->improve_skill("dremagic", 1, 1);
                        if ( fun < 100)
                        me->spell_improved("confuse",random(1000));
                } else {
                write("[1;31m\n                     ½á¹ûË¿ºÁÆð²»ÁË×÷ÓÃÁîŠ…°µ×ÔÍïÎô¡£ \n[0m");
                say( "[1;32m                     µ«ÊÇ"+target->query("name")+"Ë¿ºÁ²»ÎªËù¶¯¡£\n[0m");
                if ( fun < 100)
                me->spell_improved("confuse",random(1000));

}

        COMBAT_D->report_status(target);
        return 1;
}

