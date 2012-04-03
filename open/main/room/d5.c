// Room: /open/main/room/d5.c

inherit ROOM;

void create()
{
	set("short", "É³Ä®");
    set("long", "Õâ¶ùÊÇÒ»ÍûÎŞ¼ÊµÄÈö¹şÀ­É³Ä®£¬µ«ÔÚ·çÉ³µÄ±ßÔµÈ´ÓĞ¸öÀÏÍ·ÔÚÄÇÈ÷É¨£¬
ÔÚËûÉíºó»¹ÓĞ¸öÆÄ´óµÄÕÊÅñ¡£
");

  set("exits", ([ /* sizeof() == 4 */
  "enter" : "/open/badman/room/d_c.c",
  "west" : __DIR__"d4",
  "south" : __DIR__"d12",
  "east" : __DIR__"d6",
]) );
  set("objects",([ /* sizeof() == 1 */
  "/open/badman/ride/deserter.c" : 1,
]) );

  set("outdoors", "/open/main" );


  setup();
}

int valid_leave(object who, string dir)
{
  if(dir=="enter" && !who->query_temp("marks/f_c_ent"))
  return notify_fail("Ã»¾­¹ıÖ÷ÈËÔÊĞí¿É±ğÂÒ´³à¸£¡\n");
  return ::valid_leave(who, dir);
}

void init() {
  add_action("do_trade","want");
}

int do_trade(string str) {
  int exp;
  object me,wolf;
  me=this_player();
  exp=me->query("combat_exp");
  if(me->query_temp("marks/have_wolf",1))
  return notify_fail("[1;33mÄã²»ÊÇÓĞ×ùÆïÁËÂğ£¿[0m\n");
  if (!me->query("quests/w_camel",1))
  return notify_fail("[1;33mÄãÔÚ¸úÎÒÒªÉ¶£¿[0m\n");
  if (exp<1200000)
    return notify_fail("[1;37mÄãÒªÆï£¿ÎÒ¿´ÄãÃ»Õâ±¾ÊÂ£¡[0m\n");
  new("/open/badman/ride/r_camel.c")->move(environment(me));
  me->set_temp("marks/have_wolf",1);
  message_vision("[1;37mÀÏÍ·°ÑÂæÍÕÇ£ÁË³öÀ´¡£[0m\n",me);
  return notify_fail("[1;32mÇ§Íò±ğ¿÷´ıÕâÂæÍÕ°¡£¡[0m\n");
}
