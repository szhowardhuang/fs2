//ÊØÎÀ made by chun,fix by funkcat, onion ÖØĞÂ¸ÄĞ´
		
#include </open/open.h>
inherit NPC;
string do_help();
object ob=this_object();

void create()
{
	set_name("³ÇÃÅÎÀ¾ü",({"gate soldier","soldier"}) );
	set("gender","ÄĞĞÔ");
	set("age",33);
	set("class","soldier");
	set("str",55);
	set("long","¾©³ÇÄÚÎ»½×½ÏµÍµÄ¾ü¹Ù£¬¸ºÔğ³ÇÃÅµÄÊØÎÀ¹¤×÷£¬Ò»Éí¾ü·ş¿´ÆğÀ´Ë§´ôÁË¡£\n");
        set("combat_exp",25000);
	
	set("max_kee",1000);
	set("chat_chance_combat", 2);
	set("chat_msg_combat",({
	"³ÇÃÅÎÀ¾üºÈµÀ£º¸ÒÔÚÔÚ´Ëµ·ÂÒ..²»Ïë»îÁËÊÇ°É!!\n",
	(: this_object(),"do_help" :),
	}) );
	set("inquiry", ([
	"thief" : "´óµÁ? ËäÈ»´ó¼Ò¶¼ÔÚËµ, ¿ÉÊÇÎÒ»¹ÊÇÃ»Óö×Å¹ı¡£  :P ",
	]));
	set_skill("blade",40);
	set_skill("parry",30);
	set_skill("dodge",20);
	set_skill("her-blade",60);
	map_skill("blade","her-blade");
        set_temp("apply/damage",50);
        set_temp("apply/dodge",50);
        set_temp("apply/attack",50);
	setup();
	carry_object(CAPITAL_OBJ"Ns_armor")->wear();
	carry_object(CAPITAL_OBJ"Ns_boots")->wear();
	carry_object(CAPITAL_OBJ"Ns_hat")->wear();
	carry_object(CAPITAL_OBJ"Ns_blade")->wield();
}

void init()
{
	object who;
	:: init();
	if(interactive(who =this_player()) && !is_fighting() )
		add_action("do_report","report");
}

int accept_fight(object who)
{
	return notify_fail("³ÇÃÅÎÀ¾üËµ£º¶Ô²»Æğ£¬ÎÒÕıÔÚÖ´ĞĞ¹«Îñ¡£\n");
}
int accept_kill(object who)
{
	command("say ´óµ¨"+who->query("name")+", µ¨¸ÒÄÖÊÂ!!");
	who->set_temp("É±³ÇÃÅÎÀ¾ü",1);
	return 1;
}
string do_help()
{
	object guard;
	command("say ¨Ü..Ôã¸â, ³Å²»×¡ÁË..");
	say("[33m³ÇÃÅÎÀ¾üÕĞÀ´ËûµÄÍ¬°é°ïÃ¦µÖµ²µĞÈË¡£[0m\n");
	guard=new(CAPITAL_NPC"gate_soldier");
	guard->move( environment() );
	guard->kill_ob( ob->query_enemy()[0] );
	return "[1;33m³ÇÃÅÎÀ¾üºÈµÀ£ºÀ´ÈË°¡..¸øÎÒÉÏ..[0m\n";
}
void greeting(object who)
{
	if( !is_fighting() && !who->query_temp("É±³ÇÃÅÎÀ¾ü") ) {
	if( who->query_temp("ÓĞÏò³ÇÃÅÊØÎÀ±¨¸æ") || wizardp(who) ) {
		command("smile "+getuid(who) );
		command("say "+who->name()+"ºÃ, »¶Ó­²Î¹Û¾©³Ç¡£ :)");
	}
       	else {
		command("stare "+getuid(who));
		command("say ¨Ü£¡ÕâÎ»"+RANK_D->query_respect(who)+", ÄÄÀïÀ´µÄ£¿±¨ÉÏ(report)ÃûÀ´¡£");
	}
	}
}

int do_report(string arg)
{
	object who=this_player();

	if( !arg || arg != getuid(who) )
		return notify_fail("Çë¸æËßÎÒÄãµÄid¡£\n");

	if( who->query_temp("ÓĞÏò³ÇÃÅÊØÎÀ±¨¸æ") )
	  return notify_fail("ÎÒÒÑ¾­ÖªµÀÁË£¬Äã²»ÓÃ¶ÔÎÒËµÕâÃ´¶à´Î, ÄãµÄidÊÇ"+getuid(who)+"£¬¶Ô°É£¿\n");
	who->set_temp("ÓĞÏò³ÇÃÅÊØÎÀ±¨¸æ",1);
	who->delete_temp("É±¾©³ÇÑ²Âß½ûÎÀ¾ü");
	command("say Ğ»Ğ»ÄúµÄºÏ×÷£¬ÏÖÔÚÄú¿ÉÒÔÍ¨¹ıÁË¡£\n");
	return 1;
}
