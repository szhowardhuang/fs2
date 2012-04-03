// Room: /u/d/dhk/questsfan/rm28
inherit ROOM;
#include </open/open.h>
#include <ansi.h>
void create ()
{
  set ("short", "²Ø[1;35mÏÉ¹È[2;37;0m");
  set ("long", @LONG
ÕâÀïÊÇáÔÉ½×îÓÐÃûµÄ£¢áÔÉ½Ë«¹È¡åÖ®Ò»£¬ÓÐ×Å¡®ÏÉÈË¹ÊÏç¡¯µÄÑÅ
³ÆµÄ²ØÏÉ¹È¡£¾ÝÒ»Ð©½­ºþÒ¥´«£¬ÈôÊÇÐÞµÀÖ®ÈËÔÚ½«½üµÃµÀ³ÉÏÉÖ®Ç°ÄÜ
Ç°Íù´Ë¹ÈÐÞÐÐ¡¢¾Ó×¡Ò»¶ÎÊ±ÈÕ±ãÄÜÁ¢¼´µÃµÀ³ÉÏÉ¡£²»¹ýÄã×ÐÏ¸ÏòËÄÖÜ
´òÁ¿Ò»·¬£¬·¢¾õ´ËµØÖ»²»¹ýÊÇÒ»×ùÆÕÍ¨µÄÉ½¹È£¬¶¥¶àÊÇ»·¾³ÂÔÎªÓÅÑÅ
¡¢ÇåÐÂÒ»µã°ÕÁË£¬ÊµÔÚ¿´²»³öËüµÄÌØ±ðÔÚºÎ´¦£¬ÊµÔÚÁîÈËÄÉÃÆÑ½£¡

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"rm33",
  "west" : __DIR__"rm35",
]));

  setup();
}
int valid_leave(object who,string dir)
{
        if(dir=="west"&&present("mountain god",environment(who))||dir=="west"&&!present(environment(who)))
  {
        if(who->query_temp("meetgod_4")!=1)
        {
//       tell_object(who,""HIM"¹ÈÖÐÏÉÅ­ºÈ:·²·òË××Ó¾¹È»ÂÒ´³²ØÏÉ¹È£¬»¹²»ËÙËÙÀëÈ¥¡£"NOR"\n");
        return notify_fail("¹ÈÖÐÏÉÅ­ºÈ:·²·òË××Ó¾¹È»ÂÒ´³²ØÏÉ¹È£¬»¹²»ËÙËÙÀëÈ¥¡£\n");
        }
        return :: valid_leave(who,dir);
  }
  return :: valid_leave(who,dir);
}
void init()
{
call_out("dhk",1,this_player()); 
}
void dhk(object who)
{
  object god=new(__DIR__"npc/god.c");
    if(who->query_temp("meetgod_4")!=1 && !present("mountain god",environment(who)))
    {
       god->move(__DIR__"rm34.c");
       remove_call_out("dhk");
    }
}
