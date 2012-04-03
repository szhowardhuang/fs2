// master_jen.c
// Chan 22/5÷ÿ–¬…Ëº∆
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string test();
string kee_god();
string ask_yan();
string super_fighter();
void create()
  {
        set("class", "fighter");
        set_name("»Œ’˝«Á", ({ "master jen", "master", "jen" }) );
        set("title","„Ò…Ω≈…µ⁄∆ﬂ¥˙’∆√≈»À");
        set("nickname", "„Ò…Ω∆Êœ¿");
        set("gender", "ƒ––‘");
        set("age", 45);
        set("del_delay",1);
        set("attitude", "hero");
        set("long",
        "»Œ’˝«Á◊‘”◊…˙≥§”⁄Œ‰—ß√˚√≈÷–£¨ ‹∆‰∏∏°∏»Œ≤©Œƒ°±”¢≤≈ ΩµƒΩÃ”˝£¨ﬁπ\n"
        "Ã’≥ˆ∆‰—œÀ‡∂¯«´—∑µƒ»À∏Ò£¨…ÌŒ™„Ò…Ω≈…’∆√≈µƒÀ˚£¨“‘∑¢—Ô„Ò…ΩŒ™º∫»Œ\n"
        "£¨∂‘”⁄Œ•∑¥≈…πÊµƒµ‹◊”∫¡≤ª¡Ù«È£¨»Á¥ÀæÕø…ø¥≥ˆ∆‰—œÀ‡µƒ∏ˆ–‘\n");
        set("str", 48);
        set("cps", 40);
        set("per", 34);
        set("int", 38);
        set("kar", 16);
        set("fire_strike",1);
        set("super_fire",1);
        set("combat_exp",5000000);
        set("max_kee",30000);
        set("kee",30000);
        set("max_gin",15000);
        set("gin",15000);
        set("max_sen",15000);
        set("sen",15000);
        set("force"       , 15000);
        set("max_force"   , 15000);
	set("atman"       , 15000);
        set("max_atman"   , 15000);
	set("mana"       , 15000);
        set("max_mana"   , 15000);
        set("force_factor", 40);
        set("score"       , 200000);
        set("s_kee",1000);
        set("env/„Ò…Ω¡¨ª˜","YES");
        set("max_s_kee",1000);
        set("sec_kee","tiger");
        set("inquiry",([
                 "„Ò…Ω»≠∑®":   "¥ÀŒ™»Œº“¥´≥–µƒæ¯—ß£¨∑÷Œ™°∏Àÿ’–°±°¢°∏Ω˚∂œ°±°¢°∏∞¬“Â°±»˝÷÷°£ ",
                 "Àÿ’–":       " «„Ò…Ω»≠∑®÷–Ωœ“◊—ß°¢Õ˛¡¶Ωœ–°µƒ’– Ω°£\n",
                 "Ω˚∂œ":       "„Ò…ΩΩ˚∂œπ≤”–°∏…ΩÀÆ÷Æ∆¯°±°¢°∏∫–•…Ω¡÷°±∂˛’–°£\n"
                               "÷ª”–„Ò…Ω»≠∑®÷¡µ«∑Â‘Ïº´÷Æº ≤≈ƒ‹Ω” ‹øº—È¥´ ⁄\n",
                 "∞¬“Â":       " «…œ»Œ’∆√≈»Œ‰ﬂŒƒΩ´„Ò…Ω»≠Ω·∫œ∫∆»’’Ê∆¯À˘¥¥≥ˆµƒæ¯’–°£\n"
                               "≥∆÷ÆŒ™°Æ≥‡—Ê…Ò’∆°Øπ≤»˝ Ω\n"
                               "÷ª”–„Ò…Ωæ¯—ß¥´»À«“”–Ãÿ±π±œ◊≤≈ƒ‹¥´ ⁄\n",
                 "Ω˚∂œøº—È":   (: test :),
                 "∑Á«‡‘∆" : (: ask_yan :),
                 "œ…‘∆÷Æ∆¯":   (: kee_god :),
                 "–˛ÃÏ •µÿ":   (: super_fighter :),
                 "“∂øÒ":       "»˝ ÆƒÍ«∞∫·––Ω≠∫˛Œﬁ∂Ò≤ª◊ˆµƒ¥ÛƒßÕ∑£¨±ª…œ¥˙’∆√≈«ÙΩ˚‘⁄º‡¿Œ÷–\n",
                 "º‡¿Œ":       "‘⁄„Ò…ΩµƒΩ˚µÿ÷–\n",
          ]));
        set("functions/kang_kee/level",100);
        set_temp("roared", 1 );
		set_temp("kang-power", 1 );
        set_skill("cure",40);
        set_skill("move",50);
        set_skill("unarmed", 120);
        set_skill("force",120);
        set_skill("parry",50);
        set_skill("dodge",50);
        set_skill("fire-kee",100);
        set_skill("literate",40);
        set_skill("henma-steps",100);
	set_skill("literate",30);
        set_skill("lungshan",100);
	set_skill("haoforce",100);

        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
            (: perform_action, "force.kang_kee"   :),
        }));
        create_family("„Ò…Ω≈…", 7, "’∆√≈»À");
        setup();
            carry_object(__DIR__"ywleg")->wear();
            carry_object(__DIR__"ywboots")->wear();
            carry_object(__DIR__"ywcloth")->wear();
            carry_object(__DIR__"ywgem")->wear();
            carry_object(__DIR__"ywhelme")->wear();
            carry_object(__DIR__"ywhand")->wear();
            carry_object(__DIR__"ywsu")->wear();
            carry_object(__DIR__"armband")->wear();
               carry_object(__DIR__"star");
                carry_object(__DIR__"figring")->wield();
        add_money("gold",40);
}

int accept_object(object who, object ob)
{
  object mid;
  if( ob->query("id") == "ya-head")
  {
    destruct(ob);
    say("»Œ’˝«Á◊–œ∏∂‘“∂øÒµƒÕ∑…Û ”,Àµµ¿:’‚æπ»ª «°Æ—™ƒß°Ø“∂øÒµƒÕ∑°£\n");
    who->set("quests/ya",1);
    if( who->query("family/family_name")=="„Ò…Ω≈…"&&who->query_skill("lungshan",1) < 70)
	{
	 say("»Œ’˝«Á≈≠µ¿:„Ò…Ω≈…µƒŒ‰—ß∂º√ª”–—ß∫√¡À,ªπœÎ—ß ≤√¥Ω˚ºº!!!\n");
	 return 0;
    }
    else if( who->query("family/family_name")=="„Ò…Ω≈…")
     {
	 
      if(!who->query("fire_strike",1))
       {
        say("ƒ„Œ™Œ‰¡÷≥˝»•’‚ÕÚ∂ÒƒßÕ∑£¨¡¢œ¬»Á¥À¥Ûµƒπ¶¿Õ!\n"
            "‡≈!!∫√∞…!!Œ“±„Ω´„Ò…Ωµƒ÷’º´∞¬“Â°Æ≥‡—Ê…Ò’∆°Ø¥´ ⁄∏¯ƒ„\n");
        who->set("fire_strike",1);
        who->set("title","„Ò…Ω∞¬“Â¥´»À");
       }
      else
       {
        say("ƒ„Œ™Œ‰¡÷≥˝»•’‚ÕÚ∂ÒƒßÕ∑£¨¡¢œ¬»Á¥À¥Ûµƒπ¶¿Õ!!\n"
            "’‚–© «Œ“∂‡ƒÍ¿¥ ’ºØµƒ—©¡´µ§º∞¡È÷•œ…µ§∂º∏¯ƒ„∞…\n");
        mid=new("/open/gsword/obj/ff_pill");
        mid->add_amount( who->query("per")+100 );
        mid->move(who);
        mid=new("/open/gsword/obj/f_pill");
        mid->add_amount( who->query("per")+100 );
        mid->move(who);
       }
     }
     else
     {
      if(!who->query("get_force",1))
       {
        say("ƒ„Œ™Œ‰¡÷≥˝»•’‚ÕÚ∂ÒƒßÕ∑£¨¡¢œ¬»Á¥À¥Ûµƒπ¶¿Õ!!\n"
            "‡≈!!∫√∞…!!Œ“Ω´≤ø∑›ƒ⁄¡¶¥´ ⁄∏¯ƒ„∞…!!\n");
        message_vision(HIC"»Œ’˝«ÁΩ´À´ ÷∞¥◊°$NÃ¥÷–—®£¨’Ê∆¯À≤ ±º‰¥ÚÕ®$Nµƒ»Œ∂Ω∂˛¬ˆ\n",who);
        who->add("max_force",200);
        who->set("get_force",1);
       }
      else
       {
        say("ƒ„Œ™Œ‰¡÷≥˝»•’‚ÕÚ∂ÒƒßÕ∑£¨¡¢œ¬»Á¥À¥Ûµƒπ¶¿Õ!!\n"
            "’‚–© «Œ“∂‡ƒÍ¿¥ ’ºØµƒ—©¡´µ§º∞¡È÷•œ…µ§∂º∏¯ƒ„∞…\n");
        mid=new("/open/gsword/obj/ff_pill");
        mid->add_amount( who->query("per")+100 );
        mid->move(who);
        mid=new("/open/gsword/obj/f_pill");
        mid->add_amount( who->query("per")+100 );
        mid->move(who);
       }
     }
} else
  if( ob->query("id") == "tiger-head")
  {
    destruct(ob);
    if((who->query("family/family_name") == "„Ò…Ω≈…") && (who->query("lungshan_test") != 1))
     {
      say("»Œ’˝«Á◊–œ∏µƒø¥¡Àø¥!!,Àµ:’‚≤ª «∂¿Ω«ª¢µƒÕ∑!!°£\n");
      return 0;
     }
    if((who->query("family/family_name") != "„Ò…Ω≈…") || who->query("super_fire"))
     {
      say("»Œ’˝«Á◊–œ∏µƒø¥¡Àø¥!!,Àµµ¿:π˚»ª «∂Ò ﬁµƒÕ∑!!∏––ªƒ„Œ™Œ‰¡÷≥˝¥À¥Û∫¶°£\n");
      who->set("go_ya",1);
      return 0;
     }
    say("»Œ’˝«Á◊–œ∏µƒø¥¡Àø¥!!Àµµ¿:’‚π˚»ª «≤–∫¶Œﬁ ˝∞Ÿ–’∂Ò ﬁ--∂¿Ω«ª¢--µƒÕ∑°£\n");
    if(!who->query("super_fire",1))
     {
     say("»Œ’˝«Áµ¿:ƒ„π˚»ª≤ª∏∫Œ“À˘∆⁄Õ˚£¨ÕÍ≥…’‚ºËƒ—µƒ»ŒŒÒ!!\n"
         "∫√!!’‚ «„Ò…Ω»≠Ω˚∂œººµƒ∞¬√‹æÕ¥´ ⁄∏¯ƒ„∞…!!,Õ˚ƒ„∏¸…œ“ª≤„¬•°£\n");
     who->set("super_fire",1);
     who->set("title","„Ò…Ωæ¯—ß¥´»À");
      who->set("go_ya",1);
     }
  }
}

int accept_fight(object who)
{
 command("say π˚»ª”¢–€≥ˆ…ŸƒÍ°£\n");
 who=this_player();
 fight_ob(who);
 command("cmd usekee "+who->query("id"));
 command("charge "+who->query("id"));
// command("perform force.kang-power");
  return 1;
}

int accept_kill(object who)
{
 command("say ’“À¿!!!\n");
 who=this_player();
 kill_ob(who);
 command("cmd usekee "+who->query("id"));
 command("charge "+who->query("id"));
// command("perform force.kang-power");
  return 1;
}
  void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="fighter")
        {
                command("sigh");
                command("say ƒ„≤ª «Œ‰’ﬂ£¨Œ“≤ªƒ‹ ’ƒ„°£\n");
                return;
        }
      if((int)ob->query("cps") <20 )
{
          command("sigh");
          command("say —ß„Ò…Ω»≠∑®±ÿ–Î”–∫„–ƒ£¨±÷»Àπ€÷Æ"+ RANK_D->query_respect(ob) + "µƒ◊ ÷ À∆∫ı≤ª“À£°\n");

return;
        }

      command("hmm");
      command("pat" + ob->query("id"));
      command("recruit "+ob->query("id"));
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
		message_vision(HIW"\n÷ªº˚$N±©∆À˘”–"HIY"’Ê∆¯ƒ⁄æ¢"HIW"£¨$N»´…Ì¬§’÷‘⁄“ªπ…"HIC"’¿¿∂∆¯æ¢"HIW"÷–£¨∫’»ª“—Ω‚ø™…Ì…œ±ª∑‚µƒ—®µ¿°£\n"NOR,this_object());
        delete_busy();
		}
		}
		::heart_beat();
}

string ask_yan()
{
  object me;
  me=this_player();
  if( me->query("fyan")==5)
{
command("say ƒ˙Àµ∑Á«‡‘∆«∞±≤®⁄,◊ÚÃÏÀ˚‘¯¿¥’“Œ“…Ã¡ø”˚ΩËŒ“¬§…Ω”Î¡ı»´ È—©≤‘÷Æ¡¶,“‘∂‘∏∂—™ƒß≈”¥Ûµƒ ∆¡¶,Ã∏ÕÍ∫Û..À˚æÕÕ˘—©≤‘»•¡À°£\n ");
me->set("fyan",6);
}
  else
    {
   command("say Œ“≤ª«Â¥¶ﬂœ~°£\n");
    }
}

string test()
{
 object me;
 me=this_player();
 if(me->query("family/family_name") != "„Ò…Ω≈…")
  {

   return "»Œ’˝«Á≈≠µ¿:≤ª «„Ò…Ωµ‹◊”Œ ƒ«‘ı√¥∂‡◊ˆ ≤√¥!!!!\n";
  }
 if(me->query_skill("lungshan",1)   < 70)
  {
   return "»Œ’˝«Á≈≠µ¿:„Ò…Ω≈…µƒŒ‰—ß∂º√ª”–—ß∫√¡À,ªπœÎ—ß ≤√¥Ω˚ºº!!!\n";
  }
 say("»Œ’˝«Á…Ú“˜“ªœ¬!!!\n");
 say("»Œ’˝«Áµ¿:◊ÓΩ¸÷–—Î“Î’æÕ˘∆Ωƒœ≥«µƒ∑ΩœÚ,Ã˝Àµ”–“ª÷ª∂¿Ω«ª¢∫·––,Œ£∫¶–ÌŒﬁ ˝µƒ∞Ÿ–’!!\n");
 say("»Œ’˝«Á–¯µ¿:÷ª“™ƒ„≥˝¥À¥Û∫¶!!Œ“æÕΩ´Ω˚ºº¥´ ⁄∏¯ƒ„!!!\n");
 me->set("lungshan_test",1);
}
string kee_god()
{
 object me;
 me=this_player();
 if(!me->query("ask_god_kee"))
  {
   return "»Œ’˝«Áµ¿:¥À ¬ «Œ‰¡÷÷–÷ÿ¥Û√ÿ¥´!!À°ƒ—∑Ó∏Ê!!!!\n";
  }
 say("»Œ’˝«Á…ÚÀº¡À“ªœ¬!!!\n");
 say("»Œ’˝«Áµ¿:∂¿π¬‘∆º»»ª∂º∏˙ƒ„Àµ¡À..Œ“æÕ∏ÊÀﬂƒ„∞…!!\n");
 say("»Œ’˝«Á–¯µ¿:œ…‘∆÷Æ∆¯‘⁄ÃÏ¡Èπ»÷Æ÷–,µ´“™Ω¯ÃÏ¡Èπ»±ÿ–Î“™”–«‡¡˙÷Æ∆¯º∞ÃÏ¡È Ø≤≈ƒ‹Ω¯!!\n");
 say("»Œ’˝«Á”÷µ¿:÷¡”⁄ÃÏ¡Èπ»µƒŒª÷√µƒª∞!!‘⁄—©≤‘…Ω÷Æ÷–◊‘º∫’“∞…!!\n");
 me->set("ask_god_kee",2);
}
string super_fighter()
{
 object me;
 me=this_player();
 if((me->query("class") != "fighter") || (!me->query("ask_super_fighter")) )
  {
   return "»Œ’˝«Áµ¿:¥ÀµÿŒ™Œ‰’ﬂ¥´Àµ •µÿ,À°ƒ—∑Ó∏Ê!!!!\n";
  }
 if((me->query("family/family_name") == "„Ò…Ω≈…") && (me->query("title") != "„Ò…Ω∞¬“Â¥´»À"))
  {
   return "»Œ’˝«Á≈≠µ¿:¡¨◊‘º∫√≈≈…µƒ√ÿ∞¬“Â∂º√ª”–—ßª·¡À,Œ ƒ«√¥∂‡◊ˆ ≤√¥!!!\n";
  }
 if((me->query("family/family_name") == "—©≤‘≈…") && (me->query("title") != "—©≤‘æ¯—ß¥´»À"))
  {
   return "»Œ’˝«Á≈≠µ¿:¡¨◊‘º∫√≈≈…µƒæ¯—ß∂º√ª”–—ßª·¡À,Œ ƒ«√¥∂‡◊ˆ ≤√¥!!!\n";
  }
 say("»Œ’˝«Á…ÚÀº¡À“ªœ¬!!!\n");
 say("»Œ’˝«Á“˜ ´µ¿:------—©~…Ω~…Ó~¡Î~÷–°¢≤‘~ÃÏ~“ª~÷˘~∑Â-----\n");
 say("»Œ’˝«Á–¯µ¿:œ¬∂˛æ‰ƒ„æÕ»•Œ ¡ı»´ È∞…°£!!\n");
 say("»Œ’˝«Á◊Ó∫Ûµ¿:æ‰÷–µƒ∫≠“‚æÕ◊‘º∫ÃÂª·∞…°£!!\n");
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
	tell_object(users(),"\n\t[1;37m°´°´[36m≥§Ω≠∫Û¿ÀÕ∆«∞¿À «∞¿ÀÀ¿‘⁄…≥Ã≤…œ[1;37m°´°´[0m\n"+
	"\n\t[1;37mœÎ≤ªµΩ„Ò…Ω’∆√≈[36m»Œ’˝«Á[37mæπ±ªª˜∞‹,ø¥¿¥Œ‰¡÷Ω´“‘[33m"+winner->query("name")+"[1;37mŒ™[1;31m÷¡◊[1;37m¡À!![0m\n");

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj3/fire_feather")->move(environment(winner));
	  message_vision(HIM"\n¥”»Œ’˝«Áµƒ…Ì…œµÙœ¬¡À“ªº˛∆Êπ÷µƒ∂´Œ˜!!\n"NOR,winner);
          write_file("/log/sky/fire_feather",sprintf("%s(%s) »√»Œ’˝«ÁµÙœ¬¡Àª÷Æ—Ê””⁄ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj3/fire_feather")->move(environment(winner));
	  message_vision(HIM"\n¥”»Œ’˝«Áµƒ…Ì…œµÙœ¬¡À“ªº˛∆Êπ÷µƒ∂´Œ˜!!\n"NOR,winner);
          write_file("/log/sky/fire_feather",sprintf("%s(%s) »√»Œ’˝«ÁµÙœ¬¡Àª÷Æ—Ê””⁄ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
 :: die();
}
