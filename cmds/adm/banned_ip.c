#include <ansi.h>
inherit F_CLEAN_UP;
#define ALLOW ({"add","del","check","help","quit"})
string change_local;
private void get_choice(string arg, object user);
private void get_value(string value, object user);
string WARNING=HIY"
        特别的注意!!
        如果你是第一次使用本系统或是对本系统并不熟悉
        请一定要进入(help)选项观看使用方法，以免因为
        殊失而导致系统的不正常!!本系统目前并没有对任
        何选项做任何的保护措施，所以请小心使用。
        \n"NOR;
string LOCAL="
        (add)   增加不允许进入的ip
        (del)   删除目前不允许进入的ip，也就是让该ip进入
        (check) 查看目前banned_ip有那一些
        (help)  观看本系统说明档
        (quit)  结束系统回到fs
        \n";
string DOHELP=HIG"
        本系统提供你增加，删除，查询目前有被禁用的ip，为了表达
        的方便，特别的使用了选单式的系统，让操作更简便，与以往
        不同的是，在设定上多了*这个万用字元的使用。
        请注意，在这里的设定与ok_ip的设定不同，请看下例:
        合法的宣告: 163.26.238.*
        不合法的宣告: 163.26.238*
        请将万用字元加在.的后面，若没有这样的话可能造成判断的错
        误。
        对本系统有任何的问题，请post在bss的board上，我一定会解
        决!!
        \n"NOR;
void create()
{
        seteuid(getuid());
}
int main(object me, string arg)
{
        write(HIC"        你己经进入了banned_ip修改系统!!\n"NOR);
        write(WARNING);
        write(HIC"        本系统提供了下面的功能!!\n"NOR);
        write(LOCAL);
        write("请输入欲往之选项:\n");
        input_to( (: get_choice :), this_player() );
        return 1;
}
private void get_choice(string arg, object user)
{
        int flag;

        if( member_array(arg, ALLOW) == -1 )
        {
        write("本系统并没有提供你想要的服务，请重新输入!!!\n");
        write(LOCAL);
        write("请输入欲往之选项:\n");
        input_to( (: get_choice :), this_player() );
        return ;
        }
        switch(arg)
        {
                case "check":
                        write("目前禁用的ip有:\n");
                        CBIP_D->ip_list();
                        flag=1;
                        break;
                case "quit":
                        write("多谢您使用本系统，下次再见!!!\n");
                        return ;
                        break;
                case "help":
                        write(DOHELP);
                        flag=1;
                        break;
                default:
                        change_local=arg;
                        flag=0;
                        break;
        }
        if(flag)
        {
        write(LOCAL);
        write("请输入欲往之选项:\n");
        input_to( (: get_choice :), this_player() );
        return ;
        }
        else
        {
        write("你目前要进入的项目是("+change_local+")!!\n");
        if(change_local=="add")
        {
                write("目前禁用的ip有:\n");
                CBIP_D->ip_list();
                write("请输入要增加的ip:\n");
                input_to( (: get_value :), this_player());
                return ;
        }
        else
        {
                write("目前禁用的ip有:\n");
                CBIP_D->ip_list();
                write("请输入要删除的ip:\n");
                input_to( (: get_value :), this_player());
                return ;
        }
        }
        return ;
}
private void get_value(string arg, object user)
{

        if(!arg)
        {
        write("你并没有作("+change_local+")这项动作!!!\n");
        }
        else
        {
                if(change_local=="add")
                {
                CBIP_D->add_ip(arg);
                }
                else
                {
                CBIP_D->del_ip(arg);
                }
        }
        write(LOCAL);
        write("请输入欲往之选项:\n");
        input_to( (: get_choice :), this_player() );
        return ;
}

