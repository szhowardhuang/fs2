// lock.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir;
	string	key, *key_of_room;
	object ob, env;
	int i;

	if( !arg ) return notify_fail("你要锁什么？\n");
	arg = lower_case(arg);

	if (sscanf (arg, "%s with %s", arg, key) != 2) return
	  notify_fail ("你想用什么锁门啊。\n");
	if (!ob = present (key, me)) return
	  notify_fail ("你身上并没有 "+key+"。\n");

	env = environment(me);
	doors = env->query_doors();
	if( mapp(doors) ) {
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("你要锁什么？\n");
	
                if ((string)env->query("need_key/"+dir) ||
                    (string)env->query("need_key/door"))
                {
                  key_of_room=ob->query("key_of_room");
                  if (!sizeof (key_of_room) ||
                       strsrch(implode(key_of_room," "),file_name (env))==-1)
                  {
                      return notify_fail("这把钥匙不能锁这个门。\n");
                  }
                }

		if( env->lock_door(dir) ) {
		  message_vision("$N听到喀的一声, 将" + doors[dir]["name"] + "锁上。\n", me);
		  return 1;
		}
	}

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : lock <door> 或 <方向>
指令说明 : 
           这个指令可以让你关上门.
其他参考 :
           unlock，open，close 
HELP
    );
    return 1;
}
