// mem.c
// fund 修改，使 mem 可以计算某个路径内所有正在使用的物件所占的记忆体(9/20/1996)

inherit F_CLEAN_UP;
string *main_path = ({
	"/adm/daemons/",
	"/daemon/skill/",
	"/daemon/condition/",
        "ftp/upload/",
	"/cmds/std/",
	"/obj/",
	"/obj/board/",
	});

string memory_expression(int m);
int count_memory( string dir )
{
	mixed *file;
	object ob;
	string pathname;
	int i , memory;
	if( dir[strlen(dir)-1..strlen(dir)-1] != "/" ) dir += "/";
	file = get_dir( dir , -1 );
	for( i = 0 ; i < sizeof(file) ; i ++ ) {
		pathname = dir + file[i][0];
		pathname = resolve_path( this_player()->query("cwd") , pathname );
		if( (ob = find_object( pathname )) )
			memory += memory_info(ob);
	}
	printf("目录 %s 中的物件目前共使用 %s bytes 记忆体。\n",
		dir , memory_expression(memory) );
	return memory;
}
void count_area( string name )
{
	int total;
	printf("以下是区域 %s 目前的记体使用情形：\n",name);
	total = count_memory( "/open/"+name+"/room");
	total += count_memory( "/open/"+name+"/npc");
	total += count_memory( "/open/"+name+"/obj");
	printf("总共使用 %s。\n",memory_expression( total ));
}
void count_all_area()
{
	mixed *dirs;
	int i;
	dirs = get_dir( "/open/" , -1 );
	for( i = 0 ; i < sizeof(dirs) ; i ++ ) {
		if( dirs[i][1] == -2 ) count_area( dirs[i][0] );
	}
}
void main_count()
{
	int i;
	printf("%s 中几个主要的目录物件使用情形：\n",
		MUD_NAME );
	for( i = 0 ; i < sizeof(main_path) ; i ++ )
		count_memory( main_path[i] );
}

int main(object me, string arg)
{
	object obj;
	string dir;

	if (!arg) {
		printf( "%s目前共使用 %s bytes 记忆体。\n",
			MUD_NAME, memory_expression(memory_info()) );
		return 1;
	}

	if( arg=="-m" ) {
		malloc_status();
		write("\n");
		return 1;
	}
	if( arg == "-d" ) {
		main_count();
		return 1;
	}
	if(arg == "-a" ) {
		count_all_area();
		return 1;
	}

	if( sscanf(arg,"-d %s",dir) == 1 ) {
		count_memory( dir );
		return 1;
	}
	if( sscanf(arg,"-a %s",dir) == 1 ) {
		count_area( dir );
		return 1;
	}
	seteuid(geteuid(me));
	obj = find_player(arg);
	if (!obj) obj = find_object(arg);
	if (!obj) obj = present(arg, me);
	if (!obj) obj = present(arg, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
	if (!obj) return notify_fail("没有这样物件....。\n");

	printf( "%O 共使用 %s bytes 记忆体。\n", obj, memory_expression(memory_info(obj)));
	return 1;
}

string memory_expression(int m)
{
	float mem;

	mem = m;
	if( mem<1024 ) return m + "";
	if( mem<1024*1024 )
		return sprintf("%.2f K", (float)mem / 1024);
	return sprintf("%.3f M", (float)mem / (1024*1024));
}

int help(object me)
{
  write(@HELP
指令格式 : mem <物件之名称或档名>
          mem -d <完整路径名>
          mem -a <区域名>

这个指令告诉你某个物件占用的记忆体数量。
若没有指明物件, 则会显示目前游戏所占用的记忆体.
HELP
    );
    return 1;
}
