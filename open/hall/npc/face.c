inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("ÀäÃæÉ·", ({ "cool face", "cool", "face" }) );
        set("title", "ÏØÑÃ²¶Í·Í³Áì");
        set("nickname", "[1;31mÑª½£[0m");
        set("gender", "ÄÐÐÔ" );
        set("age", 46);
        set("str", 50);
        set("cor", 50);
        set("cps", 50);
        set("int", 50);
        set("spi", 50);
        set("kar", 50);
        set("per", 50);
        set("con", 50);

        set("max_atman", 5000);
        set("max_force", 5000);
        set("max_mana", 5000);
        set("atman", 5000);
        set("force", 5000);
        set("mana", 5000);
        set("force_factor", 5);

        set("long",@LONG
    ÕâÊÇÒ»Î»ÏàÃ²ÌÃÌÃµÄÄÐ×Ó£¬Ã»ÓÐÈËÖªµÀËûµÄÀ´Àú¡«µ«Ëû¸ßÉîÄª²âµÄ
Îä¹¦È´Ê¹ËûÄÜÉã·þÃ¿Ò»¸öºÍËû½ÏÁ¿¹ýµÄÈË£¬ËûµÄÎä¹¦Ö®¸ß....ÊµÊÇ²»ÄÜ
ÓÃÑÔÓïÐÎÈÝÖ®¡£
LONG);

        set("combat_exp", 900000);
        set("score", 20000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        "¹þ¹þ¹þ¡«¡«Ð¡×Ó!!¿´¿´¡®»êÌì°ËÊ½¡¯µÄÀ÷º¦!!!!\n"
        "ÈÃÄãÖªµÀÌìÓÐ¶à¸ßµØÓÐµØºñ!!Ð¡×Ó!!\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("literate", 90);

        set("inquiry", ([
          "³àÑª½£" : "ÄãÏëÊÔ½£Âð¡«¡«",
          "thief"  : "¿ÉºÞÎÒÓÐÒªÊÂÔÚÉí, ²»ÄÜÇ×ÊÖ´þ²¶ÄÇ¾©³Ç´óµÁ¡£",
        ]) );

        setup();
        carry_object(__DIR__"obj/redsword")->wield();
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
	  new("/open/sky/obj10/banyan_yin")->move(environment(winner));
	  message_vision(HIM"\n´ÓÀäÃæÉ·µÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/banyan_yin",sprintf("%s(%s) ÈÃÀäÃæÉ·µôÏÂÁËéÅÁéÖ®Ó¡ÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj10/banyan_yin")->move(environment(winner));
	  message_vision(HIM"\n´ÓÀäÃæÉ·µÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/banyan_yin",sprintf("%s(%s) ÈÃÀäÃæÉ·µôÏÂÁËéÅÁéÖ®Ó¡ÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}

