
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("[31m¼«Ñæ»ğ·ï»Ë[m",
        ({"fire-phoenix","fire","phoenix",}));
        set("mount_id","fire-phoenix");
        set("age",12);
        set("race","Ò°ÊŞ");
        set("score",1000000);
        set("gender","Å®ĞÔ");
set("level",1);
        set("rider","phoenix");
        setup();
}
string *dodge_msg = ({
"[47;30m$n[47;30mµÄºÚÉ«Â½ĞĞÄñÑğ×°ÒªÌÓ×ß[1m£¬[;47;30m³Ã$N[47;30m²»×¢ÒâµÄ"
"[1m£¬[;47;30mÒ»¸öË²¼ä$n[47;30mÒÑ¶ã¹ı$N[47;30mµÄ¹¥»÷[1m¡£[m\n",
"[47;30m$n[47;30mÍùÉÏÒ»Ìø[1m£¬[;47;30mÔÚ´ËË²¼äºÚÉ«Â½ĞĞÄñÍùÇ°³å[1m£¬"
"[;47;30m¹¥Æä²»Òâ[1m¡£[m\n",
});
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
