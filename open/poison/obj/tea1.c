
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ÎÚÁú²è",({"wu-long tea","tea"}) );
	set_weight(500);
	if (clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
Ò»ºøÎÚÁú²è¡£\n");
		set("unit","ºø");
		set("value", 20);
		set("±¥ºÍ", 10);
		}
		set("ÒºÌå",([
			"ÖÖÀà" : "²è",
		        "Ãû³Æ" : "ÎÚÁú²è",
			"Ê£" : 10,
			"Ö¹¿Ê" : 30,
			"drunk_apply" : -5,
]) );
		setup();
}
