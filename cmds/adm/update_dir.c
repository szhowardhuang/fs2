#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string dir)
{
        int i,len;
        object obj, tmp, *inv;
        string err,out;
        mixed *files;

        me=this_player();
        seteuid( geteuid(me) );
        out="";

        if(!dir) return notify_fail("update_dir 目录名称\n");   

        files=get_dir(dir,-1);
        i=sizeof(files);
        while(i--)
        {
          len=sizeof(files[i][0]);
          if(files[i][0][len-2..len-1]!=".c")
            continue ;
          err = catch( call_other(dir+files[i][0], "???") );
          if (err)
                out+=sprintf( "发生错误:\n%s\n", err );
        }
        out+=dir+"下所有档案update ok!!\n";
        me->start_more(out);
        return 1;
}

