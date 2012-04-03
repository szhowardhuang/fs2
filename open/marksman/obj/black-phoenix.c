
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("[1;47;30m¼«ÒşÑÖ·ï»Ë[0m",
        ({"black-phoenix","black","phoenix",}));
        set("mount_id","black-phoenix");
        set("age",12);
        set("race","Ò°ÊŞ");
        set("score",1000000);
        set("gender","Å®ĞÔ");
set("level",1);
        set("rider","phoenix");
        setup();
}
string *dodge_msg = ({
HIR"$n"HIR"µÄºìÉ«Â½ĞĞÄñÑğ×°ÒªÌÓ×ß"RED"£¬"HIR"³Ã$N"HIR"²»×¢ÒâµÄ"RED"£¬"
HIR"Ò»¸öË²¼ä$n"HIR"ÒÑ¶ã¹ı$N"HIR"µÄ¹¥»÷"RED"¡£\n"NOR,
HIR"$n"HIR"ÍùÉÏÒ»Ìø"RED"£¬"HIR"ÔÚ´ËË²¼äºìÉ«Â½ĞĞÄñÍùÇ°³å"RED"£¬"HIR"¹¥Æä²»Òâ"
RED"¡£\n"NOR,
});
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
