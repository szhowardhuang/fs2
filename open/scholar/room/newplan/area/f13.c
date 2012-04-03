// Room: /u/s/sueplan/newplan/area/f13.c
inherit ROOM;

void create ()
{
  set ("short", "[1;33mÒ÷·ç¸óÄÚ[0m");
  set ("long", @LONG

ÑÛ¼ûÒ»°ÙËêÈËÈğ¶Ë×ùÓÚÇ°£¬´ËÈËÑÛÖĞåÄÈ»ÓĞÉñ£¬ÆøÊÆÒàÓĞ¾­ÈËÖ®¸Ğ
£¬·ÖºÁ²»¼ûÆä¼ûÓâ°ÙÖ®Ì¬£¬¸óÄÚ³ÂÉèÆÌÁĞ¼òµ¥£¬ÎŞË¿ÖñÖ®ÂÒ¶ú£¬ÎŞ°¸ë¹
Ö®ÀÍĞÎ¡£

LONG);

  set("light_up ",1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"f12",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/master_wone.c" : 1,
]));

  setup();
}
