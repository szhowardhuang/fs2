
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("[1;37m¼«¶³±ù·ï»Ë[0m",
        ({"ice-phoenix","ice","phoenix",}));
        set("mount_id","ice-phoenix");
        set("age",12);
        set("race","Ò°ÊŞ");
        set("score",1000000);
        set("gender","Å®ĞÔ");
set("level",1);
        set("rider","phoenix");
        setup();
}
string *dodge_msg = ({
HIB"$n"HIB"µÄÀ¶É«Â½ĞĞÄñÑğ×°ÒªÌÓ×ß"BLU"£¬"HIB"³Ã$N"HIB"²»×¢ÒâµÄ"BLU"£¬"
HIB"Ò»¸öË²¼ä$n"HIB"ÒÑ¶ã¹ı$N"HIB"µÄ¹¥»÷"BLU"¡£\n"NOR,
HIB"$n"HIB"ÍùÉÏÒ»Ìø"BLU"£¬"HIB"ÔÚ´ËË²¼äÀ¶É«Â½ĞĞÄñÍùÇ°³å"BLU"£¬"HIB"¹¥Æä²»Òâ"BLU"¡£\n"NOR,
});
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
