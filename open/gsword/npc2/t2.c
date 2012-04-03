#include <ansi.h>
inherit NPC;
string ask_test();
string ask_test1();

void create()
{
        set_name(HIW"╣з╤Чйта╤уъ"NOR, ({ "testman"}) );
        set("gender", "дппт" );
        set("age", 158);
        set("int", 26);
set("long","╢╚к╣жпв╗це╤ма╤ои╫ёеицехк╣дйь╩╓уъ..дЦ©иртнйкШсп╧ьйта╤╣дйб║ё\n");
        set("inquiry",([
        "йта╤":(:ask_test:),
        "йта╤с║╪г":(:ask_test1:),

        ]));
        set("combat_exp",50000);
        set("max_kee",500);
        set("max_gin",500);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("force",50);
        setup();
   }

string ask_test()
{
if (this_player()->query("quests/yantestmark1")==1&&this_player()->query("quests/yantestmark2")==1 &&this_player()->query("quests/yantestmark3")==1&& this_player()->query("quests/yan")==3)
 {
  this_player()->set("quests/yan",4);
  tell_object(this_player(),HIW"дЦря╬╜м╗╧Щ╣з╤ЧйтяИак.кЫртнркмдЦ╣╫╣зхЩйта╤гЬх╔╟и.\n"NOR);  
  message("system",this_player()->name()+HIW"м╗╧Щои╫ё╣з╤Чйта╤║ё\n"NOR,users());
  this_player()->delete("quests/yantestmark1");
  this_player()->set("title","[1;36mои╫ё╣з╤Чйта╤╫ёою[0m");
  this_player()->delete("quests/yantestmark2");
  this_player()->delete("quests/yantestmark3");  
  this_player()->delete("quests/2ndtest");
  this_player()->move("/open/gsword/room2/shab1.c"); 
}
else if (this_player()->query("quests/yan")>3)
{
  tell_object(this_player(),HIW"дЦря╬╜м╗╧Щ╣з╤ЧйтяИак.кЫртнркмдЦ╣╫╣зхЩйта╤гЬх╔╟и.\n"NOR); 
  this_player()->move("/open/gsword/room2/shab1.c"); 
}
else
 {
  tell_object(this_player(),HIW"╣з╤ЧйтяИ╣дд©╣дтзсз╤ма╤дЦ╣дв╒рБа╕.\nрР╢кдЦси╠╠╥╫╩ь╣╫йЯи╫..╡╒сийЯи╫╦╫╫Эур╣╫хЩ╦Жйта╤с║╪г.ж╝╨С╡екЦ╧Щ╧ь\n"NOR);
  return (HIW"жасзхГ╨нх╔ур..уБдЦ╬мр╙╤Ю╥япдак...\n"NOR);
 }

}

string ask_test1()
{
  tell_object(this_player(),HIW"нрж╩ж╙╣юфДжпр╩╦Жйг╨цоЯтзу╧╡╝ЁпиМио,аМа╫╦Ж..дЦ╬мр╙впо╦╣дх╔урурак..\n"NOR); 
  return (HIW"╡╩╧Щнр©иртбВвеwiz ╦ЗдЦк╣.жВр╙╣дс║╪г╤╪тзquest хкнО╣диМио..дЦ©иртх╔╦ЗкШцгнйнййта╤с║╪г╣дйб\n"NOR);
 }

