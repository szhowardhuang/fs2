// Room: /u/d/dhk/questsfan/rm15
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[0;37mÊ¯ÁÖ[0m");
  set ("long", @LONG
Õâ¶ùÊÇÒ»´¦´ç²Ý²»Éú£¬¼áÊ¯ÁÖÁ¢µÄµØ·½¡£¶øÇÒÕâ¶ù¾»ÊÇÒ»Ð©Ææ
ÐÎ¹Ö×´µÄ¾ÞÊ¯ËÄ´¦ÁÖÁ¢¡£µ«ÊÇÈ´ÓÖ²»ÊÇÈËÔì¶ø³ÉµÄ£¬ËùÒÔ´ËµØµÃÃû
£¢Ê¯ÁÖ¡åÒ²¡£ÔÚ×ÐÏ¸¿´¿´ÕâÐ©¾ÞÊ¯£¬ÓÐÐ©ÖÊµØËÉÉ¢¡¢ÓÐÐ©ÖÊµØ¼áÓ²
¸÷Ê½¸÷ÑùµÄÊ¯ÐÎ¶¼ÓÐ£¬ÓÐÒ»µãÏñÊ¯Í·´ó¹ÛÔ°Ò»°ã¡£

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman" : 2,
]));
  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"rm20",
  "eastup" : __DIR__"rm14",
  "eastdown" : __DIR__"rm16",
  "west" : __DIR__"rm26",
]));

  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=6 && who->query_temp("run")==5)
  {
   tell_object(who,""WHT"ÕâµÀºÚÉ«µÄÈËÓ°Õâ´ÎÓÖ³¯¶«±ßÉ½ÉÏ±¼È¥£¬¾¡¹ÜÄãÅ¬Á¦ÌáÆø±¼³Û£¬»¹ÊÇ×·¸Ï²»¼°¡£"NOR"\n");
   who->set_temp("run",6);
   remove_call_out("dhk");
  }
}

