inherit ROOM;
void create()
{
set("short", "海神坊");
set("long",@LONG
这该说是一个房间、还是一个空间，四周向外无限延伸，完全看不到
边界，一片白茫茫的景象，仿佛置身于茫茫大雾之中，约略可以看到前方
站着一位老人，而老人的身旁有一座雕像，与把你吸进来的雕像相似。
LONG);
set("objects",([
__DIR__"statue":1,
]));
set("light_up",1);
set("no_transmit",1);
setup();
}
