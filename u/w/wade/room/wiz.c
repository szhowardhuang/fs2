inherit ROOM;

void create ()
{
  set ("short", "当巫师的第一步");
  set("long", @LONG
	1. 说在前头, 当巫师最好先想想自己的理念是否与本 MUD 相符合,
	   当巫师最重要的是: 一颗创造发明与牺牲奉献的心, 请 help mud_idea

	2. 当巫师当然一定要会巫师的基本命令, 请用 help wizcmds 查
	   以档案操作最为优先, 用 help file_oper 也可以查. 当然, 一定
	   要有目录的观念, 可以去查任何跟 MS-DOS X.X 有关的书.

	3. 读文件, 基本上, 去 /doc 下读档是非常重要的, 这个要会 cd /doc
	   跟 ls 跟 more <档名> 档命令,  此外, 读别人现有的档是很重
	   要的, 可以用 goto <房间>  再加上 more here  来读到, 如果是
	   物件, 可以直接 more <物件>, 如 more girl. 当然, 用 help 也
	   是非常重要的, 请用 help help 取得说明. 问人是最后一招.

	4. 编辑档案, 先从编自己的窝开始学习, 当然, 要您是 apprentice
	   以上才有资格有窝, 用线上编辑器编辑的话请 help edit_file
	   如果是要用自己机器上的编辑器编辑, 那就要会传档, 请用
	   help ftp 查询, 传档不能直接从 PC 上传, 详情请问其他巫师.
LONG);

  set("exits", ([
	"back"	: "/u/w/wade/workroom",
	"prog"	: __DIR__"wiz_prog",
	"rule"	: __DIR__"wiz_rules",
	"level"	: __DIR__"wiz_level",
	"QC"	: __DIR__"QC",
  ]) );

  set("light_up",1);
  setup();
}
