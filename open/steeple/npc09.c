#include <ansi.h>
inherit NPC;
void do_special1();
void do_special2();
void do_special3();
void do_special4();
void do_special5();
void do_special6();
void do_special7();
void do_special8();

void create()
{
        set_name("诸冈渡", ({"npc09","wataru"}));
        set("age",16);
        set("title",HIC"【玉帝】"NOR);
        set("gender","男性");
        set("class","killer");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spi",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("max_kee",20000);
        set("combat_exp",8000000);
        set("max_force",30000);
        set("force",30000);
        set("force_factor",30);
        set_skill("dodge",200);
        set_skill("unarmed",200);
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
        (: do_special1 :),
        (: do_special2 :),
        (: do_special3 :),
        (: do_special4 :),
        (: do_special5 :),
        (: do_special6 :),
        (: do_special7 :),
        (: do_special8 :),
        }));
        set_temp("apply/armor",130);
        set_temp("apply/damage",110);
        setup();
carry_object("/data/autoload/killer/ski_dream");
}

void do_special1()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIG
        "诸冈渡闭上双眼，喃喃的唸着咒文，四周的天气似乎起了很大的变化\n"NOR,target);
        message_vision(
        "诸冈渡睁开双眼大喝道:\n\n"+HIR"                          ***"+HIG"七"+HIR"**"+HIG"键"+HIR"**"+HIG"守"+HIR"**"+HIG"护"+HIR"**"+HIG"神"+HIR"***"NOR+"\n",target);
        message_vision(HIC
        "天空中出现了七个异空间，朝你围了过来，你以无处可逃！！！\n"NOR,target);
        message_vision(HBGRN"$N全身上下似乎全部被空间分开了！，你的存在已不具任何意义！\n"NOR,target);
        target->receive_wound("kee",800+random(500));
        COMBAT_D->report_status(target);

  }

void do_special2()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR
        "诸冈渡拨拨额头的头发轻笑说：像你这种笨家伙，也敢跟我挑战！！\n"NOR,target);
        message_vision(
        "诸冈渡举起右手大喝一声 :\n\n"+HIR"                         ***"+HIW"怒"+HIR"**"+HIW"龙"+HIR"**"+HIW"爆"+HIR"**"+HIW"炎"+HIR"**"+HIW"狱"+HIR"*** "NOR+"\n",target);
        message_vision(HIR"你只看到身体被一阵红白交错之炎火所围绕!\n"NOR,target);
        message_vision(RED
           "$N全身上下陷入一片火海之中，肌肉都已呈焦黑 !\n"NOR,target);

        target->receive_wound("kee",800+random(500));
        COMBAT_D->report_status(target);

  }

void do_special3()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR"
        诸冈渡大叫着 : 小心哦，我不会控制剑法的强度耶。。。。\n"NOR,target);
        message_vision("
        诸冈渡往你眼前的空气一刺 !你好像看到甚么东西从剑中钻出来似的!\n\n"
        "你看不清楚眼前到底出现了甚么东西 !\n"
        ,target);
        message_vision(HIR"一股如喷泉般的血$N身上不停的喷出 !!\n\n"NOR
                       HIY"那个速度极快的东西仍然不停的以高速在噬咬$N的身体!!\n"NOR
                       "一条速度极快的"+HIW" 白龙"NOR+"在$N身边不断的飞舞着 !! 咬着缠着可怜的$N!
        \n"NOR,target);
        target->receive_wound("kee",800+random(500));
        target->start_busy(2);
                COMBAT_D->report_status(target);

  }

void do_special4()
  {
    object *enemy,target;
    int i;
        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR "
        诸冈渡拨拨额头的头发轻笑说：像你这种笨家伙，也敢跟我挑战！！\n" NOR ,target);
        message_vision( "
        诸冈渡举起右手大喝一声 :\n\n"+HIY"                         ***"+HIM"灵"+HIY"**"+HIM"界"+HIY"**"+HIM"皇"+HIY"**"+HIM"龙"+HIY"**"+HIM"破"+HIY"*** "NOR+"\n",target);
        message_vision(HIG"你看到一条巨大的金黄色火焰龙朝你冲了过来 !\n"NOR,target);
        message_vision(GRN"
$N你却丝毫动弹不得，是死亡的恐惧还是对诸冈渡的恐惧？因为你发现你已经没救了！\n"NOR,target);

        target->receive_wound("kee",800+random(500));

                COMBAT_D->report_status(target);

  }

void do_special5()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
         message_vision( HIG
        "我主之力，上天之力，为我之剑，灭我之敌！！\n" NOR ,target);
        message_vision(
        "回过身见诸冈渡手中聚合光球\n\n"+HIW"                   ***干    坤    六    绝    光    弹"+HIW"***"NOR+"\n",target);
        message_vision(HIC
        "你根本不知道发生了什么事情，只觉得身体遭光球无情的袭击，无处可逃！\n"NOR,target);
        message_vision(HBGRN"$N全身上下似乎被光球冲击的体无完肤。\n"NOR,target);
                target->receive_wound("kee",800+random(500));
                COMBAT_D->report_status(target);

  }

void do_special6()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR
        "诸冈渡闭上了双眼，淡淡的说着。\n" NOR ,target);
        message_vision(
        "传说中的禁咒！！\n"+HIR"                  ***死    黑    核    爆    裂    地    狱"+HIR"*** "NOR+"\n",target);
        message_vision(HIR"你只看到身体被一阵黑光交错之炎火所围绕!\n"NOR,target);
        message_vision(RED
           "$N全身上下陷入一片炎狱之中，肌肉早已蒸发殆尽!\n"NOR,target);

                target->receive_wound("kee",800+random(500));
                COMBAT_D->report_status(target);

  }

void do_special7()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR"
        诸冈渡的六对翅膀都竖立了起来！！一股强大的气充斥在诸冈渡四周。\n" NOR,target);
        message_vision("这是属于我的最终杀招!\n\n"NOR,target);
        message_vision(HBMAG"      ----超     原     子     崩     坏     屴     起------\n"NOR,target);
        message_vision(HIG
"粉碎，粉碎，一切都化成粉碎！！！你正努力使自己回复原形！！\n"NOR,target);
        target->receive_wound("kee",800+random(500));
        target->start_busy(3);
                COMBAT_D->report_status(target);

  }

void do_special8()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR "诸冈渡化成一道光芒，射往天际！！，天空起了很大的变化！！！\n" NOR ,target);
        message_vision( "\n\n"+HIY"                         ***"+HIC"天"+HIY"**"+HIR"空"+HIY"**"+HIB"之"+HIY"**"+HIG"剑"+HIY"*** "NOR+"\n",target);
        message_vision(HIG"你看到由天空降下一道巨大的金黄色的光柱!\n"NOR,target);
        message_vision(GRN"
           $N你却丝毫动弹不得，是死亡的恐惧还是对神的恐惧？\n"NOR,target);
        target->receive_wound("kee",800+random(500));

                COMBAT_D->report_status(target);

  }

int accept_kill(object who)
{
who=this_player();
kill_ob(who);
command("charge "+who->query("id"));
command("perform fireforce.gold-fire");
command("cmd usekee "+who->query("id"));

    return 1;
}
int accept_fight(object who)
{
who=this_player();
kill_ob(who);
command("charge "+who->query("id"));
command("perform fireforce.gold-fire");
command("cmd usekee "+who->query("id"));

    return 1;
}
void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){                 //ok by chan
 object who=this_player();
 object ob,wataru;
 ob=this_object();
 wataru=present( "wataru",environment(ob) );
 if(str=="askgod wataru" || str=="askgod wataru"){
write(HIY"诸冈渡骂说：「对我使用求神问卜，真是活得不耐烦了。”!!\n"NOR);
 command("perform fireforce.gold-fire");
 wataru->kill_ob(who);
 return 1;
                  }
}

void heart_beat()
{
        object env, mob = this_object();
        int i;

        set_heart_beat(1);

        if( query("kee") < 0)
            mob->die();

        if( query_temp("heal") < 50 )
        {
            if( query("force") < 10000)
            {
               mob->add("force",10000);
            }
            if( query("kee") < 10000 )
            {
                mob->receive_curing("kee",1000);
                mob->receive_curing("gin",300);
                mob->receive_curing("sen",300);
                mob->receive_heal("kee",1000);
                add_temp("heal", 1);
                tell_room(environment(), HIY+name()+"呼唤出小岚"+
                     "小岚慢慢的运用仙术帮你疗伤.\n"+NOR);
            }
        }
        ::heart_beat();
}


int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系统：战斗停止，$N回收中，。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void die ()
	{
	 object me=query_temp("last_damage_from");
	if(!present("fight_card",me))
	{
	tell_object(me,"\n\n系统：由于你没携带晶片，所以无法记录战绩。\n");
	destruct (this_object ());
	return ;
	}
	if(!me->query("quest/start_game"))
	{
	tell_object(me,"\n\n系统：由于你没有正式登记，资料无法传输。\n");
	destruct (this_object ());
	return ;
	}
	if(me->query("quest/start_game")< 10)
        {
        tell_object(users(),HIY"
	恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第九层试炼□塔"HIG"’"HIY"通过！！

	"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第十层试炼□塔"HIG"’"HIW"。
	"NOR);
	me->set("quest/start_game",10);
        destruct (this_object ());
	return ;
        }
	{
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
	:: die();
	}
}