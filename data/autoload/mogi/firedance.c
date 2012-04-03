#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
int conjure(object me, object target)
{
        string msg;
fun=me->query("spells/firedance/level");
     if (!me->query("spells/firedance/level"))
     return 0;

        if( !target ) target = offensive_target(me);
        if(!me->is_fighting(target) )
        return notify_fail("Õâ·¨ÊõÖ»ÄÜ¶ÔÕ½¶·ÖĞµÄ¶ÔÊÖÊ¹ÓÃ¡£\n");

if(me->query("family/family_name")!="Ò¹ÃÎĞ¡Öş")
return notify_fail("Ö»ÓĞÎèÕß²ÅÄÜÊ¹ÓÃ¡£\n");
        if((int)me->query("atman") < 150)
                return notify_fail("ÄãµÄ·¨Á¦²»¹»£¡\n");

        if((int)me->query("gin") < 10 )
                return notify_fail("ÄãµÄ¾«ÉñÃ»ÓĞ°ì·¨ÓĞĞ§¼¯ÖĞ£¡\n");

        me->add("atman", -150);
        me->receive_damage("gin", 10);

         write("[1;32m\n            Š…ÁìÎòÁËÒ¹ÃÎÌìÎè¼°ÃÎĞş·¨¼øµÄ¾«Ëè£¬Ô¤±¸Ê©Õ¹[1;31m»ğ·ï·ÉÏè[1;32mÖ®Êõ¡£\n[0m");
         msg = HIC "\n                   $NµÄÉíÌå½¥½¥µÄ±»»ğÑæ°üÎ§£¬¶ø$NµÄÉíĞÎÒ²½¥" NOR;
         msg += HIY "\n                     ½¥µÄ»Ã»¯ÎªÒ»Ö»·ï»Ë£¬Ö»¼ûÒ»Ö»»ğ·ï»ËÑ¸ËÙµÄ" NOR;
         msg += HIG "\n                       Ïò×Å$n·ÉÈ¥£¬Áî$n²»¼°ÕĞ¼Ü¡£\n\n" NOR;
         message_vision(msg, me, target);
        if( 80 > random(100) ) {
                        write("[1;32m\n                     ½á¹û³É¹¦µÄÊ©Õ¹³ö»ğ·ï·ÉÏè¡£\n[0m");
                        say( "[1;31m                     "+target->query("name")+"ÉÁ¶ã²»¼°£¬»ëÉíÉÏÏÂ¶¼×ÅÁË»ğ£¬Í´¿àÒì³£!!\n[0m");
         target->add("kee",-(fun*9+250));
		 target->apply_condition("burn",random(15) +fun);
                        if ( fun < 100)
                          me->spell_improved("firedance",random(700));
        } else {
                write("[1;31m\n                     ½á¹ûË¿ºÁÆğ²»ÁË×÷ÓÃÁîŠ…°µ×ÔÍïÎô¡£ \n[0m");
                say( "[1;32m               Ö»¼û"+target->query("name")+"ÒÔÑ¸À×²»¼°ÑÚ¶úÖ®ËÙÉÁ¹ı¹¥»÷¡£\n[0m");
                         if (fun < 100)
                         me->spell_improved("firedance",random(700));
}

        COMBAT_D->report_status(target);

me->start_busy(1);
        return 1;
}

