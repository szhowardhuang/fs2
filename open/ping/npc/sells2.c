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
	set("combat_exp",800);
        set("attitude", "friendly");
        set_skill("dodge", 25);
        set_skill("hammer", 17);
        set_skill("parry", 27);
	set("vendor_goods", ({
                COMMON_OBJ"bandage",
                COMMON_OBJ"pill",
                COMMON_OBJ"pill1",
                COMMON_OBJ"plaster",
                PING_OBJ"cloud",
                CAPITAL_OBJ"tea",
		"/obj/example/wineskin",
		"/obj/example/dumpling",
		"/obj/example/chicken_leg",
	}) );
	setup();
        carry_object("/obj/example/chicken_leg")->wield();
        carry_object("/open/gsword/obj/robe")->wear();
	add_money("coin",35);
}

void greeting(object ob)
{
	int gender,per;
	gender = 0;
	per = ob->query("per");
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("gender") == "女性")
	  gender = 1;
	switch( random(3) ) {
		case 0:
                if( per < 18 && gender)
	          say("小贩靠近你小声的说: 唉! "+ob->name(1)
                       +",也许妳该去一下媚登峰!\n");

		say("小贩靠近你小声的说: 这位"+RANK_D->query_respect(ob)
                        +"来买些东西吧!\n");
			break;
		case 1:
                if( per > 22 )
                   say("小贩嘶声么喝道: "+ob->name(1)
                        +"长的好像电影明星喔!\n");

                say("小贩嘶声么喝道: "+RANK_D->query_respect(ob)
                    +",西域神器唤云扇,很有用喔! 过来看看吗!?\n");
			break;
		case 2:
                if( per < 15)
	say("小贩小声的说: "+ob->name(1)+",请具备一点公德心好吗? 人长的"
	            +"丑就不要上街吓人.\n");
		if( per > 26 && gender)
                    say("小贩赞叹道: 哇! 大美女"+ob->name(1)
		        +",妳可真是天仙下凡呀!!\n");

		say("小贩高声喊道: 跳楼大拍卖,"+RANK_D->query_respect(ob)
			+"要的话，我可以算便宜一点喔!\n");
			break;
	 }

}
