// Room: /u/o/onion/room/hell.c

inherit ROOM;

void create()
{
	set("short", "µØÀÎ");
	set("long", @LONG
Ò»×ù°µÎŞÌìÈÕµÄµØÀÎ,Ö»ÓĞÒ»µãÎ¢ÈõµÄ¹âÏßÓÉÇ½½Ç·ìÉøÍ¸½øÀ´,ÃãÇ¿¿ÉÒÔ·Ö±æËÄÖÜµÄ
¾°Îï,Õû¸öÇ½±ÚÊÇÓÉ¼áÓ²µÄ»¨¸ÚÊ¯ËùÖş³É,Æ¾ÄãµÄ¹¦Á¦Á¬ÍÚµã»ÒÏÂÀ´¶¼²»¿ÉÄÜ,Ó²ÏëÆÆÇ½
¶ø³ö¸üÊÇÄÑÈçµÇÌì.Ïëµ½×Ô¼ºÒª±»À§ÔÚÕâ¶ù,²»ÄÜÈ¥ÍæMUD,¾Í¾õµÃÓû¿ŞÎŞÀá,¡«ÍÛ¡«....

LONG
	);
        set("item_desc", ([
	"corner" :
"ÄãÕö´óË«ÑÛ,×ĞÏ¸µÄÍù½ÇÂäÇÆ,¿ÉÊÇÊµÔÚÊÇÌ«°µÁË,Ê²Ã´¶¼¿´²»µ½ßÖ...\n",	
        "plate" : 
"ÉÏÍ·ËÆºõ¿Ì×ÅÒ»Ğ©¼×¹ÇÎÄ,Æ¾×ÅÄãÓÅÒìµÄ¹úÑ§ÖªÊ¶,Äã±æÊ¶³öÕâĞ©¾ä×ÓµÄÒâË¼ÊÇ :\n"+
"\n			[1;36mIloveOnion[0m\n\n"+
"ÒÉ..ÄÑµÀÕâ¾ÍÊÇÃÜÂë?\n"
	]));
	
	setup();
}

        void init()
        {
        	add_action("do_search","search");
                add_action("do_say","'");
                add_action("do_say","say");
        }
        
        int do_say(string str)
        {
        	if (str!="IloveOnion")
        	return 0;
        	else
        	{
        	write("¹§Ï²Äã!!Äã´ğ¶ÔÁËpassword,¿ÉÒÔ³öÈ¥ÁË.\n");
        	tell_room(environment(this_player()),
        	(string)this_player()->query("name")+
        	"ºöÈ»ÏûÊ§²»¼ûÁË,ÍÛ...Ã»´øÎÒ³öÈ¥...\n",
                ({this_object(),this_player()}));
                this_player()->move(__DIR__"room3");
                write("Åö¡«µÄÒ»Éù,ÄãÖÕÓÚµôµ½µØÉÏÁË,ÒÉ...Õâ²»ÊÇÔ­±¾µÄµØ·½Âğ?\n");
                tell_room(environment(this_player()),"Åö¡«µÄÒ»Éù,Äã¿´µ½"+
                (string)this_player()->query("name")+"²»ÖªµÀ´ÓÄÇµôÁËÏÂÀ´...\n",
                ({this_object(),this_player()}));
        	return 1;
        	}
        }	
        int do_search(string str)
        {
        	if (str!="corner")
        	{
        	write("ÄãÏĞ×ÅÎŞÁÄµ½´¦ÃşÒ»Ãş...\n"+
       		      "ÏÅ!!Ò»Ö»ËÀÃ¨´Ó½ÇÂä(corner)ÅÜ³öÀ´\n");
		return 1;
		}
		else
		{
		write(
"½ÇÂäÀïËÆºõÓĞÒ»¿éÊ¯°å(plate)°¼°¼Í¹Í¹µÄ,ºÍÆäËûÇ½±ÚÌØ±ğ²»Ò»Ñù,ÄÑµÀÕâÊÇ»ú¹Ø?\n");
		return 1;
		}
       	}         
