#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit BLADE;
object ob=this_object();
void create()
{
	set_name("Ñıµ¶¡®´åÓê¡¯",({"evil-mblade","blade"}));
	set_weight(300);
set("mblade-mark",1);
        set("no_sell",1);
      set("no_get",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_auc",1);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","°Ñ");
set("long","Ñıµ¶¡®´åÓê¡¯£¬µ¶·æÍ¸Ã÷£¬µ¶Éíç³À¶£¬ÏñÍ¸Ã÷µÄÓêµãÏâÔÚç³À¶É«µÄ¹Ç¼¹£¬µ¶ÂÔ³¤£¬µ¶Íä´¦ÓĞÍ»³öµÄĞ¡¼âÈĞ£¬ÁÙÕóÉ±µĞÓĞÖÖÄªÃû¿ì¸Ğ¡£\n");
          set("value", 100);
          set("material","crimsonsteel");
	}
	init_blade(1);
  	setup();
}	
void init()
{
        add_action("do_blood","blood");
        add_action("do_power","power");
}

int do_blood(string str)
{  	
	object me=this_player();
        string name=ob->query("name");
        if( str != ob->query("id") )
	   return notify_fail("Çë¼üÈëÎäÆ÷È«Ãû¡£\n");
	if( ob->query("blooded") )
	  return notify_fail("Õâ°ÑÎäÆ÷ÒÑµÃµ½ÄãµÄÎşÉü¡£\n");
	if( ob->query("equipped") == "wielded" )
	  return notify_fail("ÇëÏÈ½«ÎäÆ÷Ğ¶ÏÂ¡£\n");
	message_vision("[31m$N»º»ºµÄÓÃ"+name+"ÍùÊÖÍó´¦Ò»»®, ÏÊÑªÈçÈªÓ¿°ãÁÜ±éÕû°Ñ"+name+"¡£\n
Ò»»á¶ù, ÏÊÑªÒÑ±»"+name+"Îü¸É´ù¾¡,¶ø"+name+"Ò²µ©È»µÄ·¢³öÒ»ÕóÒ«ÑÛµÄ[1;5;33m¹âÃ¢[0;31m¡£[0m\n",me);
set_name("[1;34m¡õ[0;34m¡õ[1;34m¡õ[0;34mM[1;31m¡®[1;37m¡õ[1;32m¡õ[1;37m¡õ[1;32mB[1;31m¡¯[0m",({"evil-mblade","blade"}));
set("wield_msg","\n$NÊÖÉÏºöÈ»¶àÁËÒ»°Ñ$n£¬µ¶¹âÑúÓ³Ò»Æ¬ÇßÀ¶£¬µ¶»Ó¶¯Ê±»¹´ø×ÅÒ»ÖÖÏñÒõÁé°ãµÄÉëÒ÷¡£\n\n");
set("unwield_msg","\n$NÊÖÉÏµÄ$nÏñÆßÔÂ°ëÃÍ¹í³ö¹Ø£¬ºöÈ»×ÔÊÖÉÏÏûÊ§ÎŞ×Ù¡£\n\n");
	set("weapon_prop/damage",100);
	set("value", 100);
	set("blooded",1);
set("mblade-mark",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
     set("no_get",1);
        set("no_drop",1);
        set("no_auc",1);
        me->set("kee",1);
        me->set("gin",1);
        me->set("sen",1);
        setup();
	return 1;
}

int do_power(string str)
{
        object weapon,me;
        me=this_player();
        if(me->query("evil-mblade") != 1)
        return notify_fail("ÄãÎŞ·¨¼İÓù´Ëµ¶¡£\n");
        if(!objectp(weapon=me->query_temp("weapon"))
        || (string)weapon->query("skill_type")!="blade")
          return notify_fail("ÒªÓĞµ¶²ÅÄÜÓÃ¾Û»êÊõ¡£\n");
   if(ob->query("blooded")!=1)
   return notify_fail("ÒªÏÈÓÃÑª(blood)Î¹ÄãµÄµ¶à¡£¡\n");
        if(weapon->query_temp("evil-mblade")==1)
          return notify_fail("ÄãÒÑ¾­ÔÚÓÃÁË¡£\n");
        message_vision(
  HIR "$NÒÔµ¶¼ÀÌì£¬¶ÙÊ±ÒõÁéÄı¾ÛÓÚ$n"+HIR+"¡£\n"NOR,me,weapon);
me->add_temp("apply/damage",100);
me->add_temp("apply/attack",100);
me->add_temp("apply/armor",100);
me->add_temp("apply/defense",100);
        weapon->set_temp("evil-mblade",1);
me->start_call_out((:call_other,__FILE__,"remove_effect",weapon,me:),me->query_skill("blade",1));
        return 1;
}
void remove_effect(object weapon,object me)
{
me->add_temp("apply/damage",-100);
me->add_temp("apply/attack",-100);
me->add_temp("apply/armor",-100);
me->add_temp("apply/defense",-100);
weapon->delete_temp("evil-mblade");
message_vision(HIW"Òõ·çĞìĞìµÄÒõÁé£¬¶ÙÊ±´Ó$n"+HIW+"·ÉÉ¢¿ªÀ´¡£\n"NOR,me,weapon);
}
int query_autoload()
{
	return 1;
}
