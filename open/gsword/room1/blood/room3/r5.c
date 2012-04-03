#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short",HIC"开天三才阵阵眼"NOR);
set ("long", @LONG
这里是传说中封印血魔之开天三才阵阵心，定眼一看，在你眼前你看到开天三灵器之光影，光影形成一三角状，在三角封印中央，似乎包着一个人，他看起来血肉糢糊似乎无比虚弱。
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc1/cking" : 1,
]));
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 2 */
"back":"/open/common/room/inn.c",
]));
  set("no_transmit", 1);
  setup();
}

void init()
{
add_action("do_search","search");
add_action("do_check","put");
}
int do_search(string str)
{
  object ob;
  ob=this_player();
message_vision("
你定睛一看，此人似乎是在仙剑凌霄宝殿壁画上的血魔，在向左右晃了晃你发现三灵器剑灵中各有一个圆形孔洞，似乎可以放上什么东西。\n",ob);
  return 1;
}

int do_check(string str)
{
 mapping weapon = ([
 "swordball in sun_fire_sword" : 1,
 "bladeball in bird_blade" : 2,
 "penball in liyu_pen" : 3,
 ]);
 object ob=this_player();
 object ob1;
 string name,str1,str2;
 if( !str || sscanf(str, "%s %s", str1, name) != 2 )
  {
   message_vision("请 put xxx in xxx\n",ob);
  }
 else if(weapon[str] && ob->query("class")=="swordsman")
  {
   message_vision(HIW"你将灵珠置入三灵器中.顿时整个房间喀然作响\n"NOR,ob);
   if(weapon[str]==1) ob->set_temp("su1",1);
   if(weapon[str]==2) ob->set_temp("su2",1);
   if(weapon[str]==3) ob->set_temp("su3",1);
  }
 else
  {
   message_vision(HIW"你触动机关-三灵器发出一到耀眼的光芒!!!\n"NOR,ob);
   ob->unconcious();
   return 0;
  }
 if(ob->query_temp("su1")==1&&ob->query_temp("su2")==1&&ob->query_temp("su3")==1)
  {
   log_file("sword/blood",sprintf("%s(%s) free bloodking on %s\n",ob->query("name"),ob->query("id"),ctime(time()) ));
   tell_object(users(),HIC"血魔狂笑道 : 哈哈~~总算有人破解仙剑老贼的阵法啦！！\n\n"NOR,ob);
   ob1 = present("bloodking",this_object());
   destruct(ob1);
   call_out("msg1",3,ob);
   return 1;
  }
}


int msg1(object ob)
{
   tell_object(users(),HIY"血魔怒道 :"HIR" 魔威荡荡圣佛惧，血雾蒙蒙神魔震！\n\n"NOR,ob);
   tell_object(users(),HIR"           众血魔将，听我号令，血染武林！\n\n"NOR,ob);
   new("/open/gsword/npc2/bknight")->move("/open/capital/room/r70");
   new("/open/gsword/npc2/bknight")->move("/open/capital/room/r70");
   new("/open/gsword/npc2/bknight")->move("/open/gsword/room/su3");
   new("/open/gsword/npc2/bknight")->move("/open/gsword/room/su3");
   new("/open/gsword/npc2/bknight")->move("/open/ping/room/road4");
   new("/open/gsword/npc2/bknight")->move("/open/ping/room/road4");
   new("/open/gsword/npc2/bknight")->move("/open/start/room/s5");
   new("/open/gsword/npc2/bknight")->move("/open/start/room/s5");
   new("/open/gsword/npc2/bknight")->move("/open/port/room/r3-1");
   new("/open/gsword/npc2/bknight")->move("/open/port/room/r3-1");
   new("/open/gsword/npc2/bknight")->move("/open/wind-rain/room9");
   new("/open/gsword/npc2/bknight")->move("/open/wind-rain/room9");
   new("/open/gsword/npc2/bknight")->move("/open/prayer/room/westarea/road29");
   new("/open/gsword/npc2/bknight")->move("/open/prayer/room/westarea/road29");
   new("/open/gsword/npc2/bknight")->move("/open/main/room/r5");
   new("/open/gsword/npc2/bknight")->move("/open/main/room/r5");
   new("/open/gsword/npc2/bknight")->move("/open/snow/room/room3");
   new("/open/gsword/npc2/bknight")->move("/open/snow/room/room3");
   new("/open/gsword/npc2/bknight")->move("/open/capital/room/r15");
   new("/open/gsword/npc2/bknight")->move("/open/capital/room/r15");

   call_out("msg2",3,ob);

   return 1;
 }

int msg2(object ob)
{
  message_vision(HIY"你开封印后，我想也没办法回仙剑派了吧，你到魔域来找我，我教你一套威力大于连阳剑法的‘血魔霸剑式’。\n"NOR,ob);
  ob->set("title",HIW"∏"HIR"魔"HIC"亟"HIY"剑宗"HIW"∏"NOR);
  ob->set("family/family_name","血魔一派");
  message_vision(HIC"  ...我在天邪峰尽头那有个魔堡…你就到那来吧… \n",ob);
  ob->set("bloodsword",2);
  ob->set("return",1);
  return 1;

}

