// Room: /d/snow/weapon_storage.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m¹ıÈ¥Ê±¿Õ[0m ±øÆ÷´¢²ØÊÒ");
  set ("long", @LONG
ÕâÊÇÒ»¼ä¶ÑÂú¸÷Ê½±øÆ÷¡¢µ¶ĞµµÄ´¢²ØÊÒ£¬¸÷Ê½ÎäÆ÷¶¼ÒÀÕÕÖÖÀà¡¢³¤
¶Ì¡¢ÒÀ´Î·ÅÔÚÒ»Æğ£¬²¢ÇÒ²ÁÊÃµÃÒ»³¾²»È¾£¬´¢²ØÊÒµÄ³ö¿ÚÔÚÄãµÄÄÏ±ß£¬
Ãæ¶Ô³ö¿ÚµÄ×óÊÖ±ßÓĞÒ»¸ö¼Ü×Ó(shelf)¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "shelf" : "Õâ¸ö¼Ü×ÓÉÏ¿Õµ´µ´µÄ£¬Ê²Ã´Ò²Ã»ÓĞ©¤©¤Á¬»Ò³¾Ò²Ã»ÓĞ¡£
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"school2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/bamboo_sword" : 1,
]));

  setup();
}

void init()
{
	add_action("do_push", "push");
}

void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3
	&&	(int)query("right_trigger")==5
	&&	!query("exits/down") ) {
		message("vision", "µØ°åºöÈ»·¢³öÔşÔşµÄÉùÒô£¬Ò»¿éµØÃæ»º»ºÒÆ¶¯×Å£¬Â¶³öÒ»¸öÏòÏÂµÄ½×Ìİ¡£\n",
			this_object() );
		set("exits/down", __DIR__"secrect_storage");
		if( room = find_object(__DIR__"secrect_storage") ) {
			room->set("exits/up", __FILE__);
			message("vision", "Ìì»¨°åºöÈ»·¢³öÔşÔşµÄÉùÒô£¬Â¶³öÒ»¸öÏòÉÏµÄ½×Ìİ¡£\n",
				room );
		}
		delete("left_trigger");
		delete("right_trigger");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "µØ°åºöÈ»·¢³öÔşÔşµÄÉùÒô£¬Ò»¿éµØÃæ»º»ºÒÆ¶¯×Å£¬½«ÏòÏÂµÄÍ¨µÀ¸Ç\×¡ÁË¡£\n",
		this_object() );
	if( room = find_object(__DIR__"secrect_storage") ) {
		room->delete("exits/up");
		message("vision", "Ìì»¨°åºöÈ»·¢³öÔşÔşµÄÉùÒô£¬ÏòÉÏµÄ½×ÌİÓÖ»º»ºµØÊÕÁË»ØÈ¥¡£\n",
			room );
	}
	delete("exits/down");
}


int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="shelf" ) {
		write("ÄãÊÔ×ÅÍÆ¶¯Õâ¸ö¼Ü×Ó£¬ËÆºõ¿ÉÒÔ×óÓÒ»¬¶¯....\n");
		return 1;
	}
	if( sscanf(arg, "shelf %s", dir)==1 ) {
		if( dir=="right" ) {
			message_vision("$N½«¼Ü×ÓÍùÓÒÍÆ...£¬ºöÈ»¡¸¿¦¡±Ò»Éù¼Ü×ÓÓÖÒÆ»ØÔ­Î»¡£\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N½«¼Ü×ÓÍù×óÍÆ...£¬ºöÈ»¡¸¿¦¡±Ò»Éù¼Ü×ÓÓÖÒÆ»ØÔ­Î»¡£\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("ÄãÒª½«¼Ü×ÓÍÆÏòÄÇ¸ö·½Ïò£¿\n");
			return 1;
		}
	}
}


void reset()
{
	::reset();
	delete("left_trigger");
	delete("right_trigger");
}
