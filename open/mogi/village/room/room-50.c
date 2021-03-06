//这里是魔界村最重要的功能,让玩家可以休息save
//其中点餐的功能改自杀手的餐厅,希望wataru不要生气...........
//room:/u/e/eva/village/room/room-50.c        made by eva

#include <room.h>
#include <ansi.h>
#include <village.h>

inherit ROOM;

void create ()
{
  set ("short", "魔界村旅店");
  set ("long", @LONG

    这里是魔界村的旅店, 由于魔界村是魔界的避风港, 这里又是魔
界村唯一一家的旅店, 再加上美丽动人的老板, 也难怪这里时常挤满
着客人!
    这里供应餐点及外带, 你可以在墙上清楚的看到菜单(menu), 至
于外带请打(list)!

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "menu" : "
               A.挶鳖肉           价格:50文
               B.腌渍魔猪肉       价格:80文
               C.火烤黑龙排       价格: 1银
               D.孔雀全席         价格: 5银
如需要餐\点 , 请打order <餐\号>, 即可立即尝到鲜美的食物!

",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/mogi/village/npc/h_boss" : 1,
]));
  set("light_up", 1);
  set("no_magic", 1);
  set("no_transmit", 1);
//   set("valid_startroom",1);
  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/mogi/dragon/liuroom",
  "out" : __DIR__"room-46",
]));
  set("no_fight", 1);
  set("evil", 1);
  set("no_auc", 1);

  setup();
}

void init()
{
    add_action("do_order","order");
}

int do_order(string str)
{
    object me;
    int foods,waters,moneys;
    me=this_player();
    if( str!="a" && str!="A" && str!="b" && str!="B" && str!="c" && str!="C" && str!="d" && str!="D")
        {
        return notify_fail("你连自己要点什么都不清楚吗!?....\n");
        }
    switch(str)
        {
        case "a":
        case "A":
            {
            moneys=50;
            foods=50;
            waters=40;
            }
            break;
        case "b":
        case "B":
            {
            moneys=80;
            foods=85;
            waters=65;
            }
            break;
        case "c":
        case "C":
            {
            moneys=100;
            foods=120;
            waters=90;
            }
            break;
        case "d":
        case "D":
            {
            moneys=500;
            foods=400;
            waters=400;
            }
        }
    if(!me->can_afford(moneys))
        {
        return notify_fail("没钱就不要充大爷嘛!.....\n");
        }
    if((int)me->query("food") >= (int)me->max_food_capacity())
        {
        return notify_fail("你已经吃不下任何东西了!!.....\n");
        }
    me->pay_money(moneys);
if ((me->query("food")+foods)>me->max_food_capacity())
    {
    me->set("food",me->max_food_capacity());
    }
else
    {
    me->add("food",foods);
    }
if ((me->query("water")+waters)>me->max_water_capacity())
    {
    me->set("water",me->max_water_capacity());    
    }
else
    {
    me->add("water",waters);
    }
    tell_object(me,"你狼吞虎咽的吞下桌上的食物!...\n");
    return 1;
}

