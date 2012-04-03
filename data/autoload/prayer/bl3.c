#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"µÄ[32mÁúÑÀÏâ½ğµ¶[0m",({"dragon-tooth blade","blade"}));
        else
         { set_name("[32mÁúÑÀÏâ½ğµ¶[0m",({"dragon-tooth blade","blade"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "°Ñ");
        set("long",@LONG

	Ò»°ÑÌúÖÆµÄ´óµ¶, Öıµ¶Ê¦¸µÔÚÖıÔìµÄ¹ı³ÌÖĞ¼ÓÈëÁË»Æ½ğ 
	Ìá¸ßÁË´Ëµ¶µÄÓ²¶È, ÃÜ¶ÈÓëÇ¿¶È!!²¢ÇÒÔÚµ¶µÄÁ½²à¼ÓÉÏ
	ÁËÁúÑÀ×öÎªÔö¼ÓÉ±ÉËÁ¦µÄÀûÆ÷!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
//        set("wield_msg", "$N´Óµ¶ÇÊ½«$n°Î³öÀ´Ö®ºó£¬»ğ¹âËÄÒç¡£\n");
        }
        init_blade(90);
        setup();
}               
int query_autoload() { return 1; }

      