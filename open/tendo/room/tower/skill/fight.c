#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,force,fiendforce,temp;
        force=me->query("max_force");
        fiendforce=me->query_skill("fiendforce",1);
        if( (string)me->query_skill_mapped("force")!= "fiendforce")
            return notify_fail("ĞŞÂŞ¶·ÆøÒªÓÃĞŞÂŞĞÄ·¨À´Æô¶¯¡£\n");
        if (me->query("force") < force/6)
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬²»ÄÜÔËÆğĞŞÂŞ¶·Æø¡£\n");
        if(me->query_temp("fight")==1)
            return notify_fail("ÄãÒÑ¾­ÔËÆğĞŞÂŞ¶·ÆøµÄ»¤ÉíÆø¾¢ÁË¡£\n");
        temp=me->query("functions/fight/level","fight");
        skill = temp;
        me->add("force",-force/10);
        me->set_temp("fight",1);
if (skill < 10){
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ĞŞÂŞ¶·Æø"HIW"¡¯µÚÒ»ÖØ¡¸[1;5;31mÆøÁÙÉ½ºÓ¶¯[0m"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹É°×É«µÄĞŞÂŞ¶·ÆøÖ®ÄÚ¡£¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
         me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*18)+80);
        return 1;
                       }
if (skill >= 10 && skill < 20){
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ĞŞÂŞ¶·Æø"HIW"¡¯µÚ¶şÖØ¡¸[1;5;36mÀ×¹ÄÕğÉ½´¨[0m"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹ÉÂÌÉ«µÄĞŞÂŞ¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*17)+80);
        return 1;
                       }
if (skill >= 20 && skill < 30){
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ĞŞÂŞ¶·Æø"HIW"¡¯µÚÈıÖØ¡¸[1;5;32mË®¾«ÊÆ¾øÂ×[0m"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹ÉÇàÉ«µÄĞŞÂŞ¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*16)+80);
        return 1;
                       }
if (skill >=30 && skill < 40){
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ĞŞÂŞ¶·Æø"HIW"¡¯µÚËÄÖØ¡¸[1;5;34m·çÉ³°µÒ¹ºğ[0m"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹É×ÏÉ«µÄĞŞÂŞ¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*15)+80);
        return 1;
                       }
if (skill >=40 && skill < 50){
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ĞŞÂŞ¶·Æø"HIW"¡¯µÚÎåÖØ¡¸[1;5;33m»ğ¹âÁÇÌì¸ê[0m"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹ÉºìÉ«µÄĞŞÂŞ¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*14)+80);
        return 1;
                       }
if (skill >=50 && skill < 60){
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ĞŞÂŞ¶·Æø"HIW"¡¯µÚÁùÖØ¡¸[1;5;35mÓêÄıÆÆÉ½Ê¯[0m"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹É»ÆÉ«µÄĞŞÂŞ¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*13)+80);
        return 1;
                       }
if (skill >=60 && skill <70){
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ĞŞÂŞ¶·Æø"HIW"¡¯µÚÆßÖØ¡¸[1;5;31mµç»¨ÕÕÌìºÓ[0m"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹ÉÒøÉ«µÄĞŞÂŞ¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
         me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*12)+80);
        return 1;
                       }
if (skill >=70 ){
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ĞŞÂŞ¶·Æø"HIW"¡¯"HIB"×îÖÕ°ÂÒå"HIW"¡¸[1;5;33m±ùº®‡ÜÈËĞÄ[0m"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹É½ğÉ«µÄĞŞÂŞ¶·ÆøÖ®ÄÚ¡£¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",50);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < fiendforce )
        function_improved("fight",random(skill*11)+80);
        return 1;
                       }
}

void remove_effect(object me, int skill)
{

        me->delete_temp("fight");
        me->add_temp("apply/dodge",-skill);
        me->add_temp("apply/parry",-skill);
        me->add_temp("apply/attack",-skill);
        me->add_temp("apply/defense",-50);
        message_vision("$N"HIW"¡®ĞŞÂŞ¶·Æø¡¯"NOR"ËùĞÎ³ÉµÄ»¤ÉíÆø¾¢¿ªÊ¼±ÀÀ£»ÁÉ¢ÁË¡£\n"NOR,me);
}



