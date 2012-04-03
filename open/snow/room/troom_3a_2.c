// Room: /u/e/eiei/room/troom_3a_2.c
inherit ROOM;

string search();
void create ()
{
  set ("short", "残破青石路");
  set ("long", @LONG
    走到这里，树林似乎更冒密了。不过如果你仔细看
    的话，在路的一旁好像有一条青石板铺成的的小路，虽
    然看起来青石板已经有点老旧，不过由于青石板一直向
    树林里面延伸，所以看起来就显的有一点突出了。
LONG);

  set("outdoors", "/u/e/eiei/room");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"troom_3a_1.c",
]));

 set("search_desc", ([ /* sizeof() == 1 */
  "青石板" : (: search :),
]));
setup();
}
string search()
{
if (this_player()->query_temp("shaswordtime")==1)
{
   message_vision("$N在青石版中找来找去 , 摸出了一颗水法珠并收进口带中 \n",this_player() );
   this_player()->set_temp("quests/findball3",1);
   new("/open/gsword/obj1/waterball")->move(this_player());
   return "";
  }
        message_vision("$N在这翻来覆去 , 结果什么也没发现 \n",this_player());
        return "";
}
