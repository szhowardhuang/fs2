// Room: /open/poison/room/eqroom.c
inherit ROOM;

void create ()
{
  set ("short", "器物间");
  set ("long", @LONG
这里是众魔教徒休息的地方 ,也是先进的教徒奖掖后进的所在 ,代
表了魔教教徒间那种高度的友爱 ,另外 ,这里亦是魔教徒交换各种神兵
利器的地方 ,所以各位师兄师姊们 ,有好东西别只顾埋了 ,留给小师弟
师妹吧 !这里有个大书架(shelf)
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
"shelf" : "一个看起来沉重而老旧的书架 ,上面布满了灰尘 ,
但是在书架的两侧 ,却不自然的一尘不染 ,好像有人转
过架上的书都很旧了 ,不过翻动的痕迹倒是不少 ,令人
诧异的是 ,都已经有图书室了 ,何必费尽心思搬个书架
到这来。
",
]));

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room1.c",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);
     set("no_clean_up",1);

  setup();
}
void init()
{
        add_action("do_turn","turn");
}

int do_turn(string str)
{
        object who;
        who = this_player();

        if(!str || str != "shelf")
                return notify_fail("你想转动什么？\n");
        else{
             tell_object(who,"\n你将书架转开 ,进入了后边的秘门。\n\n");
             who->move("/open/ping/room/road3.c");
             tell_room(this_object(),who->query("name")+"把书架转开 ,进入秘道中。\n");
            }
        return 1;
}
int valid_leave(object me, string dir)
{
if (dir == "down" && me ->query("class") != "poisoner")
  if ( !wizardp (me) )
     return notify_fail("喂 ,进去干麻 ?想被毒啊。\n");
     return :: valid_leave(me, dir);
}

