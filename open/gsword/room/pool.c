#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short","池底");
set ("long", @LONG
你运气于单田，绝心要探个究竟，使出个千斤坠直往下沉，不一
会已潜至池底，突然水草中传来一阵婴儿啼声，拨开水草一看，这下
子可是把你给吓到了，原来这啼声竟是来自一条全身金黄色的鱼，你
默想这大概就是传说中的娃娃鱼了吧!!
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc1/wawafish" : 1,
]));
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 2 */
                "up": "/open/gsword/room/road1",
]));
  set("no_transmit", 1);
  setup();
}

void init()
{
add_action("do_search","search");
add_action("do_check","give");
}
int do_search(string str)
{
  object ob;
  ob=this_player();
message_vision("
你定睛一看，难道这就是传说中的娃娃鱼?? 鱼的头骨中有五个圆形孔洞，似乎可以放上什么东西。\n",ob);
  return 1;
}

int do_check(string str)
{
 mapping weapon = ([
 "wawafish goldball" : 1,
 "wawafish fireball" : 2,
 "wawafish waterball" : 3,
 "wawafish woodball" : 4,
 "wawafish soilball" : 5,
 ]);
 object ob=this_player();
 object ob1;
 string name,str1,str2;
 if( !str || sscanf(str, "%s %s", str1, name) != 2 )
  {
    message_vision("请 give xxx xxx\n",ob);
  }
 else if(weapon[str] && ob->query("class")=="swordsman")
  {
   message_vision(HIW"你将法珠贯入娃娃余头骨中.顿时娃娃于大了一分\n"NOR,ob);
   if(weapon[str]==1) ob->set_temp("su1",1);
   if(weapon[str]==2) ob->set_temp("su2",1);
   if(weapon[str]==3) ob->set_temp("su3",1);
   if(weapon[str]==4) ob->set_temp("su4",1);
   if(weapon[str]==5) ob->set_temp("su5",1);

  }
 else
  {
   message_vision(HIW"你触动机关-四周空气随之浮动,瞬间五行挂印浮出并发出一到耀眼的光芒!!!\n"NOR,ob);
   ob->unconcious();
   return 0;
  }
 if(ob->query_temp("su1")==1&&ob->query_temp("su2")==1&&ob->query_temp("su3")==1&&ob->query_temp("su4")==1&&ob->query_temp("su5")==1)
  {
   log_file("sword/yao",sprintf("%s(%s) free yao on %s\n",ob->query("name"),ob->query("id"),ctime(time()) ));
   tell_object(users(),HIC"逍遥子喜道 : 天怜仙剑..总算有人解开我长久以来的封印了...！！\n\n"NOR,ob);
   ob1 = present("wawafish",this_object());
   destruct(ob1);
   call_out("msg1",3,ob);
   return 1;
  }
}
int msg1(object ob)
{
   tell_object(users(),HIY"遥远魔域传来震天巨响！！！\n\n"NOR,ob);

   call_out("msg2",3,ob);
   return 1;
 }

int msg2(object ob)
{
   tell_object(users(),HIY"血魔狂笑道 : 仙剑老贼别得意，如今我封印将破！\n\n            看你还有本事在封我一次吗??\n\n            哈~  哈~~  哈~~~  \n"NOR,ob);
   tell_object(users(),HIY"逍遥子叹道 : 唉~~武道无宁日，从今起，凡我仙剑弟子全力对抗血魔一族 \n"NOR,ob);
   call_out("msg3",3,ob);
   return 1;
 }
int msg3(object ob)
{
  message_vision(HIY"看样子你我真是有缘，你到仙剑后山剑圣峰来找我吧..我有其他事交代你。\n"NOR,ob);
  ob->set("quests/sunsword",1);
  ob->set("return",1);
  return 1;

}
