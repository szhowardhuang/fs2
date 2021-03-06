// Room: /u/r/ranko/garden7.c
inherit ROOM;

void create ()
{
  set ("short", "山壁");
  set ("long", @LONG
走到此处,你赫然发现一如小山般的峭壁耸立西方.往上看去,壁
上寸草不生,光秃秃的一片像似被甚么削过似的光滑.看其高度,没有
绝世轻功恐难攀登.山上不时隐现阵阵霞光,似有稀世珍宝藏于其中,
山脚下仍是种着各式各样的毒花,毒草.但其中有一处草丛(bushes)似
乎特别茂密,不禁引起你的好奇心想一探究竟。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "bushes" : "你往草丛望去,发现这里似乎隐藏了甚么东西。你不妨四处搜寻一番,看看有何发现。
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"garden2-2.c",
  "east" : __DIR__"garden4-1.c",
]));
  set("light_up", 1);
  set("be_get",0);

  setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search(string str)
{
	object me=this_player();
	if(!str || str!="bushes")
	{return 0;}
	if(me->query_temp("get_fruit") && query("be_get"))
	{ message_vision("$N找了半天,但一无所获。\n",me);
	  return 1;
	}
	message_vision("$N伸手拨开草丛，在一阵搜寻中幸运的发现一颗果子。\n",me);
	new("/open/poison/obj/fruit.c")->move(me);
	me->set_temp("get_fruit",1);
	set("be_get",1);
	return 1;
}
void reset()
{
set("be_get",0);
:: reset();
}
