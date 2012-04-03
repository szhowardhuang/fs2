#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void berserk(object me, object victim, object  weapon, int damage);
void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_att2(object me, object victim, object  weapon, int damage);
string m1="[1;37m$NÊÖÖĞ³¤½£ºçÃ¢´óÊ¢£¬¡¸½£Ó°Á¬Ñô¡±£¬Íù$nÖ±´Ì¶øÈ¥¡£\n\n[0m";
void array1();
void drunk();
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int sp_value;

string *parry_msg = ({
"\n¶ø$nÊÖÖĞµÄ³¤½£Ò»ºá£¬Ò»ÕĞ"HIB"¡®ÌúËøºá½­¡¯"NOR"ÊÆĞ®Ç§½ïÍùÇ°Ò»ÍÆÒ»ËÍ£¬µ±µÄÒ»ÉùÅö³öÁËµãµã»ğ»¨·´°Ñ$NÊÖÖĞµÄ$wÏÕĞ©Õğ·É£¡\n"NOR,
"\nµ«$n³¤½£Ò»×ª£¬Ë³×Å$NµÄ$wÒÔÒ»ÕĞ"HIC"¡®Ë³Á÷¶øÏÂ¡¯"NOR"Íù$NµÄÊÖÖ¸Ï÷È¥£¬$N´ó¾ªÊ§É«ÏÂ¼±Ã¦ÊÕÕĞ»Ø¼Ü\n",
"\n$n½£×ßÇáÁé£¬ÊÖÖĞ³¤½£ºöÏ÷ºö´ÌÒ»Á¬´®µÄ±øÆ÷×²»÷Éùºó$nÒÑ½«$NµÄ¿ìÕĞÈ«²¿»¯½â£¡\n",
HIW"\n$nÒÔ¿ìÖÆ¿ì£¬$N¿ìµ«$n¸ü¿ì£¬Á¬Ğø´Ì³öÁËÆßÆßËÄÊ®¾Å½£Ö¯³ÉÒ»µÀ½£Íø½«$NµÄÕĞÊ½¾¡Êıµ´¿ª£¡\n"NOR,    
        });

string *unarmed_parry_msg = ({
"µ«ÊÇ±»$n¸ñ¿ªÁË¡£\n",
"½á¹û±»$nµ²¿ªÁË¡£\n",
});

//½£Õó;roger¿àË¼ÈıÌìÈıÒ¹Ëù´´
//idea °æÈ¨ËùÓĞ;Ä£·Â±Ø·­Á³

void array1()
{
 object me=this_player();
 int number,i,j,m,n,hurt,mean=0,k=0,sha_mean=0,get_sha=0;
 object *partner,*target;

 partner=me->query_team();
 number=sizeof(partner);

 target=me->query_enemy();
 i=sizeof(target);
 
 for(j=0;j<number;j++){
  if(present(partner[j],environment(me)) && partner[j]->query_temp("use_form")==1)
  k=k+1;
                      }

 for(j=0;j<number;j++){
  if(partner[j]->query("get_sha_sp")==1)
  get_sha=get_sha+1;
                      }

 for(j=0;j<number;j++){
  sha_mean=sha_mean+partner[j]->query_skill("shasword",1);
                      }
  sha_mean=sha_mean/number;
 for(j=0;j<number;j++){
  mean=mean+(partner[j]->query_skill("array"));
                      }
  mean=mean/number;  

   if(k==2){
   if(random(100) > 82 && mean < 75){ 
hurt=mean*1.4*2;
message_vision("
"HIM"$NÒ»ÉùÇåĞ¥£¬ÕóĞÎÒ»×ªºÍ$nÁªÊÖÊ¹³öÒõÑôÁ½ÒÇ½£ÕóµÄ¾øÕĞ"NOR"
---[35;1m¡õ[37;1mb[35;1m¡õ[37;1m¡õ[35;1m¡õ[37;1m¡õ[35;1m¡õ[37;1m¡õ[0m---
"HIM"$N´óºÈÒ»Éù£¬½£¼âÉÁ³öÁËÒ«ÑÛ×Ï¹â£¬µĞÈËÎªÖ®Ò»Ê±ÎŞ·¨Õö¿ªÑÛ¾¦¶øÍ¬Ê±Ö»¼û$nÂú³¡ÓÎ×ß£¬¶¯×÷ÈçÏÉº×°ãÓÅÑÅÇáÁé£¬ÕóÄÚµĞÈËÒÑÔÚÍ¬Ê±È«²¿ÊÜµ½ÁËÖØ´´
\n"NOR,partner[0],partner[1]);
 for(j=0;j<i;j++){
 target[j]->receive_damage("kee",hurt);
 COMBAT_D->report_status(target[j], 1);
                 }
                                    }

   else if(random(100) > 82 && mean >= 75){
hurt=mean*1.9*2;
message_vision(HIR"
$NºÍ$nĞÄÒâÏàÍ¨£¬Ê¹³öÁËÒõÑôÁ½ÒÇÕó·¨µÄ¾«Ëè---"HIR"¡®"HIM"¶ş½£´©³¦ºì"HIR"¡¯
$NºÍ$nÍ¬Ê±×İÉíÒ»Ô¾£¬ÒÔ¼«¿ìµÄËÙ¶ÈÒÀ×ÅÕó·¨ÒÆ¶¯ÉíĞÎÉ²ÄÇ¼äÁ½ÒÇÕóÄÚºìÓ°´©Ëó£¬ÒõÖĞÓĞÑô£¬ÑôÖĞÓĞÒõ...
"NOR"½á¹ûÕóÄÚµÄµĞÈË²»ÖªÈçºÎ·ÀÓù£¬·×·×±»½£ÆøËùÉË
\n",partner[0],partner[1]);
 for(j=0;j<i;j++){
 target[j]->receive_damage("kee",hurt);
 COMBAT_D->report_status(target[j], 1);
                 }
                                          }

   else if(random(100) > 80){
message_vision(HIG"$NºÍ$n²»Í£µÄÒÆĞĞ»»Î»£¬Òõ±äÑô£¬Ñô×ªÒõ£¬Ê¹µĞÈË¿´µÃÑÛ»¨ÁÃÂÒ\n"NOR,partner[m],partner[m+1]);
                            }
}

   else if(k==3){
  if(random(100) > 82){
   if(mean >= 75 && get_sha==3){
hurt=mean*2.2*3;//ÈıÈË½ÔÓĞºóÈı && sha-array Æ½¾ù´óÓÚ75 ËùÒÔÍşÁ¦ÉÏµ÷
message_vision(HIY"
ÕóÄÚÈı²ÅºöÈ»ĞÄÒâÏàÍ¨£¬²»Ô¼¶øÍ¬¸÷Ê¹³öÏÉ½£ºóÈıÊ½ÖĞµÄÒ»ÕĞ£¬ÈÚºÏ³É´Ë¿õÊÀ¾øÕĞ
"HIW"------"HIY"ÏÉ½£ºóÈıºÏÒ»Ê½"HIW"------\n
$NÊ¹³öÏÉ½£ºóÈıÊ½Ö®µÚÒ»ÕĞ
----[1;36m¡õ[1;34mB[1;36m¡õ[1;34mY[1;36m¡õ[1;34mH[1;36m¡õ[1;34m¡õ[0m"HIW"---                
$NÒÔÆøĞĞ½£,Ë²Ê±¼äÒ»¹Éº®ÆøÁıÕÖÉíÅÔ,Ö»¼û½£ÉÏ±¡±ù½¥Æğ»Ã³É±ùÖù,$NÊÖÖĞ³¤½£ºáÉ¨,Ö»¼û±ùÖùËæ½£Æø³¯µĞÈËÃÍÁÑ´ÌÈ¥
µĞÈËË²¼ä±»´ÌÉË¶à´¦...\n",partner[0]);
message_vision("
$NÊ¹³öÏÉ½£ºóÈıÊ½Ö®µÚ¶şÕĞ
----[1;35m¡õ[1;31mU[1;35m¡õ[1;31mV[1;35m¡õ[1;31mi[1;35m¡õ[1;31mi[0m"HIW"---
$NÊÖÖĞ³¤½£¼±Ê¹,ÓúÊ¹Óú¿ì,ÍğÈôĞÚÓ¿¾ŞÀËÏòµĞÈËÖ±³å¶øÈ¥,Ë²Ê±Ñ¹Á¦åáÔö,
µĞÈË±»¾ŞÀËÕğ³öÄÚÉË,ÏÊÑª¿ñÅç....\n",partner[1]);
message_vision("
$NÊ¹³öÏÉ½£ºóÈıÊ½Ö®µÚÈıÕĞ
----[1;32m¡õ[1;33m¡õ[1;32m¡õ[1;33m¡õ[1;32m¡õ[1;33mi[1;32m¡õ[1;33m¡õ[0m"HIW"---                             
$N³¤½£·ÉÎè,ö®Ê±ËÄÖÜË®²¨ÔÆÆø±ä»¯ÍòÇ§ÄÑÒÔÔ¤ÁÏ,µĞÈËË²¼ä·Ö²»Çå½£ÔÚºÎ·½
ÕıÔÚ³ÙÒÉÖ®¼Ê,.½£ÒÑ´©Ìå¶ø³ö....\n
"HIY"ÈıÕĞºÏÒ»µÄÍşÊÆ¾ªÈË£¬Ò»¹ÉÇ¿´óµÄ½£ÆøÔÚÕóÄÚ³å×²£¬µĞÈË·ÇËÀ¼´ÉË\n"NOR,partner[2]);
 for(j=0;j<i;j++){
 target[j]->receive_damage("kee",hurt);
 COMBAT_D->report_status(target[j], 1);
                 }
                   }

   else { 
hurt=mean*1.5*3;
message_vision(HIY"
Èı²Å½£ÕóÄÚÏé¹âÒşÒş£¬½£Õó¾øÕĞ"HIW"¡®"HIY"ÁÛ¹âÈı½£"HIW"¡¯"HIY"ÒÀÈı²ÅÌØĞÔÖ®ÆøÌÚ³ö£¡
$NÒıµ¼ÈıÖÖÏé¹âÔÚÕóÄÚÁ÷×ª£¬çÍ·×¶áÄ¿£¬ÉËÈËÓÚìÅÀöÖ®ÖĞ......
\n"NOR,partner[0]);
 for(j=0;j<i;j++){
 target[j]->receive_damage("kee",hurt);
 COMBAT_D->report_status(target[j], 1);
                 }
        }
                                 }

   else if(random(100) > 80){
message_vision(HIY"$NÖ¸»ÓÈô¶¨£¬ÌìµØÈËÈıÎ»ÅäºÏÒ»Ìå·ÀÊØµÃ¹ÌÈô½ğÌÀ\n"NOR,partner[0]);
                            }
}

   else if(k==4){
  if(random(100) > 79){
   if(mean >= 75 && sha_mean >= 95){
//¿õÊÀ¾øÕĞ£¬ËÄÈË½ÔÒªÓĞË«Ê®²ÅĞĞ£¬ºÜ»³ÒÉÄÜ²»ÄÜÓĞ»ú»áÓÃ...
hurt=mean*3.1*4;
message_vision(HIB"
ÕóÄÚËÄÈËĞÄÒâºöÈ»¶ÙÎò£¬¾ö¶¨ÒÔÉíÒ»ÊÔÆÚÍûÄÜÈÚºÏ³ö¿õÊÀ¾øÕĞ"HIY"¡®"HIB"ËÄÁú±ÀÔÂ"HIY"¡¯"HIB"!!!
\n"HIW"Ö»¼ûÕóÄÚËÄÈËÍ¬Ê±ÑöÌì³¤Ğ¥ ,Ò»ÆëÊ¹³öÏÉ½£ÖÁ¼«Ö®ÕĞ"HIR"¡® Ë«¡«Ê®¡«Ğı¡«Áú¡«Õ¶ ¡¯"HIB"!!!
\n"HIB"ËÄÌõÇàÁú´ÓËÄ¸öÈËµÄ½£¼â³å³ö£¬ÔÚ¿ÕÖĞ²»Í£µØ¾ÛºÏÅÌĞı£¬É²ÄÇ¼ä!!!ÌìµØ±äÉ«£¬
·çÆğÔÆÓ¿¡£Ò»ÂÖ"HIY"Ã÷ÔÂ"HIB"ÔÚÁúÔÆÖ®¼äÏÖĞÎ£¬¶øµĞÈËÒ²±»´ËÇé¾°ËùÕğÉå£¬Ò»Ë²¼äÒÑ
±»ÍÌÃ»ÓÚ¹âÃ¢Ö®ÖĞ¡£\n\n"NOR,partner[0]);

 for(j=0;j<i;j++){
 target[j]->receive_damage("kee",hurt);
 target[j]->start_busy(1);
 COMBAT_D->report_status(target[j], 1);
                 }
                   }

   else { 
hurt=mean*1.7*4;
message_vision(HIC"
ÖÚ½£Ê¿ºöÈ»ËÄ½£Æë³ö£¬Ê¹³öËÄÏóè¯ß´½£ÕóµÄ¾øÕĞ"HIB"¡®"HIC"ËÄ½£°Ë´ï"HIB"¡¯"HIC"£¬ì¬ì¬ÉùÏì´¦Á½½£Ö±Ö¸
µĞÈËµÄĞØÇ°£¬Í¬Ê±ÁíÁ½½£´Ó×óÓÒ·Ö´Ì¡£µ±µĞÈËÏëÓèÒÔÕĞ¼ÜÊ±ËÄ½£ÓÖÍ¬Ê±·Ö»÷ºÏ´Ì£¬Íş
Á¦ÊµÔÚ¾ªÈË!
\n"NOR,partner[0]);
 for(j=0;j<i;j++){
 target[j]->receive_damage("kee",hurt);
 target[j]->start_busy(1);
 COMBAT_D->report_status(target[j], 1);
                 }
        }
                                 }

   else if(random(100) > 80){
message_vision(HIB"$NÒÔÈ«Á¦ÔË×ªËÄÏóè¯ß´Õó£¬½«µĞÈËÀÎÀÎµÄÀ§ÔÚÕóÖĞ\n"NOR,partner[0]);
                            }
}

//°ËÈËÕó¼«ÄÑ×é³É£¬Ğè°Ë¸öÏÉ½£¸ßÊÖ£¬Ö÷ÕóÕßÒàĞèÉñ200 and sha-array >=80
//so ÍşÁ¦¼ÓÇ¿
   else if(k==8){
   if(random(100) >= 75){
message_vision(HIG"\n$NÑöÌì³¤Ğ¥£¬´ß¶¯°ËØÔÓÎÁúÕóÊ¹³ö¾ªÊÀº§Ë×µÄÏÉ½£½£ÕóÖÁ¼«¾øÕĞ

                     "HIW"¡®"HIR"¡«½û¡«¶Ï¡«Á¬¡«Ñô¡«Æß¡«¾÷¡«Õ¶"HIW"¡¯"NOR"

"HIR"´ËÕĞÒ»³ö£¬¾ªÌì¶¯µØ£¬´«Ëµ×ÔÏÉ½£´´ÅÉÒÔÀ´´ÓÎ´±»Ê¹ÓÃ¹ı!!\n",partner[0]);
message_vision(sprintf(HIB"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÒ»Ê½"HIW"¡®"HIB"ÁÒÑô"HIW"¡¯"HIB"!!\n"NOR ),partner[1]); 
message_vision(sprintf(HIR"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚ¶şÊ½"HIW"¡®"HIR"²ĞÑô"HIW"¡¯"HIR"!!\n"NOR ),partner[2]);
message_vision(sprintf(HIW"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÈıÊ½"HIW"¡®ÑŞÑô¡¯!!\n"NOR),partner[3]); 
message_vision(sprintf(HIM"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚËÄÊ½"HIW"¡®"HIM"Å¯Ñô"HIW"¡¯"HIM"!!\n"NOR),partner[4]);   
message_vision(sprintf(HIC"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÎåÊ½"HIW"¡®"HIC"¶¬Ñô"HIW"¡¯"HIC"!!\n"NOR),partner[5]);
message_vision(sprintf(HIG"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÁùÊ½"HIW"¡®"HIG"³¯Ñô"HIW"¡¯"HIG"!!\n"NOR),partner[6]); 
message_vision(sprintf(HIY"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÆßÊ½"HIW"¡®"HIY"Ï¦Ñô"HIW"¡¯"HIY"!!\n"NOR), partner[7]);
message_vision(HIW"\nÆßµÀ½£ºçÍ¬Ê±¼¤¿Õ¶ø³ö£¬¡¸ÆßÑôÁ¬Ìì¡±ÔÚ¿ÕÖĞÖ¯³ÉÒ»µÀºçÍø£¡
"HIG"¶øÖ÷ÕóµÄ$N×İÉíÒ»Ô¾£¬ÄıÆø×¼±¸·¢³ö×îºóÒ»Ê½ÒÔÍê³ÉÕâ¾ªÌìµØ¶¯µÄÒ»»÷£¡\n"NOR,partner[0]);
message_vision(sprintf(HIW"\nÖ»¼û$N¿ñĞÔÖèÆğ ,´óºÈÒ»Éù¡®"HIR"½£Ó°Á¬Ñô£¬ÆßÑôÁ¬Ìì¡¯!!\n"NOR),partner[0]);
message_vision(HIW"$NµÄÆßÑôÁ¬ÌìÆøÊÆÅìíç£¬¼¤·¢ÁËÏÈÇ°ÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÄÆß¹É¸ÕÈá²»µÈµÄ½£ºç£¬Ö»¼ûºçÆøĞ¥Ìì£¬ÂúÌì½£Ó°£¬ÕóÄÚµĞÈËÈ«¶¼ÊÜµ½ÁËÖØ´´\n"NOR,partner[0]);

 for(j=0;j<i;j++){
 target[j]->receive_damage("kee",800);
 target[j]->start_busy(2);
 COMBAT_D->report_status(target[j], 1);
                 }
                      }
   else if(random(100) > 60){
message_vision(HIM"$NÖ¸»Ó°ËØÔÓÎÁúÕóÄÚµÄ½£Ê¿²»Í£µØÒÆĞĞ»»Î»£¬ÆøÊÆÍòÇ§£¡\n"NOR,partner[0]);
                            } 
}

}
//½£Õó;roger¿àË¼ÈıÌìÈıÒ¹Ëù´´
//idea °æÈ¨ËùÓĞ;Ä£·Â±Ø·­Á³:P

void drunk()
{
 object me=this_player();
 int number,i,j,me_lv,tar_lv;
 object *target;
 target=me->query_enemy();
 i=sizeof(target);
 j=random(i);
 me_lv=me->query_skill("dodge");
 me_lv*=1.3;
 tar_lv=target[j]->query_skill("dodge");
 if(me->query_skill("shasword",1) > 70&&me->query_skill("sha-steps",1)>50&&!me->query_temp("conti",1))
{
 message_vision("\n$N×íÒ÷µÀ£º
[37;1m   ¡®Óù½£³Ë·çÀ´£¬³ıÄ§ÌìµØ¼ä¡£ÓĞ¾ÆÀÖåĞÒ££¬ÎŞ¾ÆÎÒÒàµß¡£
     Ò»Òû¾¡½­ºÓ£¬ÔÙÒûÍÌÈÕÔÂ¡£Ç§±­×í²»µ¹£¬Î¨ÎÒ"HIR+me->query("name")+HIW"¡¯
Ê¹³öÒ»ÕĞ[37;1m¡®[31;1mºá×íÇ§Çï[37;1m¡¯[0m£¬³Ë×Å¾ÆÒâ½«ÏÉ½£½£Êõ·¢»ÓµÃÁÜÀì¾¡ÖÂ\n",me);
     if(me_lv > tar_lv){
 message_vision("\n$NÉÁ±Ü²»¼°£¬±»ÕâÕĞµ±ĞØ´ÌÖĞ\n",target[j]);
 target[j]->receive_damage("kee",250);
 COMBAT_D->report_status(target[j]);
 me->add("force",-30);
                       }
 else message_vision("\n$N×İÉíÔ¾Æğ£¬¼°Ê±ÉÁ¹ıÁËÕâÒ»ÕĞ\n",target[j]);                                                    
}                                         
}                                                                                               


mapping *action = ({
//1
        ([      
                "action"     :               "$NÊÖÄó½£¾÷£¬³¤½£Ò»Í¦£¬Ê¹³öÒ»ÕĞ"HIC"¡®ÈªÃùÜ½ÈØ¡¯"NOR"£¬×ËÌ¬ÓÆÑÅ£¬ÆÄÓĞÌìÉÏÏÉÈËÏÂ·²¼äÖ®Òâ",
                "dodge"      :               -10,
                "parry"      :               -10,
                "damage"     :                40,
                "force"      :                40,
                "damage_type":               "´ÌÉË"
        ]),
//2
        ([     
                "action"     :               "$NÒ»¸öĞıÉí£¬ÊÖÖĞµÄ$wÔÚ¿ÕÖĞÉÁ¹ıÒ»µÀ¹âÃ¢Ö±´ÌÏò$nµÄ$l£¬×ËÌ¬äìÈ÷Ò»ÆøºÇ³É£¬ÕıÊÇÒ»ÕĞ"HIY"¡®½ğÑãºá¿Õ¡¯"NOR,
                "dodge"      :                0,
                "parry"      :                0,
                "damage"     :                80,
                "force"      :                80,
                "damage_type":               "´ÌÉË"
        ]),
//3
        ([   
                "action"     :               "$N×ó¼çÎ¢³Á£¬×óÊÖ½£¾÷Ğ±Òı£¬ÓÒÖâÒ»Ëõ£¬Ê¹³öÒ»ÕĞ"HIM"¡®ÓĞ·ïÀ´ÒÇ¡¯"NOR"½£ÊÆÑ¸ËÙÁèÀ÷Ö±Íù$nµÄ$l´ÌÈ¥",
                "dodge"      :                10,
                "parry"      :                10,
                "damage"     :                100,
                "force"      :                100,
                "damage_type":               "´ÌÉË"
        ]),
//4
        ([  
                "action"     :               "$N½£ÊÆÒ»¸ÄÍù³£µÄÆ®Òİ¾øÂ×£¬Ê¹³öÒ»ÕĞ"HIW"¡®"HIY"ÓñËéÏÉ¸Ô"HIW"¡¯"NOR"Ö±Ï÷ºáÅü¡¢ÆøÊÆÍşÃÍµÄÍù$nÉíÉÏ´óÁ¦Õ¶È¥",
                "dodge"      :                20,
                "parry"      :                20,
                "damage"     :                150,
                "force"      :                150,
                "damage_type":               "¸îÉË"
        ]),
//5
        ([ 
                "action"     :               "$N½£ÊÆ´ó¿ª´óãØ£¬Ê¹³öÒ»ÕĞ"HIC"¡®ÅüÖñÉ¨Ó°¡¯"NOR"¿ñ·ç±©Óê°ãµÄÕĞÊ½Ê¹$n¸Ğµ½ÄÑÒÔÕĞ¼Ü",
                "dodge"      :                30,
                "parry"      :                30,
                "damage"     :                170,
                "force"      :                170,
                "damage_type":               "¸îÉË"
        ]),
//6
        ([
                "action"     :               "$N½£¼âÁ¬»®³ö¼¸¸ö½£»¨£¬Ò»ÕĞ"HIW"¡®Æ®ÔÆ´©Ñ©¡¯"NOR"Èç¸¡ÔÆ°ãÆ®Òİ£¬»¯³ÉÆ¬Æ¬°×Ñ©»º»ºÂäÓÚ$nµÄÉíÉÏ",
                "dodge"      :                30,
                "parry"      :                20,
                "damage"     :                200,
                "force"      :                200,
                "damage_type":               "´ÌÉË"
        ]),
//7
         ([     "action"     :               "$N½«ÊÖÖĞµÄ$wĞ±Òı£¬Ê¹³öÒ»ÕĞ"HIW"¡®ÇÍ±Ú¶ÏÔÆ¡¯"NOR"£¬½£ÊÆĞÛÎ°¾«ÆæÆøÊÆ×İºáÊ¹$n¸Ğµ½×óÖ§ÓÒ×¾ÄÑÒÔÕĞ¼Ü",
                "parry"      :                30,
                "dodge"      :                40,
                "damage"     :                220,
                "force"      :                220,
                "damage_type":                "¸îÉË",
           ]),
//8
          ([    "action"     :               "$NÕæÆø¹àÓÚÊÖÖĞµÄ$w£¬Ê¹³öÒ»ÕĞ"HIR"¡®·Éºçºá½­¡¯"NOR"¶ÙÊ±½£¼â³å³ö°ë³ßÀ´³¤µÄºìÉ«½£Ã¢£¬ÍÌÍÂÉÁË¸£¬àÍàÍÉùÏì´¦Íù$n¼²´Ì¶øÈ¥",
                "parry"      :                30,
                "dodge"      :                40,
                "damage"     :		      240,
                "force"      :                240,
                "post_action":                (: berserk :),
                "damage_type":                "¸îÉË",
            ]),
//9
            ([  "action"     :                "$NÊÖÖĞµÄ$wÒ»ÉÁ³öÇÊ£¬º®Ã¢ÍÌÍÂ£¬µçÉÁĞÇË¸£¬Ò»ÕĞ"HIB"¡®º®Ã¢³åÏö¡¯"NOR"½£Æø»¯³Éµãµãº®Ã¢Íù$nÉíÉÏ·ÉÈ¥",
                "dodge"      :                50,
                "parry"      :                30,
                "damage"     :                260,
                "force"      :                260,
                "post_action":                (: berserk :),
                "damage_type":                "´ÌÉË",
             ]),
//10
            ([  "action"     :                "$NÒ»ÉùÇåĞ¥£¬ÊÖÖĞ³¤½£¶¶¶¯´¦ÊıÒÔ°Ù¼ÆµÄÓñÉ«¹âÃ¢´Ó$NµÄ½£¼â¼²·É¶ø³ö£¬²ÓÀÃÈçÒøºÓ·É½¦£¬ÕıÊÇÒ»ÕĞ"HIW"¡®"HIY"¾¡ÇãÒøºÓ"HIW"¡¯"NOR"£¡",
                "dodge"      :                60,
                "parry"      :                30,
                "damage"     :                280,
                "force"      :                280,               
                "damage_type":                "´ÌÉË",
             ]),
//11
             ([ "action"     :                "$NÊ¹³öÏÉ½£ÅÉÖ®¾øÕĞ"HIG"¡®¸ôÖ½¶ÏÊ÷¡¯"NOR"£¬ÊÖÖĞµÄ$wĞé»®£¬$nãµÈ»²»Ã÷ËùÒÔÖ®¼Ê²»Öª×Ô¼º½îÂöÒÑ±»Õ¶¶Ï...",
                "dodge"      :                60,
                "parry"      :                40,
                "damage"     :                300,
                "force"      :                300,
                "post_action":                (: berserk :),
                "damage_type":                "½îÂö¾¡¶Ï",
             ]),
//12
             ([ "action"     :                "$N½£·ºÏÉÆø£¬¾Û¾«»áÉñµØÊ¹³öÁËÏÉ½£½£ÊõÖĞµÄ×î¸ß¾³½ç"HIY"¡®ÏÉÇãËªÌì¡¯"NOR"£¡½£ÓÉÏÉ»¯£¬Ê¹½£ÈôÏÉ£¬½ğ¹âÉÁÒ«ÏÂ$nÈ«ÉíÒÑ±»¸îÉË¶à´¦...",
                "parry"      :                40,
                "dodge"      :                70,
                "damage"     :                300,
                "force"      :                300,               
                "damage_type":                "ĞÄ½£Ö®ÉË",
             ]),
             ([ "action"     :                "$NÊ¹³öÏÉ½£ºóÈıÊ½Ö®µÚÒ»ÕĞ\n"+
                                              "----[1;36m¡õ[1;34mB[1;36m¡õ[1;34mY[1;36m¡õ[1;34mH[1;36m¡õ[1;34m¡õ[0m---\n"+                
                                              "$NÒÔÆøĞĞ½£,Ë²Ê±¼äÒ»¹Éº®ÆøÁıÕÖÉíÅÔ,Ö»¼û½£ÉÏ±¡±ù½¥Æğ»Ã³É±ùÖù,$NÊÖÖĞ³¤½£ºáÉ¨,Ö»¼û±ùÖùËæ½£Æø³¯$nÃÍÁÑ´ÌÈ¥\n"+
                                              "$nË²¼ä±»´ÌÉË¶à´¦...\n",
                 "dodge"     :                50,
                 "parry"     :                80,
                 "damage"    :                400,
                 "force"     :                400,
                 "post_action":               (: sp_attack0 :),
                 "damage_type":               "´ÌÉË",
                ]),
             ([ "action"     :                 "$NÊ¹³öÏÉ½£ºóÈıÊ½Ö®µÚ¶şÕĞ\n"+
                                               "----[1;35m¡õ[1;31mU[1;35m¡õ[1;31mV[1;35m¡õ[1;31mi[1;35m¡õ[1;31mi[0m---\n"+
                                               "$NÊÖÖĞ³¤½£¼±Ê¹,ÓúÊ¹Óú¿ì,ÍğÈôĞÚÓ¿¾ŞÀËÏò$nÖ±³å¶øÈ¥,Ë²Ê±Ñ¹Á¦åáÔö,\n"+
                                               "$n±»¾ŞÀËÕğ³öÄÚÉË,ÏÊÑª¿ñÅç....\n",
                                                   
                "dodge"      :                 50,
                "parry"      :                 80,
                "damage"     :                 400,
                "force"      :                 400,
                "post_action":               (: sp_attack1 :),
                "damage_type":               "¿³ÉË",
                                    
                 ]),
                   
              ([ "action"     :               "$NÊ¹³öÏÉ½£ºóÈıÊ½Ö®µÚÈıÕĞ\n"+
                                              "----[1;32m¡õ[1;33m¡õ[1;32m¡õ[1;33m¡õ[1;32m¡õ[1;33mi[1;32m¡õ[1;33m¡õ[0m---\n"+                              
                                              "$N³¤½£·ÉÎè,ö®Ê±ËÄÖÜË®²¨ÔÆÆø±ä»¯ÍòÇ§ÄÑÒÔÔ¤ÁÏ,$nË²¼ä·Ö²»Çå½£ÔÚºÎ·½\n"+
                                              ",ÕıÔÚ³ÙÒÉÖ®¼Ê,.½£ÒÑ´©Ìå¶ø³ö....\n",
 
              "dodge"      :                 50,
              "parry"      :                 80,
              "damage"     :                 400,
              "force"      :                 400,
              "post_action":               (: sp_att2 :),
              "damage_type":               "¿³ÉË",
                                                                                
              ]),
//16
            ([  "action"     :                "\n$NµÍÒ÷µÀ£º
               [32;1m¡®[37;1mÕ¶·ç½ØÑ©ÆÆÇ§Çï               ³õ¶¬Îè³¾Ò»³¯³ğ 
                 Ğ¦ÈÎÇàÌì×İºÀÇé               ½£¿ñÇé¿ñÈË¸ü¿ñ[32;1m¡¯[0m
Ò÷°ÕÎè½£¶øÆğ£¬Ê¹³öÁËÏÉ½£ÅÉµÄÉ±ÕĞ[37;1m¡®[32;1m¡õ[37;1m¡õ[32;1m¡õ[37;1mi[32;1m¡õ[37;1m¡õ[32;1m¡õ[37;1m¡õ[32;1m¡õ[37;1mM¡¯£¡
[32;1mÕĞÈçÆäÃû£¬ÔÚ$N³¤½£Îè¶¯ÏÂ±ÌÂÌ½£Æø×İºáÍğÈçÕóÕó²¨ÌÎ£¬È´ÑÚ²»×¡°µ²ØÆäÖĞµÄÉ±Òâ[0m",
                "dodge"      :                60,
                "parry"      :                50,
                "damage"     :                320,
                "force"      :                320,
                "post_action":               (: berserk :),
                "damage_type":                "¸îÉË",
             ]),
//17                      
            ([  "action"     :                "\n$N»Ø½£ÈëÇÊ£¬»º»ºËµµÀ£º
              [37;1m¡®[31;1mÒ»ÏôÒ»½£Æ½ÉúÒâ               ¸º¾¡¿ñÃûÉ±ÎŞÇé[37;1m¡¯[0m
Ëµ°ÕÑÛÖĞÉ±Òâ¶¸Ê¢£¬°Î½£³öÇÊ£¬Ê¹³öÁËÏÉ½£ÅÉ½ûÕĞ[37;1m¡®[31;1m¡õ[37;1m¡õ[31;1m¡õ[37;1m¡õ[31;1m¡õ[37;1m¡õ[31;1m¡õ[37;1m¡õ[31;1m¡õ[37;1m¡õ[37;1m¡¯£¡
[31;1m$NÑ¸ËÙµØ»Ó¶¯ÊÖÖĞµÄ$w[31;1m£¬Ö»¼ûÂúÌìÑªºìÍğÈôÂäÈÕµÄÓàêÍ£¬È´Ô­À´ÊÇ$n±»É±ÕĞËùÉË£¬ÂúÉíÏÊÑª·ÉÑïÓÚ¿ÕÖĞ£¡[0m",
                "dodge"      :                60,
                "parry"      :                50,
                "damage"     :                340,
                "force"      :                340,
                "post_action":               (: berserk :),
                "damage_type":                "¸îÉË",
             ]),
//18
            ([  "action"     :                "$NÃ¼Í·½ôËø£¬³îÉÏĞÄÍ·²»½ûÑöÌì³¤Ì¾Ò»Éù£¬Ê¹³öÁË[37;1m¡®[32;1m¡õ[33;1m¡õ[32;1m¡õ[33;1mN[32;1m¡õ[33;1mT[32;1m¡õ[33;1mL[32;1m¡õ[33;1m¡õ[37;1m¡¯
"HIG"$N°Î½£³öÇÊ£¬Çï·çìªìª£¬ÊÖÖĞµÄ$w"HIG"ÔÚ$nµÄËÄÖÜ»¯ÎªÆ¬Æ¬ÂäÒ¶£¬Ë²Ê±¼ä$nÒÑ±»¸îÉË¶à´¦..."NOR,
                "dodge"      :                60,
                "parry"      :                50,
                "damage"     :                360,
                "force"      :                360,
                "damage_type":                "¸îÉË",
             ]),             
//19 
            ([  "action"     :                "$NĞÄÖĞÅ­Òâ¼±Éı£¬¾ö¶¨Ê¹³öÏÉ½£ÅÉÖ®½ûÕĞ---[33;1m¡®[33;1m¡õ[37;1m¡õ[33;1m¡õ[37;1mF[33;1m¡õ[37;1m¡õ[33;1m¡õ[37;1m¡õ[33;1m¡õ[37;1m¡õ[33;1m¡¯£¡
$NÔË½£Èç·ç£¬½£Æø×İºá¼¤ÆğµØÃæ¹ö¹ö³¾É³£¬ÍğÈôÇ§¾üÍòÂí³Û³Ò°ãÍù$n±©»÷¶øÈ¥"NOR,
                "dodge"      :                60,
                "parry"      :                50,
                "damage"     :                380,
                "force"      :                380,
                "post_action":               (: berserk :),
                "damage_type":                "¸îÉË",
             ]),      
//20
            ([  "action"     :                "$NÍ»¸ĞĞÄÖĞÖ®±¯Òâ£¬İëÈ»Ê¹³öÁË[37;1m¡®[34;1m¡õ[37;1mH[34;1m¡õ[37;1m][34;1m¡õ[37;1mt[34;1m¡õ[37;1mP[34;1m¡õ[37;1mY¡¯£¡
"HIW"$N×İÉí¶øÆğ£¬Ò»¸öµ¹Ñö¾¹´Ó¿ÕÖĞÏò$nµ¹´Ì¶øÏÂ£¬´ËÕĞÈ«È»²»¹Ë¼ºÉí¿É¼ûÊ©Õ¹Ö®ÈËĞÄÖĞÖ®±¯Òâ¼°É±ÒâÊµÒÑµ½´ïµÄ¼«µã¡£¶ø$n¿´µ½´ËÕĞÈç´ËÊ©Õ¹¾¹ÏÅµÃÃæÈçÍÁÉ«£¬ÒÑ¾­²»ÖªÈçºÎÕĞ¼Ü£¡\n",
                "dodge"      :                60,
                "parry"      :                50,
                "damage"     :                400,
                "force"      :                400,
                "post_action":               (: berserk :),
                "damage_type":                "´ÌÉË",
             ]),      
                            
             });


int valid_learn(object me)
{
       if( !me->query_temp("weapon") )
        return   notify_fail("Á·ÏÉ½£½£Êõ±ØĞèÏÈÄÃ°Ñ½£¡£\n");
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="sword" || usage=="parry" );
}


mapping query_action(object me, object *weapon)
{

 int skill_level,limit,i,bellicosity;
 object victim ,*enemy;

 enemy = me->query_enemy();
 i=sizeof(enemy);
 weapon=me->query_temp("weapon");
 victim = enemy[random(i)];
 skill_level = (int)(me->query_skill("shasword",1));
 limit= skill_level;
 bellicosity=(int)(me->query("bellicosity",1));
 
 if(skill_level >= 95 && (me->query("family/family_name")=="ÏÉ½£ÅÉ") && me->query("id")!="murofu" && me->query("name")!="Ä½Èİ¸´"
 && me->query("force",1) > 200 && random(100) > 85)
                          {
        message_vision( sprintf(HIW"        
\nÖ»¼û$NÑöÌì³¤Ğ¥ ,Ê¹³öÏÉ½£ÖÁ¼«Ö®ÕĞ"HIR"¡® Ë«¡«Ê®¡«Ğı¡«Áú¡«Õ¶ ¡¯"HIB"!!!
"NOR),me ,victim);
        message_vision(sprintf(HIB"\n$N²»Í£µØ·ÉÎè×Å½££¬ÆäÉíĞÎ½¥½¥µØ»¯ÎªÁúĞÎ£¬"+
         "É²ÄÇ¼ä!!ÌìµØÎªÖ®±äÉ«£¬ËÄÖÜ²İÄ¾½Ô·Ç£¬\n$nÒ²±»Õâ¹ÉÆøÊÆÕğÏÅ×¡£¬"+
         "Ò»Ë²¼ä$nÒÑÔâÁúËùÍÌÊÉ¡£\n\n "NOR), me ,victim); 
        if(weapon->query("id")=="silver sword"){
        message_vision(HIW"
$NµÄÒøÁÛ¹Å½£¸ĞÓ¦µ½"HIR"¡® Ë«¡«Ê®¡«Ğı¡«Áú¡«Õ¶ ¡¯"HIW"µÄ¾ªÈËÆøÊÆ£¬½£ÉÏµÄÒøÁÛ°×¹â
ÉÁÒ«ÏÂ»¯³ÉÒ»µÀÁúĞÎ½£ÆøÖ±ÆËÏò$n\n"NOR,me,victim);
         victim->receive_wound("kee",400,me);
         COMBAT_D->report_status(victim, 1);
         victim->start_busy(1); //ÀÏÊÇÓĞÈË¶¯skills
         me->add("force",-180);
        
                                               }
        else{
         victim->receive_wound("kee",300,me);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-90);
            }   
                           
                           }

 if( me->is_team_leader() && me->query_temp("use_form")==1) 
        array1();
                                  
 if(me->query_condition("drunk",1) > 0 && random(5)==0) drunk();
     
        if (limit < 10)
                return action[random(2)];
        else if (limit < 20)
                return action[random(4)];
        else if (limit < 30)
                return action[random(5)];
        else if (limit < 40)
                return action[random(5)+1];
        else if (limit < 50)
                return action[random(5)+2];
        else if (limit < 60)
                return action[random(5)+3];
        else if (limit < 70)                        
                return action[random(5)+4];
        else if (limit < 80)                        
                return action[random(5)+5];
  if( me->query("family/family_name")!="ÏÉ½£ÅÉ" || !me->query("get_sha_sp",1) )
        {
        if (limit < 85)
                return action[random(5)+6];
        else if (limit < 90)
                return action[random(5)+7];
        else if(limit >= 90 && bellicosity >= 1000)
                return action[random(5)+15];
        else
                return action[random(5)+7];
         }
  else
        {
        if (limit < 90)
           return action[random(8)+7];
        else if(limit >= 90 && bellicosity >= 1000)
           return action[random(8)+12];
        else       
          return action[random(8)+7];
        } 
}

void sp_attack0(object me, object victim, object  weapon, int damage)
{
       sp_value =4*(cps+kar)+str+cor+spi+int1; 
       if(sp_value > 400) sp_value=400;
if( weapon->query("id")=="han_bin_sword" ||weapon->query("id")=="Sad sword")
        { 
         message_vision("\n[1;36m¡õ[1;34mH[1;36m¡õ[1;34mB[1;36m¡õ[1;34mC[0m"HIC"½£ÉÏº®ÆøÓë"NOR"$N"HIC"ÌåÄÚº®¾¢»áºÏ ,ö®Ê±ËÄÖÜÎÂ¶Èåá½µ ,Ò»¹É
Òõº®ÄÚ¾¢ÓÉ$NÊÖÖĞ³¤½£·¢³ö³¯$n¶øÈ¥\n"NOR,me,victim);
         victim->add("kee",-sp_value);        
         COMBAT_D->report_status(victim, 1);
         }         
         
       else
        { 
         message_vision("$NÒ»ÔË¾¢Ò»µÀº®Æø·¢×Ô$NµÄÌåÄÚ ,½åÓÉÊÖÖĞ³¤½£Õ¶Ïò$n\n",me,victim);
         victim->add("kee",-sp_value/2);         
         COMBAT_D->report_status(victim, 1);
        }
 
 }
void sp_attack1(object me, object victim, object  weapon, int damage)
{
    int i;
    sp_value =4*(str+cor)+cps+kar+spi+int1;
    if(sp_value > 400) sp_value=400;
    if( weapon->query("id")=="hon_water_sword" || weapon->query("id")=="Sad sword" )
    {
      message_vision("[1;31m¡õ[1;35ml[1;31m¡õ[1;35m¡õ[1;31m¡õ[1;35mC[0m"HIW"ÔÌº¬Ë®¾¢°õíç ,Óë´ËÕĞÊ½¾«ÒåÎÇºÏ ,Ò»¹ÉÈáËÆË®ÓÖÇ¿ÈçÀËµÄÄÚ¾¢ÒÑÓÉ"NOR"$N"HIW"·¢³öÖ±Ïò$n¶øÈ¥\n"NOR,me,victim);
      victim->add("kee",-sp_value);
      COMBAT_D->report_status(victim, 1);
      
    }
    else
    {
      if(!me->query_temp("conti",1))
        {
         message_vision("½åÓÉ´ËÕĞµÄ¾«Òå ,Äã¸Ğµ½Ò»¹ÉÇ°ËùÎ´ÓĞÁ¦Á¿ÓÉÄãÌåÄÚÔ´Ô´¶ø³ö ,Ò»ÕĞÕĞ¹¥Ïò¶Ô·½\n",me,victim);
         me->set_temp("conti",1);
          for(i=0;i<=2;i++)
          COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        me->delete_temp("conti");
        }
    }
}

void sp_att2(object me, object victim, object  weapon, int damage)
 {
    if( weapon->query("id")=="han_thon_sword" || weapon->query("id")=="Sad sword" )
    { 
     message_vision("[1;32m¡õ[1;33mH[1;32m¡õ[1;33m¡õ[1;32m¡õ[1;33mC[0m½£ÊÆåÄÒìÄÑ²â ,¼ÓÉÏµÚÈıÕĞÖ®±ä»ÃÄª²â ,$nÒ»¸ö²»ÁôÉñÖĞÁË$N Ò»¼ÇÇ¿»÷ÇÒÔİÊ±ÎŞ·¨¶Ô$NÕ¹¿ª¹¥»÷\n",me,victim);
    victim->add("kee",-400);    
    victim->start_busy(1);
    COMBAT_D->report_status(victim, 1);
    }
    else
    { 
    message_vision("$NÕĞÊ½Í»È»Ç§±äÍò»¯ ,ÊÖÖĞ³¤½£ÈçÉß°ã»ÓÏòµĞÈË ,$nÃş²»Çå$NµÄ¶¯Ïò ,Àä²»·ÀµÄÖĞÁËÒ»½£\n",me,victim);
    victim->add("kee",-200);     
    COMBAT_D->report_status(victim, 1);
    
    } 
 }

void berserk(object me, object victim, object  weapon, int damage)
{ 
 int skill_level=me->query_skill("shasword",1);
  if( random(100) > 70 && me->query("force",1) > 100)
  {
    if(!me->query_temp("conti"))
    {

     if( me->query("family/master_name")=="Ö£Ê¿ĞÀ" || me->query("name")=="Ö£Ê¿ĞÀ"|| me->query("dragon-sword",1)==1 )
     {
       message_vision( 
         sprintf(HIW"\nÖ»¼û$N¿ñĞÔÖèÆğ ,´óºÈÒ»Éù¡®"HIR"½£Ó°Á¬Ñô ÆßÑôÁ¬Ìì"HIW"¡¯!!\n"),me ,victim);
         message_vision( sprintf("Æß¹É¸ÕÈá²»µÈµÄºçÉ«½£ÆøİëµØÓÉ$N½£¼âÉä³ö¶Ô$nÔì³ÉÄÑÒÔ¹À¼ÆµÄÉË¡£\n\n [0m"), me ,victim);
         victim->receive_wound("kee",400,me);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-80);

     }else  
     if( me->query("family/master_name")=="ÕÅ³Ë·ç" || 
         me->query("sha-stop-1",1))
     {   
       message_vision(
         sprintf(HIW"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÒ»Ê½¡®"HIR"ÁÒÑô"HIW"¡¯!!\n"NOR ),me ,victim); 
         message_vision(sprintf(m1),me ,victim);
         victim->receive_wound("kee",300,me);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-40);            
     }else
     if( me->query("family/master_name")=="ÕÅ³ËÔÆ" ||
         me->query("sha-stop-2",1))
     { 
       message_vision(
         sprintf(HIW"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚ¶şÊ½"HIW"¡®"HIR"²ĞÑô"HIW"¡¯!!¡£\n"NOR ), me, victim );       
         message_vision(sprintf(m1), me, victim );
         victim->receive_wound("kee",300,me);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-40);
     }else
     if( me->query("family/master_name")=="ÌÆîÚ" || 
         me->query("sha-stop-3",1) )
     { 
       message_vision( sprintf(HIW"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÈıÊ½"HIW"¡®"HIY"ÑŞÑô"HIW"¡¯!!\n"NOR), me ,victim); 
         message_vision(sprintf(m1), me ,victim);
         victim->receive_wound("kee",300,me);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-40);      
     }else        
     if( me->query("family/master_name")=="ÕÔº×" ||
         me->query("sha-stop-4",1))
     {
        message_vision(sprintf(HIW"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚËÄÊ½"HIW"¡®"HIY"Å¯Ñô"HIW"¡¯!!¡£\n"NOR),me ,victim);    
          message_vision( sprintf(m1),me ,victim);
          victim->receive_wound("kee",300,me);
          me->add("force",-15);        
     }else
     if( me->query("family/master_name")=="Ã·Ó°" ||
         me->query("sha-stop-5",1))
     {
        message_vision(sprintf(HIW"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÎåÊ½"HIW"¡®"HIC"¶¬Ñô"HIW"¡¯!!¡£\n"NOR),me,victim);   
           message_vision(sprintf(m1),me,victim);
           victim->receive_wound("kee",300,me);
           COMBAT_D->report_status(victim, 1);
           me->add("force",-10);                
      }else
      if(me->query("family/master_name")=="ºÎË«Ë«" ||
         me->query("sha-stop-6",1))
      {
        message_vision( sprintf(HIW"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÁùÊ½"HIW"¡®"HIY"³¯Ñô"HIW"¡¯!!\n"NOR),me ,victim );    
           message_vision(sprintf(m1),me ,victim ); 
           victim->receive_wound("kee",300,me);
           COMBAT_D->report_status(victim, 1);
           me->add("force",-10);              
       }else               

        if( me->query_skill("shasword",1) >=60 ||  me->query("sha-stop-7",1))
// ¸ø¸Ä°İplayer µÄÈËÓÃ 
       {
         message_vision( sprintf(HIW"\n$N¿ñĞÔÖèÆğ£¬¿ÚÖĞà«à«ÓĞ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÆßÊ½"HIW"¡®"HIY"Ï¦Ñô"HIW"¡¯!!\n"NOR), me ,victim );        
           message_vision(sprintf(m1), me ,victim );
           victim->receive_wound("kee",300,me);
           COMBAT_D->report_status(victim, 1);
           me->add("force",-30);            
            }
          }   
  }
}

string query_parry_msg(string limb)
{
 object me=this_player();
 object weapon=me->query_temp("weapon");

  if(weapon && weapon->query("skill_type")=="sword")
      return parry_msg[random(sizeof(parry_msg))];
  else 
      return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)
{
          return CLASS_D("swordsman")+"/shasword/"+action;
}   
         
