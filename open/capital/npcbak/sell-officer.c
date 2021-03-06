// sell_officer.c
#include <ansi.h>
inherit NPC;
void create()
  {
        set("class", "officer");
        set_name("吴总管", ({ "officer wu", "officer"}) );
        set("title","朝庭命官");
        set("nickname", "龙图阁大学士");
        set("gender", "男性");
        set("age", 45);
        set("clan_kill",1);
        set("attitude", "hero");
        set("long",
        "吴总管为朝庭中龙图阁大学士，其学识为武林、文譠中第一等的人材\n");
       set("str", 48);
       set("cps", 40);
       set("per", 34);
       set("int", 38);
       set("kar", 16);
       set("fire_strike",1);
       set("super_fire",1);
       set("combat_exp",5000000);
       set("max_kee",9500);
       set("kee",12000);
       set("force"       , 6000);
       set("max_force"   , 7000);
       set("force_factor", 40);
       set("score"       , 200000);
       set("s_kee",400);
       set("env/狂击","YES");
       set("max_s_kee",1000);
       set("sec_kee","tiger");
       set("functions/kang_kee/level",100);
       set("max_gin",5000);
       set("max_sen",5000);
       set("gin",5000);
       set("sen",5000);
       set_skill("cure",40);
       set_skill("move",50);
       set_skill("unarmed", 120);
       set_skill("force",120);
       set_skill("parry",50);
       set_skill("dodge",50);
       set_skill("fire-kee",100);
        set_skill("literate",40);
        set_skill("henma-steps",100);
        set_skill("literate",30);
        set_skill("lungshan",100);
        set_skill("haoforce",100);
        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        set("chat_chance_combat",65);
        set("chat_msg_combat",({
            (: perform_action, "force.kang_kee"   :),
            (: "cmd god_kee"   :)
        }));
        setup();
        add_money("gold",20);
}

int accept_object(object who, object ob)
{
  object mid;
  string head_name;
  head_name=ob->query("id");
  switch(head_name)  {
  case "fire-king-head":
       command("cong");
       command("say 这是!!这是!!朝庭第一赏金的焚天魔王的人头!!!");
       command("say 大侠真是武功高强!!!!这是75000两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(7499);
       mid->move(who);
       break;
  case "dragon-head":
       command("cong");
       command("say 这是!!这是!!朝庭第一赏金的黄金甲龙的龙头!!!");
       command("say 大侠真是武功高强!!!!这是6500两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(649);
       mid->move(who);
       break;
  case "black-ghost-head":
       command("cong");
       command("say 这是!!这是!!魔界黑白双刹的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是6000两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(599);
       mid->move(who);
       break;
  case "white-ghost-head":
       command("cong");
       command("say 这是!!这是!!魔界黑白双刹的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是6000两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(599);
       mid->move(who);
       break;
  case "seven-dark-head":
       command("cong");
       command("say 这是!!这是!!魔界七魔将的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是5000两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(499);
       mid->move(who);
       break;
  case "mechoufen-head":
       command("cong");
       command("say 这是!!这是!!黑风双刹之梅超风的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是1300两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(129);
       mid->move(who);
       break;
  case "lin-head":
       command("cong");
       command("say 这是!!这是!!圣火教主之林宏升的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是7500两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(749);
       mid->move(who);
       break;
  case "sa-head":
       command("cong");
       command("say 这是!!这是!!大魔头独孤嵊的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是7500两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(749);
       mid->move(who);
       break;
  case "tiger-head":
       command("cong");
       command("say 这是!!这是!!平南城独角兽的兽头!!!\n");
       command("say 大侠真是武功高强!!!!这是10两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(0);
       mid->move(who);
       break;
  case "zhang-z-head":
       command("cong");
       command("say 这是!!这是!!风林三头目张继的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是400两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(39);
       mid->move(who);
       break;
  case "liu-head":
       command("cong");
       command("say 这是!!这是!!风林二头目刘信的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是600两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(59);
       mid->move(who);
       break;
  case "ra-head":
       command("cong");
       command("say 这是!!这是!!风林大头目雷霸的人头!!!\n");
       command("say 大侠真是武功高强!!!!这是2000两的赏金请收下!!!\n");
       mid=new("/obj/money/thousand-cash");
       mid->add_amount(199);
       mid->move(who);
       break;
  default :
       command("say 不想活了呀!!竟欺骗朝庭命官呀!!!给我滚!!!!\n");
       break;
  }
       destruct(ob);
       return 1;
}
