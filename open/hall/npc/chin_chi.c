
inherit NPC;
#include <ansi.h>

void create()
{
set_name("ÇØ  ¼É", ({ "chin chi", "chin", "chi" }));
        set("title", "ÏØÑÃÈý²¶Í·");
        set("nickname","[1;34m×·»êÇ¹[0m");
        set("age", 23);
        set("str", 25);
        set("cor", 20);
        set("cps", 20);
        set("int", 20);
        set("spi", 20);
        set("kar", 24);
        set("per", 20);
        set("con", 30);

        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 3);

        set("long", @LONG
    Ò»Î»Éí²Ä°«Ð¡µÄÄÐ×Ó£¬ÑÛÖÐÍ¸×ÅÒþÒþµÄÉ±Æø£¬ÔÚËûµÄÉí±ßÊ¹Äã¸Ðµ½
ºÜ²»×ÔÔÚ¡£¾ÝËµËûÔøÎªÁË×·Ò»¸ö½­Ñó´óµÁ£¬Ö»ÉíÉ±½øºÚ·çÕ¯£¬ÔÚÒ»Æ¬ÐÈ
·çÑªÓêÏÂÔ×ÁËÄÇ´óµÁ£¬Ôì³ÉÎäÁÖÒ»Ê±µÄºä¶¯!!
LONG);
        set("combat_exp", 150000);
        set("score",  3000);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        "ºÙºÙ....!!  ¹Ô¹ÔµØÎ¹ÎÒµÄÇ¹°É!!\n",
        "¿´¡®×·»êÁùÊ½¡¯!!  ÊÜËÀ°É!!\n"
        }) );

        set_skill("unarmed", 20);
        set_skill("force",  60);
        set_skill("parry",  40);
        set_skill("dodge",  60);
        set_skill("sword",  30);
        set_skill("literate", 20);

        set("inquiry", ([
                "×·»êÇ¹" : "ºÙºÙ!!ÏëÒªÎÒµÄÇ¹Âð?!ÄÃÄãµÄÃüÀ´»»°É!!",
        ]) );

        setup();
        carry_object(__DIR__"obj/g_lance")->wield();
        carry_object(__DIR__"obj/b_suit")->wear();
}
