 inherit NPC;
void create()
{
  set_name("知客僧",({"monk"}));
        set("gender","男性");
        set("class","scholar");
        set("combat_exp",5000);
        set("attitude","peaceful");
        set("age",23);
        set("chat_chance", 30);
        set("chat_msg", ({
        "知客僧说道: 施主您好,请问有什么事。\n",
        "知客僧说道: 施主,您要找什么人或什么地方,问我就对了。\n",
        }));
        set("inquiry", ([
        "方丈" : "您往东或往西走,看到往北的路直直走就对了。",
        "段誉" : "这个嘛,段前辈现在住在玄机房隐居,不想有人打扰。",
        "本相" : "本相师父和其他几位老师父正在牟尼院中清修,别打扰他们老人家了。",
        "牟尼堂" : "那是本寺的高僧清修之处,在本寺的西院。\n",
        "玄机房" : "那是段誉前辈夫妇居住的地方,就在寺里的东院。\n",
        ]));
        set("force",500);
        set("max_force",500);
        set("max_kee",500);
        set("kee",500);
        set("force_factor", 1);
        set_skill("force",40);
        set_skill("unarmed",30);
        set_temp("apply/dodge",40);
        setup();
        add_money("silver",10);
       }
