///open/prayer/room/hole/20.c

#include <ansi.h>
inherit ROOM;
void create ()
{
  seteuid(getuid());    
  set ("short", "àòàô³Ø");
  set ("long", @LONG
        ÄãµÄÃæÇ°ÊÇÒ»×ùĞÈ³ôÎŞ±ÈµÄÑª³Ø£¬²¢ÇÒ´«À´ÕóÕóµÄĞ°Æø!!Ñª³ØÖĞ
        ÓĞÒ»Ö»Ò°ÊŞÔÚÄÇÀï·­¹ö£¬²»¹ı±ğÅÂ£¬ ­ÉíÉÏÓĞÊıÌõµÄÌúÁ´½ûïÀ×Å
         ­£¬Ò§²»µ½ÄãµÄ£¬Äã¿ÉÒÔÊÔ×Å·Å ­×ÔÓÉ(free)!!µ«ÊÇÖÁÓÚÄãµÄ°²
        È«ÎÊÌâ£¬¿É¾ÍÃ»ÓĞÈË±£Ö¤ÁË.....
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"18",
  "south" : __DIR__"19",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/kylin-statue" : 1,
]));

        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
  setup();
}
void init()
{
 add_action("free_kylin","free");
 add_action("search_here", "search");
}

int search_here(string str)
{
    if( (this_player()->query("combat_exp",1) > 100000)  )
    {
    write("Äã³¶ÁË³¶ÌúÁ´Ö®ºó.·¢ÏÖÌúÁ´ÊÇ¿ÉÒÔË³ÑØ¶øÏÂµÄ.¿ÉÊÇÑª÷è÷ëÔÚÏÂÃæÒ®!!\n");
      set("exits/down",__DIR__"21");
      call_out("do_close",10);
   }
    else
    {
    write("Ò²ĞíÊÇÄã¾­Ñé²»×ã,ÄãÊ²Ã´Ò²Ã»·¢ÏÖ...\n");
    }    
return 1;
}

void do_close()
{
        if(!query("exits/down"))
                return;
        delete("exits/down");
        tell_room(this_object(),"ÌúÁ´±»Ñª÷è÷ëÀ­³¶ºó½«ÕâÌõ³öÂ·¸²¸Ç\ÁË¡£\n");
}

int free_kylin(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("kylin",environment(ob)))
    return notify_fail("Ñª÷è÷ë¶¼±»·Å×ßÁË, ÄãÏëÒªÔõÑùÄØ??\n");
  if( str!="kylin")
    return notify_fail("ºğ~~~~~~~~~~!!!!\n");
  message_vision("[36mÄãÔË¾¢½« ­ÉíÉÏµÄÌúÁ´Õğ¶Ï...[0m",ob);
  write("\n\n\n");
     ob1=present("kylin",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  return 1;
}   

int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision("Ñª÷è÷ë¿ªÊ¼ÔÚÑª³ØÖĞ¾çÁÒµÄ·­½Á....\n",ob);
  call_out("msg2",3,ob);
  return 1;
}

int msg2(object ob)
{
  message("mud","[33mÑª÷è÷ë±»·Å³öÀ´ÁË........´ó¼ÒĞ¡ĞÄÑ½!![0m\n",users());
  call_out("msg3",3,ob);
  return 1;
}

int msg3(object ob)
{
  new("/open/prayer/npc/kylin")->move("/open/gsword/room/su3");

  call_out("msg4",3,ob);
  return 1;
 }
int msg4(object ob)
{
  message("mud","[36mÑª÷è÷ë´óºğÒ»Éù¡«¡«\n

     [5m[33m"+ ob->query("name")+"[0m[36mĞ¦µÀ£º\n\n


     ºÇºÇºÇºÇ....ÊÇÎÒ°Ñ ­·Å³öÀ´µÄ!!Íæ¼ÒÒªµ¹´óé¹ÁË\n\n"NOR,users());
  
  return 1;
}                      
