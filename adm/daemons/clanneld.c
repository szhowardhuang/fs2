// channeld.c
// 增加各种频道, 并增加 gage 功能
// wade (6/6/1996)
// 终于把 chat* 修正好了
// 增加 music 频道, 需配合 /cmds/std/song.c 跟 /obj/example/song.c
// wade (7/7/1996)
// 增加帮派频道 By Swy

// airke更新板    旧板本在channeld.air
// 1998/9/3
// Chan在修正增加 ht cb 及 exp5000以下不能用各种频道

#include <ansi.h>
#include <net/dns.h>

inherit F_DBASE;

void create()
{
        seteuid(getuid());  // This is required to pass intermud access check.
        set_temp("channel_id", "频道精灵");
}


string myclass,myclan;
string record;

mapping channels = ([
        "sys":  (["msg_speak": "【系统】%s: %s\n",
                  "wiz_only": 1 ]),

        "wiz":  (["msg_speak": "【"HIY"众神会议"NOR"】"HIY"%s: %s\n"NOR,
                  "wiz_only": 1 ]),

        "gwiz": (["msg_speak": "【"HIG"网际巫师"NOR"】"HIG"%s：%s\n"NOR,
                  "wiz_only": 1,
                  "intermud": GWIZ,
                  "channel": "CREATOR",
                  "filter": 1 ]),

        "es":   (["msg_speak":  "【"HIR"狂想空间"NOR"】"HIR"%s：%s\n"NOR,
                  "intermud": GCHANNEL,
                  "channel": "es",
                  "filter": (: $1["MUDLIB"]=="Eastern Stories" :) ]),

        "twiz": (["msg_speak":  "【"HIW"台湾巫师"NOR"】"HIW"%s：%s\n"NOR,
                  "wiz_only":1,
                  "intermud": GCHANNEL,
                  "channel": "twiz",
                  "filter": (: $1["HOSTADDRESS"][0..2]=="140" :) ]),

        "chat":  (["msg_speak": "【"HIC"闲聊"NOR"】"HIC"%s说道: %s\n"NOR]),


        "music":  (["msg_speak": "【"HIG"天籁"NOR"】"HIG"%s 唱道: %s\n"NOR]),

        "cb":  (["msg_speak": HIC"【"HIW"帮派协商"HIW"】"HIC"%s 谈道: %s\n"NOR]),

        "dead":  (["msg_speak": "【"HIR"死亡快报"NOR"】"HIR"%s 爽快地公诸于世 ： %s\n"NOR]),

        "ht":   (["msg_speak": HIY"【"+HIG+"大侠广播"+HIY"】大侠 %s说道: %s\n"NOR]),
        
        "shout":(["msg_speak": HIR"%s纵声大叫: %s\n"NOR]),

        "gamble":(["msg_speak": "%s\n",
                   "mud_only": 1, ]),

        "mud":  (["msg_speak": HIG"%s\n"NOR,
                  "mud_only": 1, ]),

        "rumor":(["msg_speak": "【"HIM"谣言"NOR"】"HIM"%s: %s\n"NOR,
                  "anonymous": "某人", ]),

        "rumor*":(["msg_speak": "【"HIM"谣言"NOR"】"HIM""]),

        "ct*":(["msg_speak": "【"HIY"帮派"NOR"】"HIY""]),

        "wiz*": (["msg_speak": "【"HIY"众神会议"NOR"】"HIY"",
                  "wiz_only": 1        ]),

        "chat*":  (["msg_speak": "【"HIC"闲聊"NOR"】"HIC""]),

        "gt*":(["msg_speak": "【"HIG"公会"NOR"】"HIG""]),

        "gt":(["msg_speak": "【"HIG"公会"NOR"】"]),
        
        "ct":(["msg_speak": "【"HIY"帮派"NOR"】"]),

        "ht*":   (["msg_speak": HIY"【"+HIG+"大侠广播"+HIY"】"]),

        "cb*":  (["msg_speak": HIC"【"HIW"帮派协商"HIC"】"]),

]);





varargs int do_channel(object me, string verb, string arg, int emote)
{
  
  string *tuned_ch, who, emote_verb, emote_arg,cls;
  object *usr;
  int exp,clanrank;

  if (wizardp(me) && verb == "record") {
    if (!arg) tell_object (me, "现在录音况状是："+record+"\n");
    else if (arg == "stop") record = 0;
    else if (arg == "wiz" || arg == "chat") {
      if (write_file ("/log/RECORD/"+arg,
        me->query("id")+" 启动录音："+ctime(time()), 1))
      {
        record = arg;
        tell_object (me, "现在录音开始录 " + arg + " 频道。\n");
      }
    }
    return 1;
  }

  if( undefinedp(channels[verb]) && !mapp(channels))
    return notify_fail("无任何频道存在。\n");
  if(!channels[verb])
    return 0;


  if( userp(me) ) //玩家使用频道的限制
  {                               

      exp=me->query("combat_exp");
      clanrank=me->query("clan/rank");
      myclass=me->query("class");
      myclan=me->query("clan/name");
      tuned_ch = me->query_temp("channels");

      if( arg==me->query_temp("last_channel_msg") )
         return notify_fail("说话请不要重复相同的讯息。\n");

      me->set_temp("last_channel_msg", arg);

      // 非巫师不能打开巫师频道
      if( channels[verb]["wiz_only"]
       && !wizardp(me) )
        return notify_fail("这是巫师专用频道。\n");

      // 没帮派不能用 ct By Swy
      if(verb == "ct" && !myclan)
        return notify_fail("你尚未加入任何帮派。\n");
      
      if(verb == "gt" && !myclass)
        return notify_fail("你尚未加入任何公会。\n");
      //帮派协商频导
      if(verb == "cb" && (clanrank > 2))
        return notify_fail("你帮派层级不足!!无法使用此频道。\n");

      if(verb == "ht" && (exp<3000000))
        return notify_fail("你经验值未满三百万!!不算是大侠!!。\n");
      
      // 如果未满15岁不能开"es"频道
      if( verb =="es"
       && (int)me->query("age")<15 )
        return notify_fail("要满15岁才有使用es频道的权力。\n");

      //新增: shoutup 闭嘴指令
      if(me->query("shutup"))
          return notify_fail("你已经被取消使用公用频道的权利了!\n");
      if(exp < 5000)
      //新增exp在5000以下不能用任何频道,防止别人来扰乱!!!!
          return notify_fail("你经验值未满5000无法使用所有的频道!!!\n");

      //设定听众
      usr = filter_array(users(), "listen_me", this_object(), me, verb);
  } else {
      //mob使用频道,听众是所有user
      usr = users();
  }
  
  // 使用后自动打开该频道
  if( pointerp(tuned_ch) )
  {
     if( member_array(verb, tuned_ch)==-1 )
        me->set_temp("channels", tuned_ch + ({ verb }) );
  } 
  else
     me->set_temp("channels", ({ verb }) );

  // 玩家可以打开 mud 频道收听, 但是不能使用 mud 频道
  if ( channels[verb]["mud_only"] && !wizardp(me) && userp(me) )
     return 1;
    

  //  处理who 变数
  if( channels[verb]["anonymous"] )
    who = channels[verb]["anonymous"];
  else
    if( !(who = me->query_temp("channel_id") ) )
      if( !(who = me->query("channel_id") ) )
        who = me->query("name") + "(" + (me->query("id")) + ")";

  arg = ( stringp(arg) ) ? trans_color(arg) : "...";

 
//以下是各频道送出讯息


//emote
  if( verb == "ht*" ||verb == "cb*" ||verb == "chat*" || verb== "wiz*" || verb== "ct*" || verb =="rumor*" || verb == "gt*")
  {
    if (!arg )
      return notify_fail("用法: <动作> <对象> \n");
    if( sscanf (arg, "%s %s", emote_verb, emote_arg) != 2 )
      emote_verb = arg;

    return ( EMOTE_D->do_emote(me,emote_verb,emote_arg,usr,channels[verb]["msg_speak"]) ) ? 1:0;
  }


 
//公会频道
  if( verb == "gt" )
  {
      cls = (me->query("gender") == "女性") ? to_chinese("f_"+myclass) :
                                                to_chinese(myclass) ;
      message( "class_channel",
               sprintf(HIG"%s"NOR"%s说道: %s\n"NOR, cls, who, arg ),
               usr );
      return 1;
  }

//帮派频道
  if( verb == "ct" )
  { 
      message( "clan_channel",
               sprintf(HIY"【"HIC"%s"HIY"】%s说道: %s\n"NOR, myclan, who, arg ),
               usr );
      return 1;
  }  

// mud_only 频道(mud_only频道没列出说话者)
  if( channels[verb]["mud_only"] )
  {
      message( "channel:" + verb,
               sprintf( channels[verb]["msg_speak"], arg ),
                usr );
      return 1;
  }


// 一般频道 
  message( "channel:" + verb, sprintf( channels[verb]["msg_speak"],
               who, arg ), usr );
  if (verb == record)
    write_file ("/log/RECORD/"+record, sprintf( channels[verb]["msg_speak"],
               who, arg ) );
   
      


  if( (verb == "rumor"|| verb == "rumor*")
       && wiz_level(me) <=1)
  {
        write ("由于你到处散布谣言, 感觉全身虚脱无力.\n");
        me->receive_damage("gin", 10);
        me->receive_damage("kee", 10);
        me->receive_damage("sen", 10);
        do_channel(this_object(), "sys",
        me->name()+"("+me->query("id")+")"+ "散布谣言道: "+arg, 0);
  }
    

    if( !undefinedp(channels[verb]["intermud"])
     &&  base_name(me) != channels[verb]["intermud"] )
      channels[verb]["intermud"]->send_msg(channels[verb]["channel"],
            me->query("id"),me->name(1),arg,0,channels[verb]["filter"] );
    return 1;




 return 0;
/*
  if( channels[verb]
   && !undefinedp(channels[verb]["intermud"])
   &&  base_name(me) != channels[verb]["intermud"] )
    channels[verb]["intermud"]->send_msg(channels[verb]["channel"],
           me->query("id"),me->name(1),arg,0,channels[verb]["filter"] );
    return 1; */
}



//处理玩家是否接收讯息

int listen_me(object who, object me, string verb)
{
  
  if( !environment(who) )  // 分辨已上线完毕没
      return 0;
  
//现在gage好像没用....先封了
//  if(who->gage(me))
//      return 0;
 
  //分辨是否tune on
  if( !who->query_temp("channels")
        || member_array(verb, who->query_temp("channels")) == -1)
      return 0;
  
  if( channels[verb]["wiz_only"] )
      return wizardp(who);  
  

  //公会频道
  if (verb == "gt" || verb == "gt*" )
      return (myclass == who->query("class"))?1:0;   
  //帮派频道
  if (verb == "ct" || verb == "ct*") 
      return (myclan == who->query("clan/name"))?1:0; 


  return 1;
}
