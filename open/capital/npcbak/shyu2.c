// guard.c

#include <ansi.h>
#include </open/open.h>

inherit NPC;
void create()
{
                  set_name("徐大夫", ({ "doctor shyu","doctor","shyu" }) );
	set("gender", "男性" );
        set("age",45);
        set("str",35);
        set("cor",35);
	set("cps", 25);
	set("int", 15);
     set("long","刚从宫内退休的徐大夫,专门帮人剪烂佛,\n"
                 "你可以问他有关整容的事情。\n");
	set("combat_exp",338);
	set("attitude", "peaceful");
        set("inquiry", ([
            "变性"    :"如果你准备好了,就下 change 指令,好让我开始手术。",
            "整容"    :"整容喔!!那是我儿子的专长,我可不会,别想叫我退费哦。",
            "退费"    :"退你妈的头啦！",
        ]) );
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        carry_object("/obj/cloth")->wear();
}

