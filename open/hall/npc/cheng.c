inherit NPC;
#include <ansi.h>
#include <combat.h>
#include </open/open.h>
string do_thief();
string ask_test();
void create()
{
	set_name("¼ÍÎŞ³¾", ({ "chi wu-cheng","chi", "cheng" }) );
	set("title", "×ÜÀíÖ´ÊÂ");
  //set("nickname", "[1;34m¡õ[36m¡õ[34m¡õ[36m¡õ[34m¡õ[36m¡õ[34m¡õ[36m¡õ[0m NOR");
	set("class","officer");
	set("gender", "ÄĞĞÔ" );
	set_max_encumbrance(1000000);
	set("age", 46);
	set("str", 20);
	set("cor", 20);
	set("cps", 20);
	set("int", 30);
	set("spi", 20);
	set("kar", 26);
	set("per", 20);
	set("con", 30);

	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 5);

	set("long", @LONG
    ÈË³Æ¡®¾©³ÇÖ®¹â¡¯£¬ÈËËµÆä¶Ï°¸ÈçÉñ£¬¾ö²»áßË½ÆˆÇÒ¡£ËùÒÔÕâÀïµÄ
°ÙĞÕ¶¼ºÜ¾´°®Ëû¡£Ò²ÒòÎªËûµÄ¹¦¼¨»Ô»Í£¬ÏÈ»ÊÌØ´ÍÆäÒ»±úÉĞ·½±¦½££¬×¼
Æä½«¶ñ¹ßÂúÓ¯Ö®ÈË£¬ÏÈÕ¶ºó×à!!
LONG);

	set("combat_exp",500000);
	set("score", 30000);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	"ÎŞ³¾´óÈËºÈµÀ£º´óµ¨¿ñÍ½!!  ÄÃÏÂ!!\n",
	"ÎŞ³¾´óÈËºÈµÀ£º¹«ÌÃÖ®ÉÏ¾¹¸ÒÈöÒ°!!  ¸øÎÒÑÏ³Í!!\n"
	}) );

	set_skill("unarmed", 30);
	set_skill("force",  20);
	set_skill("parry",  20);
	set_skill("dodge",  20);
	set_skill("sword",  20);
	set_skill("literate", 90);

	set("inquiry", ([
	  "»úÆ÷ÈË" : "ºß!! Ë­±»ÎÒ×¥µ½ÊÇ»úÆ÷ÈËµÄ»°£¬Õ¶Á¢¾ö!!",
       "ÊÔÁ¶Ó¡¼Ç" : (:ask_test:),
	  "accuse" : "Ïë¼©²¶»úÆ÷ÈËµÄ»°£¬ÇëÏÈµ½ÃÅ¿Ú»÷¹ÄÉêÔ©(accuse)¡£",
	  "thief"  : (: do_thief :),
	  "²âÊÔ"   : "Ïë×¥Ôô(thief)¾ÍµÃÏÈ¾­¹ıÎÒ²âÊÔ, ÈôÄÜÁ¬½ÓÎÒÎåÕĞ±ãËã¹ı¹ØÁË¡£",
	  "test"   : "Ïë×¥Ôô(thief)¾ÍµÃÏÈ¾­¹ıÎÒ²âÊÔ, ÈôÄÜÁ¬½ÓÎÒÎåÕĞ±ãËã¹ı¹ØÁË¡£",
	  "accept" : "Òª½ÓÊÜ²âÊÔÂğ? ÄÇ¾Í´ò(accept test)¡£",
	]) );

	setup();
	carry_object(HALL_NPC"obj/god_sword")->wield();
	carry_object(HALL_NPC"obj/o_cloth")->wear();
}

string do_thief()
{
	object me=this_player();
    if( me->query("quests/catch_thief") == 0 || (me->query("marks/ask_linpo") && me->query("family/family_name")=="¶Î¼Ò"))
	{
	  if( me->query_temp("thief") == 0 )
	    me->set_temp("thief",1);
	  return (RANK_D->query_respect(me)+"ÊÇÓĞÒâ°ïÃ¦×¥¾©³Ç´óµÁµÄÂğ? "+
		"Ö»ÊÇ×î½üÓĞĞí¶àÃ»±¾ÊÂµÄÈËÇ°À´Ó¦Õ÷\n, "+RANK_D->query_respect(me)+
		"ÈôÓĞ±¾ÊÂµÄ»°ÇëÏÈ½ÓÊÜ²âÊÔ°É(accept test)¡£");
	}
	else
	{
	  command("smile");
	  command("pat "+me->query("id"));
	  return ("Õâ¼şÊÂÕæÊÇ¶à¿÷ÁËÄã, Èç½ñ¾©³ÇÓÖ»Ö¸´Æ½¾²ÁË¡£");
	}
}					    
void init()
{
	add_action("do_accept","accept");
}
int do_accept(string str)
{
	int i;
	object ob=this_object();
	object me=this_player();
	object mark=new(CAPITAL_OBJ"mark");
	if( me->query_temp("thief") == 0)
	  command("say ÏÈÎÊÎÊÎªºÎÒª²âÊÔ°É¡£");
	if( me->query_temp("thief") > 1)
	  command("say ²»ÊÇ²âÊÔ¹ıÁËÂğ?");
	if( me->query_temp("thief") == 1)
	{
	if( str=="test")
	{
	  command("say ºÃ! ´ıÀÏ·òÀ´ÊÔÊÔÄã! Ğ¡ĞÄÁË");
	  for(i=0;i<5;i++)
	    COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), TYPE_QUICK);
	  if( me->query("kee") > 1 )
	  {
	    command("say ¹ûÈ»²»À¢\ÎªÕæÓ¢ĞÛ, ÄÇÎÒ¾Í½«Õâ¼şÊÂÔ­Ô­±¾±¾µÄËµÓëÄãÌıÁË");
	    command("thank "+me->query("id"));
	    command("say Õâ¾©³Ç´óµÁÄ¿Ç°ÎªÖ¹ÒÑµÃÊÖ²»ÏÂÊı´Î, Á¬¾©³ÇÊ×¸»¸ÉÍ¨ÌìµÄÕ¬µÚÒ²\n"+
	    "		 ÔâÑêÁË, Òò´ËÕâ²Å¾ª¶¯»ÊÉÏÏÂÁîÒ»¸öÔÂÖ®ÄÚ±ØĞëÆÆ°¸, ¼ÈÈ»"+RANK_D->query_respect(me)+
	    "\n 	   ×Ô¸æ·ÜÓÂ, ÄÇÕâ¼şÊÂ¾Í°İÍĞÄãÁË¡£½«´ËÃû´óµÁ´ş²¶¹é°¸, Ôò±Ø¶¨ÖØÖØÓĞÉÍ¡£");
	    message_vision("$N½»¸ø$nÒ»Ãæ¡¸ÑÃÃÅÁîÅÆ¡±¡£\n",ob,me);
	    mark->move(me);
	    command("say Ï£ÍûÕâÃæÁîÅÆ¶ÔÄã°ì°¸ÄÜÓĞËùÖúÒæ¡£");
	    me->set_temp("thief",2);
	  }
	  else
	  {
	    command("say °ÕÁË°ÕÁË, ÎÒ»¹ÊÇ¼ÌĞøµÈÕæÓ¢ĞÛÀ´°É");
	    command("sigh");
	  }
	}  
	else
	  write("½ÓÊÜÊ²Ã´?!\n");
	}
	return 1;		 
}

int accept_object(object me, object man)
{
	string target = "ÕÔÇÙ·ç";
	object ob=this_object();
	object reward;
	if( me->query_temp("thief") < 2 )
	  return notify_fail(ob->query("name")+"ËµµÀ£ºÒÉ..ÎÒºÃÏñÃ»ÓĞÍĞÄã°ìÕâ¼şÊÂÂï¡£¼ÈÈ»ÄãÕâÃ´ÈÈĞÄ, ÄÇ¾ÍĞ»†ª¡£\n");
	if( man->query("victim_name") == target || man->query("name") == target )
	{
	  command("say ÕæÊÇÌ«ºÃÁË, ÎÒÍĞ¸¶ÄãµÄÊÂÖÕÓÚË³ÀûµÄ´ï³ÉÁË¡£");
	  if( man->query("name") == target )
	  {
	    command("say °´ÕÕÔ¼¶¨, Õâ¾ÍÊÇÄãÓ¦µÃµÄÉÍ½ğ¡£\n");
	    reward = new("/obj/money/gold");
	    reward->set_amount(5);
	    reward->move(me);
	    message_vision("$N´Í¸ø$nÎåÁ½»Æ½ğ¡£\n",ob,me);
	  }
	  else
	  {
	    command("say ¿ÉÏ§Õâ¾©³Ç´óµÁÒÑËÀ, Òò´ËÉÍ½ğÖ»ÓĞÒ»°ëÁË¡£");
	    reward = new("/obj/money/gold");
	    reward->set_amount(2);
	    reward->move(me);
	    message_vision("$N´Í¸ø$n¶şÁ½»Æ½ğ¡£\n",ob,me);
	  }
	  if( !me->query("quests/catch_thief") )
	  {
	    write("\n\n[1;36m**Íê³É¾©³Ç´óµÁÖ®ÃÕ***[0m\nÄãµÃµ½ÊµÕ½¾­Ñé 200¡£\n");
	    me->add("combat_exp",200);
	    if( me->query("class") == "officer" )
	    {
	      write("ÄãµÃµ½ÕşÖÎÈ¨Á¦ 20¡£\n");
	      me->add("max_officer_power",20);
	    }  
	    me->set("quests/catch_thief",1);
	    me->delete_temp("thief");
	  }
	  destruct(man);
	}
	return 1;
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

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {
	  new("/open/sky/obj9/health_charm")->move(environment(winner));
	  message_vision(HIM"\n´Ó¼ÍÎŞ³¾µÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/health_charm",sprintf("%s(%s) ÈÃ¼ÍÎŞ³¾µôÏÂÁË½¡¿µÖ®·ûÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj9/health_charm")->move(environment(winner));
	  message_vision(HIM"\n´Ó¼ÍÎŞ³¾µÄÉíÉÏµôÏÂÁËÒ»¼şÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/health_charm",sprintf("%s(%s) ÈÃ¼ÍÎŞ³¾µôÏÂÁË½¡¿µÖ®·ûÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();
}
string ask_test()
{
 if(this_player()->query("quests/yan")==3)
 {
 if(this_player()->query("quests/catch_thief",1)&&this_player()->query("quests/yantestmark1",1)  && this_player()->query("quests/2ndtest",2))
  {
  int i;
  i=6+random(5);
  command("say Ğ»Ğ»ÄúµÄ°ïÃ¦.ÎÒÔ¸Òâ½«appo¸øÎÒµÄÓ¡¼Ç´«µ½ÄãÉíÉÏ!\n");
  tell_object(this_player(),HIW"Ë²¼äÓÉ¼ÍÎŞ³¾½«ÊÖ´îÔÚÄãµÄ¼çÉÏ..Äã¶ÙÊ±¾õµÃÒ»¹ÉÅ¯ÒâÓÉ¼ÍÎŞ³¾µÄÊÖÖĞ´«¹ıÀ´\n"NOR);
  this_player()->set("quests/2ndtest",i);
  this_player()->set("quests/yantestmark2",1);
  return("×îºóÒ»¸öÓ¡¼ÇÔÚÊ¥ÏÍÊéÊÖÉÏ,Äã¿ÉÒÔÈ¥ÕÒËûÎÊÎÊÁË\n");
  }
 else if (this_player()->query("quests/yantestmark2")>1)
  return ("ÎÒÒÑ¾­°ÑÓ¡¼Ç¸øÄãÁË..Äã»¹Òª×öÊ²Ã´\n");
 else
  return ("È¥µ±ÎÒ°Ñ¾©³Ç´óµÁÕÒ³öÀ´ÎÒ¾Í¸úÄãËµÓ¡¼ÇÔÚÄÄ¡£\n");
 }
else
 return ("É¶Ó¡¼Ç..ÄãÔÚËµÊ²Ã´?\n");
}
