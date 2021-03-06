inherit ITEM;
#include <ansi.h>
object ob=this_object(),me=this_player();
void create()
{
	set_name(HIY"金之封印石"NOR,({"gold fon stone","stone"}));
	set("long","一个封印着神兵利器的神秘石头，上面有着数个大大小小不等的\n"
		  +"奇形怪洞，应该可以放入解开封印的物品，若想要得到封印的神\n"
		  +"兵，可以将你所得到的解封印的物品(insert)进去，就可以让神\n"
		  +"兵重新现世。\n");
	set("unit","尊");
	set("value",100);
	set("no_get",1);
	set("no_sac",1);
	set("no_auc",1);
	set_weight(500000);
        setup();
}

void init()
{
	add_action("do_insert","insert");
}

int do_insert(string str)
{
	switch(str)
	{
	case "sky-stone":
	if(!ob->query("sky")==1 && (present("sky-stone",me)->query("specialitem")==1) )
	{
	message_vision(HIB"$N将天尊石镶入了封印之石，只见封印之石缓缓列开一道缝隙并透出阵阵蓝光!!\n"NOR,me);
	ob->set("sky",1);
	ob->add("check",1);
	destruct(present("sky-stone",me));
	call_out("check",1,ob);
	}else{
	tell_object(me,"天尊石已经放在正确的地方啰!!\n");
	}
	break;

	case "loyal-stone":
	if(!ob->query("loyal")==1 && (present("loyal-stone",me)->query("specialitem")==1) )
	{
	message_vision(HIB"$N将忠贞石镶入了封印之石，只见封印之石缓缓列开一道缝隙并透出阵阵蓝光!!\n"NOR,me);
	ob->set("loyal",1);
	ob->add("check",1);
	destruct(present("loyal-stone",me));
	call_out("check",1,ob);
	}else{
	tell_object(me,"忠贞石已经放在正确的地方啰!!\n");
	}
	break;

	case "peace-stone":
	if(!ob->query("peace")==1 && (present("peace-stone",me)->query("specialitem")==1) )
	{
	message_vision(HIB"$N将和平石镶入了封印之石，只见封印之石缓缓列开一道缝隙并透出阵阵蓝光!!\n"NOR,me);
	ob->set("peace",1);
	ob->add("check",1);
	destruct(present("peace-stone",me));
	call_out("check",1,ob);
	}else{
	tell_object(me,"和平石已经放在正确的地方啰!!\n");
	}
	break;

	case "emperor-stone":
	if(!ob->query("emperor")==1 && (present("emperor-stone",me)->query("specialitem")==1) )
	{
	message_vision(HIB"$N将皇者石镶入了封印之石，只见封印之石缓缓列开一道缝隙并透出阵阵蓝光!!\n"NOR,me);
	ob->set("emperor",1);
	ob->add("check",1);
	destruct(present("emperor-stone",me));
	call_out("check",1,ob);
	}else{
	tell_object(me,"皇者石已经放在正确的地方啰!!\n");
	}
	break;

	case "soil-stone":
	if(!ob->query("soil")==1 && (present("soil-stone",me)->query("specialitem")==1) )
	{
	message_vision(HIB"$N将地尊石镶入了封印之石，只见封印之石缓缓列开一道缝隙并透出阵阵蓝光!!\n"NOR,me);
	ob->set("soil",1);
	ob->add("check",1);
	destruct(present("soil-stone",me));
	call_out("check",1,ob);
	}else{
	tell_object(me,"地尊石已经放在正确的地方啰!!\n");
	}
	break;

	case "justice-stone":
	if(!ob->query("justice")==1 && (present("justice-stone",me)->query("specialitem")==1) )
	{
	message_vision(HIB"$N将正义石镶入了封印之石，只见封印之石缓缓列开一道缝隙并透出阵阵蓝光!!\n"NOR,me);
	ob->set("justice",1);
	ob->add("check",1);
	destruct(present("justice-stone",me));
	call_out("check",1,ob);
	}else{
	tell_object(me,"正义石已经放在正确的地方啰!!\n");
	}
	break;

	case "charity-stone":
	if(!ob->query("charity")==1 && (present("charity-stone",me)->query("specialitem")==1) )
	{
	message_vision(HIB"$N将仁心石镶入了封印之石，只见封印之石缓缓列开一道缝隙并透出阵阵蓝光!!\n"NOR,me);
	ob->set("charity",1);
	ob->add("check",1);
	destruct(present("charity-stone",me));
	call_out("check",3,ob);
	}else{
	tell_object(me,"仁心石已经放在正确的地方啰!!\n");
	}
	break;

	default:
	message_vision("$N似乎想放什么东西，但却找不到正确的位置放!!\n",me);
	break;
	}
	return 1;

}

int check(object ob)
{
	if(ob->query("check") == 7 )
	{
	tell_object(users(),HIC"\n\t\t大地忽然剧烈地憾动了起来，在极远处的一座山顶上落下了数道的闪电!!\n"NOR);
	tell_object(users(),HIC"\n\t\t远处的闪电七彩缤纷，轻轻地划过了天际，划亮了整个天空!!\n"NOR);
	tell_object(users(),HIC"\n\t\t雷声憾动了天地，飞鸟走兽们都慌忙的飞奔走散!!\n"NOR);
	call_out("msg1",5,ob);
	}
	return 1;
}

int msg1(object ob)
{
	tell_object(users(),HIC"\n\t\t在天灵地界中的"HIY"金之封印石"HIC"因为"HIG+ me->query("name")+HIC"的努力而解开了!!\n"NOR);
	tell_object(users(),HIC"\n\t\t因为失去了神力护持的"HIY"金之封印石"HIC"开始剧烈抖动而开始崩散消逝!!\n"NOR);
	call_out("msg2",5,ob);
	return 1;
}

int msg2(object ob)
{
	tell_object(users(),HIC"\n\t\t在天灵地界尘封已久的"HIM"「金风舞梦旋”"NOR+HIC"从"HIY"金之封印石"HIC"中得到了解放而现世了!!\n"NOR,ob);
	message_vision(HIW"\n\t\t七颗解开封印的智石转化为七束光茫，缓缓注入了"HIM"「金风舞梦旋”"NOR+HIW"之中转化为不可思议的力量!!\n",ob);
	message_vision(HIW"\n\t光茫消散之后"HIM"「金风舞梦旋”"NOR+HIW"缓缓凝聚在$N手中!!\n"NOR,me);
	new("/data/autoload/open-area/money_sword")->move(me);
	write_file("/log/sky/goldfon",sprintf("%s(%s) 解开了「金风舞梦旋”于 %s\n",me->name(1),me->query("id"),ctime(time())));
	destruct(ob);
	return 1;
}