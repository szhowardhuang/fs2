inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("Öì»ðÍú", ({ "zhu howang", "zhu", "wang"}));
        set("title", "ÏØÑÃ¶þ²¶Í·");
        set("nickname","[33mÍÀÅ£Ê¦[0m");
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

        set("long", @LONG
    Ò»¸ö´Ö×³µÄÄÐ×Ó£¬ËûÔøÊÇÂ¤É½ÅÉµÄµÜ×Ó¡£¾ÓËµËûÔøÎªÁË¾ÈÈË£¬
Ò»È­»÷±ÐÒ»Í··èÅ££¬ÒòÖ®µÃÁË¸ö¡®ÍÀÅ£Ê¦¡¯µÄÃÀºÅ£¬²»¹ýÓÉÓÚËûÉú
ÐÔ·Åµ´£¬¹Ê¶ÔÒ»Ð©Éú»îÉÏµÄÏ¸½Ú²»ÊÇºÜ×¢ÖØ£¬ÍùÍùÊ¹Éí±ßµÄÈËÊÜ²»
ÁË¡£
LONG);

        set("combat_exp", 600000);
        set("score", 20000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        "¿´È­!!Ð¡ÐÄÀ²!!\n",
        "Ò»½ÅÌß·­ÄãÕâÍõ°Ëµ°!!\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("literate", 90);

        set("inquiry", ([
          "Â¤É½ÅÉ" : "°¦¡«¡«Â¤É½È­à¸¡«¡«²»ËµÒ²°Õ£®£®£®£®",
	  "thief"  : "°¦¡«¡«¿ÉÏ§ÎÒÉíÐÎ±¿ÖØ, ²»È»ÉÏ´ÎÎÒ¾Í×¥µ½ÄÇ´óµÁÁË",
        ]) );

        setup();
   //   carry_object(__DIR__"obj/dragon_armor")->wear();
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

	if( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {
	  new("/open/sky/obj11/red-crystal")->move(environment(winner));
	  message_vision(HIM"\n´ÓÖì»ðÍúµÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/red_crystal",sprintf("%s(%s) ÈÃÖì»ðÍúµôÏÂÁËºìÉ«¹â¾§ÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj11/red-crystal")->move(environment(winner));
	  message_vision(HIM"\n´ÓÖì»ðÍúµÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/red_crystal",sprintf("%s(%s) ÈÃÖì»ðÍúµôÏÂÁËºìÉ«¹â¾§ÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();
}