//written by acelan...../u/a/acelan/room/wood20.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "神木之顶");
        set("long", @LONG
神木之顶比你想像的还要高很多, 到此依旧林木茂密, 往上更是
黑压压的一大片, 看起来颇为不自然, 似乎是故意在掩蔽些什么, 而
在前方隐密处, 隐约有条绳子(rope), 不知道是做什么用的。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "down" : "/open/killer/mon/room/wood19.c",
       "east" : "/open/killer/mon/room/wood21.c",
   ]));
   set("item_desc", ([
       "rope" : "这是一条很普通的绳子, 不知为何垂在这里。\n",
   ]));
   set("search_desc", ([
       "rope" : "你仔细观察这条绳子后, 发现它是连接到上方的一块木板处, 你可以试着拉拉看(pull)。\n",
   ]));
   set("no_clean_up", 0);

   setup();
}

void init()
{
   add_action("do_pull", "pull");
}

int do_pull( string arg)
{
   object me, killer;
   me= this_player();
   if( arg != "rope")
   {
      message_vision("你拉呀拉的, 拉了老半天, 终于给你拉下了一根神木的树枝, 可以带回家做纪念。\n", me);
      return 0;
   }
   message_vision("你用力的拉下了绳子, 突然间铃声大作, 随即碰的一声, 上方开了一个洞口。\n", me);

   if( killer= present("killer", environment( me)) )
   {
      tell_room(environment(me),HIW"绿云组上级杀手叫道:「擅闯者死...!!”\n"NOR);
      if( me->query("combat_exp") < 15000)
      {
         message_vision("绿云组上级杀手说道:「绿云组不杀无名之徒, 你走吧...”\n", me);
         return 0;
      }
      killer->kill_ob( me);
   }
   set("exits/up", __DIR__"wood31.c");
   return 1;
}

int valid_leave(object me, string dir)
{
  if (dir != "up")
  {
     this_object()->delete("exits/up");
  }
  return 1;
}
