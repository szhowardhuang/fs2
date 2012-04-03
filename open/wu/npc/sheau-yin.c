#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
       set_name("ÈÎÏþÒ÷",({"sheauyin jen","sheauyin","jen"}));
       set("long","ËýÊÇÈÎÕýÇçµÄÅ®¶ù,ÈÎÏþÒ÷ , Äê¸ÕÂú¶þÊ®,ÇåÀöÍÑË×,¿´ÆðÀ´´ÏÃ÷ÁæÀþ,
ËäÊÇÅ®¶ù¼Ò, µ«ÊÇ¾«Í¨ÀñÒå,¼ÒÖÐ¾ÍÊôËý×î´ÏÃ÷¹ÔÇÉ¡£\n");
       set("gender","Å®ÐÔ");
       set("class","fighter");
       set("nickname","[1;33mÈÎÈáÍ¥[0m");
       set("combat_exp",200000);
       set("attitude","heroism");
       set("age",20);
       set("title","ãñÉ½ÅÉµÚ°Ë´úµÜ×Ó");
       set("str",23);
       set("cor",20);
       set("cps",40);
       set("per",100);
       set("int",50);
       set("con",55);
       set("spi",70);
       set("kar",27);
       set("force",960);
       set("max_force",960);
       set("max_s_kee",1000);
       set("sec_kee","dragon");
       set("force_factor",20);
        set_skill("lungshan", 60);
        set_skill("dodge"   , 50);
        set_skill("haoforce", 60);
        set_skill("force"   , 70);
        set_skill("unarmed", 40);
        set_skill("parry", 30);
        set_skill("henma-steps",60);
        set_skill("fire-kee",50);
        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
       setup();
       carry_object("/open/wu/npc/obj/goldfinger.c")->wield();
}
