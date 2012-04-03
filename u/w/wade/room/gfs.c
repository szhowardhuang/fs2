// Room: /u/w/wade/grapic_room.c
inherit ROOM;

void create ()
{
  set ("short", "[1;32mÍ¼ĞÎ»¯MUDÌÖÂÛÊÒ[0m");
  set ("long", @LONG
ÕâÊÇÒ»¼äÓÃÀ´ÈÃ·¢Õ¹Í¼ĞÎMUDµÄĞ¡×éÓÃÀ´ÌÖÂÛ¡¢ÑĞ¾¿¡¢½»»»ĞÄµÃµÄ·¿¼ä
[1;32mĞ¡×éÕÙ¼¯ÈË¼°Ö÷µ¼:Wade[0m
[1;32mServer×é:Wade¡¢Chan¡¢Fir[0m
[1;32mClient×é:Lum¡¢Sieg¡¢Acelan[0m
Ï£ÍûÄÜÒ»²½Ò»²½µÄÑĞ·¢¡¢ÔçÈÕ½«FSÍê³ÉÍ¼ĞÎ»¯¡£
LONG);

  set("exits", ([ /* sizeof() == 7 */
  "lum" : "/u/l/lum/workroom.c",
  "acelan" : "/u/a/acelan/workroom.c",
  "anmy" : "/u/a/anmy/workroom.c",
  "fir" : "/u/f/fir/workroom.c",
  "sieg" : "/u/s/sieg/workroom.c",
  "wade" : __DIR__"workroom.c",
  "chan" : "/u/c/chan/workroom.c",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
call_other("/obj/board/gfs_b.c","???");
}


