// 大写的档 --> 小写的档名
// by wade@Fantasy.Space 8/22/87

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  int n, i;
  string dir, cmds;
  mixed *file;

  dir = resolve_path(me->query("cwd"), arg);
  if (file_size(dir) == -2 && dir[strlen(dir)-1] != '/') dir += "/";
  file = get_dir(dir, -1);
  if (!sizeof(file)) {
    if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
    else
      return notify_fail("没有这个目录。\n");
  }

  n = sizeof(file);
  for (i=0; i<n; i++) {
    int         j, len;
    string      fn="xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

    cmds = "mv " + file[i][0];
    fn = file[i][0];

    len = strlen (file[i][0]);
    for (j=0; j<len; j++) {
      if (file[i][0][j] <= 'Z' && file[i][0][j] >= 'A')
        fn[j] = file[i][0][j] + ('a' - 'A');
    }
    cmds += " " + fn;
    if (fn != file[i][0])
      this_player()->do_command (cmds);
  }

  return 1;
}

int help(object me)
{
        write(@HELP
指令格式: b2s

  话说 8/22/87, wataru 要面包帮他把 ftp 成「大写”的档（几十个）
全改成小写的，他要面包先传回去，改成小写档名再传回来，…
这好像在考验面包的耐性一样…
  自从那天后，就有这个命令了。
  本指令会转换所有目录下的档案名写，大写变小写

                wade@Fantasy.Space 8/22/87
HELP
        );
        return 1;
}
