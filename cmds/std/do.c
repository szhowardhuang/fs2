#include <ansi.h>
 
// 取得第一个逗号的位置
int parse (string arg)
{
  int  i, k;
  int n;

  i = 0; k = 0; n = strlen (arg);
  arg += ",";   // 这样才可以让 ,, 的判断正常

  for (i=0; i<n; i++) {
    if (arg[i] == '"')
        if (arg[i+1] == '"') {
          i++;
          continue;
        }
        else k = !k;
    else if (arg[i] != ',') continue;
    else if (k) continue;
    else if (arg[i+1] == ',')
        i++;
    else break;
  }

  return i-1;
}

// 跳过空白部份, 使得 "l,hp", "l, hp" 跟 "l,     hp" 都可以用
int skip_space(string arg)
{
  int           i, n;

  i = 0; 
  n = strlen (arg);

  while ( i<n && arg[i] == ' ') i++;
  return i;
}

// 放弃特殊字元, 如两个双括号, 以及两个逗号其实只是一个逗号而已
string discard (string arg)
{
  string msg;
  int   i, n;

  if (!arg || arg == "") return arg;
  n = strlen(arg);
  arg += ",";   // 这理由跟 parse() 里的一样
  msg = "";
  for (i=0; i<n; i++)
    if ((arg[i] == ',' && arg[i+1] == ',') ||
        (arg[i] == '"' && arg[i+1] == '"'))
    {
        i++;
        msg += arg[i..i];
    }
    else if (arg[i] == '"') continue;
    else msg += arg[i..i];
  return msg;
}

int main(object me, string cmds, int depth, int in_do)
{
  string        cmd, other;
  int           i, j, n;

  // if(!wizardp(me) && !me->query("use_do")) return 0;
  if (!cmds || cmds == "") return 0;
  if(me->is_busy()) return 0;
 // 最多十二层 by bss
 if (depth >= 19) return 0;

  // 取出第一个逗号位置
  if (cmds == "") return 1;
  i = parse(cmds);
  if (i == -1) return 0;
  j = skip_space(cmds);
  if (i<j) return 0;
  // 顺便保留其他部份
  cmd = cmds[j..i];
  if ((i+2) < (n=strlen(cmds))) other = cmds[i+2..n-1];
  cmd = discard(cmd);
 
  // 此时 cmd 已经是 do 里的内容, 我们不允许 do 里还有 do
  if( cmd[0..1] == "do") return 0;

  // 硬性规定在 do 里头的一定是 brief mode
  if (!in_do) {
		n = me->query_temp("brief_mode");
		me->set_temp("brief_mode",1);
	}

  // 每个命令本身可能是 alias, 所以先送去 alias.c 里的 process_input 处理过
  // 然后再送进 /feature/commamd.c 处理
	me->do_command( me->process_input(cmd) );

  if ( other && other != "" )
    // 最后的参数 1 代表在 do 命令里, 这是为了 brief mode 用的
    // call_other(this_object(),"main", me, other, depth+1, 1);
	if( me ) // 玩家有可能下太多指令被踢出去, 要检查	arthur
    main (me, other, depth+1, 1);
	else return 1;

  // 把 brief mode 还原
  if(me)
  me->set_temp("brief_mode",n);
  return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : do
指令说明 :
           这个指令可以让你以更方便的方式下命令，
     1.  do: 你可以用 do 来一次下多个命命，如:
           do e,e,e,s,e,n,e
     2.  你可以下 10 e 代替连按十次 e
           4 e 跟 do e,e,e,e 是一样的意思
     3.  以上两种会在说话或者 channel 中有逗号时发生问题
           do 'hello, wade, smile
         解决之道是用双引号，或者双逗号
           do '"hello, wade",smile
           do 'hello,, wade, smile
     4.  如果要用到双括号，解法就是用两个连续双括号，
         譬如你要说 "你" 则可以用:
           do '""你"" 是大笨蛋,giggle
     5.  执行上一命令: 请直接用 !
         如果惊叹号后面有东西, 会加进去, 例如你原来是:
           smile           <-- 后来发现应该加个对象 wade
           ! wade          <-- 等于 smile wade
         注意喔，是一个惊叹号喔
     6.  修改, 例如你原先想打 smile 却不小心打成 smille
           ^ll^l           <-- 把所有 ll 改成 l
其他参考 :
           tune，alias，semote
HELP
    );
    return 1;
}
