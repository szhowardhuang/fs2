// Room: /d/snow/hockshop2.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ýÈ¥Ê±¿Õ[0m ´¢²ØÊÒ");
  set ("long", @LONG
ÕâÀïÊÇ·áµÇµ±ÆÌµÄ´¢²ØÊÒ£¬ÓÐÊ±ºòµ±ÆÌÀïµÄ´ó³¯·î»á°ÑÆÌÀï´æ²»ÏÂ
µÄËÀµ±»õÎïÄÃ³öÀ´ÅÄÂô£¬²»¹ýÄãÏÖÔÚÖ»ÄÜ¿´¼ûÒ»¸ö¸öËø×ÅµÄÏä×Ó¡£ÍùÎ÷
±ß´©¹ýÒ»µÀ²¼Á±¿ÉÒÔ»Øµ½µ±ÆÌµêÃæ¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hockshop",
]));

  setup();
}
