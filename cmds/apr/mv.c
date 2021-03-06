// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("指令格式: mv <原档名> <目标档名> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
 
        if(file_size(src)==-1) return notify_fail("没有"+src+"这个档!!\n");
        if( !rename(src, dst) ) {
          log_file ("file_operation", sprintf("%s更改档名 %s --> %s 于%s\n",
            me->short(), src, dst, CHINESE_D->chinese_time(time()))
          );
          write("Ok.\n");
	}
        else
                write("你没有足够的读写权利。\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : mv <原档名> <目标档名>
 
此指令可让你(妳)修改某个档案或目录名称。
HELP
    );
    return 1;
}
 
