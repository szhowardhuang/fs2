inherit ROOM;
void create()
{
  set ("short","狼谷");
  set ("long", @LONG
走到这里 ,眼前便只是面山壁 ,而旁边便只是几块突出的岩石罢了
 .虽然凭你的武功仍能走在上面 ,但掉到下面的山谷中可不是好玩的 ,
还是顺着原路回去吧 .

LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"wolf03.c",
  ]));

  set("objects", ([ /* sizeof() == 1 */
]));
  setup();
}
