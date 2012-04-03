// Room: /u/s/sueplan/newplan/area/qroom1
inherit ROOM;

void create ()
{
  set ("short", "[1;37m¡ì[1;32m°ËØÔÕó[1;37m¡ì[0m");
  set ("long", @LONG
                      ¸É £¨Ìì£©
                 ¶Ò     ________     Ùã
                  ¨u¡õ  ________    ¨v
          £¨Ôó£©¨u ¨u   ________   ¨v   £¨·ç£©
              ¨u ¨u ¨u            ¨v ¨v ¨v
               ¨u                   ¨v ¨v
                ¨u                    ¨v

       Àë  ©¦©¦©¦                      ©¦©¦©¦  ¿²
           ©¦  ©¦                        ©¦
     £¨»ğ£©©¦©¦©¦                      ©¦©¦©¦£¨Ë®£©

                ¨v                    ¨u
               ¨v                      ¨u
              ¨v  ¡õ¨v  ___  ___  ¨u    ¨u
            ôŞ  ¨v ¨v   ___  ___   ¨u     Õğ
                  ¨v    ___  ___    ¨u
              £¨É½£©                £¨À×£©
                        ½ìµØ£©

°ËØÔÕó©¤©¤´Ó¹Å´úÖĞ¹úÖ®Ò×¾­ÖĞËùÑİ±ä¶øÀ´£»¸É¡¢Ùã¡¢¿²¡¢ôŞ¡¢À¤¡¢Õğ¡¢
Àë¡¢¶Ò£¬¼´ÎªÆä°Ë¸öØÔÏó£»ÄãÒ»Ì¤Èë´ËÕóÖ®ºó£¬ÄÚĞÄÆğÁËÒ»¸öÒÉÎÊ£¿½ÌÖ÷
ÎªºÎ»áÉè°ËØÔÕóÓÚ´Ë£¿´ËÊ±Ç¿ÁÒµÄºÃÆæĞÄÇıÊ¹×ÅÄã£¬ÈÃÄã²»ÓÉ×ÔÖ÷µÄÏë´³
Ò»´³´ËÕó£¬´Ë°ËØÔÕòÄÚ°üº¬ÁË¸÷ÏîÎ£»ú£¬Çë°®Ï§ÉúÃü¡£
LONG);

  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/man.c" : 1,
]));
  set("evil", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"f17.c",
]));
  set("no_auc", 1);

  setup();
}
void init()
{
add_action("do_search","search");
add_action("do_go","go");
}
int do_go(string str)
{
  object me;
  me=this_player();
  if(str=="ÕóÄÚ")
  {
    if(me->query_temp("six_ask")==10)
    {
    write("ÄãÉîÉîµÄÎüÁËÒ»¿ÚÆø, ½øÈëÁË°ËØÔÕóÄÚ!!\n");
    me->move(__DIR__"q2.c");
    return 1;
    }
  else
  {
  write("Äã»¹²»ÖªµÀÊ²Ã´ÊÇ°ËØÔÕó°É??\n");
  }
  }
}
int do_search()
{
  object me=this_player();
  if( me->query("family/family_name") =="ÈåÃÅ")
  {
  write("Äã·¢ÏÖÓĞÌõÂ·¿ÉÒÔ½øÈë´ËÕó(go ÕóÄÚ)¡£\n");
  }
  else
  {
  write("ÄãÕÒ²»³ö¸öËùÒÔÈ»³öÀ´\n");
  }
return 1;
}
