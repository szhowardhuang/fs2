// goto.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int goto_inventory = 0;
        object obj, env;
        string msg;

        if( !arg )
          if (me->query("last_location"))
            return me->move(me->query("last_location"));
          else
            return notify_fail("用法: goto [-i] 人|房间\n例如: goto wade 或 goto /u/w/wade/workroom\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if (!obj) obj=LOGIN_D->find_body(arg);
if(obj&&wizardp(obj)&&obj->query("env/隐身") && wiz_level(me) < wiz_level(obj))
           return notify_fail("没有这个玩家、生物、或地方。\n");
        if(!obj) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>0 ) {
                                return me->move(arg);
                        }
                        return notify_fail("没有这个玩家、生物、或地方。\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");

        if( stringp(msg = me->query("msg_mout")) )
                message_vision(msg, me);
        else
                message_vision("只见一阵烟雾过后，$N的身影已经不见了。\n", me);

        env = environment(me);
        me->move(obj);
        if( !sizeof(all_inventory(env)) && ( !env->query("objects")
         || !sizeof(env->query("objects")) ) ) destruct(env);

        if( stringp(msg = me->query("msg_min")) )
                message_vision(msg, me);
        else
                message_vision("$N的身影突然出现在一阵烟雾之中。\n", me);

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : goto [-i] <目标>
 
这个指令会将你传送到指定的目标. 目标可以是一个living 或房间
的档名. 如果目标是living , 你会被移到跟那个人同样的环境.
如果有加上 -i 参数且目标是 living, 则你会被移到该 living 的
的 inventory 中.
 
HELP
    );
    return 1;
}
