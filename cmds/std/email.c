#include <ansi.h>
#define INTERMAIL "/data/mailo"

inherit F_CLEAN_UP;
 
int help (object);

void done_mail (object me, string who, string str)
{
  string	*msg;
  int		i;

  write_file (INTERMAIL, "#mailto: "+who+"\n");
  write_file (INTERMAIL, sprintf (@BASIC_MSG
--> 嗨! %s, 这是一封来自网路上的多人游戏站来的信,
--> 该站位于 telnet 140.122.77.123 4000, 欢迎您前往参观, 此信是由该
--> 站上的 %s(%s) 寄来的, 如果您要回信, 请在信的第一行写:
--> #mailto: %s
BASIC_MSG
, who, me->name(), me->query ("id"),  me->query ("id")));

  msg = explode (str, "\n");
  for (i=0; i<sizeof (msg); i++)
    if (msg[i][0..7] == "#mailto:")
      msg[i] = ">"+msg[i];
  str = implode (msg, "\n");
  write_file (INTERMAIL, str);
  tell_object (me, "好了, 理论上信寄出去了.\n");
}

int main(object me, string arg)
{
  seteuid(getuid(me));
 
  if (!arg) return help (me);

  write ("请输入你要寄的内容.\n");
  me->edit ( (: done_mail, me, arg :) );
  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : email e-mail-address
指令说明 :

  mud --> internet
  ================
  email jjchen@ice.ntnu.edu.tw  <-- 就开始进入编辑模式，跟 post 一样.

  internet --> mud
  ================
  当然是在 internet 上，如工作站帐号下，或 linux 下。
  必须在第一行写上 #mailto: WHO  <-- WHO 是在 mud 中的 id。如:
#mailto: wade                    <-- 必须从第一格开始些喔。
  假设现在是在工作站帐号下，而且你会用 mail 指令寄信，
  要寄到 mud 通通是寄给 jjchen@ice.ntnu.edu.tw，那就是狂想的菠萝面包。即:
  mail jjchen@ice.ntnu.edu.tw    <-- 按句点即可以结束。

其他参考 :
           post, mail(请到邮局使用)
HELP
    );
    return 1;
}
