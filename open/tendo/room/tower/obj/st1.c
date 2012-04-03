#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"[1;37m¡õ[1;31mÌ«¼«¹÷[0m",({"stick"}));
        else
         { set_name("[1;31mÌ«¼«¹÷[0m",({"stick"})); }
        seteuid(getuid());
        set_weight(8000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

        Ì«¼«¹÷ÊÇÒ»Á½¶Ë¿ÌÓĞÌ«¼«Í¼ÑùµÄÁù³ß´óÍ­¹÷!!»ÓÎèÆğÀ´
        ÓĞÈçÒ»ÍÅµÄ»Æ¹â, ¿ÉÒÔ¾¡Êıµ²×¡µĞÈËµÄ¹¥»÷!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
        set("wield_msg", "$N¡¸à§¡±µØÒ»Éù³é³öÒ»°Ñ$nÎÕÔÚÊÖÖĞ¡£\n");
        }
        init_stick(50);
        setup();
}

int query_autoload() { return 1; }



