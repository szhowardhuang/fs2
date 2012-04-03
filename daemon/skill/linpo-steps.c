// linbo-steps.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg =
({
"$nÕ¹¿ª[1;36m¡®Áè²¨Î¢²½¡¯[0m£¬×ó×ã¿ç³ö£¬¼ÈÌ¤[1m¡¸ÖĞæÚ¡±[0m£¬Á¢×ª[1m¡¸¼È¼Ã¡±[0m£¬[1;33m¡¸Éñ¹âÀëºÏ£¬Õ§ÒõÕ§Ñô¡±[0m£¬Ğ±Ğ±µÄ¶ã¹ı$N¡£\n",
"Ö»¼û$nÊ©Õ¹[1;36m¡®Áè²¨Î¢²½¡¯[0m£¬¸¦ÉÏ[1m¡¸Ì©¡±[0mÎ»£¬Ò»¸ö×ªÉí£¬ÓÒ½ÅÌ¤ÉÏ[1m¡¸¹Æ¡±[0mÎ»£¬[1;33m¡¸ÌåÑ¸·ÉğÕ£¬Æ®ºöÈôÉñ¡±[0m£¬·´¶øÈÆµ½$NÉíºó¡£\n",
"$nÌ¤³ö[1;36m¡®Áè²¨Î¢²½¡¯[0m£¬×ãÏÂ×ÔÈ»¶øÈ»×Ô[1m¡¸¾®¡±[0mÎ»Ğ±ĞĞ£¬Ì¤µ½ÁË[1m¡¸ËÏ¡±[0mÎ»£¬[1;33m¡¸ä³ÇáÇûÒÔº×Á¢£¬Èô½«·É¶øÎ´Ïè¡±[0m£¬ÇáÇáËÉËÉµØ¶ã¹ı$NµÄÕĞÊ½¡£\n",
"$nÊ¹³ö[1;36m¡®Áè²¨Î¢²½¡¯[0m£¬×Ô[1m¡¸Ô¥¡±[0mÎ»Ì¤[1m¡¸¹Û¡±[0mÎ»£¬[1;33m¡¸ôæÈô¾ªºè£¬ÍñÈôÓÎÁú¡±[0m£¬ÉÁÉí´Ó$NÉíÅÔÈÆ¹ı¡£\n",
"$nÕ¹ÏÖ[1;36m¡®Áè²¨Î¢²½¡¯[0m£¬¸ú×ÅĞ±Ì¤[1m¡¸¹Æ¡±[0mÎ»£¬[1;33m¡¸ºöÑÉ×İÌå£¬ÒÔåÛÒÔÎû¡±[0m£¬Éí×ÓÇáÇáÆ®ÁË¿ªÈ¥¡£\n",
"$nĞ±Ì¤[1;36m¡®Áè²¨Î¢²½¡¯[0m£¬ºö¸ßºöµÍ£¬ÓĞÈô[1;33m¡¸ó„·ğÙâÈôÇáÔÆÖ®±ÎÔÂ£¬Æ®Æ®ÙâÈôÁ÷·çÖ®»ØÑ©¡±[0m°ã¡£\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge")||(usage=="move");
}

int valid_learn(object me)
{
        if(me->query_skill("literate",1)*2 <= me->query_skill("linpo-steps",1))
        {
          write("ÄãµÄÖªÊ¶²»×ã£¬ÎŞ·¨Ìå»áÁè²¨Î¢²½ÖĞÒ×¾­ÁùÊ®ËÄØÔµÄ¾«Òª±ä»¯¡£\n");
          return 0;
        }
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("ÄãµÄÆø²»¹»£¬²»ÄÜÁ·Áè²¨Î¢²½¡£\n");
        me->receive_wound("kee",5);
        return 1;
}
/*Ï£ÍûÄÜÉè¼Æ³É¿¼ÂÇÒÔÏÂ
1.³ö¿ÚµÄ¸öÊı
2.µĞÈËµÄexpºÍ×Ô¼ºµÄexp
3.ÊÇ·ñÕæµÄÓĞÊ¹ÓÃlinpo-stepsÔÚdodge and moveÉÏ
*/
int can_flee(object me,int exit_number)
{
    object *enemy;
    int i,enemy_num,enemy_exp,me_exp,ratio;

    if(!me) return 0;
    if(!me->query("marks/linpo-steps")) return 0;
    if(me->query("force") <100) return 0;
    if(me->query_skill_mapped("dodge") != "linpo-steps" ||
       me->query_skill_mapped("move") != "linpo-steps") return 0;
    enemy=me->query_enemy();
   if(!sizeof(enemy)) return 0;
/*
    if(sizeof(enemy) <1){
     message_vision(
"$NºöÈ»ÁìÎò"HIC"¡®Áè²¨Î¢²½¡¯"NOR"µÄÒªÖ¼ËùÔÚ£¬½Å²½×÷µ½"HIY"¡¸¶¯ÎŞ³£Ôò£¬ÈôÎ£Èô°²£¬½øÖ¹ÄÑÆÚ£¬
ÈôÍùÈô»¹¡±"NOR",ö®Ê±Ò»Æ¬ÈËÓ°·×·É£¬ÈÃµĞÈËÍ·»èÑÛ»¨\n",me);
     message_vision(HIM"$N"HIM"¿´×¼Ê±»ú£¬Ê¹³öÁè²¨Î¢²½£¬ÌÓÀëÕ½È¦!!\n"NOR,me);
     return 1;
    }
*/
    me_exp=me->query("combat_exp");
    enemy_exp=0;
    enemy_num=0;
    for(i=0;i<sizeof(enemy);i++){
      if(!enemy[i]) continue;
      if(enemy[i]->query("combat_exp") < (int)(me_exp*2/3)) continue;
      enemy_exp+=enemy[i]->query("combat_exp");
      enemy_num++;
    }
    if(!enemy_num){
     message_vision(
"$NºöÈ»ÁìÎò"HIC"¡®Áè²¨Î¢²½¡¯"NOR"µÄÒªÖ¼ËùÔÚ£¬½Å²½×÷µ½"HIY"¡¸¶¯ÎŞ³£Ôò£¬ÈôÎ£Èô°²£¬½øÖ¹ÄÑÆÚ£¬
ÈôÍùÈô»¹¡±"NOR",ö®Ê±Ò»Æ¬ÈËÓ°·×·É£¬ÈÃµĞÈËÍ·»èÑÛ»¨\n",me);
     message_vision(HIM"$N"HIM"¿´×¼Ê±»ú£¬Ê¹³öÁè²¨Î¢²½£¬ÌÓÀëÕ½È¦!!\n"NOR,me);
     return 1;
    }
    enemy_exp/=enemy_num;
    if(exit_number >=4) ratio=100;
    if(exit_number ==3) ratio=82;
    if(exit_number ==2) ratio=66;
    if(exit_number ==1) ratio=50;
    if(exit_number ==0) return 0;
    if(!me->is_busy() && ratio > random(110) && me->query("kee")<=(me->query("max_kee")/3)) {
      if(enemy_exp < me_exp * 2){
       message_vision(
"$N ĞÄÖĞÄ¬Äî£¬½«"HIC"¡®Áè²¨Î¢²½¡¯"NOR"µÄÁùÊ®ËÄØÔ²½·¨£¬×Ô¡¸Ã÷ÒÄ¡±ÆğÊ¼£¬¾­¡¸êÚ¡±
 ¡¢¡¸¼È¼Ã¡±¡¢¡¸¼ÒÈË¡±£¬×ßÁËÒ»´óÈ¦¶øÖÁ¡¸”úÍı¡±£¬ÖÕÓÚË³Àû°Ú\ÍÑµĞÈËµÄ¾À²ø¡£\n"NOR,me);
        message_vision(HIM"$N"HIM"¿´×¼Ê±»ú£¬Ê¹³öÁè²¨Î¢²½£¬ÌÓÀëÕ½È¦!!\n"NOR,me);
        me->add("force",-200);
        return 1;
      }
      else{
        if((100*me_exp/enemy_exp) > random(110)){
          me->add("force",-200);
       message_vision(
"$N ĞÄÖĞÄ¬Äî£¬½«"HIC"¡®Áè²¨Î¢²½¡¯"NOR"µÄÁùÊ®ËÄØÔ²½·¨£¬×Ô¡¸Ã÷ÒÄ¡±ÆğÊ¼£¬¾­¡¸êÚ¡±
 ¡¢¡¸¼È¼Ã¡±¡¢¡¸¼ÒÈË¡±£¬×ßÁËÒ»´óÈ¦¶øÖÁ¡¸”úÍı¡±£¬ÖÕÓÚË³Àû°Ú\ÍÑµĞÈËµÄ¾À²ø¡£\n"NOR,me);
          message_vision(HIM"$N"HIM"¿´×¼Ê±»ú£¬Ê¹³öÁè²¨Î¢²½£¬ÌÓÀëÕ½È¦!!\n"NOR,me);
          return 1;
        }
      }
    }
    return 0;
}
