// special.c

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me, string arg)
{
	object obj, old_target;
        seteuid(getuid());
          if(!me->query("sec_kee"))
                return notify_fail("你的身上没有灵气。\n");
	SEC_KEE_D(me->query("sec_kee"))->kee_spe(me);
	return 1;
}
 
int help(object me)
{
    write(@HELP
 
指令格式：special
 
说明：这个指令让你可以使用灵气的特殊功能。
 
HELP
);
     return 1;
}
