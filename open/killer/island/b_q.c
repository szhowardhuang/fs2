#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[1;37m·¿¼ä[0m");
  set ("long", @LONG
·¿¼äÀïÃæµÄ°ÚÉèËäÈ»ÒÑ¾­±»ÅªÂÒÁË£¬µ«ÊÇÄãÈÔ¾É¿ÉÒÔ¸Ð¾õµÄ³öÀ´Õâ¼ä·¿¼äµÄÖ÷
ÈËÆ·Î¶Ê®·ÖµÄ¸ßÉÐ£¬ÇáÉ´ËÄÉ¢¡¢ÔÙ¼ÓÉÏÒ»Ð©¼òµ¥µÄ·¿¼ä×°ÊÎÆ·£¬Äã·Â·ð¿ÉÒÔ¿´µ½Ö÷
ÈËÉúÇ°µÄÔÚ´ËÐÝÏ¢Ä£Ñù£¬ÔÙ×ÐÏ¸Ò»¿´£¬É¢ÂäµÄÎïÆ·ÖÐ£¬»¹¼ÐÔÓ×ÅÒ»Ð©Å®ºì¡¢Óë´ÌÐå
£¬¿´À´ÄãÑÛÇ°µÄÕâ¾ß¹Çº¡ÉúÇ°Ó¦¸ÃÊÇ¸öÅ®µÄ¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/corpse02" : 1,
]));
  set("no_fight", 1);
  set("no_kill", 1);
  set("no_magic", 1);
  set("no_quit", 1);
  set("no_spell", 1);
  set("no_recall", 1);

  setup();
}
void init()
{
add_action("do_search","search");
}
int do_search()
{
object me;
me=this_player();
if(me->query_temp("get_amulet") >= 1)
{
tell_object(me,"ÄãÊ²Ã´Ò²Ã»ÓÐ·¢ÏÖ¡£\n");
return 1;
}
else
{
tell_object(me,"Äã´ÓÊ¬¹ÇµÄÉíÉÏ·¢ÏÖÁËÒ»¸ö»¤Éí·û¡£\n");
me->set_temp("get_amulet",1);
new(__DIR__"obj/amulet")->move(me);
return 1;
}
}
