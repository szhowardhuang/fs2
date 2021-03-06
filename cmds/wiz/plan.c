// plan.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

inherit F_DBASE;

void create()
{
        seteuid(getuid());
        set("name", "计划指令");
        set("id", "plan");
}

int main(object me, string arg)
{
        if(arg == "none")
        {
                me->delete("plan");
                write("Plan 清除。\n");
        } else {
      //  me->edit( (: this_object(), ({ "do_plan", me}) :) );
        me->edit( (: call_other, __FILE__, "do_plan", me :) );
        }
        return 1;
}

void do_plan(object me, string text)
{
object link_ob;

        me->set("plan", text);
        link_ob = me->query_temp("link_ob");
        if( link_ob ) {
                link_ob->set("plan", text);
                link_ob->save();
        }
        write("Plan 设定完成。\n");
}

int help(object me)
{
write(@HELP
指令格式 : plan || plan none

这个指令可以编辑自己的计划，plan none 可以清除设定。

相关指令：finger 
HELP
    );
    return 1;
}

