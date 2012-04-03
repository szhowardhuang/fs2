// Room: /open/gsword/room/wghouse.c
inherit ROOM;

void create ()
{
    set ("short", "仙剑□藏剑室");
  set ("long", @LONG
这里是仙剑师兄弟们为了造福刚login没EQ的玩家所特别开辟的房间 ,
看着地上堆满的EQ ,你不禁诚心感谢众师兄弟的热心.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" :"/open/gsword/room/g5-1.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  set("no_clean_up",1);
set("no_fight",1);
  setup();
  call_other("/obj/board/swordsman_b2","????");
}

void init()
{
//  add_action("do_sword","gift");
  add_action("do_pass","pass");
  add_action("do_verify","verify");
}

int do_pass()
{
   object me=this_player();
   me->move("/open/ping/room/road3");
   return 1;
} 

int do_verify(string arg)
{
 object me,ob;
 me=this_player();
 ob=new("/data/autoload/swordsman/sun_sword_book");
 if( arg!="sun_sword_book")
{
    write("你要申请什么\n");
    return 1;
   }
if(me->query("quest/sun_fire_sword",1)!=1)
  {
    write("你拿了这东西也没用\n");
    return 1;
  }

 if( present(ob,me) )
  {
    write("你已经有一本了\n");
    return 1;
   }
   else
    {
     write("好好保管此书, 别再弄丢了.\n");
     ob->move(me);
     return 1;
    }
}
/*
int do_sword(string arg)
{
 object me,ob;
 me=this_player();
 ob=new("/data/autoload/swordsman/sunsword-gift");
 if( arg!="sword")
{
    write("你要申请什么\n");
    return 1;
   }
if(me->query("id",)!=("rocken"))
  {
    write("想拿礼物...门都没有\n");
    return 1;
  }

 if(me->query("get_appogift1")==1)
  {
    write("你已经拿到礼物了...还要什么?\n");
    return 1;
   }
   else
    {
    write("[1;37m瞬间~一道七色彩虹化过你眼前,瞬间你觉得手上多了一样东西[0m\n");
   me->set("get_appogift1",1);
     ob->move(me);
     return 1;
    }
}
*/
