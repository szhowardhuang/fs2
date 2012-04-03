
inherit ROOM;

string long_desc();

void create()
{
    set("short", "Ã©Â«");
    set("long", (: long_desc :) );
    set("long.desc", @LONG
ÄãÀ´µ½ÁË´ËµØ£¬ºöÈ»·¢ÏÖ£¬Ã©Â«¾¹È»ÊÇ½¨ÔÚÒ»¿ÃÆëÑü¶ø¶ÏµÄ´óÊ÷
ÉÏ£¬ÔÚÕâÀïÄãÌýµ½ÁË£¬Ò»ÕóÕó¶£¶£µ±µ±µÄÉùÒô´ÓÎÝÄÚ´«ÁË³öÀ´£¬ÍùÉÏ
¿´ËÆºõ¿ÉÒÔ¿´µ½Ò»¿éÍ»³öÀ´µÄÊ÷¸É¡£Ê÷¸ÉÉÏ¿É¿´µ½²»ÉÙ°¼¶´(hole)¡£
LONG
        );
    set("item_desc", ([
    "hole" : @HOLE
×ÐÏ¸µØ¹Û²ìÕâÐ©°¼¶´ºó£¬Äã·¢ÏÖÕâÀïÔ­À´¿ÉÄÜÓÐÒ»×ùÍ¨ÍùÉÏÃæµÄÌÝ×Ó£¬
ÊÔÁËÊÔÄÇÐ©¶´£¬ÄãÏëÄã¡¸¿ÉÄÜ¡±ÅÀµÃÉÏÈ¥....

HOLE
    ]) );
    set("exits", ([
    "east" : "/open/tendo/room/tower/make4",
]));
         set("outdoors",1);

        setup();
}

void init()
{
    add_action("do_climb","climb");
}

string long_desc()
{
    string str;
    object ob;
    str = query("long.desc");
    ob = first_inventory(__DIR__"make6");
    if (!ob) return str+"\n";
    else
    return sprintf("[1;37m%s\n¿ÉÁ¯µÄ%sÕýÔÚÉÏÃæÕõÔú¡£[0m\n",
        str,(string)ob->name());
}

int do_climb(string str)
{
    object ob;
    return notify_fail("ÌÝ×ÓµÄºÛ¼£ÒÑ¾­ºÜÇ³ÁË, ÄãµÄÖ±¾õ¸æËßÄã, ÄãÅÀ²»ÉÏÈ¥!!\n");
    if (!str) return notify_fail("[1;32mÍùÄÇÅÀ? ÅÀÄÇÀï?!?ÊÔÊÔÅÀÇ½»òÍùÉÏÅÀÂï!![0m\n");
    if ((str != "wall") && (str != "up"))
        return notify_fail("[1;32màÅ.... Äã²»¿ÉÄÜÅÀµÃÉÏÈ¥µÄ¡£[0m\n");
    ob = first_inventory(__DIR__"make6");
    if (!ob) {
        write("[1;37mÄãÉîÉîµØÎüÁËÒ»¿ÚÆø£¬¿´×¼·½Î»£¬ÂýÂýµÄÍùÉÏÅÀ...[0m\n");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"ÉîÉîµØÎüÁËÒ»¿ÚÆø£¬¿ªÊ¼ÍùÉÏÅÀ¡£\n",
        ({this_object(), this_player()}) );
        this_player()->move(__DIR__"make6");
        return 1;
    }
    else {
        return notify_fail(sprintf("[1;37mÄãÌ§Í·¿´È¥£¬%sÕýÔÚºÜÅ¬Á¦µÄÍùÉÏÅÀ... ²»ÒªÏÅËû...[0m\n",
                                    (string)ob->name()));
    }
}



