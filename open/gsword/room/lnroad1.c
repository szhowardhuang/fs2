#include <room.h>

 inherit ROOM;
void receive_hit();
 void create()
{
        set("short", "ÏÉ½£ÅÉ½ûµØ");
        set("long", @LONG
ÕâÊÇÏÉ½£ÅÉµÄ½ûµØ,µ«ÊÇ·ÅÑÛÍûÈ¥,Õâ¶ù¸úÒ»°ãµÄÑÒÊ¯Æ½Ì¨Ã»É¶Á½Ñù,
¾°ÎïÒ²ÊÇÏ¡ÊèÆ½·²µÃºÜ,µ½µ×ÎªÊ²Ã´Õâ¶ù±»ÏÉ½£ÅÉÁĞÎª½ûµØ,ÑÏ½ûµÜ
×Ó¼°·Ã¿Í½Ó½ü,¾ÍÕæÒªËµÕâÓĞÌØÒìÖ®´¦µÄ»°,´ó¸ÅÒ²Ö»ÊÇÔÚ×ó±ßÓĞÒ»
¿ÃÉÏ°ÙÄê·ÇÒªÊ®ÈË²ÅÄÜÎ§±§¾ŞÄ¾(Gaint tree)°É!!


LONG
        );

        
        set("item_desc",(["Gaint tree":
 "ÕâÊÇÒ»¿Ã°ÙÓàÄêµÄ¹ÅÊ÷,ÌÙÂû²¼ÂúÁËÕû¸öÊ÷Éí,·­¿ªÌÙÂûÒ»¿´,Ò»¸öÕÆÓ¡(hand_print)Ç¶Èë
 Ê÷Éí,¶¨ÊÇ¸ßÈËËùÎª,ÉñÍùÖ®Óà,ÄãºÃÏëÒ²¶Ô×ÅÕÆÓ¡À´ÉÏÒ»ÕÆ(hit hand_print)»ÃÏëÄãÊÇÒÔÇ°
 µÄÄÇÎ»¸ßÈË.\n",
 "hand_print" :
 "Õâ¸öÕÆÓ¡×ã×ãÓĞÎå´ç¿íÈı´çºñ,¼òÖ±ÁîÈË·ËÒÄËùË¼\n"
 ]));
                                        
       set("exits",([
                     "south": "/u/b/bigcat/room/rroad4.c"
                     ]));
                    
                    
           setup();
        }

void init()
{
add_action("hit_hand_print","hit");
}

int hit_hand_print(string str)
{
   if(str!="hand_print")
     {
         return 0;
         }
     write(" ¿¦À²Ò»Éù¡«¡«¡«¡«¡«¡«,Äã±¾ÄÜĞÔµÄ½ôÎÕÎäÆ÷,·À±¸Í»ÈçÆæÀ´¹¥»÷\n
           ¡«¡«¡«¡«¡«\n");
     write("\n");
    receive_hit();
    return 1;
 }
 
 void receive_hit()
 {
 object ob;
 object hitter;
 write("Í»È»Ò»Î»ÀÏÕßĞ®ÕßÍò¾ùÖ®ÊÆ´ÓÌì¶ø½µ,ÊÖÖĞ³¤½£»Ã»¯³ÉÎŞÊı½£ÆøÏòÄã¶øÀ´\n");
 message_vision(sprintf("ÀÏÕßºÈµÀ:[1mÉÃ´³ÏÉ½£½ûµØÕß,ËÀ!!![0m\n"),this_player());
 ob=new("/u/b/bigcat/mob/guard");
 hitter=this_player();
 ob->move(environment(this_player()));
 ob->invocation(this_object());
 ob->kill_ob(hitter);
 set("exits",([
"enter": "/u/b/bigcat/room/tree",
"south": "/u/b/bigcat/room/rroad4"
   ]));
  }
int valid_leave(object me,string dir)
{
  if (dir=="enter" && present ("oldman", environment(me)))
      return notify_fail ("ÀÏÕßµ²×ÅÄãËµµÀ: Ïë´³½ûµØ,ÏÈÎÊÎÊÎÒÊÖÉÏµÄÕâ°Ñ½£°É¡£\n");
        return ::valid_leave(me, dir);
}     
