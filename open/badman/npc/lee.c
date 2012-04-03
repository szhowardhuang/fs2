// lee.c by oda

#include </open/open.h>

inherit NPC;

void create()
{
	set_name("Àî´ó×ì", ({ "lee da tswei", "lee", "da", "tswei" }) );
	set("nickname", "²»³ÔÈËÍ·");
	set("class", "bandit");
	set("attitude", "badman");
	set("gender", "ÄĞĞÔ");
	set("age", 40);
	set("combat_exp", 800000);
	set("long", "Äã¿´µ½Ò»¸öÏàÃ²²»·²µÄÄĞ×Ó£¬µ«ÊÇËû¾¹ÊÇ½­ºşÉÏÈËÈËÎÅÖ®É«±äµÄ¿Ö²ÀÄ§Í·\n£¬´«ËµËûµ±ÄêÔøÇ×ÊÖÉ±ÁË×Ô¼ºÈ«¼ÒÆŞĞ¡²¢³ÔÁËËûÃÇ¡£ÈËÃÇ³ÆËûÎª¡®²»³ÔÈË\nÍ·¡¯ÕıÊÇÏ·³ÆËû³ıÁËÈËÍ·ÒÔÍâÊ²Ã´¶¼³Ô£¬µ«ÊÇÊÂÊµÉÏËûºİÆğÀ´¿ÉÊÇÁ¬ÈËÍ·\n¶¼²»·Å¹ıµÄ¡£\n");

	set("str", 32);
	set("cor", 29);
	set("int", 22);
	set("spi", 20);
	set("cps", 22);
	set("con", 30);
	set("per", 32);
	set("max_force", 1200);
	set("force", 1200);
	set("force_factor", 10);
	set("max_gin", 1000);
	set("max_kee", 2300);
	set("max_sen", 1000);

	set_skill("badforce", 65);
	set_skill("badstrike", 85);
	set_skill("dodge", 40);
	set_skill("force", 55);
	set_skill("ghost-steps", 60);
	set_skill("move", 50);
	set_skill("parry", 60);
	set_skill("unarmed", 75);
	map_skill("force", "badforce");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");
	map_skill("unarmed", "badstrike");
	map_skill("parry", "badstrike");
	set("functions/evil-blade/level", 25);

	set("chat_chance_combat", 25);
	set("chat_msg_combat", ({
	(: perform_action, "unarmed.evil-blade" :),
	}));

	setup();
	add_money("gold", 10);
}

int accept_object(object who, object ob)
{
  string name, str;

  if (ob->query("name") == "¸¯ÀÃµÄÊ¬Ìå") {
  command("say Ğ¡´ô×Ó ,Ê¬Ìå¶¼ÀÃµôÁË ,ÒªÔõÃ´³Ô ?");
  return 1;
  }


  else if (ob->query("name") == "ÑîĞÄæÃµÄÊ¬Ìå") {
  if (who->query_temp("evilup")!=1) {
     command("say ÎÒÓĞ½ĞÄãÄÃÀ´Âğ ?²»¹ıÄÃÒ²ÄÃÁË ,ºÙºÙ ,Ğ»À²");
     destruct(ob);
     return 1;
     }
  else if (who->query_temp("yang")!=1) {
     command("say ÄãÕâĞ¡×Óµ¹Õæ»áÌÖÎÒ»¶ĞÄ ,Ğ»À²");
     destruct(ob);
     return 1;
     }
  else if (who->query("quests/evilup")) {
     command("say ½Ì¶¼½ÌÁË»¹Ïë¸ÉÂï ?");
     destruct(ob);
     return 1;
     }
  else {
  who->set("quests/evilup",1);
  command("say ²»´í²»´í ,µ¹Í¦ÏãµÄ !ºÃÀ² ,¾Í½ÌÄãÒ»ÕĞÄÚ¹¦°É!!!");
  tell_object (who, "[35mÄãĞÄÒ»Õğ ,È«ÉíÉ±ÆøºöÈ»ÏòÍâÒ»É¢ ,ÄãµÄÉ±ÒâÌá¸ßÁË!!!(evilup)[0m\n");
  destruct(ob);
   return 1;
  }
 }
  else if (ob->query("name") == "¹ùĞ¥·çµÄÊ¬Ìå") {
  if (who->query_temp("evilup")!=1) {
     command("say ÎÒÓĞ½ĞÄãÄÃÀ´Âğ ?²»¹ıÄÃÒ²ÄÃÁË ,ºÙºÙ ,Ğ»À²");
     destruct(ob);
     return 1;
     }
  else if (who->query_temp("kou")!=1) {
     command("say ÄãÕâĞ¡×Óµ¹Õæ»áÌÖÎÒ»¶ĞÄ ,Ğ»À²");
     destruct(ob);
     return 1;
     }
  else if (who->query("quests/evilup")) {
     command("say ½Ì¶¼½ÌÁË»¹Ïë¸ÉÂï ?");
     destruct(ob);
     return 1;
     }
  else {
  who->set("quests/evilup",1);
  command("say ºÜºÃºÜºÃ ,àÅ ,µ¹Í¦Ë³¿ÚµÄ!!!ºÃ¼Ò»ï ,¾Í´«ÄãÒ»ÕĞ°É !");
  tell_object (who, "[35mÄãĞÄÒ»Õğ ,È«ÉíÉ±ÆøºöÈ»ÏòÍâÒ»É¢ ,ÄãµÄÉ±ÒâÌá¸ßÁË!!!(evilup)[0m\n");
  destruct(ob);
  return 1;
  }
 }
  else if (ob->query("name") == "³ÂĞşÁúµÄÊ¬Ìå") {
  if (who->query_temp("evilup")!=1) {
     command("say ÎÒÓĞ½ĞÄãÄÃÀ´Âğ ?²»¹ıÄÃÒ²ÄÃÁË ,ºÙºÙ ,Ğ»À²");
     destruct(ob);
     return 1;
     }
  else if (who->query_temp("chen")!=1) {
     command("say ÄãÕâĞ¡×Óµ¹Õæ»áÌÖÎÒ»¶ĞÄ ,Ğ»À²");
     destruct(ob);
     return 1;
     }
  else if (who->query("quests/evilup")) {
     command("say ½Ì¶¼½ÌÁË»¹Ïë¸ÉÂï ?");
destruct(ob);
     return 1;
     }
  else {
  who->set("quests/evilup",1);
  command("say àÅ ,Î¶µÀºÃ³Ô¼«ÁË !²»ÁÏÄãÕâ´Î×öµÄÍ¦²»´íµÄ ,ºÃ!!¾Í½ÌÄãÕâÃ´Ò»ÕĞ!!!");
    tell_object (who, "[35mÄãĞÄÒ»Õğ ,È«ÉíÉ±ÆøºöÈ»ÏòÍâÒ»É¢ ,ÄãµÄÉ±ÒâÌá¸ßÁË!!!(evilup)[0m\n");
    destruct(ob);
    return 1;
  }
 }
  else {
  command("say ±¿µ° !½ĞÄãÄÃµÄÓÖ²»ÊÇÕâĞ©¼Ò»ïµÄ ,µ±ÎÒÃ»³Ô¹ıÂğ ?");
  return 1;
  }
  return 1;
}
 
