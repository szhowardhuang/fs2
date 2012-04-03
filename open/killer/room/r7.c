#include <room.h>
inherit ROOM;
void create ()
{
   set ("short","Ë®µ×");
   set ("long", @LONG
ÕâÊÇµØÏÂË®µÀµÄµ×²¿,Èý·½¶¼ÊÇºÚ°µÎÞ¹â
Ö»ÓÐÉÏÃæÓÐÎ¢ÈõµÄ¹âÏß(light)ÕÕÉäÏÂÀ´
 

ÄãÊÖÉÏ±§×ÅÒ»¿Å´óÊ¯Í·(stone)¡£
LONG);
set("item_desc",([
  "light" : "Äã¾¡Á¦µØÏë¿´Çå³þ¹âÏßÊÇ´ÓÄÇ¶ùÕÕÉäÏÂÀ´,µ«ÊÇÌ«°µÁË,¿´²»Çå³þ,Òª¹ýÈ¥µÄ»°,Çë(pass) ¡£\n",
  "stone" : "¾ÍÊÇÕâÒ»¿ÅÊ¯Í·¾ÈÁËÄãµÄÃü,Òª·Å¿ªÇë(swim)¡£\n",]));
  set("no_fight",1);
 set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  setup();
}
void init()
{
   add_action("do_swim",({"swim"}) );
   add_action("do_pass",({"pass"}) );
}
int do_swim(string arg)
{
   object me;
   if (!arg || arg=="" )  {
   me = this_player();
  tell_object(me,"Ö»ÌýÄã¨Ú¡«¡«¨Ú¡«¡«µÄ½ÐÉùÉùÏìÆð,ÄãµÄÊÖ·Å¿ªÁË´óÊ¯,ÔÙÒ»´ÎµØ±»
Ë®Á÷´ø×ß ¡£\n");
  tell_object(me,"[33;1m×îºóÄãÖÕÓÚ±»Ë®Á÷¸øÅ×³öµØÃæ ¡£[0m\n");

  me->move("/open/ping/room/road8");
 return 1;
 }
return 1;
}
int do_pass(string arg)
{
  object who;
  who=this_player();
  if((arg="light") || (arg=="light")) {
tell_object(who,"[1mÄã³ÔÁ¦µÄÍù¹âÏß´¦ÓÎÈ¥,ÅÀ¹ýÐ¡¶´,À´µ½ÁË²»ÖªÃûµÄµØ·½¡£[0m\n");
  who->move("/open/killer/room/rb.c");
 return 1;
  }
   return 0;
}





