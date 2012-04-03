// Room: /u/s/sueplan/newplan/area/qroom2
inherit ROOM;

void create ()
{
  set ("short", "[1;37m°ËØÔÕó[0m");
  set ("long", @LONG
                    ¡ö¡ö¡ö¡ö¡ö¡ö

                        ¡ö¡ö¡ö¡ö¡ö¡ö

                        ¡ö¡ö¡ö¡ö¡ö¡ö

                        ¸É£¨Ìì£©

ÖªÏ¤Ì«¼«ÉúÁ½ÒÇ£¬Á½ÒÇÉúËÄÏó£¬ËÄÏóÉú°ËØÔ£¬°Ë°ËÁùÊ®ËÄ»¯£¬
´ËÄËÖÐ¹úÒ×¾­Ö®ÃîËùÔÚ£¬Öî¸ð¿×Ã÷ÒÔ´Ë¶øÁ¢°ËØÔÕó£¬ÕóÄÚ±ä
»¯ÍòÇ§£¬Ò×Ê¹ÈËÃÔÊ§ÓÚ²»×Ô¾õ¼ä¡£
ÄãÃæÇ°¾íÆð²»ÉÙµÄ·çÉ³, ÇëÑ¡³ö(move)ÄãÒª×ßµÄ·½Ïò
[1;37m·½ÏòÓÐ-Ðþ, Ôª, Á·, Ö§, Á·Ðþ, Á·Ôª, Ö§Ðþ, Ö§Ôª¡£[0m
LONG);

  set("no_auc", 1);
  set("no_transmit", 1);
  set("evil", 1);

  setup();
}
void init()
{
add_action("do_move","move");
}
int do_move(string str)
{
  object me=this_player();
  if(str=="Ðþ")
  {
    me->move(__DIR__"qt2.c");
    return 1;
  }
  if(str=="Ôª")
  {
    me->move(__DIR__"qt3.c");
    return 1;
  }
  if(str=="Á·")
  {
    me->move(__DIR__"qt4.c");
    return 1;
  }
  if(str=="Ö§")
  {
    me->move(__DIR__"qt5.c");
    return 1;
  }
  if(str=="Á·Ðþ")
  {
    me->move(__DIR__"qt6.c");
    return 1;
  }
  if(str=="Á·Ôª")
  {
    me->move(__DIR__"qt7.c");
    return 1;
  }
  if(str=="Ö§Ðþ")
  {
    me->move(__DIR__"qt8.c");
    return 1;
  }
  if(str=="Ö§Ôª")
  {
    me->move(__DIR__"q1.c");
    return 1;
  }
}
