#include <weapon.h>
#include <combat.h>
inherit BLADE;
object ob=this_object();
void create()
{
	set_name("±¦µ¶¡®ºìÐä¡¯",({"red-sleeve blade","blade"}));
	set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","°Ñ");
      	  set("long","\n¡®ºìÐä¡¯£¬µ¶·æÊÇÍ¸Ã÷µÄ£¬µ¶Éíç³ºì£¬ÏñÍ¸Ã÷µÄ²£Á§Ïâ¹ü×Åç³ºìÉ«µÄ¹Ç¼¹£¬µ¶ÂÔ¶Ì£¬µ¶Íä´¦Èç¾ø´ú¼ÑÈËµÄÏËÑü£¬ÈÃÈËÒ»¼ûÖÓÇé£¬Ò»¼ûÄÑÍü¡£\n");
          set("value", 100);
          set("material","blacksteel");
	}
	init_blade(1);
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
          if(exp<=0)    exp=5000;
          else          exp=5000+exp/10;
          if( random(exp) > random(20000) && random(3)==0 && me->query("kar")>random(30) )
          {
            message_vision("\n[35m$NÊÖÖÐ [0;5m"+ob->query("name")+" [35mÑú³öÒ»Æ¬µ¶¹â, ÈçÍ¬ÃÎÒ»°ãÖ®¼ä, $nµÄÉË¿Ú±ã¼¤³öÒ»µÀÑªÈª¡£[0m\n\n",me,enemy[i]);
	    enemy[i]->apply_condition("bleeding", 50);
	    enemy[i]->add("kee",-20);
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
	"Ò»ÕóÒ«ÑÛµÄ1;5;33m¹âÃ¢[0;31m¡£[0m\n",me);
	set_name("[1m±¦µ¶[1;35m¡®ºìÐä¡¯[0m",({"red-sleeve blade","blade"}));                                                       
  	set("wield_msg","\n$NÊÖÉÏºöÈ»¶àÁËÒ»°Ñ$n£¬µ¶¹âÑúÓ³Ò»Æ¬Ë®ºì£¬µ¶»Ó¶¯Ê±»¹´ø×ÅÒ»ÖÖÏñÒôô¥°ãµÄÇåÒ÷£¬»¹ÂÓÆðÎ¢Î¢µÄÏãÆø¡£\n\n");
	set("unwield_msg","\n$NÊÖÉÏµÄ$nÏñÒ»Ä¨Ï¦êÍ£¬ÏñÒ»³¡Ï¸Óê£¬ºöÈ»×ÔÊÖÉÏÏûÊ§ÎÞ×Ù¡£\n\n");
	set("weapon_prop/damage",99);
	set("value", 100000);
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
