
inherit NPC;
string ask_tesin();
void create()
{
        set_name("地精", ({ "sprite" }) );
        set("title","魔界村居民");
        set("race","野兽");
	set("gender", "雄性" );
        set("age",132);
	set("long","他是魔界村的居民, 相传是天地精气生成的魔物.\n");
	set("combat_exp",1000);
	set("attitude", "peaceful");
        set("chat_chance", 25);
        set("chat_msg", ({
              (: this_object(),"random_move" :),
             "地精抬起了头, 用大大的眼睛四周张望着.\n",
             "地精轻声的对你呢喃了几句话, 可是你听不懂.\n",
             "地精张嘴微笑, 露出尖锐的牙齿.\n",
        }) );
        set("inquiry",([
         ]));
	set_skill("parry", 20);
        set_skill("dodge", 20);
	setup();
        add_money("coin", 50);
         	
}
 string ask_tesin()
 {
if (!this_player()->query_temp("find_tesin3"))
  {
  this_player()->set_temp("find_tesin4",1);
  return ("龙铁心?他早在十几年前..就到炎龙谷去了.");
  }
else
  {
  this_player()->set_temp("find_tesin4",2);
  return ("龙铁心?他早在十几年前..就到炎龙谷去了.");
  }

}
