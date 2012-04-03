// /open/center/npc/vendor.c
#include <obj.h>
#include <ansi.h>
#include "/open/open.h"

inherit F_VENDOR;
string ask_test();
string ask_standby();

void create()
{
      set_name("Âô»ğ²ñµÄĞ¡À±ÃÃ", ({ "sale girl", "girl" }) );
      set("nickname","[31mĞ¡À±½·[0m");
        set("gender", "Å®ĞÔ" );
        set("age", 18);
        set("long", @LONG
  Ò»¸öÔÚ¿ñÏë¿Õ¼äÂô»¨ÂôÁËÆßÄê¶àµÄĞ¡Å®º¢, ÖÕÓÚÂıÂı³¤´ó,
±ä³ÉÍ¤Í¤ÓñÁ¢µÄĞ¡À±ÃÃ, Åç»ğµÄÉí²ÄÒìÓÚÑ°³£ÈË£¬Òò´Ë, »¹
ÊÇ¾­³£±»Â·¹ıµÄÓĞÇ®´óÒ¯ÆÛ¸º¡£ÓÉÓÚÃ»ÓĞÍæ¼ÒÒª¸úËıÂò»¨,
ËıÖÁ½ñ×î´óµÄĞÄÔ¸, »¹ÊÇÔÚÕâº®ÀäµÄ¶¬ÌìÓĞÒ»¼şÒÂ·ş´©, ²»
¹ı, Ã»ÓĞÒÂ·şµÄ»°, Íæ¼Ò»á¸ü¸ßĞË°É, ËùÒÔ, ËıÖ»ºÃÒ»Ö±ÔÚ
FSÂô»¨ÏÂÈ¥....
    ×î½üËıÕıÔÚÕ÷Çó´úÌæ(standby)ËıÂô»¨µÄºÃĞÄÈË......

LONG);
        set("attitude", "friendly");
        set("rank_info/respect", "Ğ¡ÃÃÃÃ");
        set("combat_exp",180);

        set("vendor_goods", ({
            CENTER_OBJ"torch",
            CENTER_OBJ"map",
        }) );

        set("chat_msg", 5);
        set("chat_msg", ({
           "Ğ¡À±ÃÃËµµÀ: Ë­ÄÜ¸øÎÒÒÂ·ş´©°¡£¬ºÃÀäÒ®¡£\n",
           "Ğ¡À±ÃÃÀ­À­ÄãµÄÒÂ·ş,ÑÛ½ÇÉÁ×ÅÀá¹âËµµÀ: ÄúÄÜ¸øÎÒÒ»¼şÒÂ·şÂğ?\n",
           "Ğ¡À±ÃÃ¿ÉÁ¯ÙâÙâµÄËµµÀ: ¶¬Áî¾È¼ÃÒ»ÏÂÂï!¡£\n",
           "Ğ¡À±ÃÃ°§ÇóµØËµµÀ: ÄÜ²»ÄÜ´úÌæ(standby)ÎÒÂô»¨°¡£¿\n",
        }) );
set("inquiry",([
   "ÊÔÁ¶Ó¡¼Ç" : (:ask_test:),
   "standby" : (: ask_standby :),
      ]));



        set("greeting_msg", ({
         "Ğ¡À±ÃÃËµµÀ: ºÃĞÄµÄ´óÒ¯Ğ¡½ãÃÇ£¬Âò°ÑÄ¾Í·µ±²ÄÉÕ°É¡£\n",
         "Ğ¡À±ÃÃ¿ÉÁ¯ÙâÙâµÄÇÆ×ÅÄã: ÕâÎ»ºÃĞÄµÄ´óÒ¯Ğ¡½ã£¬ÉìÉìÔ®ÊÖ¾ÈÖúÎÒ°É¡£\n",
         "Ğ¡À±ÃÃÓĞÆøÎŞÁ¦µÄËµ: ºÃĞÄµÄ´óÒ¯Ğ¡½ã£¬Â·¹ı´ËµØ£¬ÄÑµÀ¼ûËÀ²»¾ÈÂğ?\n",
         "Ğ¡À±ÃÃ°§ÇóµØËµµÀ: ÄÜ²»ÄÜ´úÌæ(standby)ÎÒÂô»¨°¡£¿\n",
        }) );
        setup();
}

int accept_object(object who, object ob)
{
  object        me;

  seteuid(getuid());
  me = this_object();

  if (who->query("quests/sale_girl") == 0) {
    message_vision("Ğ¡Å®º¢ËµµÀ: Ğ»Ğ»$NÉÍ´Í¡£ÃÃÃÃÎÒÎŞÒÔÎª±¨£¬ÂôµÃµÄÒ»°ÙÎÄÇ®"
        "ÒÔ¼°ÂôÊ£µÄÒ»°ÑÄ¾Í·¸úÒ»ÕÅµØÍ¼¾Íµ±³É»Ø±¨£¬ÇëÄúĞ¦ÄÉ¡£\n",who);
    who->pay_player(100);
    who->set("quests/sale_girl",1);
    new(CENTER_OBJ"torch")->move(who);
    new(CENTER_OBJ"map")->move(who);
    who->save();
    return 1;
  }
  else {
    message_vision("Ğ¡Å®º¢ËµµÀ: Ğ»Ğ»$NÉÍ´Í¡£\n",who);
    return 1;
  }
}

string ask_test()
{
 if(this_player()->query("quests/yan")==3)
 {
  if(this_player()->query("quests/sale_girl",1) && this_player()->query("quests/yantestmark1",1) && this_player()->query("quests/2ndtest",1))
  {
  int i;
  i=6+random(5);
  command("say Ğ»Ğ»ÄúµÄ°ïÃ¦.ÎÒÔ¸Òâ½«appo¸øÎÒµÄÓ¡¼Ç´«µ½ÄãÉíÉÏ!\n");
  tell_object(this_player(),HIW"Ë²¼äÓÉÂô»ğ²ñµÄĞ¡À±ÃÃ½«ÊÖ´îÔÚÄãµÄ¼çÉÏ..Äã¶ÙÊ±¾õµÃÒ»¹ÉÅ¯ÒâÓÉĞ¡À±ÃÃµÄÊÖÖĞ´«¹ıÀ´\n"NOR);
  this_player()->set("quests/2ndtest",i);
  this_player()->set("quests/yantestmark2",1);
  return("×îºóÒ»¸öÓ¡¼ÇÔÚÊ¥ÏÍÊéÊÖÉÏ,Äã¿ÉÒÔÈ¥ÕÒËûÎÊÎÊÁË\n");
  }
 else if (this_player()->query("quests/yantestmark2")>1)
  return ("ÎÒÒÑ¾­°ÑÓ¡¼Ç¸øÄãÁË..Äã»¹Òª×öÊ²Ã´\n");
 else
  return ("¾ÈÖú¾ÈÖúÎÒ..ÎÒ¾Í¸úÄãËµÓ¡¼ÇÔÚÄÄ\n");
 }
else
 return ("É¶Ó¡¼Ç..ÄãÔÚËµÊ²Ã´?\n");
}

string ask_standby()
{
  string *places = ({
    "/open/firedancer/t01.c",
    "/open/hall/way1.c",
    "/open/killer/room/r1.c",
    "/open/killer/room/ru3.c",
    "/open/marksman/room/shop.c",
    "/open/newhand/newhand.c",
    "/open/port/room/port.c",
    "/open/bonze/room/big.c",
    "/open/start/room/f1.c",
    "/open/tensan/room6.c",
    "/open/wu/room/luroom1.c",
    "/open/badman/room/s2.c",
    "/open/capital/room/r01.c",
    "/open/doctor/room/r4.c",
    "/open/gblade/room/c2.c",
    "/open/heaven/castle/room/n5.c",
    "/open/love/room/room2-14.c",
    "/open/mogi/castle/room10.c",
    "/open/mogi/village/room/room-07.c",
    "/open/prayer/room/happy.c",
    "/open/beggar/room/room01.c",
    "/open/center/room/r10.c",
    "/open/evil-area/e01.c",
    "/open/island/room/i1.c",
    "/open/magic-manor/manor04.c",
    "/open/mon/hole.c",
    "/open/ping/room/f2.c",
    "/open/snow/room/hole.c",
    "/open/tailong/room/d3.c",
    "/open/wind-rain/43.c",
    "/open/biau/room6.c",
    "/open/dancer/room/roome2.c",
    "/open/fire-hole/f-48.c",
    "/open/gsword/room/froad2.c",
    "/open/poison/room/room10.c",
    "/open/scholar/room/wind_s.c",
    "/open/soldier/room/r36.c",
    "/open/tendo/room/r3.c"
  });

  if (this_player()->query("standby") < 1) {
    this_player()->add("standby", 1);
    this_player()->move (places[random(sizeof (places))]);
    return "say Ğ»Ğ»ÄúµÄ°ïÃ¦, ÎÒÔ¸ÒâÒÔÉíÏàĞí!\n";
  }
  else {
    this_player()->move (places[random(sizeof (places))]);
    return "say Ğ»Ğ»ÄúµÄ°ïÃ¦£¡\n";
  }
}
