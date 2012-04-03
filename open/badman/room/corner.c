#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
int do_list();
int do_trade(string);
void create() {
set("short","ÀÇÅï½ÇÂä");
set("long",@LONG
ÕâÀïÊÇÕû¸öÅï×ÓµÄÒ»½Ç£¬ÓĞ¸öÀÏÄêÈËÕ¾ÔÚÕâ£¬ÎªºÁÎŞÈËÑÌµÄ´å×Ó
Ìí¼ÓÁËµãÉúÆø¡£ËûÕıÔÚÎªÀÇÈº×¼±¸Ê³Îï£¬Äã¿´µ½ËûºÍÀÇÈº¼äµÄ¹ØÏµÊÇ
Èç´ËÇ×ÃÜ£¬»òĞí¿ÉÒÔ¸úËûÒªÆ¥ÀÇÀ´ÆïÆï°É¡£
LONG);
  set("exits",([ /* sizeof() == 1 */
  "center" : __DIR__"wolf09.c",
]));
  set("objects",([ /* sizeof() == 1 */
  "/open/badman/ride/rider.c" : 1,
]));
  set("light_up", 1);
        set("no_kill", 1);
set("no_fight", 1);
        set("no_magic", 1);
        setup();
}
void init() {
  add_action("do_trade","want");
}

int do_trade(string str) {
  int exp;
  object me,wolf;
  me=this_player();
  exp=me->query("combat_exp",1);
  if(me->query_temp("marks/have_wolf",1))
  return notify_fail("[1;33m²»ÊÇ¸øÄãÄÃ×ßÒ»Æ¥ÁËÂğ£¿[0m\n");
  if (me->query("marks/ride_wolf")!=1)
  return notify_fail("[1;33mËäÈ»ÀÇÊÇÎÒÔÚÑø£¬µ«ËùÓĞÈ¨ÊÇİ¹´óÒ¯µÄ°¡£¡[0m\n");
  if (exp<350000)
  return notify_fail("[1;33mÄãÒªÆï£¿ÎÒ¿´²»Ì«ĞĞ°É£¿ÔÙÈ¥Á·Á·°É£¡[0m\n");
  new("/open/badman/ride/r_wolf.c")->move(environment(me));
  me->set_temp("marks/have_wolf",1);
  message_vision("[1;37mĞíÀÏ´ÓÀÇÈºÖĞÌôÁËÒ»Ö»ºìÀÇÀ´¡£[0m\n",me);
  return notify_fail("[1;32mÕâÀÇ¾Í½»¸øÄãÀ²£¬ÒªºÃºÃÕÕ¹Ë°¡£¡[0m\n");
}
