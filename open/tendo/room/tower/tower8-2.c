inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
        seteuid(getuid());
        set("short","ÃÜÊÒ");
        set("long", @LONG

Äã×ß½øÒ»¼äÒõ°µ³±ÊªµÄÐ¡·¿¼ä£¬ÆäÆøÎ¶ÄÑÎÅÄÑÊÜÓÐÈçËÀÊ¬°ã£¬µÈÄãÎå
¹ÙÂýÂýÏ°¹ßºÚ°µºó£¬Äã¿´¼ûÔÚÕâ¶ùÓÐÒ»ÕÅ´²¡¢Ò»ÕÅ×À×Ó¡¢ËÄÃæÇ½(wall)ºÍ
Ò»¸öÓÃÀ´àÅàÅµÄÃ©¿Ó£¬µ«µ½´¦¶¼½áÂúÁËÖ©ÖëË¿¡£ÄãºÕÈ»·¢¾õÔÚÎ÷±ßÇ½½ÇµÄ
Ð¡´°×Ó(window)ÅÔ±ßÓÐ¸öÈË±»ÓÃÌúÃÅËøÔÚÄÇÀï¡£
LONG
        );
        set("no_fight",1);
        set("light_up", 1);
        set("no_transmit",1);
        set("no_auc",1);
  set("item_desc", ([ /* sizeof() == 2 */
  "window" : "    Ò»¸öÄ¾¿òÐ¡´°£¬ÄãÓÉ´°¿ÚÍùÍâ¿´È¥£¬·¢ÏÖÍâÏÂÍ·Õý¶ÔÒ»¸öË®³Ø£¬Äã²»
½ûÍ»·¢ÆæÏë£¬ÏëÓÉÕâ¶ùÌøÏÂÈ¥£¨jump£©ÊÇ²»ÊÇ±È½Ï¿ìÏÂµ½Ò»Â¥£¡£¿",
  "wall" : " ÐÞÂÞÐÄ·¨Ö®¿Ú¾÷ (words)
             ÐÞÂÞ¶·ÆøÄËÐÞÂÞÐÄ·¨Ö®¾øÑ§£¬Ñ§Ö®ÓÐ³ÉÕß(read words)¿É½«ÄÚÁ¦¾Û½á£¬×ª
             ¶ø·¢³öÊý±¶ÄÚ¾¢£¬ÊÇÎÒÚ¤µîÖÁ¸ßÖ®¾øÑ§¡£    perform fiendforce.fight
",
]));
        set("objects", ([ /* sizeof() == 1 */
            "/open/tendo/room/tower/npc/fiend.c" : 1,
]));
  setup();
}
void init()
{
 add_action("do_read","read");
 add_action("do_jump","jump");
 add_action("free_fiend","free");
}
int do_read(string str)
{
  object me=this_player();
  if(str!="words") {
  tell_object(me,"[1;32mÄãÏëÒª¶ÁÊ²Ã´?[0m\n");
  return -1;
  }
  if(me->query_skill("fiendforce",1) > 1){
  tell_object(me,"[1;37mÄãÔç¾ÍÒÑ¾­»áÐÞÂÞÐÄ·¨ÁË¡£[0m\n");
  return -1;
  }
  else {
  tell_object(me,"[1;37mÄãÕÕ×ÅÇ½ÉÏµÄ¿Ú¾÷Á·ÁËÒ»±é£¬ÆøÔËÒ»ÖÜÌì£¬ÄãÑ§»áÁËÐÞÂÞÐÄ·¨¡£[0m\n");
  me->set_skill("fiendforce",1);
  return 1;
       }
}
int do_jump()
{
        object who;
    who = this_player();

        who->move("/open/center/room/inn");
tell_room(this_object(),"ÄãÖ»¿´µ½Ò»µÀÉÁ¹â,ºö"+
 "µÄÒ»Éù£¬ÈËÒÑÌøÁËÏÂÈ¥¡£\n");
        message("system",
 HIW"\n\tÎäÁÖÖ®ÖÐ´«À´Ò»µÀÏûÏ¢ : "HIY""+this_player()->name()+""HIW"ÇáÇáËÉËÉµØ´³¹ýÁË"HIR"ËøÑýËþ"HIW" !!\n"NOR,users());
        return 1;
}
int free_fiend(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("fiend",environment(ob)))
    return notify_fail("ÈËÓÖ²»ÔÚ£¬Äã·ÅÊ²Ã´¡£\n");
  if(str != "fiend")
    return notify_fail("ÄãÒªÊÍ·ÅË­Ñ½¡£\n");
  if( ob->query("force") > 1000)
  {
message_vision(HIC"$NÔËÆðÈ«ÉíµÄÄÚÁ¦´òÆÆÁËÄÇµÀ"HIW"ÌúÃÅ"HIC"¡£\n"NOR,ob);
  ob1=present("fiend",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  }
  else
  {
message_vision(HIR"$NÔËÆðÄÚÁ¦ÏëÒª´òÆÆÄÇµÀ"HIW"ÌúÃÅ"HIR"£¬ÓÉÓÚÄÚÁ¦²»×ã±»ÌúÃÅÉÏµÄÒõ¾¢·´µ¯¶øÊÜÉË¡£\n"NOR,ob);
   ob->add("kee",-200);
  }
return 1;
}
int msg1(object ob)
{
message_vision(HIR"\nÖ»¼ûÚ¤µîÐÞÂÞÔËÆðÄÚÁ¦£¬Í»È»Õû¸öÇ½ÃæÕ¨ÁË¿ªÀ´¡£\n"NOR,ob);
 call_out("msg2",3,ob);
  return 1;
}
int msg2(object ob)
{
  object ob1;
message_vision(HIW"\nÚ¤µîÐÞÂÞµÀ£ºÐ¡»ï×Ó£¬¸ÐÐ»À²£¡¡£\n"NOR,ob);
message_vision(HIW"\nÚ¤µîÐÞÂÞµÀÒ»¸ö×ÝÉí£¬Íù´°»§ÄÇ¶ùÌøÏÂ£¬ÉíÓ°Ðý¼´ÏûÊ§ÔÚÄãµÄÃæÇ°¡£\n"NOR,ob);
set("exits/up","/open/snow/room/back");
message("mud","[1;34mÌì¿Õö®Ê±ÎÚÔÆÃÜ²¼...\n[0m",users());
  message("mud","[1;35mÒ»Õó¿ñºðÉùÍ»È»´«±éÎäÁÖ¸÷¸ö½ÇÂä£¡£¡£¡\n[0m",users());
  message("mud","[1;32mÚ¤µîÐÞÂÞ½«ÒÖÓôµÄÕæÆø£¬Õû¸ö±¬·¢³öÀ´£¬ºðµÀ£º\n
                 ÎäÁÖµÄÈË¸øÎÒÌý×Å£¬½ñÌìÓÉÓÚ[0m[1m"+ob->query("name")+"[1;32mµÄ°ïÖú£¬ÎÒÚ¤µîÐÞÂÞµÃÒÔÖØÏÖ½­ºþ£¬
                 Ò»ÇÐÐÂ³ð¾ÉºÞ£¬×ÜËã¿ÉÒÔÀ´¸öÁË½áÀ²£¡£¡£¡\n
                 ¹þ£¡¹þ£¡¹þ£¡¹þ£¡¹þ£¡\n
                 ÌìµÀÅÉºÍÎå°ÙÄêÇ°ÎäÁÖÖÐ×ÔôàÎªÕýµÀÈËÊ¿µÄÀÏÔô¼°ËûÃÇµÄµÜ×Ó£¬
                 µÈ×ÅÎÒÑªÏ´ÎäÁÖ°É£¡\n\n[0m",users());
  call_out("msg3",3,ob);
  return 1;
}
int msg3(object ob)
{
new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road4.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road4.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road2.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road2.c");
new("/open/tendo/room/tower/npc/monster")->move("/open/center/room/road1.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road3.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road3.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road3.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road3.c");
new("/open/tendo/room/tower/npc/snake")->move("/open/gsword/room/su3.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/gsword/room/sushop.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/gsword/room/sushop.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/capital/room/r70.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/capital/room/r70.c");
new("/open/tendo/room/tower/npc/yama")->move("/open/main/room/r19.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/r12.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/r12.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/r10.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/r10.c");
new("/open/tendo/room/tower/npc/plaguer")->move("/open/main/room/f11.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/f12.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/f12.c");
new("/open/tendo/room/tower/npc/villain")->move("/open/ping/room/road4.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road5.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road5.c");
new("/open/tendo/room/tower/npc/chieftain")->move("/open/ping/room/road6.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road10.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road10.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/soldier2.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/soldier2.c");
new("/open/tendo/room/tower/npc/goblin")->move("/open/ping/room/soldier1.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/inn.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/inn.c");
new("/open/tendo/room/tower/npc/butcher")->move("/open/wu/room/school1.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/wu/room/school1.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t03.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t03.c");
new("/open/tendo/room/tower/npc/fiend")->move("/open/tendo/room/t03.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t04.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t04.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t02.c");
new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t02.c");
 
message("mud",HIG"\n\nËøÑýËþ¶¥ºäµÄÒ»Éù²¢³öÁËÓúÇ§ÌõµÄÇà¹â£¬ÏñÁ÷ÐÇ·ÉÊÅ°ãÂäµ½ÈË¼ä....\n"NOR,users());
message("mud",HIR"\nÖÚÑýÆëµÀ:\n
                  ÎÒÃÇÖÕÓÚÖØ»ñ×ÔÓÉ£¬´Ëºó½«ÊÄËÀ×·ËæÐÞÂÞ
                       ²ùÆ½ÈË¼ä£¬ÖØ½¨Ä§½ç÷öºÚÁ¦Á¿
                    Íê³É·ÙÌì´óÍõÎå°ÙÄêÇ°¸øÓèµÄÊ¹Ãü....\n"NOR,users());
  call_out("msg4",3,ob);
  return 1;
 }
int msg4(object ob)
{
message("mud","[1;36mÂ½Çå·çÌ¾µÀ£º\n
                ÄÑµÀÎå°ÙÄêÇ°ÐÈ·çÑªÓêµÄ²Ò¾çÓÖÒªÔÙ´ÎÖØÑÝÂð£¿
                ÎäÁÖ¸÷´óÅÉ£¬½ñÌìÓÖµ½ÁËÒªÍÅ½áÒ»ÖÂµÄÊ±ºòÁË£¡
                ´ó¼ÒÆëÐÄÐ­Á¦ÏûÃðÚ¤µîÐÞÂÞ¸úËûµÄÓàµ³£¡\n\n[0m",users());
 message("mud","[1;33mÂ½Çå·ç×ÝÉù³¤Ð¥£º\n
                ÎÒÒÔÌìµÀÅÉÕÆÃÅÖ®Î»£¬ÇëÇóÎäÁÖ¸÷ÃÅÅÉ£¬½ñºó¼ûµ½ÐÞÂÞ¼°Æäµ³ÓðÕß£­\n
                ¸ñÉ±ÎðÂÛ£¡£¡£¡\n
                ÇÒ½ñÈÕÏÂÁîÎÒÌìµÀÅÉµÜ×Ó×·É±»öÊ×[0m[1m"+ob->query("name")+"[33m£¡£¡£¡\n[0m",users());
return 1;
}




