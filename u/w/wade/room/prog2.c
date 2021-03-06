inherit ROOM;

void create ()
{
  set ("short", "基本的程式写作道理 -- 续");
  set("long", @LONG_DESC

// 一些常常用到的变数(常数)的定义与宣告, 通常都用 #include 把它们括进来
// 最常见的有 #include <ansi.h>
// 值得注意的是, 后面不能有分号, 此外, 巫师也可以自己定义一些固定的常数
// 如: #define PI 3.1416
//
// 房间/生物/装备/武器 一定是从 void create() {.....} 这个函数开始看(执行)起
// 所以, 通常这函数都写在档案的最开头, 至少是很前面的地方
//
// 当由玩家控制的角色第一次碰到上面提的物件时, 一定先去执行 void init()...
// 而通常这个函数是定义一些该物件上特有的行为, 由 add_action() 设定
// 
// 请继续往东走...
LONG_DESC);

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
  this_player()->move("/u/w/wade/workroom");
  return 1;
}

int go(string str)
{
  if (str == "e" || str == "east")
    this_player()->move("/u/w/wade/workroom");
  return 1;
}
