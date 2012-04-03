#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
int skl;
int fk;
int conjure (object me, object target)
{       string msg;
fun=me->query("spells/dreamcure/level");
skl = (int)(me->query_skill("dremagic", 1));
fk=(fun+skl)/2;
if (!me->query("spells/dreamcure/level"))
     return 0;

if(me->query_temp("dreamcure")==1)
return notify_fail("ÄãÕıÔÚÊ©·¨¡£\n");
        if( (int)me->query("atman")< 80 )
                return notify_fail("ÄãµÄÁéÁ¦²»¹»¡£\n"); 
        if(me->query("class") != "dancer")
                return notify_fail("Ö»ÓĞÎèÕß²ÅÄÜÊ¹ÓÃ¡£\n");
       me->set_temp("dreamcure",1);
       if(!target)
       {
                message_vision(HIG"$NÊ¹³öÁËÃÎĞş·¨¼øÖĞµÄ"HIC"ÖÎÁÆÊõ"HIG"£¬Ö»¼ûÒ»ÕóÉñÆæ¹âÃ¢ÁıÕÕÈ«Éí¡£\n"NOR, me);
       call_out("act1",3,msg,target,me,fun,fk);
       return 1;
        }
        else{
                message_vision("[32m$NÊ¹³öÁËÃÎĞş·¨¼øÖĞµÄ[37mÖÎÁÆÊõ[32m£¬°ï$nÁÆÉËÖ»¼ûÒ»ÕóÉñÆæ¹âÃ¢ÁıÕÕ$nÈ«Éí¡£[0m\n", me, target);
                call_out("act2",3,msg,target,me,fun,fk);
                return 1;
        }

}
int act1(string msg,object target,object me,int fun,int fk) {
if(!me) return 1;
if(fk<40){
         message_vision("[32m$NÔÚÉñ¹âÁıÕÖÏÂ¸´Ô­ÁËÉÙĞí£¡[0m\n", me);
         me->receive_curing("kee", fk+150 );
}else if(fk>=41&&fk<=80){
         message_vision("[32m$NÔÚÉñ¹âÁıÕÖÏÂÃ÷ÏÔµÄºÃÁËĞí¶à£¡[0m\n", me);
         me->receive_curing("kee", fk*2+150 );
}else if(fk>=81&&fk<=99){
         message_vision("[32m$NÔÚÉñ¹âÁıÕÖÏÂÒÑ¾­È¬ÓúÁË´ó°ë£¡[0m\n", me);
         me->receive_curing("kee", fk*3+150 );
}else if(fk>=100){
         message_vision("[32m$NÔÚÉñ¹âÁıÕÖÏÂ¼¸ºõÍêÈ«µÄ¸´Ô­ÁË£¡[0m\n", me);
         me->receive_curing("kee", fk*3+250 );
}
         me->add("atman",-80);
         me->delete_temp("dreamcure");
  if(fun<100) spell_improved("dreamcure",random(1000));
         return 1;
}
int act2(string msg,object target,object me,int fun,int fk) {
         message_vision("[32m$pÔÚÉñ¹âÁıÕÖÏÂ½¥½¥µÄ¸´Ô­ÁË£¡[0m\n", me, target);
         fk = fk/2;
         target->receive_curing("kee", fk+100 );
         me->add("atman",-80);
         me->delete_temp("dreamcure");
  if(fun<100) spell_improved("dreamcure",random(1000));
         return 1;
}
