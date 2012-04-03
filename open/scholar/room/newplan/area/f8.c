// Room: /u/s/sueplan/newplan/area/f8.c
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÔÆÉ½ÏÂ[0m");
  set ("long", @LONG
ÐÐ×ßÖÁ´Ë£¬½¥¾õÉ½·çÁ¹ÒâÐìÀ´£¬Ò»ÕóÇåÐÄ¿ìÒâÏ®ÉÏÐÄ¼ä£¬²»¾õÂú»³Êæ³©
£¬Ì§Í·ÍûÈ¥£¬Ç°·½É½Í·ÔÆÆøçÔÈÆ£¬ëüëÊôèÈë²Ôñ·£¬²»±æºÎÎ½É½ÁëÌì¼Ê£¬ÓÌÈç
·ÉÑ©ÂþÂþÄý½á²»É¢£¬¹ÊÃûÎª¡®ÔÆÉ½¡¯£»Ñò³¦Ð¡Â·òêÑÑÄÏÈ¥£¬ÔÓ»¨ÉúÊ÷ÎÞÃûÓÄ
Ïãµ­µ­£¬Ê÷¼äÉ½Â·ÅÌÂÍ¶øÉý(climb up)¡£
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"f7",
]));

  setup();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string str)
{
object me;
me=this_player();
if(str=="up")
  {
  write("ÄãÒ»²½Ò»²½ÅÀÁËÉÏÈ¥!!\n");
  me->move(__DIR__"f9.c");
  return 1;
  }
}
