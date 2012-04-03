inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("[18mºÚÉ«¹â¾§"NOR,({"black-crystal"}));
	set("long","Ò»¿éÂÔ³ÊºÚÉ«µÄ¹â¾§£¬ÔÚ¹â¾§ÉÏÃæ²»Ê±µÄÉ¢·¢×ÅÆæ¹ÖµÄÁé¹â£¬µ«ÈÎ\n"
		  +"ÄãÈçºÎµÄÏ¸¿´ºÍÑĞ¾¿£¬È´Ò²²»ÖªËüÓĞºÎ×÷ÓÃ£¬Ò²ĞíºÍ´«ËµÖĞµÄÌìÁé\n"
		  +"µØ½çÓĞ¹Ø¡£\n");
	set("unit","¿é");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set_weight(1000);
	setup();
}
