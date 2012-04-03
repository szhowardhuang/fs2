//whip.c

#include <weapon.h>

inherit STABBER;

int special_att();

void create()
{
	object me=this_player();
	set_name("[1;33mÓù´Í½ð±Ê[0m", ({"golden pen", "pen", "golden"}) );
        set_weight(300);
	if( clonep() )
	 set_default_object(__FILE__);
	else 
	 {
	  set("unit", "Ö§");
	  set("long","ÕâÊÇµ±½ñÊ¥ÉÏ´Í¸øÑîÊéÎÄÉÐÊéµÄ½ð±Ê£¬¸ÐÄîËûÎª¹úµÄÐÁÀÍ¡£\n");
	  set("value", 10000);
	  set("material", "blacksteel");
	 }
	init_stabber(80);
	me->set("chat_chance_combat",10);
	me->set("chat_msg_combat", ({
	(: this_object(),"special_att" :),
         		}));       
	setup();
}

int special_att()
{
	object me=this_player(),*enemy=me->query_enemy();
	int i=sizeof(enemy),j;
	string *busy_msg=({
	"ÑîÊéÎÄ½ôÎÕ[1;33mÓù´Í½ð±Ê[1;31m×ÅÍùÄãÐØÇ°Ò»µã£¬ÄãÍ»È»¾õµÃ¶¯×÷³Ù¶ÛÁËÆðÀ´!!\n",
	"ÑîÊéÎÄÓÃ[1;33mÓù´Í½ð±Ê[1;31mÖ±´ÌÄãÐ¡ÍÈ£¬Ê¹ÄãÆËÍ¨Ò»Éù£¬µøµ¹ÔÚµØ¡£\n",
	"ÑîÊéÎÄ½«[1;33mÓù´Í½ð±Ê[1;31mÐé»ÎÒ»ÕÐ£¬³Ã»úµãÁËÄãÊÖ±Û£¬Äã¸Ðµ½ÕæÆøÖÏ°­ÄÑÐÐ¡£\n"
	});
        int k=sizeof(busy_msg);
        j=random(i);
        tell_room(environment(me),"[1;33mÍ»È»¼ä"+me->query("name")+"·É¿ìµÄÍù"+
        enemy[j]->query("name")+"ÉíÉÏÒ»µã...[0m\n",enemy[j]);
	if( enemy[j] && living(enemy[j]) )
	 { 
	  tell_object(enemy[j],"[1;31m"+busy_msg[random(k)]+"[0m");
 	  enemy[j]->start_busy(random(3)+1);
 	 } 
}	
