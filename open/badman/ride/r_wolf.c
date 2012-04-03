#include <combat.h>
#include <ansi.h>
#include <mudlib.h>
inherit NPC;
void create() {
  set_name("[31mºìÀÇ[0m", ({"red wolf","red","wolf"}));
  set("title","[1;31mÑª¹â[0m");
  set("long", "Ò»Æ¥Ä¿Â¶É±Æø£¬ÉíÍ¸ºì¹âµÄÀÇ¡£\n");
  set("horse",1);
  set("max_force",1500);
  set("force",1500);
  set("max_kee",1000);
  set("kee",1000);
  set("max_gin",1000);
  set("gin",1000);
  set("max_sen",1000);
  set("sen",1000);
  set("race", "Ò°ÊÞ");
  set("combat_exp",320000);
  set_skill("parry",80);
  set_skill("dodge",90);
  set_skill("move",90);
  set("verbs",({"bite","claw"}));
  setup();
}

void init() {
  add_action("do_runaway","back_home");
  add_action("do_ascend","ride");
  add_action("do_descend","dismount");
}

  int do_runaway()
{
  object me,wolf,target;
  string *name;
  me = this_player();
  wolf = this_object();
  target = me->query_enemy();
  if(!query_leader())
  return notify_fail("ÄãÊÇÕâÆ¥ÀÇµÄÖ÷ÈËÂð£¿\n");
  message_vision("[1;31mºìÀÇÌý´ÓÄãµÄÖ¸»ÓÍùÉ­ÁÖµÄ·½Ïò×ßÈ¥[0m\n",me);
  me->delete_temp("is_riding");
  me->delete_temp("apply/name",name);
  me->delete_temp("marks/have_wolf");
  destruct(wolf);
  return 1;
}
int do_ascend()
{
  object me,wolf,target;
  me = this_player();
  wolf = this_object();
  target = me->query_enemy();
  if(wolf->query("horse")!=1)
  return notify_fail("ÄãÒªÆïÕâ¶«Î÷²»ÈçÈ¥¼ËÔº£¡\n");
  if(me->query("class")!="bandit")
  return notify_fail("Õâ¶¯Îï²»ÊÇÄã¿ÉÒÔ×øµÄ£¡\n");
  if (me->query("combat_exp") < 600000)
  return notify_fail("Äã¿ÉÃ»ÓÐÕâÖÖÀúÁ·À´Ó¦¸¶ÔÚÀÇÉÏµÄ×´¿ö¡£\n");
  if (me->query_skill("riding",1) < 1 )
  return notify_fail("Äã»¹²»ÖªµÀÆïÊõµÄ»ù±¾£¬ÒªÔõÃ´Æï£¿\n");
  if(me->query_temp("is_riding"))
  return notify_fail("ÄãÕýÔÚÆï×ÅÄØ£¡\n");
  message_vision("[1;37m$N½ÅÒ»µÅ£¬ÊÖÒ»Ë¦£¬ÉíÒ»·­£¬¾ÍÕâÃ´ÆïÔÚÀÇÉÏÁË£¡[0m\n",me);
  wolf->set_leader(me);
me->add_temp("apply/name",({ me->name()+"£¨ÕýÆï×Å"+this_object()->name()+"£©"}));
  me->set_temp("is_riding", 1);
  move(me);
  me->set_heart_beat(1);
  return 1;
}

int do_descend()
{
  object me;
        string *name;

        me=this_player();
  if (!me->query_temp("is_riding"))
  return notify_fail("ÄãÃ»Æï¶«Î÷£¬¸ÉÂïÏÂÀ´£¿\n");
  message_vision("[1;37m$NÒ»¸ö×ªÉí£¬±ãÒÑÓ¦ÉùÂäµØ£¬ºÃºÃµØÕ¾ÔÚµØÉÏ¡£[0m\n",me);
  me->delete_temp("is_riding");
  me->delete_temp("apply/name",name);
  move(environment(me));
  me->set_heart_beat(0);

  return 1;
}

int heal_up()
{
  object *enemy,who,user;
  int i,dodge;
        user = query_leader();
  who = this_player();
  if( user->is_fighting() )
  {
   if (random(100) < (user->query_skill("riding",1)))
   {
    enemy=user->query_enemy();
    i=random(sizeof(enemy));
    message_vision("[1;31m"+user->query("name")+"Áé»îÔËÓÃÆïÊõ£¬³Ã$n²»×¢ÒâÊ±£¬\n
Ê¹ÀÇ½«$nÕû¸öÈËÑ¹ÔÚµØÉÏ£¬¶¯µ¯²»µÃ£¡[0m\n",who,enemy[i]);
    enemy[i]->receive_damage("kee",100);
    enemy[i]->start_busy(1);
    COMBAT_D->report_status(enemy[i], 1);
   }
  }
  return ::heal_up() + 1;
}
