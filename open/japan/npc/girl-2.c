//shun.c
#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N使快妖刀,一招‘春风彩蝶飞’已然使开,刀光闪烁不定,婉如彩蝶四处飞舞
$n一失神全身上下已被砍伤无数处.",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    180,
                "force"      :    200,
                "damage_type":   "割伤",
           ]),
([     "action"     :   "$N双手持妖刀,刀起刀落,正是四季花舞刀法中的‘夏夜星空明’,
$n眼睁睁的看着横刀砍来却似乎无法抵抗",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    200,
                "force"      :    200,
                "damage_type":   "砍伤",
           ]),
([    "action"     :   "$N眉头紧锁,杀意急升,‘秋意愁不断’之起手式看似完成妖刀在
$n的四周飘荡化为无数枫叶落地,$n一不定神,刀气已经逼到眼前",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    180,
                "damage_type":   "砍伤",
            ]),
([    "action"     :    "$N手中妖刀越使越快,刀风冷冽,‘冬雨寒若雪’刀招应声而出,
$n心中大惊,但为时已晚$n已陷入险境无法闪躲.",
                "dodge"      :  -35,
                "parry"      :  -35,
                "force"      :   200,
                "damage"     :   200,
                "damage_type":   "破体之伤",
            ]),                
   });

void create()
{
        set_name("田中惠子", ({"girl"}));
        set("age",15);
        set("long","她是女影门传人的师妹,与旁边的河内美加是銮生姊妹,两姊妹分别\
练了‘四季花舞刀法’的上半部与下半部,姊姊田中惠子练的是上半部刀法\n");
        set("title",HIM"女影门究极奥义流第四代弟子"NOR);
        set("gender","女姓");
        set("class","killer");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spi",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("max_gin",1000);
        set("max_kee",1000);
        set("max_sen",1000);
        set("gin",1000);
        set("kee",1000);
        set("sen",1000);
        set("combat_exp",500000);
        set("max_force",1000);
        set("force",1000);
        set("max_atman",1000);
        set("max_mana",1000);
        set("atman",1000);
        set("mana",1000);
        set("force_factor",10);
        set_skill("dodge",100);
        set_skill("nine-steps",100);
        set_skill("unarmed",70);
        map_skill("dodge","nine-steps");
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set_temp("apply/armor",100);
        set_temp("apply/damage",78);
        setup();
        carry_object("/open/japan/obj/super-cloth.c")->wear();
        set("default_actions", (: call_other, __FILE__,"query_action" :));
	reset_action();
}

mapping query_action()
{
        return action[random(sizeof(action))];
}
void do_special()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];

                message_vision(
HIW "\n惠子使出四季花舞刀法中最强的秘招,随着刀法的变换演化出‘四时转不息’的超强特攻\n",target);
                message_vision(
HIY "\n四季刀法不断变化,$N已被四周春夏秋冬之变化给吸引,不知不觉已身受中伤
\n"NOR,target);
                target->receive_wound("kee",random(50+150));
                COMBAT_D->report_status(target);

  }
