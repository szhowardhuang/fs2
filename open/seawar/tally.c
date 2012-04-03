inherit ITEM;
#include <ansi.h>
        
void create()
{
        set_name(WHT"玄冥符"NOR,({"black dark tally","tally"}));
        set_weight(1000);
	set("long","
一个古老传说的符文；在你急需救助，抑或是濒临死亡之时，可以回复
最佳状态的神奇符文。

使用方法:

        设定 : setup [种类] [最低值]    取消 : remove tally

        种类 : gin,kee,sen
\n");
        set("value",0);
        set("unit","张");
        setup();
        set_heart_beat(1);
}


void heart_beat()
{
object ob,me;
int gin,kee,sen,t_gin,t_kee,t_sen;

	me = this_player();
	ob = this_object();
        gin = me->query("gin");
        kee = me->query("kee");
        sen = me->query("sen");

        t_gin = me->query_temp("tally/gin");
        t_kee = me->query_temp("tally/kee");
        t_sen = me->query_temp("tally/sen");

        if( (string)ob->query("can_use") == (string)me->query("id") )
        {
                if( t_gin >= gin || t_kee >= kee || t_sen >= sen )
                {
                                message_vision("
$n从$N的手中冒出一阵黑烟。

$N精、气、神，瞬间回复到最佳状态！！\n",me,ob);
                                me->receive_curing("gin", (int)me->query("max_gin") );
                                me->receive_heal("gin",   (int)me->query("max_gin") );
                                me->receive_curing("kee", (int)me->query("max_kee") );
                                me->receive_heal("kee",   (int)me->query("max_kee") );
                                me->receive_curing("sen", (int)me->query("max_sen") );
                                me->receive_heal("sen",   (int)me->query("max_sen") );
                                me->delete_temp("tally");
                                destruct(ob);
                }
        }
}

void init()
{
add_action("do_set","setup");
add_action("do_remove","remove");
}

int do_set(string arg)
{
object me,ob;
string args;
int i,max;

        me = this_player();
        ob = this_object();
        
        if( !arg )
                return 0;

        if( arg )
                if( sscanf(arg, "%s %d", args, i) != 2 )
                        return notify_fail("
使用方法:

        set [种类] [最低值]

        种类 : gin,kee,sen
\n");

        if( args != "gin" && args != "kee" && args != "sen" )
                        return notify_fail("
使用方法:

        set [种类] [最低值]

        种类 : gin,kee,sen
\n");

        if( i <= 0 )
                return notify_fail("最低值不可为0。\n");

        message_vision("$N双手和握，$n从$N手中的细缝，溢出阵阵黑烟。\n",me,ob);
        ob->set("name",BRED"～ 附身 ～"+WHT" 玄冥符"NOR);
        ob->set("can_use", (string)me->query("id"));
        me->set_temp("tally/"+args,i);
return 1;
}

int do_remove(string arg)
{
object ob,me;

        me = this_player();
        ob = this_object();

        if( !arg )
                return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
                return 0;
        if( ob != this_object() )
                return 0;

        message_vision("$N口中咏颂着符文，$n从手中掉落不见。\n",me,ob);
        me->delete_temp("tally");
        destruct(ob);
return 1;
}
