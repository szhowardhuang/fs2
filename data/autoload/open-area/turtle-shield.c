#include <armor.h>
#include <ansi.h>
inherit SHIELD;
object me=this_player();
int cor,kar,intt,spi,cps;
void create()
{
        set_name(HIR"»ð¹ê¿Ç¶Ü"NOR,({"fire-turtle shield","shield"}) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","¼þ");
        set("value", 1);
        set("long","»ð¹êÉíÉÏµÄÓ²¿Ç, Ç¡ÇÉ¿ÉÒÔÓÃÀ´µÖÓù¹¥»÷¡£\n");
	set("no_put",1);
	set("no_drop",1);
//	set("no_get",1);
	set("no_sell",1);
	set("no_auc",1);
	set("no_give",1);
	set("no_steal",1);
        }
        setup();
        this_object()->set("armor_prop/parry", 5);
        this_object()->set("armor_prop/armor", 100);
        this_object()->set("armor_prop/defense", 40);
}

void init()
{
	object me,ob;
	me=this_player();
	ob=this_object();

	if( !ob->query("boss") )
	{
	ob->set("boss",me->query("id"));
	}
}

int query_autoload()
{
	return 1;
}