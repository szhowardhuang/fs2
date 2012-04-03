
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me)
{
        int ski_value,sha_value,i,j;
        int kee_lv;
        int sword_lv;
        int swordkee_lv;


        object ob,room,*target;
        room = environment(me);
        target=me->query_enemy(room);
        i=sizeof(target);
        ski_value=random(me->query_skill("shasword",1))+query_function("sha_kee")*2;
        kee_lv=query_function("sha_kee");
        sha_value=me->query_skill("shasword",1);
        swordkee_lv=query_function("swordkee");
        sword_lv=me->query_skill("sword",1);

      if(kee_lv > 100) kee_lv=100;
      if(!me->is_fighting())
  return notify_fail("½£Ó°Á¬ÑôÎ¨ÔÚÕ½¶·ÖĞ²ÅÄÜÊ¹ÓÃ¡£\n");
      if(me->query("killyao")==1)
  return notify_fail("ÄãÎŞ·¨Ê¹ÓÃÁ¬Ñô½£\n");
    if(!me) return 1;
    if(!target) return notify_fail("Ã»µĞÈË..´òÆ¨°¢..¡£\n");
           if( me->query_skill("shasword",1) < 20 )
            return notify_fail("ÄãµÄÏÉ½£½£·¨¼¼ÇÉ²»×ã¡£\n");
         if( me->query("family/family_name") != "ÏÉ½£ÅÉ")
          {
          me->add("kee",-7000);
 log_file("/sword/swordlog",sprintf("%s(%s) Ê¹ÓÃÃ»Íò½£on %s\n",me->query("name"),me->query("id"),ctime(time())));
                    return notify_fail("[1;31mÓÉÓÚÇ¿ÔËÏÉ½£¾øÑ§....Äã±»Íò½£·´ÊÉ..[0m\n");
           }
if(me->query("class")!="swordsman")
return notify_fail("²»ÊÇ½£Ê¿²»ÄÜÓÃà¸¡£\n");
         if(me->query("force") < swordkee_lv*9+100)
             return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
        if(me->query("kee") < 500)
             return notify_fail("ÄãµÄÆø²»¹»¡£\n");
        message_vision(HIB" $N×İÉíÒ»Ô¾ ,ÌåÄÚ°µÔËÄÚ¾¢ ,ÉíÌå¸¡ÉòÓÚ°ë¿ÕÖ®ÖĞ , Í»È»¼äÖÜÎ§²İÄ¾ÓÉËÊ¶¯¶ø½¥½¥
        ½£°ÎåóÕÅ ,Ò»¸ù¸ù³ÉÎªĞîÊÆ´ı·¢µÄÀûÆ÷\n"NOR,me,target[0]);
        message_vision(HIW"\n\n         $NÖ¸³É½£×Ë´óºÈÒ»Éù   ¡®"HIY"½£Ó°Á¬Ñô ³¯ÑôÔÙÏÖ"HIW"¡¯   Ë²¼äËÄÖÜÍò½£Æë·¢..£¡\n\n\n"NOR,me,target[0]);
// ½£Æø100 ¼°sha_kee ¼ÓÇ¿ÍşÁ¦
if (kee_lv==100 && swordkee_lv==100)
{
       message_vision("[1;34m¾ÍÔÚ´ËÊ±ÒÑÓÉ$N½«Àû½£ÍùÊÖÉÏÒ»´Ì...![0m \n[1;31mÖ»¼û°µºìÉ«µÄ½£ÆøËæÑª¹â´Ü³ö..[0m \n[1;37m°ë¿ÕÖĞ»ìÔÓ×Å¸÷Ê½½£Æø..É²ÄÇ¼ä¸÷ÖÖ½£Æø×ª±ä³ÉÊıÖÖ½£Õó ...[0m \n[1;34mÖ»Ìı$N¸ßº°[1;31m½£Æø[1;37mÆÆµĞ[1;33m---¡®Ê¯ÆÆÌì¾ª¡¯![0m\n",me);
     for(j=0;j < i;j++){
        if(!target[j]) continue;

          target[j]->receive_damage("kee",(sha_value*5+kee_lv*5+sword_lv*6));
          target[j]->start_busy(1);
          target[j]->receive_wound("kee",sword_lv*10);
}
//±¾ÉíÊÜÉË
       if(me->query("quest/sun_fire_sword")==1)
          me->add("kee",-((sha_value*5+kee_lv*5+sword_lv*5)/8));
       else
          me->add("kee",-((sha_value*5+kee_lv*5+sword_lv*5)/5));
          me->start_busy(1);
          me->add("force",-kee_lv*4);
}
      else if ( ski_value <  5 ){
           me->add("force",-kee_lv);
          write(HIM"\n ²»¹ıÒ»°Ñ¶¼Ã»ÓĞÃüÖĞ ,Äãµ±³¡ĞßºìÁËÁ³½«½£ÊÕ»Ø\n"NOR);
          COMBAT_D->report_status(me);
		  say(HIM" Äã·¢ÏÖ¿ÕÖĞÂÒ½£·ÉÎè ,²»¹ı¾ÍÊÇÃ»ÓĞÃüÖĞµĞÈË ,²»½ûÖ¸×Å"+me->query("name")+"µÄ±Ç×Ó´óĞ¦\n"NOR);
          }
        else if( ski_value < 20  )
          {
          me->add("force",-kee_lv);
     for(j=0;j < i;j++){
        if(!target[j]) continue;
          target[j]->receive_damage("kee",(sha_value/2+kee_lv*2+sword_lv*2));
         COMBAT_D->report_status(target[j]);
                       }
          write (HIM" Äã·¢ÏÖ´ó²¿·ÖµÄ½£¶¼³¯µØÉÏ´òÈ¥ ,ÉõÖÁ»¹´òÏò×Ô¼º ,Äã·¢ÊÄÒªºÃºÃÁ·½£
                   ½«À´·½ÄÜÍêÈ«¼İÔ¦\n"NOR);
		  say(HIM" Äã¿´µ½¿ÕÖĞÒ»¶Ñ½£³¯ÄãÉäÀ´ ,Âè°¡¡«¿ìÉÁ..·¢ÏÖÔ­À´ÊÇ"+me->query("name")+"Õâ¸ö¼Ò»ïÔÚÎè½£\n"NOR);
          }
          else if( ski_value < 40 )
          {
           me->add("force",-kee_lv);
     for(j=0;j < i;j++){
        if(!target[j]) continue;
          target[j]->receive_damage("kee",(sha_value/2+kee_lv*2+sword_lv*2));
          COMBAT_D->report_status(target[j]);
                       }
          write (HIM" ÒÑÓĞÒ»Ğ©ÄÜ×¼È·ÃüÖĞµĞÈË ,Ê¹µÄµĞÈËÊÜ´´²»Ğ¡\n"NOR);
          say(HIM" Äã¿´¼û¿ÕÖĞÒ»Ğ©Æø½£ÈÎ"+me->query("name")+"»ÓÈ÷×ÔÈç ,ĞÄÖĞ°µ°µÇÕÅå\n"NOR);
                 }
          else if( ski_value < 60)
          {
           me->add("force",-kee_lv);
     for(j=0;j < i;j++){
        if(!target[j]) continue;
          target[j]->receive_damage("kee",(sha_value+kee_lv*3+sword_lv*3));
         COMBAT_D->report_status(target[j]);
                       }
          write(HIM"\n Ê®Ö®°Ë¾ÅµÄÆø½£³¯µĞÈË¼¤Éä¶øÈ¥ ,Ê¹µĞÈËÊÜµ½ÑÏÖØµÄ´´ÉË\n"NOR);
		  say(HIM"\n ³ÉÇ§ÉÏÍòµÄÆø½£Èº¼¯³¯Ò»Ä¿±êÉäÈ¥ ,¿´µÄÄãîªÄ¿½áÉà , °ëÉÎËµ²»³ö»°À´\n"NOR);
          }
          else
          {
          me->add("force",-kee_lv*3);

          me->start_busy(1);
//ĞÂÔöÈôenableÁ¬ÑôÆß¾÷½£·¨ÍşÁ¦¼Ó±¶
//roger 98/8/17

     for(j=0;j < i;j++){
        if(!target[j]) continue;
          target[j]->receive_damage("kee",(sha_value*3+kee_lv*4+sword_lv*4));
                       }

          write(HIY" ÔÚÄãË«ÊÖ»ÓÎèÖ®ÏÂ ,Íò½£¾ùÃüÖĞµĞÈË ,´©Ìå¶ø¹ı ,µĞÈËÍ´¿àµÄË»ºğ×Å\n"NOR);
say(HIY" Äã²»¸ÒÏàĞÅÑÛÇ°äè²ªµÄÆøÊÆ ,ÈºÌìµÄÆø½£ÑÚ¸Ç\ÁËÒ«ÑÛµÄÑô¹â ,È´·¢³öÒ»¹É
                ¸üÎªÑ¤ÀöµÄ¹âÃ¢\n"NOR);
           }

         write("\nÄãºÄ·Ñ´óÁ¿ÕæÁ¦ ,µÃĞİÏ¢Ò»»ØºÏ²ÅÄÜ¼ÌĞø¹¥»÷\n");
  while(i--) {
  if(target[i])
        message_vision(HIR"$NÃæ¶Ô´ËÇé¾³ÒÑÍêÈ«É¥Ê§ÕĞ¼ÜÄÜÁ¦ÈÎÓÉ½£ÆøÔÚÆäÉíÉÏ»®³öÎŞÊıµÄÉËºÛ£¡\n"NOR,target[i]);
          COMBAT_D->report_status(target[i]);
}
           if(kee_lv >=100) me->set("functions/sha_kee/level",100);
           else function_improved("sha_kee",random(kee_lv*5)+kee_lv*5);
        return 1;
}
