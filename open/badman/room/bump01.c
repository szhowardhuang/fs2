inherit ROOM;
 void create()
{
  set ("short","ÃíÍ¥ÖĞµÄ´ó¶´");
  set ("long",@LONG
ÕâÀïÊÇ¿Ó¶´µÄ¾¡Í·£¬Ö®Ç°Ëù¿´µ½µÄÄÇ¹ÉÀ¶¹â£¬ÒòÎªÄãµÄ¸ü¼Ó¿¿½ü£¬ÏÔ
µÃ¸üÊÇÒ«ÑÛ£¡×ĞÏ¸Ò»¿´£¬Õâ¹ÉÀ¶¹â¾¹ÊÇÍ¸¹ıµØÃæÉ¢³ö£¬ÄàµØÒ²Òò´ËÍ¸³öÉÁ
ÉÁÀ¶¹â£¬½ÌÈË²»µÃ²»ÔŞÌ¾ÈıÉù£¡£¡£¡
LONG);
  
  set("outdoors", "/open/badman");

  set("exits", ([ /* sixeof() == 1 */
  "east" : __DIR__"bump.c",
]));

  setup();
}

void init()
{
  add_action("do_search","search");
  add_action("do_dig","dig");
}
int do_search()
{
  object who;
  who = this_player();
  message_vision("Äã¿´ÁË¿´µØÉÏµÄÄàµØ£¬ËÉËÉÈíÈíµÄ£¬ºÃÏñ¿ÉÒÔÍÚ£¨dig£©¡£\n",who);
  who->set_temp("marks/dig",1);
  return 1;
}
int do_dig()
{
  object who;
  who = this_player();
  if (who->query_temp("marks/dig",1))
  {
   message_vision("[1;36mÄãÍÚÑ½ÍÚ£¬ºöÈ»Ò»ÕóÒ«ÑÛµÄÀ¶¹âÕÕÒ«×ÅÄã£¡[1;31m
µ«Õâ¶´Ñ¨ÒòÎªÄãµÄ·­¶¯£¬¾Í¿ìÒªËúÁË£¡£¡[1;32m
Í»È»ÓĞÈË×¥×ÅÄãÒÂ·şµÄºóÁì£¬½«ÄãÌáÁËÆğÀ´£¡[0m\n",who);
  who->move("/open/badman/room/wolf17.c");
   return 1;
  }
  else
  {
  message_vision("[36mÄãÒªÍÚÄÄÀï£¿[0m\n",who);
  return 1;
  }
}
