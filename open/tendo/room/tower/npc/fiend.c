#include <ansi.h>
#include <combat.h>
inherit NPC;
#define bell_big 400
#define bell_small 200
#define SPELLLVL 100
#define MANACOST 150
#define INVCOST 18
int special_att ();
object room2;
void create()
{
        set("title",RED"⁄§µÓ÷Æ◊"NOR);
        set_name("⁄§µÓ–ﬁ¬ﬁ",({"fiend"}));
        set("max_gin",3000);
        set("gin",3000);
        set("race","“∞ ﬁ");
        set("age",1200);
        set("str", 100);
        set("max_kee", 2400);
        set("kee", 2400);
        set("limbs", ({ "Õ∑≤ø", "…ÌÃÂ", "«∞Ω≈" , "∫ÛΩ≈" , "Œ≤∞Õ" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",500000);
        set_temp("apply/armor",90);
        set_temp("apply/attack", 90);
        set("force_factor",12);
        set("bellicosity",2000);
        set("max_sen",3000);
        set("sen",3000);
        set("max_atman",2500);
        set("atman",2500);
        set("max_mana",2000);
        set("mana",2000);
        set("max_force",3000);
        set("force",3000);
        set("cor", 40);
        set("cps", 40);

        set("chat_chance_combat",45);
        set ("chat_msg_combat", ({(: special_att :)}));

        command("wield all");
        command("wear all");
        set_skill("hell-evil",90);
        map_skill("parry","hell-evil");
        set("unarmed",90);
        map_skill("unarmed","hell-evil");
        set_skill("dodge",90);
        set_skill("fly-steps", 70);
        map_skill("dodge","fly-steps");
        set_skill("parry",90);
        setup();
        carry_object ("/open/tendo/room/tower/obj/ring")->wield ();
        carry_object ("/open/tendo/room/tower/obj/neck")->wear ();
        add_money("gold",20);
        carry_object("/open/tendo/room/tower/obj/boots")->wear();
        carry_object("/open/tendo/room/tower/obj/cloth")->wear();
        carry_object("/open/tendo/room/tower/obj/hat")->wear();
        carry_object("/open/tendo/room/tower/obj/hands")->wear();
        carry_object("/open/tendo/room/tower/obj/belt")->wear();
        carry_object("/open/tendo/room/tower/obj/wrists")->wear();
        carry_object("/open/tendo/room/tower/obj/shield")->wear();
        carry_object("/open/tendo/room/tower/obj/legging")->wear();
        carry_object("/open/tendo/room/tower/obj/book");

}

int accept_kill(object ob)
{
        int i;
        object ob1,hu_fa;
        string place;
        ob1 = this_object();

        if( !present("hu-fa", environment(ob)) )
        {
        tell_room(environment(ob),HIW"\nÕª»ª£°≥Â≥ˆ¡ΩŒªª§∑®!!\n\n"NOR);
        for(i=0;i<2;i++)
         {
         hu_fa = new("/open/tendo/room/tower/npc/hu_fa");
         hu_fa->move(environment(ob));
         hu_fa->kill_ob(this_player());
         }
        }
        write("[1;32mª§∑®◊›…Ì∑…∆Àπ˝¿¥Ω–µ¿£∫ ƒÀ¿±£ª§–ﬁ¬ﬁ£°£°[0m\n");
        return 1;
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
"          £≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  “ª   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIY"—˝ ƒß æ€ ∂¶"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁ…Ì–ŒŸø∂¯Ã⁄∑…»˝’…,¡Ëø’≈¸≥ˆ“ª"NOR"
    "HIW"π…’∆æ¢,√‡√‡’∆”∞,»ÁΩ≠∫”»±µÃÀ∆,±©–∫∂¯œ¬,’∆∑Á»Áº§¡˜"NOR"
                  "HIW"∞„µÿœÚƒ„∏Ùø’≈¸¿¥!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  ∂˛   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIR"ƒß –‘ øÒ ∑¢"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁ¬˙Õ∑“¯∑¢”≠∑Á»ÁÃŒ,À´ƒøÕ¬π‚»ÁæÊ,"NOR"
    "HIW"∫ˆ»ªÀ´±€∂∂ŒË,ª√ªØ≥…«ß∞ŸÃı ÷±€,√ø“ªÃı ÷±€∆À≥ˆ“ª∞„ªÎ"NOR"
             "HIW"–€µƒ’∆∑Á,¬˝ÃÏµƒ’∆”∞œÚƒ„æÌ≈¸∂¯¿¥!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  »˝   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIW"πÌ ∆¯ π· ƒ‘"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁÀ´ ÷±©≥§£¨¡≥≤ø«‡Àø±©¬∂£¨≈®¡“µƒ∂Ò"NOR"
    "HIW"≥Ù¥”À´’∆Õ∏≥ˆ£¨÷ªº˚⁄§µÓ–ﬁ¬ﬁÀ´ ÷≤ªÕ£º≤ŒË£¨æ¢∆¯÷–º–¥¯◊≈"NOR"
  "HIW"¡Ó»ÀŒ≈÷Æ”˚≈ªµƒ∂æ∆¯, πµ√ƒ„ ‹µΩ∂æ∆¯µƒ”∞œÏ£¨ ‹µΩ≤ª«·µƒ…À∫¶!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  Àƒ   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIC"˜Œ ˜» ˜Õ ˜À"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁ“ª…˘¡˙“˜∞„µƒ≥§–•,¥Ï…Ì∑…Ã⁄,…Ì–Œµ¥"NOR"
    "HIW"ø’ªÿŒË,“ª¡¨¥Æ∂Ø◊˜‘⁄Õ¨“ª ØªµÁπ‚÷Æº‰ÕÍ≥…,◊‘≤ªÕ¨µƒ∑ΩœÚ,"NOR"
  "HIW"≤ªÕ¨µƒΩ«∂»,ƒ«Õ»ÁÀ∆¿˜πÌƒß◊¶∞„µƒ’∆”∞,œÚƒ„πÓ“Ï∆Êæ¯µƒ∑…≈¸∂¯÷¡!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  ŒÂ   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "MAG"πÌ ˜» ∞› ‘¬"HIB"  °Ø°´"NOR"
          "HIW"÷ªº˚⁄§µÓ–ﬁ¬ﬁ…Ì–Œ“ªπ™£¨À´’∆«∞≈¸£¨“ªµ¿∞Î‘¬"NOR"
    "HIW"–Œµƒæ¢∆¯√Õ»ªœÚ«∞”ø»•£¨–€ªÎµƒæ¢∆¯£¨πŒµ√µÿ√Ê»Á∑……≥◊ﬂ Ø∞„"NOR"
                       "HIW"µÿœÚƒ„øÒœÆ∂¯»•!!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  ¡˘   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIY"’∆ ≤ª »– —™"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁÀ´’∆ªØ≥…«ß∞Ÿ’∆”∞,’∆”∞”÷ƒ˝≥…“ªπ…æ™"NOR"
              "HIW"ÃÏ∂Ø∆«µƒæ¢∆¯,≥ØœÚ∆∆∑Á…˘¿¥¥¶≈¸»•!!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  ∆ﬂ   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIC"—˝ πÌ ƒ™ ≤‚"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁ«¸ÃÂπ≠…Ì£¨À´’∆ΩÙÃ˘µÿ√Ê£¨»´…Ì¡˝’÷‘⁄"NOR"
    "HIW"“ª∆¨¿∂π‚÷–£¨µÿ√ÊÕ»Á≤®ÃŒ∞„∏°∂Ø£¨ÀÊ◊≈–Óª˝µƒƒ⁄æ¢£¨¿∂π‚≤ª∂œ"NOR"
   "HIW"‘ˆº”£¨÷ªº˚⁄§µÓ–ﬁ¬ﬁÕª»ªΩ´À´’∆“ª∫œ£¨“ªµ¿∫ß»À¿∂º˝œÚƒ„º≤…‰∂¯»•!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  ∞À   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIR"∑Á ƒß øÒ ◊™"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁ“‘∆¯π·»ÎÀ´◊¶ ,À´◊¶…¡≥ˆ“ª’Û“´ƒøΩπ‚,"NOR"
    "HIW"∆¯Ã· Æ∂˛≥… ,æ¢◊¢»´…Ì ,–Ó ∆◊º±∏ π≥ˆ◊Ó«ø◊Ó∞‘µ¿µƒ“ª Ω,ˆÆ ±"NOR"
  "HIW"øÒ¡˙ƒß∆¯º±ÀŸ–˝»∆⁄§µÓ–ﬁ¬ﬁ ,ŒﬁŸ±ƒß∆¯“Ú¥Àæ™∂ØÃÏµÿ÷Æ∆¯ ,ª•øπ±©≥ˆ"NOR"
 "HIW" ˝µ¿◊œµÁ¿◊π‚ ,⁄§µÓ–ﬁ¬ﬁ∫ˆ»ªœ÷…Ì”⁄ƒ„«∞ ,∂‘ƒ„ π≥ˆ¡À Ø∆∆ÃÏæ™µƒ“ªª˜!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄  æ≈   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIY"πÌ ”∞ ÷ÿ ÷ÿ"HIB"  °Ø°´"NOR"
          "HIW"Œﬁ«ÓŒﬁæ°µƒæ¢¡¶”…Àƒ÷‹”ø»Î⁄§µÓ–ﬁ¬ﬁÃÂƒ⁄£¨÷ªº˚⁄§"NOR"
    "HIW"µÓ–ﬁ¬ﬁÀ´’∆≤ªÕ£◊ˆ◊≈œ∏Œ¢µƒ±‰ªØ£¨∑¬∑»Á∫⁄∂¥∞„£¨Ω´ÕÚŒÔ∂ºÕÃ ≥"NOR"
                 "HIW"—Õ√,∫ˆ»ªÀ´’∆ª˜œÚƒ„µƒ»´…Ì!"NOR"
           "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄   Æ   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIW"πÌ ∆¯ Œﬁ ÃŒ"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁøÒ∫“ª…˘,…œø’∆Ω…Ì≈≤∫Û»˝¥Á,◊Û ÷≈ƒµÿ,”“"NOR"
    "HIW" ÷π…∂Øƒ⁄æ¢,∆∆ÃÏ∂¯≥ˆ,’∆æ¢»Á…Ω,º§∆ŒﬁÃŒµƒ∆¯æ¢,º–◊≈¿◊ˆ™ÕÚæ‘"NOR"
                       "HIW"÷Æ ∆≥Øƒ„∂¯¿¥!!"NOR"
         "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄   Æ  “ª   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIC"πÌ —Ê ¡Ë ¿˜"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁ◊Û◊„∫·“∆,¥Ï—¸…Ú…Ì,µ•–‰“ª—Ô,À≤ ±øÒ∑Á∑˜"NOR"
    "HIW"∆, ≥æ…≥∑…—Ô,⁄§µÓ–ﬁ¬ﬁ≥√∑……≥◊ﬂ Ø÷Æº ,‘À∆—Ù∏’’Ê∆¯,…Ì–Œ“ª–˝,"NOR"
      "HIW"À´’∆ƒ⁄¬£,¥ﬂ∆“ªπ…¡Ë¿˜µƒ∆¯—Ê,≥Øƒ„µƒÃÏ¡È∏«¡¨–¯≈ƒ≥ˆ ˝’∆!"NOR"
         "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"µ⁄   Æ  ∂˛   Ω £≠£≠"NOR"
                  "HIB"°´°Æ  "HIR"»∫ ƒß ¬“ ŒË"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁ…¡…Ì∑¥’∆ª˜≥ˆ£¨“ªµ¿«‡…´π‚√¢¥”’∆÷–∑¢≥ˆ£¨"NOR"
    "HIW" πƒ„∑÷≤ª«Â…Ì‘⁄∫Œ∑Ω£¨÷ªº˚⁄§µÓ–ﬁ¬ﬁ…Ì–Œ“ª’π£¨ª√ªØ≥…«ßÕÚ…Ì”∞,"NOR"
 "HIW"…Ì”∞÷–º–¥¯◊≈≥¡÷ÿµƒ’∆æ¢œÚƒ„’÷œ¬,ƒ„’˝‘⁄≥Ÿ“…÷Æº “—±ªŒﬁ ˝’∆”∞À˘ª˜÷–!"NOR"
        "HIB"£≠£≠ "HIW"⁄§  µÓ  "HIR"æ¯  "HIY"—ß  "HIB"÷Æ  "HIC"÷’  "RED"º´  "MAG"√ÿ  "HIW"ºº "HIB"£≠£≠"NOR"
                  "HIB"°´°Æ  "MAG"«ß  ªÍ  √  …¢"HIB"  °Ø°´"NOR"
          "HIW"⁄§µÓ–ﬁ¬ﬁ÷ÿ÷ÿµƒ’∆,¡¨µ˛µƒ»≠,ÕÚæ˚÷Æ¡¶,ªÎ–€÷Æ∆¯,…∑"NOR"
    "HIW" ±ÃÏø’∑¬∑Õª»ª∫⁄∞µœ¬¿¥,—˝ƒß∑¬∑∂º¥”ƒπµÿ≈¿¡À∆¿¥,Õ∆…Ωµπ∫£,"NOR"
 "HIW"¥Ûµÿ∑≠πˆ,◊›∫·…œœ¬ø’º‰,Œ™’∆∑Á”Î’∆”∞À˘≤º,”–»Á√‡√‡∑…º µƒ¿˚»–ª˜œÚƒ„!!\n"+NOR,me);

  if (random (2) >= 1)
    {
      damage = 30+(victim->query ("max_kee") / 8);
   if (damage < 40)
        damage = 40;
      if (damage > 250)
        damage = 250;
message_vision(HIR"$N≤ª–“±ª’∆∑Á≈¸÷– , ∂Ÿ ±»´…Ì—™»Á»™”ø.\n"NOR,victim);
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
void unconcious()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),
HIB"\n⁄§µÓ–ﬁ¬ﬁ∞¶µ¿:
     "HIW"°Æ∞Ÿ ƒÍ  ¿  ¬ ø’ ª™ ¿Ô£¨“ª ∆¨ …Ì –ƒ ÀÆ ‘¬ º‰ ;\n                        
                      "HIY" \∂¿\ –Ì ÕÚ …Ω …Ó √‹ ¥¶£¨÷Á ≥§ ı√ ◊¯ —⁄ À… πÿ °£°Ø\n
"HIC"√ªœÎµΩŒ“⁄§µÓ–ﬁ¬ﬁ±ª¿ßŒÂ∞ŸƒÍ÷Æ∫Û£¨µ√“‘÷ÿº˚ÃÏ»’!!ΩÒ»’»¥∞‹”⁄"HIW""+winner->query("name")+""HIC"÷Æ ÷£°£°\n"NOR);
        :: unconcious();
}
void die()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),HIB"\n\n÷ªº˚ÃÏø’Œ⁄‘∆œ˚…¢£¨”÷ª÷∏¥¡À“ª∆¨œÈ∫Õ°£\n\n"NOR);

        :: die();
}

      


