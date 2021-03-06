// token.c

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name("ＰＫ执照", ({ "pk license", "license" }) );
	set("unit", "个");
	set ("no_get", 1);
	set ("no_drop", 1);
	seteuid(getuid());
	setup();
}

void init()
{
  add_action ("do_give", "give");
}

string long()
{
  return @TEXT
    拥有ＰＫ执照的人才能合法的享受ＰＫ的乐趣而不必担心受
九省总巡捕的追杀，当然，别以为有了ＰＫ执照就可以为所欲为
的干坏事，想ＰＫ还是去找同样有ＰＫ执照的人吧！
    一旦你拥有ＰＫ执照，quit 之后仍然还在，下次 login 不
必再申请。如果想做安份的老百姓，可以在碰到九天巡捕的时候
向他忏悔退还执照，遗失视同无照，不得申请补发。
TEXT;
}

int query_autoload ()
{
  return 1;
}

int do_give(string arg)
{
  object	me, who, env, obj;
  string	something, someone;

  if (!arg || sscanf (arg, "%s to %s", something, someone) != 2)
    return notify_fail ("用法: give <某物> to <某人>\n");

  me = this_player();
  env = environment(me);
  obj = this_object();
  if (!who=present(someone, env))
    return notify_fail ("嘿! 你想给谁啊!!\n");
  if (something != "license" && something != "pk license") return 0;
  if (who->query("id") != "cop head")
    return notify_fail ("ＰＫ执照只能给九省总巡捕，不然就必须好好收藏。\n");
  message_vision("%N把ＰＫ执照交给了九省总巡捕。\n", me);
  return who->accept_object(me, obj);
}
