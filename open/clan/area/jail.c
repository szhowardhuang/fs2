#include <ansi.h>
inherit ROOM;
int leave(object me);
void create()
{
  set("short", HIY"世界的角落"NOR);
  set("long", @LONG
    这边是世界的角落，这边有许多的浪人在此流浪着，流浪在此
的人，机乎是无恶不作的大坏蛋，被朝廷放逐到此的罪人，通常如
果尚未关满刑期的话，是不会释放的。
        [1;31m打 "check"可以检查看看是否能回到中原。[0m
LONG
       );
set("light",1);
  set("no_fanset", 1);
  set("valid_startroom", 1);
  set("have_reborn", 1);
  set("no_chome", 1);
  set("light_up", 1);
  set("no_fight", 1);
  set("pkgame", 1);
  set("no_clean_up", 1);
  set("no_sac", 1);


   setup();
}
void init(){

        add_action("block_cmd","");
}
int block_cmd(string arg)
{
if((string)query_verb() == "check") return leave(this_player());
// 以下是可以下的指令
if((string)query_verb() == "look") return 0;
if((string)query_verb() == "ans")  return 0;
if((string)query_verb() == "say")  return 0;
if((string)query_verb() == "tell")  return 0;
if((string)query_verb() == "quit")  return 0;
if((string)query_verb() == "home")  return 0;

write("叫你不要随便乱动,还乱动....\n");
return 1;
}
int leave(object me)
{
        int outtime;
        string msg="";
        if(me->query("mud_age")>me->query("jail_time"))
        {
        write(HIY"请好好重新作人，别再犯了。\n"NOR);
        me->delete("jail_time");
        me->move("/open/common/room/inn.c",1);
        }
        else 
        {
        outtime=me->query("jail_time")-me->query("mud_age");
        if ( outtime/3600 ){
                  msg=msg+HIR+outtime/3600+"小时"+NOR;
                  outtime=outtime%3600;
        }
        if ( outtime/60 ){
                  msg=msg+HIW+outtime/60+"分钟"+NOR;
        }
        if ( outtime%60 ){
                  msg=msg+HIW+outtime%60+"秒"+NOR;
        }
        write("你还有"+msg+"刑期才满。\n");
        }
return 1;
}
