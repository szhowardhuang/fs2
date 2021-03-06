// localcmds.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *cmds;
	int i;

    if(arg){
      if(present(arg,environment(me)))
        me=present(arg,environment(me));
      else if(find_player(arg))
        me=find_player(arg);
    }
	cmds = me->query_commands();
	write("你身上及四周的物品与所在的环境提供以下指令：\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		printf("%-15s %-15s %O\n", cmds[i][0], cmds[i][3], cmds[i][2]);
	}
	return 1;
}

int help()
{
	write(@TEXT
指令格式：localcmds

列出你身上及四周的物品与所在的环境提供的所有指令。
TEXT
	);
	return 1;
}

