// Room: /u/s/sueplan/newplan/area/jroom.c
inherit ROOM;

void create ()
{
  set ("short", "[1;37mÆæÕó°ËØÔ[1;33m-ÕóĞÄ[0m");
  set ("long", @LONG
  
ÄãÀ´µ½°ËØÔÕóµÄÖĞĞÄ£¬¿´µ½ÑÛÇ°ÓĞÒ»¸ö¿´ËÆÃ¼Ä¿ºÍÉÆµÄÈË£¬
²»¹ıÄãÏ¸Ï¸Ò»¿´£¬ËûÈ´ÓÖ³äÂúÉ±Æø£¬¿´ÆğÀ´ËÄºõ¶Ô
Äã²¢²»ÊÇÓĞ·Ç³£´óµÄºÃ¸Ğ¡£Äã¿´µ½ËûÉíÉÏµÄ´©×Å
¶¨¾¦Ò»¿´²Å·¢ÏÖËûÉíÉÏ¾¹ÓĞÁùèºÆæÂÔÒ»Êé£¬ÄãÕâÊ±
²Å·¢ÏÖ£¬Ô­À´ÑÛÇ°µÄÕâ¸öÈË¾¹ÊÇÓĞÌìÏÂµÚÒ»¾üÊ¦Ö®³ÆµÄ
Öî¸ğ¼ÒºóÒá£¬Öî¸ğÒØÕÑ!!
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/juka_jone" : 1,  
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 2 */
  "leave" : __DIR__"q1.c",
  "south" : __DIR__"room11.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
if(dir=="leave"&&present("juka jone",environment(me)))
  {
return notify_fail("Äã·¢¾õÓĞÈËµ²ÔÚÄãÃæ, ²»ÈÃÄã¹ı!!!\n");
   }
  return 1;
}
