// sleep.c
// 冬眠，避免玩家玩太久，自己设冬眠时间
// by wade@Fantasy.Space 87/8/11

inherit F_CLEAN_UP;


int main ( object me, string arg )
{
  int t=0, d=0, h=0, m=0, s=0;

  if (!arg || arg == "") {
    return 0;
  }

  sscanf (arg, "%d %d %d %d", s, m, h, d);
  if (d < 0 || h < 0 || m < 0 || s < 0) {
    write ("时间一定要大于○\n");
    return 1;
  }
  t = ((d * 24 + h) * 60 + m) * 60 + s;

  t += time();
  me->set("sleep",t);
  printf ("冬眠时间为：%d天%d小时%d分%d秒。\n设定冬眠到 %s\n",
        d, h, m, s, ctime (t));
  me->do_command ("quit");
  return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : sleep 秒 分 时 天
指令说明 :
           这个指令让使用者设定一段时间内不能上线。
           天/时/分/秒，不可以小于○，当然，可以省略不给
           当你想一段时间不上线，又怕意志力不够，
           用这命令就对了。

   ** : 此命令会强迫你 "quit" :)
HELP
    );
    return 1;
}
