inherit ROOM;
void create()
{
  set ("short", "奖品兑换处");
  set ("long", @LONG

这里就是专门兑换奖品的地方，只要你得到的忍邪
弟子头颅到达一定的程度，那你可以试着兑换你想
要的奖品喔！

 ‘东边的墙上，还贴着一张羊皮纸(paper)。’

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/m-eq-man": 1,
]));

  set("exits", ([ /* sizeof() == 1 */
"west":__DIR__"r4",
]));
  set("no_fight",1);
  set("no_magic",1);
  set("no_kill",1);
  set("no_smash",1);
  set("no_dest",1);
  set("item_desc", ([ /* sizeof() == 1 */
  "paper" : @LONG
若想知道身上有多少颗雪苍弟子头颅，你可以用"ask man about head"。
若想兑换奖品可以用"want xxxxx"。
若想知道能兑换那些奖品请打"list"。
LONG,
]));
  setup();
}
