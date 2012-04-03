inherit ITEM;
void create()
{
        set_name("Ñª±äÖ®ÑÀ", ({ "blood change","blood" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("value", 0);
        }
}
