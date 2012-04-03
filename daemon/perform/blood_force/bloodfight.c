#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

//void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,skill1,force,bloodforce,temp;
        force=me->query("max_force");
        bloodforce=me->query_skill("blood_force",1);
        if( (string)me->query_skill_mapped("force")!= "blood_force")
            return notify_fail("ÑªÄ§¶·ÆøÒªÓÃÑªÄ§ĞÄ·¨À´Æô¶¯¡£\n");
        if (me->query("force") < force/6)
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬²»ÄÜÔËÆğÑªÄ§¶·Æø¡£\n");
        if(me->query_temp("fight")==1)
            return notify_fail("ÄãÒÑ¾­ÔËÆğÑªÄ§¶·ÆøµÄ»¤ÉíÆø¾¢ÁË¡£\n");
        temp=me->query("functions/bloodfight/level");
        skill = temp;
        me->add("force",-force/10);
        me->set_temp("bloodfight",1);
if (skill < 15){
        skill1=2*skill;
        message_vision(
        HIR "$NÔËÆğ¡®"HIM"ÑªÄ§¶·Æø"HIR"¡¯µÚÒ»²ã¡¸"HIC"ÑªÆø·½¸Õ "HIR"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹Éµ­ºìÉ«µÄÑªÄ§¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);   
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*18)+80);
        return 1;
                       }
if (skill >= 15 && skill < 30){
        skill1=1.5*skill;
        message_vision(
        HIR "$NÔËÆğ¡®"HIM"ÑªÄ§¶·Æø"HIR"¡¯µÚ¶ş²ã¡¸"HIC"ÑªÆøÁèÈË "HIR"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹É°µºìÉ«µÄÑªÄ§¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*17)+80);
        return 1;
                       }
if (skill >=30 && skill < 50){
        skill1=1.2*skill;
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ÑªÄ§¶·Æø"HIW"¡¯µÚÈı²ã¡¸"HIC"ÑªÆøÁè¿ÕÒ«ËÄ·½"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹ÉºìÉ«µÄÑªÄ§¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*15)+80);
        return 1;
                       }
if (skill >=50 && skill < 70){
        skill1=skill;
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ÑªÄ§¶·Æø"HIW"¡¯µÚËÄ²ã¡¸"HIY"Ñª°ÔËÄ·½"HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹ÉºìÉ«µÄÑªÄ§¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*14)+80);
        return 1;
                       }
if (skill >=70 && skill < 90){
        skill1=0.8*skill;
        message_vision(
        HIW "$NÔËÆğ¡®"HIM"ÑªÄ§¶·Æø"HIW"¡¯µÚÎå²ã¡¸"HIR"ÑªÈ¾¾ÅÖØÌì "HIW"¡±£¬È«ÉíËÄÖÜÁıÕÖÔÚÒ»¹ÉÁÁºìÉ«µÄÑªÄ§¶·ÆøÖ®ÄÚ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*13)+80);
        return 1;
                       }
if (skill >=90){
        skill1=0.5*skill;
        message_vision(
        HIC "$N´óºÈ£º"HIR"Ä§Íşµ´µ´Ê¥·ğ¾å£¬ÑªÎíÃÉÃÉÉñÄ§Õğ£¡£¡\n"HIC"Ëæ¼´ÔËÆğ¡®"HIR"ÑªÄ§¶·Æø"HIC"¡¯Ö®ÖÕ¼«ÍşÁ¦"HIW"¡¸"HBRED"Ä§ÑªÖÍ¿ÕÈ¾ºì³¾"NOR""HIW"¡±"HIC"£¬È«ÉíÉ¢·¢³öÎŞ±Èºì¹â£¬ËÄÖÜË²¼äÁıÕÖÔÚÒ»¹ÉËàÉ±Ö®ÆøÖ®ÖĞ¡£\n" NOR,me);
        me->add_temp("apply/dodge",skill);
        me->add_temp("apply/parry",skill);
        me->add_temp("apply/attack",skill);
         me->add_temp("apply/defense",-skill1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        if(skill < bloodforce )
        function_improved("bloodfight",random(skill*12)+80);
        return 1;
    }
   }
void remove_effect(object me,int skill,int skill1)
{
me->delete_temp("bloodfight");
me->add_temp("apply/dodge",-skill);
me->add_temp("apply/parry",-skill);
me->add_temp("apply/attack",-skill);
me->add_temp("apply/defense",skill1);
message_vision(HIW"$N¡®ÑªÄ§¶·Æø¡¯"NOR"ËùĞÎ³ÉµÄ»¤ÉíÆø¾¢¿ªÊ¼±ÀÀ£»ÁÉ¢ÁË¡£\n"NOR,me);
}


