inherit ROOM;

void create()
{
 set("short","西厢房");
 set("long",@LONG
你看到一群乞丐围在一起，并听到铿、铿的声音，你走近
一看，原来是他们正在玩骰子.....你想加入他们吗？

LONG);
 set("exits",([
 "south" : __DIR__"room06.c"
 ]));
 setup();
}
