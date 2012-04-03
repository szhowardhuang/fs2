inherit ROOM;

void create ()
{
  seteuid(getuid());
  set ("short", "ÑªÄ§µî");
  set ("long", @LONG
´ËµØËæ´¦¿É¼û±éµØ¶ÏÇ½²Ğ±Ú....ÊµÔÚºÜÄÑÏëÏñÊÇµ±³õºä¶¯Ò»Ê±µÄÌìÄ§×ªÊÀÌå
ÑªÄ§µÄ¹¬µî£¬Ö»¼ûÕâÀï³ıÁËÒ»µÀµÀµÄµÄ·ûÖäÖ®Íâ...ÔÚ½ÇÂäÄã¿É¿´µ½Ò»Ì¯ÆæĞÎ¹Ö×´
µÄÑª×Õ(blood).....ËÆºõÓĞ×ÅÒ»Ğ©ÃØÃÜ....
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "blood" : " Ò»Ì²ÆæĞÎ¹Ö×´µÄÑª×Õ",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/gsword/room1/blood/room3/r3.c",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "blood" : "Äã×ĞÏ¸¿´ÁËÕâÌ²Ñª×Õ£¬ºÕÈ»·¢ÏÖÑª×Õ¾¹È»±»Ò»µÀµ½·ûÖä(taoistfigure)ÎªÔÚÖĞÑë²¢ÔÚ·ûÖäÖĞ´À´ÀÓû¶¯..ËÆºõÔÚ½ÏÄãËº¿ª(tear)Ëü¡£\n",

]));
  setup();
}
void init()
{
 add_action("do_tear","tear");
}
int do_tear(string str)
{
  object ob,ob1;
  ob=this_player();
  if( str!="taoistfigure")
    return notify_fail("Ëº·ûÖäÀ²....ÄãÌì±øÅ·...!!\n");
  if(ob->query_temp("blood1")!=1)
    return notify_fail("³Ô´ó±ãÈ¥...Ã»¿ª·âÓ¡Ò²Ïë½â...!!\n");
  if(ob->query_temp("killtiger")!=1 && ob->query_temp("killdragon")!=1)
    return notify_fail("Ã»ÍêÈ«½âÃÔÒ²ÏëÀ´·ÅÑªÄ§...ÄãÕÒËÀ¨Ú...!!!\n");
message_vision("[1;36mÄãÒ»ÕÅÒ»ÕÅµÄËº¿ªÌùÔÚÑª×ÕÉÏ·½µÄ·ûÖä[0m...\n ",ob);
    ob->set("swordplus",1);
  ob->set("bloodsword",1);
  ob->delete_temp("killtiger");
  ob->delete_temp("killdragon");
  ob->delete_temp("blood1");
log_file("sword/broken",sprintf("%s(%s) ½â·ÅÑªÄ§ on %s\n",ob->query("name"),ob->query("id"),ctime(time()) ));


  call_out("msg1",3,ob);
  return 1;

}

int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision("[1;31mÑª×Õ½¥½¥²úÉúÑª¹â...²¢Ò»²½Ò»²½µÄ×é³ÉÈËĞÎ[0m..\n",ob);
  call_out("msg2",3,ob);
  return 1;
}

int msg2(object ob)
{
  object ob1;

  message_vision("[32mÍ»È»...Ò»µÀµÀÎŞÓëÂ×±ÈµÄÄ§ÆøÓÉËÄÃæ°Ë·½ÉäÈëÏ÷ÈËÖĞ...ÏÅµÃ$NÕ¾²»Ö±[0m..\n",ob);

  message_vision("[1;35mÑªÄ§µÀ: Ğ¡¹í....ÊµÔÚÊÇÌ«¸ĞĞ»ÄãÁË.ÎÒ×ÜËã³ö·âÓ¡ÁË[0m.\n",ob);
  message_vision("[1;31mµ½ÂÌÃ«ÀÏ×æµÄÊ¯µñÏñÄÇÀ´ÕÒÎÒ°É..(blood)ÎÒÔİÊ±»áÔÚÄÇ..[0m\n",ob);
  message_vision("[1;31mÖ»¾õÒ»µÀÑª¹â»®¹ıÑÛÇ°....ÑªÄ§ÒÑ¾­ÏûÊ§ÎŞ×ÙÁË[0m...\n",ob);
   this_player()->move ("/open/gsword/room/g6-5.c");
   this_player()->set("title","[1;33mÏÉ½£½£ÏÀ--(°µ²ØÄ§Æø)--[0m");
  message("mud","[1;37mÒ»ÕóÕó¿ªÌì±ÙµØµÄĞ¦Éù×ÔÊñÉ½ÆæÕóÖĞ´«³ö[0m..\n\n\n",users());

  message("mud","[1;31mÑªÄ§[1;37m¿ñ½ĞµÀ: \n
      ¹ş ¹ş ¹ş......·âÓ¡¶àÄê...×ÜËãÓĞÈËÀ´°ÑÎÒ·Å³öÈ¥À²~~~ÕæÊÇºÃÑùµÄ
      åĞÒ£×Ó¡¢·çÇàÔÆÄãÃÇ¸ø¿´×Å°É...ÎÒ»áÕÒÄãÃÇ±¨³ğµÄ    
[1;31m          ÎÒ  µÄ  ×Ó  µÜ  ÃÇ  ½«  Ñª  Ï´  Îä  ÁÖ  [0m\n ",users());
  call_out("msg3",3,ob);
return 1;

}

int msg3(object ob)
{
  message("mud","[1;35mÖ£Ê¿ĞÀÌ¾µÀ:\n

     Ìì~~~Ê¦×æÓëÊ¦ÊåµÄ·âÓ¡±»ÆÆ....°¦~~Ïë²»µ½ÏÉ½£¾¹È»ÓĞÅÑÍ½

           ÌìÓÓÏÉ½£.¾ÍÇëÊ¦×æÃÇÔÙ´ÎÏÔÁéÁË[0m....\n",users());

  return 1;
}
