inherit ITEM;
#include <ansi.h>
        
void create()
{
    set_name("骨骸",({"skeleton"}));
    set("long","
一具披着道袍的骨骸，看来死去的年代已经相当久远了，你心思道：
说不定这就是小蝶她师父－灵韵师太的骨骸...你发觉道袍上似乎有
些奇特...
        \n");
    set("unit","具");
    set("value",100);
    set("no_get",1);
    set("no_sac",1);
    set("no_auc",1);
    set_weight(500000);
    setup();
}

void init()
{
        add_action("sea_ske","search");
}

int sea_ske(string arg)
{
        object me = this_player();
        object ob = this_object();
        object book = new("/data/autoload/tendo/book");
        object letter = new("/open/mon/obj/letter");
        
        if(me->query_temp("icestorm/ice_spell")==6)
        {
        if(!arg) return 0;
        if(arg!="道袍")
        {
                write("你仔细的反覆查看了"+arg+"好几次，但就是没有任何的发现...\n");
                return 1;
        }
                write("你仔细的反覆查看了"+arg+"...\n忽然从"+arg+"内掉出了一本古书及一封信笺...\n\n
你顺手便检了起来...\n");
                book->move(me);
                letter->move(me);
                me->set_temp("icestorm/ice_spell",7);
                return 1;
        }
}

