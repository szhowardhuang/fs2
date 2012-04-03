//wu-array.c Îäµ±½£Õó
#include <ansi.h>
inherit SKILL;
int valid_enable(string usage) { return usage=="array";} 
void sp_attack(int number);
void doing_array(object *,object );
int mean;
int form_array(object leader)
{
   object *member;
   int i;
   int enable_array=0;
   int number;
   member = leader->query_team();
   if( sizeof(member) == 2 )
      number =2;
   else if( sizeof(member)==3)
      number=3;
   else if( sizeof(member)==4)
      number=4;
   else if( sizeof(member)==7)
      number=7;
   else if( sizeof(member)==8)
      number=8;
   else
      return notify_fail("ÈËÊı²»×ã, ÎŞ·¨×é³É½£Õó¡£\n");
   if( leader->query_temp("use_form",1) )
      return notify_fail("½£ÕóÕıÔÚÊ©Õ¹ÖĞ¡£\n");
   if( ( string)leader->query("skill_type") !="sword")
      return notify_fail("¶Ó³¤Ã»³Ö½£, ÑÉÄÜ³É½£Õó¡£\n");
   for( i=0; i<sizeof(member); i++)
   {
      if( sizeof(member) == 2 )
      {
         if( leader->query("sen",1) > 20)
         {
            message_vision("[1;32m$N´øÁìÖÚÈËÕ¹¿ªÁ½ÒÇ×·ĞÇ½£Õó¡£[0m\n", leader);
            leader->add("sen", -20);
            doing_array( member, leader);
         }
         else
            message_vision("[1mÄã¾«Éñ²»×ã, ÎŞ·¨Æô¶¯½£Õó\n[0m",leader);
      }
      if( sizeof(member) == 3 )
      {
         if( leader->query("sen",1) > 30)
         {
            message_vision( "[1;32m$N´øÁìÖÚÈËÕ¹¿ªÌìµØÈËÈı²Å½£Õó¡£[0m\n", leader);
            leader->add("sen", -30);
            doing_array( member, leader);
         }
         else
            message_vision("[1mÄã¾«Éñ²»×ã, ÎŞ·¨Æô¶¯½£Õó\n[0m",leader);
      }
      if( sizeof(member) == 4 )
      {
         if( leader->query("sen",1) > 40)
         {
            message_vision("[1;32m$N´øÁìÖÚÈËÕ¹¿ªËÄÏóĞıí¶½£Õó¡£[0m\n", leader);
            leader->add("sen",-40);
            doing_array( member, leader);
         }
         else
            message_vision("[1mÄã¾«Éñ²»×ã, ÎŞ·¨Æô¶¯½£Õó\n[0m",leader);
      }
      if( sizeof(member) == 7 )
      {
         if( leader->query("sen",1) > 50)
         {
            message_vision("[1;32m$N´øÁìÖÚÈËÕ¹¿ªÕæÎäÆß½ØÕó¡£[0m\n", leader);
            leader->add("sen",-50);
            doing_array( member, leader);
         }
         else
            message_vision("[1mÄã¾«Éñ²»×ã, ÎŞ·¨Æô¶¯½£Õó\n[0m",leader);
      }
      if( sizeof(member)==8)
      {
         if( leader->query("sen",1) > 60)
         {
            message_vision("[1;32m$N´øÁìÖÚÈËÕ¹¿ª°ËØÔÓÎÁú½£Õó¡£[0m\n", leader);
            leader->add("sen",-60);
            doing_array( member, leader);
         }
         else
            message_vision("[1mÄã¾«Éñ²»×ã, ÎŞ·¨Æô¶¯½£Õó\n[0m",leader);
      }
   }
   return 0;
}

void doing_array(object *member,object leader)
{
   int i;
   leader->set_temp("use_form",1);
   for(i= 0; i< sizeof(member); i++)
      if( present(member[i]->query("id"), environment(leader)))
         member[i]->set_temp("use_form",1);
   leader->start_call_out( (: call_other, __FILE__, "remove_array", member,leader :), random(10)+leader->query_skill("wu-array",1));
}

void remove_array( object *member,object leader)
{
   int i;
   if(leader->query_temp("use_form",1))
   {
      message_vision("[1m$NÍ»È»ĞÄÉñÒ»·Ö, ½Å²½Ò»¸öÌ¤´í, ½£ÒÑ²»³ÉÕó, ½£Õó±ØĞëÖØ×é¡£\n[0m",leader);
      for(i=0; i<sizeof(member); i++)
         member[i]->delete_temp("use_form",1);
   }
}
