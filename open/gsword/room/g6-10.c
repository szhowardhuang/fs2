#include <room.h>

 inherit ROOM;
 void receive_hit();
 int done=0;
 void create()
{
        set("short", "ÏÉ½£ÅÉ½ûµØ");
        set("long", @LONG
ÑÛÇ°ÊÇÒ»¸öÙ¼´óµÄÉ½¶´£¬ÃÅ¿ÚÒÔ¾«¸ÖÕ¤À¸·â×¡£¬¶´ÄÚºÚÆİÆİµÄÒ»Æ¬£¬
ÍêÈ«²»ÄÜÌ½ÖªÀïÃæËµ²»³öµÄ¹îÒìÆø·Õ£¬Ê±ÓĞÌıµ½¶¯Îï²Ò½ĞµÄÉùÒô£¬Ê±¶øÎÅ
µ½Å¨ºñµÄÑªĞÈÎ¶µÀÁîÄã²»º®¶ø²ü¡£¶´¿ÚµÄ×ó²àÓĞ¸öÀ­¸Ë(level)¡£
 
LONG
        );

             
        set("item_desc",(["level":
 "Õâ¸öÀ­¸ËÒÑÉúĞâ¶àÄê£¬ËÆºõÊÇÓÃÀ´¿ªÆôÕ¤ÃÅÓÃµÄ£¬Äã¿ÉÒÔÊÔ×ÅÀ­(pull)¶¯Ëü¡£\n",
 ]));
                                        
       set("exits",([
                     "east":__DIR__"g6-9",
                     ]));
                    
           setup();
        }

void init()
{
add_action("pull_level","pull");
}

int pull_level(string str)
{
   if( done==1)
     return notify_fail("»ú¹ØÒÑ¾­Æô¶¯\n");
   if(str!="level")
     {
         return notify_fail("ÄãÒªÀ­Ê²Ã´??\n");
         }
     write(" ¿¦À²Ò»Éù¡«¡«¡«¡«¡«¡«\n
            Õ¤ÃÅ½¥½¥µÄÉıÆğ.\n");
     write("\n");
    done=1;
    receive_hit();
    return 1;
 }
 
 void receive_hit()
 {
 object ob;
 object hitter;
 write("Í»È»Ò»Î»ÀÏÕßĞ®ÕßÍò¾ùÖ®ÊÆ´ÓÌì¶ø½µ,ÊÖÖĞ³¤½£»Ã»¯³ÉÎŞÊı½£ÆøÏòÄã¶øÀ´\n");
 message_vision(sprintf("ÀÏÕßºÈµÀ:[1mÉÃ´³ÏÉ½£½ûµØÕß,ËÀ!!![0m\n"),this_player());
 ob=new("/open/gsword/npc/guard");
 hitter=this_player();
 ob->move(environment(this_player()));
 ob->invocation(this_object());
 ob->kill_ob(hitter);
 set("exits",([
     "east":__DIR__"g6-9",
    "north":__DIR__"g6-11"
    ]));
  }
int valid_leave(object me,string dir)
{
  if (dir=="north" && present ("oldman", environment(me)))
      return notify_fail ("ÀÏÕßµ²×ÅÄãËµµÀ: Ïë´³½ûµØ,ÏÈÎÊÎÊÎÒÊÖÉÏµÄÕâ°Ñ½£°É¡£\n");
        return ::valid_leave(me, dir);
}     
     
     
     
        
