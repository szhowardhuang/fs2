#include <combat.h>
#include <ansi.h>
#include <mudlib.h>
inherit NPC;
void create() {
  set_name("[1;33mÂæÍÕ[0m", ({"desert camel","desert","camel"}));
  set("title","[33m³¾É³[0m");
  set("long", "Ò»Í·×ì°Í²»Í£µØ¾×½À£¬ÑÛÉñ´ôÖÍµÄÂæÍÕ¡£\n");
  set("horse",1);
  set("no_kill",1);
  set("no_fight",1);
  set("max_force",2750);
  set("force",2750);
  set("max_kee",3200);
  set("kee",3200);
  set("max_gin",1500);
  set("gin",1500);
  set("max_sen",2250);
  set("sen",2250);
  set("race", "Ò°ÊÞ");
  set("combat_exp",750000);
  set_skill("parry",120);
  set_skill("move",100);
  set_skill("dodge",100);
  set("verbs",({"bite","claw"}));
setup();
}

void init() {
  add_action("do_ascend","ride");
  add_action("do_descend","dismount");
  add_action("do_wall","desertwall");
  add_action("do_runaway","back_desert");
}

int do_runaway()
{
  object me,wolf,target;
  string *name;
  me = this_player();
  wolf = this_object();
  target = me->query_enemy();
  if(!query_leader())
  return notify_fail("ÄãÊÇÕâÂæÍÕµÄÖ÷ÈËÂð£¿\n");

  message_vision("[1;33mÂæÍÕ¹Ô¹ÔµØÌýÄãµÄ»°£¬»Ø¼ÒÈ¥ÁË¡£[0m\n",me);
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
  if (me->query("combat_exp") < 1200000)
  return notify_fail("ÄãµÄ½­ºþÀúÁ·¿´À´²»ÄÜÓ¦¸¶ÔÚÂæÍÕÉÏµÄ×´¿ö¡£\n");
  if (me->query_skill("riding",1) < 1 )
  return notify_fail("Äã»¹²»ÖªµÀÆïÊõµÄ»ù±¾£¬ÒªÔõÃ´Æï£¿\n");
  if(me->query_temp("is_riding"))
  return notify_fail("ÄãÕýÔÚÆï×ÅÄØ£¡\n");
  message_vision("[1;33m$NÉí×ÓÒ»×ª£¬Ë«½ÅÒ»Ì¤£¬Ë²¼ä±ã°²×øÔÚÍÕ·åÖ®ÉÏ£¡[0m\n",me);
  wolf->set_leader(me);
me->add_temp("apply/name",({ me->name()+"£¨ÕýÆï×Å"+this_object()->name()+"£©"}));
  me->set_temp("is_riding", 1);
  me->add("marks/h_camel",random(5));
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

int do_wall()
{
  object me,who;
  string *name;
  int dodge,camel;
  who=this_player();
  dodge=((who->query_skill("riding",1)+who->query_skill("parry",1))/2);
  camel=(who->query("marks/h_camel"));
  me=query_leader();
  who->add("marks/h_camel",random(3));
  if (!me)
  return notify_fail("ÕâÂæÍÕ²»µ±ÄãÊÇÖ÷ÈË£¬»¹ÊÇÆïÆï¿´°É£¡\n");
  if (who->query_temp("marks/wall",1))
  return notify_fail("ÄãÇ°ÃæÒÑ¾­ÓÐµÀÉ³Ç½ÁË£¡\n");
  if (random(200)>(who->query_skill("riding",1)))
  return notify_fail("[1;37mÂæÍÕ²»ÌýÄãµÄÖ¸»Ó£¬²»°ïÄãÖþÆðÉ³Ç½£¡[0m\n");
  if (random(500) > camel)
  return notify_fail("[1;35m¿´À´ÄãºÍÂæÍÕµÄ¸ÐÇé²»¹»ºÃ£¬ ­²»ÀíÄã¡£[0m\n");
 message_vision("[33m"+me->query("name")+"×øÏÂÂæÍÕºöÈ»Ë«ÑÛÒ»Õö£¬ËÄ½ÅÁ¦Ì¤µØÃæ£¬\n
³¾É³ÂúÌì·ÉÎè£¬"+who->query("name")+"ÉíÇ°ÏÖÆðÒ»µÀÉ³Ç½£¡[0m\n",who);
  who->add_temp("apply/defense",dodge);
  who->set_temp("marks/wall",1);
  call_out("remove_effect",10,who);
  return 1;
}

void remove_effect()
{
  object me,who;
  string *name;
  int dodge;
  who=this_player();
  me=query_leader();
  dodge=((who->query_skill("riding",1)+who->query_skill("parry",1))/2);
  message_vision("[1;37mºäµÄÒ»Éù£¬´£Á¢ÔÚ"+me->query("name")+"Ç°µÄÉ³Ç½ÒÑÏûÊ§£¡[0m\n",who);
  who->add_temp("apply/defense",-dodge);
  who->delete_temp("marks/wall");
}

int heal_up()
{
  object *enemy,who,user;
  int i,dodge;
        user = query_leader();
  who = this_player();
  if(!user) return 1;
  if( user->is_fighting() )
  {
   user->add("marks/h_camel",random(3));
   if (random(120) < (user->query_skill("riding",1)))
   {
    enemy=user->query_enemy();
    i=random(sizeof(enemy));
    message_vision("[1;33m"+user->query("name")+"×ùÏÂÂæÍÕÍ»È»ÕÅ¿ª×ì°Í£¬\n
ÒÔÑ¸À×²»¼°ÑÚ¶úÖ®ÊÆÏò$nÍÂÁË¼¸¿Ú¿ÚË®£¡$nË²¼ä´íãµ²»ÒÑ£¬ÎÞ·¨×Ô¼º£¡[0m\n",who,enemy[i]);
    enemy[i]->start_busy(2);
   }
  }
  return ::heal_up() + 1;
}
