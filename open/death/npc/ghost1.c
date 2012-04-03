inherit NPC;

int *a=({0, 0, 0, 0, 0, 0});
int *b=({0, 0, 0, 0, 0, 0});
int in_toss;

void create()
{
        set_name("孤魂野鬼", ({ "ghost" }) );
        set("gender", "男性" );
        set("age", 50);
        set("int", 30);
        set("long","一个落单的野鬼，路过的鬼卒都跟他打招呼，好像人面很熟，搞不好可以从他口中探到不少消息，但是他眼中充满贪婪的眼神，仿佛前世十分好赌。\n" );
        set("combat_exp",50000);
        set("max_kee",500);
        set("max_gin",500);                        
        set("attitude", "peaceful");
        set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("force",50);
        setup();
}

void init()
{
        add_action("reply", "ask");
        add_action("do_beg", "beg");
        add_action("do_kneeze", "kneeze");
        add_action("do_play","play");
        add_action("do_toss","toss");
}

int reply(string str)
{
int i;

    i = this_player()->query_temp("ask");
    if(i == 0)
        write("我在这一带还算蛮熟的，应该算是奈何桥的地头蛇吧！\n");
    else if (i == 1)
        write("我认识很多出名的人喔！如果不想受酷刑的话就来求(beg)我吧！\n");
    else if (i >= 2) {
        write("我就是因为好赌，而欠债累累，最后被放高利贷砍死的。不过近来技术进步了，不少鬼差兄弟还欠我钱咧！\n");
        return 1;
    }
    if (this_player()->query_tmp("death/quest"))
        write("听说奈何桥下有一条小径通到河边，而且有不少好东西在那里。\n");

    this_player()->set_temp("ask", ++i);
    return 1;
}

int do_beg(string str)
{
        if (str != "ghost")
                return notify_fail("你要求谁啊！？\n");
        else if(this_player()->query_temp("death/dice"))
                return notify_fail("你已经跟我玩过一次了！不要贪心再来烦我！！\n");
        else {
            if(this_player()->query_temp("ask") < 3)
                return notify_fail("你要求我吗？先跪(kneeze)下来再求一次吧！\n");
            else {
                write("好吧！看你这么有诚意，就跟你玩(play)一盘吧！玩赢我再帮你说情。\n");
                this_player()->set_temp("ask", 4);
                return 1;
            }
        }
}

int do_kneeze(string str)
{
        if(str != "ghost")
                return notify_fail("你要向谁跪下啊！？\n");
        else
        {
            if(this_player()->query_temp("ask")>=3)
                return notify_fail("你已经跪下来了！\n");
            else {
                message_vision("$N一脸委屈地朝孤魂野鬼跪了下去。\n", this_player());
                this_player()->set_temp("ask", 3);
                return 1;
            }
        }
}


int do_play(string str)
{
        if(this_player()->query_temp("ask")<4)
                return notify_fail("本大爷不屑跟你玩！先求我吧！\n");
        else
        {
        if(this_player()->query_temp("death/force"))
                write("孤魂野鬼说道：来吧，请掷(toss)骰子(dice)！\n              如果你掷的比我大，那你就不用扣内力了！\n              但是你只有一次的机会喔！\n");
        else if(this_player()->query_temp("death/mana"))
                write("孤魂野鬼说道：来吧，请掷(toss)骰子(dice)！\n              如果你掷的比我大，那你就不用扣法力了！\n              但是你只有一次的机会喔！\n");
        else if(this_player()->query_temp("death/atman"))
                write("孤魂野鬼说道：来吧，请掷(toss)骰子(dice)！\n              如果你掷的比我大，那你就不用扣灵力了！\n              但是你只有一次的机会喔！\n");
        else
        {
                write("孤魂野鬼说道：啊！对不起！我突然发现我不能帮上你的忙！请你去找别人吧！\n");
                this_player()->delete_temp("ask");
        }
        }
        this_player()->set_temp("ask", 5);
        return 1;
}

int do_toss(string str)
{
        int i;

        if( str!="dice") 
                return notify_fail("你要玩什么？\n");
/*      if(this_player()->query_temp("ask")!=5)
                return notify_fail("本大爷不屑跟你玩！先求我吧！\n");*/
        if(this_player()->query_temp("death/dice"))
                return notify_fail("你已经跟我玩过一次了！不要贪心再来烦我！！\n");
        if(this_player()->query_temp("death/force"))
                return notify_fail("我不能帮你任何忙！请你不要烦我了！\n");
        if( in_toss )
                return notify_fail("我正在跟别人玩，不要打搅我们！！\n");
        in_toss=1;
        this_player()->set_temp("ask", 6);
        for(i=0;i<3;i++)
        {
                a[i]=random(6)+1;
                a[i+3]=0;
                b[i]=random(6)+1;
                b[i+3]=0;
        }
        a[3]=a[0]+a[1]+a[2];
        b[3]=b[0]+b[1]+b[2];

        if(a[1]==a[2] && a[0]==a[1])
                a[5]=a[1];
        else if(a[1]==a[2] || a[0]==a[1])
                a[4]=a[1];
        else if(a[0]==a[1] || a[0]==a[2])
                a[4]=a[0];
        else if(a[1]==a[2] || a[0]==a[2])
                a[4]=a[2];
        else
                a[4]=0;
                
        if(b[1]==b[2] && b[0]==b[1])
                b[5]=b[1];
        else if(b[1]==b[2] || b[0]==b[1])
                b[4]=b[1];
        else if(b[0]==b[1] || b[0]==b[2])
                b[4]=b[0];
        else if(b[1]==b[2] || b[0]==b[2])
                b[4]=b[2];
        else
                b[4]=0;
        message_vision("$N大喊∶上天可怜可怜我吧！来个豹\子吧！\n$N亲了一下手中的骰子，慎重的往碗公里甩去．．\n", this_player());
        call_out("roll_dice", 2, 0, this_player()->query("id"));
        return 1;
}

void roll_dice(int i, string ppl)
{
        if(i<3)
        {
        say("骰子在碗公里滚了一会儿．．终于第"+chinese_number(i+1)+"个骰子停了下来，是"+chinese_number(a[i])+"点。\n");
        call_out("roll_dice", 2, i+1, ppl);
        } else {
        if(a[5] > 0)
        say("\n野鬼说道：看来要使出绝活才能赢你了！看我的！\n");
        else if(a[4] > 0)
        say("\n野鬼说道：好小子！看不出来你的技术不错嘛！！现在换我了！\n");
        else
        say("\n野鬼说道：哈！哈！哈！不过如此尔尔，看我怎么痛宰你！\n");
        say("\n野鬼一把抓起骰子，好像作法般乱舞起来，接着大喊一声：西八辣！！熟练地把手中的骰子如雨点般往碗公里甩去。\n\n");
        call_out("ghost_turn", 3, 0, ppl);
        }
}

int ghost_turn(int i, string ppl)
{
object ob;

        if(i<3)
        {
        say("骰子在碗公里翻腾了一阵子．．野鬼大喝一声：停！\n骰子好像会听话似的停了下来，第"+chinese_number(i+1)+"颗的点数是"+chinese_number(b[i])+"。\n");
        call_out("ghost_turn", 2, i+1, ppl);
        } else {
        in_toss=0;
        ob=find_player(ppl);
        ob->set_temp("death/dice", 1);
        ob->delete_temp("ask");
        if(a[5] == b[5] && a[4]==b[4] && a[3] == b[3]) {
                ob->delete_temp("death/dice");
                ob->set_temp("ask", 5);
                say("\n野鬼说道：这次平手，再来一次！\n");
                return 1;
        } else if(a[5] < b[5] ) {
                say("\n野鬼说道：哈哈哈！你不是我的对手啦！\n");
                return 1;
        } else if(a[4] < b[4]) {
                say("\n野鬼说道：怎样？我很强吧！下次再来吧！\n");
                return 1;
        } else if(a[3] < b[3]) {
                say("\n野鬼说道：不服气再来啊！我随时奉陪！\n");
        } else {
        say("\n野鬼说道：你果真有两把刷子，我再去练几把，再等你来赐教！！\n");
        ob->delete_temp("death/force");
        ob->delete_temp("death/mana");
        ob->delete_temp("death/atman");
        return 1;
        }
        }
}

