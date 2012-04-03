inherit NPC;  //村民 by dhk 2000.6.12
#include <ansi.h>
#include </open/open.h>

void create()
{
    set_name("嵩山村民",({"tendo man","tendo","man"}) );
    set("gender", "男性");
    set("age",40);
    set("attitude", "peaceful");
    set("long", "他是居住嵩山，以捡材维生的村民，别看他一付老实样其实是\n"
               +"一位深藏不漏的，练气士。\n");
    set("kee",600);
    set("max_kee",600);
    set("combat_exp",1000);
    set("class","fighter");
    set_skill("move",20);
    set_skill("force",20);
    set_skill("dodge",20);
    set_skill("parry",20);
    set_skill("unarmed",20);
    setup();
}
int accept_kill(object who)
{
  return 1;
}
int accept_fight(object who)
{
  return 1;
}
void init()
{
  remove_call_out("greets");
  call_out("greets",1,this_player());
}
void greets(object me)
{
  tell_object(me,"嵩山村民自言自语的说：最近传说山上出现一位仙人\n");
  tell_object(me,"                        有人看到他在山崖边凌空随手乱指，而那对面的山壁就留下\n");
  tell_object(me,"                        几行斗大的字。随后就莫名其妙的消失了，真是太神奇了！\n");
  remove_call_out("greets");
}
