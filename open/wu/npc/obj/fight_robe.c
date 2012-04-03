
// fighter_robe.c

#include <armor.h>
 
inherit CLOTH;
 
void create()
{
        set_name( "武斗服", ({ "fighter robe","robe"}) );
        set("long",
                     "这是一件造型特殊的衣服，于肩部及胸部特别做加强\n"
                       "，以适战斗所需，护肩上还有一个""斗""字，是一般武\n"
                       "斗家十分喜爱的服装\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit"              , "件");
                set("material"          , "cloth");
                set("armor_prop/armor"  ,  5);
                set("armor_prop/unarmed",  2);
        }

        setup();
}
