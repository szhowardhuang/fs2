inherit ROOM;

void create()
{
 set("short","卧室");
 set("long",@LONG
这里是丐帮帮主的卧室，里面看起来干干净净的，每样东
西都是有条不紊的摆设整齐，不过上面却积了一层薄薄的
灰尘，原来帮主是一个大老饕，只要一有时间就到外面去
寻找美食，甚少在这里休息。
LONG);
 set("exits",([
 "south" : __DIR__"room22.c"
 ]));
 setup();
}
