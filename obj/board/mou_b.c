inherit BULLETIN_BOARD;
void create()
{
  set_name("魔刀千字墙", ({"board"}));
  set("location", "/open/gblade/room/secret");
  set("board_id", "mou_b");
  set("long","
上面龙飞凤舞的写着一些东西，都是莫无愁多年练功所发展的武功招式
心得，旁边还夹杂一些奇怪的文字，看也看不懂。\n" );
  setup();
  set("capacity", 35);
  set("master",({"swy"}));
}
