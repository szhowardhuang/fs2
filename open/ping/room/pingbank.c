// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
  set ("short", "平南钱庄");
  set ("long", @LONG
这里是平南钱庄,虽然地处偏远,可是你在别处的存款,这里
还是承认的,你可以看看这儿的公告(board),看看有甚么服务.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您现有的存款    convert: 换钱币
    withdraw: 提款               deposit: 存款    
    cdonate: 把钱转存至你的帮派之中
 ",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road3",
]));
  set("objects", ([
       "/open/ping/npc/officer-1" :1,
     ]) );
  set("light_up", 1);
  set("donate",1);

  setup();
}
