// mark.c
//
// 将布告标示成不可显示
// mark		显示所有被标示的布告
// mark N	标示第 N 封
// mark N-	标示第 N 封以后的
// mark -N	标示从头至第 N 封
// mark N-M	标示从 N 至 M 封
// wade@Fantasy.Space 12/16/1999
// 对于 BBS 系统的用法说明请见 help BBS

#include <BBS.h>

int help();

int main(object me, string m)
{
  string	*token;		// 字串，我们想用 explode()
  string	board;		// 正在处理的版面
  object	BBS;
  int		N, M;

  if (!m || m == "") {	// 不会用？帮他显示 help()
    return help ();
  }

  if (!objectp (BBS = find_object (BBS_OBJ))) {	// 找不到 BBS
    write ("BBS 系统没启动！请通知巫师。\n");
    return 1;
  }
  board = me->query ("post/board");
  token = explode (d, "-");	// 不知道会有什么值？？？
  if (sizeof (token) == 2) {	// N-M 格式
    sscanf (token[0], "%d", N);
    sscanf (token[1], "%d", M);
    write (BBS->mark (board, N, M));
  }
  else if (d[0..0] == "-") {	// -M 格式
    sscanf (token[0], "%d", M);
    write (BBS->mark (board, 0, M));
  }
  else if (d[-1..-1] == "-") {	// N- 格式
    sscanf (token[0], "%d", N);
    write (BBS->mark (board, N, BBS->nol (board)));
  }
  else {			// N 格式
    sscanf (d, "%d", N);
    write (BBS->mark (board, N));
  }

  return 1;
}

int help()
{
  write(@HELP
指令格式 : mark [[N][-][M]]
意义 :
	此为 BBS 系统，命令有：
	使用者：list, select, post, read, renew
	巫　师：discard, mark, extract
指令说明：
	标示布告。
	mark		显示所有被 mark 住的布告
	mark N		第 N 封
	mark N-		标示第 N 封以后的
	mark -M		标示从头至第 M 封
	mark N-M	标示第 N 至 M 封
HELP
    );
    return 1;
}
