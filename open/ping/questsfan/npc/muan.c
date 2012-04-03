inherit NPC;     //¶Î´¨ÔÀ
#include <ansi.h>
#include </open/open.h>
inherit F_MASTER;
int exert_sunforce();

void create()
{
  set_name("¶Î´¨ÔÀ",({"muan duan","muan","duan"}));
  set("long","¶Î´¨ÔÀ¼´ÊÇ¶ÎÊÏµÕÏµ×åÈËÖÐ×îÄêÇáÓÐÎªµÄ×å³¤¡£ËûÂÊÁìÊÀ\n"
              +"´úÊÖÊØ»¤ºç¾§¿óµÄ×åÈË£¬¶É¹ýÐí¶àÄêµÄËêÔÂ¡¢¾¡ÐÄ¾¡Á¦£¬\n"
            +"¶øÇÒÇ××ÔÕòÊØ¾§¹È×îºóµÄ¹Ø¿¨¡£\n");
  set("gender","ÄÐÐÔ"); 
  set("class","scholar");
  set("nickname",""+HIC+"»ÃÓî²ßÊ¿"+NOR+"");
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
  set("env/Áù¾ø½£","YES");
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
            ""+HIC+"¶Î´¨ÔÀ×ÔÑÔ×ÔÓïµÄµÀ: Ïëµ½ÎÒ³öÈÎ×å³¤Ê±ÔøÎª±¾×å²ÆÔ´·³ÄÕ£¬Òò¶øÒ»Í·ÔÔÈëÑÐ¾¿¡¢ÊÕ¼¯ÌìÏÂ¼äµÄ±¦Îï¡£"+NOR+"\n"+
""+HIC+"µ«ÊÇÎÒÍòÍòÏë²»µ½ËùÎ½µÄ£¢"HIR"±¦Îï"HIC"¡åÒ²ÉîÉîµÄÎüÒýÎÒ£¬º¦ÎÒ×Ô½ñ»¹ÎÞ·¨×Ô°Î¡£"NOR"\n",
            ""+HIC+"¶Î´¨ÔÀËµ: ×î½üÎÒÔÚ²Ø¾­¸óÕÒµ½Ò»±¾£¢"HIB"¿ö¹ÅÆæÎï´óÈ«"HIC"¡å£¬ËüÕæÊÇÒ»±¾ÆæÊéÑ½£¡"+NOR+"\n",
            ""+HIY+"¶Î´¨ÔÀÌ¾µÀ: ÕæÏë¼ûÊ¶Ò»ÏÂÄÇ±¾ÊéÖÐ¼ÇÔØ£¬ÓÚÊ¢ÌÆÊ±ÆÚ³ö×ÔÃû¼ÒÖ®ÊÖµÄÄÇ×ù£¢"HIR"Ë«÷è÷ë»ðÁðÁ§"HIY"¡åÑ½£¡"+NOR+"\n",
               }));
setup();
  add_money("gold",50);
  carry_object("/open/ping/obj/cloud_fan");
    carry_object(PING_OBJ"neck0")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_armor")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_cloak")->wear();
  create_family("¶Î¼Ò",10,"×å³¤");
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
        tell_object(users(),"\n\t[0;1m¡õ[1my[1;36m¡õ[1mj[1m¡õ[1mP[1m¡õ[1m@[1m¡õ[1m¡õ[1m¡õ[1mP[1m¡õ[1m¡õ[1m¡õ[1m_[1m [1m [0m[0;1;36m¡õ[1m¡õ[1m¡õ[1mn[1m¡õ[1m¡õ[1m¡õ[1mW[1m¡õ[1mE[1m¡õ[1md[1m¡õ[1m¡õ[0m\n\t\t[0;1;36m¡õ[1m¡õ[1m¡õ[1mJ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mE[1m¡õ[1mU[1m¡õ[1m¡õ[1m [1m [1m¡õ[1mS[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mz[0m\n"+
        "\n\t[0;1m¡õ[1mQ[1m¡õ[1m¡õ[1m¡õ[1mq[1m¡õ[1mt[1m¡õ[1m¡õ[1m¡õ[1m@[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mu[1m,[1m [0m[0;1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m"+HIR+""+winner->query("name")+"[0;1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m\n\t[0;1m¡õ[1mu[1m¡õ[1mO[1;31m¡õ[1m¡õ[0m[0;1;31m¡õ[1m¡õ[1m¡õ[1mt[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m\n");
        tell_object(users(),"\n\n[36mÄÏ·½Ìì¿Õ»­¹ýÒ»µÀ[0;1;5m¡õ[1;5my[1;5m¡õ[1;5mP[0m¡£\n\n\t[0;1;31m¡õ[1mu[1;35m¡õ[0m[0;1;35m¡õ[1m¡õ[1mv[1m¡õ[1mP[1;31m¡õ[1mv[0m\n\n");
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
          command("say Ì«ºÃÁË, ÕâÊÇËÍÎÒµÄÂð£¿Ð»ÁË¡£");
         if( me->query("family/family_name") == "¶Î¼Ò" && me->query("questsfan/quest_step") == 5 )
          {
           command("say ¶Î´¨ÔÀÉñÇéºÍÔÃµÄ¶ÔÄãËµµÀ:¸óÏÂ¾¹ËÍÎÒÈç´Ë¹óÖØÖ®Îï£¬¼ÈÈ»¸óÏÂÊÇÒªÀ´È¡ºç¾§
                          Ê¯µÄ£¬ÄÇ±ãÊÇÒÑ¾­Í¨¹ýÖØÖØ¿¼Ñé£¬Ëü¾ÍÔÚÉ½¶´ÖÐÄúÇë±ã°É!!!\n");
            me->set("questsfan/quest_step", 6);
          }
          destruct(obj);
        }
        else
        command("? "+getuid(me));
        return 1;
}

