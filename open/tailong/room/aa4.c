// Room: /u/o/ookami/newarea/aa4 
inherit ROOM;
 
void create ()
{
  set ("short", "µã²ÔÉ½Ñü");
  set ("long", @LONG
µ±Äã×ßµ½ÕâÀï,Äã¿´µ½Ç°·½ÓĞÒ»¶°½ğ±Ì»Ô»ÍµÄ½¨ÖşÎï,ºÃÏñÊÇÒ»×ù·ğ
ËÂ,µ«ÊÇÔ¶Ô¶¿´È¥ÓÖºÃÏñÊÇÒ»×ù¹¬µî,ÁîÈËÌ¾Îª¹ÛÖ¹,×ĞÏ¸ÏëÏë,ÕâÓ¦¸Ã¾Í
ÊÇÓĞÃûµÄÌìÁúËÂÁË°É
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"aa3.c",
  "north" : __DIR__"aa5.c",
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
