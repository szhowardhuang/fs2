inherit ROOM;

void create()
{
  set("short", "ÕÊÅñ");
  set("long", "ÕâÊÇÒ»¸öµäĞÍµÄÓÎÄÁÃñ×åµÄÕÊÅñ¡£µ«ÄÚ²¿µÄ°Ú\ÉèÈ´Ïàµ±µØ
ºº»¯¡£ÅîÄÚµÄ½ÇÂäÓĞÒ»¸öÏàµ±´óµÄÄ¾°å´²£¬ÀÏ¶ùËùËµµÄÓ¦¸Ã¾Í
ÊÇÕâ´²ÁË°É£¿
");

  set("exits", ([ /* sizeof() == 4 */
  "out" : "/open/main/room/d5.c",
]) );

  set("light_up",1);

setup();
}

void init()
{
 add_action("do_search","search");
 add_action("do_open","open");
}

int do_search(object me)
{
  object who;
  who = this_player();
  message_vision("[1;37m$NÔÚÄ¾°æ´²ÉÏ×ĞÏ¸µØ²ì¿´ÁËÒ»·¬£¬·¢ÏÖ´²ÖĞÑëÆ«×óµÄµØ
·½ÓĞ¸ö°¼²Û£¬¿´Ñù×Ó¿ÉÒÔÓÃÊÖ½«Æä´ò¿ª£¨open£©¡£[0m\n",who);
  who->set_temp("marks/open",1);
  return 1;
}

int do_open()
{
  object who;
  who = this_player();
  if (who->query_temp("marks/open",1))
  {
   message_vision("[1;37m$N°ÑÊÖÉìÈë´²ÉÏµÄ°¼²ÛÄÚ£¬ÓÃÁ¦Ò»À­£¬
Ò»ÌõÍ¨µÀµÄÈë¿Ú±ãÔÚÑÛÇ°¡£[0m\n",who);
   set("exits/enter",__DIR__"d_c01.c");
   set_temp("have_open",1);
   remove_call_out("do_closed");
   call_out("do_closed",60);
   return 1;
  }
}

void do_closed()
{

        delete_temp("have_open");
        delete("exits/enter");
        tell_room(this_object(),"[1;37m°µµÀµÄÈë¿Ú±»·çÉ°´µµÃ×÷Ïì£¬¸ÕÏÆÆğÀ´µÄÄ¾°åÔÙ¶È±»ãØÉÏ£¡[0m\n");
}
