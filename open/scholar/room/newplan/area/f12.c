// Room: /u/s/sueplan/newplan/area/f12.c
inherit ROOM;

void create ()
{
  set ("short", "[1;33mÒ÷·ç¸ó[0m");
  set ("long", @LONG
·çÐìÐì´µÀ´£¬½«ÁýÕÖ×ÅµÄ±¡Îí´µÉ¢£¬¶¨ÑÛÒ»¿´£¬ÒÑÀ´µ½ÁËÒ÷·ç¸óÃÅÇ°
£»¿´ÕâÕ¬µÚ²ÔËÉ»·±§ÄÑ±æ´óÐ¡£¬Ò»É«µÄ°×Ç½»ÒÍßÏàµ±ËØÑÅ£¬ÃÅ¿ÚÁ½Ö»Ê¯Ê¨
×ÓÕÅ×ìÎ¢Ð¦×Å£¬ËÆºõÒ²°²ÓÚÕâÒþÊÀ¶ÀÁ¢°ãµÄÇéµ÷£»Ò»×ßµ½ÁËÃÅ¿Ú£¬Ò»Î»Ñ¾
÷ßÕýÐ¦Ò÷Ò÷µØµ²×¡ÁËÄãµÄÈ¥Â·£¬¿´À´Äã¿ÉµÃÒÀ×Å¹æ¾ØËÍÉÏÃûÌû²ÅÐÐ¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"f13.c",
  "west" : __DIR__"f11",
]));
  set("outdoors", "/u/s");

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="enter")
  {
    if(me->query_mark("sixgod-plan") && me->query_temp("six_ask")<4)
    return notify_fail("ÕâÀïÄãÊÇ½ø²»È¥µÄ!!\n");
  }
  return 1;
}
