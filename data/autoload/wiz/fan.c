// made by ccat
// 二版...加入 group move...     ccat....9_12.96
// 由于 chun 抗议,改成只传送 officer 所带的兵与 follow 的player.
//                                               ccat....9_15,96
//change by xman ........97.11.17
//
#include <ansi.h>
inherit ITEM;
inherit F_GUILDCMDS;
inherit F_AUTOLOAD;
void create()
{
        set_name("唤云扇", ({ "cloud fan","fan" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long",@LONG
      这是一把用来招换飞云的扇子,专门提供给有钱人使用,
      只要你钱庄存款够,你就可以随意飞翔在本大陆.
      (费用: 飞翔一次 500 coin,直接从钱庄扣.)

      使用格式: waveto <number>    ex: waveto 1,waveto 2
      现今提供的各传点: 1. 京城市中   2. 蜀中市中   3. 平南市中
                        4. 中央驿站   5. 陵云村     6. 您的游戏进入点
                        7. <set by u> 8. <set by u> 9. <set by u>
                       10. 枫林港    11. 仙剑派    12. 魔教
                       13. 泷山派    14. 雪苍派    15. 镜月岛

      设定格式: fanset <number>   ex: fanset 7,fanset 8 (只限 7,8,9)
      会自动把你所在位置存下来,成为新的传送点.

      查询格式: fanshow           ex: fanshow
      可以查询你的传送点所在.

      群体移动: gmove <on|off>  ex: gmove on,gmove off
      群体传送模式 开|关,若  群体传送模式 开,则 waveto 将传送你所带的兵
      及 follow你的人   ........<gmove 限沙加(xman)一人使用>............
LONG
               );
                set("value", 1000);
        }
}
void init()
{
        if( environment() == this_player() ){
        add_action("do_fanset", "fanset");
        add_action("do_fanshow", "fanshow");
        add_action("do_waveto", "waveto");
        add_action("do_gmove", "gmove");
        }
}

int do_gmove(string arg)
{
   object me;
   me = this_player();
   if( me->query("id") != "xman")
   {
      write("此命令限 沙加(xman)一人使用.\n");
      return 1;
   }
   switch(arg)
   {
     case "on":
           me->set_temp("gmove",1);
           write("群体移动模式 开起(on)!!!\n");
           break;
     case "off":
           me->delete_temp("gmove");
           write("群体移动模式 关闭(off)!!!\n");
           break;
     default:
           write("群体移动: gmove <on|off>\n");
   }
  return 1;
}

int do_fanset(string arg)
{
    int no_transmit;
    string str,str_s;
    object me,where;
    if( (arg != "7") && (arg != "8") && (arg != "9") )
    {
      write("你只能设定传送点 7,8,9...\n");
      return 1;
    }
    me = this_player();
    where = environment(me);
    no_transmit = where->query("no_transmit",1);
    str_s = where->query("short");
    str=file_name(where);
    if( arg == "7")
    {
      me->set_temp("fan/7",str);
      me->set_temp("fan_s/7",str_s);
    }
    if( arg == "8")
    {
      me->set_temp("fan/8",str);
      me->set_temp("fan_s/8",str_s);
    }
    if( arg == "9")
    {
      me->set_temp("fan/9",str);
      me->set_temp("fan_s/9",str_s);
    }
    write("你设定这里为你的新传送点.\n");
    return 1;
}
int do_fanshow(string arg)
{
    object me;
    string str_s;
    me = this_player();
    str_s = me->query_temp("fan_s/7");
    printf("传送点 7 是%s.\n",str_s);
    str_s = me->query_temp("fan_s/8");
    printf("传送点 8 是%s.\n",str_s);
    str_s = me->query_temp("fan_s/9");
    printf("传送点 9 是%s.\n",str_s);
    return 1;
}
int do_waveto(string arg)
{
    mixed count;
    int money,i,gmove;
    object me,roomm,env;

    string room="";
    me = this_player();
    if( me->query_temp("unconcious") )          return 0;
    message_vision( RED+"只见一道闪电划过，"HIR"$N"RED"消失的无影无踪。\n"+NOR ,me);
    switch(arg)
    {
       case "1":
         room="/open/capital/room/r70";         break;
       case "2":
         room="/open/gsword/room/su3";          break;
       case "3":
         room="/open/ping/room/road4";          break;
       case "4":
         room="/open/center/room/inn";          break;
       case "5":
         room="/open/start/room/s5";            break;
       case "10":
         room="/open/port/room/r3-1";           break;
       case "6":
         room = me->query("startroom");         break;
       case "7":
         room = me->query_temp("fan/7");        break;
       case "8":
         room = me->query_temp("fan/8");        break;
       case "9":
         room = me->query_temp("fan/9");        break;
       case "11":
         room ="/open/gsword/room/g5-1";        break;
       case "12":
         room ="/open/poison/room/room1";       break;
       case "13":
         room ="/open/wu/room/school8";         break;
       case "14":
         room ="/open/snow/room/room2";         break;
       case "15":
         room ="/open/dancer/room/start";       break;
       default:
     }
     gmove = me->query_temp("gmove");
     if( gmove )
     {
       roomm = environment(this_player());
     }

     // 检查 room 是否存在, gmove on|off 都得用,故放此
     env = environment(me);
     if( !me->move(room) ){
       write (" 唤云扇说: 不要玩我，根本没这地方..."HIC"-_-;\n"NOR);
        return 1;
     }

   if( gmove )
   {
     count = all_inventory( roomm );
     for( i=0;i < sizeof( count ) ;i++)
     {
       if( count[i]->is_character() &&
       ( count[i]->query_temp("id") == me->query("id")
          || count[i]->query_leader() == me ) )
             count[i]->move(room);
     }
   }

// 用来减少room 所占用太多记忆体, 请不要把这里删除
   if( !sizeof(all_inventory(env)) && ( !env->query("objects")
    || !sizeof(env->query("objects")) ) ) destruct(env);

     if( gmove )
     {
        message_vision(RED+"一阵雷电交加后，"HIR"$N"RED"带领大家出现在此!!\n"+NOR,me);
     }else
        message_vision(RED+"一阵雷电交加后，"HIR"$N"RED"在此降临!!\n"+NOR,me);

     me->set("bank/coin",money-500);
     return 1;
}
int query_autoload()
{
  if (wizardp(this_player()))
    return 1;
  else return 0;
}

