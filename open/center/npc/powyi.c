// powyi.c

#include "/open/open.h"
inherit NPC;

void create()
{
  set_name("宝姨", ({ "Powyi", "powyi" }));
  set("race", "人类");
  set("gender", "女性");
  set("age", 40);
  set("long", "雍容华贵, 风韵犹存, 当年必定是响当当的绝色人物\n");
  set("attitude", "friendly");
  set("cor", 23);
        set("combat_exp",640);
  set("chat_chance", 2);
  set("chat_msg",({
    (: this_object() :),
    (: this_object() :),
    (: this_object() :),
    (: this_object() :),

    "宝姨笑着说∶里面坐 ! 里面坐 !\n",
    "宝姨笑着说 : 第一次来 ?\n",
    "宝姨笑着说 : 没关系 ! 一回生, 二回熟嘛. \n"
    "宝姨笑着说 : 我们刚刚找到一个小姑娘, 长得好漂亮, 改天叫她出来见见世面.\n",
    }));

  set_temp("apply/attack", 20);
  set_temp("apply/damage", 10);
  set_temp("apply/armor", 10);
  setup();
  carry_object(CENTER_OBJ"cloth2")->wear();
}
