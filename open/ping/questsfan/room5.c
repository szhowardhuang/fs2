// Room: /u/d/dhk/questsfan/room5
inherit ROOM;
#include <ansi.h>
#include <room.h>
void create ()
{
  set ("short", "[0;36mÃÜµÀ[2;37;0m");
  set ("long", @LONG
°µ°µµÄ×ßµÀÖÐ£¬ºöÈ»Æ®À´Ò»ÕóÁ¹·ç¡£ÕâÊ±ÄãÐÄÏëÊÇ³ö
¿Úµ½ÁËÂð£¿ÄãÃ®×ãÈ«¾¢×ÐÏ¸ËÑË÷£¬¹ûÈ»×ßµÀµÄ¾¡Í·ÉÏ·½ÓÐ
Ò»´¦ÈôÒþÈôÏÖµÄ³ö¿Ú£¬¶øÇÒ·ç¾ÍºÃÏñÊÇ´ÓÄÇÀïÀ´µÄ¡£

LONG);
set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room4",
]));

  setup();
}
void init()
{
        add_action("do_search", "search");
}

int do_search()
{
        object who;
        who = this_player();

        tell_object(who,"\nÄã×ÐÏ¸ËÑË÷£¬ÖÕÓÚÕÒµ½Ò»¸öÒþÃÜµÄ³ö¿Ú¡£\n\n");
        who->move(__DIR__"room6");
        return 1;
}
