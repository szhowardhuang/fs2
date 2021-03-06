// purge.c

#include <ansi.h>
#define SYNTAX  "指令格式：purge [<未上线天数>] | <使用者姓名> because <原因>\n"

inherit F_CLEAN_UP;

int do_purge_players(int day);
int do_purge_all_players();

int main(object me, string arg)
{
        string name, reason;
        int day;
        object ob;

        if( me!=this_player(1))
                return notify_fail("你没有权力使用这个指令。\n");

        if( !arg ) return notify_fail(SYNTAX);

        if (arg == "(player)") return do_purge_all_players();
        if( sscanf(arg, "%d", day) && day >= 0) return do_purge_players(day);

        if( sscanf(arg, "%s because %s", name, reason)!=2 )
                return notify_fail(SYNTAX);

        if (SECURITY_D->get_status(name) != "(player)")
                return notify_fail("请用 purgewiz 的指令来 purge 巫师。\n");

        seteuid(getuid());
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
                return notify_fail("没有这位使用者。\n");

        if(ob=find_player(name))
                destruct(ob);

        cp(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__, "/data/backup/login/" +  name[0..0] + "/" + name +__SAVE_EXTENSION__);
        cp(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__, "/data/backup/user/" +  name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        write( "使用者 " + capitalize(name) + " 删除掉了。\n");

tell_object(users(),"【"HIC"闲聊"NOR"】"HIC"清秀小岚美眉(Anmy)说道:"HIC+ capitalize(name) +HIC"受到"HIW"天谴"HIC"，消失于狂想空间了。\n"NOR);
        log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, reason));

        return 1;
}

int do_purge_all_players()
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        mixed info;

        seteuid(getuid());
        message("system", "\n*** 整理玩家储存档中，请稍候.... ***\n", users());
        write("处理中：");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write(dir[i]);
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 )
                                if( (string)SECURITY_D->get_status(name)!="(player)" )
                                        continue;
                        info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                        if( SECURITY_D->get_status(name) == "(player)" ) {
                                rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                                rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
                                count ++;
                        }
                }
        }
        write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
        write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");

        return 1;
}

int do_purge_players(int day)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        mixed info;

        seteuid(getuid());
        message("system", "\n*** 整理玩家储存档中，请稍候.... ***\n", users());
        write("处理中：");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write(dir[i]);
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 )
                                if( (string)SECURITY_D->get_status(name)!="(player)" )
                                        continue;
                        info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                        if( (time()-(int)info[1])/86400 >= day ) {
                                rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                                rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
                                count ++;
                        }
                }
        }
        write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
        write( count + " 个超过 " + day + " 天未上线的使用者被清除掉了。\n");
        write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
        log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));


        return 1;
}

int help()
{
        write(SYNTAX + @TEXT

清除一个使用者或清除超过一定天数不曾上线地使用者。
清除一个会留备份在 backup，用 restore -1 可救回来。
TEXT
        );
}
