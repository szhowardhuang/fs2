#include <ansi.h>
#include </open/open.h>
inherit NPC;
void create()
{
set("title","黑牙联前代兵器使");
set_name("完颜宏烈",({"hou-la","hou","la"}));
set("long","他是陷害柴荣叛变得背德小人，令人不耻，但你还是得小心一点。\n");
set("gender","男性");
        set("attitude","aggressive");
set("age",60);
set("int",30);
set("per",30);
set("str", 15);
set("con", 30);
set("force",400);
set("max_force",400);
set("combat_exp", 250000);
set_skill("force",50);
set_skill("dodge",50);
set_skill("parry",50);
setup();
add_money("gold",5);
}

int accept_kill(object who)
{
   say("小家伙，你也想对付我？太自大了！！\n"
        +"我至少也是黑牙联的兵器使呀！！!\n");
   setup();
   return 1;
}
void die()
{
   object head;
 
   say(HIG"可恶！天魔解体大法给你吧！\n"NOR);
   tell_object(this_player(),"他一溜烟的消失了，只留下那一本天魔解体大法....\n");
   head=new("/open/killer/obj/evilgod.c");
   head->move(this_player());
   destruct(this_object());
}