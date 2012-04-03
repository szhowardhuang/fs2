// Room: /open/death/gate.c
#include <ansi.h>
#include <login.h>
#include </include/basic_skill.c>
inherit ROOM;
void end_death(object me);
void create ()
{
  set ("short", "[31mÒõ²ÜÈë¿Ú[2;37;0m");
  set ("long", @LONG
ÄãÒÑ¾­À´µ½ÁËÒõ¼äµÄÈë¿Ú¡£ËäÈ»¾àÀëµØ¸®»¹ÓÐÒ»¶Î¾àÀë£¬µ«ÊÇÄãÒÑ¾­
¸ÐÊÜµ½ÕóÕó´Ì¹ÇµÄÒõ·ç¡£ËÄÖÜÒ»Æ¬»ÄÁ¹£¬µ«ÊÇÈ´¹íÓ°´±´±£¬¿´À´Õâ±ßµÄÒ¹
×Ü»áÂùÈÈÄÖµÄ£¬Ó¦¸Ã²»³îÃ»°é¡£ÄÏ±ßºÍÉÏÃæºÃÏñÊÇºÍÈËÊÀ¼äÏàÍ¨µÄ¹ÜµÀ£¬
²»¹ýºÃÏñÓÐÒ»¹ÉÎÞÐÎµÄÁ¦Á¿¸ô¿ªÕâÁ½¸ö²»Í¬µÄÊÀ½ç£¬¿´À´Òª´ÓÕâÁ½¸ö·½Ïò
»ØÈ¥²»ÊÇÄÇÃ´¼òµ¥µÄÊÂÇé¡£
LONG);

  set("exits", ([ /* sizeof() == 3 */
//  "up" : "/open/common/room/inn",
//  "south" : "/open/common/room/inn",
  "north" : __DIR__"bridge1",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_transmit", 1);

  setup();
}

int valid_leave(mixed me, string dir)
{
        int i;
        string room;

        if (dir == "south") {
                i = (int)me->query_temp("back_road");
                i = i + 1;
                if (i >= (random(5) + 5)) {
                    me->set_temp("back_road", 10);
                    return notify_fail("ÄãÕæµÄÄÇÃ´Ïë»Ø¼ÒÂð£¿  ºÃ°É£¡£¡¾ÍÈçÄãËùÔ¸£¬²»¹ýÒª¸¶³öºÜ´óµÄ´ú¼Ûà¸£¡£¡\nÏëÇå³þÁËÖ®ºó£¬ Èç¹û»¹ÊÇÒª»ØÈ¥µÄ»°¾ÍÍùÉÏÃæ×ß°É£¡£¡\n");
                } else {
                        me->set_temp("back_road",i);
                        return notify_fail("Äã»¹Ïë»Ø¼Ò£¿½øÁËµØ¸®¾ÍÃ»ÓÐÂ·¿ÉÍËÁË£¡\n");
                }
        }
        else if (dir == "north") {
                me->delete_temp("back_road");
                return 1;
                }
        else if (dir == "up" || dir == "ÉÏÃæ")
        {
            if ( (int) me->query_temp("back_road") >= 10 )
            {
                end_death(me);
		me->delete_temp("back_road");
                me->reincarnate();
                if(!stringp(room = me->query("startroom")))
                    room = STARTROOM;
                me->move(room);
                message_vision(
                "Í»È»ÌìÖÐ½µÏÂÒ»ÍÅÏé¹â£¬ÁîÈËÎÞ·¨ÓÃÈâÑÛÖ±ÊÓ¡£\n¹ýÁËÒ»»á¶ù£¬Ïé¹âÉ¢È¥£¬Ò»µÀÈËÓ°³öÏÖ£¬$NÖÕÓÚ´ÓÒõ¼äÍµÅÜ»ØÀ´ÁË¡£\n",me);
                return notify_fail("¹§ìûÄãÓÖÖØ»ØÈËÊÀÁË¡£\n");
            } else
		return notify_fail("Ïë»ØÈ¥£¡£¿ Ã»ÄÇÃ´¼òµ¥£¡£¡\n");
        }
        else
        return 1;
}

void auto_revive(object ob)
{
	end_death(ob);
	ob->reincarnate();
	ob->move(REVIVEROOM);
	tell_object(ob, "ÑÖÂÞÍõ¿´Äã²»Ë¬À²£¡£¡ËÍÄã»ØÈË¼ä£¡£¡\n");
}

void start_death(object ob)
{
	if(ob->query("combat_exp"))
        ob->set_temp("death/combat_exp", 1);

	if( ob->query("death/time") >= random(3)+3 ) {
	    ob->set("death/time", 0);
	    return; 
	}

	ob->add("death/time", 1);
	ob->set_temp("death/skill", 1);
	if( ob->query("max_force") || ob->query("max_mana") || ob->query("max_atman") )
	{
	if( ob->query("max_force") >= ob->query("max_mana")
	&& ob->query("max_force") >= ob->query("max_atman") )
        ob->set_temp("death/force", 1);
        else if( ob->query("max_mana") >= ob->query("max_force")
        && ob->query("max_mana") >= ob->query("max_atman") )
                ob->set_temp("death/mana", 1);
	else
                ob->set_temp("death/atman", 1);
	}
//	call_out("auto_revive", 300, ob);
}

void end_death(object me)
{
    	int cost;
	mapping skl, lrn, map;
	string *sname, *mapped;
    	int i;


    if( me->query_temp("death/combat_exp") )
    {
        // cost =(int) ( me->query("combat_exp") *
// int ºÍ str ¸ßµÄÈËµÃÊµÕ½¾­Ñé±È½Ï¿ì... so ¿Û±È½Ï¶à... 5% - 10%
//       ( (random(me->query("int")*2 + me->query("str") - 30) + 60) / 12 ) /
// kar ±È½Ï¸ßµÄÈË.. ±È½ÏÓÐ¸£Æø... ¿ÉÒÔ´òÕÛ... ³ýÒÔ 1 - 2....
//        ( random(me->query("kar") - 10) / 15 + 1) / 100 );
	if( !me->query("death/time") ) {
	    cost = me->query("combat_exp") / 100 * 3;
            me->add("combat_exp", -cost);
            tell_object(me, "ÄãµÄÊµÕ½¾­Ñé±»¿ÛÁË"+chinese_number(cost)+"µã¡£\n");
	    return;
	}

        cost = me->query("combat_exp") / 100 * 7;

        me->add("combat_exp", -cost);
	tell_object(me, "ÄãµÄÊµÕ½¾­Ñé±»¿ÛÁË"+chinese_number(cost)+"µã¡£\n");
    }
    if( me->query_temp("death/skill") )
    {
        skl = me->query_skills();
        if(sizeof(skl)) {
            sname  = keys(skl);
            map = me->query_skill_map();
            if( mapp(map) ) mapped = values(map);
            if( !mapped ) mapped = ({});
            for(i=0; i<sizeof(skl); i++) 
            if((member_array(sname[i], mapped) != -1 ) || (sname[i] == basic_skill[sname[i]]) )
	    {
		if (random(me->query("kar")-10) < 8)
		{
		cost = (int) ( skl[sname[i]] * 
// int ½Ï¸ßÕßµÃ skill ±È½Ï¿ì... so ¿Û±È½Ï¶à..  1% - 4%
		((random(me->query("int")) + 10) / 10 ) /
// ¸£Ôµ½Ï¸ßÕß.. ¿Û½ÏÉÙ.. ³ýÒÔ 1 - 2
        	(random(me->query("kar") - 10) / 20 + 1) / 100 );
		skl[sname[i]] -= cost;
		tell_object(me, "ÄãµÄ"+to_chinese(sname[i])+"¼¼ÇÉ±»¿ÛÁË"+chinese_number(cost)+"µã¡£\n");
		}
	    }
        }
    }


    if( me->query_temp("death/force") )
    {
        cost = (int) ( me->query("max_force") *
// con ½Ï¸ßÕßµÃ force ±È½Ï¿ì... so ¿Û±È½Ï¶à..  2% - 5%
        ((random(me->query("con")) + 20) / 10 ) /
// ¸£Ôµ½Ï¸ßÕß.. ¿Û½ÏÉÙ.. ³ýÒÔ 1 - 2
        (random(me->query("kar") - 10) / 20 + 1) / 100 );
        if( cost > 10)
          cost = 10;
        me->add("max_force", -cost);
        tell_object(me, "ÄãµÄÄÚÁ¦ÉÏÏÞ±»¿ÛÁË"+chinese_number(cost)+"µã¡£\n");
    }
    if( me->query_temp("death/mana") )
    {
        cost = (int) ( me->query("max_mana") *
// spi ½Ï¸ßÕßµÃ mana ±È½Ï¿ì... so ¿Û±È½Ï¶à..  2% - 5%
        ((random(me->query("spi")) + 20) / 10 ) /
// ¸£Ôµ½Ï¸ßÕß.. ¿Û½ÏÉÙ.. ³ýÒÔ 1 - 2
        (random(me->query("kar") - 10) / 20 + 1) / 100);
        if( cost > 10)
          cost = 10;
        me->add("max_mana", -cost);
        tell_object(me, "ÄãµÄ·¨Á¦ÉÏÏÞ±»¿ÛÁË"+chinese_number(cost)+"µã¡£\n");
    }
    if( me->query_temp("death/atman") )
    {
        cost = (int) ( me->query("max_atman") *
// spi ½Ï¸ßÕßµÃ ÁéÁ¦ ±È½Ï¿ì... so ¿Û±È½Ï¶à..  2% - 5%
        ((random(me->query("spi")) + 20) / 10 ) /
// ¸£Ôµ½Ï¸ßÕß.. ¿Û½ÏÉÙ.. ³ýÒÔ 1 - 2
        (random(me->query("kar") - 10) / 20 + 1) / 100 );
        if( cost > 10)
          cost = 10;
        me->add("max_atman", -cost);
        tell_object(me, "ÄãµÄÁéÁ¦ÉÏÏÞ±»¿ÛÁË"+chinese_number(cost)+"µã¡£\n");
    }
    me->delete_temp("death");
}
