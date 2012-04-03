#include <room.h>

inherit ROOM;

void create()
{
        set("short", "Ê¥»ðÃÜÊÒ");
	set( "build", 150 );
        set("long", @LONG

	Õâ¶ùÊÇÊ¥»ð½ÌÄÚ²¿µÄÃÜÊÒ, Õâ¼äÃÜÊÒÓ¦¸ÃÊÇÖ±½ÓÔÚÊ¯±ÚÉÏ
	ÍÚ¾ò½¨ÔìµÄ!!ÖÐ¼äÓÐÒ»×ùÑÒÌ¨, ÉÏÃæ°ÚÓÐÒ»×ù¶¦(bottle)
	, ¶¦ÄÚ·¢³ö²ÓÀÃ¶áÄ¿µÄ¹â»ª!!

LONG);

set("item_desc",([
"bottle": "  [36mÒ»×ùÉúÌúÖý³ÉµÄÊ¨Í·¶¦ [0m "
]));
        set("exits", ([
            "east":__DIR__"2elder1"
        ]) );
setup();
}

void init()
{
 add_action("do_search","search");
 add_action("do_pull","pull");
}
 
int do_search(string str)
{
   object user;
   user=this_player();
   if( !user->query("quests/white-crystal",1))
   {
       write("Õâ×ù¶¦¿´À´²¢Ã»ÓÐÊ²Ã´Ææ¹ÖµÄµØ·½!!\n");
       return 1;
   }    

   if(str=="bottle")
   {
       write(" [36mÄãÔÙ×ÐÏ¸ÍÆÇÃÒ»·¬, ·¢ÏÖÊ¨¶ú(ear)µÄ²¿·ÖËÆºõÓÐµã¹Å¹Ö[0m....\n");
       user->set_temp("have_search_bottle",1);
   }
   else if(str=="ear")
   {
       if(!user->query_temp("have_search_bottle",1))     
       write("Å¶!!Ô­À´ÊÇÄê¾ÃÊÜ³±, ÉúÁËÐâÁË!!\n");
       else
       {
           write("Ê¨¶ú±»ÄãÒ»ÅöÖ®ºó, ¶¦ÄÚµÄ¹â»ª½¥¼õ, Äã¿ÉÒÔÇå³þµØ¿´¼û¶¦ÄÚµÄÊÂÎï : 
     
           ¶¦ÄÚÓÐÁù¸ö¶´, ÆäÖÐÒ»¸ö¶´ÊÇ¿ÕµÄ, ÆäÓàÔò·Ö±ðÊÇ...
     
      [30mºÚË®¾§[0m(black-crystal)--»ëÌìÐÄ·¨µÚÁù²ãÐÄ·¨Ö®¿Ú¾÷
      [34mÀ¶Ë®¾§[0m(blue-crystal)---»ëÌìÐÄ·¨µÚÆß²ãÐÄ·¨Ö®¿Ú¾÷
      [33m»ÆË®¾§[0m(yellow-crystal)-»ëÌìÐÄ·¨µÚ°Ë²ãÐÄ·¨Ö®¿Ú¾÷
      [31mºìË®¾§[0m(red-crystal)----»ëÌìÐÄ·¨µÚ¾Å²ãÐÄ·¨Ö®¿Ú¾÷
      [32mÂÌË®¾§[0m(green-crystal)--»ëÌìÐÄ·¨µÚÊ®²ãÐÄ·¨Ö®¿Ú¾÷

      Ô­À´ÕâÀï¾ÍÊÇ»ëÌìË®¾§µÄ·ÅÖÃ´¦!!Äã¿ÉÒÔ³¢ÊÔ×Å°ÎÆðËüÃÇ(pull)..\n");
      user->set_temp("can_pull",1);
       }   
   }
   else
       write("ÄãÔÚÕÒÊ²Ã´??\n");
    
  return 1;   
}      

int do_pull(string str)
{
 object user=this_player();
 object cry;

 if( (str=="black-crystal") && user->query("quests/white-crystal",1) )
 {
   if( user->query_skill("superforce",1) < 50 )
   {
   write("\n[35mÍ»È»Ë«ÊÖ¸Ðµ½Ò»ÕóµçÊÉ...............ÍÛ!!!!ºÚË®¾§·¢³ö¾çÁÒµÄÇ¿¹â....[0m\n\n");
   return 0;
   }
   else
   {
   write("ÓÉÓÚÄãÒÑ¾­Á·ÓÐ»ù±¾ÐÄ·¨, [30mºÚË®¾§[0m±»ÄãÔË¾¢Ò»°Î, Ó¦Éù¶øÆð!!\n",user);        
   cry=new("/open/prayer/obj/crystal2" );
   cry->move(user);
   return 1;
   }
}

 if(str=="blue-crystal") 
 {
   if( user->query_skill("superforce",1) < 85)
   {
   write("\n[35mÍ»È»Ë«ÊÖ¸Ðµ½Ò»ÕóµçÊÉ...............ÍÛ!!!!À¶Ë®¾§·¢³ö¾çÁÒµÄÇ¿¹â....[0m\n¿´À´ÄãµÄ»ëÌìÐÄ·¨µÈ¼¶»¹²»¹».\n");
   return 0;
   }
   else
   {
   write("ÓÉÓÚÄãÒÑ¾­Á·³ÉµÚÁù²ãÐÄ·¨, [34mÀ¶Ë®¾§[0m±»ÄãÔË¾¢Ò»°Î, Ó¦Éù¶øÆð!!\n",user);        
   cry=new("/open/prayer/obj/crystal3" );
   cry->move(user);
   return 1;
   }
}     

 if(str=="yellow-crystal")
 {
   if( user->query_skill("superforce",1) < 120)
   {
   write("\n[35mÍ»È»Ë«ÊÖ¸Ðµ½Ò»ÕóµçÊÉ...............ÍÛ!!!!»ÆË®¾§·¢³ö¾çÁÒµÄÇ¿¹â....[0m\n¿´À´ÄãµÄ»ëÌìÐÄ·¨µÈ¼¶»¹²»¹».\n");
   return 0;
   }
   else
   {
   write("ÓÉÓÚÄãÒÑ¾­Á·³ÉµÚÆß²ãÐÄ·¨, [33m»ÆË®¾§[0m±»ÄãÔË¾¢Ò»°Î, Ó¦Éù¶øÆð!!\n",user);        
   cry=new("/open/prayer/obj/crystal4" );
   cry->move(user);
   return 1;   
   }
}

 if(str=="red-crystal")
 {
   if( user->query_skill("superforce",1) < 160)
   {
   write("\n[35mÍ»È»Ë«ÊÖ¸Ðµ½Ò»ÕóµçÊÉ...............ÍÛ!!!!ºìË®¾§·¢³ö¾çÁÒµÄÇ¿¹â....[0m\n¿´À´ÄãµÄ»ëÌìÐÄ·¨µÈ¼¶»¹²»¹».\n");
   return 0;
   }
   else
   {
   write("ÓÉÓÚÄãÒÑ¾­Á·³ÉµÚ°Ë²ãÐÄ·¨, [31mºìË®¾§[0m±»ÄãÔË¾¢Ò»°Î, Ó¦Éù¶øÆð!!\n",user);        
   cry=new("/open/prayer/obj/crystal5" );
   cry->move(user);
   return 1;
   }
}

 if(str=="green-crystal")
 {
   if( user->query_skill("superforce",1) <200)
   {
   write("\n[35mÍ»È»Ë«ÊÖ¸Ðµ½Ò»ÕóµçÊÉ...............ÍÛ!!!!ÂÌË®¾§·¢³ö¾çÁÒµÄÇ¿¹â....[0m\n¿´À´ÄãµÄ»ëÌìÐÄ·¨µÈ¼¶»¹²»¹».\n");
   return 0;
   }
   else
   {
   write("ÓÉÓÚÄãÒÑ¾­Á·³ÉµÚ¾Å²ãÐÄ·¨, [32mÂÌË®¾§[0m±»ÄãÔË¾¢Ò»°Î, Ó¦Éù¶øÆð!!\n",user);        
   cry=new("/open/prayer/obj/crystal6" );
   cry->move(user);
   return 1;
   }
 }
}  
