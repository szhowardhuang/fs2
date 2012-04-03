//花园迷阵第五型房间，正确方向是东方
inherit ROOM;
string npc_name;
void create()
{
set("short", "花园迷阵");
set("long", @LONG
	在你眼前的是一大片夹竹桃，正开着粉红色的花朵，微风轻拂，枝条摇曳。
	婆娑起舞，奼紫嫣红，轻舞波浪的旋律，不由得令人痴醉。
	陪伴花草的是一堆堆布置完美的绿石，有了这些小山高的石堆，
	将此景色点缀的更无懈可击，石堆与花之间有着参差不齐的羊肠小径。
	在你眼前有一个石堆档路，在十丈之外有一些景色如下。
	东方只有一个石头，北方种有两棵夹竹桃，西方种有两棵夹竹桃，
 	   (请打move east,north,south,west任一方向)

LONG );
set("no_transmit",2);
setup();
}
void init()
{
  int i;
 object guard,me;

  i=random(4); 
 if(interactive(me = this_player()))
 {
  switch(i)
  {
	case 0:
	{
		guard=new("/open/killer/headkill/npc/hoga.c");
		guard->move("/open/killer/headkill/killtest/flowrm6.c");
		npc_name="ice river";
		break;
	}
	case 1:
	{
		guard=new("/open/killer/headkill/npc/shun.c");
		guard->move("/open/killer/headkill/killtest/flowrm6.c");
		npc_name="shun";
		break;
	}
	case 2:
	{
		guard=new("/open/killer/headkill/npc/seiya.c");
		guard->move("/open/killer/headkill/killtest/flowrm6.c");
		npc_name="seiya";
		break;
	}
	case 3:
	{
		guard=new("/open/killer/headkill/npc/ikki.c");
		guard->move("/open/killer/headkill/killtest/flowrm6.c");
		npc_name="ikki";
		break;
	}
	case 4:
	{
		guard=new("/open/killer/headkill/npc/shuryu.c");
		guard->move("/open/killer/headkill/killtest/flowrm6.c");
		npc_name="shuryu";
		break;
	}
  }
 }
  add_action("do_move", "move");
}

int do_move(string arg)
{
  int way;
  object me=this_player();
  object ob=this_object();

  if (!arg)
     return notify_fail("选择一个你要去的方向吧。\n");
 if(present(npc_name,environment(me))) 
     return notify_fail("小子，先打倒守卫再说\n");	

  if ((arg == "west") || (arg == "north") || (arg == "south"))
  {
    me->set_temp("killrun",0);
    me->move(__DIR__"flowrm1.c");
    return 1;
  }
  if (arg == "east")
  {//表示方向正确
    if (me->query_temp("killrun") > 10)
    {
      me->move(__DIR__"flowrm8.c");
      return 1;
    }
    else
	{
		way=random(8);
		me->add_temp("killrun",1);
		switch (way)
		{
			case 0:
			{
				me->move(__DIR__"flowrm2.c");
				return 1;
			}
			case 1:
			{
				me->move(__DIR__"flowrm3.c");
				return 1;
			}
			case 2:
			{
				me->move(__DIR__"flowrm4.c");
				return 1;
			}
			case 3:
			{
				me->move(__DIR__"flowrm5.c");
				return 1;
			}
			case 4:
			{
				me->move(__DIR__"flowrm6.c");
				return 1;
			}
			case 5:
			{
				me->move(__DIR__"flowrm7.c");
				return 1;
			}
			case 6:
			{
				me->move(__DIR__"flowrm7a.c");
				return 1;
			}
			case 7:
			{
				me->move(__DIR__"flowrm7b.c");
				return 1;
			}
	}  //switch block
}		//else block
}  //检查正确方向的block
return notify_fail("挖勒，你移动的是哪一个方向呀！\n");
}
