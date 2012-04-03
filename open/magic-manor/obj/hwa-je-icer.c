#include <weapon.h>
#include <ansi.h>

inherit UNARMED;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
     set_name(CYN"»¯½ÙÁâ¹éÕæ"NOR,({"hwa-je-icer","icer"}) );
     set_weight(10000);
     if( clonep() ) 
            set_default_object(__FILE__);
     else {
            set("long","¼ÅÔª×ÓËùÊ¹ÓÃµÄÎäÆ÷£¬ÎªÒ»ÉñÃØÖı½«¾«ĞÄÖıÔìµÄ¡¸°ËÉ«ÁéÆ÷¡±Ö®Ò»£¬ÁâÉí\nÒşÒşÍ¸³öºÚ°×Á½¹ÉÆø¾¢¡£\n");
            set("unit", "°Ñ");             
            set("value",20000);
            set("sharp",9);
            set("material","blacksteel");
			set("e-weapon",1);
			set("no_give",1);
 			set("no_steal",1);
            }
	init_unarmed(100);
 	set("wield_msg",CYN"$N"CYN"ÔØÉÏ$n"CYN"£¬$n"CYN"ÖÜÉí·ºÆğºÚ°×Á½É«µÄ¹îÒìÆøÏ¢!!\n"NOR);
        set("unwield_msg","$NÇáÇáĞ¶ÏÂ$n£¬$nÖÜÉíµÄ¹îÒìÆøÏ¢Ò²ÏûÊ§´ù¾¡¡£\n"NOR);

          setup();
}                   


void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wield","wield");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{
	int uexp;
//	::wield();
	if( !query("equipped") )
	{
	user = this_player();
	uexp = user->query("combat_exp");
	  if( uexp < 3000000 )
	  {
	  message_vision("$NµÄ¾­Ñé²¢²»×ãÒÔÍêÈ«Ö§ÅäÕâÑùµÄÉñ±øÀûÆ÷!!\n"NOR,user);
	  set_heart_beat(0);
	  }else{
//	  message_vision(CYN"$N"CYN"ÔØÉÏ$n"CYN"£¬$n"CYN"ÖÜÉí·ºÆğºÚ°×Á½É«µÄ¹îÒìÆøÏ¢!!\n"NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="hwa-je-icer" || str=="icer" || str=="all")
	if( query("equipped") )
	{
	message_vision("$NÇáÇáĞ¶ÏÂ$n£¬$nÖÜÉíµÄ¹îÒìÆøÏ¢Ò²ÏûÊ§´ù¾¡¡£\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="hwa-je-icer" || str=="icer" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$NÇáÇáĞ¶ÏÂ$n£¬$nÖÜÉíµÄ¹îÒìÆøÏ¢Ò²ÏûÊ§´ù¾¡¡£\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="hwa-je-icer" || str=="icer" || str=="all")
	if( query("equipped") )
	{
	message_vision("$NÇáÇáĞ¶ÏÂ$n£¬$nÖÜÉíµÄ¹îÒìÆøÏ¢Ò²ÏûÊ§´ù¾¡¡£\n"NOR,user,ob);
	set_heart_beat(0);
	}
}
void heart_beat()
{
	object *enemy;
	int i;

	if( !objectp(user) )
	{
	set_heart_beat(0);
	return;
	}

	if( user->query_skill("unarmed") )
	{
	be = user->query_skill("unarmed",1);
	}else{
	be = random(120);
	}

	k = user->query("int",1);
	sp = user->query("spi",1);
	co = user->query("cor",1);
	st = user->query("str",1);
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
	if( user->query("class") == "prayer" )
	{
	qq = qq*1.5;
	be = be*0.75;
	}

	if( user->is_fighting() && query("equipped") )
	{
	  if( be > random(500) )
	  {
	  enemy=user->query_enemy();
	  if(!enemy) return ;
	  i=random(sizeof(enemy));
	  if( environment(user) == environment(enemy[i]) )
	  if( random(300) > random(enemy[i]->query_skill("dodge",1)) )
	  {
	  message_vision(HIB"Ö»¼û¡¾"NOR"[18mºÚ"HIW"°×"NOR+HIB"¡¿Á½µÀÆø¾¢Ñ¸ËÙÓÉ"NOR"$n"HIB"´Ü³ö£¬·ÉÏò$N"HIB"µÄÖÜÉíÒªº¦!!\n"NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU"Ö»¼û$N"BLU"£¬×ó¶ãÓÒÉÁµÄÃâÇ¿±Ü¿ªÕâÁ½µÀºÚ°×Æø¾¢!!\n"NOR,enemy[i],ob);
	  }
	}
	return;
}

