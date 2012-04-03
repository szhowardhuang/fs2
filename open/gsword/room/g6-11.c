
// Room: /open/gsword/room/g6-11
inherit ROOM;
void create ()
{
  seteuid(getuid());	// ²»ÊÇËµÒª¼ÓÕâÒ»ĞĞÂğ?
  set ("short", "É½¶´");
  set ("long", @LONG
Õâ¸ö¶´Ñ¨ÆÄ´ó£¬Íù¶«ÍùÎ÷Íù±±¶¼ÓĞÒ»¸ö½ÏĞ¡µÄÊ¯Ñ¨£¬¶´ÄÚÃÖÂş×ÅÒ»ÖÖ
Ëµ²»³öµÄ¹îÒìÆø·Õ£¬Ê±ÓĞÌıµ½¶¯Îï²Ò½ĞµÄÉùÒô£¬Ê±¶øÎÅµ½Å¨ºñµÄÑªĞÈÎ¶µÀ
ÁîÄã²»º®¶ø²ü¡£
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"g6-10",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/obj/gstatue1.c" : 1,
]));
  
  setup();
}

void init()
{
 add_action("cut_hand","cut");
 add_action("do_enter","blood");
}
 
int cut_hand(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("statue",environment(ob)))
    return notify_fail("Äã¸îÕâÃ´¶à´Î¸ÉÂï ,Ê§Ñª¹ı¶à²»ºÃÅ¶.\n");
  if( str!="hand")
    return notify_fail("½ĞÄã¸îÊÖÀ² ,ÄãÔÚ¸îÄÄ°¡!!\n");
  message_vision("[1;31mÒ»ÖùÏÊÑª×Ô$NÊÖÍóÅç³ö ,ÍùµñÏñ¼¤Éä¶øÈ¥.....      \n [0m",ob);
  write("\n\n\n");
     ob1=present("statue",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  return 1;
}   

int do_enter(string str)
{
   object me = this_player();
  if(me->query("bloodsword")==1)
   me->move("/open/gsword/room1/blood/room3/r5.c");
   return 1;
}
int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision("Ö»¼ûµñÏñÊÖÖ¸Î¢¶¯ ,Á³É«½¥×ªºìÔÎ\n",ob);
  call_out("msg2",3,ob);
  return 1;
}

int msg2(object ob)
{
  object ob1;

  message_vision("Í»È»ÀÏ×æÑÛ¾¦Ò»ÕÅ ,Ò»×ùµñÏñ¾¹¶û¸´»îÁË ,ÏÅµÄ$NÁ¬ÍËÈı²½..\n",ob);  
  message_vision("ÀÏ×æµÀ: Ğ¡×ÓĞ»Ğ»ÄãÀ².....\n",ob);
  message_vision("ÀÏ×æÒ»¸ö¼ı²½³åµ½¶´¿Ú ,×ÙÉíÒ»Ô¾ ,ÉíÓ°ÏûÊ§ÔÚÉ½¹ÈÖĞ\n",ob);
  ob1=new("/open/gsword/mob/bigghost");
  ob1->move("/open/gsword/room/test");
  message("mud","[1;34mÒ»Õó¿ªÉ½ÁÑµØµÄĞ¦Éù×ÔÊñÉ½ÖĞ´«³ö..\n\n\n[0m",users());
  message("mud","[1;32mÂÌÃ«ÀÏ×æºğµÀ: \n
      ¹ş ¹ş ¹ş......´Àµ°[33;1m"+ ob->query("name")+"[0m\n
   [1;32mÊ¹µÄÀÏ×ÓÎÒÖÕÓÚµÃÒÔÖØÏÖ½­ºş \n
          ÏÉ½£ÅÉµÄ¹êËï×ÓÃÇ ,Ä¨¸É¾»ÄãÃÇµÄ²±×Ó ,¾²´ıËÀÉñµÄÀ´ÁÙ°É ,\n
              ÎÒÒª  Ñª  Ï´  ÏÉ  ½£  !!!!\n [0m",users());
  call_out("msg3",3,ob);
  return 1;
}

int msg3(object ob)
{
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road8");
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road6");
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road1");
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road4");
 new("/open/gsword/mob/bloody")->move("/open/gsword/room/road6");
 new("/open/gsword/mob/bloody")->move("/open/gsword/room/road4");
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road4"); 
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road1");
 new("/open/gsword/mob/ghost1")->move("/open/gsword/room/road1");
 new("/open/gsword/mob/ghost1")->move("/open/gsword/room/rroad1");
 new("/open/gsword/mob/ghost1")->move("/open/gsword/room/lroad1");
 message("mud","[1;34mÀÏ×æÒÑ¾­¸´»îÁË ,\n
     Ğ¡¹íÃÇ ,ÔÛÃÇÉ±ÉÏÏÉ½£ÌæÀÏ×æÏ´³¾..\n[0m",users()); 
  call_out("msg4",3,ob);
  return 1;
 }
int msg4(object ob)
{
  message("mud","[1;33mÖ£Ê¿ĞÀÌ¾µÀ:\n

     °¦...ÕæÊÇÒ»³¡Ô©Äõ...
           ÖÚ×ÓµÜÃÇ ,ÈÃÎÒÃÇÆëĞÄ»¯½âÕâ³¡°ÙÄêÇ°ËùÖØÏÂµÄÒò¹û..\n[0m",users());
  
  return 1;
}                      
