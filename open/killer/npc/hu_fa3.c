// 这是小渡的标准NPC
inherit NPC;

string to_man();
string to_ask();

void create()
{
  object ob1;

  set_name("渡永天",({"dou_tan","dou","tan"}));
  set("title","黄龙组组长");
  set("long","此人乃杀手的幕后功臣，杀手有一大堆高手是由此人锻炼出来");
  set("gender","男性");
  set("combat_exp",1000000); 
  set("attitude","friendly");
  set("force_factor",10);
  set("age",50);
  set("class","killer");

  set("str", 56);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("con", 55);
  set("kar", 20);

  set("max_gin",200);
  set("eff_gin",200);
  set("gin",200);
  set("max_kee",2200);
  set("eff_kee",2200);
  set("kee",2200);
  set("max_sen",200);
  set("eff_sen",200);
  set("sen",200);  
  set("force",1500);
  set("max_force",1500);
  set("bellicosity",300);

  set_skill("throwing",80);
  set_skill("parry",80);
  set_skill("dodge",80);
  set_skill("shade-steps",80);
  set_skill("rain-throwing",75);
  map_skill("parry","rain-throwing");
  map_skill("throwing","rain-throwing");
  map_skill("dodge","shade-steps");
set("inquiry",([
"追杀者" : (: to_man :),
"欧阳不空" : (: to_ask :),
]));
  setup();
  ob1=carry_object("/open/killer/obj/lustar");
  ob1->add_amount(200);
  ob1->wield();
  carry_object("/open/killer/weapon/k_arm3.c")->wear();
  carry_object("/open/killer/weapon/k_belt2.c")->wear();
  carry_object("/open/killer/weapon/k_cloth2.c")->wear();
  add_money("gold",20);
}

string to_man()
{
  object ob,me;
 
 me=this_player();

 if (me->query_temp("mission3") != 1)
   return "说什么？我不懂耶";

 tell_object(me,"你想要追杀那个人呀。。。。。嗯。。。。\n");
 tell_object(me,"好吧！我就告诉你，那个人就是无影掌--叶双\n");
 tell_object(me,"此人武功非常高强，如果你功力不够高，最好不要去找死\n");
 tell_object(me,"这张纸你拿去，顺着谜题去找，在某处调查可以找到人指示你\n");
 if (me->query_temp("mission3") != 2)
{
 ob=new("/open/killer/obj/paper1.c");
 ob->move(me);
}
 me->set_temp("mission3",2);
 return "小心一点呀！提示的地点是由此处开始算";
}

string to_ask()
{
  object ob,me;
 
 me=this_player();
 if (me->query_temp("mission3") != 5)
   return "$N说什么？我不懂耶";
 tell_object(me,"想不到居然被你找到欧阳不空！！\n");
 tell_object(me,"好吧！我就是无影掌--叶双，好！受死吧！\n");
 set_name("叶双",({"yar_sha","yar","sha"}));
 set("title","无影掌");
 set("combat_exp",700000); 
 ob=new("/open/killer/obj/yar_head.c");
 ob->move(this_object());
 me->set_temp("mission3",6);
 this_object()->kill_ob(me);
 return "接招！！！";
}
