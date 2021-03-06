int help (object me);
inherit F_CLEAN_UP;

int main(object me, string arg)
{
  object	*ob, obj;
  int		i;

  if (!arg) return help(me);
  if (arg == "all") {
    for (i=0; i<sizeof(ob=all_inventory(me)); i++) {
      ob[i]->delete_temp("secured");
      ob[i]->delete("autoload");
    }
  }

  else if (obj = present(arg, me)) {
    obj->delete_temp("secured");
#ifdef SAVEEQ
    obj->delete ("autoload");
#endif
  }
  else return notify_fail ("没有这样物品.\n");
  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : unsecure <物件>
范    例 : unsecure map
	   unsecure all
说    明 :
	   本指令让玩家可以取消保护物件，才可以被 drop，sell，give
HELP
    );
    return 1;
}
