inherit NPC;
#include <ansi.h>

void create()
{
set_name("ÉñËã×Ó", ({ "accounter"}));
        set("title", "ÑÃÃÅÊ¦Ò¯");
        set("gender", "ÄÐÐÔ" );
        set("nickname","[1;33m¾ÅÃæÁáçç[0m");
        set("age", 46);
        set("str", 50);
        set("cor", 50);
        set("cps", 50);
        set("int", 50);
        set("spi", 50);
        set("kar", 50);
        set("per", 50);
        set("con", 50);

        set("max_atman", 5000);
        set("max_force", 5000);
        set("max_mana", 5000);
        set("atman", 5000);
        set("force", 5000);
        set("mana", 5000);
        set("force_factor", 5);

        set("long", @LONG
    ÎÞ³¾´óÈËµÄµÃÁ¦ÖúÊÖ£¬ÓÐ×Å¶ÁÊéÈËµÄ¸ß·åÁÁ½Ú·ç·¶£¬¾ÝËµËûÒ²ÊÇ¸ö
Éî²Ø²»Â¶µÄ¸ßÊÖ£¬²»Öª´«ÑÔÊÇ·ñÈ·Êµ??²»¹ý£¬ËûµÄÈ·°ïÁË°ÙÐÕ²»ÉÙµÄÃ¦
Æ½³£°ÙÐÕÒ²ºÜ¾´ÖØÖ®¡£
LONG);

        set("combat_exp", 20000);
        set("score", 30000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        "Ô©Ô©Ïà±¨ºÎÊ±ÁË¡«¡«\n",
        "²»Òª×öÎÞÎ½µÄÕõÔúÁË°É!!\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("literate", 90);

        set("inquiry", ([
          "¼ÍÎÞ³¾" : "à¸¡«ÄãÊÇÎÊÎÞ³¾´óÈËà¸! ËûÊÇºÃ¹Ùà¸!!",
	  "thief"  : "àÅ..ÕâÃû´óµÁ¿É°ÑÎÒÃÇÎÞ³¾´óÈË¸øÕû²ÒÁË, Á¬»ÊÉÏ¶¼ÖªµÀÁË, °¦..",
	]) );

        setup();
        carry_object(__DIR__"obj/o_cloth")->wear();
}
