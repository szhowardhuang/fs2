// fusword.c

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me, object victim, object  weapon, int damage);

string *parry_msg=
    ({
      "$nÊ¹³öÉñÁú¾øÑ§ÖÐµÄÉñÁú½£·¨£¬½«$NµÄÎäÆ÷µ´ÁË³öÈ¥¡£\n",
      "$nÊÖÖÐ³¤½£·ÉÎè£¬¡®µ±¡¯µÄÒ»Éù£¬½«$NµÄ¹¥ÊÆ¾¡ÊýµµÁËÏÂÀ´¡£\n",
      "$nÊÖÍó·­×ª£¬Ò»½£Æ½Æ½»÷³ö£¬ÇÉÃîµÄ»¯½âÁË$NµÄÕÐÊ½¡£\n",
      "$nÒ»½£»÷Ïò$NµÄÒªÑ¨£¬±ÆµÄ$N»ØÉíµ²½££¬ÕýÊÇ·ÀÓùÖ®×î¸ß¾³½ç\n",
    });
string *array_msg=
    ({
      "[1;33m$N´øÁì×ÅÖÚ½£Ê¿£¬½Å²È°ËØÔ£¬½£»¯Á½ÒÇ£¬½«ÉñÁú½£·¨·¢»Óµ½¼«ÖÂ¡£\n[0m",
      "[1;33mÖÚÈËÓúÕ½ÓúË³£¬ÓúÕ½ÓúÓÂ£¬ÁîµÐÈËÍûÖ®µ¨ÇÓ¡£\n[0m",
      "[1;33m$NÖ¸»ÓÈô¶¨£¬ÖÚÈË½£ÕÐÒ»ÕÐÕÐµÝÏòµÐÈË£¬ÅäºÏµÄÌìÒÂÎÞ·ì¡£\n[0m",
     }); 
mapping *action = ({
        ([      
                "action"     :               "$NÍ»È»ÁìÎòÁË¡®½£ËæÐÄ·¢¡¯µÄµÀÀí£¬¹­ÉíÇüÍÈÏòÇ°µ¯³ö£¬ÕýÊÇÒ»ÕÐ¡®ÈéÑà´©ÁÖ¡¯¡£",
                "dodge"      :               -25,
                "parry"      :                20,
                "damage"     :                250,
                "damage_type":               "´ÌÉË"
        ]),
        ([     
                "action"     :               "$NÎÕ½£Ö®ÊÖÒ»½ô£¬·ÜÁ¦ÏòÇ°´Ì³ö£¬Ò»ÕÐ¡®À×öªÍò¾û¡¯¹¥Ïò$n¡£",
                "dodge"      :               -30,
                "parry"      :                25,
                "damage"     :                300,
                "damage_type":               "´ÌÉË"
        ]),
        ([   
                "action"     :               "$NÆøÈç¾ÅÖéÐÐ±éÖÜÉí´óÑ¨£¬Á¦¹á½£¼â£¬ÆÍ²¼ºáÉ¨£¬ÕýÊÇÒ»ÕÐ¡®·çÆðÔÆÓ¿¡¯",
                "dodge"      :                -30,
                "parry"      :                30,
                "damage"     :                400,
                "damage_type":               "´ÌÉË"
        ]),
        ([  
                "action"     :               "$NÊÖÖÐÖ®½££¬»Ã»¯ÆðÎÞÊý½£È¦£¬»ô»ô½£¹â½«$n°üÎ§ÆäÖÐ£¬ÕýÊÇÒ»ÕÐ¡®ÔË×ªÇ¬À¤¡¯",
                "dodge"      :               -30,
                "parry"      :                30,
                "damage"     :                500,
                "damage_type":               "´ÌÉË"
        ]),
        ([ 
                "action"     :               "$NÄýÆøÓÚ½££¬ÊÖÖÐÖ®½£ºöÈ»ÏòÇ°·ÉÈ¥£¬ÕýÊÇÒ»ÕÐ¡®³¤ºç¹áÈÕ¡¯£¬È¥ÊÆÖ®¼²Ê¹$n²»¼°ÕÐ¼Ü",
                "dodge"      :               -30,
                "parry"      :                20,
                "damage"     :                650,
                "force"      :                130,
                "damage_type":               "¸îÉË"
        ]),
        ([
                "action"     :               "$NºöÈ»Ô¾ÆðÕÉÓà£¬ÓÉ°ë¿ÕÖÐÏò$n¼²¹¥¶øÖÁÕýÊÇÒ»ÕÐ¡®·ÉÁúÔÚÌì¡¯",
                "dodge"      :               -20,
                "parry"      :                35,
                "damage"     :                850,
                "force"      :                100,
                "damage_type":               "´ÌÉË"
        ]),
         ([     "action"     :               "$NÁËÎòÁË½£·¨ÉÏ¡®Á¬Ãà²»¾ø¡¯Ö®ÕæÒå£¬ÊÖÖÐÅå½£Ò»µ´Á¬Ê¹³ö¡®ÈéÑà´©ÁÖ¡¯¡®À×öªÍò¾û¡¯¡®·çÆðÔÆÓ¿¡¯£¬·Ö¹¥$nÖÜÉí´óÑ¨",
                "dodge"      :                -35,
                "parry"      :                30,
                "damage"     :                1000,
                "force"      :                100,
                "post_action":                (: berserk :),
                "damage_type":                "¸îÉË",
           ]),
          ([    "action"     :               "$NÁìÎòÁË¡®ÒÔÆøÓù½£¡¯Ö®ÕæÒå£¬ÔËÆøÓÚÖ¸¿ØÖÆ¿ÕÖÐÖ®½£¹¥Ïò$n¡£ÕýÊÇ´«ËµÖÐµÄ¡®Óù½£Êõ¡¯",
                "dodge"      :                -40,
                "parry"      :                40,
                "damage"     :                1100,
                "force"      :                110,
                "post_action":                (: berserk :),
                "damage_type":                "¸îÉË",
            ]),
            ([  "action"     :                "$NÁìÎòÁËËùÎ½¡®ÒÔ¾²ÖÆ¶¯¡¯£¬Á¢¼´ÐÄÈçÃ÷¾µ£¬¿´³ö$nµÄÆÆÕÀ£¬Ò»Á¬Ê¹³ö¡®ÈéÑà´©ÁÖ¡¯¡®À×öªÍò¾û¡¯¡®·çÆðÔÆÓ¿¡¯¡®ÔË×ªÇ¬À¤¡¯¡®³¤ºç¹áÈÕ¡¯½£ÆøÐÎ³ÉäöÎÐ½«$n°üÎ§ÆäÖÐ",
                "dodge"      :                -30,
                "parry"      :                45,
                "damage"     :                1500,
                "force"      :                120,
                "post_action":                (: berserk :),
                "damage_type":                "¸îÉË",
             ]),
             ([ "action"     :                "$NÒÑµÃ½£·¨¾«Òª£¬Ò»ÑÛ¿´¶Ô´©$nÖ®ÕÐÊ½£¬ËæÊÖÒ»½£±ãÆÆ½âËûµÄÕÐÊ½²¢½«ÆäÖØ´´£¬ÕýÊÇ½£·¨Ö®¼«ÖÁ¡®ÎÞÕÐÊ¤ÓÐÕÐ¡¯",
                "dodge"      :                -40,
                "parry"      :                45,
                "damage"     :                1700,
                "force"      :                120,
                "post_action":                (: berserk :),
                "damage_type":                "¸îÉË",
             ]),
            ([  "action"     :                "$NÃæÂ¶Î¢Ð¦£¬ÑöÊÓ²ÔÌì£¬´ý$n¹¥ÊÆÒÑ½ü£¬Ö»¼û¿ÕÖÐ½£»¨ÉÁÉÁ£¬$N´ÓÈÝµÄÊÕ½£»ØÇÏ£¬$nÈ´ÒÑÊÜµ½ÉíÊÜÖØÉË",
                "dodge"      :                -45,
                "parry"      :                50,
                "damage"     :                2000,
                "force"      :                130,
                "post_action":               (: berserk :),
                "damage_type":                "¸îÉË",
             ]),            
             
   });
int valid_learn(object me)
{
       if( !me->query_temp("weapon") )
        return   notify_fail("Á·ÉñÁú½£Êõ±ØÐèÏÈÄÃ°Ñ½£¡£\n");
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="sword" || usage=="parry" );
}

string query_parry_msg(string limb)
{
  int parry_pow;
  object me;
  me=this_player();
        parry_pow = (int)( me->query_skill("fuswords", 1)/10);
          if ( parry_pow <= 5)
                return parry_msg[random(2)];
            else

                return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
       int skill_level, limit,i;
	   object victim,*enemy;
		enemy = me->query_enemy();
		i=sizeof(enemy);
        victim = enemy[random(i)];
        skill_level = (int)(me->query_skill("fuswords", 1));
        limit= (int)(skill_level/8);
        if( me->query_temp("use_form",1))
          message_vision( array_msg[random(sizeof(array_msg))],me );
if(me->query_temp("weapon"))
{
 weapon=me->query_temp("weapon");  //¿Û×Ô¼ºforce 200
if((me->query("class")=="dancer")&&(weapon->query("id")=="dragon sword"))
  {
if(me->query("id")==("cgy"))
{
message_vision(HIC"$NÊ¹³öÉñÁú½£·¨ÖÕ¼«°ÂÒå,Ö»¼ûÒ»Ìõ»ðÁú³¯×Å$nÖ±ÆË¶øÈ¥\n"NOR,me,victim);
message_vision(HIR"                                        &.  &.     .\n"NOR,me,victim);
message_vision(HIR"                                        ~ss.&ss. .s'\n"NOR,me,victim);
message_vision(HIR"                                .     .ss&&&&&&&&&&s.\n"NOR,me,victim);
message_vision(HIR"                                &. s&&&&&&&&&&&&&&`&&Ss\n"NOR,me,victim);
message_vision(HIR"                                ~&&&&&&&&&&&&&&&&&&o&&&       .\n"NOR,me,victim);
message_vision(HIR"                               s&&&&&&&&&&&&&&&&&&&&&&&&s.  .s\n"NOR,me,victim);
message_vision(HIR"                              s&&&&&&&&&~&&&&&&~~~~&&&&&&~&&&&&.\n"NOR,me,victim);
message_vision(HIR"                              s&&&&&&&&&&s~~&&&&ssssss~&&&&&&&&~\n"NOR,me,victim);
message_vision(HIR"                             s&&&&&&&&&&'         `~~~ss~&~&s~~\n"NOR,me,victim);
message_vision(HIR"                             s&&&&&&&&&&.              `~~~~~&  .s&&s\n"NOR,me,victim);
message_vision(HIR"                             s&&&&&&&&&&&&s....               `s&&'  `\n"NOR,me,victim);
message_vision(HIR"                         `ssss&&&&&&&&&&&&&&&&&&&&####s.     .&&~&.   . s-\n"NOR,me,victim);
message_vision(HIR"                           `~~~~&&&&&&&&&&&&&&&&&&&&#####&&&&&&~     &.&'\n"NOR,me,victim);
message_vision(HIR"                                 ~&&&&&&&&&&&&&&&&&&&&&####s~~     .&&&|\n"NOR,me,victim);
message_vision(HIR"                                  ~&&&&&&&&&&&&&&&&&&&&&&&&##s    .&&~ &\n"NOR,me,victim);
message_vision(HIR"                                   &&~~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&~   `\n"NOR,me,victim);
message_vision(HIR"                                  &&~  ~&~&&&&&&&&&&&&&&&&&&&&S~~~~'\n"NOR,me,victim);
message_vision(HIR"                             .   .~     '  &&&&&&&&&&&&&&&&####s\n"NOR,me,victim);
message_vision(HIR"                             &.          .s&&&&&&&&&&&&&&&&&####~\n"NOR,me,victim);
message_vision(HIR"                 .           ~&s.   ..ssS&&&&&&&&&&&&&&&&&&&####~\n"NOR,me,victim);
message_vision(HIR"                 &           .&&&S&&&&&&&&&&&&&&&&&&&&&&&&#####~\n"NOR,me,victim);
message_vision(HIR"                 Ss     ..sS&&&&&&&&&&&&&&&&&&&&&&&&&&&######~~\n"NOR,me,victim);
message_vision(HIR"                  ~&&sS&&&&&&&&&&&&&&&&&&&&&&&&&&&########~\n"NOR,me,victim);
message_vision(HIR"           .      s&&&&&&&&&&&&&&&&&&&&&&&&#########~~'\n"NOR,me,victim);
message_vision(HIR"           &    s&&&&&&&&&&&&&&&&&&&&&#######~~'      s'         .\n"NOR,me,victim);
message_vision(HIR"           &&..&&&&&&&&&&&&&&&&&&######~'       .....&&....    .&\n"NOR,me,victim);
message_vision(HIR"            ~&&&&&&&&&&&&&&&######~' .     .sS&&&&&&&&&&&&&&&&s&&\n"NOR,me,victim);
message_vision(HIR"              &&&&&&&&&&&&#####~     &. .s&&&&&&&&&&&&&&&&&&&&&&&&s.\n"NOR,me,victim);
message_vision(HIR"   )          &&&&&&&&&&&#####'      `&&&&&&&&&###########&&&&&&&&&&&.\n"NOR,me,victim);
message_vision(HIR"  ((          &&&&&&&&&&&#####       &&&&&&&&###~       ~####&&&&&&&&&&\n"NOR,me,victim);
message_vision(HIR"  )\\         &&&&&&&&&&&&####.     &&&&&&###~             ~###&&&&&&&&&   s'\n"NOR,me,victim);
message_vision(HIR" (   )        &&&&&&&&&&&&&####.   &&&&&###~                ####&&&&&&&&s&&'\n"NOR,me,victim);
message_vision(HIR" )  ( (       &&~&&&&&&&&&&&#####.&&&&&###'                .###&&&&&&&&&&~\n"NOR,me,victim);
message_vision(HIR" (  )  )   _.&~   &&&&&&&&&&&&######.&&##'                .###&&&&&&&&&&\n"NOR,me,victim);
message_vision(HIR" ) (  ( \\.         ~&&&&&&&&&&&&&#######....          ..####&&&&&&&&&&&~\n"NOR,me,victim);
message_vision(HIR"(   )& )  )        .&&&&&&&&&&&&&&&&&&####################&&&&&&&&&&&~\n"NOR,me,victim);
 message_vision(HIR"(   (&&  ( \\     _sS~  `~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&S&&.\n"NOR,me,victim);
message_vision(HIR" )  )&&&s ) )  .      .   `&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&~'  `&&\n"NOR,me,victim);
message_vision(HIR"  (   &&&Ss/  .&.    .&..s&&&&&&##S&&&&&&&&&&&&&&&&&&&&&&&&S~~        '\n"NOR,me,victim);
message_vision(HIR"    \\)_&&&&&&&&&&&&&&&&&&&&&&&##~  &&        `&&.        `&&.\n"NOR,me,victim);
message_vision(HIR"        `~S&&&&&&&&&&&&&&&&&#~      &          `&          `&\n"NOR,me,victim);
message_vision(HIR"            `~~~~~~~~~~~~~'         '           '           '\n\n\n"NOR,me,victim);

 
message_vision(HIR"$n±»»ðÁúËùÍÌÊÉ,Ë²Ê±È«ÉíÊÇ»ðÍ´¿à²»¼º¡£\n"NOR,me,victim);
victim->add("kee",-100000);
victim->apply_condition("burn",random(10));
COMBAT_D->report_status(victim, 1);
  

me->add("force",-200);
}
}
}
        if (limit < 1 )
                return action[random(1)];
        if (limit < 2 )
                return action[random(2)];
        if (limit < 3)
                return action[random(3)];
        if (limit < 4)
                return action[random(4)];
        if (limit <5 )
                return action[random(4)+1];
        if (limit <6 )
                return action[random(4)+2];
        if (limit <7)                        
                return action[random(4)+3];
        if (limit <8)
                return action[random(4)+4];
        if (limit <9)
                return action[random(4)+5];
        if (limit <10)
                return action[random(4)+6];
        else
                return action[random(4)+6];
}

void berserk(object me, object victim, object  weapon, int damage)
{ 
     if( (int)me->query_skill("fuswords",1) > random(60)+35 && me->query("force_factor")>= random(5) && me->query("force")>30)
        { 
         if(!me->query_temp("berserk" ))
          {
             if(me->query("name")=="¸µ½£º®")
             {
              message_vision( sprintf("[1;33mÖ»¼û$N½£ÕÐÒ»»º£¬Íòµã½£¹âÙ¿È»ÏûÊ§£¬»¯ÎªÒ»µÀ½£ºçÏò×Å$nµÄÐØÇ°¿ñ±¼¶øÈ¥£¬ÕýÊÇÒ»ÕÐ¡®ÍòÁ÷¹é×Ú¡¯¶Ô$nÔì³ÉÁËÄª´óµÄÉËº¦¡£\n [0m"), me ,victim);
              victim->add("kee",-120);
              me->add("force",-10);
              }
                me->set_temp("berserk", 1);
            }
             me->delete_temp("berserk");
          }
      
} 


int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}
