// Room: /u/b/bss/bug_room
#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "bug回报暨公布room");
  set ("long", "
本房间主要的用途是在给与玩家回报bugs和给巫师公布已处理或未处理
的bug,本房间的使用原则如下:
"HIY"
(1)要回报bug的玩家,请用本房间所提供的(record)功能,切勿将bug post
   在board上,否则巫师将以公布bug的罪名与以严惩,轻者废武功,重者
   purge
(2)若发现在record中有不是回报bug的文章,也将以增加巫师工作负担的罪
   名与以严惩,轻者ckill十次,重者purge
(3)在房间中的公布栏主要是给巫师将已处理或未处理的bug公布给玩家知
   道的,若有玩家乱post或是把它当成与巫师或玩家的聊天版,或者跟bug
   完全没关系的文章,post的玩家也将与以严惩,轻者罚款,重者sleep
(4)回报的bug一经确定属实之后,将会对该回报玩家与以奖励,切勿狮子大开
   口,要些geq,meq这类的好防具,或者是大幅的提升自己能力的要求,虽然
   会以玩家所希望的为主,但是巫师还是会以玩家所回报的bug大小,决定
   到底要给啥好处
(5)本房间切忌使用于其他用途,例如发呆,练功,逃避打斗等,若经发现属实
   一律ckill 10 次,没得讲
有别的以后再补.................
"NOR);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/wiz/fsroom2",
]));
  set("objects",([
  "/obj/bug_record.c":1,
]));
  set("no_magic", 1);
  set("light_up", 1);
  set("no_fight", 1);
  setup();
  call_other("/obj/board/bug_b","???");
}

