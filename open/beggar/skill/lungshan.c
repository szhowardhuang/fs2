// lungshan.c
// Chan 15/5×ö×îºóµÄÐÞÕý
// Chan 10/22ÖØÐÂ¸ÄÐ´
// 1.Ôö¼ÓÎäÆ÷ÌØ¹¦ 2.ÐÞÕýÁ¬Ðø¼¼
// Swy QC 87/10/22  Î´¾­Ðí¿ÉÇëÎðÐÞ¸Ä
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void berserk(object me,object victim,object weapon,int damage);
void berserk1(object me,object victim,object weapon,int damage);
void berserk2(object me,object victim,object weapon,int damage);
void fire1(object me, object victim, object  weapon, int damage);
void fire2(object me, object victim, object  weapon, int damage);
void fire3(object me, object victim, object  weapon, int damage);
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int sp_value;
// ÎäÕß damage and force ÉÏÏÞÎª 190
mapping *action = ({
// 1
([
     "action"     :"$NÊ¹³öãñÉ½¾øÑ§µÄÆðÊÖÊ½£¬Ò»ÕÐ[1m¡¸·ÉÆÙÈëÉ½¡±[0m£¬¶Ô×¼$nµÄ$l´ò³öÄÑÒÔ×½ÃþµÄÒ»È­",
     "dodge"      :-25,
     "parry"      :-20,
     "damage"     : 30,
     "force"      : 50,
     "damage_type":"ðöÉË"
 ]),
// 2
 ([
     "action"     :"$NµÍºðÒ»Éù!!ÕæÆø´ÓË«ÕÆÖÐÊÍ³ö£¬Ê¹³öÒ»ÕÐ[1m¡¸½­ºÓÈÕÏÂ¡±[0m£¬¶Ô×¼$nµÄ$l¼±ÅÄ¶ø³ö",
     "dodge"      :-25,
     "parry"      :-20,
     "damage"     : 25,
     "force"      : 50,
     "damage_type":"ðöÉË"
 ]),
// 3
 ([
     "action"     :"$NÓÌÈçÁ÷Ë®°ãËæ$nµÄ¹¥ÊÆ£¬Ê¹³öÒ»ÕÐ[1m¡¸×·ÆÙËÝÔ´¡±[0m±ãÍù$nµÄ$l·´»÷¹ýÈ¥",
     "dodge"      :-50,
     "parry"      :-10,
     "damage"     : 20,
     "force"      : 80,
     "damage_type":"ðöÉË"
 ]),
// 4
 ([
     "action"     :"$N´óºÈÒ»Éù£¬Ë«È­Ò»Ìá£¬Ò»ÕÐ[1m¡¸ÎåÔÀ¶¥Ìì¡±[0mÍù$nµÄÎå¸öÒªº¦»÷³ö",
     "dodge"      :-10,
     "parry"      :-25,
     "damage"     : 70,
     "force"      : 100,
     "damage_type":"ðöÉË"
 ]),
// 5
 ([
     "action"     :"$N²½ÂÄÒ»³Á£¬ÄýÉñ¾ÛÆø£¬Ë«È­Á¬ÏÂÊ¹³ö[1m¡¸Ç§´¨°ÙÔÀ¡±[0m»÷Ïò$n$l",
     "dodge"      :-30,
     "parry"      :-5,
     "damage"     : 90,
     "force"      : 190,
     "damage_type":"ðöÉË"
 ]),
// 6
 ([
     "action"     :"$N×ÝÉíÒ»Ô¾£¬Ê¹³öãñÉ½È­°ÂÒå[36m¡¸É½ÈªÈºÓ¿¡±[0m£¬È­ÈçÁ¬Öé°ãÒ»Á¬ÊýÊ®È­»÷Ïò$n$l",
     "dodge"      :-30,
     "parry"      :-30,
     "damage"     : 110,
     "force"      : 150,
     "damage_type":"ðöÉË"
 ]),
// 7
 ([
     "action"     :"$NË«È­½»´í£¬ÔË×ãÕæÆø£¬Ê¹³öãñÉ½È­°ÂÒå[1;36m¡¸É½ÇîË®¾¡¡±[0m£¬Íò¾ûÖ®Á¦»÷Ïò$n$l£¬ÄÑÒÔÕÐ¼Ü",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 130,
     "force"      : 140,
     "damage_type":"ðöÉË"
 ]),
// 8
 ([
     "action"     :"$NË«ÊÖÈç¡¸Á÷Ë®¡±°ãÈáÒàÈá¡¢¸ÕÒà¸Õ£¬Ê¹³öãñÉ½È­ÖÐ°ÂÒå[1;32m¡¸´¨Á÷²»Ï¢¡±[0m£¬ËÆÓÐËÆÎÞ°ãÏò$n$l»÷³ö",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 135,
     "force"      : 140,
     "post_action":(: berserk1 :),
     "damage_type":"ðöÉË"
 ]),
// 9
 ([
     "action"     :"$NÒ»È­ÖÁ¸Õ¡¢Ò»È­ÖÁÈá£¬Ê¹³öãñÉ½È­°ÂÒå[1;36m¡¸É½´¨Á÷Ë®¡±[0m£¬¸ÕÈá²¢¼ÃµÄÒ»»÷Ïò$n$l»÷È¥£¬ÎÞ·¨ÉÁ¶ã",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 145,
     "force"      : 160,
     "damage_type":"ðöÉË"
 ]),
// 10
 ([
     "action"     :"$NÈ­É¢ÁéÆø£¬ö®Ê±¿ñ·çËÄÆð£¬ÎÞÇîÕæÆø×Ô$NÉíÅÔÓ¿³ö£¬Ê¹³öãñÉ½È­ÃØ°ÂÒå[1;32m¡¸É½ºÓ¾ãÃð¡±[0m£¬$n$l½«ÊÜ¿ÉÅÂÖ®Á¦Ëù»ÙÃð",
     "dodge"      :-50,
     "parry"      :-50,
     "damage"     : 150,
     "force"      : 150,
     "post_action":(: berserk2 :),
     "damage_type":"ðöÉË"
 ]),
// 11
 ([  "action"     :             "$NÊ¹³ö³àÑæÉñÕÆµÚÒ»Ê½\n"
                         "--"HIR"¡®³àÑæÆÆ¿Õ¡¯"NOR"--\n"
             HIW"$N½«ºÆÈÕÕæÆø£¬ÔËÖÁÊÖÖ¸ÉÏ£¬´ËÊ±ÊÖÖ¸·¢³öË¿Ë¿µÄÈÈÆø\n"
                "$N¸Ð¾õµ½ÊÖÉÏµÄºÆÈÕÕæÆøÔ½À´Ô½¸ß£¬Ê®Ö»ÊÖÖ¸·¢³öÒ«ÑÛµÄ¹âÃ¢\n"
                "$NµÍºðÒ»ÉùÊýÊ®µÀÖËÈÈÕæÆøÈç·øÉä°ã¿ñÉä$n\n"NOR,
      "dodge"     :   80,
      "parry"     :   50,
      "damage"    :   160,
      "force"     :   150,
      "post_action":  (: fire1 :),
      "damage_type":  "´ÌÉË",
     ]),
// 12
 ([   "action"     :                 "$NÊ¹³ö³àÑæÉñÕÆµÚ¶þÊ½\n"
                         "--"HIR"¡®ÁÒÑæÂþÌì¡¯"NOR"--\n"
             HIW"$NÄæÔËºÆÈÕÕæÆø£¬½«ÕæÆøÔËÖÁÊÖÕÆ£¬Ë²Ê±Ë«ÕÆÍ¨ºì\n"
                "$NÌåÖÐµÄºÆÈÕÕæÆøÈç·ÐË®°ã´ÓÊÖÉÏ¹ö¹ö¶ø³ö£¬²»ÍÂ²»¿ì\n"
                "$N½«Ë«ÕÆÏòÇ°Ò»ÍÆ£¬ÂþÌìÖËÈÈÕæÆøÈçÈÈÀË°ãÏ®Ïò$n\n"NOR,
     "dodge"      :  80,
     "parry"      :  50,
     "damage"     :  170,
     "force"      :  190,
     "post_action":(: fire2 :),
     "damage_type":"ðöÉË",

      ]),
// 13
  ([ "action"     :               "$NÊ¹³ö³àÑæÉñÕÆÖÕ¼«°ÂÒå\n"
                         "--"HIR"¡®·ÙÌìÃðµØ¡¯"NOR"--\n"
             HIW"$NÔ¾ÖÁ°ë¿ÕÖÐ½«ºÆÈÕÕæÆø·¢É¢³öÀ´£¬ÍðÈçÁÒÈÕ\n"
                "$N¿ñºðÒ»ÉùÐ®´øÖËÈÈÕæÆøÈçÁÒÈÕ×¹µØ°ã¿ñ×¹¶øÏÂ\n"
                "Êý²»ÇåµÄÕÆÓ°¼°ÖËÈÈÕæÆøÐÎ³ÉÁú¾í·ç°üÎ§ÁË$n\n"NOR,

     "dodge"      :  80,
     "parry"      :  50,
     "damage"     :  180,
     "force"      :  180,
     "post_action":(: fire3 :),
     "damage_type":"ðöÉË",

     ]),
// 14
 ([
     "action"     :"$N¶ÙÎòãñÉ½È­·¨Ö®---[1;5;36mÇ§É½ÍòË®¡¢Á¬Ãà²»¶Ï[0m---£¬½«ËùÑ§µÄãñÉ½È­·¨Á¬Ãà²»¾ø°ãµÄÊ¹ÓÃ³öÀ´!!\n",
     "dodge"      :-50,
     "parry"      :-50,
     "damage"     : 50,
     "force"      : 50,
     "post_action":(: berserk :),
     "damage_type":"ðöÉË"
 ]),

});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return   notify_fail("Ñ§ãñÉ½¾øÑ§±ØÐë¿ÕÊÖ¡£\n");
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="unarmed" );
}

mapping query_action(object me, object  weapon)
{
 int skill_level, limit ,test,f,k,i;
 object victim ,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 skill_level = (int)(me->query_skill("lungshan", 1));
 limit= (int)(skill_level/10);
 f = random(10);
 k = random(100);             //ÒÔÏÂÎäÆ÷ÌØ¹¦µÄ²¿·Ý.³öÏÖÂÊÎª15%,¿ÛµÐÈËkee 210
if(me->query_temp("weapon"))
{
 weapon=me->query_temp("weapon");  //¿Û×Ô¼ºforce 200
if(me->query("family/family_name")=="ãñÉ½ÅÉ"&&weapon->query("id")=="carzy dragon")
  {
if((k>85)&&(skill_level>90)&&(me->query_skill_mapped("force")=="haoforce"))
{
message_vision(HIW"$NÊÖÉÏµÄ"HIY"¿ñÁúÏèÌìÆÆ"HIW"±»$NµÄºÆÈÕÆø¾¢ËùÒý,»Ã»¯³öÒ»Ìõ¾Þ´ó»ðÁú!!\n"NOR,me,victim);
message_vision(HIR+@LONG

                             /           /
                            /' .,,,,  ./
                           /';'     ,/
                          / /   ,,//,`'`
                         ( ,, '_,  ,,,' ``
                         |    /@  ,,, ;  `
                        /    .   ,' /' `,``
                       /   .     ./, `,, ` ;
                    ,./  .   ,-,',` ,,/''\,'
                    |   /; ./,,'`,,'' |   |
                    |     /   ','    /    |
                     \___/'   '     |     |
                       `,,'  |      /     `\
                            /      |        ~\
                           '       (
                           :
                          ; .         \--\----

LONG+NOR,me);
 for(i=0;i<3;i++)
 {
message_vision(HIR"Ð×ÃÍµÄ»ðÁú¶Ô$nÅç³öÁËÖËÈÈ»ðÑæ,Ë²Ê±$n±»»ðÑæËù°üÎ§,È«ÉíÍ´¿à²»¼º¡£\n"NOR,me,victim);
victim->add("kee",-70);
victim->apply_condition("burn",random(10));
COMBAT_D->report_status(victim, 1);
  }
message_vision(HIW"$NÊÖÉÏµÄ"HIY"¿ñÁúÏèÌìÆÆ"HIW"·¢Ò»µÀ°×¹â,»ðÁúÏûÊ§ÔÚ°×¹âÖ®ÖÐÁË¡£\n"NOR,me);
me->add("force",-200);
}
}
}
 if(me->query("family/family_name")=="ãñÉ½ÅÉ"&& me->query("fire_strike",1))
  {
    if( (string)me->query_skill_mapped("force") == "haoforce")
    {
    if (limit = 10)
      {
       if((int)me->query("force") > 1000)
        {
         if (f< 1)
         return action[13];
         return action[random(5)+8];
        }
       if((int)me->query("force") > 750)
        {
         if (f< 1)
         return action[13];
         return action[random(5)+7];
        }
       if((int)me->query("force") > 500)
        {
         if (f< 1)
         return action[13];
         return action[random(5)+6];
        }
      }
    }
  }
    if (limit < 5 )
            return action[random(5)];
    if (limit < 6 )
    {
       return action[random(5)+1];
    }
    if (limit < 7 )
    {
       return action[random(5)+2];
    }
    if (limit < 8 )
    {
       return action[random(5)+3];
    }
    else if (limit < 9)
            {
         if (f< 1)
                return action[13];
                return action[random(5)+4];
            }
    else
    {
         if (f< 1)
       return action[13];
       return action[random(5)+5];
    }
}

void fire1(object me, object victim, object  weapon, int damage)
{
int skill_level;
skill_level = (int)(me->query_skill("haoforce", 1));
if (skill_level > 80)
{
      sp_value =4*(cps+kar)+str+cor+spi+int1;
      message_vision(HIW"ÊýÊ®µÀÖËÈÈÕæÆøÔÚ$nÌåÄÚÂÒ´Ü²¢¿ñ±¬¿ªÀ´\n"NOR,me,victim);
      victim->add("kee",-sp_value/2);
      me->add("force",-80);
      victim->apply_condition("burn",random(10)+((int)me->query_skill("haoforce", 1)/10));
      COMBAT_D->report_status(victim, 1);
}
}

void fire2(object me, object victim, object  weapon, int damage)
{
    int skill_level;
    skill_level = (int)(me->query_skill("haoforce", 1));
if (skill_level > 90)
{
    int i;
    sp_value =4*(str+cor)+cps+2*kar+spi+int1;
message_vision(HIW"$NµÄÖËÈÈÕæÆøÔÚ$nÅÔÐÎ³ÉÕæ¿ÕÐýÎÐ£¬Ê¹$nÎÞ·¨¶¯µ¯\n"NOR,me,victim);    
      victim->add("kee",-sp_value/2);
      victim->start_busy(1);
      me->add("force",-100);
      victim->apply_condition("burn",random(15)+((int)me->query_skill("haoforce", 1)/10));
      COMBAT_D->report_status(victim, 1);
}
}

void fire3(object me, object victim, object  weapon, int damage)
 {
     int skill_level;
skill_level = (int)(me->query_skill("haoforce", 1));
if (skill_level > 100)
{
     sp_value =4*(cor+int1)+3*str+spi+cps+kar;
message_vision(HIW"$n±»$NµÄÖËÈÈÁú¾íÕæÆø£¬¾íÖÁ°ë¿ÕÖÐ²¢±»ËºÁÑ¿ªÀ´\n"NOR,me,victim);     
        victim->add("kee",-sp_value/2);
        me->add("force",-170);
     victim->apply_condition("burn",random(10)+((int)me->query_skill("haoforce", 1)/10));
     COMBAT_D->report_status(victim, 1);
}
}

void berserk(object me, object victim, object  weapon, int damage)
{ //Á¬Ðø¼¼µÄ²¿·Ý,·Ö³É¶þ¸ö.kee >1500(Ö¸mob),kee<1600Ö¸player
int bovalue,sklv,ko,bound=10,i,vdodge;//¿ÛµÄkeeÔ¼¶þ±¶(mob¼°player±ÈµÄ»°)
vdodge=victim->query_skill("dodge",1);
if(vdodge>140)
 vdodge=140;
 sklv=(int)me->query_skill("lungshan",1)/10;
// ÐÞÕýÅÐ¶¨ ²»È»¿ÉÄÜ»áÓÐ100% Ö»Òªhaoforce¸ß¾Í¿ÉÄÜ By Swy
 ko=(int)me->query_skill("lungshan",1);
 ko=ko+((int)me->query_skill("unarmed",1)+(int)me->query_skill("fire-kee",1))/2;
//³öÏÖÂÊËÄ³É,³É¹¦ÂÊÔ¼50% Ê®ÏÂÈ«ÖÐ¿Ûkee 500,mobµÄ»°Ô¼1000È«ÖÐµÄ»°
 for(i=0;i<sklv;i++)
 {
  switch(i) {
case 0:
 message_vision("$NÊ¹³öãñÉ½¾øÑ§µÄÆðÊÖÊ½,[1m¡¸·ÉÆÙÈëÉ½¡±[0m£¬¶Ô×¼$nµÄÒªº¦´ò³öÄÑÒÔ×½ÃþµÄÒ»È­\n",me,victim);
break;
case 1:
 message_vision("$NµÍºðÒ»Éù!!ÕæÆø´ÓË«ÕÆÖÐÊÍ³ö£¬Ê¹³öÒ»ÕÐ[1m¡¸½­ºÓÈÕÏÂ¡±[0m£¬¶Ô×¼$nÑ¨Î»¼±ÅÄ¶ø³ö\n ",me,victim);
break;
case 2:
 message_vision("$NË«ÊÖ¼±×ªÊ¹³öãñÉ½¾øÑ§Ö®[1m¡¸×·ÆÙËÝÔ´¡±[0m¿ìËÙµØÍù$nÖÂÃü²¿Î»»÷³ö\n ",me,victim);
break;
case 3:
 message_vision("$N´óºÈÒ»Éù£¬Ë«È­Ò»Ìá£¬Ò»ÕÐ[1m¡¸ÎåÔÀ¶¥Ìì¡±[0mÍù$nµÄÎå¸öÒªº¦»÷³ö\n ",me,victim);
break;
case 4:
 message_vision("$N²½ÂÄÒ»³Á£¬ÄýÉñ¾ÛÆø£¬Ë«È­Á¬ÏÂÊ¹³ö[1m¡¸Ç§´¨°ÙÔÀ¡±[0m»÷Ïò$nÈ«ÉíÒªº¦\n",me,victim);
break;
case 5:
 message_vision("$N×ÝÉíÒ»Ô¾£¬Ê¹³öãñÉ½È­°ÂÒå[36m¡¸É½ÈªÈºÓ¿¡±[0m£¬È­ÈçÁ¬Öé°ãÒ»Á¬ÊýÊ®È­»÷Ïò$nµÄÒªº¦\n ",me,victim);
break;
case 6:
 message_vision("$NË«È­½»´í£¬ÔË×ãÕæÆø£¬Ê¹³öãñÉ½È­°ÂÒå[1;36m¡¸É½ÇîË®¾¡¡±[0m£¬Íò¾ûÖ®Á¦»÷Ïò$nÊ¹$nÄÑÒÔÕÐ¼Ü\n",me,victim);
break;
case 7:
 message_vision("$NË«ÊÖÈç¡¸Á÷Ë®¡±°ãÈáÒàÈá¡¢¸ÕÒà¸Õ£¬Ê¹³öãñÉ½È­ÖÐ°ÂÒå[1;32m¡¸´¨Á÷²»Ï¢¡±[0m£¬Ë«ÕÆËÆÓÐËÆÎÞ°ãÏò$n»÷³ö ",me,victim);
break;
case 8:
 message_vision("$NÒ»È­ÖÁ¸Õ¡¢Ò»È­ÖÁÈá£¬Ê¹³öãñÉ½È­°ÂÒå[1;36m¡¸É½´¨Á÷Ë®¡±[0m£¬¸ÕÈá²¢¼ÃµÄÒ»»÷Ïò$n»÷È¥£¬ÎÞ·¨ÉÁ¶ã ",me,victim);
break;
case 9:
 message_vision("$NÈ­É¢ÁéÆø£¬ö®Ê±¿ñ·çËÄÆð£¬ÎÞÇîÕæÆø×Ô$NÉíÅÔÓ¿³ö£¬Ê¹³öãñÉ½È­ÃØ°ÂÒå[1;32m¡¸É½ºÓ¾ãÃð¡±[0m£¬$n½«ÊÜ¿ÉÅÂÖ®Á¦Ëù»ÙÃð ",me,victim);
break;}
// ÃüÖÐÔ¼ 50% By Swy 
if(random(ko)>vdodge-30){
message_vision(HIY"$n±»$NÁèÀ÷Òì³£µÄãñÉ½È­·¨»÷ÖÐ,$nÉíÉÏ±»ÀÓÏÂÉîºñµÄÕÆÓ¡¡£\n"NOR,me,victim);
bovalue=(int)victim->query("kee");
//mob¿Û¶þ´Î,player¿ÛÒ»´Î
if(bovalue>1600) victim->add("kee",-bound);
        victim->add("kee",-bound);
        COMBAT_D->report_status(victim, 1);
        bound=bound+10;
  }
else{
message_vision(HIW"$nÔÚÇ§¾ùÒ»¿ÌÖ®¼Ê¿´³ö$NãñÉ½È­·¨µÄÆÆÕÀ,ÓÐ¾ªÎÞÏÕµØ¶ãÁË¿ªÀ´¡£\n"NOR, me, victim);
        bound=bound+10;
  }
 }
message_vision(HIR"$NÊ¹³öÁ¬Ãà²»¾øºó,È«ÉíÄÚÁ¦¿Ý\½ß,Ê¹$N²»µÃ²»¸Ï½ôÔËÆøµ÷Ï¢¡£\n"NOR,me);
    me->start_busy(1);
    me->add("force",-bound);
    COMBAT_D->report_status(victim, 1);
}

void berserk1(object me, object victim, object  weapon, int damage)
{
int skill_level;
skill_level = (int)(me->query_skill("lungshan", 1));
// ÃüÖÐÔ¼ 50%
if(((skill_level+random(150)) > 160) && (me->query("super_fire",1)))
{
message_vision(HIC"$n±»ãñÉ½È­·¨ÖÐËùÔÌº­µÄÉ½´¨Á÷Ë®Ö®ÆøÏ¢ËùÇÖ£¬Ê¹$nÃÔÊ§ÔÚÉ½Ë®Ö®ÖÐ\n"NOR,me,victim);
      victim->start_busy(1);
      me->add("force",-40);
      COMBAT_D->report_status(victim, 1);
}
}

void berserk2(object me, object victim, object  weapon, int damage)
{
int skill_level1,skill_level2;
skill_level1 = (int)(me->query_skill("lungshan", 1));
// haoforce ÄÜÁ· so ÉèÏÞ By Swy
skill_level2 = (int)(me->query_skill("haoforce", 1));
if(skill_level2 > 100) skill_level2=100;
// ÃüÖÐ 50% By Swy
if(((skill_level1+skill_level2+random(200)) > 285) &&
  ((string)me->query_skill_mapped("force") == "haoforce") &&
  (me->query("super_fire",1))&&(me->query("force")>200))
{
message_vision
( HIR"$NÁ³É«Ò»±ä,È«ÉíÉ¢³öÖËÈÈÎÞ±ÈµÄÕæÆø,Ë«ÊÖÈçÐýÎÐ°ãÊ¹³öãñÉ½¾øÑ§Ö®½û¶Ï¼¼!!!\n\n"HIY
     "      ¡î¡ï¡®"HIW"»ð¡«º£¡«·Ù¡«Ìì  "HIB"²¨¡«ÌÎ¡«ÐÚ¡«Ó¿"HIY"¡¯¡ï¡î\n"HIR
"Ô´Ô´²»¶ÏµÄÖËÈÈÆø¾¢Èç´óº£ÀË°ã,Ò»²ãÓÖÒ»²ãµÄÏò$n¿ñ¾í¶øÈ¥,$n±»°üÎ§ÔÚÈÈÀËÖ®ÖÐ
$nÖ»¾õ¾Þ´óµÄÖËÈÈÆø¾¢ÈëÇÖÈ«Éí¾­ÂöÎÞ·¨ÄýÆø,¸Ð¾õÄÚÁ¦²»¶ÏµØÔÚÁ÷Ê§Ö®ÖÐ\n"NOR
      ,me,victim);
      victim->add("kee",-200);
      victim->add("force",-300);
victim->apply_condition("burn",random(10) +((int)me->query_skill("haoforce",1)/10));
     // delay µÄ condition 5 »Ø By Swy
 victim->apply_condition("hart",random(10)+1);
      me->add("force",-200);
      COMBAT_D->report_status(victim, 1);
}
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        if( (int)me->query("force") < 3 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        if( (int)me->query_skill("literate") <= ( (int)(me->query_skill("lungshan", 1)*0.75) ) )
                return notify_fail("ÄãµÄÎäÑ§ÖªÊ¶²»×ã£¬ËÆºõÎÞ·¨²ÎÍ¸¾øÑ§ÖÐÉ½Ë®Ö®Òå¡£");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("fighter")+"/lungshan/"+action;
}
