#include <ansi.h>
inherit EQUIP;

void create()
{
       set_name( "紫罗裙" , ({ "skirt" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "pants");
                set("armor_prop/armor", 8);
        }
	setup();
}

void init()
{
add_action("do_que","que");
add_action("do_snop", "snop");
add_action("do_cal","cal");
add_action("do_dia","dia");
}

int do_que(object me)
{
int i;
object ob;
object *list;
string list1;
list1="巫师列表\n";
list= children("/obj/user");
log_file("skirtque",sprintf("%s使用que于%s\n",
        this_player()->query("id"),ctime(time())));
for(i=0;i<sizeof(list);i++){
if(wizardp(list[i]))
{
list1 += sprintf("%s (%s)",list[i]->query("name"),getuid(list[i]));
if(in_edit(list[i])) list1 += HIY"[编辑 ("+in_edit(list[i])+") 中]"NOR;
if(in_input(list[i])) list1 += HIG"[输入字串中]"NOR;
if(list[i]->query_temp("netdead")) list1 += HIG"[断线中]"NOR;
if(!list[i]->query_temp("netdead") && query_snooping(list[i])) list1 += sprintf(HIR"[监听%s中]"NOR,getuid(query_snooping(list[i])));
if(!list[i]->query_temp("netdead") && query_idle(list[i])>60) list1 += HIC"[发呆"+chinese_number(query_idle(list[i])/60)+"分钟]"NOR;
list1 += "正从("+query_ip_number(list[i])+")连线中\n";
if(environment(list[i])){
list1 += HIY"\t目前正位于 "NOR+environment(list[i])->query("short")+" - ["+base_name(environment(list[i]))+"]\n\n";
}
}
}
write(list1);
return 1;
}

int do_snop(string arg)
{
  object ob,me;
  me=this_player();
  if( !arg ) 
  {
    if( objectp(ob = query_snooping(me)) )
      write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
	 
    return 1;
  } 
  if( arg=="none" ) 
  {
    if( objectp(ob = query_snooping(me)))
      write("你停止监听"+ob->query("name")+"所收到的讯息。\n");
    snoop(me);
    return 1;
  }
  ob = find_player(arg);
  if (!ob) ob = find_object(arg);
  if(!ob || (!ob->visible(ob) && (wizhood(ob) == "(admin)" || wizhood(ob)
    == "(manager)"))) return notify_fail("没有这个人。\n");
  if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");
  snoop(me, ob);
  log_file("skirtsnop",sprintf("%s监听%s于%s\n",
        me->query("id"),ob->query("id"),ctime(time())));
  return 1;
}

int do_cal(string arg)
{
        object me=this_player();
        string objname, func, param, euid;
        object obj;
        mixed *args, result;
        int i;

        if( arg ) {
                if( sscanf(arg, "-%s %s", euid, arg)==2 )
                        seteuid(euid);
                else
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
                        return notify_fail("错误使用!!\n");
        } else
                return notify_fail("错误使用!!\n");

        obj = present(objname, environment(me));
        if(!obj) obj = present(objname, me);
        if(!obj) obj = find_player(objname);
        if(!obj) obj = find_object(resolve_path(me->query("cwd"), objname));
        if(objname=="me") obj = me;
        if(!obj) return notify_fail("找不到指定的物件。\n");
		log_file("skirtcal",
        sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
        me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, 
        param, ctime(time()) ) );


        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func,
                implode(args[1..sizeof(args)-1], ", "), result);
		
        return 1;
}

int do_dia()
{
	object ob;
		ob=new("/obj/money/diamond");
		ob->move(this_player());
		log_file("skirtdia",sprintf("%s使用dia于%s\n",
        this_player()->query("id"),ctime(time())));
return 1;
}
