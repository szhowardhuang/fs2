inherit ROOM;

void create()
{
 set("short","太君山脚");
 set("long",@LONG
树木苍翠，时有昆虫兽鸣声，不远处正有几个乞丐布袋里
拿出小蛇，有黑有红，有长有短，附近全是过膝的长草，
或许已经有几条小蛇埋伏在你身边了，你心下不禁慌乱，
只觉毛骨悚然，若不想给咬上一口，身中奇毒，最好夹起
尾巴，迅速逃离此处吧。

LONG);
 set("exits",([
 "west" : __DIR__"room01.c",
 "north" : __DIR__"room03.c"
 ]));
 setup();
}
