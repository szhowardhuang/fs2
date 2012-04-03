// Room: /d/snow/sroad2.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m Ñ©Í¤Õò½ÖµÀ");
  set ("long", @LONG
ÕâÀïÊÇÑ©Í¤ÕòµÄ½ÖµÀ£¬ÄãµÄ±±±ßÓĞÒ»¼Ò¿ÍÕ»£¬´ÓÕâÀï¾Í¿ÉÒÔÌıµ½¿Í
Õ»ÀïÈËÃÇÒû¾ÆÌ¸Ğ¦µÄÉùÒô£¬½ÖµÀÍù¶«²»Ô¶´¦ÓĞ¸ö×ª½ÇÍù±±£¬Èç¹ûÄãÍù¶«
Ö±×ß¾ÍÊÇÉÏÉ½µÄĞ¡¾¶ÁË£¬ÍùÎ÷Ôò¿ÉÒÔ×ßµ½³µÂíÀ´ÍùÂçÒï²»¾øµÄ¹ÙµÀ¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/snow/npc/farmer" : 2,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"school",
  "west" : __DIR__"sroad3",
  "east" : __DIR__"sroad1",
]));

  setup();
}
