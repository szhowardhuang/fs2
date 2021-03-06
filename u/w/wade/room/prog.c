inherit ROOM;

void create ()
{
  set ("short", "本房间教你基本的程式写作道理");
  set ("long", @LONG

// 首先讲注解, 双斜线(//)之后的东东一概对程式没作用,
//     只是给巫师好理解程式用的, 称为注解, 就像这一行一样
// 其次, 讲物件继承, 也许你在别的地方已经有定义好某个承式了
//     那样的话就可以直接用 inherit <该程式> 来继承
//     在这儿要强调的是, inherit 跟 #include 是不一样的
//     至于哪里不一样, 这就等你慢慢写程式写多了就知道了, 底下是例子
inherit ROOM;

// 接下来, 每个程式是由许多的"叙述"组成的, 每一个叙述可以是下列的一种:
//   1.  呼叫函数, 如: setup();	// 函数一定是有一对小括号
//   2.  设定变数, 如: who = this_player();
//   3.  一段程式, 如: for, if/then/else, 等, 大部份是由大括号括起来
//   4.  定义函数, 如: int say(string arg)
//                     {
//                         ............;
//                     }
// 请继续往东走...
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "back" : "/u/w/wade/workroom",
]));

  setup();
}

void init()
{
  add_action("e", "e");
  add_action("e", "east");
  add_action("go", "go");
}

int e()
{
  this_player()->move(__DIR__"prog1");
  return 1;
}

int go(string str)
{
  if (str == "e" || str == "east") {
    if (this_player()->move(__DIR__"prog1")) return 1;
  }
  return 0;
}
