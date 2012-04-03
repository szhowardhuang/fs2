#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","ÎåĞĞÕóÕóÑÛ");
          set("long",@LONG

ÄãÒÑÂõÈëÁËÎåĞĞ°ËØÔÕóÖĞµÄÎåĞĞÕó£¬ÔÚ´Ë´¦Äã¿´µ½ÁËÂúµØµÄ¿İ¹Ç£¬
ËÄÖÜºÁÎŞ¹âÏß£¬ÉìÊÖ²»¼ûÎåÖ¸£¬Ô¶Ô¶µÄÍûÈ¥£¬Ö»¿´µ½Ò»µãÁÁ¹â£¬ÁîÄãÏë
Á¢¿Ì·É±¼¹ıÈ¥£¬Ö»¼ûÒ»ÕóÕóµÄÒõ·çÆËÃæ¶øÀ´£¬´ËÊ±²Å·¢¾õÓĞĞí¶àµÄÑı÷È
ÏòÄãÕâ·É±¼¹ıÀ´¡£ÕâÀï¾ÍÊÇÎåĞĞÕóµÄÕóÑÛ£¬´ÓÕâÀï¾Í¿ÉÒÔÀë¿ªÎåĞĞÕóÁË
¡£
LONG);
        set("exits", ([
	"north":__DIR__"room3",
	"south":__DIR__"room3b",
	"west":__DIR__"room3c",
	"east":__DIR__"room3b",
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
	"north":__DIR__"room3",
	"south":__DIR__"room3b",
	"east":__DIR__"room3b",
	"west":__DIR__"room3c",
	"out":__DIR__"tower4-1",
	]));
	return 1;
}


