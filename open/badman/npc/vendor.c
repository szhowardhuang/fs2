//vendor.c
#include "/open/open.h"
inherit F_VENDOR;

void create()
{
	set_name("小贩",({"vendor"}));
	set("gender", "男性" );
	set("age", 27);
set("long", @LONG

  四处设摊卖些小东西的人,你可以列出(list)他卖些什么...
  
LONG
	);
	set("no_kill",1);
	set("combat_exp",116);
        set("attitude", "friendly");
        set_skill("dodge", 25);
        set_skill("hammer", 17);
        set_skill("parry", 27);
	set("vendor_goods", ({
//   "/open/badman/obj/bird_food",
"/open/ping/obj/cloud",
		"/obj/example/wineskin",
		"/obj/example/dumpling",
		"/obj/example/chicken_leg",
                CENTER_OBJ"torch",
	}) );
        set("no_kill",1);
	setup();
        carry_object("/obj/example/chicken_leg")->wield();
        carry_object("/obj/cloth")->wear();
	add_money("coin",35);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                say("小贩嘶声么\喝道: "+RANK_D->query_respect(ob)
                        +"过来看看吗!?\n");
			break;
                case 1:
		say("小贩高声喊道: 跳楼大拍卖,"+RANK_D->query_respect(ob)
			+"要的话，我可以算便宜一点喔!\n");
			break;
	}
}
