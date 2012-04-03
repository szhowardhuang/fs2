// Room: /u/o/onion/workroom.c~
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "Ñó´ĞµÄĞ¡ÎÑ");
	set("long", @LONG
	
	Ò»¸öĞ¡Ğ¡µÄ·¿¼ä,ËæÒâµÄ¶Ñ×ÅÒ»Ğ©¶«Î÷,Äã×î¸Ğµ½ĞËÈ¤µÄÊÇ·¿¼ä½ÇÂä·Å×Å
	Ò»ÕÅ´ó×À×Ó,ÉÏÃæ°Ú×Å¸÷Ê½¸÷ÑùµÄÊé(book),ÁíÍâÄã»¹ÎÅµ½ÁËÒ»ÕóÕóµÄÏã
	Î¶´Ó´°±ß´«À´,×ĞÏ¸Ò»¿´È´ºÕÈ»·¢ÏÖÒ»Åè[1m¡¾ÌìÉ½Ñ©´Ğ¡¿[0m(onions),°×É«µÄ
	»¨°ê´«À´ÆË±ÇµÄÏãÎ¶..
	
LONG
	);

	set ("item_desc", 
	(["book" : "
	Äã¿´µ½ÕâĞ©ºñºñµÄÊé°üÀ¨ÁËµç×ÓÑ§,¹¤Êı,Ïß¿Ø..µÈÃÜÃÜÂéÂéµÄÔ­ÎÄÊé,²»
	½ûÓÉÖÔµÄÅå·şÆğ[Onion]À´ÁË...\n",
          "onions" : "
        ÉñÃØµÄÖÁ±¦,´«ÎÅÖĞµÄÏÉÎï--[1m¡¾ÌìÉ½Ñ©´Ğ¡¿[0m,¾¹È»ÔÚÕâ³öÏÖÁË,Í¸Ìå°×ÈçÓñ
        ÓĞÈçÑ©°ã,ÒòÎ¢·ç»¹ÇáÇáµÄ²ü¶¶×Å,Çåµ­µÄÏãÎ¶Ê¹ÄãÈÌ²»×¡ÏëÒªºÃºÃµÄÆ·Ğá
        (sniff)Ò»·¬...\n"]));
      
        set("objects", ([
        "/u/o/onion/npc/noname": 1,
//      "/u/o/onion/npc/vendor": 1,
	 ]));	
        set("exits", ([ 
		"up" : "/open/ping/room/p1",
		"down" : __DIR__"fightroom",
		"north" : "/open/capital/room/SCH",
        	"west" : "/open/biau/room0",
		"south" : "/open/capital/room/D03",

        	"east" : "/open/wiz/hall1",
         ]));
        set("no_clean_up", 0);
        set("valid_startroom", 1);
                             
        setup();
                  }                                    
                                                              	 
	void init()
	{
	 add_action("do_sniff","sniff");
	}
	int do_sniff(string str)
	{
                object me = this_player();
                int max;
                
                    write("Äã×ßÉÏÇ°È¥, ÓÃÁ¦µÄÎüÁËÒ»´ó¿ÚÆø,ÍÛ...¿ÚÆøÇåĞÂ... \n"
                    +"ÎüÈëµÄÏãÆøÔÚÄãÉíÌåµÄÆæ¾­°ËÂöÖ®ÄÚ´Ü¶¯,Äã¸Ğµ½Ò»ÇĞ×´¿ö¶¼¸´Ô­ÁË...\n");
		    me->reincarnate();
		    max = me->query("max_s_kee");
		    me->set("s_kee",max);		
                    max = me->query("max_gin");
                    me->set("eff_gin",max);
                    me->set("gin",max);
                    max = me->query("max_kee");
                    me->set("eff_kee",max);
                    me->set("kee",max);
                    max = me->query("max_sen");
                    me->set("eff_sen",max);
                    me->set("sen",max);
		    max = me->query("max_force");
		    me->set("force",max);
		    max = me->query("max_mana");
		    me->set("mana",max);	
                    max = me->max_food_capacity();
                    me->set("food",max);
                    max = me->max_water_capacity();
                    me->set("water",max);
                    me->clear_condition();
                     
                    tell_room(environment(me),(string)me->query("name")+
                    "×ß½ü[1m¡¾ÌìÉ½Ñ©´Ğ¡¿[0m,ÎÅÁËÒ»ÎÅ,Á³ÉÏÂ¶³öĞÒ¸£µÄĞ¦Èİ.\n",({this_object(), me}));
                    return 1;
        }
