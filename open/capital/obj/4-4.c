#include <weapon.h>
#include <combat.h>
inherit SWORD;
object ob=this_object();
void create()
{
	set_name("Ææ½£¡®ÍìÁô¡¯",({"stay sword","sword"}));
        set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","°Ñ");
	  set("long","\n¡®ÍìÁô¡¯£¬Õû°Ñ½£ÉíÊÇÖ±µÄ£¬Ö»ÓÐ½£µÄ°ÑÊÖÊÇÍäµÄ£¬ÍäÈç°ëÔÂ£¬ÁîÈË»³ÒÉÒªÈçºÎ³Ö½£¡£ÉÏÍ·¿Ì×Å\n"+
	"		 [36m¡¸ÍìÁôÌìÑÄÍìÁôÈË,ÍìÁôËêÔÂÍìÁôÄã¡±¡£[0m\n");
          set("value", 100);
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
          if( random(exp) > random(20000) && random(2)==0 && me->query("kar")>random(30) )
          {
	    message_vision("[32m$NÊÖÉÏ [0;5m"+ob->query("name")+" [32m»Ã»¯³öÒ»Æ¬ìÅÀöÃÔã¯, ¶ø$nºÃËÆÊ§ÁËÉñËÆµÄ´ôÁ¢²»¶¯¡£[0m\n\n",me,enemy[i]);
	    enemy[i]->set("start_busy", 10);
	    enemy[i]->add("kee",-10);
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
	set_name("[1mÆæ½£[1;33m¡®ÍìÁô¡¯[0m",({"stay sword","sword"}));
	set("wield_msg","\n$NÍ»È»°Î³ö$n£¬Ö»¾õµÃÓÖ¿ì¡¢ÓÖÆæ¡¢ÓÖ¾ø£¬Èý·Ö¾ªÑÞ£¬Èý·ÖäìÈ÷£¬Èý·Öã°âê£¬¼ÓÉÏÒ»·ÖµÄ²»¿ÉÒ»ÊÀ¡£\n\n");
	set("unwield_msg","$N½«$nÊÕÆð£¬Ö»¾õµÃºöÈ»Ö®¼äÈôÓÐËùÊ§¡£\n\n");
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
