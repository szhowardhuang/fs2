//get_rest.c by bss 把玩家从监牢放出来
#include <ansi.h>
#include <login.h>
#define SYNTAX  "指令格式：unget_rest 使用者姓名\n"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object player,ob;
        string name,reason;

        if(!arg) return notify_fail(SYNTAX);

        name=arg;
        seteuid(getuid());
        player=find_player(name);
        if(player)
        {
                if(!player->query("have_get_rest"))
                        return notify_fail("他并没有在天牢里阿!!\n");
                player->set("have_get_rest",0);
                player->set("startroom",STARTROOM);
                tell_room(environment(player),HIM"
忽然有两名神将出现在众人眼前，对众人说道:吾等奉命释放
"+HIY+player->query("name")+HIM+"并将其送回人间!!\n"NOR);
                player->move(STARTROOM);
                player->save();
        }
        else
        {
                if(!FINGER_D->acquire_login_ob(name))
                        return notify_fail("没有这个玩家!!\n");

                ob="/adm/daemons/cappointd.c"->get_user_ob(name);
                player="/adm/daemons/cappointd.c"->get_user_body(ob);
                player->set_temp("link_ob",ob);
                player->setup();
                if(!player->query("have_get_rest"))
                        return notify_fail("他并没有在天牢里阿!!\n");
                player->set("have_get_rest",0);
                player->set("startroom",STARTROOM);
                player->save();
        }
        write(name+"这名玩家已经被释放了!!\n");
        log_file("static/UNGET_REST",sprintf("%s 被 %s 放出天牢 at %s\n"
                 ,name,me->query("id"),ctime(time())));
        return 1;
}

