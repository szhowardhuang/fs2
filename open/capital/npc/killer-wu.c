// ·ÙÌìÄ§Íõ by roger
// ·ÙÌìÔÚĞŞÕı by chan
#include <ansi.h>
inherit NPC;   
void create()
{
        set("long","
ÄªÎŞ³î£¬ÌìÏÂµÚÒ»ºÚµÀÃËÖ÷£¬ÉÃ³¤°µÉ±£¬¿¿½±½ğÎªÉú!!!!!
½ÓÊÕ¸÷°ïÅÉÎ¯ÈÎ!!ÈôÓĞ±»°ïÅÉ×·¼©µÄÈË³öÏÖÔÚËûµÄÃæÇ°!!!¾ø¶ÔÊÇÉ±ÎŞºÕ!!!!
ÆäÎä¹¦Îª¼«»ğ¹¦¼°¼«»ğÕÆ!!!À´Àú²»Ïé!!!!
");
        set("gender","ÄĞĞÔ");
        set("class","fighter");
        set("nickname",HIR"¼«µÀÉ±ÊÖ"NOR);
        set("title","ºÚµÀÃËÖ÷");
        set_name("ÄªÎŞ³î",({"wu"}));
        set("combat_exp",15500000);
        set("attitude","hero");
        set("score",5000000);
        set("bellicosity",10000);
        set("age",45);
        set("max_force",250000);
        set("force",240000);
        set("max_kee",33000);
        set("kee",34000);
        set("max_gin",14000);
        set("max_sen",14000);
        set("str", 35);
        set("cor", 35);
set("no_lyssa",1);
        set("cps", 30);
        set("per", 30);
        set("int", 30);
        set("force_factor",45);
        set_skill("dodge",220);
        set_skill("force",250);
        set("clan_kill",1);     //²»ÄÜÅÉÉ±ÊÖ×·É±
        set_skill("move",280);
        set_skill("parry",250);
        set_skill("mogi-steps",200);
        set_skill("firestrike",220);
        set_skill("unarmed",220);
        set_skill("literate",200);
        set_skill("fireforce",250);
        set_temp("armor_vs_force",5000);
        map_skill("force","fireforce");
        map_skill("unarmed","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("parry","firestrike");
        set("functions/gold-fire/level",100);
        set("quest/gold-fire",1);
        set("quest/new_gold_fire",1);
        setup();
        carry_object("/data/autoload/mogi/fire-armor")->wear();
        carry_object("/data/autoload/mogi/fire-cloud-boots")->wear();
        carry_object("/data/autoload/mogi/fire-belt")->wear();
        carry_object("/data/autoload/mogi/daemon-cloak")->wear();
        carry_object("/data/autoload/mogi/fire-dragon")->wield();
        add_money("gold",1000);
}

void greeting(object ob)
{
 if(ob->query("ckill"))
  {
    command("say ¹ş!!¹ş!!ÓÖÒ»¸öÀ´ËÍËÀµÄ!!¿´ÕÆ!!");
    command("perform fireforce.gold-fire");
    kill_ob(ob);
    ob->start_busy(2);
  } else if(ob->query("mk-blade")) {
if(ob->query("gender")=="ÄĞĞÔ") {
if(ob->query("title")!="[1;37mäöÓğ[1;33mµ¶»Ê[0m" && !ob->query_temp("powerup") &&
   !ob->query_temp("addbasic")) {
tell_object(ob,HIW"ÄãÊ¹ÓÃĞ°ÁéÖÆµ¶Êõ´íÂÒ£¬ÎÒ°ïÄã»¹Ô­title\n"NOR);
ob->set("title","[1;37mäöÓğ[1;33mµ¶»Ê[0m"); }} else {
if(ob->query("title")!="[1;34mµ¶»ê[1;36mÓÄ¼§[0m" && !ob->query_temp("powerup") &&
   !ob->query_temp("addbasic")) {
tell_object(ob,HIW"ÄãÊ¹ÓÃĞ°ÁéÖÆµ¶Êõ´íÂÒ£¬ÎÒ°ïÄã»¹Ô­title\n"NOR);
ob->set("title","[1;34mµ¶»ê[1;36mÓÄ¼§[0m"); }}}
}
