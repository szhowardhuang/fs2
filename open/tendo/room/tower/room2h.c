#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","ËÄÏóÕóÕóÑÛ");
          set("long",@LONG

ÄãÒÑ¾­×ßÈëÎåĞĞ°ËØÔÕóµÄËÄÏóÕóÖĞ£¬Ö»¼ûËÄÖÜ¶¼ÊÇÑÒÊ¯£¬ÒÔ¼°Ò»
Ğ©À§ËÀÔÚ´ËµÄÈËµÄº¡¹Ç£¬ÔÚ´ËÄãÒÑÎŞ·¨±æÃ÷·½Ïò¡£¸¯ÀÃµÄ¶ñ³ô¸üÊÇÁî
ÄãÎŞ·¨ÈÌÊÜ¡£ÔÙ¼ÓÉÏµØÃæÉÏ¶¼ÊÇÀÃÄà£¬¸üÊÇÄÑ×ß£¬½ÅÉÏÆß¸ß°ËµÍ£¬Íû
³öÀ´ºÚÆáÒ»ÍÅ£¬ÁîÈË¾õµÃÒ»ÒõÉ­¿Ö²À¡£ÕâÀï¾ÍÊÇËÄÏóÕóµÄÕóÑÛ£¬´ÓÕâ
Àï¾Í¿ÉÒÔÀë¿ªËÄÏóÕóÁË¡£\n");
LONG);
        set("exits", ([
	"north":__DIR__"room2",
	"south":__DIR__"room2b",
	"west":__DIR__"room2c",
	"east":__DIR__"room2b",
        ]) );
	set("objects",([
]));
        set("no_transmit",1);
          setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search(string str)
{
	if(str!="eye") return 0;
	message_vision(
	"[1;37m$N´ÓÕâÀïÕÒÁËÕÒ£¬Í»È»´¥ÅöÁËÑÒÊ¯£¬Ê¹ÕóÑÛ´òÁË¿ªÀ´¡£[0m\n",this_player());
	set("exits",([
	"north":__DIR__"room2",
	"south":__DIR__"room2b",
	"east":__DIR__"room2b",
	"west":__DIR__"room2c",
	"out":__DIR__"tower2-1",
	]));
	return 1;
}


