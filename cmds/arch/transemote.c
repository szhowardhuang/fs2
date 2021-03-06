// /cmds/arch/transemote.c
// 本档案改自 es2 mudlib
// 欢迎流传本档案, 请保留本档头
// wade 1998/7/10

inherit F_CLEAN_UP;

int in_use;

int main(object me, string arg)
{
  string        *emotes;
  mapping       emote;

  if ( !arg ) return notify_fail("你要转换什么 emote？\n");

  if ( arg == "-a" ) {
    int i, s, trans;

    emotes = EMOTE_D->query_all_emote();
    s = sizeof (emotes);
    for (i=0; i<s; i++) {
      write ("转换["+i+"]: "+emotes[i]+"\n");
      emote = EMOTE_D->query_emote (emotes[i]);
      trans = 0;
      if (!undefinedp (emote["updated"])) {
        trans = 1;
        map_delete (emote, "updated");
      }
      if (undefinedp (emote["short"]) && !undefinedp (emote["myself"])) {
        emote["short"] = emote["myself"][0..7];
        trans = 1;
      }
      if (trans) EMOTE_D->set_emote (emotes[i], emote);
    }
    return 1;
  }

  emote = EMOTE_D->query_emote(arg);

  write ("转换 emote：" + arg + "\n");
  write ("───────────────────────────────\n");
  printf ("自己:%s\n其他人:%s\n看给自己:%s\n他人看给自己:%s\n看给他人:%s\n",
          emote["myself"],
          emote["others"],
          emote["myself_self"],
          emote["others_self"],
          emote["myself_target"]);
  printf ("他人看给他:%s\n其他:%s\n",
          emote["target"], emote["others_target"]);
  write ("───────────────────────────────\n");
  write ("短讯息：");
  input_to("get_msg", emote, arg);
  return 1;
}


int get_msg (string msg, mapping emote, string pattern)
{
  if (msg == "~q") {
    write ("取消。\n");
    return 1;
  }
  emote["short"] = msg;
  EMOTE_D->set_emote (pattern, emote);
  return 1;
}

int help(object me)
{
write(@HELP
指令格式 : transemote [-a | emote]
 
这个指令可以转换 emote 成新格式，请勿乱用。
HELP
    );
    return 1;
}
