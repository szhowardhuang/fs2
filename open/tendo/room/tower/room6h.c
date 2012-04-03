#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","°ËØÔÕóÕóÑÛ");
          set("long",@LONG
ÕâÀï¾ÍÊÇÎåĞĞ°ËØÔÕóµÄ°ËØÔÕóÁË£¬ÔÚ´Ë´¦Äã¿´µ½ÁËÂúµØµÄÎäÆ÷£¬
ËÄÖÜÆáºÚÈçÒ¹£¬ÉìÊÖ²»¼ûÎåÖ¸£¬Ô¶Ô¶ÍûÈ¥£¬Ò»µÀ¹âÏßÓ­Ãæ¶øÀ´£¬ÁîÄã
ÏëÁ¢¿Ì·É±¼¹ıÈ¥£¬Ö»¼ûÒ»ÕóÕóµÄÒõ·çÆËÃæ¶øÀ´£¬´ËÊ±²Å·¢¾õÓĞĞí¶à¹í
Ó°ÏòÄãÕâ±¼À´¡£ÕâÀï¾ÍÊÇ°ËØÔÕóµÄÕóÑÛ£¬´ÓÕâÀï¾Í¿ÉÒÔÀë¿ª°ËØÔÕóÁË
¡£
LONG);
        set("exits", ([
	"north":__DIR__"room6",
	"south":__DIR__"room6b",
	"west":__DIR__"room6c",
	"east":__DIR__"room6b",
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
	"north":__DIR__"room6",
	"south":__DIR__"room6b",
	"east":__DIR__"room6b",
	"west":__DIR__"room6c",
	"out":__DIR__"tower7-1",
	]));
	return 1;
}


