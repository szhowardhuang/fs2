inherit ITEM;
void create()
{
set_name("龙神水珠", ({"dragon_stone","stone"}));
set("long",@LONG
传说中，水龙神进出水底时所用的神奇水珠，能增加持有者抵抗
进入水压强大的地方。
LONG);
set("unit","颗");
set_weight(100);
set("value",0);
setup();
}