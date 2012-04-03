inherit NPC;
string do_act();
string do_acc();
string do_aca();
string do_acb();
string ask_tesin();
void create()
{
        set_name("柳绘心",({"liu hey-shun","liu"}));
        set("gender","女性");
        set("age",30);
        set("class","fighter");
        set("str",30);
        set("long","柳家标局第二掌门,也是柳淳风的女儿。 .\n");
        set("chat_chance",10);
        set("inquiry",([
        "龙铁心" : (:ask_tesin:),
        "讨伐" : (:do_act:) ,
        "报仇" : (:do_aca:) ,
        "宝库" : (:do_acc:) ,
        "郑雨桥" : (:do_acb:) ,
        ]));
        add_action("do_act","act");
        add_action("do_acc","acc");
        add_action("do_aca","aca");
        add_action("do_acb","acb");
        set("combat_exp",1000000);
        setup();
        add_money("silver",1);
}
int accept_fight(object who)
{
 return notify_fail("柳绘心说:都不会怜香惜玉啊。\n");
}
void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting()) 

        {
        remove_call_out("greeting");
        call_out("greeting",2,obj);
        }
}
void greeting(object ob)
{
        command("cry ");
}
  string do_act()
{
        command("say 唉.我爹是位正义之士。几年前，听到有位残暴的人「郑雨桥” ");
        command("say 就义不容辞的带领着镳局弟子去替天行道。");
        command("say 他跟暴王战了三天三夜，还是无法战胜他，壮烈牺牲了。");
        command("say 结果还被暴王拿走了柳家「宝库”的钥匙。");
        command("say 我很想替父亲「报仇”，无奈自己没武功，也不能拿回钥匙。");
        command("say 我就是为了报仇，抱着必死的决心来到魔界，想找寻勇士。");
           
 }
string ask_tesin()
{
if (this_player()->query("quests/shasword")>=2 && this_player()->query("quests/shasword")<5)
{
this_player()->set("quests/shasword",5);
return ("十几二十年前,就是龙大侠帮我们柳家重振雄风的..如果现在龙大侠还在的话..那不知该有多好.");
}
}
string do_acc()
{
command("say 那宝库就在炎龙谷的里面。");
        command("say 若能替我杀掉暴王，就自己拿着钥匙取宝物去吧。");
}

string do_aca()
{
    command("say 只能怨自己没武功啦。");
    command("say 不过...只要有人替我报仇..那宝库里的宝物就当做谢礼吧。");
}

string do_acb()
{
   command("say 哼!杀父仇人，不共戴天。");
   command("say 他生性残暴，爱杀生，已经有很多壮士为了讨伐他而一去不回。");
   command("say 他现在是炎龙谷的谷主。");
}
