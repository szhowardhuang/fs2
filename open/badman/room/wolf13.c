inherit ROOM;
 void create()
{
  set ("short","ÆÆÃí");
  set ("long",@LONG
ÕâÊÇÒ»¼ä¿´À´ÒÑ»Ä·ÏÒÑ¾ÃµÄĞ¡Ãí .¹©×ÀÉÏºÍ°ª¿ÉÇ×µÄ·ğÏñÒ²ÒÑÆÆ¾É
²»¿° ,´ÓËÄÖÜÍÇÛÜ²»ÒÑ ,Äê¾ÃÊ§ĞŞµÄÇé¿ö¿´À´ ,ÕâÀïËÆºõµÄÈ·ÊÇÎŞÈË¾Ó
×¡ .
LONG);

  set("light_up", -1);
  set("exits", ([ /* sixeof() == 1 */
  "east" : __DIR__"wolf12.c",
]));

  setup();
}

void init()
{
  add_action("do_search","search");
  add_action("do_bump","bump");
}
int do_search()
{
  object who;
  who = this_player();
  if (who->query_temp("marks/karup2",1))
  {
   tell_object(who,"Äãµ½´¦¿´ÁË¿´£¬·¢ÏÖÔÚÆÆ¾ÉµÄÉñ×ÀÅÔÓĞÉÈ\n");
   tell_object(who,"°ëËúµÄÃÅ£¬ÓÉÇ½±ÚÌ®ËúµÄÊ¯¶ÑËäÈ»½«Í¨µÀ\n");
   tell_object(who,"¶Â×¡£¬µ«»òĞí¿ÉÒÔ½«Ö®×²¿ª£¨bump£©¡£\n");
   who->set_temp("marks/bump",1);
   return 1;
  }
  else
  {
  message_vision("[36mÕâÖÖÆÆ¾ÉµØ·½ÓĞÉ¶ºÃËÑÑ°µÄ£¿[0m\n",who);
  return 1;
  }
}
int do_bump()
{
  object who;
  who = this_player();
  if (who->query_temp("marks/bump",1))
  {
   tell_object(who,"[1;33mÄãÆø³Áµ¤Ìï£¬Ê¹¾¢ÓÃÁ¦Ò»×²£¡[0m\n");
   tell_object(who,"[1;33m°õ£¡µÄÒ»Éù£¬Äã³åµ½ÁËÁíÍâÒ»¸ö·¿¼ä£¡£¡[0m\n");
   tell_object(who,"[1;33mµ«ºÃ¾°²»³££¬Äã½ÅÏÂÒ»¿Õ£¬µøµ½ÁËÒ»¸ö´ó¶´ÖĞ£¡£¡[0m\n");
   who->move("/open/badman/room/bump.c");
   tell_room(this_object(),"[1;31mÄãÖ»¿´µ½"+who->query("name")+"ÍùÇ°Ò»³å£¬¾Í²»¼ûÁË!£¡[0m\n");
   return 1;
  }
  else
  {
  message_vision("[36m×²£¿ÄãÊÇÒª×²ÄÄÀï£¿£¿[0m\n",who);
  return 1;
  }
}
