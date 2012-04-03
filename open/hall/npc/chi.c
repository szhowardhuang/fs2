inherit NPC;
#include <ansi.h>

void create()
{
set_name("ÇØ  ¼É", ({ "chin chi", "chin", "chi" }));
        set("title", "ÏØÑÃÈý²¶Í·");
        set("nickname","[1;34m×·»êÇ¹[0m");
        set("age", 23);
        set("str", 25);
        set("cor", 20);
        set("cps", 20);
        set("int", 20);
        set("spi", 20);
        set("kar", 24);
        set("per", 20);
        set("con", 30);
        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 3);

        set("long", @LONG
    Ò»Î»Éí²Ä°«Ð¡µÄÄÐ×Ó£¬ÑÛÖÐÍ¸×ÅÒþÒþµÄÉ±Æø£¬ÔÚËûµÄÉí±ßÊ¹Äã¸Ðµ½
ºÜ²»×ÔÔÚ¡£¾ÝËµËûÔøÎªÁË×·Ò»¸ö½­Ñó´óµÁ£¬Ö»ÉíÉ±½øºÚ·çÕ¯£¬ÔÚÒ»Æ¬ÐÈ
·çÑªÓêÏÂÔ×ÁËÄÇ´óµÁ£¬Ôì³ÉÎäÁÖÒ»Ê±µÄºä¶¯!!
LONG);
        set("combat_exp", 150000);
        set("score",  3000);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        "ºÙºÙ....!!  ¹Ô¹ÔµØÎ¹ÎÒµÄÇ¹°É!!\n",
        "¿´¡®×·»êÁùÊ½¡¯!!  ÊÜËÀ°É!!\n"
        }) );

        set_skill("unarmed", 20);
        set_skill("force",  60);
        set_skill("parry",  40);
        set_skill("dodge",  60);
        set_skill("sword",  30);
        set_skill("literate", 20);

        set("inquiry", ([
          "×·»êÇ¹" : "ºÙºÙ!!ÏëÒªÎÒµÄÇ¹Âð?!ÄÃÄãµÄÃüÀ´»»°É!!",
          "thief"  : "¿É¶ñµÄ´óµÁ, ËµÆðÀ´¾ÍÒ»Í·Æø, ºÙ! Äã¸Ã²»»áÊÇËûµÄÍ¬µ³°É!!",
        ]) );

        setup();
        carry_object(__DIR__"obj/g_lance")->wield();
        carry_object(__DIR__"obj/b_suit")->wear();
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
	  new("/open/sky/obj10/fir_yin")->move(environment(winner));
	  message_vision(HIM"\n´ÓÇØ  ¼ÉµÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/fir_yin",sprintf("%s(%s) ÈÃÇØ  ¼ÉµôÏÂÁËÉ¼ÁéÖ®Ó¡ÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj10/fir_yin")->move(environment(winner));
	  message_vision(HIM"\n´ÓÇØ  ¼ÉµÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/fir_yin",sprintf("%s(%s) ÈÃÇØ  ¼ÉµôÏÂÁËÉ¼ÁéÖ®Ó¡ÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}

