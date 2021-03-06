// discard.c
//
// 删除布告
// discard	删除命令不能乱用，就帮他显示 help() 吧！
// discard N	删除第 N 封
// discard N-  删除第 N 封以后的
// discard -N	删除从头至第 N 封
// discard N-M	删除从 N 至 M 封
// wade@Fantasy.Space 12/16/1999
// 对于 BBS 系统的用法说明请见 help BBS

#include <BBS.h>

int help();

int main(object me, string d)
{
  string	*token;		// 字串，我们想用 explode()
  string	board;		// 正在处理的版面
  object	BBS;
  int		N, M;

  if (!d || d == "") {	// 不会用？帮他显示 help()
    return help ();
  }

  if (!objectp (BBS = find_object (BBS_OBJ))) {	// 找不到 BBS
    write ("BBS 系统没启动！\n");
    return 1;
  }
  board = me->query ("post/board");
  token = explode (d, "-");	// 不知道会有什么值？？？
  if (sizeof (token) == 2) {	// N-M 格式
    sscanf (token[0], "%d", N);
    sscanf (token[1], "%d", M);
    write (BBS->discard (board, N, M));
  }
  else if (d[0..0] == "-") {	// -M 格式
    sscanf (token[0], "%d", M);
    write (BBS->discard (board, 0, M));
  }
  else if (d[-1..-1] == "-") {	// N- 格式
    sscanf (token[0], "%d", N);
    write (BBS->discard (board, N, BBS->nol (board)));
  }
  else {			// N 格式
    sscanf (d, "%d", N);
    write (BBS->discard (board, N));
  }

  return 1;
}

int help()
{
  write(@HELP
指令格式 : discard [[N][-][M]]
意义 :
	此为 BBS 系统，命令有：
	使用者：list, select, post, read, renew
	巫　师：discard, mark, extract
指令说明：
	删除布告。
	discard 	太笨了，帮您显示 本讯息。
	discard N	删除第 N 封
	discard N-	删除第 N 封以后的
	discard -M	删除从头至第 M 封
	discard N-M	删除第 N 至 M 封
HELP
    );
    return 1;
}
