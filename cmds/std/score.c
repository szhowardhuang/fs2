// score.c
// Modify By Spirits.
// Modified by wade 1/10/1996
// Modified by Anmy 98/4/2
// Modified by Chan 98/8/17
inherit F_CLEAN_UP;

#include <ansi.h>
#include <combat.h>

string state( int value, int max );
string status_color( int value, int max );
string status_string( int status );

void create() { seteuid(ROOT_UID); }

void wiz_score(object ob)
{
  mapping my;
  string skill_type, couples,attack_skill,skill_map;
  object weapon;
  int attack_points, dodge_points, parry_points,damage,damage_bonus,power_dam,damage_1,damage1,damage2,damage_2;
  my = ob->query_entire_dbase();
  if( objectp(weapon = ob->query_temp("weapon")) )
  if(present(weapon, ob))
  skill_type = weapon->query("skill_type");
  else {
  weapon = 0;
  ob->delete_temp("weapon");
  skill_type = "unarmed";
  } else skill_type = "unarmed";
  attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
  parry_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_OTHER);
  dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
// ÉËº¦Á¦²¿·Ö by swy
if( objectp(weapon) )  {
attack_skill = weapon->query("skill_type");
damage = (int) ob->query_temp("apply/damage");
if( damage > 500 ) damage = 500;
} else damage = 0;
skill_map = ob->query_skill_mapped(attack_skill);
if(userp(ob)) {
damage += (int)ob->query_skill(attack_skill, 1)*2+(int)ob->query_skill("force", 1);
if( ob->query_skill(skill_map, 1) != 0 )
damage += ob->query_skill(skill_map, 1)*3;
else damage = damage; } else {
damage += (int)ob->query_skill(attack_skill, 1)*2+(int)ob->query_skill("force", 1);
if( ob->query_skill(skill_map, 1) != 0 )
damage += ob->query_skill(skill_map, 1)*2;
else damage = damage; }
// ¼ÓÉÏ skills ÀïµÄ damage by swy
if( my["class"]=="fighter" ) {
damage += 500; }
else if(my["class"]=="swordsman"||my["class"]=="blademan"||my["class"]=="bandit") {
damage += 400; }
else if(my["class"]=="scholar"||my["class"]=="prayer"||my["class"]=="bonze"||
        my["class"]=="beggar"||my["class"]=="officer"||my["class"]=="marksman") {
damage += 300; }
else if(my["class"]=="killer"||my["class"]=="poisoner"||my["class"]=="doctor"||
        my["class"]=="taoist") {
damage += 100; }
else if(my["class"]=="dancer") {
damage += 200; } else {
damage += 50; }
// ¶îÍâÉËº¦Á¦ by swy
damage_bonus = my["str"];
if( my["class"]=="fighter" ) {
damage2 = 500; }
else if(my["class"]=="swordsman"||my["class"]=="blademan"||my["class"]=="bandit") {
damage2 = 400; }
else if(my["class"]=="scholar"||my["class"]=="prayer"||my["class"]=="bonze"||
        my["class"]=="beggar"||my["class"]=="officer"||my["class"]=="marksman") {
damage2 = 300; }
else if(my["class"]=="killer"||my["class"]=="poisoner"||my["class"]=="doctor"||
        my["class"]=="taoist") {
damage2 = 100; }
else if(my["class"]=="dancer") {
damage2 = 200; } else {
damage2 = 50; }
damage_bonus+=(int)(my["force_factor"]*damage2*0.2);
// µĞÈË´òÄã¿ÉÒÔµÖÏúµÄÖµ by swy
power_dam = my["max_force"];
damage_1 = (int)(power_dam / 10);
// ×ÜÉËº¦Á¦ by swy
damage1 = damage+damage_bonus+(attack_points/100);
// ×ÜµÖÏúÖµ by swy
damage_2 = damage_1+(dodge_points/100)+(parry_points/100);

 printf(BOLD "%s" NOR "%s\n" +
         "¡õ ÉúÈÕ£º%s\n¡õ ÄêÁä£º%sËê\tĞÔ±ğ£º%s\n",
      RANK_D->query_rank(ob),
      ob->short(),
      CHINESE_D->chinese_date((my["birthday"] - 14*365*24*60) * 60),
      chinese_number(my["age"]),
      my["gender"]
    );
	if (couples = my["couples/name"])
		printf ("\tÅäÅ¼ÊÇ: %O¡£\n", couples);

	printf( "¡õ ×Ü¹²É±ÁË "HIY"%d"NOR" ¸öÈË, "HIR"%d"NOR" Î»Íæ¼Ò, ÆäÖĞÓĞ "HIM"%d"NOR" Î»¸ßÊÖ¡£\n",
	my["MKS"] + my["PKS"], my["PKS"], my["HKS"] );
	printf("¡õ Õ½¹¦: "HIY"%6d"NOR"\n",my["war_score"]);
  printf("¡õ ×´¿ö£º%s[0m\n",status_string(my["status"]));

  if( mapp(my["family"]) ) {
    if( my["family"]["master_name"] )
        printf("¡õ Ê¦¸¸£º "HIW"%s"NOR"¡£\n",
                my["family"]["master_name"]
      );
  }
  if(my["clan"])
  {
printf("¡õ ËùÊô°ïÅÉ£º"+HIY+"%s\n"NOR,my["clan"]["name"]);
    if(my["clan"]["title"])
      printf("¡õ °ïÖĞÖ°Î»£º"+HIC+"%s\n\n"NOR,my["clan"]["title"]);
  }
  if(my["max_s_kee"])
    printf("¡õ ÁéÆø£º¡¾ %s ¡¿£º"+ HIG+"%d/%d\n" NOR,
        to_chinese(my["sec_kee"]),
        my["s_kee"], my["max_s_kee"]);

  if(my["class"] && my["class"]=="officer")
  {
    printf("¡õ ¹ÙÎ»£º¡¾"HIW"%s"NOR"¡¿\tÈ¨Á¦£º"HIY"%d/%d\n"NOR
                  "\tÕşÖÎ¾­Ñé£º"HIC"%d\n"NOR,
        my["officer_class"],
        my["officer_power"],
        my["max_officer_power"],
        my["office_exp"]
    );
  }

	printf(
		"¡õ ëöÁ¦[str]: %2d   µ¨Ê¶[cor]: %2d   ÎòĞÔ[int]: %2d   ÁéĞÔ[spi]: %2d\n"+
	      	"¡õ ¶¨Á¦[cps]: %2d   ÈİÃ²[per]: %2d   ¸ù¹Ç[con]: %2d   ¸£Ôµ[kar]: %2d\n\n",
      			my["str"], my["cor"], my["int"], my["spi"],
      			my["cps"], my["per"], my["con"], my["kar"]
    	);
	printf("¡õ ¾«£º%s%4d/%d\t%s(%d%%)"NOR
                 "\tÁéÁ¦£º%s%4d/%d\t(+%d)"NOR
               "\t\tÊ³Îï£º%s%4d/%d\n"NOR,
    status_color(my["gin"], my["eff_gin"]), my["gin"], my["eff_gin"],
    status_color(my["eff_gin"], my["max_gin"]),
    my["eff_gin"] * 100 / my["max_gin"],
    status_color(my["atman"], my["max_atman"]), my["atman"], my["max_atman"],
    my["atman_factor"],
    status_color(my["food"], ob->max_food_capacity()),
    my["food"],
    ob->max_food_capacity()
  );

  printf("¡õ Æø£º%s%4d/%d\t%s(%d%%)" NOR
                 "\tÄÚÁ¦£º%s%4d/%d\t(+%d)" NOR
               "\t\tÒûË®£º%s%4d/%d\n"NOR,
    status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
    status_color(my["eff_kee"], my["max_kee"]),
    my["eff_kee"] * 100 / my["max_kee"],
    status_color(my["force"], my["max_force"]), my["force"], my["max_force"],
    my["force_factor"],
    status_color(my["water"], ob->max_water_capacity()),
    my["water"],
    ob->max_water_capacity()
  );
  printf("¡õ Éñ£º%s%4d/%d\t%s(%d%%)"NOR
                 "\t·¨Á¦£º%s%4d/%d\t(+%d)\n\n" NOR,
    status_color(my["sen"], my["eff_sen"]),  my["sen"], my["eff_sen"],
    status_color(my["eff_sen"], my["max_sen"]),
    my["eff_sen"] * 100 / my["max_sen"],
    status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
    my["mana_factor"] );

  printf("¡õ Õ½¶·¹¥»÷Á¦£º"HIW"%O(+%O)"NOR
                   "\tÕ½¶··ÀÓùÁ¦£º"HIW"%O(+%O)\n" NOR,
 attack_points+1,
    (int)ob->query_temp("apply/damage"),
 (dodge_points + (weapon? parry_points: (parry_points/10)))+1,
    (int)ob->query_temp("apply/armor")
  );
printf("¡õ ÎäÑ§ÉËº¦Á¦£º"HIW"%d"NOR"\t¶îÍâÉËº¦Á¦£º"HIW"%d"NOR"\t×ÜºÏÉËº¦Á¦£º"HIW"%d\n"NOR,
damage,damage_bonus,damage1);
printf("¡õ ÄÚÁ¦µÖÏúÖµ£º"HIW"%d"NOR"\t×ÜµÖÏúÖµ£º"HIW"%d\n"NOR,
damage_1,damage_2);
  printf("¡õ É±      Æø£º"RED"%O"NOR
                   "\tÇ±      ÄÜ£º"HIY"%O(%O%%)" NOR
                     "\tÊµÕ½¾­Ñé£º"HIM"%O\n" NOR,
                my["bellicosity"],
                my["potential"] - my["learned_points"],
                (int)(1 + my["learned_points"]) * 100 /
                 (1 + my["potential"]),
                my["combat_exp"]);
}

void player_score(object ob)
{
	mapping my;
	string skill_type, couples;
	object weapon;
	int attack_points, dodge_points, parry_points;

	my = ob->query_entire_dbase();

	printf(BOLD "%s" NOR "%s\n" +
	"¡õ ÉúÈÕ£º%s\n¡õ ÄêÁä£º%sËê\tĞÔ±ğ£º%s",
	RANK_D->query_rank(ob),
	ob->short(),
	CHINESE_D->chinese_date((my["birthday"] - 14*365*24*60) * 60),
	chinese_number(my["age"]),
	my["gender"]
	);
	if (couples = my["couples/name"])
		printf ("\tÅäÅ¼ÊÇ: %O¡£\n", couples);
	else
		printf ("¡£\n");

	printf( "¡õ ×Ü¹²É±ÁË "HIC"%d"NOR" ¸öÈË, "HIR"%d"NOR" Î»Íæ¼Ò, ÆäÖĞÓĞ "HIM"%d"NOR" Î»¸ßÊÖ¡£\n",
	my["MKS"] + my["PKS"], my["PKS"], my["HKS"] );
	if( my["war_score"] )
		printf( "¡õ Õ½¹¦: "HIY"%d"NOR" µã\n", my["war_score"] );
	printf("¡õ ×´¿ö£º%s[0m\n",status_string(my["status"]));

  if( mapp(my["family"]) ) {
    if( my["family"]["master_name"] )
        printf("¡õ Ê¦¸¸£º "HIW"%s"NOR"¡£\n",
                my["family"]["master_name"]
      );
  }

	if(my["clan"]) {
		printf( "\n¡õ ËùÊô°ïÅÉ: "+HIY+"%s\n"NOR  , my["clan"]["name" ] );
		if(my["clan"]["title"])
			printf(   "¡õ °ïÖĞÖ°Î»: "+HIC+"%s\n\n"NOR, my["clan"]["title"] );
	}

	if(my["max_s_kee"])
		printf("¡õ ÁéÆø¡¾ %s ¡¿: "+ HIG+"%d/%d\n" NOR,
			to_chinese(my["sec_kee"]), my["s_kee"], my["max_s_kee"]);

  if(my["class"] && my["class"]=="officer")
  {
   printf("¡õ ¹ÙÎ»:¡¾"HIW"%s"NOR"¡¿ È¨Á¦ %d/%d  ¡õ ÕşÖÎ¾­Ñé: "HIC"%d\n"NOR,
        my["officer_class"],
        my["officer_power"],my["max_officer_power"],
        my["office_exp"]
    );
  }

	printf(
		"¡õ ëöÁ¦[str]: %2d   µ¨Ê¶[cor]: %2d   ÎòĞÔ[int]: %2d   ÁéĞÔ[spi]: %2d\n"+
	      	"¡õ ¶¨Á¦[cps]: %2d   ÈİÃ²[per]: %2d   ¸ù¹Ç[con]: %2d   ¸£Ôµ[kar]: %2d\n\n",
      			my["str"], my["cor"], my["int"], my["spi"],
      			my["cps"], my["per"], my["con"], my["kar"]
    	);
	printf("¡õ ¾«: %s%s%-6s%s  ÁéÁ¦: %s%-5s  ¾­ÑéÖµ: "HIM"%-12d"NOR" Ê³Îï: %s  ÒûË®: %s\n"NOR,
    state( my["gin"], my["eff_gin"] ),
    status_color(my["eff_gin"], my["max_gin"]),
    "("+my["eff_gin"] * 100 / my["max_gin"]+"%)",NOR,
    state (my["atman"], my["max_atman"]),
    "("+my["atman_factor"]+")",
    my["combat_exp"],
    state(my["food"], ob->max_food_capacity()),
    state (my["water"], ob->max_water_capacity())
  );

  printf("¡õ Æø: %s%s%-6s%s  ÄÚÁ¦: %s%-5s  Ç±  ÄÜ: %-12s "HIR"É±Æø"NOR" %-5d"HIR" ÖĞ¶¾"NOR" %s\n",
    state (my["kee"], my["eff_kee"]),
    status_color(my["eff_kee"], my["max_kee"]),
    "("+my["eff_kee"] * 100 / my["max_kee"]+"%)",NOR,
    state (my["force"], my["max_force"]),
    "("+my["force_factor"]+")",
    my["potential"] - my["learned_points"]+"("+
    (int)(1+(int)my["learned_points"])*100 / (1+(int)my["potential"])+"%)",
    my["bellicosity"],
    ob->query_condition()?":~~(":NOR":-)",
  );

  if( objectp(weapon = ob->query_temp("weapon")) )
    if (present(weapon, ob))
      skill_type = weapon->query("skill_type");
    else {
        weapon = 0;
        ob->delete_temp("weapon");
        skill_type = "unarmed";
    }
  else
    skill_type = "unarmed";

  attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
  parry_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_OTHER);
  dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

  printf("¡õ Éñ: %s%s%-6s%s  ·¨Á¦: %s%-5s \n\n",
    state( my["sen"], my["eff_sen"] ),
    status_color( my["eff_sen"], my["max_sen"] ),
    "("+my["eff_sen"] * 100 / my["max_sen"]+"%)",NOR,
    state (my["mana"], my["max_mana"]),
 "("+my["mana_factor"]+")");

  printf(HIY"¡¶Õ½¶·¹¥»÷Á¦¡·: "HIW"%O("HIC"+%O"HIW")\n"NOR
         HIY"¡¶Õ½¶··ÀÓùÁ¦¡·: "HIW"%O("HIG"+%O"HIW")\n" NOR,
 attack_points+1,
    (int)ob->query_temp("apply/damage"),
 (dodge_points + (weapon? parry_points: (parry_points/10)))+1,
    (int)ob->query_temp("apply/armor")
);
}

// by babe
string status_color( int value, int max )
{
	int	ratio;

	if( max )
		ratio = value * 100 / max;
	else
		ratio = 100;

	if     ( ratio > 100 ) return HIC;
	else if( ratio ==100 ) return HIW;
        else if( ratio >= 90 ) return HIG;
        else if( ratio >= 80 ) return GRN;
        else if( ratio >= 60 ) return HIY;
        else if( ratio >= 40 ) return YEL;
        else if( ratio >= 20 ) return HIR;
	else		       return RED;
}

// by babe
string state( int value, int max )
{
	int	ratio;
	string	msg;

	if( max==0 )
		return HIR+"._.??"+NOR;

	ratio  = value * 100 / max;
	if     ( ratio > 100 ) msg = HIC + "*_* ";
	else if( ratio ==100 ) msg = HIW + "^O^ ";
        else if( ratio >= 90 ) msg = HIG + "^o^ ";
        else if( ratio >= 80 ) msg = GRN + "^_^ ";
	else if( ratio >= 60 ) msg = HIY + "-.- ";
	else if( ratio >= 40 ) msg = YEL + "-_-\"";
	else if( ratio >= 20 ) msg = HIR + "!_! ";
	else		       msg = RED + ">_< ";

	return msg + NOR;
}

string status_string(int status)
{
        string *status_desc=({
        "[1mÄã¾õµÃÉíÌå×´¿öÁ¼ºÃ£¬»ëÉí³äÂúÁË»îÁ¦¡£",
        "[1;36mÄã¾õµÃÓĞµãÍ·ÔÎ£¬µ«»¹Ã»Ê²Ã´´ó°­¡£",
        "[1;33mÄã¸Ğµ½ĞÄÖĞÕóÕó·³Ôê£¬ÑÛÇ°ëüëÊëÊµÄ¿´²»ÕæÇĞ¡£",
        "[1;32mÄã¿ªÊ¼¾õµÃ¶ñĞÄ£¬ÕóÕóµÄÔÎÑ£¸Ğ´«À´¡£",
        "[1;35mÄã¾õµÃÍ·Í´ÓûÁÑ£¬ºÃÏëÕÒ¸öµØ·½ÌÉÏÂÀ´ĞİÏ¢¡£",
        "[1;31mÄã¾õµÃÌìĞıµØ×ª, ËÆºõ¿ìÒªÔÎµ¹ÁË¡£"
        });
        if( status >= 1000 )    status=999;
        if( status < 0 )        status=0;
        if( status < 400 )
                return status_desc[0];
        else
                return status_desc[(status-400)/100];
}

varargs int main( object me, string arg, int mode )
{
	object	ob;

	seteuid(getuid(me));

	if( !arg )
		ob = me;
	else if( wizardp(me) ) {
		arg = lower_case(arg);
		ob = present( arg, environment(me) );
		if( !ob )
			ob = find_player(arg);
		if( !ob )
			ob = find_living(arg);
        if( !ob )
            ob = FINGER_D->acquire_login_ob(arg);
		if( !ob )
			return notify_fail("ÄãÒª²ì¿´Ë­µÄ×´Ì¬?\n");
	}
	else
		return notify_fail("Ö»ÓĞÎ×Ê¦ÄÜ²ì¿´±ğÈËµÄ×´Ì¬¡£\n");

	if( mode==1 )
		ob = me->query_temp("pal");

	if( wizardp(me) )
		wiz_score(ob);
	else
		player_score(ob);

	return 1;
}

int help(object me)
{
  write(@HELP
Ö¸Áî¸ñÊ½ : score
           score <¶ÔÏóÃû³Æ>                   (Î×Ê¦×¨ÓÃ)
Ö¸ÁîËµÃ÷ :
           Õâ¸öÖ¸Áî¿ÉÒÔÏÔÊ¾Äã(Š…)»òÖ¸¶¨¶ÔÏó(º¬¹ÖÎï)µÄ»ù±¾×ÊÁÏ¡£
           »ù±¾×ÊÁÏµÄÉè¶¨Çë²ÎÔÄ 'help setup'¡£
ÆäËû²Î¿¼ :
           hp
HELP
    );
    return 1;
}
