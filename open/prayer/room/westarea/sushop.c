//sushop.c
// made by chun,copy and re-edit by rence
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
  set ("short", "西域市集");
  set ("long", @LONG
  这里是西域地区唯一的商店,在这你可以估价(value),
卖断(sell),交易买货(buy),并可以察看这里有什么
货品待售(list).
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road9",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/keeper" : 1,
]));

  set("light_up", 1);

  setup();
}