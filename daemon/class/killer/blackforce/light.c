//made by leei to test 
//ĞŞ¸ÄÏà¹ØÖ®µµ°¸ /std/char.c ÓĞ×¢Ã÷ 
//               /daemon/skill/blackforce.c  2~4ĞĞ
//               /cmds/drop.c  65~69ĞĞ
#include <ansi.h>
inherit F_FUNCTION; 
inherit F_CLEAN_UP;  
int exert(object me, object target)
{
        int fun_lv, ski_lv, x;
        ski_lv = me->query_skill("blackforce");
        fun_lv = me->query("functions/light/level",1);

        if( me->query("family/family_name") != "ºÚÑÀÁª" ) {
        tell_object(me,"Ö»ÓĞºÚÑÀÁªµÄÃÅÈË²Å¿ÉÒÔÊ¹ÓÃ¡£\n"); return 1; }
        if( ski_lv < 1 ) {
        tell_object(me,"ÄãµÄ¡®ºÚÑÀÉñ¹¦¡¯Ã»Á·µ½¼Ò¡£\n"); return 1; }
        if( me->query("force") < fun_lv+5 ) {
        tell_object(me,"ÄãµÄÄÚÁ¦²»¹»¡£\n"); return 1; }
        if( me->query("sen") < 50 ) {
        tell_object(me,"ÄãµÄÉñÖÇ×´Ì¬²»¹»¼¯ÖĞ¡£\n"); return 1; }
        if( !target ) {
        tell_object(me,"Ê¹ÓÃ¸ñÊ½ exert light <ÎïÆ·>¡£\n"); return 1; }
        if( target->query("had_light")  ) {
        tell_object(me,target->name()+"Ä¿Ç°ÒÑ±»Ê©·¨£¬²»ĞèÒªÔÙÊ©Ò»´ÎÁË¡£\n");
        return 1; }
        if( target->query("light_up") ) {
        tell_object(me,target->name()+"ÔçÒÑ¾ßÓĞÄÜÁ¿£¬²»ĞèÒªÔÙÊ©·¨ÁË¡£\n");
        return 1; }
        if( target->query("no_get") ) {
        tell_object(me,target->name()+"ÎŞ·¨½ÓÊÜÊ©·¨¡£\n"); return 1; }
        if( me->is_fighting() ) {
        tell_object(me,"Õ½¶·ÖĞÎŞ·¨Ê©Õ¹Õâ¸öÖäÊõ¡£\n"); return 1; }
        if( target->is_character() || target->is_corpse() ) {
        tell_object(me,"ÄãÖ»ÄÜ¶Ô·ÇÉúÎïÊ¹ÓÃÖäÎÄ¡£\n"); return 1; }

        me->receive_damage("sen",25); 
	message_vision(HIR"$N¼¯ÖĞ¾«Éñ£¬×¨ĞÄµØÒ÷³ªÆğ¡®"HIW"¼¤¹âÊõ"HIR"¡¯...¡£\n"NOR,me);

	if( random(ski_lv + fun_lv)  < random(fun_lv)+random(ski_lv) )
        {
        if ( ski_lv < 10 ) x=3;
        else x=ski_lv/3;

   target->add("light_up",(fun_lv*x)+(target->query_weight()/100));
   me->add("force",- (me->query("force"))/5 );  
   message_vision(HIW"\n´Ó$NÊÖÖĞÉä³öÒ»µÀÇ¿ÁÒµÄ¹âÃ¢×¢Èë$nÖĞ¡£\n"NOR,me,target);
        call_out("been_light", 3+random(fun_lv/4), me, target);
        me->start_busy(random(x)/3);
        } else {
	message_vision(YEL"\n$NÒ÷³ªÍêÖäÎÄºóÈ´ÉõÃ´ÊÂÒ²Ã»·¢Éú¡£\n"NOR,me);
        me->add("force",-fun_lv);  
        me->start_busy(random(x)/3);
        }
   function_improved("light",random(me->query("max_force",1)/3));    
        return 1;
}
int been_light(object me, object target)
{
        int fun_lv,ski_lv,weight;
        if(!target) return notify_fail("Ä¿±ê²»¼ûÁË!!\n");
        ski_lv = me->query_skill("blackforce");
        weight=target->query_weight();
        fun_lv = me->query("functions/light/level");
        if( weight < 0 ) {
   message_vision(HIY"\n$nµÄÄÜÁ¿ÒÑ¾­±»$NÕ¥¸ÉÁË¶øÏûÊ§À²¡£\n"NOR,me,target);
        destruct(target);
        } else {
   message_vision(HIY"\n$nµÄÄÜÁ¿±»$N¼¤·¢³öÀ´£¬·¢³öÇ¿ÁÒµÄ¹âÃ£¡£\n"NOR,me,target);
      if ( weight > 1000 ) {
        target->set_weight(weight-fun_lv*ski_lv/3);  }
      else { target->set_weight(weight-ski_lv*2); }
        target->set("had_light",1);
        target->set("be_light",1); 
        target->set("old_name", target->name() );
        target->set("name","[4;1m"+target->name()+"[0m");
        }
}
