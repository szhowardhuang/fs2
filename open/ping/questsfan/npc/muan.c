inherit NPC;     //段川岳
#include <ansi.h>
#include </open/open.h>
inherit F_MASTER;
int exert_sunforce();

void create()
{
  set_name("段川岳",({"muan duan","muan","duan"}));
  set("long","段川岳即是段氏嫡系族人中最年轻有为的族长。他率领世\n"
              +"代手守护虹晶矿的族人，渡过许多年的岁月、尽心尽力，\n"
            +"而且亲自镇守晶谷最后的关卡。\n");
  set("gender","男性"); 
  set("class","scholar");
  set("nickname",""+HIC+"幻宇策士"+NOR+"");
  set("attitude","heroism");
  set("age",30);
  set("max_kee",9500);
  set("kee",9500);
  set("str",40);
  set("con",40);
  set("cps",40);
  set("cor",24);
  set("int",22);
  set("kar",40);
  set("bellicosity",5000);
  set("max_force",10000);
  set("force",10000);
  set("force_factor",10);
  set("combat_exp",10000000);
  set_skill("dodge",100);
  set_skill("move",100);
  set_skill("force",150);
  set_skill("parry",90);
  set_skill("unarmed",90);
  set_skill("stabber",120);
  set_skill("literate",120);
  set_skill("linpo-steps",100);
  set_skill("six-fingers",100);
  set_skill("sunforce",150);
  map_skill("unarmed","six-fingers");
  map_skill("parry","six-fingers");
  map_skill("stabber","six-fingers");
  map_skill("move","linpo-steps");
  map_skill("dodge","linpo-steps");
  map_skill("force","sunforce");
  set("env/六绝剑","YES");
  set("marks/sun-finger",1);
  set("marks/six_sp",3);
  set("functions/handwriting/level",100);
  set("chat_chance_combat",100);
  set("chat_msg_combat",({
     (:perform_action,"unarmed.handwriting":),
     (:this_object(),"exert_sunforce":),
     }));
  set("chat_chance",10);
  set("chat_msg", ({
            ""+HIC+"段川岳自言自语的道: 想到我出任族长时曾为本族财源烦恼，因而一头栽入研究、收集天下间的宝物。"+NOR+"\n"+
""+HIC+"但是我万万想不到所谓的＂"HIR"宝物"HIC"″也深深的吸引我，害我自今还无法自拔。"NOR"\n",
            ""+HIC+"段川岳说: 最近我在藏经阁找到一本＂"HIB"况古奇物大全"HIC"″，它真是一本奇书呀！"+NOR+"\n",
            ""+HIY+"段川岳叹道: 真想见识一下那本书中记载，于盛唐时期出自名家之手的那座＂"HIR"双麒麟火琉璃"HIY"″呀！"+NOR+"\n",
               }));
setup();
  add_money("gold",50);
  carry_object("/open/ping/obj/cloud_fan");
    carry_object(PING_OBJ"neck0")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_armor")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_cloak")->wear();
  create_family("段家",10,"族长");
}
int accept_kill(object who)
{
  command("perform unarmed.handwriting");
  command("wield fan");
  command("exert sun-finger");
  command("wield finger");
  kill_ob(who);
  return 1;
}
int accept_fight(object who)
{
  command("perform unarmed.handwriting");
  command("wield fan");
  command("exert sun-finger");
  command("wield finger");
  fight_ob(who);
  return 1;
}
void die()
{
        object winner = query_temp("last_damage_from");
//        if(!wizardp(winner)){;:
        tell_object(users(),"\n\t[0;1m□[1my[1;36m□[1mj[1m□[1mP[1m□[1m@[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1m_[1m [1m [0m[0;1;36m□[1m□[1m□[1mn[1m□[1m□[1m□[1mW[1m□[1mE[1m□[1md[1m□[1m□[0m\n\t\t[0;1;36m□[1m□[1m□[1mJ[1m□[1m□[1m□[1m□[1m□[1mE[1m□[1mU[1m□[1m□[1m [1m [1m□[1mS[1m□[1m□[1m□[1m□[1m□[1mo[1m□[1m□[1m□[1m□[1m□[1m□[1;37m□[1mz[0m\n"+
        "\n\t[0;1m□[1mQ[1m□[1m□[1m□[1mq[1m□[1mt[1m□[1m□[1m□[1m@[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mu[1m,[1m [0m[0;1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[0m"+HIR+""+winner->query("name")+"[0;1m□[1m□[1m□[1m□[0m\n\t[0;1m□[1mu[1m□[1mO[1;31m□[1m□[0m[0;1;31m□[1m□[1m□[1mt[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mH[1m□[1m□[1m□[1m□[0m\n");
        tell_object(users(),"\n\n[36m南方天空画过一道[0;1;5m□[1;5my[1;5m□[1;5mP[0m。\n\n\t[0;1;31m□[1mu[1;35m□[0m[0;1;35m□[1m□[1mv[1m□[1mP[1;31m□[1mv[0m\n\n");
//       }
        :: die();
}
void init()
{
        add_action("do_answer","answer");
        set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}


int accept_object(object me, object obj)
{
        if( obj->query("id") == "fire colored glaze" )
        {
          command("pat "+getuid(me));
          command("say 太好了, 这是送我的吗？谢了。");
         if( me->query("family/family_name") == "段家" && me->query("questsfan/quest_step") == 5 )
          {
           command("say 段川岳神情和悦的对你说道:阁下竟送我如此贵重之物，既然阁下是要来取虹晶
                          石的，那便是已经通过重重考验，它就在山洞中您请便吧!!!\n");
            me->set("questsfan/quest_step", 6);
          }
          destruct(obj);
        }
        else
        command("? "+getuid(me));
        return 1;
}

