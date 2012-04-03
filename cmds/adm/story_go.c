#include <ansi.h>
inherit F_CLEAN_UP;
void create()
{
        seteuid(getuid());
}
int main(object me, string arg)
{
    "/adm/daemons/storyd.c"->test_story();
    return 1;
}


