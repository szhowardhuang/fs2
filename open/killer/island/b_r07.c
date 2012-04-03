#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[1;37m×ßµÀ[0m");
  set ("long", @LONG
ÄÏ±ßµÄÃÅ(door)ËÆºõ²»Í¬ÓÚÖ®Ç°Ëù¿´µ½µÄÄÇÐ©ÃÅ£¬±È½ÏÆðÀ´£¬ÕâÒ»ÉÈÃÅËÆºõ¸Ð
¾õ¸ß¹óÁËÐí¶à£¬¿´À´×¡ÔÚÕâ¼ä·¿¼äµÄÈËÓ¦¸ÃÊÇÒ»¸öÂúÖØÒªµÄÈË°É¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/death" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "door" : "ÕâÉÈÃÅ²¢Ã»ÓÐ°ÑÊÖ¿ÉÒÔ×ª¶¯£¬¿´À´ÓÃÆÕÍ¨µÄ·½·¨ÊÇ´ò²»¿ªµÄ¡£
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"b_r06",
]));

  setup();
}
void init()
{
add_action("do_pray","pray");
}
int do_pray(string arg)
{
object me;
me=this_player();
if(!arg||arg!="door")
return notify_fail("ÄãÒªÆíµ»Ê²Ã´£¿\n");
if(me->query_temp("quest_corpse")!=2)
return notify_fail("ÄãÇáÉùµÄÏò´óÃÅÆíµ»£¬È´Ê²Ã´ÊÇÒ²Ã»·¢Éú¡£\n");
else{
tell_object(me,"ÄãËÆºõ¸Ð¾õµÄµ½ÓÐÈËÔÚ¸úÄãµÀÐ»....\n\n");
message_vision(HIB"      $NµÄÉíÌåÍ»È»±»Ò»ÍÅÀ¶¹â°üÎ§×¡£¬Õû¸öÈËÌÚ¿ÕÏûÊ§ÁË£¡£¡\n\n"NOR,me);
tell_object(me,"Äã´©¹ýÁËÃÅ°å£¬½øÈëÁË·¿¼äÄÚ¡£\n");
me->move(__DIR__"b_q");
return 1;
}
}
