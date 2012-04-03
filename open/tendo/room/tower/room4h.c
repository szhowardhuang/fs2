#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","ÁùÒÇÕóÕóÑÛ");
          set("long",@LONG
ÕâÀï¾ÍÊÇÎåĞĞ°ËØÔÕóÖĞµÄÁùÒÇÕóÁË£¬ÔÚ´Ë´¦Äã¿´µ½ÁËÒ»ÍÅÍÅ¹í»ğ
£¬ËÄÖÜÒõÉ­É­µÄ£¬ÉìÊÖ²»¼ûÎåÖ¸£¬Ô¶Ô¶µÄÍûÈ¥£¬Ö»¿´µ½¼¸´¦³ö¿Ú£¬Áî
ÄãÏëÁ¢¿Ì·É±¼¹ıÈ¥£¬Ö»¼ûÒ»ÕóÕóµÄÒõ·çÆËÃæ¶øÀ´£¬´ËÊ±²Å·¢¾õÓĞĞí¶à
ÑıÄ§ÏòÄãÕâ±¼À´¡£ÕâÀï¾ÍÊÇÁùÒÇÕóµÄÕóÑÛ£¬´ÓÕâÀï¾Í¿ÉÒÔÀë¿ªÁùÒÇÕó
ÁË¡£
LONG);
        set("exits", ([
	"north":__DIR__"room4",
	"south":__DIR__"room4d",
	"west":__DIR__"room4c",
	"east":__DIR__"room4d",
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
	"north":__DIR__"room4",
	"south":__DIR__"room4b",
	"east":__DIR__"room4b",
	"west":__DIR__"room4c",
	"out":__DIR__"tower5-1",
	]));
	return 1;
}


