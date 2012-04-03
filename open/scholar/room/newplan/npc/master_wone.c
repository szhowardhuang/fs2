//by roger
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string do_array();
string do_tigi();
string do_sixplan();
string do_koming();
string do_sehan();
string do_hoba();
string do_book();


void create() {
        set_name(HIC"Ì«¹«Íû"NOR,({"master wone","wone","scholar"}));
        set("class","scholar");
        set("nickname","$HIW$ÌìÏÂµÚÒ»¾üÊ¦$NOR$");
        set("title",HIY"½ª×ÓÑÀ"NOR);
        set("long",
"Ì«¹«ÍûÒÔÖúÖÜÊÒÍõ³¯È¡µÃÌìÏÂÖ®Ìì²Å¾üÊ¦, ²¢ÇÒ 
×Ô´´±ø·¨¼ÆÄ±, ¸üÊ¤Ëï×Ó±ø·¨¡£ 
");
        set("inquiry", ([
        "°ËØÔÕó"        : (: do_array :),
        "Öî¸ğ¿×Ã÷"        : (: do_koming :),
        "Áùèº"          : (: do_sixplan :),
        "Ì«¼«°ËØÔ"    : (: do_tigi :),
        "Öî¸ğÕ°"      : (: do_sehan :),
        "Öî¸ğÒØÕÑ"    : (: do_hoba :),
        "ÁùèºÒ×±¾"      : (: do_book :),
]));
        set("str",40);
        set("cor",25);
        set("gender","ÄĞĞÔ");
        set("guild_master",1);
        set("attitude","heroism");
        set("family/family_name","ÈåÃÅ");
        set("max_gin",5000);
        set("max_kee",8000);
        set("max_sen",8000);
        set("max_force",8000);
        set_skill("sixgod-plan",120);
        set("combat_exp",5000000);
        set("functions/movedown/level",100);
        set("functions/finger/level",100);
set("chat_chance_combat", 100);
set("chat_msg_combat",({
(: perform_action("stabber.movedown") :),
(: perform_action("stabber.finger") :),
}));
        set("chat_chance",50);
        set("chat_msg",({
        }));
        setup();
       carry_object("/open/scholar/room/newplan/obj/pen")->wield();
       add_money("gold",50);
 }
string do_array()
{
        object me=this_player();
        if(me->query_temp("six_ask")==8)
        {
          me->set_temp("six_ask",9);
        return("
          °ËØÔÕóÊÇÖî¸ğ¿×Ã÷Ëù´´Ö®ÕóĞÎ, Èç¹ûÒª
        ´³¹ıÈ¥, ²¢ĞëÒªÁË½âÌ«¼«°ËØÔÖ®±ä»¯¡£");
}
else
        return("×öÈË±ğÌ«°ËØÔ, ÕæÊÇµÄ!!!");
}
string do_koming()
{
        object me=this_player();
          if(me->query_temp("six_ask")==5)
        {
          me->set_temp("six_ask",6);
          return("
          ÄãËµ¿×Ã÷Âğ??Ëû¾ÍÊÇÎÅÃûÈı¹úÊ±´úµÄ´ó¾ü
          Ê¦Ñ½, ÈåÃÅµÄÖî¸ğÉñËã¾ÍÊÇÓÉ¿×Ã÷ËùĞ´
          , ²»¹ıÖî¸ğÉñËãÀïÃæµÄ¶«Î÷²¢Ã»ÓĞÎÒµÄ 
          ÁùèºÀïÃæµÄ¼ÆÄ±¸ß¼¶, ËùÒÔÖî¸ğ¿×Ã÷±ã
          ½«ÎÒµÄÁùèº½èÈ¥, µ½Ã»Ïëµ½²»¾ÃÖ®ºóËû
          ¾Í²¡ËÀÁË, ½«ÊéÁô¸øËûµÄ´«ÈËÖî¸ğÕ°¡£");
        }
        else
        return("¿×Ã÷??ÄÇÊÇÏ¹ÃÜÍÛ¸ç..¿ÉÒÔ³ÔÂğ???");
}          
string do_sehan()
{
        object me=this_player();
        if ( me->query_temp("six_ask")==6)
        {
          me->set_temp("six_ask",7);
          return("
          Öî¸ğÕ°ÊÇÖî¸ğ¿×Ã÷µÄºóÈË, Ò²ÊÇÒ»¸ö¸»
          ÓĞÖÇÄ±µÄÈË, ²»¹ıËûÈ´°ÑÁùèº¸øÁËËû×î
          Ğ¡µÄ¶ù×ÓÖî¸ğÒØÕÑ¡£");
        }
        else
          return("È¥ËÀÀ²!!ÈË¼ÒµÄ¶ù×ÓÓÖ²»ÊÇÎÒÉúµÄ, ÍÛ°¢ÔÖ!!");
}
string do_hoba()
{
        object me=this_player();
        if( me->query_temp("six_ask")==7)
        {
          me->set_temp("six_ask",8);
          return("
          Öî¸ğÒØÕÑÊÇÖî¸ğÒ»ÃÅµÄ°ÜÀà, ËûÄÃ×Å
          Áùèº´ËÊéÎ£º¦×ÅÊÀÈË, Äã°ïÎÒ°ÑÊéÈ¡»Ø
          °É, Öî¸ğÒØÕÑÏÖÔÚÎªÓÚ°ËØÔÕóÖĞ!!");
        }
        else
          return("Ê²Ã´Ê²Ã´???");
}
string do_sixplan()
{
        object me=this_player();
        if( me->query("family/family_name")=="ÈåÃÅ" && (me->query_temp("six_ask")==4))
        {
          me->set_temp("six_ask",5);
          return("
          ÁùèºÊÇÎÒĞ´µÄÕ½ÂÔÊé¼®Ö®Ò», ²»¹ıÎÒ°ÑËû´«¸øÁËÖî¸ğ¿×Ã÷ÁË
          °É¡£");
        }
        else
        return("Áù÷Ò??¿ÉÒÔ³ÔÂğ??¡£");
}
string do_tigi()
{
        object me=this_player();
        if( me->query_temp("six_ask")==9)
        {
          me->set_temp("six_ask",10);
          return("
          °ËØÔÕóÓĞ·Ö°ËÖÖØÔÏó, ×ß·¨ÊÇÓÉÖî¸ğ¿×Ã÷ÀûÓÃÌ«¼«¿ÉÉúÁ½
          ÒÇ, Á½ÒÇ¿ÉÉúËÄÏó, ËÄÏóÓÖÉú°ËØÔµÄÔ­ÀíËùĞ´³ÉµÄ, ÆäÖĞ
          ¿ÉÄÜ»áÓöµ½¸÷ÖÖµĞÊÖ, ÆäÊµËû¾Í½«°ËØÔÕóÉèÔÚ´ËÉ½µÄÎ÷ÄÏ
          ÄãÏëÈ¥¾ÍÈ¥°É, °İÍĞÄãÁË¡£
        ");
        }
        else
          return("Ì«¼«ÕÅÈı·á~~~~ya~~~");
}
string do_book()
{
        object me=this_player();
        object ob;
        if(me->query("family/family_name") != "ÈåÃÅ")
        return("ÄãÄÃÁËÒ²Ã»ÓÃ!!\n");
        if(me->query_temp("get_sixgod_book"))
        return("ÄãÒÑ¾­ÄÃ¹ıÁËÀ²!!\n");
        if(!me->query("mark/sixgod-plan"))
        return("°İÍĞ..ÄãÄÃÁËÒ²Ã»ÓĞÓÃÑ½?!!\n");
        else
        {
        ob=new("/u/s/sueplan/obj/book1");
        ob->move(me);
        message_vision("Ì«¹«Íû¸ø¸ö$NÒ»±¾Êé\n",me);
        }
}

int accept_object(object me, object obj)
{
        if( obj->query("id") == "sixgod-plan book" )
        {
if( me->query_temp("ko_houng") == 1 && !me->query("mark/sixgod-plan") && me->query_temp("ko_hace")==1 && me->query_temp("ko_show")== 1 && me->query_temp("ko_kao")==1 && me->query_temp("ko_yea")== 1 && me->query_temp("ko_jone")== 1)
          {
            command("say ¼ÈÈ»Äã¶áÈ¡ÁùèºÆæÂÔÓĞ¹¦, ÎÒ±ã½«ÁùèºÆæÂÔÉÏ¼ÇÔØµÄ¼ÆÄ±
´«ÊÚÓëÄã°É¡£");
tell_object(me,"»ÆÊ¯¹«¶ÔÄãËµ : ÒÔºó¿ÉÒÔµ½ÎÒÕâÄÃÆß²Ê·ï»Ë±Ê(want Æß²Ê·ï»Ë±Ê)¡£\n");
tell_object(users(),"
[1;37mÌ«¹«Íû·¢³öË¬ÀÊµÄĞ¦Éù :
[1;37m    ¡õ         ¹ş¹ş¡«ºÃÒ»Ä±ÂÔµÄ½«²Å"+me->query("name")+"Ñ½£¡£¡
[1;33m    Äã¹ûÈ»Ã»ÓĞÈÃÎÒÊ§Íû£¡£¡ºÃ°É£¬ÎÒ¾Í´«ÄãÎÒµÄ±ØÉú¾øÑ§ -\n
[1;5;36m           ¡®Áù   èº   Ææ    ÂÔ¡¯[0m\n\n");
        me->set("mark/sixgod-plan",1);
        me->set("title","[1;36mÈå×ğ[1;37m¡®[1;45;37mÁùèºÆæÂÔ[1;0m[1;37m¡¯[1;33m´«ÈË[0m");
          }
          destruct(obj);
        }
        else
        {
        command("kick "+getuid(me));
        command("say Õâ¶«Î÷²»ÊÇÄã´òµÄ°É???");
        }
        return 1;
}
void init()
{
add_action("do_change","change");
add_action("do_want","want");
}

int do_change(string str)
{
  object me = this_player();
  if(str=="title")
  {
  if(!me->query("mark/sixgod-plan"))
  return notify_fail("Äã»¹Ã»Ñ§¹ıÁùèºÆæÂÔ\n");
  if(me->query("family/family_name")!="ÈåÃÅ")
  return notify_fail("ÄãÒÑ²»ÊÇÈåÃÅÖ®ÈË\n");
me->set("title",
"[1;36mÈå×ğ[1;37m¡®[1;45;37mÁùèºÆæÂÔ[0m[1;37m¡¯[1;33m´«ÈË[0m");
  tell_object(me,"titleĞŞ¸ÄÍê³É\n");
  return 1;
  }
}

int do_want(string arg)
{
  object me = this_player();
  object pen = new("/open/scholar/room/newplan/obj/bird_pen.c");
  if(!arg||arg!="Æß²Ê·ï»Ë±Ê")
  return notify_fail("ÄãÏëÒªÊ²Ã´???\n");
  if(!me->query("mark/sixgod-plan"))
  return notify_fail("ÄãÎ´½â¹ıÁùèºà¸!!\n");
  if(me->query("family/family_name")!="ÈåÃÅ")
  return notify_fail("ÄãÒÑ²»ÊÇÈåÃÅÖ®ÈË\n");
  if(me->query_temp("ok_get_pen"))
  return notify_fail("ÄãÒÑ¾­ÄÃ¹ıÁËÀ²\n");
  me->set_temp("ok_get_pen",1);
  pen->move(me);
  tell_object(me,"ÄãÈ¡µÃÁËÒ»Ö§Æß²Ê·ï»Ë±Ê¡£\n");
  return 1;
}
