#include <ansi.h>
#include </open/open.h>
inherit NPC;

int change;
void create()
{
set_name("红叶组一级杀手",({"red killer","red","killer"}));
set("long","他是红叶组的杀手，但似乎与大家格格不入\n");
set("gender","男性");
set("attitude","friendly");
set("age",35);
set("int",30);
set("per",30);
set("str", 40);
set("con", 30);
set("force",400);
set("max_force",400);
set("combat_exp", 180000);
set_skill("force",30);
set_skill("dodge",100);
set_skill("parry",75);
setup();
add_money("gold",2);
}

int accept_kill(object who)
{
   if(who->query_temp("mission1")==1)
   {
     say(HIY"可恶，居然被你发现了，看我终极技--泣血悲天\n"NOR);
     set("combat_exp", 650000);
     change=1;
     setup();
     return 1;
   }
   setup();
   return 1;
}

void die()
{
   object head;
 
   if (change ==1)
   {
     message_vision(HIY"可恶！居然会败在你的手下,无法完成任务了\n"NOR,this_object());
     message_vision("说完之后他就倒下了。。。。\n",this_object());
     head=new("/open/killer/obj/npc_head.c");
     head->move(this_object());
   }
   ::die();
}