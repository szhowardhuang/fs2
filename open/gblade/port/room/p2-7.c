// copy from Room: /d/snow/hockshop.c
// made by chun,and copy by ccat

#include "/open/open.h"
#include <room.h>

inherit HOCKSHOP;

void create ()
{
	set("short","枫林当铺");
  set ("long", @LONG
这是枫林港唯一的一家当铺 , 由于枫林港居民大都生活富裕 ,
加上黑市发达 , 交易热络 , 平常并不常有人走进当铺 , 位于此精
华地带 , 地价高昂 , 这间当铺看来也撑不久啦 , 一张木牌(sign)
告诉你这里的服务 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p2-2.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "	在这里你可以典当(pawn)物品或者赎回(redeem)典当
	在这儿的物品，也可以鉴定(value)物品的价值。
",
]));
  set("light_up", 1);

  setup();
}
