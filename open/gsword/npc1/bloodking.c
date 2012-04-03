inherit NPC;
#include <ansi.h>
#include "/open/open.h"
void create()
{
set_name(HBRED"血魔"NOR,({"bloodking","king"}));
set("long","天魔转世..不过在先前与由仙剑派祖师逍遥子所率领的武林同盟大战
失利后..就消失武林,如今已卷土重来.由其眼中..可明显的看出其对
仙剑派的恨意似乎无穷无尽..\n");
        set("gender","男性");
        set("class","swordsman");
            set("family/family_name","仙剑派");
            set("combat_exp",20000000);
            set("attitude","heroism");
            set("dragon-sword",1);
            set("bellicosity", 100000);
        set("age",200);
        set("title",HIR"万魔至尊"NOR);
            set("str", 70);
            set("cor", 50);
            set("cps", 70);
            set("con", 60);
            set("int", 30);
            set("max_gin", 50000);
            set("gin",60000);
            set("max_kee", 80000);
            set("kee",100000);
            set("s_kee",10000);
            set("max_s_kee",10000);
            set("force",200000);
            set("max_force",100000);
            set_skill("literate",80);
            set_skill("magic",100);
            set_skill("spells",50);
            set_skill("blood_sword",200);
            set_skill("fireforce",300);
        set_skill("move",120);
        set_skill("force",300);
        set_skill("dodge",220);
        set_skill("parry",220);
        set_skill("ghost-steps",220);
        set_skill("sword",170);

        map_skill("dodge","ghost-steps");
        map_skill("move","ghost-steps");
        map_skill("force","fireforce");
        map_skill("sword","blood_sword");
        map_skill("parry","blood_sword");
        set("force_factor",50);
        set("inquiry",([
  "血魔" : "就是我ㄚ..",
  "逍遥子" : "可恶得逍遥子…当初就是他..害我惨遭封印",
  "剑法" : "就是我所创的剑招..你在这拿我的笔记(take bloodbook)去读吧.",
]));
        setup();
 carry_object("/open/gsword/obj1/sadsword")->wield();
 carry_object("/open/gsword/obj1/bloodring.c")->wear();
        add_money("gold",5);
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
        command("wear all");
}

