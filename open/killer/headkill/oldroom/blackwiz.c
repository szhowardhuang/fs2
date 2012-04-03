#include <room.h>

inherit ROOM;

 
void create()

{
  
	set("short", "Íæ¼ÒÒé¼û·¢±íÊÒ");
  
	set("long", @LONG
  
		¸÷Î»...×î½ü±¾ÅÉ·Ç·Ç·Ç·Ç·Ç³£Ö®ÀäÇå,
		Òò´ËÏ£ÍûÍæ¼ÒÄÜ¹»¶à¶à½¨ÒéÒ»Ð©
Ò²»¶Ó­ÔÝÊ±¹àË®Òà¿É....
                       
		Íæ¼Ò¿É¿ªÊ¼ÔÚ´ËÁôÑÔÁË....no idea.






¿´µ½µ±ÄêµÄÐðÊö£¬²»ÖªµÀÄãµÄÏë·¨ÊÇÊ²Ã´£¿
ÕâÀïÊÇÉ±ÊÖÒÔÇ°µÄ½»ÒêÊÒ£¬µ«Ò²¼¸ºõÃ»ÓÐÈËÀ´¡£
»òÐíÊÇÉ±ÊÖÊµÔÚÌ«ÈõÁË°É£¿
ËäÈ»Äãµ½Ä¿Ç°»¹²»ÖªµÀÄãÎªºÎ»áÔÚÕâÀï£¬µ«ÊÇÄã»¹ÊÇµ½´¦È¥¿´¿´°É£¿
LONG);
        
	set("exits", ([ /* sizeof() == 1 */
	
		"south":__DIR__"r3",
	
///         "west":__DIR__"r0.c",
  
	]));
       
	setup();
        


//	call_other("/obj/board/killerwiz_b","???");

}

/*
int valid_leave(object me, string dir)

{
  
	if (me->query("class")!="killer" && dir=="west")
 
		return notify_fail("ÕâÊÇÉ±ÊÖµÄ½ûµØ!ÓÉÓÚÄãÃ»Á·[1m°ÔÓêó§»ê[0m,				¹ÊÄãÎÞ·¨½øÈë!\n");


	return ::valid_leave(me,dir);

}


void init()

{
  
	add_action("do_pass","pass");

}


int do_pass()

{
  
	object me;
  
	me = this_player();
  
	me->move("/open/center/room/inn");
  
	return 1;

}

*/
