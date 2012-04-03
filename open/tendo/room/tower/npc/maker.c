#include <command.h>
#include <ansi.h>

inherit NPC;

void create()
{
    set_name( HIW"Â½²½´º"NOR ,({"maker lu","maker","lu"}));
    set("title", HIR"ÎäÆ÷"HIC"ÖýÔì´óÊ¦"NOR);
    set("gender", "ÄÐÐÔ");
    set("age",43);
    set("attitude","friendly");
    set("long",@LONG

        ËûÊÇÖýÔìÎäÆ÷µÄ´óÊ¦, ×¨ÃÅÎªÎäÁÖÏÀÊ¿ÃÇÖýÔìË³ÊÖµÄ±øÆ÷,
        ²»¹ýÕâÐ©±øÆ÷²»ÊÇËæ±ã¾ÍÄÜ´òÔì³öÀ´µÄ, ²ÄÁÏ·½Ãæ¿ÉµÃ·ÑÐÄ
        Ò»µãÈ¥ÊÕ¼¯........
LONG);

    set("combat_exp",3000);
    set("str",36);
    set("con",34);
    set("int",32);
    set("max_kee",300);
    set("kee",300);
    set("max_force",500);
    set("force_factor", 2);
    set("force",500);
    set("no_kill",1);
    setup();
}

void init()
{
        add_action("do_select","select");
}

int accept_object(object who, object obj)
{

        if( obj->value() == 1000000 )
        {
        write("[1;32mºÃ!ÎÒÈ¥×¼±¸Ò»ÏÂÖýÔì¿ÕÊÖÎäÆ÷µÄ¹¤¾ß!![0m\n");
        who->set_temp("money/unarmed",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 2200000 )
        {
        write("[1;32mºÃ!ÎÒÈ¥×¼±¸Ò»ÏÂÖýµ¶ÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/blade",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 1800000 )
        {
        write("[1;32mºÃ!ÎÒÈ¥×¼±¸Ò»ÏÂÖý¹­ÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/bow",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 2000000 )
        {
        write("[1;32mºÃ!ÎÒÈ¥×¼±¸Ò»ÏÂÖý±ÞÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/whisk",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 1600000 )
        {
        write("[1;32mºÃ!ÎÒÈ¥×¼±¸Ò»ÏÂÖýØ°Ê×ÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/dagger",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 1400000 )
        {
        write("[1;32mºÃ!ÎÒÈ¥×¼±¸Ò»ÏÂÖý¹÷ÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/stick",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 1200000 )
        {
        write("[1;32mºÃ!ÎÒÈ¥×¼±¸Ò»ÏÂÖýÉÈÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/fan",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 2400000 )
        {
        write("[1;32mºÃ!ÎÒÈ¥×¼±¸Ò»ÏÂ´ò½£ÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/sword",1);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[1;37mÉúÌú[0m" )
        {
        command("say [1;37mÕâÊÇ¿éÉúÌú!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!![0m\n");
        who->set_temp("marks/metal",1);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[1;32m»ÆÍ­[0m" )
        {
        command("say [1;37mÕâÊÇ¿é»ÆÍ­!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!![0m\n");
        who->set_temp("marks/metal",2);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[1;37m°×Òø[0m" )
        {
        command("say [1;37mÕâÊÇ¿é°×Òø!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!![0m\n");
        who->set_temp("marks/metal",3);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[1;33m½ð×Ó[0m" )
        {
        command("say [1;37mÕâÊÇ¿é»Æ½ð!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!![0m\n");
        who->set_temp("marks/metal",4);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[1;32m´äÓñ[0m" )
        {
        command("say [1;37mÕâÊÇ¿é´äÓñ!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!![0m\n");
        who->set_temp("marks/metal",5);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[1;37m°×Óñ[0m" )
        {
        command("say [1;37mÕâÊÇ¿é°×Óñ!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!![0m\n");
        who->set_temp("marks/metal",6);
        destruct(obj);
        return 1;
        }
        else
        {
        command("say [1;31mÕâÎ»¿Í¹ÙÕæÊÇ´ó·½, ÄÇÎÒ¾Í¹§¾´²»Èç´ÓÃü†ª!![0m\n");
        return 0;
        }
}

int do_select(string arg)
{
        object who=this_player();
        object bl,sw,st,un,fa,da,wh,bow;

	if( (int)this_player()->query("age") < 16 )
		return notify_fail("[1;36mÄãÄê¼ÍÌ«Ð¡ÁË£¬µÈÀÏÒ»µãÔÙÀ´ÖÆÔìÎäÆ÷°É¡£[0m\n");

        if( ( arg == "blade") && who->query_temp("money/blade") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("[1;33mÖýÔì´óÊ¦½«½ðÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆðÀ´ÁË....[0m\n\n");
            if ( who->query_temp("marks/metal",2) )
            bl=new("open/tendo/room/tower/obj/bl2");
       else if ( who->query_temp("marks/metal",4) )
            bl=new("open/tendo/room/tower/obj/bl4");
       else if ( who->query_temp("marks/metal",6) )
            bl=new("open/tendo/room/tower/obj/bl6");
       else if ( who->query_temp("marks/metal",5) )
            bl=new("open/tendo/room/tower/obj/bl5");
       else if ( who->query_temp("marks/metal",3) )
            bl=new("open/tendo/room/tower/obj/bl3");
       else bl=new("open/tendo/room/tower/obj/bl1");
           }
          who->delete("money/blade");
          who->delete("marks/metal");
          bl->move(who);
        message("system",
	HIW "\n\nÒ»´úÖýÔì´óÊ¦Â½²½´ºÎª[1;37m"+who->name()+"[0m´òÔìÁËÒ»°Ñ¾øÊÀ±øÆ÷[1;31m"+bl->name()+"[0m\n\n" NOR,users());
	return 1;
}

        if( ( arg == "sword") && who->query_temp("money/sword") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("[1;33mÖýÔì´óÊ¦½«½ðÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆðÀ´ÁË......[0m\n\n");
            if ( who->query_temp("marks/metal",2) )
            sw=new("open/tendo/room/tower/obj/sw2");
       else if ( who->query_temp("marks/metal",4) )
            sw=new("open/tendo/room/tower/obj/sw4");
       else if ( who->query_temp("marks/metal",6 ) )
        sw=new("open/tendo/room/tower/obj/sw6");
       else if ( who->query_temp("marks/metal",5) )
            sw=new("open/tendo/room/tower/obj/sw5");
       else if ( who->query_temp("marks/metal",3) )
            sw=new("open/tendo/room/tower/obj/sw3");
       else sw=new("open/tendo/room/tower/obj/sw1");
          }
          who->delete("marks/metal");
          who->delete("money/sword");
          sw->move(who);
        message("system",
	HIW "\n\nÒ»´úÖýÔì´óÊ¦Â½²½´ºÎª[1;37m"+who->name()+"[0m´òÔìÁËÒ»°Ñ¾øÊÀ±øÆ÷[1;31m"+sw->name()+"[0m\n\n" NOR,users());
	return 1;
}
       if( ( arg == "bow") && who->query_temp("money/bow") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("[1;33mÖýÔì´óÊ¦½«½ðÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆðÀ´ÁË......[0m\n\n");
            if ( who->query_temp("marks/metal",2) )
            bow=new("open/tendo/room/tower/obj/bow2");
       else if ( who->query_temp("marks/metal",4) )
            bow=new("open/tendo/room/tower/obj/bow4");
       else if ( who->query_temp("marks/metal",6 ) )
            bow=new("open/tendo/room/tower/obj/bow6");
       else if ( who->query_temp("marks/metal",5) )
            bow=new("open/tendo/room/tower/obj/bow5");
       else if ( who->query_temp("marks/metal",3) )
            bow=new("open/tendor/room/tower/obj/bow3");
       else bow=new("open/tendo/room/tower/obj/bow1");
          }
          who->delete("marks/metal");
          who->delete("money/bow");
          bow->move(who);
        message("system",
	HIW "\n\nÒ»´úÖýÔì´óÊ¦Â½²½´ºÎª[1;37m"+who->name()+"[0m´òÔìÁËÒ»°Ñ¾øÊÀ±øÆ÷[1;31m"+bow->name()+"[0m\n\n" NOR,users());
	return 1;
}
       if( ( arg == "whisk") && who->query_temp("money/whisk") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("[1;33mÖýÔì´óÊ¦½«½ðÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆðÀ´ÁË......[0m\n\n");
            if ( who->query_temp("marks/metal",2) )
            wh=new("open/tendo/room/tower/obj/wh2");
       else if ( who->query_temp("marks/metal",4) )
            wh=new("open/tendo/room/tower/obj/wh4");
       else if ( who->query_temp("marks/metal",6 ) )
            wh=new("open/tendo/room/tower/obj/wh6");
       else if ( who->query_temp("marks/metal",5) )
            wh=new("open/tendo/room/tower/obj/wh5");
       else if ( who->query_temp("marks/metal",3) )
            wh=new("open/tendo/room/tower/obj/wh3");
       else wh=new("open/tendo/room/tower/obj/wh1");
          }
          who->delete("marks/metal");
          who->delete("money/whisk");
          wh->move(who);
        message("system",
	HIW "\n\nÒ»´úÖýÔì´óÊ¦Â½²½´ºÎª[1;37m"+who->name()+"[0m´òÔìÁËÒ»°Ñ¾øÊÀ±øÆ÷[1;31m"+wh->name()+"[0m\n\n" NOR,users());
	return 1;
}
        if( ( arg == "dagger") && who->query_temp("money/dagger") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("[1;33mÖýÔì´óÊ¦½«½ðÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆðÀ´ÁË......[0m\n\n");
            if ( who->query_temp("marks/metal",2) )
            da=new("open/tendo/room/tower/obj/da2");
       else if ( who->query_temp("marks/metal",4) )
            da=new("open/tendo/room/tower/obj/da4");
       else if ( who->query_temp("marks/metal",6 ) )
            da=new("open/tendo/room/tower/obj/da6");
       else if ( who->query_temp("marks/metal",5) )
            da=new("open/tendo/room/tower/obj/da5");
       else if ( who->query_temp("marks/metal",3) )
            da=new("open/tendo/room/tower/obj/da3");
       else da=new("open/tendo/room/tower/obj/da1");
          }
          who->delete("marks/metal");
          who->delete("money/dagger");
          da->move(who);
        message("system",
	HIW "\n\nÒ»´úÖýÔì´óÊ¦Â½²½´ºÎª[1;37m"+who->name()+"[0m´òÔìÁËÒ»°Ñ¾øÊÀ±øÆ÷[1;31m"+da->name()+"[0m\n\n" NOR,users());
	return 1;
}

        if( ( arg == "stick") && who->query_temp("money/stick") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("[1;33mÖýÔì´óÊ¦½«½ðÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆðÀ´ÁË......[0m\n\n");
            if ( who->query_temp("marks/metal",4) )
            st=new("open/tendo/room/tower/obj/st4");
       else if ( who->query_temp("marks/metal",6) )
            st=new("open/tendo/room/tower/obj/st6");
       else if ( who->query_temp("marks/metal",2) )
            st=new("open/tendo/room/tower/obj/st2");
       else if ( who->query_temp("marks/metal",3) )
            st=new("open/tendo/room/tower/obj/st3");
       else if ( who->query_temp("marks/metal",5) )
            st=new("open/tendo/room/tower/obj/st5");
       else st=new("open/tendo/room/tower/obj/st1");
          }
          who->delete("money/stick");
          who->delete("marks/metal");
          st->move(who);
           message("system",
	HIW "\n\nÒ»´úÖýÔì´óÊ¦Â½²½´ºÎª[1;37m"+who->name()+"[0m´òÔìÁËÒ»°Ñ¾øÊÀ±øÆ÷[1;31m"+st->name()+"[0m\n\n" NOR,users());
	return 1;
}

        if( ( arg == "unarmed") && who->query_temp("money/unarmed") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("[1;33mÖýÔì´óÊ¦½«½ðÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆðÀ´ÁË......[0m\n\n");
            if ( who->query_temp("marks/metal",4) )
            un=new("open/tendo/room/tower/obj/un4");
       else if ( who->query_temp("marks/metal",6) )
            un=new("open/tendo/room/tower/obj/un6");
       else if ( who->query_temp("marks/metal",3) )
            un=new("open/tendo/room/tower/obj/un3");
       else if ( who->query_temp("marks/metal",5) )
            un=new("open/tendo/room/tower/obj/un5");
       else if ( who->query_temp("marks/metal",2) )
            un=new("open/tendo/room/tower/obj/un2");
       else un=new("open/tendo/room/tower/obj/un1");
          }
          who->delete("marks/metal");
          who->delete("money/unarmed");
          un->move(who);
        message("system",
	HIW "\n\nÒ»´úÖýÔì´óÊ¦Â½²½´ºÎª[1;37m"+who->name()+"[0m´òÔìÁËÒ»°Ñ¾øÊÀ±øÆ÷[1;31m"+un->name()+"[0m\n\n" NOR,users());
	return 1;
}
        if( ( arg == "fan") && who->query_temp("money/fan") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("[1;33mÖýÔì´óÊ¦½«½ðÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆðÀ´ÁË......[0m\n\n");
            if ( who->query_temp("marks/metal",5) )
            fa=new("open/tendo/room/tower/obj/fa5");
       else if ( who->query_temp("marks/metal",4) )
            fa=new("open/tendo/room/tower/obj/fa4");
       else if ( who->query_temp("marks/metal",2) )
            fa=new("open/tendo/room/tower/obj/fa2");
       else if ( who->query_temp("marks/metal",3) )
            fa=new("open/tendo/room/tower/obj/fa3");
       else if ( who->query_temp("marks/metal",6) )
            fa=new("open/tendo/room/tower/obj/fa6");
       else fa=new("open/tendo/room/tower/obj/fa1");
          }
          who->delete("marks/metal");
          who->delete("money/fan");
          fa->move(who);
          message("system",
	HIW "\n\nÒ»´úÖýÔì´óÊ¦Â½²½´ºÎª[1;37m"+who->name()+"[0m´òÔìÁËÒ»°Ñ¾øÊÀ±øÆ÷[1;31m"+fa->name()+"[0m\n\n" NOR,users());
	return 1;
}

}






