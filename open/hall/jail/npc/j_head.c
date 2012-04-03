
//j_master.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("óãÊëÂä", ({"jail master","master"}));
        set("title", "ÀÎ·¿Í³Áì");
        set("nickname", "[36mÒ»Ç®Ò»Ãü[0m");
        set("long",@LONG
    Ò»¸öÉí×Å¶ÌÉÀµÄ±ëĞÎ¾Şºº£¬ÉíÉÏÅä×ÅÒ»°ÑÁÁÉÁÉÁµÄ¸Öµ¶£¬ºÃÏñ
»áÁ½ÏÂ×ÓµÄÑù×Ó!!ËûÊÇÀÎ·¿µÄÍ·Í·£¬Äã¿ÉÒÔÎÊÎÊ¿´ÊêÈËµÄÏûÏ¢¡£
LONG);
        set("gender", "ÄĞĞÔ");

        set("age", 35);
        set("attitude", "peaceful");
        set("score", 200000);
        set("combat_exp", 70000);

        set("str", 30);
        set("max_gin", 2000);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("inquiry", ([
            "ÊêÈË" : "ÒªÊêÈË!!??Ã»ÎÊÌâ...³ıÁËËÀÀÎÀïµÄÎÒÃ»°ì·¨...ÆäËûÒ»ÂÉÒ»°ÙÁ½!!²»¶ş¼Û!!ºÙºÙ..",
        ]) );

        setup();

        set("chat_chance", 5);
        set("chat_msg", ({
            "Ã»É¶ÊÂ¾Í¿ì¹ö!!ÀÏ×ÓºÜÃ¦....Ã»¿Õ¸úÄãÃÇÕâĞ©¹ê¶ù×ÓÏ¹³¶!!\n",
            "É¶ÊÂ!!¿ìËµ!!\n",
        }));
}

