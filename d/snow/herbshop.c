// Room: /d/snow/herbshop.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ýÈ¥Ê±¿Õ[0m É£ÁÚÒ©ÆÌ");
  set ("long", @LONG
ÕâÀïÊÇÒ»¼ä¹æÄ£²»Ð¡µÄÒ©ÆÌ£¬Ææ¹ÖµÄÊÇ£¬ÔÚÕâÀïÄãÎÅ²»µ½Ò»Ë¿Ò©ÆÌ
Ó¦ÓÐµÄÒ©Î¶£¬ÓÐµÄÖ»ÊÇÒ»¹Éµ­µ­µÄÌ´Ïã£¬ÁîÈË¾õµÃÐÄ¿õÉñâù£¬Ò©ÆÌµÄ¹ñ
Ì¨¾ÍÔÚµêÆÌ¿¿±±µÄÒ»Ãæ£¬¹ñÌ¨ºóÊÇÒ»¸ö¾Þ´óµÄÒ©¹ñ(cabinet)£¬ ÉÏÃæµÄ
Ð¡³éÌëÖ»ÅÂÓÐÆß¡¢°Ë°Ù¸öÖ®¶à£¬µ«ÊÇÈ«²¿Ã»ÓÐÌù±êÇ©£¬Ò©ÆÌµÄ³ö¿ÚÔÚ¶«
±ß¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"mstreet3",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "cabinet" : "Ò»×ù¾Þ´óµÄÉ¼Ä¾Ò©¹ñ£¬´ÓËü°µºìÉ«µÄÎÆÀí¸ú¼¸´¦Ä¥µÃ·¢ÁÁµÄºÛ¼££¬
Õâ¸öÒ©¹ñÄê´úÏë±ØÏàµ±¾ÃÔ¶ÁË£¬ÓÐÒ»µãºÜÌØÊâµÄÊÇ£¬Ò©¹ñºÍÇ½±ÚËÆºõÌù
µÃ·Ç³£½ôÃÜ£¬¿´²»³öË¿ºÁ·ìÏ¶¡£
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/herbalist" : 1,
  __DIR__"npc/woodcutter" : 1,
]));

  setup();
}
