// by Onion
#include </open/open.h>
inherit ROOM;
string do_boxes();
void create ()
{
  set ("short", "¸ÉÍ¨ÌìÄÚÔº");
  set ("long", @LONG
×ß½øÕâ¶ù, ÊÇ¸ÉÍ¨Ìì×¡Õ¬µÄÄÚÔº, Ò»Æ¬Æ½Ì¹µÄµØ·½, ¶ø½ÇÂä»¹¶Ñ·Å
×Å¼¸¸ö´óÏä×Ó(boxes), ²»Öª·Å×ÅÊ²Ã´¶«Î÷, ÓÉÓÚÊÇÇ®Í¨ÌìµÄµØ·½, Ê¹
ÄãÓĞµãÏëËÑ²é(search)µÄºÃÆæĞÄ¡£

LONG);

  set("light_up", 1);
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"rich",
]));
	set("item_desc",([
	"boxes"	: "¼¸¸ö´óÏä×Ó, ÀïÍ·²»ÖªµÀ·ÅÁËÊ²Ã´¶«Î÷¡£\n",
	]));
	set("search_desc",([
	"boxes" : (: do_boxes :),
	]));
	set_temp("ÓĞ¹·",1);

  setup();
}

string do_boxes()
{
	if( query_temp("ÓĞ¹·") ){
		tell_room( this_object(),"[1;33m²»ÖªµÀ´ÓÄÄ¶ù³å³öÀ´Ò»Ö»Ğ×ÃÍµÄéáÈ®¡£[0m\n");
		new(CAPITAL_NPC"dog0")->move(this_object());
		delete_temp("ÓĞ¹·");
	}
	return "Õâ¼¸¸öÏä×Ó¶¼ÉÏÁËËø, ÄãÃ»°ì·¨´ò¿ª¡£\n";
}		

	