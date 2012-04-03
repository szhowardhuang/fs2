// ÖØĞÂÉè¼Æmaster_liu by Chan
// Ôö¼ÓĞí¶à¹¦ÓÃ
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string book();
string icef();
string test();
string super_fighter();
/*
// ÒÔÇ°µÄquestsºóÀ´È¡ÏûÁË,Ê®Àï×·É±Áî!!!!
string ask_sec()
{
        if( !this_player()->query("quests/to-kill-1") )
                return "ÄãÔÚËµĞ©Ê²Ã´ ?\n";
        this_player()->set("quests/to-kill-2",1);
        return "ºÃ°É ! ÎÒ¾Í¸æËßÄãºÃÁË ! ºÚÏÉÂŞºº¾ÍÊÇÀîÁé !\n";
}
//ºÃÏñÊÇ·µÀÏ»¹Í¯Ö®quests  È¡ÏûÖĞ by chan
int do_check( object me )
{
        command("say "+(me->query("gender")=="ÄĞĞÔ" ? "×³Ê¿" : "¹ÃÄï")+" ! Äã¿´ÁËËÆºõÊÜµ½ÁË¼«ÖØµÄÄÚÉË£¬ÈÃÎÒÌæÄã¿´¿´°É ?");
}
int do_nod()
{
        object me = this_player() , ob = this_object();
        if( !me->query("quests/kill-dugur") || me->query("quests/cure-star") ) return 0;
        message_vision("$N¿´ÁË¿´$nÉíÉÏµÄÉËºÛ¡£\n",this_object(),this_player());
        command("sign");
        command("say ÀÏ·òÎŞÄÜÎªÁ¦£¬ÉËÄãÖ®ÈËµÄ¸ù»ùÔ¶ÔÚÀÏ·òÖ®ÉÏ£¬µ±½ñÊÀÉÏ£¬¿ÖÅÂÖ»ÓĞÖ£Ê¿ĞÀÓĞÕâÖÖÊµÁ¦¡£");
        command("say ¿ìÈ¥ÕÒËûÀ´°ïÄã¿´¡¸ÄãµÄÉË¡±²¢ÇëËû°ïÄã¡¸ÁÆÉË¡±¡£");
        return 1;
}
*/
void create()
{
   set_name("ÁõÈ«Êé",({"master liu","liu"}));
   set("long","ËûÊÇÑ©²ÔÈıÏÀÖ®Ê×¡®ºÚÓ°¹í½Å¡¯ÁõÈ«Êé£¬Ò»Ë«Ìú½Å£¬×İºáÎäÁÖ¡£\n");
   set("gender","ÄĞĞÔ");
   set("guild_master",1);
   set("class","fighter");
   set("nickname","ºÚÓ°¹í½Å");
   set("combat_exp",5000000);
   set("attitude","heroism");
   set("age",47);
   set("title","Ñ©²ÔÅÉµÚËÄ´úÕÆÃÅÈË");
   set("str", 50);
   set("cor", 24);
   set("cps", 18);
   set("per", 24);
   set("int", 42);
   set("force", 7000);
   set("max_kee",15000);
   set("kee",15000);
   set("quests/read_snow",3);
      set("max_gin",3000);
      set("gin",5000);
          set("sen",5000);
          set("max_sen",5000);
   set("s_kee",600);
   set("max_s_kee",1000);
   set("sec_kee","tiger");
   set("inquiry",([
        "ÌìĞ°Ê¯":   "Ê¦¸¸ÁÙÖÕÇ°Ôø½»¸øÎÒÕâÑù±¦Îï£¬ËûËµ´ËÎïµ±ÔùÓëÓĞÔµÈË¡£",
        "ÓĞÔµÈË":   "ÄÜËµ³öÊ®ÄêÇ°ÎäÁÖÈı´ó¸ßÊÖÕß£¬¼´ÎªÓĞÔµÈË¡£\n",
        "²Ø¾­¸ó":  (: book :),
        "ĞşÌìÊ¥µØ":   (: super_fighter :),
        "¹±Ï×":   (: test :),
//      "ÓñÃÅ¹Ø" : (: ask_sec :),
          ]));
    set_skill("literate",30);
   set("force_factor", 50);
   set("max_force",3000);
      set_skill("snow-kee",100);
   set_skill("cure",40);
          set_skill("move",50);
   set_skill("force",120);
   set_skill("magic",20);
   set_skill("dodge",50);
       set_skill("parry",50);
   set("functions/ice-fingers/level",100);
   set("functions/snow-powerup/level",50);
   set_skill("spells",20);
      set_skill("unarmed",120);
   set_skill("snowforce",100);
   map_skill("force","snowforce");
           set_skill("black-steps",100);
   set_skill("snow-martial",100);
   map_skill("unarmed","snow-martial");
   map_skill("dodge","black-steps");
   map_skill("parry","snow-kee");
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   (: icef :),
   }));
   setup();
   create_family("Ñ©²ÔÅÉ",4,"ÕÆÃÅÈË");
   carry_object(SNOW_OBJ"figring")->wield();
   carry_object("/open/snow/obj/liucloth.c")->wear();
}

void init()
{
        object ob;
/*
        object me = this_player();
        if( me->query("quests/kill-dugur") && !me->query("quests/cure-star") )
                call_out("do_check",1,me);
*/
        add_action("do_say","say");
/*
        add_action("do_nod","nod");
*/
        add_action("do_join","join");
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
     ::heart_beat();
}

void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="fighter")
        {
                command("say Äã²»ÊÇÎäÕß£¬ÎÒ²»ÄÜÊÕÄã¡£\n");
                return;
        }
      if((int)ob->query("str")<20) {
          command("say Ñ©²ÔÎäÑ§ÒªÁ¦Á¿´óµÄÈË²ÅÄÜÑ§£¬ÎÒ¿´ÄãÇë»Ø°É!\n");
          return;
      }
      command("hmm");
      command("recruit "+ob->query("id"));
}

int accept_fight(object who)
{
who=this_player();
command("cmd usekee "+who->query("id"));
 command("say ¹ûÈ»Ó¢ĞÛ³öÉÙÄê¡£\n");
 command("perform snow-kee.snow-powerup");
command("cmd usekee "+who->query("id"));
 command("charge "+who->query("id"));
 return 1;
}

int accept_kill(object who)
{
who=this_player();
 command("say ËÀ°É~~~~\n");
 kill_ob(who);
command("charge "+who->query("id"));
 command("perform snow-kee.snow-powerup");
command("cmd usekee "+who->query("id"));
 return 1;
}

int do_say(string str,object ob)
{
     object who;
        who=this_player();
        if(who->query("get_stone")==1){
           return 0;}//¼ÇµÃºÜ¾ÃÖ®Ç°lum¾ÍÒªÎÒ¸Ä³ÉÕâÈı¸öpplµÄÃû×ÖÁËÕâĞ©ÈËÒ²ËãÊÇÀúÊ·
	else {	            //ÁË...³ıÁËsulaÕâÀÏÔô..so...ÔÙ°ÑËû¸Ä³ÉÕâÈı¸ö..........cgy
    if (str=="³ÂµûÒÂ")  this_player()->set_temp("say_1",1);
    if (str=="»ÆÔÆ")    this_player()->set_temp("say_2",1);
    if (str=="¸´»îĞ°Éñ")  this_player()->set_temp("say_3",1);
    if(this_player()->query_temp("say_1")==1&&this_player()->query_temp("say_2")==1&&this_player()->query_temp("say_3")==1)
     {
      command("smile");
      command("say Äã¹ûÈ»ÊÇÓĞÔµÈË¡£\n");
      
        this_player()->set("get_stone",1);
		call_out("do_gs",1,ob);
      }
    return 0;
}}
int do_gs(object ob)
    {
        object stone;
     
        command("say ÌìĞ°Ê¯ÄÃÈ¥°É !");
        new("/open/snow/obj/stone")->move(this_player());
        
        return 1;
    }
string icef()
{       
        command("perform snow-martial.ice-fingers");
        return "\n";
}
string book()
{
   object me=this_player();
   if(me->query("allow_study")==1)
          return "àÅ...²»ÊÇ¸úÄãËµ¹ıÁËÂğ£¿\n";
   command("say ´ËÄË±¾ÅÉ²ØÊéÖØµØ£¬ÀïÃæÓĞ±¾ÅÉÖØÒªÃØóÅ¡£");
   if(me->query("family/family_name")!="Ñ©²ÔÅÉ")
          return "Äã²»ÊÇ±¾ÅÉµÄµÜ×Ó£¬Ã»×Ê¸ñ¶Á±¾ÅÉµÄÊé¡£\n";
   if(me->query("combat_exp")<150000)
          return "ÒÑÄãÕâÖÖ³Ì¶ÈÒª¶Á²Ø¾­¸óµÄÊé£¬»¹ÔçµÄºÜ¡£\n";
    return "Ö»ÓĞÎªÎäÁÖÓĞÖØ´óµÄ¹±Ï×µÄÑ©²ÔÅÉµÜ×Ó²ÅÄÜÈë²Ø¾­¸óÑĞ¶Á!!!\n";
}

int do_join()
{
        if(this_player()->query("class"))
                return notify_fail("ÄãÒÑ¾­¼ÓÈëÆäËû¹¤»áÁË¡£\n");
        this_player()->set("class","fighter");
        message("system",
        HIC "ÌìÉúÓ¢²Å.....\n\nÒ»´úÎäÕß"+this_player()->name()+"µ®ÉúÁË !!!\n" NOR,users());
        return 1;
}
string test()
{
 object me;
 me=this_player();
 if(me->query("family/family_name") != "Ñ©²ÔÅÉ")
  {
   return "ÁõÈ«ÊéµÀ:ÕâÊÇÑ©²ÔÅÉµÄÊÂ,±ğµÄÃÅÅÉ²»ÓÃ¹ıÎÊ!!!!\n";
  }
if((int)me->query_skill("snow-martial",1)<70)
{
return "ÄãµÄÑ©²ÔÎäÑ§..Î´ÊìÁ·!!!ÎÒ¿´ËãÁË..°É..\n";
}
 say("ÁõÈ«ÊéÉòÒ÷Ò»ÏÂ!!!\n");
 say("ÁõÈ«ÊéµÀ:×î½üãñÉ½ÅÉµÄÕÆÃÅÈÎÕıÇçÀ´º¯,ÇëÎÒĞ­ÖúÏûÃğÔÚÆ½ÄÏ³Ç¸½½üµÄ¶À½Ç»¢!!!\n");
 say("ÁõÈ«µÀĞøµÀ:Õâ¸öÈÎÎñ¾Í½»¸øÄã°É....!!!\n");
 me->set("snow_test",1);
}
int accept_object(object who, object ob)
{
  if( ob->query("id") == "tiger-head")
  {
    destruct(ob);
    if((who->query("family/family_name") == "Ñ©²ÔÅÉ") && (who->query("snow_test") != 1))
     {
      say("ÁõÈ«Êé×ĞÏ¸µÄ¿´ÁË¿´!!,Ëµ:Õâ²»ÊÇ¶À½Ç»¢µÄÍ·!!¡£\n");
    return 0;
     }
    if((who->query("family/family_name") != "Ñ©²ÔÅÉ") || who->query("read_ok"))
     {
     say("ÁõÈ«Êé×ĞÏ¸µÄ¿´ÁË¿´!!,ËµµÀ:¹ûÈ»ÊÇ¶ñÊŞµÄÍ·!!¸ĞĞ»ÄãÎªÎäÁÖ³ı´Ë´óº¦¡£\n");
  return 1;
     }
   say("ÁõÈ«Êé×ĞÏ¸µÄ¿´ÁË¿´!!ËµµÀ:Õâ¹ûÈ»ÊÇ²Ğº¦ÎŞÊı°ÙĞÕ¶ñÊŞ--¶À½Ç»¢--µÄÍ·¡£\n");
   if(!who->query("allow_study"))
   {
    who->set("allow_study",1);
say("ºÃ°É£¡ÎÒ×¼Äã¶Á²Ø¾­¸óÄÚµÄÊé£¬µ«ÊÇÑ©²ÔÃØÂ¼¡¢¿İÒ¶²ĞĞÇÃØóÅ¡¢ºÍºÚÓ°²Ğ·çÂ¼Èı±¾ÊéÖ»×¼¶ÁÒ»±¾£¬¶øÇÒ¶ÁÒ»´Î¡£\n");
   }
   if(who->query("allow_study")==1)
    say("àÅ...²»ÊÇ¸úÄãËµ¹ıÁËÂğ£¿\n");
return 1;
  }
}
string super_fighter()
{
 object me;
 me=this_player();
 if((me->query("class") != "fighter") || (!me->query("ask_super_fighter")) )
  {
   return "ÁõÈ«ÊéµÀ:´ËµØÎªÎäÕß´«ËµÊ¥µØ,Ë¡ÄÑ·î¸æ!!!!\n";
  }
 if((me->query("family/family_name") == "ãñÉ½ÅÉ") && (me->query("title") != "ãñÉ½°ÂÒå´«ÈË"))
  {
   return "ÁõÈ«ÊéÅ­µÀ:Á¬×Ô¼ºÃÅÅÉµÄÃØ°ÂÒå¶¼Ã»ÓĞÑ§»áÁË,ÎÊÄÇÃ´¶à×öÊ²Ã´!!!\n";
  }
 if((me->query("family/family_name") == "Ñ©²ÔÅÉ") && (me->query("title") != "Ñ©²Ô¾øÑ§´«ÈË"))
  {
   return "ÁõÈ«ÊéÅ­µÀ:Á¬×Ô¼ºÃÅÅÉµÄ¾øÑ§¶¼Ã»ÓĞÑ§»áÁË,ÎÊÄÇÃ´¶à×öÊ²Ã´!!!\n";
  }
 say("ÁõÈ«ÊéÉòË¼ÁËÒ»ÏÂ!!!\n");
 say("ÁõÈ«ÊéÒ÷Ê«µÀ:------ÏÉ~ÔÆ~»¤~Æø~Áè¡¢Éí~ÔÚ~Ê¥~µØ~ÖĞ-----\n");
 say("ÁõÈ«ÊéĞøµÀ:ÉÏ¶ş¾äÄã¾ÍÈ¥ÎÊÈÎÕıÇç°É¡£!!\n");
 say("ÁõÈ«Êé×îºóµÀ:¾äÖĞµÄº­Òâ¾Í×Ô¼ºÌå»á°É¡£!!\n");
 me->set("ask_super_fighter",1);
}
void die()
{
   object winner = query_temp("last_damage_from");
   tell_object(users(),
   "\n\t[1mÏëÎÒ[1;36mÁõÈ«Êé[1;37m´³µ´ÎäÁÖÊıÊ®ÔØ,´ÓÎŞÒ»°Ü½ñÌì¾¹±»[33m"+winner->query("name")+"[1;37mËù°Ü!!ÕæÊÇÅå·ş!!Åå·ş!![0m\n");
 :: die();
}
