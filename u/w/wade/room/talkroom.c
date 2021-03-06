// Room: /u/w/wade/workroom.c
#include <room.h>

inherit ROOM;
inherit F_SAVE;

void create ()
{
  set ("short", "聊天室");
  set ("long", @LONG




	菠萝面包的聊天室,
	专门给他心爱的客人聊天的




LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 3 */
        "down"	: "/u/w/wade/workroom",
  ]));

  restore();
  setup();
  call_other("/obj/board/wade_talk_b", "???");
}

void init ()
{
  object	mbox;
  string	id;
  string	*f;

  id = this_player()->query("id");
  f = this_object()->query("friends");

  if (id == "wade") {
    add_action("setf", "setf");
    add_action("delf", "delf");
    add_action("do_save", "sr");
  }
  else if ( !f || member_array(id, f) == -1 )
  {
    write ("啊, 这里不欢迎不请自来的耶!\n");
    this_player()->move("/open/center/room/inn");
    return;
  }

  seteuid(getuid());

  // 处理信箱.
  if( !this_player()->query_temp("mbox_ob") ) {
    mbox = new(MAILBOX_OB);
    if (mbox->move(this_player()))
      write ("为了您的方便, 面包发给您一张快递单.\n");
  }
  add_action ("do_home", "home");
  add_action ("do_home", "goto");
}

int setf(string arg)
{
  string	*f;
  object	ob;

  if (this_player()->query("id") != "wade")
    return notify_fail("只有主人能动喔!\n");

  f = this_object()->query("friends");
  if (!f)
    f = ({ arg });
  else if (member_array(arg, f) == -1)
    f += ({ arg });
 
  set("friends",f);
  write ("已经把 "+ arg +"设为好友了!\n");
  if (ob=find_player(arg)) {
    tell_object(ob, this_player()->query("name")+
		"邀请你去聊天, 愿意的话请 goto wade\n");
    write ("好了, 已经帮你邀请他了!\n");
  }
  return 1;
}

int delf(string arg)
{
  object	ob;
  string        *f;

  if (this_player()->query("id") != "wade")
    return notify_fail("只有主人能动喔!\n");

  f = this_object()->query("friends");
  if (!f)
    return notify_fail ("名单中已经没有任何名字了\n");
  else if (member_array(arg, f) == -1)
    return notify_fail (arg+"又不在名单中, 你想干嘛?!\n");

  if (ob=present(arg, this_object())) {
    write ("好吧, 顺便把他踢出去吧!\n");
    ob->move("/open/center/room/inn");
    tell_object(ob, "你被踢出去了, 抱歉!\n");
  }
  printf ("旧名单: %O\n", f);
  f = f - ({ arg });
  printf ("新名单: %O\n", f);
  set ("friends", f);
  return 1;
}

string query_save_file()
{
  return "/u/w/wade/room/talkroom";
}

int do_save()
{
  save();
  write ("房间储存完毕!\n");
  return 1;
}

int valid_leave(object me, string dir)
{
        object mbox;

        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你将信箱交回驿站。\n");
                destruct(mbox);
        }
        return 1;
}

int do_home(string arg)
{
  object mbox, me;

  me = this_player();
  if( mbox = me->query_temp("mbox_ob") ) {
    tell_object(me, "你将信箱交回驿站。\n");
    destruct(mbox);
  }

  return 0;
}
