#include <ansi.h>
inherit NPC;

void create()
{
    set_name(RED"<垂死> "NOR"年轻男子", ({"young man","man"}));
    set("long", "一个年轻男子，病的好像死人一般。\n");
    setup();
}
void init()
{
    add_action("do_check","check");
    add_action("do_heal","cmd save_die");
}
int do_check(string arg)
{
    object me=this_player();

    if(arg == "young man" || arg == "man")
{
    if(!me->query("doctor/agree_woman")==1)
{
	write(HIY"老妇人着急的大叫：你想干什么！！！\n"NOR,me);
	return 1;
}else{
	write(HIY"你搬了张椅子到了病床旁边...\n"NOR,me);
	call_out("do_check1",3,me);
	return 1;
    }
  }
}
int do_check1(object me)
{
	write(HIY"你抓起了年轻男子的手腕，开始为他把脉...\n"NOR,me);
	call_out("do_check2",5,me);
}
int do_check2(object me)
{
	write(HIY"你感觉到他微弱不堪的脉搏，似乎还慢慢的在减弱当中...\n"NOR,me);
	call_out("do_check3",3,me);
}
int do_check3(object me)
{
	write(HIY"你皱了皱眉头，发现情况似乎不太乐观...\n"NOR,me);
	call_out("do_check4",3,me);
}
int do_check4(object me)
{
	write(HIY"你看着一旁焦急的老妇人，思考着不知道应不应该跟她说...\n"NOR,me);
	call_out("do_check5",5,me);
}
int do_check5(object me)
{
	write(HIY"你鼓起勇气，终于决定还是要说出口了...\n"NOR,me);
	me->set("doctor/check_man", 1);
	me->delete("doctor/agree_woman");
	return 1;
}
int do_heal(string arg)
{
    object me=this_player();
    object ob=this_object();

    if(!arg || arg != "man") return notify_fail("你想要救活谁???\n");
    if(!me->query("doctor/save_die"))
	return notify_fail("以你现在的能力是救不了他的！\n");
    if(me->query("force") < 8000)
	return notify_fail("以你现在的能力是救不了他的！\n");
    if(ob->query("save")==1)
	return notify_fail("他看起来健健康康的，根本就没必要救他的呀！\n");

	message_vision("$N施展出银针门秘传绝技「圣手回春术”，将手搭在$n的头顶与气海，
灌输自己的真气，想要把$n从鬼门关救回来!!!\n",me,ob);
	message_vision("$N终于把$n给救活了，不过也累出了满身大汗!!\n",me,ob);
	message_vision("$N因此获得了500点的经验值！",me);
	write("一旁的老妇人见状，赶紧奔了过来，激动的说道：这位神医果然名不虚传，多谢您救了小犬一命，
老身无以为报，只有这颗本来要给小犬的「天王保命丹”，那现在就把它献给您了，实在万分感谢！！");
	me->add("combat_exp",500);
	ob->set("name","年轻男子");
	ob->set("long","一个非常健康的年轻男子！");
	ob->set("save",1);
	return 1;
}
