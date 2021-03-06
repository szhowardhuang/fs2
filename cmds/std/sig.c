// sig.c
//
// 由 wade 新增, 可以配合 post/followup 等命令的使用
// by wade in 6/30/1996

inherit F_CLEAN_UP;
inherit F_DBASE;

void create()
{
        seteuid (getuid());
        set ("名字", "签名档指令");
        set ("id", "sig");
}

int main(object me, string arg)
{
  string 	id, fn, *buf;

  if (me != previous_object()) return 0;

  id = me->query("id");
  fn = sprintf ("%s/sig/%s/%s.sig", DATA_DIR, id[0..0], id);
  assure_file (fn);

  if (arg == "none")
  {
    rm (fn);
    write("清除签名档。\n");
  }
  else {
    me->edit( (: this_object(), ({ "do_plan", this_player()}) :) );
  }
  return 1;
}

void do_plan(object me, string text)
{
  string fn, id;
  object link_ob;

  id = me->query("id");
  fn = sprintf ("%s/sig/%s/%s.sig", DATA_DIR, id[0..0], id);

  if (write_file (fn, text, 1) == 1)
    write ("签名档设定完成。\n");
  else
    write ("签名档无法写入.\n");
}

int help(object me)
{
write(@HELP
指令格式 : sig || sig none
指令说明 :
	   这个指令可以编辑自己的签名档，sig none 可以清除设定。
	   注意: 没加参数的话会在你编完签名档之后盖掉旧的档案.

相关指令 : plan，post，followup
HELP
    );
    return 1;
}

