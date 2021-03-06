// list.c
//
// 查看布告，预设从上次看过的开始列
// wade@Fantasy.Space 12/16/1999
// 对于 BBS 系统的用法说明请见 help()

#include <BBS.h>

int help();

int main(object me, string cat)
{
  object	BBS;
  string	title, 		// 暂时的主题
		auth, 		// 暂时的作者
		board,		// 要查看的版面
		msg;	// 用来印出讯息
  int           i, 	// 给 for 用的暂时值
		t, 	// 布告暂时的时间值
		last_t,	// 暂时的，玩家身上的时间点
		post_n,	// 暂时的，玩家身上的第几封
		nol,	// Number of Lists in board
		n; 	// 以现在的时间点，要往前(后)看的数目

  // 确定 BBS 物件
  if (!objectp (BBS = find_object (BBS_OBJ))) {
    BBS = new (BBS_OBJ);
  }
  if (!BBS) {
    write ("BBS 物件不存在！请通知巫师！\n");
    return 1;
  }
  if (cat == "cat") {	// 列出所有版面，当然可以和前面的合并判断
    printf ("目前的版面有：%O\n", BBS->query_cat());
    return 1;
  }
  // 尚未使用 select 设定看哪一个版面
  if (undefinedp (board = me->query("post/board"))) {
    printf ("请使用 select 命令设定看哪一个版面后，再使用本命令。\n");
    return 1;
  }
  if (!BBS->if_has_board (board)) {
    write ("你选的版面错误！请用 select 再选择一次。\n");
    return 1;
  }
  if (!cat) {	// 没给参数
    n = 0;
  }
  // 语法错误，本来也可以设成从现在的开始列
  else if (sscanf (cat, "%d", n) != 1) {
    return help();
  }

  // 没看过这个版面(也许是新版)
  if (undefinedp (last_t = me->query ("post/"+board))) {
    me->set("post/"+board, 0);
  }

  // 设定 看到 第几个布告，为了安全起见，每用一次 list 就做一次
  if (post_n = BBS->query_order (board, last_t) < 0) {	// 应该已经没布告了
    write ("没任何布告！\n");
    return 1;
  }
  me->set_temp (board, post_n);

  nol = BBS->nol (board);
  n = post_n + n;
  if (n < 0) n = 0;
  if (n > nol) n = nol;

  msg = BBS->query_lists (board, n);
  printf ("%s\n全部是 %d 封，上次看到第 %d 封。\n",
	msg, nol, post_n);

  return 1;
}

int help()
{
  write(@HELP
指令格式 : list [cat | [[+|-]数字N]
BBS 说明 :
	此为 BBS 系统，命令有：
	使用者：list, select, post, read, renew
	巫　师：discard, mark, extract
指令说明：
	查看布告。
	list		<-- 若未使用 select 选择看哪一个版面，则同 list cat
	list cat	<-- 列出所有版面
	list N		<-- 从起点往后跳至 N 个讨论后，列出其后二十个讨论
	list -N		<-- 从起点往前跳至 N 个讨论后，列出其后二十个讨论
HELP
    );
    return 1;
}
