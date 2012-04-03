inherit ITEM;
#include <ansi.h>
void create ()
{
set_name("铁盒子",({"iron box","box"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","这是一个普通的铁盒子，似乎可以打开(open)的样子。");
        set("no_get",1);
        set("value",1);
        set("unit","盒");
        setup();
}}
void init()
{
add_action("do_open","open");
add_action("do_close","close");
}
int do_open(string arg)
{
object me,ob;
me=this_player();
if(!arg||(arg!="box"))
return notify_fail("你要打开什么？\n");
if(me->query_temp("openbox")==1)
return notify_fail("你已经打开了这个铁盒子。\n");
else{
ob=new(__DIR__"note");
me->delete_temp("move_out");
message_vision(HIY"
$N打开了盒子，只见其中金光闪闪，装满了各式各样的宝物!!
$N在之中发现了一块令牌，外貌非常熟悉，原来是一块黑牙联的杀手密令!!
盒子中装着各式各样的宝物，令你不禁想拿走一些!!
\n"NOR,me);
ob->move(me);
me->set_temp("openbox",1);
return 1;
}
}