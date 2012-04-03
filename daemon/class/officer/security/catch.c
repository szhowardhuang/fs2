#include <ansi.h>
int do_command(object me,object ob,string arg)
{
	int i;
	object obj;
	if(me==ob) 
	{
		tell_object(me,"捉拿自己 ?\n");
		return 1;
	}
	if(ob->query("officer_type")!="catcher")
	{
		tell_object(me,"他没有捉拿人犯的职权。\n");
		return 1;
	}
	obj=find_player(arg);
        if(!obj) obj = find_living(arg);
        if (!obj) obj=LOGIN_D->find_body(arg);
        if(!obj) {
		tell_object(me,"没有这个人。\n");
		return 1;
        }
	if(!userp(obj))
	{
	message_vision(
	"$N说道：立刻随我去捉拿$n !\n",me,obj);
	message_vision(
	"$n答道：愿听从大人差遣\n",me,ob);
	ob->set_leader(me);
	ob->party_npc_set(me,ob);
	}
	else
	{
	message_vision(
	"$N说道：立刻去捉拿"+obj->name()+"\n",me);
	message_vision(
	"$n答道：属下遵命。\n",me,ob);
	message_vision(
	"$n开始去捉拿人犯，离开了这里。\n",me,ob);
	ob->move(environment(obj));
	message_vision(
	"突然之间一道人影闪出，$N来到这里。\n",ob);
	message_vision(
	"$N喝道：大胆小贼"+obj->name()+" ! 快快随吾归案 !!\n",ob,obj);
	ob->kill_ob(obj);
	ob->set_leader(obj);
	}
	if( !ob->query("commander") )
	{
	   ob->set("commander",me->query("id"));
	   ob->set("name",me->query("name")+"的"+ob->query("name"));
	}
	me->add("officer_power",-ob->query("officer_power"));
	return 1;
}
