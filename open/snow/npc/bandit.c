#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
          set_name("流寇",({"bandit"}));
         set("long","他是一个历尽世间风霜,饱受惊吓的流寇,由于头目被官差杀了,所以躲在此处不敢外出。\n");
		set("gender","男性");
	set("combat_exp",775);
          set("attitude","aggressive");
          set("age",30);
          set("score",100);
               set("str", 25);
                set("cor", 30);
                set("per", 20);
                set("int", 10);
                set("cps", 10);
          set("bellicosity",10000);
          set_skill("dodge",10);
set_skill("sword",20);
set_skill("parry",10);
	setup();
        carry_object(SNOW_OBJ"longsword")->wield();
}

