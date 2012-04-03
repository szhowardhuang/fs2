#include "/open/mogi/castle/npc/castle.h"
#include <ansi.h>
inherit NPC;
   
void create()
{
	set("long","
    ·ÙÌìÄ§Íõ, Ä§½çÖ®Í³ÖÎÕß, ËûÈ«Éí»ğÑæÈÆÉí, »ğÉàËæ×ÅËûµÄÇéĞ÷²»Í£µÄ±¼ÌÚ×Å¡£
×ĞÏ¸Ò»¿´Ëû¾¹¿ÉÒÔÓùÆøÁè¿Õ, ÄÚ¹¦Ö®Éî¼òÖ±²»¿ÉË¼Òé¡£ÁíÍâÁ·¾Í¿õÊÀ¾øÑ§¡¸¼«»ğ¹¦¡±
, ¼«»ğÕÆÒ»·¢¶¯¸üÊÇÁÒÑæ±¼ÌÚ, Íş²»¿Éµ²¡£ÓÉ¼«»ğ¹¦Ëù»¯³ÉµÄ¡¸¼«»ğ½ğÉí¡±»¤Éí
Æø¾¢¸üÄÜÔÚËÄÖÜĞÎ³É¼áÓ²»ğÕÖ¡£
");
        set("gender","ÄĞĞÔ");
        set("nickname",HIR"³àÓü»ìãä"NOR);
        set("title","Ä§½çÖ®Íõ");
        set_name("·ÙÌìÄ§Íõ",({"fire king","king"}));
        set("combat_exp",16000000);
        set("class","fighter");
        set("attitude","aggressive");
        set("score",90000000);
        set("bellicosity",1000000);
        set("age",10000);
        set("max_force",70000);
        set("force", 250000 ); 
        set("max_kee",70000);
        set("max_gin",70000);
        set("max_sen",70000);
        set("str", 35);
        set("cor", 35);
        set("cps", 35);
        set("int", 35);
        set("con", 35);
        set("kar", 35);
        set("force_factor",50);
        set_skill("dodge",200);
        set_skill("force",250);
        set("no_mount",1);
        set("no_plan_follow",1);
        set_skill("move",280);
        set_skill("parry",200);
        set_skill("mogi-steps",200);
        set_skill("firestrike",220);
        set_skill("unarmed",220);
        set_skill("literate",200);
        set_skill("fireforce",250);
        set_temp("apply/defense",60);
        set_temp("apply/armor",60);
        set_temp("apply/attack",30);
        set_temp("no_die_soon",1);
        map_skill("force","fireforce");
        map_skill("unarmed","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("parry","firestrike");
        set("functions/gold-fire/level",100);
        set("quest/gold-fire",1);
        set("quest/new_gold_fire",1);
        setup();
        carry_object("open/mogi/castle/obj/fire-king-head");
        carry_object("/data/autoload/mogi/fire-armor")->wear();
        carry_object("/data/autoload/mogi/fire-cloud-boots")->wear();
        carry_object("/data/autoload/mogi/fire-belt")->wear();
        carry_object("/data/autoload/mogi/daemon-cloak")->wear();
        carry_object("/data/autoload/mogi/fire-dragon")->wield();
        carry_object("/open/mogi/castle/obj/blood-water");   
        carry_object("/data/autoload/mogi/sspill")->set_amount(7);
        carry_object("/open/killer/headkill/obj/world_dag.c");
        add_money("gold",1000);
}

void init()
{
	::init();
	add_action( "block_cmd", "" );
	add_action( "do_cmd", "cmd" );
	add_action( "do_exert", "exert" );
	if( this_player()->query("combat_exp") < 2500000 )
		add_action( "do_kill", "kill" );
}

// µ² do, ÒÔÃâ cmd ÅĞ¶ÏÊ§Ğ§ by ACKY
int block_cmd( string arg )
{
	if( (string)query_verb() == "do" ) {
		write( HIY"·ÙÌìÄ§ÍõÀäĞ¦:¡¸ÏëË£ÏÂÈıÀÃµÄ¼¼Á©?! ºß! È¥ËÀ°É!¡±\n"NOR );
		if( is_fighting() )
			this_player()->start_busy(1);
		return 1;
	}
}

int do_cmd(string str){                 //ok by chan
 string arg;
 object who=this_player();
 object ob,king;
 ob=this_object();
 king=present( "king",environment(ob) );
 
	if( !str )
		return 0;

 if(str=="askgod king" || str=="askgod fire king"){
 write(HIY"·ÙÌìÄ§ÍõÀäĞ¦£º¡¸ÔÚ±¾Ä§ÍõÃæÇ°ÇóÉñÎÊ²·!?ÏÈÎÊÎÊÎÒ»¹²î²»¶à¡£¡±È¥ËÀ°É!!\n"NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;
}
 if(str=="vet king" || str=="vet fire king"){
 write(HIY"·ÙÌìÄ§ÍõÅ­³âµÀ£º¡¸ËÀÓ¹Ò½èÆÔÚÕâÀï¸ÉÊ²Ã´£¿£¡²»ÈçÎÒËÍÄãÒ»³Ì°É£¡£¡¡±\n"NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;
}
 if(str=="bak king"){
 write(HIY"·ÙÌìÄ§ÍõÀäĞ¦£ºÏë°µÉ±±¾Ä§Íõ!!!Ò²²»´òÌıË­ÊÇ°µÉ±Ö®ÍõÑ½!!!È¥ËÀ°É!!\n"NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;
                  }

	if( sscanf( str, "%s %s", str, arg ) )
		if( str=="throw" ) {
			write( HIY"·ÙÌìÄ§ÍõÀäĞ¦:¡¸Ïë¸ÉÊ²Ã´? ¹ö¿ª!¡±\n"NOR );
			return 1;
		}
}

int do_kill( string str )
{
	object me = this_player();

	if( (str=="fire king"||str=="king") && me->query("combat_exp")<2500000 ) {
		write( HIY"·ÙÌìÄ§ÍõÀäÀäµØËµ:¡¸Äã²»¹»×Ê¸ñÉ±ÎÒ!¡±\n"NOR );
		return 1;
	}
	return 0;
}

void greeting( object me )
{
	write( HIY"·ÙÌìÄ§Íõ·¢³öÉåÈËĞÄÉñÉùÒô:\n\t¡¸À´ÕßºÎÈË¡«¡«¡±
\t¡¸ÄÜÀ´µ½ÕâÀï, Õæ²»¼òµ¥! ½­ºşÖ®ÉÏµÄÈËÎï, ËãÄãÒ»ºÅ!¡±
\t¡¸²»¹ıÈôÏëÕÒÎÒ±È»®, Äã»¹²îµÃÌ«Ô¶!¡±
"NOR ); 
}

int accept_fight(object who)
{
	write( HIY"·ÙÌìÄ§ÍõÀäÀäµØËµ:¡¸ÒªÃüµÄ»°¾Í¿ì×ß°É!¡±\n"NOR );
	return 0;
}

int do_exert( string str )
{
	mixed	all;
	int	i;
	object	me;
	me	= this_player();
	all	= all_inventory(environment(me));

	if( str=="roar" ) {
		say(HIC"$NÆøÄıµ¤Ìï, ÓÃÁ¦Ò»ºğÆóÍ¼ÒÔÄÚÁ¦ÕğÉË·ÙÌìÄ§Íõ¡£\n", me );
		say(HIC"·ÙÌìÄ§ÍõÀäĞ¦Ëµ¡®ÄãÕâÒ²½Ğºğ? ÈÃÄãÃÇ¼ûÊ¶Ò»ÏÂÕæÕıµÄ"HIR"ÌìÄ§¿ñºğ"HIC"°É!\n");
		say(HIR"\n·ÙÌìÄ§Íõ´óºğÒ»Éù, É²ÄÇ¼äÌì¾ªµØÒ¡, Ä§½çÒò´Ë¶øÕğ¶¯! ÖÜÔâµÄÉúÎïÉ²ÄÇ¼ä·ÇËÀ¼´ÉË!\n");
		message_vision( HIR"½á¹ûËùÓĞÈË±»ÕâÍşÁ¦ÎŞ±ÈµÄÌìÄ§Å­ºğÕğÉË, ÍÛÒ»ÉùÍÂ³öÒ»´ó¿ÚÏÊÑª!\n"NOR, me );
		for( i=0 ; i<sizeof(all); i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
				all[i]->add( "kee", -600 );
all[i]->delete_temp("hardshell");
				COMBAT_D->report_status( all[i], 1 );
			}
		return 1;
	}
	return 0;
}

int accept_kill( object who )
{
	write( HIY"·ÙÌìÄ§Íõ´Ó±¦×ùÉÏ»íÈ»Õ¾Æğ!\n"NOR );
	command("say Êó±²ÎŞÀñ! ‡Ÿ‡ŸÎÒ¼«»ğ¹¦µÄÀ÷º¦°É!");
	if( !is_fighting() )
		command("perform fireforce.gold-fire");
	return 1;
}

void heart_beat()
{
	mixed	all;
	object	king;
	int	i, j, tmp , count;

	king	= this_object();
	all	= all_inventory(environment(king));
	count = random(100);
	j = random(3)+1;

//¸Ä±äĞÄÌø³ö»÷·½Ê½£¬fire king±¾ÉíÄÜÁ¦ÒÑ¾­±©ÃÍÁË£¬ÔËÆø²»ºÃĞÄÌø
//ÓÖÒ»´ÎÈ«³ö£¬ÊµÔÚÊÇÌ«Ç¿ÁË£¬¾ÍËãÔÙÇ¿µÄpplÒ²»áÒ»Ö±±»delayµ½ËÀ£¬
//Á¬ÌÓµÄ»ú»áÒ²Ã»ÓĞ£¬ËùÒÔ¸ü¶¯ĞÎÊ½£¬¸Ä³ÉÈ«Ê±¶Î³ö£¬Ã¿Ò»´ÎĞÄÌø»áËæ
//»úÒ»ÖÖ£¬ÈôÔÚÊı×Ö±ßÔµÔò²»³ö£¬ÈôÕæµÄÔËÆø²»ºÃÒ»Ö±³öbusy£¬ÄÇ¾ÍÔË
//ÆøÌ«²îÁË¡£

	for( i=0 ; i<sizeof(all); i++ )
		if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" && !is_fighting(all[i]) )
			kill_ob(all[i]);

	if( count < 10 && is_fighting() ) { // Ö÷´ò busy
		message_vision( HIR"\n·ÙÌìÄ§Íõ´óºÈÒ»Éù, É²ÄÇ¼äÌì¾ªµØÒ¡, Ä§½çÒò´Ë¶øÕğ¶¯! ÖÜÔâµÄÉúÎïÉ²ÄÇ¼ä·ÇËÀ¼´Ëé!\n\n"NOR, king );
		message_vision( HIR"½á¹ûËùÓĞÈË±»ÕâÍşÁ¦ÎŞ±ÈµÄÌìÄ§Å­ºğÕğÉË, ÍÛÒ»ÉùÍÂ³öÒ»´ó¿ÚÏÊÑª!\n"NOR, king );
		for( i=0 ; i<sizeof(all); i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
				all[i]->add( "gin", -100 );
all[i]->delete_temp("hardshell");
				all[i]->start_busy(j);//±äµÄËæ»úĞÔÖÊµÄ£¬ÖÁÉÙÒ»»ØºÏ£¬ÖÁ¶àÈı»ØºÏ¡£
				COMBAT_D->report_status( all[i], 1 );
			}
	}

	if( count > 10 && count < 25 && is_fighting() ) { // Ö÷´ò force
		message_vision( HIR"
	·ÙÌìÄ§Íõ½«È«ÉíÒµ»ğ°µÔËÕÆÉÏ, ÕÆÉÏÒµ»ğÔÌ²Ø×ÅÎŞÏŞÎü¾¢
	Õ£ÑÛ¼ä, ·ÙÌìÄ§Íõß³ºÈ»Øµ´"HIW"¡®Ä§µÀÂÖ»Ø Òµ»ğºáĞĞ¡¯"HIR"
	Òµ»ğ²»¶ÏÏòËÄÖÜÎüÒıÆø¾¢!\n\n"NOR, king );
		message_vision( HIR"½á¹ûËùÓĞÈË°Ë³ÉÄÚÁ¦È«ÊÜÒµ»ğÎüÒı, ÄÚ¾¢¿ñĞ¹!\n"NOR, king );
		for( i=0 ; i<sizeof(all) ; i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
				tmp = all[i]->query("force")/5*4;
				all[i]->add( "force", -tmp );
all[i]->delete_temp("hardshell");
				king->add( "force", tmp );
			}   
	}

	if( count > 25 && count < 50 && is_fighting() ) { // Ö÷´òÉñ
		message_vision( HIR"
	·ÙÌìÄ§ÍõÈ«Éí»ğÑæÈÆÉí, Í»È»½«ÖÜÉíÒµ»ğ°µÔËÕÆÉÏ,
	Õ£ÑÛ¼ä, ·ÙÌìÄ§Íõß³ºÈ»Øµ´"HIW"¡®Ä§µÀºáĞĞ ÁÒÑæ±¼ÌÚ¡¯"HIR"
	Òµ»ğ²»¶ÏÏòÄãÏ®À´!\n\n"NOR, king );
		for( i=0 ; i<sizeof(all) ; i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" )
				all[i]->receive_wound( "sen", 100+random(100) );
	}

	if( count > 50 && count < 80 && is_fighting() ) { // Ö÷´òmob
		message_vision( HIR"
	·ÙÌìÄ§Íõ»¯ÉíÁ¶ÓüÒµ»ğ, ÑıÆøÔÚÒ»Ë²¼ä±ä³É·ĞÌÚÑªºìÄ§·ç,
	·²±»Æä´µ·÷Ö®Îï¾¡»Ó³ÉÆû, ÈÛÈË¿Ú±ÇÁîÈËÖÏÏ¢
	Õ£ÑÛ¼ä, ·ÙÌìÄ§Íõß³ºÈ»Øµ´"HIW"¡®³àÓü»ìãä Ä§µÀÕÚÌì¡¯"HIR", ÈÛÈÚÄ§ÆøĞ®×ÅÊ´¹Ç
	·ÙÑæÖ®·ç·è¿ñµØÇÖÏ®×ÅÒ»ÇĞ!\n\n"NOR, king );
		for( i=0 ; i<sizeof(all); i++ )
			if( living(all[i]) && !wizardp(all[i]) && !userp(all[i]) &&
			    !all[i]->query("master") && all[i]->query("id")!="fire king" )
				all[i]->die();
all[i]->delete_temp("hardshell");
	}

	if( count > 80 && is_fighting() ) { // Ö÷´òÆø
		message_vision( HIR"
	·ÙÌìÄ§Íõ»¯ÉíÁ¶ÓüÒµ»ğ, ÑıÆøÔÚÒ»Ë²¼ä±ä³É·ĞÌÚÑªºìÄ§·ç,
	·²±»Æä´µ·÷Ö®Îï¾¡»Ó³ÉÆû, ÈÛÈË¿Ú±ÇÁîÈËÖÏÏ¢
	Õ£ÑÛ¼ä, ·ÙÌìÄ§Íõß³ºÈ»Øµ´"HIW"¡®³àÓü»ìãä Ä§µÀÕÚÌì¡¯"HIR", ÈÛÈÚÄ§ÆøĞ®×ÅÊ´¹Ç
	·ÙÑæÖ®·ç·è¿ñµØÇÖÏ®×ÅÒ»ÇĞ!\n\n"NOR, king );
		message_vision( HIR"½á¹û±»ÈÛÈÚ¼«»ğ¾íµ½, °§º¿Á¬Á¬ÖĞ»ëÉíÇàÑÌÖ±Ã°, °éËæ×ÅÕóÕó½¹ÈâÎ¶!\n"NOR, king );
		for( i=0 ; i<sizeof(all); i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
			all[i]->receive_wound( "kee", 500 );
all[i]->delete_temp("hardshell");
			COMBAT_D->report_status( all[i], 1 );
		}
	} 

	if( random(100) < 50 && is_fighting() && king->query("kee") > 0 )
	{
		message_vision( HIG"\n·ÙÌìÄ§ÍõÉíÃ°³öĞÜĞÜ»ğÑæ, ÉË¿Ú½¥½¥µÄÓúºÏÁË!\n"NOR, king );
		king->delete_busy();
		king->clear_condition();
	    king->receive_curing("kee",5000);
	    king->receive_heal("kee",5000);
	    king->receive_curing("gin",5000);
	    king->receive_heal("gin",5000);
	    king->receive_curing("sen",5000);
	    king->receive_heal("sen",5000);

	}

	// by babe ¼ÆËã¸ÕºÃ, ²»Òªµ÷Õû
	if( !is_fighting() ) {
		if( query("force") < query("max_force") ) // 1 -> 5.035
			command( "ex 200" );
		if( query("eff_kee") < query("max_kee") ) // 35 -> 40
			command( "10 exert heal" );
		if( query("gin") < query("eff_gin") ) // 125
			command( "exert regenerate" );
		if( query("kee") < query("eff_kee") ) // 125 -> 300
			command( "4 exert recover" );
		if( query("sen") < query("eff_sen") ) // 125
			command( "exert refresh" );
	}

	// enf ²»¼õ·´Ôö
	if( query("force_factor") < 40 )
	{
	king->set( "force_factor", 45 );
	}

    set_heart_beat(1);
	::heart_beat();
}

void die()
{
	int i,j;
	object *enemy;
  
   object winner = query_temp("last_damage_from");
   string name = winner->query("name");
   enemy = query_enemy();
  i=sizeof(enemy);
  
        tell_object(users(),HIW"
            
         ·ÙÌìÄ§ÍõÑöÌìÌ¾µÀ£º¡®ÍòÄêÒÔÀ´ÎÒµÄ¾ªÊÀÉñ¹¦ÎŞÈËÄÜµĞ,
                             Ïë²»µ½½ñÈÕ°ÜÓÚ"+HIY+
                             (winner->query("family/family_name")?winner->query("family/family_name"):"")+
                             HIC+name+HIW"       
                             Ö®ÊÖ, ÕæÊÇºóÉú¿ÉÎ·¡«Ì¾°¡¡« ¡¯

        "HIB"   Ä§½çïWÆğ¿ñ·ç±©Óê   Ò»´úÄ§½çÖ®Íõ·ÙÌìÄ§Íõ°ÜÁË!             
"NOR);

 log_file("mogi/KILL_FIRE_KING", sprintf("%s(%s) ´ò°Ü ·ÙÌìÄ§Íõ on %s\n"
,name,winner->query("id"), ctime(time()) ));

/*
	//by ACKY
	if( random(100) < 10 )
		environment(this_object())->war_start();
*/
	if( winner->query("clan/id") )
		CLAN_D->add_clanset( winner->query("clan/id"), "develop" , 10 );

   tell_object(winner,"
\n·ÙÌìÄ§ÍõËµ£ººÃ°É...¼ÈÈ»ÄãÒÑ¾­Ó®ÁËÎÒÁË£¬ÎÒ¾Í°Ñ·çÇàÔÆ
½»¸øÄãÁË£¬·´ÕıÕâÃ´¶àÄêÀ´ËûÒ²²»¿ÏÍÂÂ©Á¬ÑôÆß¾÷½£·¨µÄ°ÂÃØ¡£
²»¹ıËû±»ÎÒÓÃ¶ÀÃÅÊÖ·¨µã×¡ÁËÈıÔªÖØÑ¨£¬¹¦Á¦ÒÑ¾­±»·â
ÏÖÔÚÎÒ´«Äã½âÑ¨ÊÖ·¨(recover force)£¬ÄãÍù±±×ß¿ÉÕÒµ½Ëû¡£
\n");

   tell_object(winner,HIY"\n·ÙÌìÄ§ÍõÔÙÓÃ±ÆÒô³ÉÏßµÄ¹¦·ò¸æËßÄã£º
ÕæÊÇºóÉú¿ÉÎ·...ÕâÑùÎÒÒ²Ã»±ØÒªÒş²ØÎÒµÄ¾øÑ§ÁË£¬ÏÖÔÚÎÒ¾Í´«Äã
"HIR"¼«»ğ½ğÉíĞÄ·¨"HIY"£¬¼«»ğÕæ¾­¾Í·ÅÔÚ°×»¢ÊÒ£¬É÷Ï°Ö®£¡
\n"NOR);
   winner->set("quest/gold-fire",1);
   winner->set("quest/new_gold_fire",1);
   winner->set_temp("win_fireking",1);

   for(j=0;j<i;j++){
       if(enemy[j]->query("class")=="swordsman" && enemy[j]->query_temp("win_fireking")!=1)
       {
       enemy[j]->set_temp("win_fireking",1);
   tell_object(enemy[j],"·ÙÌìÄ§ÍõËµ£ººÃ°É...¼ÈÈ»ÄãÒÑ¾­Ó®ÁËÎÒÁË£¬ÎÒ¾Í°Ñ·çÇàÔÆ
½»¸øÄãÁË£¬·´ÕıÕâÃ´¶àÄêÀ´ËûÒ²²»¿ÏÍÂÂ©Á¬ÑôÆß¾÷½£·¨µÄ°ÂÃØ¡£
²»¹ıËû±»ÎÒÓÃ¶ÀÃÅÊÖ·¨µã×¡ÁËÈıÔªÖØÑ¨£¬¹¦Á¦ÒÑ¾­±»·â
ÏÖÔÚÎÒ´«Äã½âÑ¨ÊÖ·¨(recover force)£¬ÄãÍù±±×ß¿ÉÕÒµ½Ëû¡£
\n");
       }
                    }
//²¹³ä....................................
//ÎäÕß½âÁË»°.»á±ä³ÉÒ»´úÎä×ğ....Í¬Ê±¿ÉÒÔÊ¹ÓÃÖÕ¼«È­ÊÆ...................by chan
 if(winner->query("class") == "fighter")
 if((winner->query("combat_exp") > 5000000) && !(winner->query("final/ko_king")))
 {
   winner->set("final/ko_king",1);
   winner->set("final/limit",1);
   tell_object(winner,HIR"ÄãÖÕÓÚÍ»ÆÆÎäÑ§ÉÏ¼«ÏŞ!!Îò³öÖÕ¼«È­ÊÆ!!³ÉÎªÎä×ğ!!\n"NOR);
   winner->set("title","[1;33mĞşÌìÎä×ğ [0m");

   write("Çë´òÒ»ÏÂhelp ÖÕ¼«È­ÊÆ,¿ÉÒÔµÃÖª¸ü¶àµÄÑ¶Ï¢....!!!\n");
  }
//²¹³äµ¶¿Í½âÁËÄÜÓĞÖÆµ¶Êõ by swy
 if(winner->query("class") == "blademan")
if(winner->query("combat_exp")>5000000&&!winner->query("mk-blade")&&userp(winner))
 {
   winner->set("mk-blade",1);
tell_object(winner,HIY"\n·ÙÌìÄ§ÍõÔÙÓÃ±ÆÒô³ÉÏßµÄ¹¦·ò¸æËßÄã£º
ÕæÊÇºóÉú¿ÉÎ·...ÕâÑùÎÒÒ²Ã»±ØÒªÒş²ØÎÒµÄ¾øÑ§ÁË£¬ÏÖÔÚÎÒ¾Í´«Äã
"HIR"Ğ°ÁéÖÆµ¶Êõ"HIY"£¬É÷Ï°Ö®£¡\n"NOR);
if(winner->query("gender")=="ÄĞĞÔ") { winner->set("title",HIW"äöÓğ"HIY"µ¶»Ê"NOR); }
else { winner->set("title",HIB"µ¶»ê"HIC"ÓÄ¼§"NOR); }
   write("Çë´òÒ»ÏÂ help Ğ°ÁéÖÆµ¶Êõ£¬ÄÜÖªµÀ¸ü¶àÑ¶Ï¢¡£\n");
  }

//Bellow Add By AceLan.......
        if( winner->query("family/family_name")=="ÈåÃÅ")
        {
                 tell_object(winner,HIW"ÄãÆ¾½å×Å¸ßÉîµÄĞÄ·¨ÔÚ²»Öª²»¾õÖĞÁìÎòÁË·ÙÌìÄ§Íõ¼«»ğ¹¦µÄ¾«Ëè£¬
¿àË¼ÁË°ëâÃÖ®ºóÍ»È»¶ÙÎòµ½½«¼«»ğ¹¦ÈÚÈë¿×Ã÷±ø·¨Ö®µÀ£¬Ëì´óÉù¿ñ»¶µÀ
"+HIR+"==========¡®¼«»ğÒ»³ö£¬ÍòÎï¾ß·Ù¡¯==========\n"
NOR);
        } 

  :: die();
}                    
