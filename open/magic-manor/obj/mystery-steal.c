#include <ansi.h>
#include <armor.h>
inherit NECK;
inherit F_SAVE;
inherit F_AUTOLOAD;
object user;

string inputstr,verb;

void create()
{
set_name("[1;36mÃîÊÖ¿Õ¿ÕÌ×[0m",({"mystery steal"}));
  set_weight(1);
  if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long","\n");
  set("unit", "Ìõ");
  set("material","steal");
  set("value",10000);
  set("no_sell", 1);
  set("no_give",1);
  set("no_get",1);
  set("no_put",1);
  set("no_auc",1);
  set("no_drop",1);
  set("no_steal",1);
  set("armor_prop/armor", 10);
 }

  setup();
}

void init()
{
        if( this_player()==environment() )
        add_action("do_steal","steal");
}

int do_steal(string arg)
{
  string ob,player;
  object obj, npc, me;
  me = this_player();


	if(!arg)
	return notify_fail("\n");

	if(sscanf(arg, "%s from %s",ob,player) != 2)
	return notify_fail("\n");

	if ( !(npc = present(player, environment (me))) )
        return notify_fail ("Ã»Õâ¸ö"+arg+"\n");

	if(wiz_level(npc)>0)
	return notify_fail("\n");

	if (!(obj=present(ob, npc)))
	return notify_fail ("\n");

	obj->move(me);
	message_vision("Ö»¼û$NÇÄÇÄÌù½ü$n£¬²»¶¯ÉùÉ«µÄÍµÁË$nµÄ"HIY+obj->name(1)+NOR"¡£\n"NOR,me,npc);

	return 1;
}
