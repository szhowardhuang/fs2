// Room: /open/gsword/room/wghouse.c
inherit ROOM;

void create ()
{
    set ("short", "ÏÉ½£¡õ²Ø½£ÊÒ");
  set ("long", @LONG
ÕâÀïÊÇÏÉ½£Ê¦ÐÖµÜÃÇÎªÁËÔì¸£¸ÕloginÃ»EQµÄÍæ¼ÒËùÌØ±ð¿ª±ÙµÄ·¿¼ä ,
¿´×ÅµØÉÏ¶ÑÂúµÄEQ ,Äã²»½û³ÏÐÄ¸ÐÐ»ÖÚÊ¦ÐÖµÜµÄÈÈÐÄ.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" :"/open/gsword/room/g5-1.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  set("no_clean_up",1);
set("no_fight",1);
  setup();
  call_other("/obj/board/swordsman_b2","????");
}

void init()
{
//  add_action("do_sword","gift");
  add_action("do_pass","pass");
  add_action("do_verify","verify");
}

int do_pass()
{
   object me=this_player();
   me->move("/open/ping/room/road3");
   return 1;
} 

int do_verify(string arg)
{
 object me,ob;
 me=this_player();
 ob=new("/data/autoload/swordsman/sun_sword_book");
 if( arg!="sun_sword_book")
{
    write("ÄãÒªÉêÇëÊ²Ã´\n");
    return 1;
   }
if(me->query("quest/sun_fire_sword",1)!=1)
  {
    write("ÄãÄÃÁËÕâ¶«Î÷Ò²Ã»ÓÃ\n");
    return 1;
  }

 if( present(ob,me) )
  {
    write("ÄãÒÑ¾­ÓÐÒ»±¾ÁË\n");
    return 1;
   }
   else
    {
     write("ºÃºÃ±£¹Ü´ËÊé, ±ðÔÙÅª¶ªÁË.\n");
     ob->move(me);
     return 1;
    }
}
/*
int do_sword(string arg)
{
 object me,ob;
 me=this_player();
 ob=new("/data/autoload/swordsman/sunsword-gift");
 if( arg!="sword")
{
    write("ÄãÒªÉêÇëÊ²Ã´\n");
    return 1;
   }
if(me->query("id",)!=("rocken"))
  {
    write("ÏëÄÃÀñÎï...ÃÅ¶¼Ã»ÓÐ\n");
    return 1;
  }

 if(me->query("get_appogift1")==1)
  {
    write("ÄãÒÑ¾­ÄÃµ½ÀñÎïÁË...»¹ÒªÊ²Ã´?\n");
    return 1;
   }
   else
    {
    write("[1;37mË²¼ä~Ò»µÀÆßÉ«²Êºç»¯¹ýÄãÑÛÇ°,Ë²¼äÄã¾õµÃÊÖÉÏ¶àÁËÒ»Ñù¶«Î÷[0m\n");
   me->set("get_appogift1",1);
     ob->move(me);
     return 1;
    }
}
*/
