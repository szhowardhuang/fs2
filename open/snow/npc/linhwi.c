#include <ansi.h>

inherit NPC;

string identy()
{
	object ob;
	if( present("lin sword",this_player()) )
		return "你身上的那把剑就是凭证！\n";
	ob = new("/open/snow/obj/lin_sword");
	ob->move(this_player());
	tell_object(this_player(),"刘玲慧给你一把剑。\n");
	this_player()->set("quests/to-kill-0",1);
	return "这本剑是我平时随身携带的，拿给他看他会相信的。\n";
}
void create()
{
        set_name("刘玲慧", ({ "liu linhwi", "hall", "linhwi" }) );
        set("long",
             "她是掌门的女儿,由于误触门规,还是被掌门关在禁闭室里面。\n");
        set("attitude", "heroism");
        set("gender", "女性" );
        create_family("雪苍派",5,"弟子");
        set("age", 20);
        set("str", 20);
        set("cor", 20);
        set("cps", 20);
        set("per", 30);
        set("max_force", 300);
        set("force", 300);
        set("force_factor",5);

	set("combat_exp", 24637);

        set("chat_chance", 3);
        set("chat_msg", ({
                "刘玲慧说:唉～真是无聊...\n",
                "刘玲慧说:爹爹也真是太凶了,不小心犯错就把我关在这里!\n",
                "刘玲慧说:真羡慕你可以自由的活动...\n",
        }) );


	set("force",300);
	set("max_force",300);
        set_skill("unarmed", 35);
        set_skill("force", 40);
        set_skill("literate", 35);
        set_skill("snowforce", 35);
        set_skill("parry", 35);
        set_skill("dodge", 35);
         set_skill("snow-martial", 20);
        map_skill("force", "snowforce");
	set_skill("black-steps",30);
	map_skill("dodge","black-steps");
         map_skill("unarmed", "snow-martial");
        set("inquiry",([
           "刘全书":   "他就是我爹爹。\n",
           "天邪石":   "相传天邪石有一秘密,详细内容我也不清楚,爹爹识它为至尊的宝物,我就是因为天邪石才被爹爹罚关在此处。\n",
	"密室": "听爹爹说过，在后山的密室里好像关着一个人。\n",
	"如何进入密室" : "这个我也不太清楚，不过好像听说要写字在墙上的石版上。\n",
	"黑仙罗汉" : "这个人有听我爹爹提过，他好像跟我爹爹之间有些什么特别的关系似的。",
	"刘全书与黑仙罗汉" : "这个是我爹爹的密秘，我问过他好几次，他都不说。",
	"密秘" : "要我爹爹说出他的密秘很难啦，除非 .....\n",
	"除非" : "我干嘛平白无故帮你，除非你帮我把云哥哥带来见我。\n",
	"凭证" : (: identy :),
           ]));

        setup();

        carry_object("/obj/cloth")->wear();
}
int ok()
{
	if( this_player()->query("quests/to-kill-0") != 1 ) return 0;
	command("say 云哥哥 ....");
	command("smile");
	command("smile "+this_player()->query("id"));
	command("say 只要跟我爹爹提到「玉门关”一室，我爹爹就会毫无招架之地。");
	this_player()->set("quests/to-kill-1",1);
}
void init()
{
	object ob;
	object env = environment( this_object() );
	if( (ob = present("dugur",env)) && ob->name() == "独孤云" )
		call_out("ok",1);
}
