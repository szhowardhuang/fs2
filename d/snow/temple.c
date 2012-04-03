#include <obj.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ³ÇÚòÃí");
  set ("long", @LONG
ÕâÊÇÒ»¼äÊ®·ÖÀÏ¾ÉµÄ³ÇÚòÃí£¬ÔÚÄãÃæÇ°µÄÉñ×ÀÉÏ¹©·î×ÅÒ»×ğºìÁ³µÄ³Ç
Úò£¬ÃíËäÀÏ¾É£¬µ«ÊÇÉñ°¸ËÄÖÜÒÑ±»Ïã»ğŞ¹³ÉÎÚºÚµÄÑÕÉ«£¬ÏÔÊ¾ÕâÀï±Ø¶¨Ïà
µ±ÊÜµ½ĞÅÍ½µÄ¾´Ñö¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"square",
  "south" : __DIR__"eroad1",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/obj/paper_seal" : 2,
]));
  set("no_fight", "1");

  setup();
}
