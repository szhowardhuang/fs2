inherit ITEM;
#define VOID		"/obj/void"
#define QUEST_ROOM	"/open/main/room/s16"
void create()

{
      set_name("ÅÚÕÌ",({"firecracker"}) );
      set_weight(8000);
      if( clonep() )
           set_default_object(__FILE__);
      else {
           set("unit","¸ö");
           set("long","ÕâÊÇ¶Î¼ÒÁªÂçÓÃµÄÅÚÕÌ, Äã¿ÉÒÔÈ¼·Å(fire)Ëü¡£");
           set("value",0);
           }
      setup();
}

void init()
{
	add_action("do_fire","fire");
}

int do_fire(string str)
{
	object me=this_player();
	object place=environment(me);
	if( !place->query("outdoors") )
	  write("ÔÚÎÝ×ÓÀïÄãÏë·Å»ð°¡¡£\n");
	else
	{
	if( str != "firecracker" )
	  write("ÄãÒªÉÕÊ²Ã´¶«¶«°¡? \n");
	else
	{
	  this_object()->move(VOID);
	  message_vision("$N´Ó»³ÀïÌÍ³öÒ»¸öÅÚÕÌ, È»ºóË§ÆøµÄ½«Ëü·¢Éä³öÈ¥¡£\n",me);
	  if(me->query_temp("thief") >= 7)
	  {
	    tell_room(environment(me),"[1;36mÅÚÕÌ³ÊÏÖÓÅÃÀµÄ»¡¶ÈÔÚÌì¿ÕÕ¨ÁË¿ªÀ´...\n"+
"								  \n"+
"	   [5;31m*[5;35m*	[5;33m*		[0m[1;34m* [1;35m * 				  \n"+
"             [1;36m*  [1;5;31m¡ï   [5;32m*           [0m[1;33m¡ï  	[5;35m*		  [0m[1;35m**      \n"+
"                   [1;31m*         [1;35m¡î [5;35m*                        [0m[1;33m*   [5;33m¡ï  \n"+
"                      [5;32m*   *   [0m[1;32m¡ï         [5;35m*        [5;33m*    [0m[1;33m¡î [5;36m*      \n"+
"		[5;36m*		[0m[1;36m*  [5;31m*		    [5;36m* 	    [1;31m**    \n"+
"			[5;31m**			[5;32m**[0m		  \n"+
"                            					  \n");
	    call_out("result",4);
	  }
	  else
	  { 
	    tell_room(environment(me),"[36m¿ÉÄÜÊÇ¼¼Êõ²»ºÃµÄ¹ØÏµ, ÅÚÕÌÍáÍáÐ±Ð±µÄÂäÁËÏÂÀ´¡£[0m\n");
	    destruct(this_object());
	  }  
	}
	}
	return 1;
}
void result()
{
	object me=this_player();
	if( environment(me)->query("capital_thief") == 0 )
	{  
	  write("[36m¿ÉÊÇËÄÖÜÎ§¶¼Ã»Ê²Ã´¶¯¾², ¿ÉÄÜÊÇÒòÎªÕâ¶ù²»ÊÇ¾©³ÇÀïµØÊÆ×î¸ßµÄµØ·½¡£[0m\n"); 
	  destruct(this_object());
	}  
	else
	{
	  write("[36mÄãËÆºõÆ²¼û½ÇÂäÓÐºÚÓ°Ò»ÉÁ¡£\n»ú²»¿ÉÊ§, ÄãÂíÉÏ×·ÁË¹ýÈ¥¡£[0m\n");
	  tell_room(environment(me),me->query("name")+"Í»È»¼±¼±Ã¦Ã¦µÄÀë¿ªÁË¡£\n",me);
	  call_out("follow1",3);
	  me->set_temp("block_msg/all", 1);
	  me->move(VOID);
	}
}
void follow1()
{
	object me=this_player();
	me->set_temp("block_msg/all", 0);
	write("[1;33m(ÎÒ×·ÎÒ×·ÎÒ×·×·×·....)[0m\n");
	call_out("follow2",3);
	me->set_temp("block_msg/all", 1);
}
void follow2()
{
	object me=this_player();
	me->set_temp("block_msg/all", 0);
	write("[1;33m(Åû¾£Õ¶¼¬ÎÒ×·×·×·....)[0m\n");
	call_out("follow3",3);
	me->set_temp("block_msg/all", 1);
}
void follow3()
{
	object me=this_player();
	me->set_temp("block_msg/all", 0);
	write("[1;33m(·­É½Ô½ÁëÎÒ×·×·×·....)[0m\n");
	call_out("follow4",3);
	me->set_temp("block_msg/all", 1);
}
void follow4()
{
	object me=this_player();
	me->set_temp("block_msg/all", 0);
	write("[36mÖ»¼ûºÚÓ°ÔÚ²Ý´Ô(bush)¼äÒ»´Ü, ËÆºõÊ§È¥ÁË×ÙÓ°[0m\n");
	me->set_temp("thief",8);
	me->move(QUEST_ROOM);
	destruct(this_object());
}	