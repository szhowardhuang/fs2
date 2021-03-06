// copy from Room: /d/snow/postoffice.c

inherit ROOM;

void create()
{
        set("short", "巫师专用邮局");
        set("long", @LONG
    邮局门口上悬着一块木牌(sign)，上面写了些字。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
	    "sign" : "牌子上写道：

          巫师专用邮局

",
]));
        set("exits", ([ /* sizeof() == 1 */
                "east" : "/open/wiz/hall1",
        ]));

        setup();
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

void init()
{
  object mbox;

  seteuid(getuid());

  if( !this_player()->query_temp("mbox_ob") ) {
    mbox = new(MAILBOX_OB);
    if (mbox->move(this_player()))
      write ("[邮局]: 邮务小姐看你一进来, 交给你一个信箱\n");
  }

  add_action ("do_home", "home");
  add_action ("do_goto", "goto");
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

int do_goto (string arg)
{
  object mbox, me;

  me = this_player();
  if( mbox = me->query_temp("mbox_ob") ) {
    tell_object(me, "你将信箱交回驿站。\n");
    destruct(mbox);
  }
  
  return 0;
}
