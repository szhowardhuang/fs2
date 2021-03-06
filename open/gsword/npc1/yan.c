inherit NPC;
#include <ansi.h>
#include "/open/open.h"
int ask_sword();
int ask_tesin();
int ask_kking();
int ask_roger();
int ask_array();
int ask_fu();
int ask_shasword();
void create()
{
        set("title","仙剑派第二代弟子"),
        set_name("风青云",({"yan"}));
        set("nickname",HIR"剑如回阳"NOR);
        set("class","swordsman");
        create_family("仙剑派",2,"长老");
        set("family/master_name","逍遥子");
        set("family/family_name","仙剑派");
        set("attitude","heroism");
        set("env/连击","YES");
        set("gender","男性");
        set("age",87);
        set("str",50);
        set("con", 44);
        set("int", 60);
        set("cps", 48);
        set("cor", 48);    
        set("long","他是仙剑派第二代弟子，郑士欣之师叔，正为对抗血魔而勤练剑术。\n");
        set("combat_exp",4000000);
        set("max_gin",10000);
        set("gin",10000);
        set("max_kee",30000);
        set("max_force",10000);
        set("force",10000);
        set("kee",30000);
        set("max_sen",10000);
        set("sen",10000);
        set("functions/swordkee/level",100);
        set("functions/sha_kee/level",100);
        set("functions/sunswordkee/level",100);
        set_skill("dodge",100);
        set_skill("unarmed",90);
        set_skill("parry",120);
        set_skill("sword",120);
        set_skill("sun_fire_sword",100);
        set_skill("sha-steps",100);
        set_skill("shaforce",150);
        set_skill("force",130);
        set_skill("array",100);
        set_skill("sha-array",100);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","sun_fire_sword");
        map_skill("parry","sun_fire_sword");
        set("force_factor",20);
        set("inquiry",([
  "仙剑连阳" : (: ask_sword :),
  "天门奇阵" : (:ask_array:),
  "李梦枕" : (:ask_roger:),
  "连阳七绝斩" : (:ask_fu:),
  "龙铁心" : (: ask_tesin :),
  "血魔" : "当年就为了诛灭这荼毒武林的魔王,而使当时武林数大高手皆先后消失…当然包括了师父逍遥子",
  "开天三灵器" : "开天三灵器是当初师父为了对付血魔请人打造，听说要开封印需靠三派传人，配合三灵器才能开启呢~",
  "逍遥子" : "就是师父嘛..当年在一次偶然间..师父传我几招的剑招..也就是我前一阵子传给你的禁断连阳七诀…这只是师父绝学的一部份..",
  "仙剑峡谷" : (:ask_shasword:),
]));
set("get_sha_sp", 1);
set("quests/sunfire",1);
set("chat_msg_combat",({
        (: perform_action,"sun_fire_sword.sunswordkee" :)
  }));
        setup();
carry_object("/open/gsword/obj/dragon-sword.c")->wield();
carry_object("/open/gsword/obj1/ring.c")->wear();
carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
        add_money("gold",5);
}
int accept_fight(object who)
{
 fight_ob(who);
 command("perform sun_fire_sword.sunswordkee");
 return 1;
}
int accept_kill(object who)
{
command("say 让你知道连阳剑的厉害！\n");
set("have_kill_me",1);
 kill_ob(who);
command("perform sun_fire_sword.sunswordkee");
return 1;
}
void init() {
  object obj;
  ::init();
  if(interactive(obj=this_player()) && !is_fighting())
     {
      remove_call_out("greeting");
      call_out("greeting",1,obj);
     }
}

void greeting(object ob)
{
        command("hmm");
        command("wear all");
}

int ask_sword()
{
  object me;
  me=this_player();

command("say 那是师父的绝世宝剑ㄚ..由于斩妖无数..故已成为妖魔的克星..不过为封印血魔..已将其分铸成开天三灵器…我想你一定知道..。\n ");

       return 1;
}
int ask_tesin()
{
  object me;
  me=this_player();
  command("say 剑师龙铁心也是在当年大战后消失的英雄之一..不过我确定他在魔域。 ");
  return 1;
}

int ask_fu()
{
  object me=this_player();
  if (me->query("quests/sunfire")==1)
  command ("say 你不是已经会了?");
  else if (me->query("quests/yan")<5)
  {
  command ("say 连阳七绝斩..乃是我囚困于焚天魔域时领悟出来的...。");
  command ("say 如果你想学..你得通过仙剑峡谷,并通试练者武试..你才有资格跟我学连阳七绝斩。");
  if (me->query("quests/yan")<1) me->set("quests/yan",1);
  }
  else if(me->query("quests/yan")==5)
  {
  command ("say 既然你都得到认证了...那我就把连阳七绝斩的要领跟你说...。");
  message("system",HIY"风青云开始将连阳七绝斩的基本功夫传授于"+this_player()->name()+"。\n"NOR,users());
  message_vision("$N随着风青云的指导将连阳七绝斩演练了一遍。\n"NOR,me);
  command ("say 以后你可以利用perform sun_fire_sword.sunswordkee 在战斗中使出连阳七绝斩..。");
  me->set("quests/sunfire",1);
  }
}
int ask_shasword()
{
 object me=this_player();
 command ("say 仙剑峡谷乃仙剑祖传练剑之处..由于极为隐密..因此已经渐被淡忘.。");
 command ("say 而我也仅仅记得他在蜀山附近...确实地点..你得自行前往蜀山寻找。");
 me->set_temp("quests/yan",1);

}

int ask_array()
{
object me=this_player();
if(!me->query("quests/sblood")) return 1;
else
{
command("say 天门奇阵阿....");
command("say 我在当初我到魔域就是为了要找天门奇阵的下落,就在我发现线索时,中了焚天魔王的陷阱，才会被焚天魔王所擒，至于天门奇阵真正的下落，我想..你可以自行前往魔域调查..但是据说要进入此阵需要许多的准备，非常人所能进入的。");
}
}
int ask_roger()
{
command("say 李梦枕....这个人跟仙剑派似乎有极大的渊源..我曾在魔域遇见过他..此人乃是武林一大传奇，据说他是金风细雨楼大楼主，但是看他的打扮，似乎已经再外流浪许久了...");
return 1;
}
