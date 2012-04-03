// ¶ÔÆäfsµÄ½ø²½°ïÆä lungshan ×öÆäºÏ¼¼ by swy
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
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
// ÎäÕß damage and force ÉÏÏÞÎª 500
mapping *action = ({
// 1
([
     "action"     :"$NÊ¹³öãñÉ½¾øÑ§µÄÆðÊÖÊ½£¬Ò»ÕÐ[1m¡¸·ÉÆÙÈëÉ½¡±[0m£¬¶Ô×¼$nµÄ$l´ò³öÄÑÒÔ×½ÃþµÄÒ»È­",
     "dodge"      :-25,
     "parry"      :-20,
     "damage"     : 50,
     "force"      : 50,
     "damage_type":"ðöÉË"
 ]),
// 2
 ([
     "action"     :"$NµÍºðÒ»Éù!!ÕæÆø´ÓË«ÕÆÖÐÊÍ³ö£¬Ê¹³öÒ»ÕÐ[1m¡¸½­ºÓÈÕÏÂ¡±[0m£¬¶Ô×¼$nµÄ$l¼±ÅÄ¶ø³ö",
     "dodge"      :-25,
     "parry"      :-20,
     "damage"     : 100,
     "force"      : 100,
     "damage_type":"ðöÉË"
 ]),
// 3
 ([
     "action"     :"$NÓÌÈçÁ÷Ë®°ãËæ$nµÄ¹¥ÊÆ£¬Ê¹³öÒ»ÕÐ[1m¡¸×·ÆÙËÝÔ´¡±[0m±ãÍù$nµÄ$l·´»÷¹ýÈ¥",
     "dodge"      :-50,
     "parry"      :-10,
     "damage"     : 150,
     "force"      : 150,
     "damage_type":"ðöÉË"
 ]),
// 4
 ([
     "action"     :"$N´óºÈÒ»Éù£¬Ë«È­Ò»Ìá£¬Ò»ÕÐ[1m¡¸ÎåÔÀ¶¥Ìì¡±[0mÍù$nµÄÎå¸öÒªº¦»÷³ö",
     "dodge"      :-10,
     "parry"      :-25,
     "damage"     : 200,
     "force"      : 200,
     "damage_type":"ðöÉË"
 ]),
// 5
 ([
     "action"     :"$N²½ÂÄÒ»³Á£¬ÄýÉñ¾ÛÆø£¬Ë«È­Á¬ÏÂÊ¹³ö[1m¡¸Ç§´¨°ÙÔÀ¡±[0m»÷Ïò$n$l",
     "dodge"      :-30,
     "parry"      :-5,
     "damage"     : 250,
     "force"      : 250,
     "damage_type":"ðöÉË"
 ]),
// 6
 ([
     "action"     :"$N×ÝÉíÒ»Ô¾£¬Ê¹³öãñÉ½È­°ÂÒå[36m¡¸É½ÈªÈºÓ¿¡±[0m£¬È­ÈçÁ¬Öé°ãÒ»Á¬ÊýÊ®È­»÷Ïò$n$l",
     "dodge"      :-30,
     "parry"      :-30,
     "damage"     : 300,
     "force"      : 300,
     "damage_type":"ðöÉË"
 ]),
// 7
 ([
     "action"     :"$NË«È­½»´í£¬ÔË×ãÕæÆø£¬Ê¹³öãñÉ½È­°ÂÒå[1;36m¡¸É½ÇîË®¾¡¡±[0m£¬Íò¾ûÖ®Á¦»÷Ïò$n$l£¬ÄÑÒÔÕÐ¼Ü",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 350,
     "force"      : 350,
     "damage_type":"ðöÉË"
 ]),
// 8
 ([
     "action"     :"$NË«ÊÖÈç¡¸Á÷Ë®¡±°ãÈáÒàÈá¡¢¸ÕÒà¸Õ£¬Ê¹³öãñÉ½È­ÖÐ°ÂÒå[1;32m¡¸´¨Á÷²»Ï¢¡±[0m£¬ËÆÓÐËÆÎÞ°ãÏò$n$l»÷³ö",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 400,
     "force"      : 400,
     "post_action":(: berserk1 :),
     "damage_type":"ðöÉË"
 ]),
// 9
 ([
     "action"     :"$NÒ»È­ÖÁ¸Õ¡¢Ò»È­ÖÁÈá£¬Ê¹³öãñÉ½È­°ÂÒå[1;36m¡¸É½´¨Á÷Ë®¡±[0m£¬¸ÕÈá²¢¼ÃµÄÒ»»÷Ïò$n$l»÷È¥£¬ÎÞ·¨ÉÁ¶ã",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 400,
     "force"      : 400,
     "damage_type":"ðöÉË"
 ]),
// 10
 ([
     "action"     :"$NÈ­É¢ÁéÆø£¬ö®Ê±¿ñ·çËÄÆð£¬ÎÞÇîÕæÆø×Ô$NÉíÅÔÓ¿³ö£¬Ê¹³öãñÉ½È­ÃØ°ÂÒå[1;32m¡¸É½ºÓ¾ãÃð¡±[0m£¬$n$l½«ÊÜ¿ÉÅÂÖ®Á¦Ëù»ÙÃð",
     "dodge"      :-50,
     "parry"      :-50,
     "damage"     : 400,
     "force"      : 400,
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
      "damage"    :   500,
      "force"     :   500,
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
     "damage"     :  500,
     "force"      :  500,
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
     "damage"     :  500,
     "force"      :  500,
     "post_action":(: fire3 :),
     "damage_type":"ðöÉË",

     ]),
// 14
 ([
     "action"     :"$N¶ÙÎòãñÉ½È­·¨Ö®---[1;5;36mÇ§É½ÍòË®¡¢Á¬Ãà²»¶Ï[0m---£¬½«ËùÑ§µÄãñÉ½È­·¨Á¬Ãà²»¾ø°ãµÄÊ¹ÓÃ³öÀ´!!\n",
     "dodge"      :-50,
     "parry"      :-50,
     "damage"     : 200,
     "force"      : 200,
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
 int skill_level, limit ,f,k,i,j,l,m,a;
 object victim ,*enemy,room,*all;
 enemy = me->query_enemy();
 i=sizeof(enemy);
victim=offensive_target(me);
if(!victim) return action[random(5)];
 room = environment(me);
 all = all_inventory(room);
 m=sizeof(all);
 skill_level = (int)(me->query_skill("lungshan", 1));
 limit= (int)(skill_level/10);
 f = random(10);
 k = random(100);
if(me->query("combat_exp")>1500000) {
if(!me->is_busy() && userp(me) && 20>random(100) && me->query("family/family_name")=="ãñÉ½ÅÉ") {
for(a=0;a<i;a++) {
if(!enemy[a]) continue;
if(enemy[a]->query("family/family_name")!="Ñ©²ÔÅÉ") continue;
enemy[a]->set_temp("is_enemy",1);
}
for(j=0;j<m;j++) {
if(!userp(all[j])) continue;
if(!all[j]->is_fighting()) continue;
if(all[j]->query_temp("is_enemy")) continue;
if(all[j]->query_temp("use-two-power")) continue;
if(all[j]->query("family/family_name")!="Ñ©²ÔÅÉ") continue;
for(l=0;l<10;l++) {
message_vision(HIW"Ö»¼û"+me->query("name")+"Óë"+all[j]->query("name")+"Á¬ÊÖ£¬°ÑãñÉ½ÅÉÓëÑ©²ÔÅÉµÄ¾øÑ§ÈÚºÏÒ»ÖÂ£¬Ê¹³ö¡®"HIC"º®±ù"HIR"ÁÒ»ð"HIB"ÕÆ"HIW"¡¯Ïò$N¿ñ¹¥¶øÈ¥¡£\n"NOR,victim);
victim->receive_damage("kee",500);
COMBAT_D->report_status(victim);
}
m=0;
all[j]->set_temp("use-two-power",1);
me->start_busy(1);
all[j]->start_busy(1);
victim->start_busy(1);
}}}
if(me->query_temp("weapon"))
{
 weapon=me->query_temp("weapon");  //¿Û×Ô¼ºforce 200
if(me->query("family/family_name")=="ãñÉ½ÅÉ"&&weapon->query("id")=="crazy dragon")
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
victim->receive_damage("kee",100);
victim->apply_condition("burn",random(10)+1);
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
       if((int)me->query("force") > 3000)
        {
if(f<2)
         return action[12];
return action[random(10)+4];
        }
       if((int)me->query("force") > 2000)
        {
if(f<2)
         return action[11];
return action[random(10)+4];
        }
       if((int)me->query("force") > 1000)
        {
if(f<2)
         return action[10];
return action[random(10)+4];
        }
      }
    }
  }
    if (limit < 5 )
            return action[random(5)];
    if (limit < 6 )
    {
       return action[random(6)];
    }
    if (limit < 7 )
    {
       return action[random(6)+1];
    }
    if (limit < 8 )
    {
       return action[random(6)+2];
    }
    else if (limit < 9)
            {
if(f<2)
                return action[13];
                return action[random(6)+3];
            }
    else
    {
if(f<2)
       return action[13];
       return action[random(6)+4];
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
      victim->receive_damage("kee",(100+2*sp_value));
      me->add("force",-100);
      victim->apply_condition("burn",random(10)+1);
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
    message_vision(HIW"$NµÄÖËÈÈÕæÆøÔÚ$nÅÔÐÎ³ÉÕæ¿ÕÐýÎÐ£¬Ê¹$nÉíÐÄÊÜ´´\n"NOR,me,victim);
      victim->receive_damage("kee",(150+2*sp_value));
      me->add("force",-150);
      victim->apply_condition("burn",random(15)+1);
      COMBAT_D->report_status(victim, 1);
}
}

void fire3(object me, object victim, object  weapon, int damage)
 {
     int skill_level;
skill_level = (int)(me->query_skill("haoforce", 1));
if (skill_level >= 100)
{
     sp_value =4*(cor+int1)+3*str+spi+cps+kar;
     message_vision(HIW"$n±»$NµÄÖËÈÈÁú¾íÕæÆø£¬¾íÖÁ°ë¿ÕÖÐ²¢±»ËºÁÑ¿ªÀ´\n"NOR,me,victim);
      victim->receive_damage("kee",(200+2*sp_value));
      me->add("force",-200);
     victim->apply_condition("burn",random(20)+1);
     COMBAT_D->report_status(victim, 1);
}
}

void berserk(object me, object victim, object  weapon, int damage)
{
int bovalue,sklv,ko,bound=50,i;
sklv=(int)me->query_skill("lungshan",1)/10;
if((me->query("id")=="cgy"||me->query("id")=="master jen")||(60>random(100)&&me->query("env/ãñÉ½Á¬»÷")&&me->query("family/family_name")=="ãñÉ½ÅÉ")) {
 for(i=0;i<sklv;i++)
 {
  switch(i) {
case 0:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚÒ»ÕÐ"HIC"¡¸·ÉÆÙÈëÉ½¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n",me,victim);
break;
case 1:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚ¶þÕÐ"HIC"¡¸½­ºÓÈÕÏÂ¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n ",me,victim);
break;
case 2:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚÈýÕÐ"HIC"¡¸×·ÆÙËÝÔ´¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n ",me,victim);
break;
case 3:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚËÄÕÐ"HIC"¡¸ÎåÔÀ¶¥Ìì¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n ",me,victim);
break;
case 4:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚÎåÕÐ"HIC"¡¸Ç§´¨°ÙÔÀ¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n",me,victim);
break;
case 5:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚÁùÕÐ"HIC"¡¸É½ÈªÈºÓ¿¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n ",me,victim);
break;
case 6:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚÆßÕÐ"HIC"¡¸É½ÇîË®¾¡¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n",me,victim);
break;
case 7:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚ°ËÕÐ"HIC"¡¸´¨Á÷²»Ï¢¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n",me,victim);
break;
case 8:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚ¾ÅÕÐ"HIC"¡¸É½´¨Á÷Ë®¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n",me,victim);
break;
case 9:
 message_vision("$NÊ¹³öãñÉ½È­·¨µÚÊ®ÕÐ"HIC"¡¸É½ºÓ¾ãÃð¡±"NOR"£¬ÕæÆø¿ñÍÂ»÷Ïò$n¡£\n",me,victim);
break;
}
// ÐÞÕýÈ«ÃüÖÐ By Swy
message_vision(HIY"$NÁèÀ÷Òì³£µÄãñÉ½È­·¨£¬ÔÚ$nÉíÉÏÀÓÏÂÉîºñµÄÕÆÓ¡¡£\n"NOR,me,victim);
        victim->receive_damage("kee",bound);
        COMBAT_D->report_status(victim, 1);
        bound=bound+10;
 }
// È¡Ïû×ÔÉí busy by swy
/*
message_vision(HIR"$NÊ¹³öÁ¬Ãà²»¾øºó£¬È«ÉíÄÚÁ¦¿Ý\½ß£¬²»µÃ²»¸Ï½ôÔËÆøµ÷Ï¢¡£\n"NOR,me);
if(me->query("del_delay") != 1) {
    me->start_busy(1);
}
*/
    me->add("force",-bound);
    COMBAT_D->report_status(victim, 1);
}
}

void berserk1(object me, object victim, object  weapon, int damage)
{
// Ìá¸ßÃüÖÐÂÊ by swy
if(60>random(100) && me->query("super_fire",1))
{
message_vision(HIC"$n±»ãñÉ½È­·¨ÖÐËùÔÌº­µÄÉ½´¨Á÷Ë®Ö®ÆøÏ¢ËùÇÖ£¬Ê¹$nÍÂÁËÒ»¿ÚÏÊÑª¡£\n"NOR,me,victim);
      victim->receive_damage("kee",350);
      me->add("force",-50);
      COMBAT_D->report_status(victim, 1);
}
}

void berserk2(object me, object victim, object  weapon, int damage)
{
// Ìá¸ßÃüÖÐÂÊ by swy
if(60>random(100) &&
  ((string)me->query_skill_mapped("force") == "haoforce") &&
  (me->query("super_fire",1))&&(me->query("force")>200))
{
message_vision
( HIR"$NÁ³É«Ò»±ä,È«ÉíÉ¢³öÖËÈÈÎÞ±ÈµÄÕæÆø,Ë«ÊÖÈçÐýÎÐ°ãÊ¹³öãñÉ½¾øÑ§Ö®½û¶Ï¼¼!!!\n\n"HIY
     "      ¡î¡ï¡®"HIW"»ð¡«º£¡«·Ù¡«Ìì  "HIB"²¨¡«ÌÎ¡«ÐÚ¡«Ó¿"HIY"¡¯¡ï¡î\n"HIR
"Ô´Ô´²»¶ÏµÄÖËÈÈÆø¾¢Èç´óº£ÀË°ã,Ò»²ãÓÖÒ»²ãµÄÏò$n¿ñ¾í¶øÈ¥,$n±»°üÎ§ÔÚÈÈÀËÖ®ÖÐ
$nÖ»¾õ¾Þ´óµÄÖËÈÈÆø¾¢ÈëÇÖÈ«Éí¾­ÂöÎÞ·¨ÄýÆø,¸Ð¾õÄÚÁ¦²»¶ÏµØÔÚÁ÷Ê§Ö®ÖÐ\n"NOR
      ,me,victim);
      victim->receive_damage("kee",500);
      victim->add("force",-200);
victim->apply_condition("burn",random(15)+1);
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
