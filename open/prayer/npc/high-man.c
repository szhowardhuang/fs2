// ÒşÊÀ¸ßÈË

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
  object ob;
	set_name("[33mÓÚÍòÍ¥[0m", ({"master uh","master","uh"}));
        set("nickname","[36mµ¶Éñ½£ÏÉÊ®Èı±Ş[0m");
	set("long",@LONG

	ËûÔÚÉÙÄêÖ®Ê±, ¾«Í¨Öî°ãÎäÑ§, ÓÈÆäÒÔµ¶, ½£, ±ŞÈı
	ÕßÎª×î!!ĞÔÇéÎÂºÍ, Ï²»¶½«¾ßÓĞ×ÊÖÊÕßµ÷½Ì³ÉÎªÎäÒÕ
	¸ßÇ¿µÄİ¼Ó¢·İ×Ó!!ÓëÊ¥»ğ½ÌµÄ¸±½ÌÖ÷ÊÇ½áÒåµÄĞÖµÜ!!
	Òş¾ÓÖ®ºó×Ô³ÉÒ»ÅÉ, ×Ô³ÆÎª [¹ã³ÉÅÉ] !!

LONG);
	set("gender","ÄĞĞÔ");
        set("class","prayer");
        set("title","ÒşÊÀ¸ßÈË");
	set("combat_exp",4500000);
        set("attitude","heroism");
	set("age",73);
        set("kee",9500);
        set("max_kee",9500);
	set("force",10000);
	set("max_force",10000);
	set("force_factor",35);
        set("max_gin",6800);
        set("max_sen",6800);
        set_skill("dodge", 60);
	set_skill("sword", 300);
	set_skill("blade", 300);
	set_skill("whip", 300);
	set_skill("cure",65);
	set_skill("literate",65);
	set_skill("force",90);
        set_skill("move", 70);
        set_skill("parry", 70);
        set_skill("stick",55);
        set_skill("unarmed", 90);
	setup();
	create_family("¹ã³ÉÅÉ",1,"ÕÆÃÅ");
}

int accept_kill(object ob)
{
        command("smile");
	command("say ÀÏ·ò¾ÈÁËÄã, ÄãÏëÒªÒÔÔ¹±¨µÂÂğ??\n");
        return 0;

}

void init()
{
	object ob;
	::init();
	if(interactive(ob =this_player()) && !is_fighting() )
	{
	remove_call_out("greeting");
        call_out("greeting",1,ob);
        add_action("do_nod","nod"); 
        add_action("do_thx","thx");
        }
}

void greeting(object ob)
{
        if (ob->query_temp("high-man") == 4 )
        {
        write("\n[36mºÇºÇ, ÕâÎ»Ğ¡ĞÖµÜĞÑÁËæÖ??ÄãµÄÃüÕæ´ó!!ĞÒ¿÷ÊÇÎÒÂ·¹ı´ËµØ!!·ñÔòÄãµÄĞ¡Ãü¾ÍÃ»†ª!![0m\n");
        write("\nÄãµÄÉËÊÆÆÄÖØ, ºÃºÃµØĞİÑø°É!!\n");
        ob->set_temp("high-man", 5);
        return; 
        }
}

int do_thx()
{
	object ob=this_player();
	if ( ob->query_temp("high-man") == 5 )
        {
        write("\n[36mÀÏ·òÓëÄãÒ²ËãÊÇÓĞÔµÁË, ¿´ÄãµÄ×ÊÖÊÒ²²»´í, ¾Í´«ÄãÒ»Ğ©¹¦Á¦ÒÔÎª·ÀÉíÖ®ÓÃ°É!!²»¹ıÄãÏÂÉ½ºó, ¿É²»ÒªÏòÈËÌáÈÎºÎÖ»×ÖÆ¬Óï!!¶®Âğ(nod)??[0m\n");
        ob->set_temp("high-man", 6);
        return 1;
        }
	else
        {
	return 0;
	}
}

int do_nod()
{
	object ob = this_player();
	int lv  = (int)ob->query("cor");
	int lv1 = (int)ob->query("con");

        if( ob->query_temp("high-man") < 6 && ob->query("quests/high-man") )
        {
	return 0;
	}
	else
        {
	write("\n[36màÅ!!ÄÇÀÏĞàÕâ¾Í¿ªÊ¼´«¹¦ÁË!!,,,,,,,,,,,,,,[0m\n");
	ob->add("max_force", (lv+lv1)*5);
	ob->add("combat_exp", (lv+lv1)*1200); 
	ob->set_skill("sword", 30);
	ob->set_skill("blade", 30);
	ob->set_skill("whip", 30);
	ob->set("quests/high-man",1);
	ob->delete_temp("high-man");
        return 1;
	}

}
