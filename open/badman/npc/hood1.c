#include <ansi.h>

inherit NPC;

string do_steal();

void create()
{
      set_name("小泼皮",({"hood"}) );
      set("long","一个整天在街头上闲混闲逛的小混混。\n");

      set("gender","男性");
      set("age",25);
      set("attitude","badman");

      set_skill("dodge",10);
      set_skill("unarmed",15);
      set_temp("apply/attack",10);
      set_temp("apply/armor",10);
      set("combat_exp",300);

      set("chat_chance_combat",80);
      set("chat_msg_combat",({
         (:do_steal:)
      }));

      set("chat_chance",2);
      set("chat_msg",({
          "小泼皮一脸鸟样的在你面前走了几圈。\n",
          "小泼皮拍了拍你的肩膀，说道：喂！小兄弟、拿些钱来给老子花花啊。\n",
      }));

      setup();

      carry_object("/obj/cloth")->wear();
}
