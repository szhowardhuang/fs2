#include <ansi.h>
// by airke
inherit NPC;

void do_sleep();

void create()
{ 
  set_name(HIY"小黄金甲龙"NOR,({"gold-dragon","dragon"}));
  set("age",1);
  set("long","pat it or order <动作>\n");
  set("no_kill",1);
  set("kee",200000);
  set("max_force",10000);
  set("force_factor",30);
  set("combat_exp",7000000);
  set("chat_chance", 35);
  set("chat_msg", ({
  HIY+"黄金小甲龙高兴的在你身旁绕来绕去～～～\n"NOR,
  HIY+"黄金小甲龙眨了眨大大的双眼，很无辜的望着你....\n"NOR,
  HIY+"黄金小甲龙大吼: ㄚ～～～～ㄨ～～～～\n"NOR,
  HIY+"黄金小甲龙用脚在地上无聊地画着圈圈....\n"NOR,
  HIY+"黄金小甲龙伸手一指，变出了一堆食物........开始躲在一旁大快朵颐 :D~~\n"NOR,
  HIY+"黄金小甲龙爬到你肩上舔了舔你的脸。哇！....好恶心ㄛ..\n"NOR,     
  HIY+"黄金小甲龙依偎在你脚边撒娇。\n"NOR,
  HIY+"黄金小甲龙很累地打了一个哈欠...Zzzz\n"NOR,
  (: do_sleep :),
  }));

  setup();
}

void do_follow(object owner)
{
 command("follow "+owner->query("id")); 
 set_leader(owner);
return;
}

void init() {
object obj;
::init();
     if(interactive(obj=this_player())) {
          command("ssmile "+obj->query("id"));
        }
add_action("do_pat","pat");
add_action("do_order","order");
add_action("do_kick","kick");
add_action("do_lick","lick");
add_action("do_flop","flop");
add_action("do_die","die");
add_action("do_faint","faint");
add_action("do_hammer","hammer");
add_action("do_spit","spit");
add_action("do_ride","ride");
add_action("do_shout","shout");
return;
}

int do_pat(string str) {
 
  object scale,room;
  string name;

  if(!str||sscanf(str, "%s",name)!=1)
          return 0;
  if(name != "gold-dragon")
          return 0;
  message_vision (HIC"$N拍拍黄金小甲龙的头，黄金小甲龙又变成了木雕。\n"NOR,this_player());
  room = environment(this_player());
  new("/open/island/obj/statue")->move(room); 
  destruct(this_object());
  return 1;
}


int do_order(string str)
{
  string act,tar;  
  
 if(this_player()!=this_object()->query_leader())
       return 0;
  if(!str)
       return notify_fail(HIY"黄金小甲龙眨了眨双眼，疑惑地望着你....\n"NOR);
  if(sscanf(str, "%s %s",act,tar)==2) {
     command(act+" "+tar);
     return 1;
  }
  if(sscanf(str, "%s",act)) {
     command(act);
     return 1;
  }
 return 1;
}

void do_sleep()
{
  object room;
  mixed all;
  int allnum,i; 

  room = environment(this_object());
  all = all_inventory(room);
  allnum=sizeof(all);
  for(i=0;i<allnum;i++) {
      if(userp(all[i])) {
          message_vision (HIY"小甲龙偷偷钻进了$N的怀里....睡着了....\n"NOR,all[i]);
          new("/open/island/obj/spat")->move(all[i]);
          i=allnum+1;              
      }
  } 
  destruct(this_object());
 return;
}

int do_ride(string str) {
 
  object room;
  string name;

  if(!str||sscanf(str, "%s",name)!=1)
          return 0;
  if(name != "gold-dragon")
          return 0;

  command("inn");
  write("\n牠还没满周岁ㄝ，请爱护稀有动物....\n");
  
  return 1;
}



