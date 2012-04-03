// Room: /open/capital/room/SCH.c

inherit ROOM;

void create ()
{
  set ("short", "ÊéÉú¹«»á");
  set ("long", @LONG
ÕâÀïÊÇÊéÉúÃÇÆ½³£¾Û¼¯µÄµØ·½£¬ËûÃÇ¶¼ÔÚÕâ¶ùÌÖÂÛÌìÏÂ´óÊÂ£¬³©Ëù
ÓûÑÔ¡£Ç½±ÚÉÏ¹Ò×ÅÒ»¸±Ê«Áª(poet)£¬¶øÔÚÇ°ÌÃÉÏ×ø×ÅÒ»Î»ÀÏÏÈÉú£¬Ô­À´
ÊÇÌìÏÂÊéÉú¶¼ºÜÅå·şµÄÑîÊéÎÄ--ÑîÉĞÊé£¬ËûÕı÷××ÅËûµÄ´óºú×Ó¿´×ÅÌÃÖĞ
µÄÒ»ÇĞ¡£

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "poet" : "	©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´
	©¦		          ©¦
	©¦  [1mÌ¸ ÎÄ ÂÛ Îä µÀ Ğş »ú[0m  ©¦
	©¦  [1m´º ÏÄ Çï ¶¬ Ò» É« ÒÂ[0m  ©¦
	©¦  [1måÛ ÓÎ ½­ ºş Ç§ Íò Àï[0m  ©¦
	©¦  [1mÉí ²Ø Ìì µØ Á½ ¾í Êé[0m  ©¦
	©¦		          ©¦
	©¦		[1;36m¾©³ÇÑî´ó[0m  ©¦
	©¦		  [1;36m×íºó¿ñ²İ[0m©¦
	©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"SCH1",
  "east" : __DIR__"h01",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/scholar/master" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="south" )
	{
	if( me->query("class") != "scholar" )
	  return notify_fail("·ÇÊéÉú²»µÃ½øÈë!\n");
	if( !me->query_temp("½øÈëÊé·¿") )
	  return notify_fail("Î´µÃÑîÊéÎÄÍ¬Òâ(agree), ²»µÃ½øÈë!\n");
	}
	return ::valid_leave(me, dir);
}
