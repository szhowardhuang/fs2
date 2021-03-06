#include <ansi.h>

inherit NPC;

void create()
{
      set_name("江湖艺人",({"ihinerant"}));
      set("long",@LONG
一个已有一些年纪的卖艺师父，你可以从他脸上看到岁月所留下的痕迹。
今天他这好在此地摆摊卖艺，希望能赚些生活费。
LONG
      );
      set("age",56);
      set("attitude","friendly");
      set("gender","男性");

      set_skill("unarmed",35);
      set_skill("dodge",35);
      set_skill("parry",35);
      set("combat_bat",10000);

      set("chat_chance",3);
      set("chat_msg",({
          "江湖艺人喊道：来来来！有人的捧个人场，有钱的捧个钱场！\n",
          "江湖艺人叫道：小弟初来贵宝地....\n",
          "江湖艺人一发劲，打碎了地上的三块砖。\n",
      }) );

      setup();

      add_money("coin",10);
      carry_object("/obj/cloth")->wear();
}
