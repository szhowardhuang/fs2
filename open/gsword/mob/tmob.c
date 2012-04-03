// copy from /d/snow/npc/teacher.c
inherit NPC;

int a;
int b;
int in_toss;

void create()
{
	set_name("Íõ¿­", ({ "wang","wang kai","kai"}) );
	set("gender", "ÄÐÐÔ" );
	set("age", 43);
	set("int", 26);
        set("long","ËûÕý¾Û¾«»áÉñµÄ¿´×Å×ÀÉÏÄÇÒ»¸ö´óÍë¹«£¬×ìÖÐÄîÄîÓÐ´Ê¡£ÄãºÃÆæ
 µÄÏëÖªµÀ¶ûJ¹«Àïµ½µ×ÊÇÉ¶±¦±´£¬×ß½üÒ»¿´£¬ÍÚÁ¨ÀÕ£¡¾¹È»ÊÇÎ÷°ËØÝ¡£\n" );
        
        set("inquiry",([
        "½ûµØ": "ÄãÊÇË­£¡½ûµØµÄÊÂÎÒÒ»¸Å²»Öª£¬¾ÍËãÖªµÀ²»»á¸æËßÄã£¬Äã×ß°É¡£\n",
        "·âÓ¡": "°¦£¡±ðËµÄÇÃ´¶àÌÖÈËÑáµÄ»°ÌâÁË£¬ÔÛÃÇÍæÁ½°Ñ°É£¬ÄãÓ®ÁË£¬ÔÙÀ´ÎÊ
        	ÎÒÒ²²»³Ù°¡¡£\n"]
        ) );
	
	set("combat_exp",1087);
        set("max_kee",500);
        set("max_gin",500);                        
	set("attitude", "peaceful");
	set_skill("unarmed",50);
	set_skill("parry",50);
	set_skill("force",50);
	setup();
}

init()
{
	add_action("play_dice","play");
	add_action("toss_dice","toss");
}


int play_dice(string str)
{

	if( str!="dice" ) {
		write("ÄãÒªÍæÊ²Ã´£¿\n");
		return 1;
	}
	write("Íõ¿­µÀ:ÄãÏÈÀ´°É£¬ÇëÖÀ÷»×Ó\n");
	return 1;
}

int toss_dice(string str)
{
	if( str!="dice") {
		printf("ÄãÒªÍæÊ²Ã´£¿\n");
		return 1;
	}
	if( in_toss ){
		printf("ÎÒÕýÔÚ¸ú±ðÈËÍæ£¬²»Òª´ò½ÁÎÒÃÇ£¡£¡\n");
		return 1;
	}

	a=random(5)+1;
	b=random(5)+1;
	message_vision("$N´óº°¡Ã[1mæÖÃÐ°Ëßäºä£¬Ìì±øÌì½«ÎªÎÒËùÓÃ£¬Î÷°ËÀ±£¡£¡[0m\n", this_player());
	if( a > 3 ) {
	 message_vision("$N´óÐ¦ : ¹þ£¡¹þ£¡ÎÒÖÀµ½ "+a+" µã£¬¿´À´ÄãÊÇÐ×¶à¼ªÉÙ£¡£¡ ¸ÃÄãÁË£¡\n", this_player());
	} else {
	 message_vision("$N´¹Í·É¥ÆøµÄËµ : °¦£¡°¦£¡ÕæÊÇÈü£¬¾¹È»ÊÇ "+a+" µã,Äã¿ÉÀÖÁË°É£¡ÄãÖÀ°É£¡\n", this_player());
	}//end if_else
	remove_call_out("shou_turn");
	in_toss=1;
	call_out("shou_turn",2, this_player()->query("id"));
	return 1;
}

void shou_turn(string str)
{
        say("\nÖ»¼ûÍõ¿­ÒÔÑ¸À×²»¼°ÑÚ¶úËÙ¶È£¬½«Íë¹«ÔÚ¿ÕÖÐ»ÎÁËÁ½È¦£¬Ëæ¼´¶¨ÔÚ×ÀÉÏ£¬´ó½ÐÒ»Éù¡®¿ª¡¯£¡£¡\n");
	if( b > a ){
		command("say " + sprintf("¹þ£¡Ð¡ÐÖµÜÄãÊäÁË£¬ÎÒÖÀµ½ %d µã¡£\n", b));
	}
        else if( b==a){
		command("say " + sprintf("ÎÒÒ²ÊÇÖÀµ½ %d µã£¬ÕâÅÌÔÛÃÇ¿ÉÊÇºÏ¾ÖÁË¡£\n", b));
	}
	else {
		this_object()->add(str, 1);
		if(this_object()->query(str) != 3)
			command("say " + sprintf("ÕæÊÇ±³°¡£¬¾¹ÊÇÖÀµ½ %d µã£¬ËãÎÒµ¹é¹£¬ÔÛÃÇÔÙÀ´Á½°Ñ£¡£¡\n",b));
		else if(this_object()->query(str) == 3)
		{
			command("say " + sprintf("ÕæÊÇ±³°¡£¬¾¹ÊÇÖÀµ½ %d µã£¬ÊäÄãÈý´Î!! ÎÒ¾Í¸æËßÄã°É¡£\n",b));
			command("tell "+ str +" µ±Äê×æÊ¦Ò¯åÐÒ£×ÓÓÃÈýÑù·¨±¦½«Ëû·âÓ¡ÆðÀ´£¬×æÊ¦Ò¯ÍËÐÝÖ®ºó¾Í°ÑÈýÑù±¦Îï·Ö±ð½»¸øËûÈý¸ö´óµÜ×Ó±£¹Ü£¬Òª½â¿ªÌìÄ§µÄ·âÓ¡£¬·ÇÒªÕâÈýÑù·¨±¦Í¬Ê±Ê©·¨£¬³ý´ËÖ®Íâ±ðÎÞËû·¨¡£\n"); 
			this_object()->delete(str);
		}
	}
	in_toss = 0;
}
