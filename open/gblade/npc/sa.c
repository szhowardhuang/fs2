#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;
void create()
{
        set_name("¶À¹ÂáÓ",({"degu sa","sa"}));
        set("long","´ËÈËÊÇ¶À¹Â³îµÄÊ¦ĞÖ£¬ºÍµÜ×Ó¶À¹ÂÄª³îÒ»ĞÄÏëÆ½Ä§µ¶¡£\n");
        set("gender","ÄĞĞÔ");
        set("combat_exp",10000000);
        set("score",9000000);
        set("sec_kee","god");
        set("max_s_kee",1000);
        set("s_kee",1000);
        set("age",60);
        set("class","fighter");
        set("family/family_name","Ñ©²ÔÅÉ");
        set("title","ÎäÌìÖÁÊ¥");
        set("force",100000);
        set("max_gin",50000);
        set("max_kee",50000);
        set("max_sen",50000);
        set("bellicosity",30000);
        set("max_force",50000);
        set("max_atman",50000);
        set("max_mana",50000);
        set("atman",50000);
        set("mana",50000);
        set("force_factor",85);
        set("str",50);
        set("cor",50);
        set("cps",50);
        set("int",50);
        set("con",50);
        set("spi",50);
        set("kar",50);
        set("no_hole",1);
        set("no_plan_follow",1);
        set("no_mount",1);
        set("env/³åÑ¨","YES");
        set_skill("snow-martial", 100);
        set_skill("snowforce", 300);
        set_skill("literate",100);
        set_skill("black-steps",100);
        set_skill("unarmed",120);
        set_skill("dodge",100);
        set_skill("snow-kee",100);
        set_skill("parry",100);
        set_skill("force",300);
        map_skill("unarmed", "snow-martial");
        map_skill("parry","snow-kee");
        map_skill("force", "snowforce");
        map_skill("dodge", "black-steps");
        set_temp("armor_vs_force",1500);
        set_temp("no_die_soon",1);
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);
        set_temp("apply/dodge",50);
        set_temp("apply/parry",50);
        setup();
        carry_object("/open/snow/obj/figring")->wield();
        add_money("diamond", 10);
}
void init()
{
add_action("do_cmd","cmd");
add_action("do_cmd_do","");
add_action("do_team","");
}

int do_team(string arg)
{
object me,*all;
int i;
me=this_object();
all=all_inventory(environment(me));
if((string)query_verb()=="team") {
for(i=0;i<sizeof(all);i++)
{
if(all[i]->query("id")=="degu sa") continue;
if(!living(all[i])) continue;
if(wizardp(all[i])) continue;
kill_ob(all[i]);
}
}
}
int do_cmd_do(string arg)
{
if((string)query_verb()=="do") {
write(HIY"¶À¹ÂáÓÀäĞ¦ :¡¸ÓÃ do ÎÒ»á do run à¸¡±\n"NOR);
return 1;
}
}

int do_cmd(string str) {
 object who=this_player();
if(str=="throw five poison to sa" ||
   str=="throw five poison to degu sa") {
return 0;
} else 
 if(str=="askgod sa" || str=="askgod degu sa") {
 command("say ±¾ÎäÊ¥×îÑá¶ñÊ¹ÓÃÕ¼²·Ö¸ÁîµÄÈËÁË£¬ËÍËÀ°É£¡\n");
 who->start_busy(2);
 kill_ob(who);
}
 else if(str=="vet sa" || str=="vet degu sa") {
 command("say ±¾ÎäÊ¥×îÌÖÑáÃÉ¹Å´ó·òÁË£¡¸øÎÒÈ¥ËÀ°É£¡\n");
 who->start_busy(3);
 kill_ob(who);
 }
else if(str=="bak sa" || str=="bak degu sa") {
  command("say ±¾ÎäÊ¥Ò»Éú¹âÃ÷×îÑá¶ñÍµÍµÃşÃşµÄÈËÁË£¬ËÍËÀ°É£¡\n");
  who->start_busy(2);
  kill_ob(who);
}
 return 1;
}

void heart_beat()
{
object winner = query_temp("last_damage_from");  
object me,*target,victim,*player;
int i,j,k,a,b,c,d=0;
a=random(100);
me=this_object();
if(me->is_fighting()||me->is_killing()) {
target=me->query_enemy();
player=me->query_enemy();
if(i=sizeof(target)) {
if(a>=6&&a<=35) {
message_vision(HIC"\n¶À¹ÂáÓÍ»È»ÑÛÂ¶Ğ×¹â£¬ÖÜÎ§¾Û¼¯ÒõÀäÄÚ¾¢\n\n"NOR"
"HIR"¶À¹ÂáÓĞ°¶ñµÄ¿ñºğ£º¿´ÎÒµÄ¡®ÃğÊ¬ÈÜÑªÕÆ¡¯\n\n"NOR"
"HIB"¶ÙÊ±Ò»¹ÉÇ¿ÁÒµÄÊ¬³ôÎ¶ÃÖÌì¶øÉúÂ¤ÕÖËÄÖÜÎ§\n\n"NOR,me);
for(b=0;b<i;b++) {
if(userp(target[b])) continue;
target[b]->die();
}
}
if(random(100)>40) {
for(c=0;c<i;c++) {
if(!userp(target[c])) continue;
player[d]=target[c];
d=d+1;
}
victim=player[random(d)];
if(!victim) { } else {
if(a>=1&&a<=5) {
if(environment(me)==environment(victim)) {
for(k=0;k<10;k++) {
message_vision(HIG"¶À¹ÂáÓ´óºÈÒ»Éù£¬ÈÚºÏÑ©²ÔÓëãñÉ½¾øÑ§£¬Ïò$N»÷³ö¡®Ğş±ùÀë»ğÕÆ---»ÙÌìÃğµØÊ½¡¯\n"NOR,victim);
victim->receive_damage("kee",600,me); 
COMBAT_D->report_status(victim);
}
victim->set_temp("last_damage_from",me);
}
} else if(a>=36&&a<=45) {
if(environment(me)==environment(victim))
for(b=0;b<2;b++) {
message_vision(HIR"¶À¹ÂáÓ´óºÈÒ»Éù£¬ÈÚºÏÑ©²Ô¾øÑ§£¬Ïò$N»÷³ö¡®Ğş±ùÀë»ğÕÆÒ»Ê½¡¯\n"NOR,victim);
victim->receive_damage("kee",300,me);
COMBAT_D->report_status(victim);
}
} else if(a>=56&&a<=60) {
if(environment(me)==environment(victim))
for(b=0;b<4;b++) {
message_vision(HIY"¶À¹ÂáÓ´óºÈÒ»Éù£¬ÈÚºÏÑ©²Ô¾øÑ§£¬Ïò$N»÷³ö¡®Ğş±ùÀë»ğÕÆ¶şÊ½¡¯\n"NOR,victim);
victim->receive_damage("kee",300,me);
COMBAT_D->report_status(victim);
}
} else if(a>=71&&a<=75) {
if(environment(me)==environment(victim))
for(b=0;b<6;b++) {
message_vision(HIM"¶À¹ÂáÓ´óºÈÒ»Éù£¬ÈÚºÏÑ©²Ô¾øÑ§£¬Ïò$N»÷³ö¡®Ğş±ùÀë»ğÕÆÈıÊ½¡¯\n"NOR,victim);
victim->receive_damage("kee",300,me);
COMBAT_D->report_status(victim);
}
} else if(a>=86&&a<=90) {
if(environment(me)==environment(victim))
for(b=0;b<8;b++) {
message_vision(HIB"¶À¹ÂáÓ´óºÈÒ»Éù£¬ÈÚºÏãñÉ½¾øÑ§£¬Ïò$N»÷³ö¡®Ğş±ùÀë»ğÕÆËÄÊ½¡¯\n"NOR,victim);
victim->receive_damage("kee",300,me);
COMBAT_D->report_status(victim);
}
} else if(a>=94&&a<=98) {
if(environment(me)==environment(victim))
for(b=0;b<10;b++) {
message_vision(HIC"¶À¹ÂáÓ´óºÈÒ»Éù£¬ÈÚºÏãñÉ½¾øÑ§£¬Ïò$N»÷³ö¡®Ğş±ùÀë»ğÕÆÎåÊ½¡¯\n"NOR,victim);
victim->receive_damage("kee",300,me);
COMBAT_D->report_status(victim);
}
} else if(a==99||a==66||a==0) {
if(environment(me)==environment(victim))
for(b=0;b<20;b++) {
message_vision(HIW"¶À¹ÂáÓ´óºÈÒ»Éù£¬ÈÚºÏÑ©²ÔºÍãñÉ½¾øÑ§£¬Ïò$N»÷³ö¡®Ğş±ùÀë»ğÕÆ---ÎŞÑÄÊ½¡¯\n"NOR,victim);
victim->receive_damage("kee",250,me);
COMBAT_D->report_status(victim);
}
} else { }
}
}
}
me=this_object();
target=me->query_enemy();
if(random(100)>50)
{
if(i=sizeof(target))
{
if(!me->query("change"))
{
if(random(10) >= 5)
{
message_vision(HIY"¶À¹ÂáÓÔËÆğ¡®Àë»ğÕÆ¡¯ÏòÄãÒ»»÷£¬¶ÙÊ±ÄãÏÊÑª¿ñÅç£¡\n"NOR,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-2000);
target[j]->apply_condition("hart",10);
}
} else {
message_vision(HIC"¶À¹ÂáÓĞÄ¸ĞÆ£±·£¬ÔËÆğ¡®¶À¹ÂÃØ´«·¨Öä¡¯Ò»µÀÀ¶¹â´Ó²ÔÌì·¢³ö£¬¶ÙÊ±¾«Éñ°Ù±¶¡£\n"NOR,me);
me->receive_curing("gin",2500);
me->receive_heal("gin",2500);
me->receive_curing("kee",5000);
me->receive_heal("kee",5000);
me->receive_curing("sen",2500);
me->receive_heal("sen",2500);
me->add("force",1500);
me->delete_busy();
me->clear_condition();
}
} else {
if(random(10) >= 5) {
message_vision(@LONG

[1;36m¶À¹ÂáÓÔËÆğÑ©²Ôº®¾¢£¬¶ÙÊ±Ö»¼û¶À¹ÂáÓÀ¶¹â»¤Éí£¬ö®ËÆÌìÉñ£¡
[1;33m¡î¡ï¡î¡ï¡î¡ï¡î¡ï¡î¡ï¡î¡ï¡î¡ï¡î¡ï¡î¡ï¡î

[1;31m¶À¹ÂáÓÅ­ºğ£º¿´ÎÒµÄ¡®ÕÀÀ¶¹âÌåÊõ¡¯£¡£¡£¡

[1;33m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
[1;36m¶ÙÊ±Ò»ÕóÇ¿ÁÒµÄÀ¶¹âËÆÃÍ»¢ËÆµÄ°ÑÄãÍÌÃ»ÔÚ¿ÚÖĞ£¡
[0m

LONG,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-4000);
target[j]->apply_condition("cold",10);
target[j]->set_temp("over/left",1);
target[j]->set_temp("over/r-eyes",1);
}
} else {
message_vision(HIC"¶À¹ÂáÓĞÄ¸ĞÆ£±·£¬ÔËÆğ¡®ÕÀÀ¶¹âÌåÊõ¡¯Ò»µÀÀ¶¹â´Ó²ÔÌì·¢³ö£¬¶ÙÊ±¾«Éñ°Ù±¶¡£\n"NOR,me);
me->receive_curing("gin",5000);
me->receive_heal("gin",5000);
me->receive_curing("kee",10000);
me->receive_heal("kee",10000);
me->receive_curing("sen",5000);
me->receive_heal("sen",5000);
me->delete_busy();
me->add("force",3000);
me->clear_condition();
}
}
}
}
if((me->query("eff_kee") < 4000 || me->query("kee") < 4000) &&
!me->query("change"))
{
tell_object(users(),"[1;37m");
tell_object(users(),"\n¿É¶ñÑ½£¡¶À¹ÂáÓÅ­µÀ£ºÀÏ»¢²»·¢Íş£¬Äãµ±²¡Ã¨£¡\n\n¿´À´ÎÒÖ»ºÃÊ¹³ö°Ù·ÖÖ®¶ş°ÙµÄÁ¦Á¿ÁË£¡\n\n¿ÉºŞµÄ"+winner->query("name")+"µÈËÀ°É£¡\n\n");
tell_object(users(),"[0m");
        me->set("force_factor",50);
        me->set("eff_kee",50000);
        me->set("kee",50000);
        me->set("eff_gin",50000);
        me->set("eff_sen",50000);
        me->set("gin",50000);
        me->set("sen",50000);
        me->set("force",100000);
        me->set("fire_strike",1);
        me->set("super_fire",1);
        me->set("family/family_name","ãñÉ½ÅÉ");
        me->set("env/ãñÉ½Á¬»÷","YES");
        me->set("combat_exp",20000000);
        me->set_skill("lungshan", 100);
        me->set_skill("haoforce", 300);
        me->set_skill("fire-kee",100);
        me->set_temp("kang-power",1);
        map_skill("unarmed", "lungshan");
        map_skill("parry","fire-kee");
        map_skill("force", "haoforce");
        me->reset_action();
        me->set("change",1);
        me->delete_busy();
        me->clear_condition();
        me->set("title",HIC"¡®ÕÀÀ¶Ê¥¹â¡¯"+HIW+"ÎäÌìÖÁÊ¥"NOR);
}
}
me->clean_up_enemy();
::heart_beat();
}

void die()
{
object *enemy;
int i,j;
object winner = query_temp("last_damage_from");
object head,me,ring;
string name = winner->query("name");
me=this_object();
enemy=me->query_enemy();
i=sizeof(enemy);
ring=present("mdragon-ring",winner);
log_file("mblade/kill_sa", sprintf("%s(%s) ´ò°Ü ¶À¹ÂáÓ on %s\n"
,name,winner->query("id"), ctime(time()) ));
head=new("/open/gblade/obj/sa-head");
head->move(winner);
if(!ring) {
winner->set("meq/mring",1);
head=new("/data/autoload/mblade/mring");
head->move(winner);
}
if(userp(winner)) winner->add("snow-head",50);
winner->set_temp("ko_sa",1);
for(j=0;j<i;j++) {
if(enemy[j]->query("class")!="blademan") continue;
enemy[j]->set_temp("ko_sa",1);
}
/*
	if( winner->query("clan/id") && userp(winner) )
	CLAN_D->add_clanset( winner->query("clan/id"), "develop" ,  20 );
*/
	tell_room(environment(),sprintf("%s´Ó¶À¹ÂáÓÉíÉÏÇĞÏÂÒ»¿ÅÈËÍ·¡£\n",winner->name()));
	tell_object(users(),HIW"\n\n¶À¹ÂáÓÑÙÑÙÒ»Ï¢µÀ£º\n\n\t¿ÉºŞ£¡¿ÉºŞÑ½£¡Ã»Ïëµ½ÎÒÒ»´úÎäÊ¥£¡\n\n\t¾¹°ÜÓÚ"+winner->name()+"ÕâÎŞÃûĞ¡±²£¡¿ÉºŞ°¡£¡\n\n"NOR);
	:: die();
}

int accept_fight(object who)
{
	command("say ×ß¿ª±ğ·³ÎÒ£¡\n");
	return 0;
}

int accept_kill(object who)
{
	who=this_player();
	command("kill "+who->query("id"));
	command("cmd god_kee");
	return 1;
}
