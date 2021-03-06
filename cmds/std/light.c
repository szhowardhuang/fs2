#ifdef WEATHER
// light
// 由 wade 撰写
// 要点亮的物件上必须有一变数: (int)light_up
// 该变数的值是可以点的秒数, 如果是负值, 表永远有效
 
#include <ansi.h>
 
int main(object me, string arg)
{
  object	*light;
  object	ob;
  string	unit;
 
  seteuid(getuid(me));
 
  if(!arg) return notify_fail("light <物件>  <-- 如 light torch\n");

  arg = lower_case(arg);
  if (!ob = present (arg, me))
    return notify_fail("你身上没有这样东西。\n");
    if ( ob->query("had_light") )
    return notify_fail("你已经点着了。\n");

  if (!ob->query("light_up"))
    return notify_fail ("你点什么啊.\n");

  unit = ob->query("unit");
  if (!unit) ob->set("unit", unit="件");
  message_vision("$N点亮一"+unit+ob->name()+"。\n", me);

  ob->set("short", sprintf ("点亮着的%s(%s)",ob->name(),ob->query("id")));
  ob->set("had_light",1);
  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : light <物件>
指令说明 :
           这个指令可以让你(妳)点亮火把。
范    例 : light torch
其他参考 :
           unlight
HELP
    );
    return 1;
}
#endif
