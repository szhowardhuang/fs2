inherit EQUIP;
void create()
{
	set_name("��Ƥ����",({"tiger hands","hands"}));
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
��Ƥ�Ƴɵ����� , �ܴ�����߱������ƻ���
");
        set("unit", "˫");
	set("value",4000);
        set("material","cloth");
	set("armor_type", "hands");
	set("armor_prop/armor",10);
	set("armor_prop/attack",5);
        }
        setup();
}