inherit ROOM;
void create()
{
set("short", "红叶组密室");
set("long", @LONG
	你似乎来到了一个诡异的地方，阴暗的灯光显示出这里隐密程度
	你略为环顾了一下四周，想不到居然没有任何出口？
	想不到杀手总坛居然还有这样子的地方，莫非有隐藏着什么样的秘密？
	到处搜寻一下， 应该可以找到一些蛛丝马迹吧......

LONG
);
setup();
}

void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
  object me=this_player();
  int max;

  if (arg)
  	return 0;
  if (me->query_temp("firstpart")  !=2)
  {
    message_vision("$N哇勒....你是怎么来到这里的，作弊呀？？  可恶........。\n", me);
    message_vision("一瞬间一阵机关鸣动声............\n",me);
    max=me->query("kee");
    max= (int) (max/2);
    me->add("kee",-max);
    tell_object(me,"一阵冲撞力将你弹飞，落入陷阱之中一直坠落。。。。。\n");
    me->move("/open/killer/room/firstrm.c");
    return 0;
  }
  else
  {
    message_vision("$N在四周寻找了一下，发现了一个按钮，用力的按了下去\n", me);
    message_vision("一阵机关鸣动声后，墙上突然出现一个暗门，里面竟然是鲁寻!!？\n",me);
    message_vision("你将鲁寻身上的枷锁解开之后，并且解开他的穴道。\n",me);
    message_vision("$N将鲁寻救出来后，询问有关东瀛岛的所在问题.....\n",me);
    tell_object(me,"鲁寻说：‘上次我们去找我爹的梦想得时候，就发现往东瀛方向的风浪过大’\n");
    tell_object(me,"‘所以才会被吹到那作海盗岛上，似乎是因为岛的西北方往东瀛的航道上’\n");
    tell_object(me,"‘有一阵强力的神风阻挡，所以根本无法接近该区域’\n");
    tell_object(me,"‘但是我爹或许会知道(破浪的方法)，你可以前去询问他’\n");
    tell_object(me,"‘后面有一个密道，是东瀛杀手的出入口，你快离开...，我会自己走的’\n");
    me->set_temp("firstpart",3);
    me->move("/open/killer/room/firstrm.c");
    return 1;
  }   
 }
