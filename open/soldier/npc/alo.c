#include <ansi.h>
#include </open/open.h>
inherit NPC;
void create()
{
 seteuid(getuid()); 
set("nickname",HIB"闪灵悍将"NOR);
set_name("阿诺啥米碗糕",({"a lo","a","lo"}));
set("long","
    他拥有一副健壮的体格，是所有军中最勇猛慓悍
的，他剃着一个小平头和穿着一件汗衫，加上一身迷
彩裤，在他背后插着一把利器，莫非是～～～～～～
");
set("gender","男性");
set("attitude","heroism");
set("age",32);
set("max_kee",3500);
set("class","soldier");
set("kee",3500);
set("int",30);
set("per",30);
set("str", 35);
set("con", 30);
set("force",2000);
set("max_force",2000);
set("combat_exp",800000);
set_skill("force",60);
set_skill("spforce",50);
set_skill("dodge",60);
set_skill("parry",70);
set_skill("lance",80);
set_skill("power-lance",80);
set_skill("eagle-steps",60);
map_skill("dodge","fly-steps");
map_skill("lance","power-lance");
map_skill("force","spforce");
map_skill("parry","power-lance");
set("apply/armor",60);
  set("inquiry",([
      "李察鸡饵" : "你找他干嘛!!!..别给我乱来!!!。\n",
      
      ]));
setup();
carry_object("/open/soldier/obj/calamity")->wield ();
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


