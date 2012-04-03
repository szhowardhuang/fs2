// È«ĞÂ¸Ä°æ by swy
// ÔÙ´ÎÕûºÏÉó²é npc »á±©Ç¿ÎÊÌâ by swy
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <login.h>
inherit F_DBASE;
inherit SSERVER;
// skills ÀïµÄ force Öµ
mapping force_div = ([
"fighter"   :500,
"bandit"    :400,
"swordsman" :400,
"blademan"  :400,
"scholar"   :300,
"bonze"     :300,
"officer"   :300,
"prayer"    :300,
"beggar"    :300,
"marksman"  :300,
"dancer"    :200,
"poisoner"  :100,
"killer"    :100,
"taoist"    :100,
"doctor"    :100,
]);
// skills ÀïµÄ damage Öµ
mapping damage_div = ([
"fighter"   :500,
"bandit"    :400,
"swordsman" :400,
"blademan"  :400,
"scholar"   :300,
"bonze"     :300,
"officer"   :300,
"prayer"    :300,
"beggar"    :300,
"marksman"  :300,
"dancer"    :200,
"poisoner"  :100,
"killer"    :100,
"taoist"    :100,
"doctor"    :100,
]);
// class »ù±¾ÃüÖĞÂÊ
mapping hurt_div = ([
"fighter"   :500,
"bandit"    :600,
"swordsman" :600,
"blademan"  :600,
"scholar"   :700,
"bonze"     :700,
"officer"   :700,
"prayer"    :700,
"beggar"    :700,
"killer"    :700,
"marksman"  :700,
"dancer"    :800,
"poisoner"  :800,
"taoist"    :800,
"doctor"    :800,
]);
// class ÕĞ¼Üµ÷ÕûÖµ
mapping parry_div = ([
"dancer"    :       9,
"poisoner"  :       9,
"doctor"    :       8,
"taoist"    :       8,
"killer"    :       8,
"marksman"  :       7,
"scholar"   :       7,
"bandit"    :       7,
"prayer"    :       6,
"officer"   :       6,
"fighter"   :       6,
"bonze"     :       5,
"beggar"    :       5,
"blademan"  :       4,
"swordsman" :       4,
]);

string *guard_msg = ({
        CYN "$N×¢ÊÓ×Å$nµÄĞĞ¶¯£¬ÆóÍ¼Ñ°ÕÒ»ú»á³öÊÖ¡£\n" NOR,
        CYN "$NÕı¶¢×Å$nµÄÒ»¾ÙÒ»¶¯£¬ËæÊ±×¼±¸·¢¶¯¹¥ÊÆ¡£\n" NOR,
        CYN "$N»º»ºµØÒÆ¶¯½Å²½£¬ÏëÒªÕÒ³ö$nµÄÆÆÕÀ¡£\n" NOR,
        CYN "$NÄ¿²»×ª¾¦µØ¶¢×Å$nµÄ¶¯×÷£¬Ñ°ÕÒ½ø¹¥µÄ×î¼ÑÊ±»ú¡£\n" NOR,
        CYN "$N²»Í£µÄÔÚ$nÉíÅÔÓÎÒÆ×Å£¬×¨ĞÄµÄÑ°ÕÒ$nµÄÆÆÕÀ¡£\n" NOR,
        CYN "$NÂıÂıµØÒÆ¶¯×Å½Å²½£¬ËÅ»ú³öÊÖ¡£\n" NOR,
        CYN "$NÑÛ¹ÛËÄÂ·£¬¶úÌı°Ë·½£¬¼¯ÖĞ¾«ÉñÓë$n²ø¶·×Å¡£\n" NOR,
        CYN "$N²½²½ÎªÓª£¬Ë«ÑÛÖ±ÊÓ×Å$n£¬ÏëÕÒ³ö$nµÄ·ÀÊØÂ©¶´¡£\n" NOR,
});

string *catch_hunt_msg = ({
        YEL "$NºÍ$n³ğÈËÏà¼û·ÖÍâÑÛºì£¬Á¢¿Ì´òÁËÆğÀ´£¡\n" NOR,
        YEL "$N¶Ô×Å$n´óºÈ£º¡¸¿É¶ñ£¬ÓÖÊÇÄã£¡¡±\n" NOR,
        YEL "$NºÍ$nÒ»ÅöÃæ£¬¶ş»°²»Ëµ¾Í´òÁËÆğÀ´£¡\n" NOR,
        YEL "$NÒ»¼ûµ½$n£¬ÀäÀäµÄµÀ£º¡¸ÎÒÁ©»¹ÕæÊÇÓĞÔµÑ½£¡È¥ËÀ°É£¡¡±\n" NOR,
        YEL "$NÒ»ÑÛÆ³¼û$n£¬¡¸ºß¡±µÄÒ»Éù³åÁË¹ıÀ´£¡\n" NOR,
        YEL "$NÒ»¼ûµ½$n£¬ã¶ÁËÒ»ã¶£¬´ó½Ğ£º¡¸ÎÒÔ×ÁËÄã£¡¡±\n" NOR,
        YEL "$N¶Ô×Å$nÀäÀäµÄºßÁËÒ»Éù£¬ÏëÖÂ$nÓÚËÀµØ£¡\n" NOR,
        YEL "$NÓë$n²Á¼ç¶ø¹ı£¬Á¢¿Ì×ª¹ıÉíÀ´£¬´ó½Ğ£º¡¸Ğ¡Íõ°Ëµ°ÄÄÀïÅÜ£¡¡±\n" NOR,
});

int death_effect(object victim);
string dodge_skill, parry_skill,skill_map,class1,class2,class3,my_skill_message2,k_class;
string rstrone,rstrtwo;
int ap, dp, op, pp,fap,fdp, damage, damage_bonus, i,my_skill=0,choose_skill;
int wounded=0,ppp,divv,div1_2,div1,div2,c1,c2,cmexp,my_skill_power=0,power_dam;
int bssone=0;
int pod;
int dodge_ratio;

void create()
{
        seteuid(getuid());
        set("name", "ËÀÉñ");
        set("id", "deadgod");
}

string damage_msg(int damage, string type)
{

	string str;
	object me = this_player();
	object victim;
	if(!me) me=previous_object();
	if(!me) return "";
	victim=offensive_target(me);
	if(!victim) return "";
	if( damage == 0 )
		return "½á¹ûÃ»ÓĞÔì³ÉÈÎºÎÉËº¦¡£\n";
	//Õâ²¿·İ»áÕÕ³ÉÍæ¼ÒµÄÒòÈÅ,ËùÒÔÎÒÏÈDisable by Chan 2002/08/11
	/*
	if( damage > victim->query("max_kee")*2 ) {
		if( !userp(victim) )
			victim->set( "corpse_gone", 1 );
		str = HIR"½á¹ûÌı¼û¡¸ºä¡±µØÒ»Éù¾ªÌì¾ŞÏì, ¼«¶È¾ª¿ÖµÄ$nË²¼ä»¯³ÉıV·Û, »Ò·ÉäÎÃğ¡£"NOR;
		if( wizardp(me) )
			str += "(" + damage + ")";
		return str + "\n";
	}
	*/
	if( wizardp(me) || wizardp(victim) )
		return "Ôì³É "HIR + damage + NOR" µã" + type + "¡£\n";
        switch( type ) {
        case "”ÛÉË":
        case "¸îÉË":
                if( damage < 100 ) return "½á¹ûÖ»ÊÇÇáÇáµØ»®ÆÆ$pµÄÆ¤Èâ¡£\n";
                else if( damage < 300 ) return "½á¹ûÔÚ$p$l»®³öÒ»µÀÏ¸³¤µÄÑªºÛ¡£\n";
                else if( damage < 500 ) return "½á¹û¡¸àÍ¡±µØÒ»Éù»®³öÒ»µÀÉË¿Ú£¡\n";
                else if( damage < 700 ) return "½á¹û¡¸àÍ¡±µØÒ»Éù»®³öÒ»µÀÑªÁÜÁÜµÄÉË¿Ú£¡\n";
                else if( damage < 900 ) return "½á¹û¡¸àÍ¡±µØÒ»Éù»®³öÒ»µÀÓÖ³¤ÓÖÉîµÄÉË¿Ú£¬½¦µÃ$NÂúÁ³ÏÊÑª£¡\n";
                else return "½á¹ûÖ»Ìı¼û$nÒ»Éù²Òº¿£¬$wÒÑÔÚ$p$l»®³öÒ»µÀÉî¼°¼û¹ÇµÄ¿ÉÅÂÉË¿Ú£¡£¡\n";
                break;
        case "´ÌÉË":
                if( damage < 100 ) return "½á¹ûÖ»ÊÇÇáÇáµØ´ÌÆÆ$pµÄÆ¤Èâ¡£\n";
                else if( damage < 300 ) return "½á¹ûÔÚ$p$l´Ì³öÒ»¸ö´´¿Ú¡£\n";
                else if( damage < 500 ) return "½á¹û¡¸àÛ¡±µØÒ»Éù´ÌÈëÁË$n$l´çĞí£¡\n";
                else if( damage < 700 ) return "½á¹û¡¸àÛ¡±µØÒ»Éù´Ì½ø$nµÄ$l£¬Ê¹$p²»ÓÉ×ÔÖ÷µØÍËÁË¼¸²½£¡\n";
                else if( damage < 900 ) return "½á¹û¡¸àÛàÍ¡±µØÒ»Éù£¬$wÒÑÔÚ$p$l´Ì³öÒ»¸öÑªÈâ¼UºıµÄÑª¿ßÁş£¡\n";
                else return "½á¹ûÖ»Ìı¼û$nÒ»Éù²Òº¿£¬$wÒÑÔÚ$pµÄ$l¶Ô´©¶ø³ö£¬ÏÊÑª½¦µÃÂúµØ£¡£¡\n";
                break;
        case "ğöÉË":
                if( damage < 500 ) return "½á¹ûÖ»ÊÇÇáÇáµØÅöµ½£¬±ÈÅÄ²ÔÓ¬ÉÔÎ¢ÖØÁËµã¡£\n";
                else if( damage < 1000 ) return "½á¹ûÔÚ$pµÄ$lÔì³ÉÒ»´¦ğöÇà¡£\n";
                else if( damage < 1500 ) return "½á¹ûÒ»»÷ÃüÖĞ£¬$nµÄ$lµÇÊ±Ö×ÁËÒ»¿éÀÏ¸ß£¡\n";
                else if( damage < 2000 ) return "½á¹ûÒ»»÷ÃüÖĞ£¬$nÃÆºßÁËÒ»ÉùÏÔÈ»³ÔÁË²»Ğ¡µÄ¿÷£¡\n";
                else if( damage < 2500 ) return "½á¹û¡¸Åé¡±µØÒ»Éù£¬$nÍËÁËÁ½²½£¡\n";
                else if( damage < 3500 ) return "½á¹ûÕâÒ»ÏÂ¡¸Åé¡±µØÒ»Éù´òµÃ$nÁ¬ÍËÁËºÃ¼¸²½£¬²îÒ»µãË¤µ¹£¡\n";
                else if( damage < 4500 ) return "½á¹ûÖØÖØµØ»÷ÖĞ£¬$n¡¸ÍÛ¡±µØÒ»ÉùÍÂ³öÒ»¿ÚÏÊÑª£¡\n";
                else if( damage < 5500 ) return "½á¹ûÕâ»ÙÌìÃğµØ¡¸ºä¡±µØÒ»»÷Ê¹µÃ$nÑªÁ÷ÂúµØ£¡\n";
                else return "½á¹ûÖ»Ìı¼û¡¸Åé¡±µØÒ»Éù¾ŞÏì£¬$nÏñÒ»À¦µ¾²İ°ã·ÉÁË³öÈ¥£¡£¡\n";
                break;
        case "±ŞÉË":
                if( damage < 100 ) return "½á¹ûÖ»ÊÇ´Ó$l±íÃæÇáÇá²Á¹ı¡£\n";
                else if( damage < 300 ) return "½á¹ûÅ¾µÄÒ»ÉùÔÚ$p$l´òÁËÒ»ÌõÒóºìµÄ±ŞºÛ¡£\n";
                else if( damage < 500 ) return "½á¹ûË¢µÄÒ»ÉùÔÚ$p$l³éÁËÒ»µÀÓÖ³¤ÓÖÉîµÄ¿É²ÀÑªºÛ£¡\n";
                else if( damage < 700 ) return "½á¹û$nÒ»Éù°§º¿£¬ÉíÉÏÒÑ¶àÁËÌõÉî¼°¼û¹ÇµÄ¿ÉÅÂÉË¿Ú£¡\n";
                else if( damage < 900 ) return "½á¹ûÖ»Ìı¼û$nÒ»Éù²Ò½Ğ£¬$n$lÒÑ±»³éµÄÆ¤¿ªÈâÕÀ,ÏÊÑªÖ±Á÷£¡\n";
                else return "½á¹ûÒ»±ŞÃüÖĞ,Ö»Ìı¼û¿©À²Ò»Éù,£¬n°§ºÅµ¹µØ$l½î¶Ï¹ÇÁÑ,ÏÊÑª¿ñÓ¿²»Ö¹£¡£¡\n";
                break;
        default:
                if( !type ) type = "ÉËº¦";
                if( damage < 100 ) str =  "½á¹ûÖ»ÊÇÃãÇ¿Ôì³ÉÒ»´¦ÇáÎ¢";
                else if( damage < 300 ) str = "½á¹ûÔì³ÉÇáÎ¢µÄ";
                else if( damage < 500 ) str = "½á¹ûÔì³ÉÒ»´¦";
                else if( damage < 700 ) str = "½á¹ûÔì³ÉÒ»´¦ÑÏÖØ";
                else if( damage < 900 ) str = "½á¹ûÔì³ÉÆÄÎªÑÏÖØµÄ";
                else if( damage < 1100 ) str = "½á¹ûÔì³ÉÏàµ±ÑÏÖØµÄ";
                else if( damage < 1300 ) str = "½á¹ûÔì³ÉÊ®·ÖÑÏÖØµÄ";
                else if( damage < 1500 ) str = "½á¹ûÔì³É¼«ÆäÑÏÖØµÄ";
                else str =  "½á¹ûÔì³É·Ç³£¿ÉÅÂµÄÑÏÖØ";
                return str + type + "£¡\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIW "¿´ÆğÀ´ÆøÑª³äÓ¯£¬²¢Ã»ÓĞÊÜÉË¡£" NOR;
        if( ratio > 95 ) return HIG "ËÆºõÊÜÁËµãÇáÉË£¬²»¹ı¹â´ÓÍâ±í¿´²»´ó³öÀ´¡£" NOR;
        if( ratio > 90 ) return HIG "¿´ÆğÀ´¿ÉÄÜÊÜÁËµãÇáÉË¡£" NOR;
        if( ratio > 80 ) return GRN "ÊÜÁË¼¸´¦ÉË£¬²»¹ıËÆºõ²¢²»°­ÊÂ¡£" NOR;
        if( ratio > 60 ) return HIY "ÊÜÉË²»Çá£¬¿´ÆğÀ´×´¿ö²¢²»Ì«ºÃ¡£" NOR;
        if( ratio > 40 ) return YEL "ÆøÏ¢´ÖÖØ£¬¶¯×÷¿ªÊ¼É¢ÂÒ£¬¿´À´ËùÊÜµÄÉË×ÅÊµ²»Çá¡£" NOR;
        if( ratio > 30 ) return HIR "ÒÑ¾­ÉËºÛÀÛÀÛ£¬ÕıÔÚÃãÁ¦Ö§³Å×Å²»µ¹ÏÂÈ¥¡£" NOR;
        if( ratio > 20 ) return HIR "ÊÜÁËÏàµ±ÖØµÄÉË£¬Ö»ÅÂ»áÓĞÉúÃüÎ£ÏÕ¡£" NOR;
        if( ratio > 10 ) return RED "ÉËÖØÖ®ÏÂÒÑ¾­ÄÑÒÔÖ§³Å£¬ÑÛ¿´¾ÍÒªµ¹ÔÚµØÉÏ¡£" NOR;
        if( ratio > 5  ) return RED "ÊÜÉË¹ıÖØ£¬ÒÑ¾­ÑÙÑÙÒ»Ï¢£¬ÃüÔÚµ©Ï¦ÁË¡£" NOR;
        return                  RED "ÊÜÉË¹ıÖØ£¬ÒÑ¾­ÓĞÈç·çÖĞ²ĞÖò£¬ËæÊ±¶¼¿ÉÄÜ¶ÏÆø¡£" NOR;
}

string status_msg(int ratio)
{
        if( ratio==100 ) return HIW "¿´ÆğÀ´³äÂú»îÁ¦£¬Ò»µãÒ²²»ÀÛ¡£" NOR;
        if( ratio > 95 ) return HIG "ËÆºõÓĞĞ©Æ£±¹£¬µ«ÊÇÈÔÈ»Ê®·ÖÓĞ»îÁ¦¡£" NOR;
        if( ratio > 90 ) return HIG "¿´ÆğÀ´¿ÉÄÜÓĞĞ©ÀÛÁË¡£" NOR;
        if( ratio > 80 ) return GRN "¶¯×÷ËÆºõ¿ªÊ¼ÓĞµã²»Ì«Áé¹â£¬µ«ÊÇÈÔÈ»ÓĞÌõ²»ÎÉ¡£" NOR;
        if( ratio > 60 ) return HIY "Æø´­ĞêĞê£¬¿´ÆğÀ´×´¿ö²¢²»Ì«ºÃ¡£" NOR;
        if( ratio > 40 ) return YEL "ËÆºõÊ®·ÖÆ£±¹£¬¿´À´ĞèÒªºÃºÃĞİÏ¢ÁË¡£" NOR;
        if( ratio > 30 ) return HIR "ÒÑ¾­Ò»¸±Í·ÖØ½ÅÇáµÄÄ£Ñù£¬ÕıÔÚÃãÁ¦Ö§³Å×Å²»µ¹ÏÂÈ¥¡£" NOR;
        if( ratio > 20 ) return HIR "¿´ÆğÀ´ÒÑ¾­Á¦²»´ÓĞÄÁË¡£" NOR;
        if( ratio > 10 ) return RED "Ò¡Í·»ÎÄÔ¡¢ÍáÍáĞ±Ğ±µØÕ¾¶¼Õ¾²»ÎÈ£¬ÑÛ¿´¾ÍÒªµ¹ÔÚµØÉÏ¡£" NOR;
        return                  RED "ÒÑ¾­ÏİÈë°ë»èÃÔ×´Ì¬£¬ËæÊ±¶¼¿ÉÄÜË¤µ¹ÔÎÈ¥¡£" NOR;
}

varargs void report_status(object ob, int effective)
{
  if(!ob) return ;
  if(ob->query("max_kee") <1) return ;
        if( effective )
            message_vision( "( $N" + eff_status_msg(
                   (int)ob->query("eff_kee") * 100 / (int)ob->query("max_kee") )
                   + " )\n", ob);
        else
            message_vision( "( $N" + status_msg(
                   (int)ob->query("kee") * 100 / (int)ob->query("max_kee") )
                   + " )\n", ob);
}

// by ACKY
varargs void report_kee( object me )
{
	tell_object( me, sprintf( "\t[ %s¾«Á¦: %d"NOR" %sÆøÑª: %d"NOR" %sÉñî¨: %d"NOR" ]\n",
		STATUS("gin"), me->query("gin"), STATUS("kee"), me->query("kee"), STATUS("sen"), me->query("sen") ) );
}

varargs int skill_power(object ob, string skill, int usage)
{
        int level, power, app1, app2,mpower;
        if(!ob) return 0;
        if( !living(ob) ) return 0;
        level = ob->query_skill(skill);
        switch(usage) {
                case SKILL_USAGE_ATTACK:
                        app1 = ob->query_temp("apply/attack");
                        if(userp(ob)) {
                        if(app1>100) app1=100;
                        } else { if(app1>80) app1=80; }
                        level += app1;
                        break;
                case SKILL_USAGE_DEFENSE:
                        app1 = ob->query_temp("apply/defense");
                        if(userp(ob)) {
                        if(app1>100) app1=100;
                        } else { if(app1>80) app1=80; }
                        app2 = ob->query_temp("apply/armor");
                        if(userp(ob)) {
                        if(app2>100) app2=100;
                        } else { if(app2>80) app2=80; }
                        level += (app1+app2);
                        break;
                case SKILL_USAGE_OTHER:
                        app1 = ob->query_temp("apply/dodge");
                        if(userp(ob)) {
                        if(app1>100) app1=100;
                        } else { if(app1>80) app1=80; }
                        app2 = ob->query_temp("apply/parry");
                        if(userp(ob)) {
                        if(app2>100) app2=100;
                        } else { if(app2>80) app2=80; }
                        level += (app1+app2);
                        break;
        }
        if( !level ) return (int)ob->query("combat_exp")/2000;
//mpower,Õâ¸ö¾ÍÊÇtempµÄÁË,doctor and wiz×¨ÓÃ,by bss
        if(ob->query_temp("mpower")==1
          && (ob->query("class")=="doctor" || wizardp(ob))) {
          power = (level*level)*2; }
//mpower,ÊÇsetµÄà¸,²»ÊÇtempµÄ,npc and wiz×¨ÓÃ, by swy and bss
        else if(wizardp(ob) || !userp(ob)) {
            mpower=ob->query("mpower")+1; 
        if(!mpower) mpower=1;
        power = (level*level)*mpower; 
       }
          else {
            mpower=1;
          power = (level*level)*mpower;        
          }
        return power + (int)ob->query("combat_exp")/2000;
}

varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
        object *t;
        mapping my,your, action;
        string limb, *limbs, result, attack_skill,arrow_path,my_skill_message,skill_number;
        rstrone="";
        rstrtwo="";
        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();
        // ================================================================
        // (1) ÕÒ³ö´ò¼ÜÑ¶Ï¢, ¸ù¾İÎäÆ÷ÖÖÀà¶ø¶¨
        // ĞŞÕı by ChanÎªÁËÈÃÍæ¼ÒÊ¹ÓÃ³ö×Ô¼ºµÄÕĞÊ½ÔÚÕâÀïĞŞÕı!!!!Ä¿Ç°Ö»ÓĞÉè¼Æ³ö¹¥»÷µÄÕĞÊ½!!!
        // Ö÷ÒªÊÇ·Ö³É¶ş²¿·İ
        action = me->query("actions");

        if( !mapp(action) ) {
            me->reset_action();
            action = me->query("actions");
        }
        if( !mapp(action) ) {
            CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s): bad action = %O",
                        me->name(1), me->query("id"), me->query("actions", 1)));
            return 0;
        }
// ×Ô´´ÕĞÊ½²¿·Ö  by swy
     if(me->query("env/my_skill") && (sizeof(me->query("hero")) > 2) && (random(100) < 30))
     {
         choose_skill=sizeof(me->query("hero"));
        if(me->query("combat_exp") > 8000000 && random(100) < 6)
         {
          choose_skill=choose_skill-1;
          for(i=1;i<choose_skill;i++)
           {
            skill_number=sprintf("%d",i);
            my_skill_message2=me->query("hero/action"+skill_number);
            my_skill_message=my_skill_message+"\n"+my_skill_message2+"\n";
            my_skill_message=my_skill_message+HIW+"$NĞÄÉñ½øÈë½£ĞÄÍ¨Ã÷µÄ¾³½ç,Á¬Ãà²»¾ø°ãÊ¹³ö×Ô´´Ö®ÕĞÊ½"+NOR;
           }
         }
        else{
         choose_skill=choose_skill-1;
         choose_skill=random(choose_skill); //È¡ÂÒÊıµÄ·½Ê½À´ÕÒ³öÊÊºÏµÄ!!!!
         if(!choose_skill) choose_skill=1;
         skill_number=sprintf("%d",choose_skill);
         if(!me->query("hero/action"+skill_number))
           my_skill_message="$NÕĞÊ½»¹Ã»ÓĞÉè¼ÆºÃ!!ÄãÕĞÊ½ÓĞÎÊÌâÓĞÎÊÌâ!!!!\n";
         else
           my_skill_message=me->query("hero/action"+skill_number);
        }
        result = "\n" + my_skill_message + "\n";
        my_skill_power=choose_skill-1;
       }
      else {
        result = "\n" + action["action"] + "\n";
       }
// ¼ÆËã³ö¹¥·½¹¥»÷Á¦,·À·½·ÀÓùÁ¦,·À·½¶îÍâ·ÀÓùÁ¦ by swy
        if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
        else attack_skill = "unarmed";
        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);   // ¹¥·½¹¥»÷Á¦
        if( !ap ) ap = 1;
        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);   // ·À·½·ÀÓùÁ¦
        if( !dp ) dp = 1;
        op = skill_power(victim, "dodge", SKILL_USAGE_OTHER);     // ·À·½¶îÍâ·ÀÓùÁ¦
        if( !op ) op = 1;
        if( objectp(weapon) )  {
        damage = (int) me->query_temp("apply/damage");
        if( damage > 500 ) damage = 500;
        } else damage = 0;
// ÒÔ skill ×÷ÎªÖ÷ÒªµÄÉËº¦Á¦ by swy
        skill_map = me->query_skill_mapped(attack_skill);
        me->set_temp("level_1", me->query_skill(attack_skill, 1));
        me->set_temp("level_2", me->query_skill(skill_map, 1));
        me->set_temp("level_3", me->query_skill("force", 1));
// npc ÉËº¦Á¦»á±È ppl Ğ¡Ò»Ğ© by swy        
        damage += (int)(me->query_temp("level_1")*2+me->query_temp("level_3"));
                if(userp(me)) {
        if( me->query_temp("level_2") >= 1 )
        damage += me->query_temp("level_2")*3;
        else damage = damage; } else {
        if( me->query_temp("level_2") >= 1 )
        damage += me->query_temp("level_2")*2;
        else damage = damage; }
        me->delete_temp("level_1");
        me->delete_temp("level_2");
        me->delete_temp("level_3");
// ¶îÍâÉËº¦Á¦ÏÈ¼ÓÉÏ±ÛÁ¦Ó°Ïì by swy
// ¼ÓÉÏ skills Àï damage µÄÖµ
// ÎÒ°Ñ skills Àï damage Éè¶¨ÔÚ combatd.c ÀïÃæ
// Ò»·½ÃæÎÒ¿ÉÒÔ²»ÓÃ¸Ä skills µÄ damage
// ÁíÒ»·½Ãæ¿ÉÒÔ·ÀÖ¹ÓĞÈË¶¯µµ°¸ by swy
// Ã»ÓĞ class npc µÄ skills damage ÒÔ×î¸ß 700 À´¼ÆËã by swy
// Ã»ÓĞ class ppl µÄ skills damage ÒÔ×î¸ß 50 À´¼ÆËã by swy
        damage_bonus = my["str"];
        class1=my["class"];
        divv=damage_div[class1];
        if(!divv && !userp(me) && action["damage"]) {
        divv=action["damage"];
                if(!divv) divv=100;
        if(divv>700) divv=700; }
        else if(!divv && !userp(me)) {
        divv=100; } else {
        if(!divv && userp(me)) divv=50;
        }
if(find_player("swy") && find_player("swy")->query("env/divv"))
tell_object(find_player("swy"),sprintf("damage=%d\n",divv));
        damage += divv;
// µĞÈË busy Ê±·ÀÓùÁ¦½µ 20% by swy
        if( victim->is_busy() ) dp=dp*4/5;

        //¼ÓÈë²âÊÔ£¬actionÖĞÉè¶¨dodge¶ÔÓÚÃüÖĞÂÊµÄÓ°Ïì
        //dodgeµÄ·¶Î§ÊÇ-100~100£¬Éè¶¨-100µÄ»°¾ÍÊÇÕâÕĞ±ØÖĞÎŞÒÉ£¬¶ã¶¼¶ã²»µô
        //0µÄ»°¾ÍÊÇ´ËÕĞÖĞÓë²»ÖĞÍêÈ«ÓÉÖ®Ç°µÄ¹«Ê½¾ö¶¨£¬
        //ÕıÖµÔò»áÔö¼ÓµĞÈË¶à¶ãµôÕâÕĞµÄ¿ÉÄÜ
        //·½·¨ÏÈÓÃÀàËÆÉÏÃæ×Ô´´ÕĞÊ±dpµÄ¼ÆËãÀ´¾ö¶¨ by bss
        //ÒòÎªÊÇ²âÊÔ£¬ËùÒÔÖ¸¶¨¶ÔÏñ
        if(me->query("class")=="lancer" || wizardp(me))
        if(action["dodge"]){
          dodge_ratio=action["dodge"];
          if(dodge_ratio >0){
            while(dodge_ratio >100)//Éè¶¨³¬¹ı100µÄ»°¾ÍÊÇÉè¶¨´íÎó
              dodge_ratio/=100; //ËùÒÔÏÈ³ı100ÔÙËµ
            dp=dp+(dp*dodge_ratio)/100;
          }
          else{
            while(dodge_ratio < -100)//Éè¶¨³¬¹ıÁË-100¾ÍÊÇÉè¶¨´íÎó
              dodge_ratio/=100; //ËùÒÔÏÈ³ı100ÔÙËµ
            dodge_ratio=100-(100+dodge_ratio);
            dp=(dp*dodge_ratio)/100; //Ìá¸ßratioµÄ±ÈÂÊ
            if(!dp) dp=1; //Èç¹ûdodgeÉè¶¨ÊÇ-100µÄ»°£¬¸ødpÒ»¸ö»ù±¾Öµ1
          }
        }
// ÃüÖĞÂÊÓ¦¸ÃÓÉ class ÃüÖĞÂÊ + ÊµÕ½¾­ÑéÀ´ÅĞ¶¨ by swy
// Èç¹û¹¥»÷·½ÊÇ npc ÓÖÃ»ÓĞ class Éè¶¨Îª 500 by swy
// Èç¹û·ÀÓù·½ÊÇ npc ÓÖÃ»ÓĞ class Éè¶¨Îª 500 by swy
class2=my["class"];
div1=hurt_div[class2];
if(userp(me) && !div1) div1=400;
if(!userp(me) && !div1) div1=500;
c1=(int)my["combat_exp"];
c2=(int)your["combat_exp"];
if(c1-c2<0) { div2=0; }
else if(c1-c2>=4000000) { div2=400; }
else if(c1-c2>=3000000) { div2=300; }
else if(c1-c2>=2000000) { div2=200; }
else if(c1-c2>=1000000) { div2=100; }
else { div2=50; }
div1_2=div1+div2;
if(div1_2>900) div1_2=900;
// ÉäÊÖÏµÍ³ part 1 by swy
// ÉäÖĞ×óÑÛ»òÓÒÑÛÃüÖĞÂÊ¼õ°ë  Ë«ÑÛ¶¼ÉäÖØÊ§Ã÷  ÃüÖĞÂÊ = 0
// µ±È»ºÏÀí    Ò²ÊÇ doctor ²ÅÄÜÒ½ÖÎ
if(me->query_temp("over/r-eyes")==1&&me->query_temp("over/l-eyes")==1) {
div1_2=100;
tell_object(me,HIY"ÄãË«ÑÛÊ§Ã÷ºÁÎŞÖĞÃüÂÊ¿ÉÑÔ!\n"NOR);
} else if(me->query_temp("over/r-eyes")==1||me->query_temp("over/l-eyes")==1) {
div1_2 /= 2;
tell_object(me,HIG"ÄãÑÛ¾¦ÊÜÉËÃüÖĞÂÊÖè¼õÒ»°ë!\n"NOR);
}
if(find_player("swy") && find_player("swy")->query("env/divv"))
tell_object(find_player("swy"),sprintf("hurt=%d\n",div1_2));
if(find_player("cgy") && find_player("cgy")->query("env/divv"))
tell_object(find_player("cgy"),sprintf("hurt=%d\n",div1_2));
            if(div1_2<random(1000)) {
            dodge_skill = victim->query_skill_mapped("dodge");
            if( !dodge_skill ) dodge_skill = "dodge";
            if (SKILL_D(dodge_skill)->query_dodge_msg(limb))
              result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
            if( dp < ap && (!userp(victim) || !userp(me))
               && random(your["gin"]*100/your["max_gin"] + your["int"]) > 50 ) {
                    your["combat_exp"] += 1;
                    victim->improve_skill("dodge", 1);
            }
            damage = RESULT_DODGE;
        }
        else {
// ÊÇ·ñ±»ÕĞ¼Ü¿ª by swy
            if( victim->query_temp("weapon") ) {
                    pp = skill_power(victim, "parry", SKILL_USAGE_OTHER);
                    pp = pp * 1.2;
            }
            else {
                    pp = skill_power(victim, "parry", SKILL_USAGE_OTHER);
            }
            class1=your["class"];
            if(!class1) divv=10;
            else
            divv=parry_div[class1];
            if(!divv) divv=10;
if(find_player("bss") && find_player("bss")->query("env/check_combat"))
tell_object(find_player("bss"),sprintf("divv=%d\n",divv));
if(find_player("swy") && find_player("swy")->query("env/divv"))
tell_object(find_player("swy"),sprintf("parry=%d\n",divv));
if(find_player("cgy") && find_player("cgy")->query("env/divv"))
tell_object(find_player("cgy"),sprintf("parry=%d\n",divv));
            if( victim->is_busy() )
            pp=pp/divv;
            else {
            ppp = (pp*10)/divv;
            pp=(pp+ppp)/2;
            }
            if( pp < 1 || !pp ) pp = 1;
// Ôö¼Óparry message by Roger && Chan
// ËµÃ÷:Ö»ÓĞµ±ÎÒ·½ÊÖÖĞÓĞ±øÆ÷»òµĞÎÒ¶¼Ã»±øÆ÷Ê±²ÅÄÜÕĞ¼Ü
// »»¾ä»°ËµÈç¹û¶Ô·½ÓĞ±øÆ÷×Ô¼ºÃ»ÄÃ¾ÍÎŞ·¨ÕĞ¼ÜÁË
// ÓĞÎäÆ÷Ê±µÄparry_msg£¬µ«ÎäÕß²»¹ÜÊÖÖĞÓĞÎŞÎäÆ÷parry_msg ¶¼Ò»Ñù By Roger

            if( random(ap + pp) < pp ) {

                if( dp < ap && (!userp(victim) || !userp(me))
                   && random(your["gin"]*100/your["max_gin"] +
                      your["int"]) > 50 ) {
                         your["combat_exp"] += 1;
                         victim->improve_skill("parry", 1);
                }
            if( victim->query_temp("weapon") || your["class"]=="fighter" )
                {
                parry_skill = victim->query_skill_mapped("parry");
                if( !parry_skill )
                result += SKILL_D("parry")->query_parry_msg(weapon);
                else if (SKILL_D(parry_skill)->query_parry_msg(limb))
                result += SKILL_D(parry_skill)->query_parry_msg(limb);
                else result += SKILL_D("parry")->query_parry_msg(weapon);
// ·´»÷¼Ü¹¹ by swy
if((victim->query("class")=="bonze"||victim->query("class")=="bandit"||victim->query("id")=="swy")
&& victim->query_skill("counter",1)>random(200) && attack_type!=TYPE_QUICK) {
    victim->set_temp("can_contour",1); }
                } else if(!me->query_temp("weapon")&&!victim->query_temp("weapon")) {
                result += SKILL_D("parry")->query_parry_msg();
// ·´»÷¼Ü¹¹ by swy
if((victim->query("class")=="bonze"||victim->query("class")=="bandit"||victim->query("id")=="swy")
&& victim->query_skill("counter",1)>random(200) && attack_type!=TYPE_QUICK) {
    victim->set_temp("can_contour",1); }
                } else {
result += HIR+"$nÃ»ÓĞ"+HIW+"±øÆ÷"+HIR+"Ğ¶¿ªµĞÈË"+HIC+"ÎäÆ÷"+HIR+"£¬Òò´ËÖĞÕĞÊÜÉËÁË¡£\n"+NOR;
victim->set_temp("no_weapon_parry",1); }
damage = RESULT_PARRY;
            } else {
// ´òµ½µĞÈËÄÚÁ¦µÄÓ°Ïì by swy
        if( my["force_factor"]>0 && my["force"]>=my["force_factor"]) {
                    my["force"] -= my["force_factor"];
                    fap = skill_power(me, "force");
                    fdp = skill_power(victim, "force");
// ÓĞÄÚÁ¦Ó°Ïì,±»µ²¿ª
                    if( your["force_factor"] > 0 &&
                        random(fap + fdp) < fdp ) {
                            damage_bonus = 0;
                            result += "µ«ÊÇ$NÕĞÊ½Ëùº¬µÄÄÚ¾¢±»$nµÄ»¤ÉíÆø¾¢Ëù»¯½â£¬";
                            if( fdp < random(fap) && userp(me) )
                                    victim->improve_skill("force", 1);
                    }
// ÓĞÄÚÁ¦Ó°Ïì, ´òµ½ÁË
                    else {
// Ã»ÓĞ class ppl µÄ skills force ÒÔ×î¸ß 50 À´¼ÆËã by swy
// Ã»ÓĞ class npc µÄ skills force ÒÔ×î¸ß 700 À´¼ÆËã by swy
class1=my["class"];
divv=force_div[class1];
if(!divv && !userp(me) && action["force"]) {
divv=action["force"];
if(!divv) divv=100;
if(divv>700) divv=700;
} else if(!divv && !userp(me)) {
divv=100;
} else { if(!divv && userp(me)) divv=50; }
if(find_player("swy") && find_player("swy")->query("env/divv"))
tell_object(find_player("swy"),sprintf("force=%d\n",divv));
damage_bonus+=(int)(my["force_factor"]*divv*0.15);
}
}

                if( damage_bonus > 0
                   && your["force_factor"] > 0
                   && your["force"] >= your["force_factor"] ) {
                      if( living(victim) ) result += "$NµÄÄÚ¾¢»÷À£ÁË$nÉíÉÏµÄ»¤ÉíÕæÆø£¬";
                      else                 result += "$nÉíÉÏµÄÕæÆø×ÔÈ»µØÉú³öÒ»¹É¿¹¾ÜµÄÆø¾¢£¬";
                      power_dam = your["max_force"];
                      damage_bonus -= (power_dam / 10);
                      your["force"] -= your["force_factor"];
                    }

                damage_bonus -= (int)victim->query_temp("apply/armor_vs_force");
                damage_bonus -= (int)(dp/150);
                // =============================================================
                //    (6) Apply the damage bonus to the damage we'll inflict.
                //        °ÑÉËº¦Öµ¼ÓÉÏÈ¥
                //

                if( damage_bonus > 0 )
                damage += (int)damage_bonus;
                else damage = damage;

                if( attack_type == TYPE_QUICK )
                        damage += 100;

                // ÓÅ»İĞÂÍæ¼ÒÒ»Ìì

                if( userp(me) )
                    if( me->query("mud_age") < 10800 ) {
                        damage += (int) my["str"];
                        message_vision(HIY "Ö»¼û$NÉíÅÔ»·ÈÆ×ÅÒ»È¦ºì¹â, "+
                                "$NµÄÁ¦Á¿ÔöÇ¿ÁË!¡£\n" NOR, me);
                    }
                    else if( me->query("mud_age") < 11400 )
                        message_vision(HIY "$NÉíÅÔµÄºì¹â½¥½¥°µµ­ÏÂÀ´, "+
                                "Ç÷½üÓÚÆ½µ­¡£\n" NOR, me);
// °ÑÉËº¦Á¦¼ÓÉÏ¹¥»÷Á¦,ÔÚ¼õµ÷·ÀÓùÁ¦ÎªĞÂÉËº¦Á¦ by swy
damage += (ap/100);
damage -= (op/100);
if(userp(me)) {
damage=(int)damage;
} else { damage=(int)damage*0.85; }
if(damage<=0) damage=100;
if( victim->query_temp("losehurt")==1 )
{ damage=(int)(damage/2); }
                if (victim->query_temp("unsuck")==1)
                {
message_vision(HIY"\n¡®½ğÖÓÕÖ¡¯Ê®³É¹¦Á¦£¬¹ûÈ»À÷º¦£¬¾¹°Ñ$N¼ÓÖîÔÚ$nµÄ¹¥»÷È«Êı·´Õğ»ØÈ¥¡£\n"NOR,me,victim);
                    me->add("kee",-(damage));
                    me->add("eff_kee",-(damage));
                    report_status(me);
                    if(damage > 0) damage=0;
                       victim->delete_temp("unsuck");
                }
                if (victim->query_temp("goldheal")==1)
                {
message_vision(HIY"\nÖ»Ìı¼û¨Î_¨ç_¨äÒ»Éù£¬$NµÄ¹¥ÊÆ¾¡±»$nµÄ¡®½ğÖÓÕÖ¡¯»¯È¥¡£\n"NOR,me,victim);
                  if(damage > 30) damage=30;
                     victim->delete_temp("goldheal");
                }
           if (me->query_temp("powerup")==1 ) {
                    damage += 250;
                }
                    if (me->query_temp("keeup")==1 ) {
                    damage = damage*3/4;
                }
// ĞŞÕıÔö¼Ó»úÂÊ by swy
c1=(int)my["combat_exp"];
c2=(int)your["combat_exp"];
if(c1-c2<0) { div2=0; }
else if(c1-c2>=4000000) { div2=40; }
else if(c1-c2>=3000000) { div2=30; }
else if(c1-c2>=2000000) { div2=20; }
else if(c1-c2>=1000000) { div2=10; }
else { div2=5; }
div1_2=90-div2;
if(div1_2<50) div1_2=50;
if(div1_2>random(100)) {
if ( victim->query_temp("ref_shield")==1)
{
message_vision(HIC"\nĞş±ù½á½ç"HIM"½«$NµÄ¹¥»÷ÍêÈ«µÄ·´µ¯»ØÈ¥!!\n"NOR,me,victim);
                me->receive_damage("kee",(damage),victim);
                me->receive_wound("kee",(damage),victim);
                if(damage > 0) damage=0;
                report_status(me,1);
                }
}
// dancer manashield ĞğÊö
if ( victim->query_temp("mana_shield")==1)//dancer
{
message_vision(HIW"\n»ÃÃÎÖ®ÒíÒşÔ¼¶øÏÖ£¬ÈáÈôÃŞĞõ£¬ÇáÇáµØ½«$N¹¥»÷»¯¹éÓÚÎŞĞÎ!!\n"NOR,me,victim);
                if(damage > 0) damage=damage/2;
				report_status(victim,1);
                }
if ( victim->query_temp("mana_shield2")==1)//non dancer
{
message_vision(HIY"\n»ÃÃÎÖ®ÒíÒşÔ¼¶øÏÖ£¬ÈáÈôÃŞĞõ£¬ÇáÇáµØ½«$N¹¥»÷¼õÈõ²»ÉÙ!!\n"NOR,me,victim);
                if(damage > 0) damage=damage*2;
				report_status(victim,1);
                }
if ( victim->query_temp("mana_shield3")==1)//fighter,prayer
{
message_vision(HIY"\n»ÃÃÎÖ®ÒíÒşÔ¼¶øÏÖ£¬ÈáÈôÃŞĞõ£¬ÇáÇáµØ½«$N¹¥»÷¼õÈõ²»ÉÙ!!\n"NOR,me,victim);
                if(damage > 0) damage=damage*4;
                report_status(victim,1);
                }
if ( victim->query_temp("mana_shield4")==1)//mblade
{
message_vision(HIY"\n»ÃÃÎÖ®ÒíÒşÔ¼¶øÏÖ£¬ÈáÈôÃŞĞõ£¬ÇáÇáµØ½«$N¹¥»÷¼õÈõ²»ÉÙ!!\n"NOR,me,victim);
                if(damage > 0) damage=damage*8;
                report_status(victim,1);
                }

                        //power_down......by cgy....
if (me->query_temp("power-down")>=1)
{
 pod=me->query_temp("power-down");
 if (pod>16) {damage=damage/10;}
 if (pod>14&&pod<17) {damage=damage/5;}
 if (pod>12&&pod<15) {damage=damage*3/10;}
 if (pod>10&&pod<13) {damage=damage*4/10;}
 if (pod>8&&pod<11) {damage=damage*5/10;}
 if (pod>6&&pod<9) {damage=damage*6/10;}
 if (pod>4&&pod<7) {damage=damage*7/10;}
 if (pod>2&&pod<5) {damage=damage*8/10;}
 if (pod>0&&pod<3) {damage=damage*9/10;}
 }
 if (victim->query_temp("rainbow-steps")==1 && random((int)victim->query("functions/rainbow-steps/level",1))>60)
 {
  message_vision(HIY"\n$n"NOR"Ê¹³öÔÂÓ°Î¢²½ÖÕ¼«Îè²½"HIW"¡«"HIM"Æß²Ê»ÃÃÎ"NOR",ÊÖÖĞÆß²Ê¶Ğ´ø»Ã³ÉÒ»µÀ²ÊºçÉäÏò"HIB"$N£¡\n"NOR,me,victim);
  message_vision(HIY"                $n"HIR"Æä±¾ÉíÈç"HIG"ÁéÉßÆÛµĞ°ãµÄ¶ã¹ı"HIY"$N"HIR"µÄÁèÀ÷¹¥»÷¡£¡£\n"NOR,me,victim);
  if(damage > 0) damage=0;
 }
 if (victim->query_temp("snake-steps")==1 && random((int)victim->query("functions/snake-steps/level",1))>70)
 {
  message_vision(HIC"\n$n"HIR"ÉíÓ°»Ã»¯ÍòÇ§ÏòËÄ·½Á÷´Ü,ĞÎÓ°ÃÔÀëÁî"HIY"$N"HIR"µÄ¹¥ÊÆ¿ñ»÷²ĞÓ°¡££¡\n"NOR,me,victim);
  message_vision(HIG"  ½á¹û¡¸àÍ¡±µØÒ»Éù£¬Æß²Ê¹âÃ¢´Ó"HIB"$N"HIG"µÄÉíÉÏ´©Í¸¶ø³ö, Áî"HIB"$N"HIG"ÃÔÊ§¾°Ïó¡£\n"NOR,me,victim);
  message_vision(HIY"                $n"HIC"³Ã»úÉÁ¹ı"HIB"$N"HIC"Ğ×ÃÍµÄ¹¥»÷¡£\n"NOR,me,victim);
  if(damage > 0) damage=0;
 }
 if (victim->query_temp("adv-dodge")==1)
 {
  message_vision(HIY"\n$nÊ¹³ö"HIG"¡îÏÀÓ°²½¡î"HIY"ÒÔÑ¸½İÎŞ±ÈµÄËÙ¶ÈÉÁ¹ı$NµÄ¹¥»÷²¢ÔŞÉÏÒ»»÷½«$NÖØ´´¡£\n"NOR,me,victim);
  me->add("kee",-(damage));
  report_status(me);
  if(damage > 0) damage=0;
 }
       if(me->query_temp("kang-power")==1) {
message_vision(HIW"$NµÄ¡®ÁÒÑæºÆÆø¡¯¾ÛÆøÓÚÁ¦£¬Ê¹$NµÄÍşÁ¦Ôö¼Ó²»ÉÙ¡£\n"NOR,me);
 damage += 350;
}
                if (victim->query_temp("hardshell") ) {
                  if( damage > 10 ) damage = 10;
                }
                if(victim->query_temp("hwa_je")){
                  if(damage >0) damage=0;
                }
                if (me->query_temp("addpower")==1)
                {
                  damage += 1500;
                  me->delete_temp("addpower");
                }
                if (me->query("mpower")) {
                  damage += 300;
                }
// ·¢ÏÖÒ»¸ö bug ×Ô´´ÕĞÊ½¶Ô fighter Ã»ÓÃ·´¶ø¼õµÍ damage
// µ«ÊÇ¶ÔÆäËûÃÅÅÉÈ´ÓĞÌìÈÀÖ®±ğ Èç¹ûÒ»°ã class damage ÓĞ 1000
// ÄÇ 1000 * my_skill_power »áºÜ¿ÉÅÂ   ÒòÎª my_skill_power ×î¸ß¿ÉÒÔ 8
// ÄÇ 1000 * 8 = 8000 ²»¾ÍµÈÓÚ½Ğ fighter È¥ËÀÂğ
// ²»¹ıÎªÁË½±Àø¼Ó¸ö 100 ¾ÍºÃÁË     by swy
                if(me->query("env/my_skill")) {
                  damage=damage+100;
                 } else {
                 if(userp(me) && userp(victim)) { damage = damage; }
                 else { damage=(int)damage*0.85; } }
// ÉäÊÖÏµÍ³ part 2  by swy
// ÉäÖĞÓÒ»ò×óÊÖ damage ¼õ°ë  ÉäÖĞ×óÓÒÊÖ damage = 0
// ×óÓÒÊÖ¶¼ÊÜÉËµ±È»Ã»ÍşÁ¦  ºÜºÏÀí   Òª°ÑÉËÖÎÓú´òËã¸ø doctor ´Ë¹¦ÄÜ
if(me->query_temp("over/right")==1&&me->query_temp("over/left")==1) {
damage=30;
tell_object(me,HIC"ÄãË«ÊÖÊÜÉËºÁÎŞÉËº¦Á¦¿ÉÑÔ!\n"NOR);
} else if(me->query_temp("over/right")==1||me->query_temp("over/left")==1) {
damage /= 2;
tell_object(me,HIR"ÄãÊÖÊÜÉËÉËº¦Á¦Öè¼õÒ»°ë!\n"NOR);
}
if(find_player("swy") && find_player("swy")->query("env/divv"))
tell_object(find_player("swy"),sprintf("all=%d\n",damage));
if(find_player("cgy") && find_player("cgy")->query("env/divv"))
tell_object(find_player("cgy"),sprintf("all=%d\n",damage));
                victim->set_temp("no_armor_effect",1);
                result += damage_msg(damage, action["damage_type"]);
//2001.11.1 ÏÂÃæµÄ²¿·Ö É±ÊÖµÄµÚËÄ½×¶Î½ø½× »ÃÖ®ÈÌÉ±µÄ×¨Êô¼¼ÇÉ ·ÖÓ°ÊõµÄ¶¯×÷
//	    ·¢¶¯»úÂÊÊÇĞ´ÔÚdodgeÄÇ±ß£¬·¢¶¯Ö®ºó¾Í»áÓĞ%ÈÃdamage±ä0
//2002.04.04 ĞŞÕıÂß¼­ÉÏµÄ´íÎó
 if (victim->query_temp("shadowfun") > 0)
 {
      switch ( victim->query("dark-steps/shadow/lv") )
      {
      	case 0..10 : //50%
      		if (random (100) > 50)
      		{
  message_vision(HIW"\n$n °´ÕÕÎåĞĞ°ËØÔµÄ²½·¨£¬ÔÚÕû¸ö¿Õ¼äÖĞ»Ã»¯³öÎŞÏŞµÄÉíÓ°,"HIY"$N"HIW"¸ù±¾ÎŞ´Ó¹¥»÷Æğ¡££¡\n"NOR,me,victim);
      		  damage = 0;      		
      		}
      		break;
      	case 11..40 : //60%
      		if (random (100) > 40)
      		{
  message_vision(HIW"\n$n °´ÕÕÎåĞĞ°ËØÔµÄ²½·¨£¬ÔÚÕû¸ö¿Õ¼äÖĞ»Ã»¯³öÎŞÏŞµÄÉíÓ°,"HIY"$N"HIW"¸ù±¾ÎŞ´Ó¹¥»÷Æğ¡££¡\n"NOR,me,victim);
  message_vision(HIW"$N ·è¿ñµÄÍù»ÃÓ°¹¥»÷¶øÈ¥,$nË¿ºÁÓĞÊÜµ½Ò»µãÉËº¦¡£\n"NOR,me,victim);
  			me->receive_damage("gin", 150 , victim );
      			damage = 0;
      		}
      		break;
      	case 41..70 :
      		if (random (100) > 30)
      		{
  message_vision(HIW"\n$n °´ÕÕÎåĞĞ°ËØÔµÄ²½·¨£¬ÔÚÕû¸ö¿Õ¼äÖĞ»Ã»¯³öÎŞÏŞµÄÉíÓ°,"HIY"$N"HIW"¸ù±¾ÎŞ´Ó¹¥»÷Æğ¡££¡\n"NOR,me,victim);
  message_vision(HIW"$N ·è¿ñµÄÍù»ÃÓ°¹¥»÷¶øÈ¥,$nË¿ºÁÃ»ÓĞÊÜµ½Ò»µãÉËº¦¡£\n"NOR,me,victim);
  			me->receive_damage("gin", random(150)+150 , victim );
      			damage = 0;
      		}
      		break;
      	case 71..100:
      		if (random (100) > 20)
      		{
  message_vision(HIW"\n$n °´ÕÕÎåĞĞ°ËØÔµÄ²½·¨£¬ÔÚÕû¸ö¿Õ¼äÖĞ»Ã»¯³öÎŞÏŞµÄÉíÓ°,"HIY"$N"HIW"¸ù±¾ÎŞ´Ó¹¥»÷Æğ¡££¡\n"NOR,me,victim);
  message_vision(HIW"¹âÓ°²»¶ÏµÄÔÚ"HIG"$N"HIW"µÄÉí±ß»·ÈÆ, Áî"HIG"$N"HIW"¸Ğµ½ÎŞÏŞµÄ¿Ö¾å\n"NOR,me,victim);
  message_vision(HIR"$n"HIW"ËùÊ¹³öµÄ·ÖÓ°Êõ£¬ÈÃ"HIG"$N"HIW"¸ù±¾²»ÖªµÀÈçºÎ·¢¶¯¹¥ÊÆ¡£\n"NOR,me,victim);
  			me->receive_damage("gin", random(250)+150 , victim );
  			me->start_busy(1);
      			damage = 0;
      		}
      		break;
      	case 101..150: //×¨¼Ò¼¶£¬Ö»ÓĞÌØÊâ½±Àø£¬²Å¿ÉÒÔÉıµ½´Ë¼¶
      		if (random (100) > 10)
      		{
  message_vision(HIW"\n$n °´ÕÕÎåĞĞ°ËØÔµÄ²½·¨£¬ÔÚÕû¸ö¿Õ¼äÖĞ»Ã»¯³öÎŞÏŞµÄÉíÓ°,"HIY"$N"HIW"¸ù±¾ÎŞ´Ó¹¥»÷Æğ¡££¡\n"NOR,me,victim);
  message_vision(HIW"¹âÓ°²»¶ÏµÄÔÚ"HIG"$N"HIW"µÄÉí±ß»·ÈÆ, Áî"HIG"$N"HIW"¸Ğµ½ÎŞÏŞµÄ¿Ö¾å\n"NOR,me,victim);
  message_vision(HIR"$n"HIW"ËùÊ¹³öµÄ·ÖÓ°Êõ£¬ÈÃ"HIG"$N"HIW"¸ù±¾²»ÖªµÀÈçºÎ·¢¶¯¹¥ÊÆ¡£\n"NOR,me,victim);
  message_vision(HIW"$N ·è¿ñµÄÍù»ÃÓ°¹¥»÷¶øÈ¥,$nË¿ºÁÃ»ÓĞÊÜµ½Ò»µãÉËº¦¡£\n"NOR,me,victim);
  			me->receive_damage("gin", random(400)+150 , victim );
  			me->start_busy(1);
      			damage = 0;
      		}
      		break;
      	default: //Î×Ê¦²ÅÓĞ¿ÉÄÜÕâÒ»¼¶
      		me->receive_damage("gin", random(1999)+600 , victim );
  		me->start_busy(2);
      		damage =0;
      }
      //²»¹ÜÓĞÃ»ÓĞ·¢¶¯³É¹¦£¬¶¼Òª¿Ûµô
      victim->add_temp("shadowfun",-1);
 }


// ÎÒ¾õµÃÕÕ class ÌØÉ« swordsman and blademan ¿ÉÒÔÉË×î´óÖµ
// ËùÒÔÎÒµ÷Õû swordsman and blademan ËØÕĞ¾ÍÄÜÉËº¦×î´óÖµ by swy
if(me->query("class")=="swordsman" || me->query("class")=="blademan") {
                damage = victim->receive_wound("kee",damage,me); } else {
                damage = victim->receive_damage("kee", damage, me ); }

                if( weapon ) weapon->hit_ob(victim, damage);
                else me->hit_ob(victim, damage);

                // Gain combat_exp.

                if( ap < dp && (!userp(me) || !userp(victim))
                   && random(my["gin"]*100/my["max_gin"] + my["int"]) > 30 ) {
                      my["combat_exp"] += 1;
                      my["potential"] += 1;
                      me->improve_skill(attack_skill, 1);
                }

                if( (!userp(me) || !userp(victim))
                   && random(your["max_kee"] + your["kee"]) < damage ) {
                      your["combat_exp"] += 1;
                      your["potential"] += 1;
                }
                }
                }
        result = replace_string( result, "$l", limb );

        if( objectp(weapon) ) {
                result = replace_string( result, "$w", weapon->name() );
                if( weapon->query("can_hold") )
                        arrow_path = weapon->query("arrow/path");
                if( stringp(arrow_path) )
                        result= replace_string( result, "$c",arrow_path->name() );
        }
        else if( stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );




        bssone=sizeof(result);
        if(bssone >=8192)
        {
                rstrtwo=result[8000..(bssone-1)];
                rstrone=result[0..7999];
                message_vision(rstrone,me,victim);
                message_vision(rstrtwo,me,victim);
        }

        else {
        message_vision(result, me, victim );
        }
        if( damage > 0 ) report_status(victim);
        if( damage > 0 ) report_kee(victim);
// ÎäÕß×Ô¶¯³å·âÑ¨ÏµÍ³ by swy Çë wiz ±ğ°ÑÌõ¼şËµ³öÈ¥ thx
if(!userp(me)) cmexp=(int)me->query("combat_exp")/2;
else cmexp=(int)me->query("combat_exp")*4/5;
// 1.ÏÈ¼ì²éÊÇ·ñÎª ppl
if(userp(victim)
// 2.ÔÙ¼ì²é exp
&& random(cmexp)<random(victim->query("combat_exp"))
// 3.¼ì²éÊÇ·ñ busy
&& victim->is_busy()
// 4.ÔÙ¼ì²éÄÚ¹¦µÈ¼¶¸ßµÍ
&& me->query_skill("force")<victim->query_skill("force")
// 5.ÔÙ¼ì²éÒª³åÑ¨ËùĞèµÄÕæÆøÖµ(ÒòÎªÕæÆø¿É bet ËùÒÔÉè¸ßÒ»µã)
&& victim->query("force")>5000
// 6.ÔÙ¼ì²é»úÂÊ
&& random(100)>50
// 7.¼ì²é»á³åÑ¨µÄ exp ÏŞÖÆ
&& victim->query("combat_exp")>3000000
// 8.¶à¼ÓÒ»¸öÏëÓÃÔÙÓÃµÄÌõ¼ş
&& victim->query("env/³åÑ¨")=="YES"
// 9.×îºó¼ì²éÒª fighter
&& victim->query("class")=="fighter") {
message_vision(HIW"\nÖ»¼û$N±©ÆğËùÓĞ"HIY"ÕæÆøÄÚ¾¢"HIW"£¬$NÈ«ÉíÂ¤ÕÖÔÚÒ»¹É"HIC"ÕÀÀ¶Æø¾¢"HIW"ÖĞ£¬ºÕÈ»ÒÑ½â¿ªÉíÉÏ±»·âµÄÑ¨µÀ¡£\n"NOR,victim);
message_vision(HIW"$N¾ªãµÖ®Ê±£¬$n¾Û¼¯ËùÓĞ"HIY"ÕæÆøÄÚ¾¢"HIW"£¬°Ñ$NÂ¤ÕÖÔÚÒ»¹É"HIC"ÕÀÀ¶Æø¾¢"HIW"ÖĞ£¬$NÊÜµ½Ç¿´óÆø¾¢Ñ¹ÆÈĞĞ¶¯ÊÜ×è¡£\n"NOR,me,victim);
victim->delete_busy();
me->start_busy(1);
if(victim->query("force")>5000) { victim->add("force",-5000); }
else { victim->set("force",0); }
}
if(victim->query_temp("no_weapon_parry")==1&&victim->query("kee")>0) {
victim->receive_damage("kee",250,me);
victim->delete_temp("no_weapon_parry"); }
if( victim->query_temp("can_contour")==1 ) {
message_vision(HIW"\n$NÊ¹³ö"HIR"°ÔÍõĞ¶¼×"HIW"½åÓÉÕĞ¼Ü$n¹¥»÷Ö®Ê±£¬È«Éñ¹á×¢³Ã»ú·¢¶¯·´»÷£¡\n"NOR,victim,me);
do_attack(victim, me, victim->query_temp("weapon"));
victim->delete_temp("can_contour");
}
      if(!me->query("env/my_skill")) {    //ĞŞÕıÊ¹ÓÃ×Ô¼ºµÄÕĞÊ½Ê±..²»³öÏÖÔ­ÓĞÕĞÊ½µÄÌØ¹¦!!!!
   if(me->query("force") > 1) {
        if( functionp(action["post_action"]) )
               evaluate( action["post_action"], me, victim, weapon, damage);

        action = me->query("force_actions");

        if( mapp(action) )
            if( functionp(action["post_action"]) )
                   evaluate( action["post_action"], me, victim, weapon, damage);
} else tell_object(me,"[1;36mÄãµÄÄÚÁ¦²»×ãÒÔÇı¶¯ÎäÑ§¸½¼Ó¹¥»÷![0m");
     }//ÒÔÉÏ
        action = me->query("weapon_actions");  //ÎäÆ÷µÄ²¿·İ!!!!

        if( mapp(action) )
            if( functionp(action["post_action"]) )
                   evaluate( action["post_action"], me, victim, weapon, damage);


        // Add By Oda 96/7/11
        // Èç¹ûÍæ¼Ò×é team ´ò mob µÄÊ±ºò, ÈË¼Ê¹ØÏµ»áÔö¼Ó
        if( pointerp(t=me->query_team()) ) {
                if( me->is_team_leader() ) {
                        for( i=1; i<sizeof(t); i++ )
                             if(t[i])
                                me->add("ÈË¼Ê¹ØÏµ/"+t[i]->query("id"),1);
                } else
                         if(t[0])
                        me->add("ÈË¼Ê¹ØÏµ/"+t[0]->query("id"),1);
        }

        // See if the victim can make a riposte.

        if( attack_type==TYPE_REGULAR
           && damage < 1
           && victim->query_temp("guarding") ) {
                 victim->set_temp("guarding", 0);
                 if( random(my["cps"]) < 10 ) {
                     message_vision("$NÒ»»÷²»ÖĞ£¬Â¶³öÁËÆÆÕÀ£¡\n", me);
                     do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
                  }
                  else {
                     message_vision("$N¼û$n¹¥»÷Ê§Îó£¬³Ã»ú·¢¶¯¹¥»÷£¡\n", victim, me);
                     do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
                  }
        }
}

//      fight()
//
//      This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
        object ob;
        int i;
        if( !living(me) ) return;
        if (!me->visible(victim)
        && (random(100 + (int)me->query_skill("perception")) < 100) )
                return;
        // If victim is busy or unconcious, always take the chance to
        //   make an attack.
        if( victim->is_busy() || !living(victim) ) {
            me->set_temp("guarding", 0);
            do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        } else if(me->query("class")=="swordsman"&&victim->query("class")!="swordsman"
                  && !me->query_temp("delay_fight"))
        {
          me->set_temp("guarding", 0);
          me->set_temp("delay_fight",1);
          do_attack(me, victim, me->query_temp("weapon"));
        } else if(me->query("class")!="swordsman"&&victim->query("class")=="swordsman"
                  && !victim->query_temp("delay_fight"))
        {
          me->set_temp("guarding", 0);
          victim->set_temp("delay_fight",1);
          do_attack(victim, me, victim->query_temp("weapon"));
        } else if( random( (int)victim->query("cps") * 3 ) <
          ((int)me->query("cor") + (int)me->query("bellicosity") / 50) )
        {
                me->set_temp("guarding", 0);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
        // Else, we just start guarding.
        } else if( me->query_temp("guarding")==0 ) {
                me->set_temp("guarding", 1);
                message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
                return;
        } else return;

        // Make sure the victim had noticed the attack.
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
}

//      auto_fight()
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
void auto_fight( object me, object obj, string type )
{
        // Don't let NPC autofight NPC.
        if( !userp(me) && !userp(obj) ) return;

        // Because most of the cases that we cannot start a fight cannot be checked
        // before we really call the kill_ob(), so we just make sure we have no
        // aggressive callout wating here.
        if( me->query_temp("looking_for_trouble") ) return;
        me->set_temp("looking_for_trouble", 1);

        // This call_out gives victim a chance to slip trough the fierce guys.

if( me->query("id") == "konni" )
tell_object(find_player("konni"), me->query("id") +" "+ type+"\n");
        call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
        int bellicosity;

        if( !me ) return;                               // Are we still exist( not becoming a corpse )?

        me->delete_temp("looking_for_trouble");
        if( !obj ) return;

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
)       return;

        bellicosity = (int)me->query("bellicosity");
        if(!wizardp(me)) {
                message_vision("$NÓÃÒ»ÖÖÒìÑùµÄÑÛÉñÉ¨ÊÓ×ÅÔÚ³¡µÄÃ¿Ò»¸öÈË¡£\n", me);
        }

        if( (int)me->query("force") > (random(bellicosity) + bellicosity)/2 )
                return;

        // ĞŞ¸ÄÒ»ÏÂÎª²»»á¿³Âí  µ«ÆäËûµÄmobÕÕ¿³  By Swy
        if( bellicosity > (int)obj->query("score") && !wizardp(obj) && living(obj) ) {
                message_vision( "$N¶Ô×Å$nºÈµÀ£º" + RANK_D->query_self_rude(me)
                        + "¿´ÄãÊµÔÚºÜ²»Ë³ÑÛ£¬È¥ËÀ°É¡£\n", me, obj);
                me->kill_ob(obj);
        }
        else {
                message_vision( "$nµÄÕıÒåÖ®ÆøÉ¢·¢È«Éí, Ê¹$N²»¸ÒÇÖ·¸ÉËº¦$n¡£\n", me, obj );
        }
}

void start_hatred(object me, object obj)
{
        if( !me ) return;                               // Are we still exist( not becoming a corpse )?

        me->delete_temp("looking_for_trouble");
        if( !obj ) return;

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        // We found our hatred! Charge!
        message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
        me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
        if( !me ) return;                               // Are we still exist( not becoming a corpse )?

        me->delete_temp("looking_for_trouble");
        if( !obj ) return;

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        // We found our vendetta opponent! Charge!
        me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
        if( !me ) return;                               // Are we still exist( not becoming a corpse )?

        me->delete_temp("looking_for_trouble");
        if( !obj ) return;

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        // We got a nice victim! Kill him/her/it!!!
        me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
  // ¿ÉÒÔÔÚ npc ÉíÉÏÉè set_temp("die","xxxxxxx");
  // »ò set_temp("die",(: die_msg :) );
  // ÕâÑùÔÚ npc ËÀºó»áÏÔÊ¾¸ÃÑ¶Ï¢¡£
  // ²»¹ı£¬Ò² ¿ÉÒÔÍ¸¹ıÎï¼şµÄ void init() À´Éè¶¨¡£
  // added by wade 87/9/9
  mixed die_msg;

	switch(event) {
	case "dead" :
		if( !undefinedp( die_msg = ob->query_temp("die") ) ) {
			if( stringp(die_msg) )
				message( "sound", die_msg, environment (ob) );
			else if( functionp(die_msg) )
				evaluate(die_msg);
		}
		else
  // µ½ÕâĞĞÇ°¶¼ÊÇÔö¼Ó½øÀ´µÄ
			message_vision("\n$NËÀÁË¡£\n\n", ob);
      break;
    case "unconcious":
      message_vision("$N½ÅÏÂÒ»¸ö²»ÎÈ£¬µøÔÚµØÉÏÒ»¶¯Ò²²»¶¯ÁË¡£\n\n", ob);
      break;
    case "revive":
      message_vision("\n$NÂıÂıÕö¿ªÑÛ¾¦£¬ÇåĞÑÁË¹ıÀ´¡£\n\n", ob);
      break;
  }
}

void killing (object who)
{
  object        where, cop_head;

  where = environment (who);

  if (!cop_head=find_living("cop head"))
    if (cop_head = new(COP_HEAD))
      cop_head->move(where);
  else
    if (!cop_head->is_fighting()) cop_head->move(where);
}

void winner_reward(object killer, object victim)
{
        killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
//PKµÄ²¿·İÖØĞÂ¸ÄĞ´ by Chan 9/18/98
        int bls,pktime,pkmoney;
        string vmark,pktitle,death_str;

        // Call the mudlib killer apply.
        if (victim)
          killer->killed_enemy(victim);
        else
          killer->killed_enemy(killer);

        if( userp(victim) ) { //ËÀµÄÈËÊÇplayerµÄ»°.....ÒÔÏÂ×ö
         if(userp(killer)) //killerÊÇÍæ¼Ò²ÅÖ´ĞĞÏÂÃæµÄ
          {
           if((!victim->query("pker"))&&(!victim->query("ckill")))
           { //É±ËÀµÄÈËÊÇpker»òckillµÄ»°¾Í²»Ëãpk
             if(killer->query("id")!=victim->query("id"))
             {//×Ô¼ºÉ±ËÀ×Ô¼º²»Ëãpk
               // pkÉè¶¨µÄ²¿·İ by Chan
               pktime = 1800; //Éè¶¨ÈıÊ®·ÖÖÓ²»ÄÜÀëÏß by chan
               pktime += time();//Ëã³öÏµÍ³Ê±¼ä+ÈıÊ®·ÖÖÓ by chan
               killer->set("PKTIME",pktime);  //°ÑÊ±¼äÉèÎªÓÀ¾Ã´¢´æµÄby bss
               if(!killer->query("pker"))
               { //Èç´ËÉè·¨ÊÇÅÂµÚ¶ş´Îpk..°ÑºÃµÄtitle¸ø¸ÇÁË by chan 11/24
                 pktitle=killer->query("title");
                 killer->set("PKNAME",pktitle);
               }
                killer->set("title",HIR"É±ÈËĞ×ÊÖ"NOR);
                tell_room(killer,HIR"ÄãÉ±ÁËÏßÉÏÍæ¼Ò,³ÉÁËÉ±ÈËĞ×ÊÖÁË¡£\n"NOR);
                killer->set("pker",1);
             }
             killer->add("PKS", 1);
             // by ACKY
             if( victim->query("combat_exp")>=3000000 )
             killer->add("HKS", 1);
           }
           else{
            pkmoney=victim->query("combat_exp");//¸ù¾İpkerµÄexp¸øÓèkill
            pkmoney=pkmoney*10;//Èç¹ûÊÇexpÒ»°ÙÍò¾ÍÊÇ1000 gold
            killer->add("coin",pkmoney);//pkerµÄÈËÇ®
            tell_room(killer,HIW"ÄãÎªÃñ³ıº¦,É±ÁËÉ±ÈËĞ×ÊÖ,µÃµ½ÁËÒ»±Ê³ê½ğ¡£\n"NOR);
            }//pkerËÀºó¾Í²»Ëãpker¼°½â³ı×·¼©×´Ì¬
          }
                // modify by oda, pk Íæ¼Ò²»¼ÓÉ±Æø
                // bls = 10;
                bls = 0;

	switch( random(5) ) { // by ACKY
	case 1:
		CHANNEL_D->do_channel( killer, "dead",
			sprintf( "¿ñĞ¦Ëµ:¡¸¿ÉÁ¯µÄ%s, »Ø¼ÒÏòÄãµÄÄ¸Ç×¿ŞËß°É¡£¡±", victim->name(1) ) );
		break;
	case 2:
		CHANNEL_D->do_channel( killer, "dead",
			sprintf( "³ÜĞ¦×Å:¡¸ÎŞÄÜµÄ%s, Äã»¹ÓĞµ¨À´Ò»´ÎÂğ?¡±", victim->name(1) ) );
		break;
	case 3:
		CHANNEL_D->do_channel( killer, "dead",
			sprintf( "¸ßº°×Å:¡¸ÍÛ¹ş¹ş, ÓĞË­Ô¸Òâ°ï%sÊÕÊ¬°¡!¡±", victim->name(1) ) );
		break;
	case 4:
		CHANNEL_D->do_channel( killer, "dead",
			sprintf( "´óĞ¦×Å:¡¸Ììµ×ÏÂ¾ÓÈ»»¹ÓĞÏñ%sÕâÃ´×Ô²»Á¿Á¦µÄÈË!¡±", victim->name(1) ) );
		break;
	case 5:
		CHANNEL_D->do_channel( killer, "dead",
			sprintf( "¿ñĞ¦Ëµ:¡¸¿´×Å%sÏÊÑªÂÒÅç, ÕæÊÇÒ»ÖÖÎŞÉÏµÄÏíÊÜ!¡±", victim->name(1) ) );
		break;
	case 6:
		CHANNEL_D->do_channel( killer, "dead",
			sprintf( "´óº°×Å:¡¸%s, ÎÒ»¹¿ÉÒÔÔÙÉ±ÄãÒ»´Î, Ö»ÒªÄã¸ÒÀ´µÄ»°!¡±", victim->name(1) ) );
		break;
	default:
		CHANNEL_D->do_channel( killer, "dead",
			sprintf( "¿ñĞ¦×Å:¡¸ÍÛ¹ş¹ş, ÎÒËæËæ±ã±ã¾Í°Ñ%sÉ±µôÁË£¡¡±", victim->name(1) ) );
	}

	death_str="";
    death_str=victim->query("id")+victim->name(1)+"±»"+killer->query("id")+killer->name(1)+"ËùÉ±ÔÚ"+ctime(time())+sprintf("ÓĞ%d¸öÌæÉí!!\n",victim->query("standby"));
                 write_file("/open/death/death_record",death_str);
        }
        else {
                killer->add( "MKS", 1 );
                if( victim->query("combat_exp")>=10000000 )
                        killer->add( "HKS", 1 );
                bls = 1;
        }

        killer->add("bellicosity", bls );

        if( stringp(vmark = victim->query("vendetta_mark")) )
                killer->add("vendetta/" + vmark, 1);
}

//ÒòÎªÓĞÆğËÀ»ØÉúÖ®ÊõÁË£¬ËùÒÔÈËËÀ¿ÛÖµ±ØĞèÊÇÔÚºÚ°×ÎŞ³£ËÍÈË»ØÈË¼äÊ±¿Û
//ÎÒ°Ñ¿ÛÖµµÄ²¿·İĞ´ÔÚÕâ by bss
int death_effect(object victim)
{
    string pktitle;
   if(!victim) return 0;
    if(victim->query("pker")) //ËÀµÄÈËÊÇÉ±ÈË·¸£¬pkerµÄexp¿Û¶ş´Î....
    {
      pktitle=victim->query("PKNAME"); //°Ñtitle¸øËÍ»ØÀ´...
      victim->set("title",pktitle);
      victim->skill_death_penalty();
      victim->add("combat_exp", -(int)victim->query("combat_exp") / 10);
    }
    victim->set("pker",0);
    victim->delete("ckill");
    victim->delete("ckill_id"); //È¡ÏûckillËùÉèµÄ....by chan
    victim->set("PKTIME",0);
    //killer²»ÊÇcharµÄ²¿·İ×öÒÔÉÏµÄÊÂÇé...
    //ËÀµÄÈËÊÇplayerÒ²ÊÇÉÏÃæÔÚ´¦Àí.....
    victim->clear_condition();
    victim->set_temp("snow-powerup",0);
    // Give the death penalty to the dying user.
    victim->set("bellicosity", 0);
    victim->add("combat_exp", -(int)victim->query("combat_exp") / 10);
    victim->delete("vendetta");
    if( (int)victim->query("potential") > (int)victim->query("learned_points"))
             victim->add("potential",
                    ((int)victim->query("learned_points") - (int)victim->query("potential"))/10 );
    victim->skill_death_penalty();
    return 1;
}



//
// ÓÃÀ´Ğ´auto_size µÄmob Ö®ÓÃ
// modified by konn
//
int auto_size(object mob, object mob_2)
{
        object weapon = mob_2->query_temp("weapon");
        string skill, m_skill;
        int exp, gin, kee, sen, force, mana, atman, f_fac, m_fac, a_fac;
        int lv_1, lv_2, apply;

/*
        if( weapon ) skill = weapon->query("skill_type");
        else skill = "unarmed";

        lv_1 = mob_2->query_skill(skill, 1);
        m_skill = mob_2->query_skill_mapped(skill);
        if( m_skill )
            lv_2 = mob_2->query_skill(m_skill, 1);

        lv_1 = (int) lv_1;
        lv_2 = (int) lv_2;
        mob->set_skill("unarmed", lv_1);
        mob->set_skill("hell-evil", lv_2);

        lv_1 = mob_2->query("dodge", 1);
        lv_1 = (int) lv_1;
        mob->set_skill("dodge", lv_1);

        lv_1 = mob_2->query("parry", 1);
        lv_1 = (int) lv_1;
        mob->set_skill("parry", lv_1);

        apply = mob_2->query_temp("apply/damage");
        mob->set_temp("apply/damage", apply);
        apply = mob_2->query_temp("apply/armor");
        mob->set_temp("apply/armor", apply);

        exp = (int) 1.5 * mob_2->query("combat_exp");
        gin = 2 * mob_2->query("max_gin");
        kee = 2 * mob_2->query("max_kee");
        sen = 2 * mob_2->query("max_sen");
        force = 2 * mob_2->query("max_force");
        mana = 2 * mob_2->query("max_mana");
        atman = 2 * mob_2->query("max_atman");
        f_fac = (int) mob_2->query("force_factor");
        m_fac = (int) mob_2->query("mana_factor");
        a_fac = (int) mob_2->query("atman_factor");

        mob->set("combat_exp", exp);
        mob->set("gin", gin);
        mob->set("max_gin", gin);
        mob->set("kee", kee);
        mob->set("max_kee", kee);
        mob->set("sen", sen);
        mob->set("max_sen", sen);
        mob->set("force", force);
        mob->set("max_force", force);
        mob->set("mana", mana);
        mob->set("max_mana", mana);
        mob->set("atman", atman);
        mob->set("max_atman", atman);
        mob->set("force_factor", f_fac);
        mob->set("mana_factor", m_fac);
        mob->set("atman_factor", a_fac);

        mob->delete("auto_size");

        if( mob_2->is_character()     &&
            !wizardp(mob_2)           &&
            !mob_2->query("evil_mob")    ) {
            mob->kill_ob(mob_2);
            mob_2->kill_ob(mob);
        }

        mob->setup();
*/
        return 1;
}
