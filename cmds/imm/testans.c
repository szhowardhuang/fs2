inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me,string arg)
{


      if(!wizardp(me) && !me->query("bss_test_char"))      
        return 0;

      "/std/char.c"->check_robot();
      return 1;
}
