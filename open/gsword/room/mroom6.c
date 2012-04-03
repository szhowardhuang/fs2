// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
  set ("short", "ÊñÉ½ÆæÕó");
  set ("long", @LONG
    ·ç,ÔÚ´ËÍ£ÁË,¿ÕÆøÀï´ø×ÅÒ»Ë¿º®ÒâµÄ¼Å¾²,Ò»²ãµ­µ­µÄÎíËæµØËÄÉ¢,
Ò»Öê¹ÅËÉ(pine)°ÎµØ¶øÆğ,Ó­Ïò²ÔÀ¶µÄÌì¿Õ,ÄãÌıµ½ÓĞÈËÔÚÔ¶·½Ò÷Ê«,
    Ê«Ô»:
[36m       
       ÊñÉ½ÆæÕóÁĞÉ½Úñ,ì¬ì¬º®ÒâÆËÃæ´ß,  Æ¬Æ¬Ïé¹âÁı¶·T,·×·×µ­ÎíÍ¸ÁéÌ¨,
       ÓãÁú´Ë¼Ê·ÖÕæÎ±,ÓñÊ¯´Ó´Ë¾¡ÍÑÌ¥,  ¶àÉÙĞŞ³ÖÔâ´Ë½Ù,ÈıÊ¬Õ¶È¥ÎåÔÆ¿ª.
[2;37;0m        
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "pine" : "Äã·¢ÏÖ¹ÅËÉÉÏÓĞÈË¿Ì×Ö:
ÊñÉ½ÆæÕóÆæÖĞÆæ,ÎåĞĞÏà¿Ë±ä»¯Ç§.
ÏÉ½£µÜ×ÓËæÒâ¹ı,³¤Ğ¦Ò»ÉùÔ¾(fly up)ÁúÃÅ.
",
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/mroom7.c",
  "east" : "/open/gsword/room/lake0.c",
]));

  setup();
}

void init()
{
	add_action("fly_up","fly");
}

int fly_up(string arg)
{
	if(arg!="up" ){
		return 0;}
	message_vision("Ò»Æ¬Ïé¹âÖĞÂ¤ÕÖ×Å$N....\n",
		this_player());
	if((string)this_player()->query("family/family_name") == "ÏÉ½£ÅÉ" ) {
		message_vision("\nÖ»¼ûµ½Ò»ÕóÑÌÎí,$NÏûÊ§ÔÚÏé¹âÖĞ...\n", this_player());
                this_player()->move(__DIR__"test");
	} else {
		message_vision("\nÖ»¼ûÒ»ÕóÑÌÎí,Ò»¿Å¼¦µ°µôÔÚ$NµÄÍ·ÉÏ....\n",
			this_player() );
	}
	return 1;
}

