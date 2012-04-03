#include <ansi.h>

//inherit F_GUILDCMDS;
inherit NPC;

object ghost= this_object();

void do_meeting( object me)
{
   string str;
   object where;
   if( !me->query_temp("ghost") && me->query("class") == "killer" && !ghost->query_temp("followed"))
   {
      message_vision("[1;37mÖ»¼ûÑÛÇ°°×¹âÒ»ÉÁ, Ò»µÀÑÌÎíËÆÂýÊµ¿ìµÄ×ê½øÁË$NÌåÄÚ¡£\n[0m", me);
      command("say ´øÎÒÈ¥ÕÒÂÌÔÆ×é³¤ÖÜ°Ë²®ÉêÔ©°É...");
      command("follow "+ me->query("id"));
      ghost->set_temp("followed", me);
      me->set_temp("ghost", 1);
   }
   // ¼ÙÈçÓÐ follow µ«ÊÇÄÇ¸öÈËÓÖ²»ÔÚµÄ»°...
   else if( ghost->query_temp("followed") && !present( (ghost->query_temp("followed"))->query("id"), environment( ghost)))
   {
      where= environment( ghost->query_temp("followed"));
      str=file_name( where);
      ghost->move( str);
   }
   return;
}
void create()
{
        object ob;
        set_name("ÈÎÓ¯Ó¯",({"ljen"}));
        set("long","Ò»Î»ÍËÒþ½­ºþµÄÉ±ÊÖ, ÏÖÔÚÔò³ÉÁËÒ»Î»ÃÀÀöµÄÅ®¹í¡£\n");
        set("gender","Å®ÐÔ");
        set("combat_exp",300000);
        set("attitude","heroism");
        set("age",18);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("per", 30);
        set("spi", 30);
        set("int", 30);
        set("force", 2000);
        set("max_force", 2000);
        set("kee", 1000);
        set("max_kee", 1000);
        set("force_factor",10);

        set_skill("move",60);
        set_skill("force",70);
        set_skill("dodge",80);
        set_skill("parry",60);
        set_skill("throwing",70);

        set_skill("blackforce",60);
        set_skill("ghost-steps",70);
        set_skill("rain-throwing",70);

        map_skill("force","blackforce");
        map_skill("dodge","ghost-steps");
        map_skill("throwing", "rain-throwing");

        set_temp("invis",1);

        set("chat_chance", 8);
        set("chat_msg", ({
"ÈÎÓ¯Ó¯ËµµÀ:¡¸ÎÒËÀµÄºÃ²Ò¨Ú....¡±\n",
"ÈÎÓ¯Ó¯ËµµÀ:¡¸Ö»ÓÐÖÜ°Ë²®²ÅÄÜÌæÎÒÉêÔ©¡£¡±\n",
"ÈÎÓ¯Ó¯ËµµÀ:¡¸Ë­ÄÜ°ïÎÒ±¨³ð...¡±\n",
"ÈÎÓ¯Ó¯ËµµÀ:¡¸ÄÑµÀËµÈË³¤µÄÃÀÀöÒ²ÊÇÒ»ÖÖ´íÎóÂð?¡±\n",
"ÈÎÓ¯Ó¯ËµµÀ:¡¸Ë­ÄÜ°ïÎÒ±¨µÃ´ó³ðµÄ, ÎÒÔ¸ÒâÒÔÉíÏàÐí...¡±\n",
        }));

        setup();
        ob=carry_object("/open/killer/obj/hate_knife");
        ob->set_amount(200);
        ob->wield();
}

void init ()
{
   object me= this_player();
   if( !me->query_temp("ghost"))
      call_out("do_meeting",1,me);
   add_action("do_waveto", "waveto");
   add_action("do_waveto", "wa");
}

int do_waveto(string arg)
{ 
    mixed count;
    int money,i,gmove;
    object me,roomm;
    object ghost;
    string room="";
    me = this_player();
    ghost= this_object();
    if( me->query_temp("unconcious") )          return 0;
    if( me->is_fighting() )
        return notify_fail("Õ½¶·ÖÐÎÞ·¨Ê¹ÓÃ»½ÔÆÉÈ¡£\n");
    if( me->query_temp("ÇÀ½ÙÖÐ") )
        return notify_fail("ÇÀ½ÙÖÐÎÞ·¨Ê¹ÓÃ»½ÔÆÉÈ¡£\n");
    if( environment(me)->query("no_transmit") )
    {
       write("Í»È»Ò»ÕóÄÜÁ¿´ÓµØµ×·¢³ö,»÷É¢ÁËÄãÕÐÀ´µÄÔÆ¶ä,\n");
       write("ËÆºõÕâÀïµÄ´óÉñ²»Ô¸´ËµØ¿ÉÒÔ´«ËÍ...\n");
       return 1;
    }  
    money = me->query("bank/coin");
    if( money < 500)
    {
       write(" »½ÔÆÉÈËµ: ÄãµÄ´æ¿î²»×ã,ÎÞ·¨Ö§¸¶·ÑÓÃ.\n");
       return 1;
    }
    message_vision( HIB+"Ö»¼ûÌìÉÏ½µÏÂÒ»¶äÔÆÂ¤ÕÖ×Å$N\n"+NOR ,me);   
    switch(arg)
    {
       case "1":
         room="/open/capital/room/r70";         break;
       case "2":
         room="/open/gsword/room/su3";          break;
       case "3":
         room="/open/ping/room/road4";          break;
       case "4":
         room="/open/center/room/inn";          break;
       case "5":
         room="/open/start/room/s5";            break;
       case "10":
         room="/open/port/room/r3-1";           break;   
       case "6":
         room = me->query("startroom");         break;
       case "7":
         room = me->query_temp("fan/7");        break;
       case "8":
         room = me->query_temp("fan/8");        break;
       case "9":
         room = me->query_temp("fan/9");        break;
       default:
     }
     gmove = me->query_temp("gmove");
     if( gmove )
     {
       roomm = environment(this_player());
     }

     // ¼ì²é room ÊÇ·ñ´æÔÚ, gmove on|off ¶¼µÃÓÃ,¹Ê·Å´Ë
     if( !me->move(room) )
     {
        write(" »½ÔÆÉÈËµ: ÎÞ´ËµØµã...\n");
        return 1;
     }
     else
        ghost->move( room);
     
   if( gmove )
   {
     count = all_inventory( roomm );
     for( i=0;i < sizeof( count ) ;i++)
     {
       if( count[i]->is_character() &&
       ( count[i]->query_temp("id") == me->query("id")
          || count[i]->query_leader() == me ) )
             count[i]->move(room);
     }
   }
     
/*    no_transmit Ò»¶¨ÎÞ·¨ fanset,¹ÊÒ»¶¨ÎÞ·¨´«ËÍ,´Ë´¦¶àÓà ...ccat...9_12.96 
      if( environment(me)->query("no_transmit") ) {
        message_vision(HIB+"Í»È»Ò»ÕóÄÜÁ¿´ÓµØµ×·¢³ö,½«$NµÄÔÆ¶äµ¯×ß¡£\n"+NOR,me);
        me->move("/open/common/room/inn");
     }
     else
 */    
     if( gmove )
     {
        message_vision(HIB+"Ò»ÕóÇå·ç¹ýºó,$N´øÁì´ó¼Ò´ÓÌì¶ø½µ.\n"+NOR,me);
     }else
        message_vision(HIB+"Ò»ÕóÇå·ç¹ýºó,$N´ÓÌì¶ø½µ.\n"+NOR,me);

     me->set("bank/coin",money-500);
     return 1;
}

