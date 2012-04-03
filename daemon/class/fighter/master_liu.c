// ±à¸Ämaster_liu , Ôö¼Ó½øÈëĞ°Áé½çµÄÏŞÖÆstring ask_evil(), 2001/8/8 write by Firedancer
// ÖØĞÂÉè¼Æmaster_liu by Chan
// Ôö¼ÓĞí¶à¹¦ÓÃ
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string book();
string ask_yan();
string icef();
string test();
string super_fighter();
string ask_evil();
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
   set("force", 15000);
   set("max_kee",30000);
   set("kee",30000);
   set("quests/read_snow",3);
      set("max_gin",15000);
      set("gin",15000);
          set("sen",15000);
          set("max_sen",15000);
   set("s_kee",1000);
   set("max_s_kee",1000);
   set("sec_kee","tiger");
   set_temp("roared", 1 );
   set("inquiry",([
        "ÌìĞ°Ê¯":   "Ê¦¸¸ÁÙÖÕÇ°Ôø½»¸øÎÒÕâÑù±¦Îï£¬ËûËµ´ËÎïµ±ÔùÓëÓĞÔµÈË¡£",
        "ÓĞÔµÈË":   "ÄÜËµ³öÊ®ÄêÇ°ÎäÁÖÈı´ó¸ßÊÖÕß£¬¼´ÎªÓĞÔµÈË¡£\n",
        "²Ø¾­¸ó":  (: book :),
        "ĞşÌìÊ¥µØ":   (: super_fighter :),
        "¹±Ï×":   (: test :),
         "·çÇàÔÆ" : (: ask_yan :),
//      "ÓñÃÅ¹Ø" : (: ask_sec :),
        "ÕğĞ°µÀ" : (: ask_evil :),
          ]));
    set_skill("literate",30);
   set("force_factor", 70);
   set("max_force",15000);
      set_skill("snow-kee",100);
   set_skill("cure",40);
          set_skill("move",50);
   set_skill("force",120);
   set_skill("magic",20);
   set_skill("dodge",50);
       set_skill("parry",50);
   set("functions/ice-fingers/level",100);
   set("functions/snow-powerup/level",100);
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

// by babe
void heart_beat()
{
        if( !is_fighting() ) {
        if( query("sen") < query("eff_sen") ) // 125
                        command( "exert refresh" );
                if( query("force") < query("max_force") ) // 1 -> 5.035
                        command( "ex 160" );
                if( query("eff_kee") < query("max_kee") ) // 35
                        command( "10 exert heal" );
                if( query("gin") < query("eff_gin") ) // 125
                        command( "exert regenerate" );
                if( query("kee") < query("eff_kee") ) // 125 -> 300
                        command( "3 exert recover" );
                
        }
		if(is_busy() ){
		if(30>random(100)){
		message_vision(HIW"\nÖ»¼û$N±©ÆğËùÓĞ"HIY"ÕæÆøÄÚ¾¢"HIW"£¬$NÈ«ÉíÂ¤ÕÖÔÚÒ»¹É"HIC"ÕÀÀ¶Æø¾¢"HIW"ÖĞ£¬ºÕÈ»ÒÑ½â¿ªÉíÉÏ±»·âµÄÑ¨µÀ¡£\n"NOR,this_object());
        delete_busy();
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
 command("say ¹ûÈ»Ó¢ĞÛ³öÉÙÄê¡£\n");
 fight_ob(who);
 command("charge "+who->query("id"));
 command("perform snow-kee.snow-powerup");
 command("cmd usekee "+who->query("id"));
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

string ask_evil()
{
object me,ob;
        me=this_player();
        ob=this_object();
        call_out("do_evil",1,me);
        return "àÅ...\n\n";
}

int do_evil()
{
object me,ob,obj;
int i=sizeof(users());
        me=this_player();
        ob=this_object();
        i=i/4;
        if(i < 1)
                i=3;
        if(i > 6)
                i=6;
        if(me->query_temp("evil/w_temp/ask"))
        {
                tell_object(me,
"ÁõÈ«ÊéËµ£ºÀÏÄÉÒÑ¾­½«¿¼Ñé¸æËßÄãÁË¡«
           
           µ±È»£¬Èç¹ûÄã½«ÀÏÄÉ¸øÄãµÄÌû×ÓÒÅÊ§£¬ÄÇÀÏÄÉÒ²°®ÄªÄÜÖú¡£\n");
                return 0;
        }
        message_vision("
$NËµµÀ£ºÀÏÄÉÏëÒª¿¼ÑéÒ»ÏÂ$NµÄÈÊµÂÆ·ĞĞ£¬Èç¹ûÍ¨¹ıÀÏÄÉµÄ¿¼Ñé£¬ÄÇÀÏÄÉ¾Í´ğÓ¦ÄãµÄÇëÇó¡£

$N×ßµÀ·¿ÄÚ...¹ıÒ»¶ÎÊ±¼äºó£¬ÄÃ×ÅÒ»ÕÅÌû×Ó³öÀ´¡£

$NËµµÀ£º¿¼ÑéºÜ¼òµ¥£¬Ö»ÒªÄãÊÕ¼¯µ½ "+i+" Î»ÈËÊ¿µÄÇ©Ö¤£¬ÀÏÄÉ¾Í´ğÓ¦ÈÃÄãÈ¥¡£\n

$N½«Ìû×Ó½»¸øÁË$n¡£\n\n",ob,me);
        obj=new("/open/evil-area/npc/obj/paper");
        obj->set_temp("paper_count",i);
        obj->set_temp("paper_owner",me->query("id"));
        obj->move(me);
        me->set_temp("evil/w_temp/ask",1);
return 1;
}


int do_say(string str,object ob)
{
     object who;
        who=this_player();
        if(who->query("get_stone")==1){
           return 0;}//¼ÇµÃºÜ¾ÃÖ®Ç°lum¾ÍÒªÎÒ¸Ä³ÉÕâÈı¸öpplµÄÃû×ÖÁËÕâĞ©ÈËÒ²ËãÊÇÀúÊ·
        else {              //ÁË...³ıÁËsulaÕâÀÏÔô..so...ÔÙ°ÑËû¸Ä³ÉÕâÈı¸ö..........cgy
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
string ask_yan()
{
  object me;
  me=this_player();
  if( me->query("fyan")==6)
{
command("say ·çÇàÔÆÇ°±²¨Ú,×òÍíËûÑ©²ÔÉ½Ò»ÌË²¢È«Á¦ÑûÇëÎÒ¼ÓÈë¶Ô¿¹ÑªÄ§µÄĞĞÁĞ..Ì¸Íêºó..Ëû¾Í»ØÏÉ½£È¥ÁË¡£\n ");
me->set("fyan",7);
}
  else
    {
   command("say ÎÒ²»Çå´¦ßÏ~¡£\n");
    }
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
        if(ob->query("id")=="paper")
        {
                if(ob->query_temp("paper_owner")!=who->query("id"))
                {
                message_vision(
"$NËµ£ºÕâ¸ö$n²»ÊÇÄãµÄ°É...ÈÃÀÏÄÉÔİÊ±ÏÈ½«ËüÊÕÆğÀ´...\n\n
$NËµÍê±ã°Ñ$n¸øÊÕÆğÀ´ÁË¡£\n",this_object(),ob);
                destruct(ob);
                return notify_fail("»¹ÓĞÊ²Ã´ÊÂÇéÂğ£¿\n");
                }
                if((int)ob->query_temp("paper_count_times") > (int)ob->query_temp("paper_count"))
                {
                message_vision(
"$NËµ£ººÃ°É£¬¼ÈÈ»ÄãÒ²Í¨¹ıÎÒµÄ¿¼ÑéÁË¡£ÀÏÄÉÓ¦³ĞÄã£¬ÈÃÄã¿ÉÒÔÍ¨¹ı¡²·ûÎÆÕó¡³µÄË®Ö®Õó¡£\n

"HIW"$NÔËÆğÑ©²ÔĞÄ·¨£¬½áËªÓÚÕÆ£¬ÃÍÈ»»÷Ïò$n£¬$nµÄ¶îÍ·¶¸È»¸¡ÏÖ³öÒ»¸ö¡²Ë®¡³×Ö¡£\n"NOR,this_object(),who);
                who->set_temp("evil/w_enter",1);
                who->delete_temp("evil/w_temp");
                destruct(ob);
                return notify_fail("ÕâÑù¾ÍĞĞÁË¡£\n");
                }
                else
                {
                message_vision("$NËµµÀ£ººÜ±§Ç¸£¬Ìû×ÓÉÏµÄÈËÊıÉĞÎ´µ½´ïÀÏÄÉËù¶¨µÄ±ê×¼...Ê©Ö÷Çë»Ø°É¡£\n",ob,who);
                who->delete_temp("evil/w_temp");
                destruct(ob);
                return notify_fail("Ê©Ö÷Çë»Ø°É¡£\n");
                }
        }
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
        int j;
        if(!winner)
        {
        ::die();
        return ;
        }
        tell_object(users(),
   "\n\t[1mÏëÎÒ[1;36mÁõÈ«Êé[1;37m´³µ´ÎäÁÖÊıÊ®ÔØ,´ÓÎŞÒ»°Ü½ñÌì¾¹±»[33m"+winner->query("name")+"[1;37mËù°Ü!!ÕæÊÇÅå·ş!!Åå·ş!![0m\n");

        if ( winner->query_temp("bless")==1 )
        {
        j=random(6000);
          if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
          {      
          new("/open/sky/obj1/ice_emblem")->move(environment(winner));
          message_vision(HIM"\n´ÓÁõÈ«ÊéµÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/ice_emblem",sprintf("%s(%s) ÈÃÁõÈ«ÊéµôÏÂÁË±ùÖ®ÎÆÕÂÓÚ %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }else{
        j=random(12000);
          if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
          {      
          new("/open/sky/obj1/ice_emblem")->move(environment(winner));
          message_vision(HIM"\n´ÓÁõÈ«ÊéµÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/ice_emblem",sprintf("%s(%s) ÈÃÁõÈ«ÊéµôÏÂÁË±ùÖ®ÎÆÕÂÓÚ %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }
 :: die();
}
