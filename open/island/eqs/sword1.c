#include <weapon.h>
inherit SWORD;
object ob=this_object();
void create()
{
	set_name("Éñ½£¡®ÑªºÓ¡¯",({"blood-river sword","sword"}));
	set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","°Ñ");
	  set("long","\n¡®ÑªºÓ¡¯£¬½£Éí°¼Í¹²»Æ½£¬½£·æÆä¶ÛÎÞ±È£¬½£¼¹ÍäÇú£¬½£¼âÍáÐ±£¬Èç¹ûËµÓÐ³öÉ«Ö®´¦£¬±ãÊÇÕâ°Ñ½£ÒþÒþÍ¸³öºì¹â¡£\n");
          set("value", 10);
          set("material","blacksteel");
        }
	init_sword(1);      
        setup();
}
void init()
{
	add_action("do_blood","blood");
	set_heart_beat(1);
}
void heart_beat()
{
        int i,exp;
        object me=environment(this_object());
        object *enemy;
        if( me->is_fighting() && ob->query("equipped")=="wielded" && ob->query("blooded") )
	{
	  enemy=me->query_enemy();
          i=random(sizeof(enemy));
	  exp=me->query("combat_exp")-enemy[i]->query("combat_exp");
	  if(exp<=0)	exp=5000;
	  else		exp=5000+exp/10;
	  if( random(exp) > random(20000) && random(4)==0 && me->query("kar")>random(30) )
	  {
            message_vision("\n[31m$NÊÖÖÐ [0;5m"+ob->query("name")+" [31mÍ»È»»¯³ÉÂúÊÒÒ«ÑÛºì¹âÁýÕÖ×¡$n¡£[0m\n\n",me,enemy[i]);
            enemy[i]->add("kee",-100);
            COMBAT_D->report_status(enemy[i]);
	  }
	}
}
int do_blood(string str)
{
	object me=this_player();
	string name=ob->query("name");
	if( str != ob->query("id") )
	  return notify_fail("Çë¼üÈëÎäÆ÷È«Ãû¡£\n");
	if( ob->query("blooded") )
	  return notify_fail("Õâ°ÑÎäÆ÷ÒÑµÃµ½ÄãµÄÎþÉü¡£\n");
	if( ob->query("equipped") == "wielded" )
	  return notify_fail("ÇëÏÈ½«ÎäÆ÷Ð¶ÏÂ¡£\n");
	message_vision("[31m$N»º»ºµÄÓÃ"+name+"ÍùÊÖÍó´¦Ò»»®, ÏÊÑªÈçÈªÓ¿°ãÁÜ±éÕû°Ñ"+
	name+"¡£\n²»Ò»»á¶ù, ÏÊÑªÒÑ±»"+name+"Îü¸É´ù¾¡, ¶ø"+name+"Ò²µ©È»µÄ·¢³ö"+
	"Ò»ÕóÒ«ÑÛµÄ[1;5;33m¹âÃ¢[0;31m¡£[0m\n",me);
	set_name("[1mÉñ½£[1;31m¡®ÑªºÓ¡¯[0m",({"blood-river sword","sword"}));
	set("weapon_prop/damage",99);
	set("value", 100000);
	set("wield_msg","\n$N»º»ºµÄ°Î³ö$n£¬½£×÷ÁúÒ÷£¬Çå´àÔÃ¶ú¡£Ò»ÖÖÕ§¿´ÁîÈËÐÄ¶¯£¬Ï¸¿´×ãÒÔÈÃÈËÐÄÑªêÚ¶¯µÄºì¹â£¬×Ô½£ÉíÍ¸ÁË³öÀ´¡£\n\n");
	set("unwield_msg","\n$N½«$nÊÕÈëºñÌ×¹ÅÇÊÖ®ÄÚ£¬ö®ÄÇ¼äÓÐÈçÌ«ÑôÎ÷ÏÂ°ã£¬ÂúµØºì¹âµ«È»ÏûÊ§¡£\nÖ»¼û½£ÇÊÈ´ÒþÈ»Í¸Ñú×ÅÑªºì£¬Ò»ÈçÈËÌåÀïµÄÑªÂöÒ»°ãÁ÷¶¯¡£\n\n");
	set("blooded",1);
	setup();
	call_out("wake_up",4);
	me->unconcious();
	return 1;
}
void wake_up()
{
	object who=this_player();
	who->remove_call_out("revive");
	who->revive();
}