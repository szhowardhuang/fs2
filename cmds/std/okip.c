
int help();

int main(object me, string str)
{
        string  flag, okip, *ip_list, *ips;
        int     i;

        if( !str ) {
                if(!me->query("ok_ip"))
                        write( "你还没设 ok-ip.\n");
                else
                        write( "你的 ok-ip 现在设定为 :\n"+"  "+
                                (string)me->query("ok_ip")+"\n" );
                return 1;
        }

        if( (string)me->query("name") == "guest" )
                return notify_fail("你不能帮 guest 设 okip!!\n");

        if( sscanf(str,"-%s %s", flag, okip) != 2 )
                return help();

        if( me->query("ok_ip") )
                ip_list = explode( me->query("ok_ip"), ":" );
        else 
                ip_list = ({});

        if( okip == "now" )
                ips = ({ (string)me->query("ip") });
        else if( okip )
                ips = explode(okip,":");

        if( flag == "s" )
                ip_list = ips;
        else if( flag == "a" ) {
                for( i=0; i<sizeof(ips); i++ )
                        if( member_array(ips[i], ip_list) == -1 )
                                ip_list += ({ ips[i] });
        } else if( flag == "d" ) {
                for( i=0; i<sizeof(ips); i++ )
                        if( member_array(ips[i], ip_list) != -1 )
                                ip_list -= ({ ips[i] });
        } else return notify_fail("Wrong flag!\n");

        me->set("ok_ip", implode(ip_list,":"));

        write("OK-IP 现在设定为 :\n"+"  "+ me->query("ok_ip")+"\n");
        me->save();
        return 1;
}

int help()
{

        write(@C_HELP
指令格式：okip <-a | -d | -s> <IP:IP:...>

本指令可以让您设定自己的 okip list。只有从这些 IP address 上
连过来的人才能使用这个人物。

参数说明：
    -a                          增加
    -d                          删除
    -s                          重新设定

IP 格式可以为 140.113.23.32 或 140* 或 *23 或 cis* 或 *pc 等
。但请勿使用 "?"。若无给予任何参数，将会传回现有的 okip list
。若 IP = now 则视为目前的 login IP。

当您不确定您的 ip name，或是当 ip name 不能正常作用时， 请使
用 ip number 以避免错误。

范例：
    okip -a aaa.bbb.ccc.ddd     将 aaa.bbb.ccc.ddd 加入 okip 里。
    okip -d aaa.bbb.ccc.ddd     将 aaa.bbb.ccc.ddd 自 okip 中删除。
    okip -s aaa.bbb.ccc.ddd eee.fff.ggg.hhh
                                将原来的 aaa.bbb.ccc.ddd 替换为
                                eee.fff.ggg.hhh。

使用格式: okip [-a|-d|-s] [IP:IP:...]

    这指令可以用来设定你自己的 okip LIST，只有从这些 IP address 上连过
来的人才能使用这个人物 。

参数说明: a - 增加、d - 删除、s - 重新设定。

    IP 格式可为 140.113.23.32 或 140* 或 *23 或 cis* 或 *pc 等。
但请勿使用"?"。若无给予任何参数将会传回现有的 okip list。
若 IP = now 则视为目前的 login IP。

C_HELP
        );
}
