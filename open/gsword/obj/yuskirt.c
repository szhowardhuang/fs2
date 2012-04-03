inherit EQUIP;
void create()
{
       set_name( "´óºìÂÞÈ¹" , ({ "skirt" ,"redskirt" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 1000);
                set("material", "cloth");
                set("armor_type", "pants");
                set("armor_prop/armor", 8);
        }
}
