inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG "วเม๚ึฎตั" NOR,({"de"}));
	set("unit","ึง");
	set("value",20000);
        setup();
}
int query_autoload() { return 1; }
