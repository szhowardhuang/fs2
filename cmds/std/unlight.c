#ifdef WEATHER
// light
// 由 wade 撰写
// 要点亮的物件上必须有一变数: (int)light_up
// 该变数的值是可以点的秒数, 如果是负值, 表永远有效
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
  int		light;
  object	ob, *myob;
 
  seteuid(getuid(me));
 
  if(!arg) return notify_fail("unlight <物件>  <-- 如 unlight torch\n");
  arg = lower_case(arg);

  if (!ob = present (arg, me)) return
    notify_fail ("你身上没有这样东西。\n");

  if (!ob->query("had_light"))
    return notify_fail (sprintf ("这%s%s并没有被点亮。\n",
      ob->query("unit"), ob->name()));

  message_vision("$N熄灭了一"+ob->query("unit")+ob->name()+"。\n", me);

  ob->delete("short");
  ob->delete("had_light");
  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : unlight <物件>
范    例 : unlight torch
指令说明 : 
           这个指令可以让你(妳)熄灭某些特定物件。
HELP
    );
    return 1;
}
#endif
