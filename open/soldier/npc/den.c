#include <ansi.h>
#include </open/open.h>
inherit NPC;
void create()
{
 seteuid(getuid()); 
set("nickname",HIY"机枪手"NOR);
set_name("载卡多",({"den ka","den","ka"}));
set("long","
    他是辛卡多的双胞兄弟,两人所拥有的武功
几乎一模一样强,由于他们两掠夺到中国大将吕
布和张飞的丈八蛇矛和方天化戟,使两人犹如鱼
的水般的强。

    ");
set("gender","男性");
set("attitude","heroism");
set("age",32);
set("max_kee",4500);
set("class","soldier");
set("kee",4500);
set("int",30);
set("per",30);
set("str", 35);
set("con", 30);
set("force",3000);
set("max_force",3000);
set("combat_exp",1000000);
set_skill("force",60);
set_skill("spforce",50);
set_skill("dodge",60);
set_skill("parry",70);
set_skill("lance",90);
set_skill("power-lance",90);
set_skill("eagle-steps",70);
map_skill("dodge","fly-steps");
map_skill("lance","power-lance");
map_skill("force","spforce");
map_skill("parry","power-lance");
set("apply/armor",80);
setup();
carry_object("/open/soldier/obj/meter")->wield ();
add_money("gold",10);
}

int accept_kill(object who)
{
   say(HIY" 老子跟你拼了!!!\n"NOR);
   setup();
   return 1;
}
void init()
{
      if (this_player()->query_temp("blood")== 1)
      kill_ob(this_player());
}


