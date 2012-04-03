// one.c by oda

#include </open/open.h>
#include <ansi.h>

inherit NPC;

string do_cure();
string stop_bleed();
string cure_poison();
string do_ask();

void create()
{
	set_name("Íò´ºÁ÷", ({ "one tsun liu", "one", "liu" }) );
	set("title", "ÉñÒ½");
	set("gender", "ÄĞĞÔ");
	set("age", 49);
	set("attitude", "peaceful");
	set("combat_exp", 100000);
	set("no_kill", 1);
	set("long", "Äã¿´µ½Ò»¸öÖĞÄêÄĞ×Ó£¬Éí×Å³¤ÅÛ»Æ¹Ú£¬ÓğÒÂÆ®Æ®£¬äìÈ»³ö³¾£¬\nÉñÇé¿´À´Ëµ²»³öµÄºÍÆ½Äş¾²¡£\nËûÊÇ¶ñÈË¹ÈÖĞÎ¨Ò»µÄÒ½Éú£¬ËùÒÔÔÚ¶ñÈË¹ÈÖĞµÄÈË¶¼¿¿ËûÖÎ²¡¡£\n");
	set("str", 22);
	set("cor", 20);
	set("int", 33);
	set("spi", 30);
	set("cps", 32);
	set("con", 28);

	set("chat_chance", 3);
	set("chat_msg", ({
		"Íò´ºÁ÷Ì¾ÁË¿ÚÆø£¬à«à«µÀ£º°¦..²»ÖªµÀÓĞË­ÄÜ¾ÈµÃÁËËû..\n",
		"Íò´ºÁ÷Ò¡ÁËÒ¡Í·Ëµ£º¿ÉÕæ¿àÁËĞ¡Óã¶ùÕâº¢×Ó¡£\n",
	}) );
	
	set("inquiry", ([
	//"Ëû"	:	(: do_ask1 :),
	//"Ğ¡Óã¶ù":	(: do_ask2 :),
    "¶ñÈËÉ­ÁÖ" : "ÄãÏëÈ¥¶ñÈËÉ­ÁÖ.. ?ÎÒÒ²Ö»ÊÇÌıËµ¶øÒÑ ,ÏêÏ¸Î»ÖÃÕû¸ö¶ñÈË¹ÈÒ²Ö»ÓĞ¶ÅÉ±ºÍĞùÔ¯Èı¹âÄÇ¸öÀÃ¶Ä¹íÖªµÀ¶øÒÑ...\n",
	"ÁÆÉË"	:	(: do_cure :),
	"Ö¹Ñª"	:	(: stop_bleed :),
	"½â¶¾"	:	(: cure_poison :),
    "ÆÆÃí"  :   (: do_ask :),
	]));

	setup();
}

int accept_fight(object me)
{
	return notify_fail("Íò´ºÁ÷Ğ¦×Å¶ÔÄãËµ£ºÕâÎ»"+RANK_D->query_respect(me)+"±ğ¿ªÍæĞ¦ÁËºÃÂğ?\n");
}

string do_cure()
{
	int kee, ekee, mkee;
	object who;
	who = this_player();
	ekee = who->query("eff_kee");
	mkee = who->query("max_kee");

	if( ekee==mkee ) return "Äã²»ÊÇºÃºÃµÄ£¿ÄÄÓĞÊÜÉË£¿";
	if( ekee>=mkee*8/10 ) return "ÄãµÄÉËÊÆ²»ËãÑÏÖØ£¬×Ô¼º¶àĞİÏ¢¾ÍºÃÁË¡£";
	kee = (mkee*8/10 - ekee);
	if( !who->can_afford(kee*100) )
		return "¶Ô²»Æğ£¬ÒÔÄãÉËÊÆ¶øÑÔ£¬Ö»ÓĞÕâµãÇ®¿ÖÅÂ°ï²»ÁËÄã¡£";
	who->pay_money(kee*100);
	who->set("eff_kee", mkee*8/10);
	message_vision("Íò´ºÁ÷¼ì²éÁËÒ»ÏÂ$NµÄÉËÊÆ£¬²¢ÇÒÄÃÁË¼¸ÌûÍâÉËÒ©·óÔÚ$NµÄÉË¿ÚÉÏ¡£\n", who);
	tell_object(who, HIC"Äã¸Ğ¾õµ½ÉíÉÏµÄÉË¿ÚºÃ¶àÁË¡£\n"NOR);
	return "ºÃÁË£¬ÕâÎ»"+RANK_D->query_respect(who)+"£¬ÒÔºó¼ÇµÃĞ¡ĞÄÒ»µãà¸¡£";
}

string stop_bleed()
{
	int bleed;
	object who = this_player();

	if( !bleed = who->query_condition("bleeding") )
		return "ÄãÄÄÀïÁ÷ÑªÁË£¿Á÷±ÇÑªÎÒ¿É²»ÖÎ¡£";
	if( !who->can_afford(500*bleed) )
		return "¶Ô²»Æğ£¬ÒÔÄãÉËÊÆ¶øÑÔ£¬Ö»ÓĞÕâµãÇ®¿ÖÅÂ°ï²»ÁËÄã¡£";
	who->pay_money(500*bleed);
	message_vision("Äã¿´µ½Íò´ºÁ÷ÒÔ¼«ÊìÁ·µÄÊÖ·¨Ñ¸ËÙµÄ°ï$N·óÒ©²¢°üÔúÉË¿Ú¡£\n", who);
	who->apply_condition("bleeding", 0);
	tell_object(who, HIC"ÄãµÄÉË¿ÚÍ£Ö¹Á÷ÑªÁË¡£\n"NOR);
	return "ÕâÑùÓ¦¸Ã¾Í¿ÉÒÔÁË¡£";
}

string cure_poison()
{
	int snake, coldpoison;
	int dark, five, rose, fire;
	object who = this_player();
	coldpoison = 0;

	if( who->query_condition("spring") ) {
		command("grin");
		return "ÒõÑôºÏºÍÉ¢ÊÇÃ»ÓĞ½âÒ©µÄ£¬Äã×Ô¼º°®Íµ³Ô£¬ÎÒÒ²Ã»°ì·¨À²¡£";
	}
	snake = who->query_condition("snake_poison");
	if( dark = who->query_condition("dark_poison") )
		coldpoison += dark;
	if( five = who->query_condition("five_poison") )
		coldpoison += five;
	if( rose = who->query_condition("rose_poison") )
		coldpoison += rose;
	if( fire = who->query_condition("fire_poison") )
		coldpoison += fire;

	if( !coldpoison && !snake )
		return "ÀÏ·òÊµÔÚÊÇ¿´²»³öÄãÖĞµÄÊÇÊ²Ã´¶¾¡£";
	if( coldpoison && coldpoison<=3 ) {
		tell_object(who,"Íò´ºÁ÷Ò¡Ò¡Í·Ëµ£ºÄãÖĞµÄÌì±ùÆæ¶¾ÒÑ¾­Ã»°ì·¨ÔÙ¼õÇáÁË¡£\n");
	} else if( coldpoison ) {
		tell_object(who,"Íò´ºÁ÷Öå×ÅÃ¼Í·ËµµÀ£ºÄãÖĞÁËÚ¤Ä§½ÌµÄÌì±ùÆæ¶¾£¬ÎÒÖ»ÄÜÊÔ×Å°ïÄã¼õÇá¶¾ĞÔ¿´¿´ÁË¡£\n");
		if( !who->can_afford(coldpoison/2*20000) )
			return "¶Ô²»Æğ£¬ÄãµÄÇ®Âò²»ÆğÕâÃ´¹óµÄ½âÒ©¡£";
		who->pay_money(coldpoison/2*20000);
		if( dark ) who->apply_condition("dark_poison", dark/2);
		if( five ) who->apply_condition("five_poison", five/2);
		if( rose ) who->apply_condition("rose_poison", rose/2);
		if( fire ) who->apply_condition("fire_poison", fire/2);
	}
	if( snake ) {
		tell_object(who, "Íò´ºÁ÷¿´ÁË¿´ÄãËµµ½£ºÄãÖĞÁËÉß¶¾à¸¡£\n");
		if( !who->can_afford(500*snake) )
			return "¶Ô²»Æğ£¬ÄãÉíÉÏµÄÇ®²»¹»ÓÃÀ´½âÄãµÄÉß¶¾à¸¡£";
		who->pay_money(500*snake);
		who->apply_condition("snake_poison", 0);
	}
	message_vision("Íò´ºÁ÷×ĞÏ¸µÄ¼ì²éÁËÒ»ÏÂ$NµÄ×´¿ö£¬±ã×ªÉí´Ó³÷¹ñÉÏµÄÒ»¸ö¹Ş×ÓÀï\nÄÃÁË¼¸¿ÅºÚÉ«Ò©Íè£¬·ÅÔÚ$NµÄ¿ÚÖĞ¡£\n", who);
	tell_object(who, "Ò»ÕóÇ¿ÁÒµÄ³ôÎ¶´ÓÄã×ìÀï´«ÁË³öÀ´£¬ÁîÈË×÷Å»£¬ÄãÖ»ºÃÄó×¡±Ç×ÓÒ»\n¿ÚÆø°ÑÒ©ÍèÍÌÁËÏÂÈ¥¡£\n");
	if( coldpoison )
		tell_object(who, HIC"Äã¸Ğ¾õµ½ÌåÄÚµÄ¶¾ĞÔ¼õÈõ²»ÉÙ¡£\n"NOR);
	else
		tell_object(who, HIC"Äã¸Ğ¾õµ½Êæ·ş¶àÁË¡£\n"NOR);
	return "Á¼Ò©¿à¿Ú£¬Äã¾ÍÈÌÈÌ°É¡£";
}

string do_ask()
{
  int me;
  object who = this_player();
  if(who->query_temp("marks/karup2")!=1)
  {
   return "Ê²Ã´ÆÆÃí£¿¶ñÈË¹ÈÄÄÓĞÕâÖÖ¶«Î÷£¿\n";
  }
  else
  {
   who->set_temp("marks/allow",1);
message_vision("[36mÍò´ºÁ÷ËµµÀ£º[1;33m°¦£¬ÕâÁ½¸ö¸ÃËÀµÄÅ®ÈË£¡É¶¶¼¸úÄãËµÁË£¡
ºÃ°É£¬ÕâÆÆÃí¿ÉÊÇÔÚ¶ñÈËÉ­ÁÖµÄÄ³¸öµØ·½£¬È¥ÕÒĞùÔ¯Èı¹â°É¡£
µ«¿É±ğËµÊÇÎÒÈÃÄãÈ¥µÄ°¡£¡²»È»¶ÅÉ±ÖªµÀÁË£¬ÄãÎÒ¶¼Âé·³£¡[0m\n",who);
  return "[1;37m¿ÉÇ§Íò±ğ½²°¡£¡[0m\n";
  }
}
