#include </open/open.h>
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("杜杀", ({ "du sa", "du", "sa" }) );
        set("nickname", "血手");
        set("title", HIW"～幻影～"NOR"恶人谷大头目");
        set("gender", "男性");
        set("age", 41);
        set("class", "bandit");
        set("guild_master", 1);
    set("bellicosity", 2500);
        set("attitude", "badman");
        set("combat_exp", 5000000);
   set("long","这个人身子又瘦又长，一身雪白的长袍，他的脸就跟他的衣服一样苍白。
仔细一看，你才发现他的左手已经断了，并且装上了一个锋利的钢钩。他就是恶人谷中
最令人畏惧的十大恶人之首－「血手”杜杀。");

        set("str", 40);
        set("cor", 40);
        set("int", 24);
        set("spi", 22);
        set("cps", 30);
        set("con", 30);
        set("per", 16);
        set("max_gin", 1500);
        set("max_kee", 5000);
        set("max_sen", 1500);
    set("max_force",10000);
    set("force",10000);
        set("force_factor", 10);

   set_skill("array",80);
   set_skill("magic",20);
   set_skill("spells",20);
   set_skill("bad-array",100);
  set_skill("change",100);
    set_skill("dodge", 80);
   set_skill("sword",80);
  set_skill("ghost-steps",100);
    set_skill("force", 70);
  set_skill("badforce",100);

    set_skill("move", 80);
    set_skill("parry",70);
    set_skill("unarmed",80);
set_skill("cure",50);
  set_skill("badstrike",100);
        set_skill("gamble", 50);
    set_skill("literate",30);
        map_skill("unarmed", "badstrike");
    map_skill("array", "bad-array");
        map_skill("parry", "badstrike");
        map_skill("force", "badforce");
        map_skill("dodge", "ghost-steps");
        map_skill("move", "ghost-steps");
    set("quests/badroar",1);
set("functions/evil-blade/level",100);
set("functions/badroar/level",50);

    set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.evil-blade" :),
        (: perform_action, "unarmed.badroar" :),
        }) );

        setup();
        create_family("恶人谷",1,"大头目");
        set("family/next_title", "小喽喽");
        add_money("gold", 10);
        carry_object(BAD_OBJ"badhelmet")->wear();
    carry_object(BAD_OBJ"evil_claw.c")->wield();
}


int accept_fight(object who)
{
        message_vision("杜杀冷冷的瞄了$N一眼。\n", who);
        command("say 哼，不自量力的家伙。\n");
        return 1;
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
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系统：由于你没携带晶片，所以无法记录战绩。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系统：由于你没有正式登记，资料无法传输。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 16)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第十五层试炼□塔"HIG"’"HIY"通过！！

"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第十六层试炼□塔"HIG"’"HIW"。
	"NOR,me);
	me->set("quest/start_game",16);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
}
}


