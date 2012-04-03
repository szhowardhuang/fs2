#include <ansi.h>
#include <combat.h>
inherit NPC;
string magic1();
string magic2();
#define bell_big 400
#define bell_small 200
#define SPELLLVL 100
#define MANACOST 150
#define INVCOST 18
int special_att ();
object room2;

void create()
{
     set_name("’ÚÀ˛√˜Õı",({"tower king","king"}));
     set("title",HIW"ÃÏΩÁ÷Æ…Ò"NOR);
     set("long","À˚∑Ó√¸œ¬∑≤’Ú ÿÀ¯—˝À˛.........\n");
     set("gender","ƒ––‘");
     set("class","taoist");
     set("age",1200);
     set("str",70);
     set("kar",70);
     set("per",50);
     set("cps",70);
     set("cor",70);
     set("combat_exp",500000);
     set("spi",70);
     set("int",70);
     set("max_kee",1800);
     set("kee",1800);
     set("max_sen",3000);
     set("sen",3000);
     set("max_force",2000);
     set("force",2000);
     set("gin",2000);
     set("max_mana",2500);
     set("mana",2500);
     set("max_atman",2500);
     set("atman",2500);
     set_skill("force",80);
     set_skill("gforce",80);
     map_skill("force","gforce");
     set_skill("dodge",80);
     set_skill("g-steps",80);
     map_skill("dodge","g-steps");
     set_skill("magic",80);
     set_skill("gmagic",80);
     map_skill("magic","gmagic");
     set_skill("whip",90);
     set_skill("gwhip",100);
     map_skill("whip","gwhip");
     set_skill("parry",80);
     map_skill("parry","gwhip");
     set_skill("spells",80);
     set_skill("necromancy",80);
     map_skill("spells","necromancy");
     set("force_factor",10);
     set("chat_chance_combat",50);
     set("chat_msg_combat", ({
     (: special_att :),
     (: magic1 :),
     (: magic2 :),

}));
setup();
     carry_object("/open/tendo/room/tower/obj/kwhisk")->wield();
     carry_object("/open/tendo/room/tower/obj/karmband")->wear();
     carry_object("/open/tendo/room/tower/obj/kbelt")->wear();
     carry_object("/open/tendo/room/tower/obj/kcape")->wear();
     carry_object("/open/tendo/room/tower/obj/kcloth")->wear();
     carry_object("/open/tendo/room/tower/obj/khat")->wear();
     carry_object("/open/tendo/room/tower/obj/klegging")->wear();
     add_money("gold",10);
     command("wield all");
     command("wield all");
}
string magic1()
{
 if (this_object ()->query ("sen") >30) {
 "/daemon/class/taoist/necromancy/invocation"->cast_soldier(this_object(),"lumob");
}
return "\n";
}
string magic2()
{
if(random(2))
command("cast feeblebolt");
else command("cast missible");
return "\n";
}
int spell ()
{
  return SPELLLVL;
}

int manacost ()
{
  return MANACOST;
}

int invcost ()
{
  return INVCOST;
}

int special_att ()
{
  object me = this_object ();
  object *enemy = query_enemy (), victim;
  int i = sizeof (enemy), damage;
  victim = enemy[random(i)];
      message_vision(HIB+
"              ’ÚÀ˛√˜Õı≈≠∆¯øÒÃ·£¨≤ªπÀ…Ì…œµƒ…Àø⁄£¨≤ª∂œµÿΩ´ƒ⁄¡¶‘À÷¡ Æ∂˛≥…°£\n        
                          "HIR"’ÚÀ˛√˜Õı…Ì…œ∑¢≥ˆ“ªπ…«ø¥Ûµƒ…±“‚\n
                 "HIY"’ÚÀ˛√˜Õıµƒ»´…Ìø™ ºæ€∆«ø¡“µƒ"HIW"∫Æ±˘"HIW"”Î"HIR"¡“ª"HIY"¡Ωµ¿ª∑…Ì∆¯æ¢£¨\n
                      "HIW"°´ ¡Ωµ¿∆¯æ¢‘¥‘¥≤ª∂œµƒœÚ ÷…œƒ˝æ€£° °´\n
                              "HIY"Ÿøµÿ’ÚÀ˛√˜Õı¥Û∫»“ª…˘\n
                 "HIY"◊Û ÷ π≥ˆ“ª’–"RED"ÃÏ È"MAG"æ¯—ß"HIY"÷–÷Æ÷’º´∞¬“Â - -"HIW"∫Æ ±˘ æ¢"HIY"£≠-\n
                 "HIC"”“ ÷“ª∑≠ π≥ˆ"RED"ÃÏ È"MAG"æ¯—ß"HIC"÷–÷ÆŒ‰—ß√ÿºº °´°´"HIR"¡“ ª æ¢"HIC"°´°´ \n°°
                   "HIB"÷ªº˚∫Æ±˘”Î¡“ª¡Ωµ¿∆¯æ¢»ÁøÒ∑Á±©”Í∞„µÿª˜œÚ$N\n
                        "HIW"¥ÀƒÀÃÏ È÷Æ≤ª√ÿ÷Æ¥´"HIC" °Æ"HIW"∫Æ±˘"HIR"¡“ª"HIW"æ¢"HIC"°Ø\n"+NOR,me);

  if (random (2) >= 1)
    {
      damage = 30+(victim->query ("max_kee") / 8);
   if (damage < 40)
        damage = 40;
      if (damage > 250)
        damage = 250;
message_vision(HIR"$N…¡∂„≤ªº∞,±ª∫Æ±˘¡“ª¡Ωµ¿∆¯æ¢Õ∏ÃÂ∂¯π˝,»´…Ì…œœ¬±ª¡“ªº∞∫Æ±˘∞¸Œß◊≈,≤ªÕ£µƒÀª∫!\n"NOR,victim);
      victim->apply_condition ("bleeding", random (i * i));
      victim->receive_damage ("kee", damage, me);
      COMBAT_D->report_status (victim, 0);
    }
  else
    {
message_vision(HIW"÷ªø…œß¿Î$N≤Ó¡À“ªµ„, ≈¸µΩµÿ…œ, ∫‰µƒ“ª…˘æﬁœÏ, µÿ∆§∂Ÿ ±¡—¡Àø™¿¥.\n"NOR,victim);
    }
  start_busy (1);
  return 1;
}
 int accept_fight(object me)
 {
  if((int)me->query("combat_exp")<=380000)
  {
  command("say ∏Ûœ¬ªπ√ª”– µ¡¶”ÎŒ“Ωœ¡ø..");
  return 0;
  }
  command("say «Î÷∏ΩÃ£°");
  return 1;
 }

int accept_kill(object ob)
{
	message_vision( HIR "$n π≥ˆ[1;37mÃÏΩÁæ¯—ß[0m÷Æ∂®…Ì ı π$N≤ªƒ‹∂ØµØ°£\n",this_player(),this_object());
	set("no_sword",1);
	this_player()->start_busy(3);
	return 1;
}
void die()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),
HIW"\n’ÚÀ˛√˜Õı— œ¬◊Ó∫Û“ªø⁄∆¯∞¶µ¿:\n\n
                 "HIR"°´ °´ °´ÃÏ   ∞°°´ °´ °´Œ“°´µƒ°´»Œ°´ŒÒ°´—Ω°´\n
          "HIC"ΩÒ»’æπ»ªª·∂œÀÕ”⁄"HIW""+winner->query("name")+""HIC"÷Æ ÷£°£°\n"NOR);


        :: die();
}

      


