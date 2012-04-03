inherit SKILL;
#include <ansi.h>
#include <array.h>
int mean;
int valid_enable(string usage) { return usage=="array"; }
void doing_array(object *member,object leader);
int form_array(object leader)
{
        object *member;
        int i,bandit=0,mean=0;
        int enable_array=0;
        int number;
        member = leader->query_team();
        if( sizeof(member) == 2)
             number = 2;
        else if( sizeof(member) == 3)
             number = 3;
        else if( sizeof(member) == 4)
             number = 4;
        else if (sizeof(member) == 5)
             number = 5;
        else
             return notify_fail("ÕâÖÖ»ìÕ½·½·¨»¹Ã»ÓĞÈËÑĞ¾¿³öÀ´À² !\n");
        if( leader->query_temp("use_form",1) )
             return notify_fail("ÄãÃÇÕıÔÚ´ò»ìÕ½¡£\n");
        for(i=0;i<sizeof(member);i++)
        if ( sizeof(member) == 2)
        {
if( leader->query("sen",1) > 30 && leader->query("bellicosity",1) > 50)
            {
              message_vision("[1;32m$N´óºÈÒ»Éù ,Ê©³öÁË¶ñÈËĞ°ÕóÖĞµÄ[1;33mÀÇ±·Îª¼é ,\n[1;32mÄãºÍÍ¬°éË²¼ä»¯³ÉÁ½µÀºÚÓ°Ïò¶ÔÊÖ³åÈ¥¡£[0m\n",leader);
              leader->add("sen",-20);
              doing_array(member,leader);
             }
           else
              message_vision("Äã¾«ÉñÁ¦²»×ãÒÔ´ò»ìÕ½\n",leader);
         }

        else if( sizeof(member) == 3)
         {
if( leader->query("sen",1) > 45 && leader->query("bellicosity",1) > 100)
              {
               message_vision("[1;32m$NÖ¸Ê¾ÖÚÈË×óÓÒ¿ñ´Ü£¬Ê©Õ¹¶ñÈËĞ°ÕóÖĞµÄ[1;34mÉñ³ö¹íÃ» ,\n[1;32mË²¼ä½«µĞÈË°üÎ§×¡¡£\n[0m\n",leader);
               leader->add("sen",-35);
               doing_array(member,leader);
              }
             else
               message_vision("Äã¾«ÉñÁ¦²»×ãÒÔ´ò»ìÕ½\n",leader);
          }

        else if( sizeof(member) == 4)
         {
if( leader->query("sen",1) > 50 && leader->query("bellicosity",1)> 150)
              {
               message_vision("[1;32m$N´øÁìÖÚÈËÊ©Õ¹¶ñÈËĞ°ÕóÖĞµÄ[1;35mÁúÉßÔÓ´¦\n[1;32mÔÚÒ»Ë²¼ä±ã»ìÏıµĞÈËÊÓÏß¡£[0m\n",leader);
               leader->add("sen",-40);
               doing_array(member,leader);
              }
             else
               message_vision("Äã¾«ÉñÁ¦²»×ãÒÔ´ò»ìÕ½\n",leader);
          }
        else if (sizeof(member) == 5)
         {
if( leader->query("sen",1) > 70 && leader->query("bellicosity",1)> 200)
             {
              message_vision("[1;32m$N´øÁìÖÚÈËÊ©³ö¶ñÈËĞ°ÕóÖĞµÄ[1;31m°Ù¹íÒ¹ĞĞ ,\n[1;32mºöÈ»·çÔÆ±äÉ«£¬·çÉ³´Ü·É¡£[0m\n",leader);
               leader->add("sen",-60);
               doing_array(member,leader);
              }
            else
               message_vision("Äã¾«ÉñÁ¦²»×ãÒÔ´ò»ìÕ½\n",leader);
         }
          return 1;

  }

void doing_array(object *member,object leader)
{
          int i;
          leader->set_temp("use_form",1);
          for(i= 0; i< sizeof(member);i++)
          if(present(member[i]->query("id"),environment(leader)))
            {
             member[i]->set_temp("use_form",1);
             }
       leader->start_call_out( (: call_other, __FILE__, "remove_array",
           member,leader :), 1+leader->query_skill("bad-array",1)/2);
}

void remove_array( object *member,object leader)
 {
    int i;
   if(leader->query_temp("use_form",1))
   {
     message_vision("[1;37m$NÍ»È»ĞÄÉñÒ»·Ö£¬´íÊ§³öÊÖÁ¼»ú£¬±ØĞëÖØĞÂÀ´¹ı¡£[0m\n",leader);
     for(i=0; i<sizeof(member);i ++)
       member[i]->delete_temp("use_form",1);
   }
  }
