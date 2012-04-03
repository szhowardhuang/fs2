// Room: /u/d/dhk/questsfan/rm5
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "É½ÁÖ[1;31mâH[0mÂ·");
  set ("long", @LONG
ÕâÒ»»á¶ù£¬ÄãÓÖ¿´µ½Ò»Ö»½ğ±³»ğÔ³Õı°ÑÍæ×ÅÒ»¿ìÁÁ¾§¾§
µÄÊ¯Í·£¬ÄãĞ¡ĞÄÒíÒíÓÖ¶ã¶ã²Ø²ØµÄÓû×ßµÄ¸ü½øÈ¥¹Û²ì£¬ÉúÒ»
²»Ğ¡ĞÄ³ÉÁË»ğÔ³µÄµãĞÄ¡­hmm¡£ ÓÖÄã×ĞÏ¸Ò»ÇÆ£¬ÍÛ£¡²»µÃÁË
 ­°ÑÍæµÄ¾¹ÊÇÔøÔÚ¹ÅÊéµä¼®¼ÇÔØµÄÆæÊ¯£¢âHÊ¯¡åÑ½£¡Õâ´ÎÕæ
ÊÇ´ó¿ªÑÛ½çÁË¡£

LONG);

  set("outdoors", "/u/d");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tod.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"rm4",
  "westup" : __DIR__"rm6",
]));

  setup();
}
