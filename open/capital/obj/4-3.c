#include <weapon.h>
#include <combat.h>
inherit BLADE;
object ob=this_object();
void create()
{
	set_name("Ä§µ¶¡®²»Ó¦¡¯",({"should-not blade","blade"}));
	set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit","°Ñ");
      	  set("long","\n¡®²»Ó¦¡¯,µ¶ÉíÎŞÑÕÉ«£¬÷öµ­ÎŞ¹â£¬µ«ÇÆÔÚÃ¿¸öÈËÑÛÀï£¬È´¶¼ÓĞ²»Í¬ÑÕÉ«ÓĞµÄ·¢³öÁÁÁÒµÄºÚ¹â£¬ÓĞµÄÈçÇàµç£¬ÓĞµÄÈçô÷Ñª£¬ÓĞµÄ¾¹ÊÇÎå²Ê¹â»ª£¬Ä¿ÎªÖ®ìÅ¡£\n");
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
        int i,exp,count;
        object me=environment(this_object());
        object *enemy;
        if( me->is_fighting() && ob->query("equipped")=="wielded" && ob->query("blooded") )
        {
          enemy=me->query_enemy();
          i=random(sizeof(enemy));
          exp=me->query("combat_exp")-enemy[i]->query("combat_exp");
          if(exp<=0)    exp=5000;
          else          exp=5000+exp/10;
          if( random(exp) > random(20000) && random(5)==0 && me->query("kar")>random(30) )
          {
            message_vision("\n[36m$NÊÖÖĞ [0;5m"+ob->query("name")+" [36m²»°²µÄ¶¶¶¯ÆğÀ´, É¢·¢³ö¿ÉÅÂµÄÄ§Á¦, ´İ¶¯³ö$NÎŞÇîµÄÕ½ÒâÖ±Ö¸$n¡£[0m\n\n",me,enemy[i]);
	    for(count=0;count<5;count++)
	    {
	      message_vision(ob->query("name")+"[1;36mÒıÁì×Å$NµÄÊÖ×ö³ö·è¿ñ¹¥»÷!![0m\n",me);
	      COMBAT_D->do_attack(me,enemy[i],ob, TYPE_QUICK);
	    }
	  }
	}
}	
int do_blood(string str)
{
        object me=this_player();
        object ob=this_object();
        string name=ob->query("name");
        if( str != ob->query("id") )
           return notify_fail("Çë¼üÈëÎäÆ÷È«Ãû¡£\n");
        if( ob->query("blooded") )
          return notify_fail("Õâ°ÑÎäÆ÷ÒÑµÃµ½ÄãµÄÎşÉü¡£\n");
        if( ob->query("equipped") == "wielded" )
          return notify_fail("ÇëÏÈ½«ÎäÆ÷Ğ¶ÏÂ¡£\n");
        message_vision("[31m$N»º»ºµÄÓÃ"+name+"ÍùÊÖÍó´¦Ò»»®, ÏÊÑªÈçÈªÓ¿°ãÁÜ±éÕû°Ñ"+
        name+"¡£\n²»Ò»»á¶ù, ÏÊÑªÒÑ±»"+name+"Îü¸É´ù¾¡, ¶ø"+name+"Ò²µ©È»µÄ·¢³ö"+
        "Ò»ÕóÒ«ÑÛµÄ[1;5;33m¹âÃ¢[0;31m¡£[0m\n",me);
	set_name("[1mÄ§µ¶[1;36m¡®²»Ó¦¡¯[0m",({"should-not blade","blade"}));
	set("wield_msg","\n$N³é³ö$n£¬Ò»µ¶ÔÚÊÖ£¬Õû¸öÈËµÄÕ½Ö¾¶¼ËÆ±»´ø¶¯£¬·¢³ö·è¿ñµÄ¹¥»÷£¬É±Á¦´óÔö¡£\n\n");
	set("unwield_msg","$N½«ÊÖÉÏ$n·Å¿ª£¬Õû¸öÈËĞ¹ÁËÒ»¿ÚÆø£¬»º»ºµÄ½«$nÊÕÆğ¡£\n\n");
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
