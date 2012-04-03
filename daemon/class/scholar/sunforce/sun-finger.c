// handwriting.c by Onion
void create(){ seteuid(getuid()); }
int exert(object me,object target)
{
	string *WEAPON_NAME=({
"[0;34mÒ»ÑôÆøÖ¸[0m",
"[1;34mÒ»ÑôÆøÖ¸[0m",
"[0;36mÒ»ÑôÆøÖ¸[0m",
"[1;36mÒ»ÑôÆøÖ¸[0m",
"[1mÒ»ÑôÖ¸Æø[0m"
	});
	int damage = (me->query("force_factor")*me->query_skill("sunforce",1))/10;
        int force_cost = me->query("force_factor")*20;
	object ob;
	if( force_cost == 0 )
	  return notify_fail("ÖÁÉÙÒªÒ»³É¹¦Á¦à¸¡£\n");
        if( me->query("force") < force_cost )
          return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if( present("sunforce finger",me) )
	  return notify_fail("ÄãÄ¿Ç°ÒÑ¾­ÓĞÁíÒ»ÊøÒ»ÑôÆøÖ¸ÁË¡£\n");
        if( !me->query("marks/sun-finger") )
          return notify_fail("Äã»¹Ã»Ñ§»áà¸¡£\n");
	if( damage == 0 )
	  damage=1;
        if( damage > 120)
          damage=120;
        ob=new(CLASS_D("scholar")+"/obj/sunfinger");
        ob->set_name(WEAPON_NAME[damage/30],({"sunforce finger","finger"}) );
	ob->set("weapon_prop/damage",damage);
	ob->move(me);
        message_vision("\n[1m$NÃæÉ«ÄıÖØ, Á½ÊÖ½â³É´óÊÖÓ¡, ºöÈ»´óºÈÒ»Éù, Ò»µÀÖ¸ÆøÓÉÖ¸¼â³å³ö, ²ÓÀÃÎŞ±È¡£\n[0m\n",me);
	me->add("force",-force_cost);
        me->start_call_out( (: call_other, __FILE__, "do_vanish",ob,me :),20*60
);
        return 1;
}
void do_vanish(object ob,object me)
{
    if(!me) me=this_player();
    if(!me) me=previous_object();
    if(!me){
    if(ob) destruct(ob);
    return ;
    }
    if(!ob) return ;
	tell_object(me,"\n"+ob->query("name")+"ÂıÂıµÄÏûÊÅÓÚ¿ÕÆøÖĞ, ¾«Æø»Ø¹éÓÚ´óµØ¡£\n");
	destruct(ob);
}
