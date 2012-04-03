// hp cmds

#include <ansi.h>

inherit F_CLEAN_UP;

string status_color(int current, int max);
string score_string(object ob);
string hero_string(object ob);

varargs int main( object me, string arg, int mode )
{
        object ob;
        mapping my;
        string status_desc="";

        seteuid(getuid(me));

        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄ×´Ì¬£¿\n");
        } else
                return notify_fail("Ö»ÓÐÎ×Ê¦ÄÜ²ì¿´±ðÈËµÄ×´Ì¬¡£\n");

	if( mode==1 )
		ob = me->query_temp("pal");

        my = ob->query_entire_dbase();

	printf( "¾«Á¦:%s%6d /%6d (%3d%%)"NOR+
                "  ÁéÁ¦:%s%6d /%6d (+%2d)"NOR+
                "  ¼¢¶ö/¿Ú¿Ê: %s%d%% / %s%d%%\n"NOR,
		status_color( my["gin"], my["max_gin"] ),
		my["gin"],
		my["eff_gin"],
		my["eff_gin"] * 100 / my["max_gin"],
		status_color( my["atman"], my["max_atman"] ),
                my["atman"], my["max_atman"],
                my["atman_factor"],
                status_color(my["food"], ob->max_food_capacity()),
                100-100*my["food"]/ob->max_food_capacity(),
                status_color(my["water"], ob->max_water_capacity()),
                100-100*my["water"]/ob->max_water_capacity() );
	printf( "ÆøÑª:%s%6d /%6d (%3d%%)" NOR+
                "  ÄÚÁ¦:%s%6d /%6d (+%2d)" NOR+
                "  Ç±ÔÚ-ÄÜÁ¦: %O(%O%%)\n"NOR,
                status_color( my["kee"], my["max_kee"]),
                my["kee"], my["eff_kee"],
                my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),
                my["force"], my["max_force"],
                my["force_factor"],
                (int)ob->query("potential") - (int)ob->query("learned_points"),
                (1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential")));
	printf( "Éñî¨:%s%6d /%6d (%3d%%)" NOR
                "  ·¨Á¦:%s%6d /%6d (+%2d)" NOR
                "  ÊµÕ½-¾­Ñé: %O\n",
                status_color(my["sen"], my["max_sen"]),
                my["sen"], my["eff_sen"],
                my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
                my["mana_factor"],
                my["combat_exp"] );

	status_desc += CON_D->con_query(ob);
        status_desc += (ob->query_temp("medicine/plaster_power")?"[1;33m(Í¿Ò©)[0m ":"");
        status_desc += (ob->query_temp("sun-moon")?"("HIY"ê»«hÆø¾¢"NOR") ":"");
        status_desc += (ob->query_temp("bloodkee")?"("HIR"ÑªÉ±Óà¾¢"NOR") ":"");
        status_desc += (ob->query_temp("bloodfight")?"("HIR"ÑªÄ§¶·Æø"NOR") ":"");
        status_desc += (ob->query_temp("no_power_sword")?"("HIY"ÄùÅÌÉ±¾¢"NOR") ":"");
        status_desc += (ob->query_temp("no_power_godsub")?"("HIC"·ÖÉíÓà¾¢"NOR") ":"");
        status_desc += (ob->query_temp("medicine/bandaged")?"[1m(°üÔú)[0m ":"");
        if( status_desc=="" ) status_desc += "ÎÞ";
	printf("ÃûÉù: %s              É±Æø:"HIR"%6d"+NOR+"                ÎäÑ§-ÐÞÎª: %s\n",score_string(ob),my["bellicosity"],hero_string(ob));
	printf("×´Ì¬: %s\n", status_desc );
	return 1;
}

string status_color( int current, int max )
{
        int ratio;

        if( max>0 )
        	ratio = current * 100 / max;
        else
        	ratio = 100;
	if( ratio >100 ) return HIC;
        if( ratio > 90 ) return HIG;
        if( ratio > 80 ) return GRN;
        if( ratio > 60 ) return HIY;
        if( ratio > 40 ) return YEL;
        if( ratio > 20 ) return HIR;
		         return RED;
}

string score_string(object ob)
{
  int scores;
  string *ppl_desc;

  scores =scores+(ob->query("MKS")*2);
  scores =scores-(ob->query("PKS")*500);
  scores =scores-(ob->query("death/time")*300);
  scores =scores+(ob->query("pk_win")*40);
  scores =scores-(ob->query("pk_lose")*40);
  scores =scores+(ob->query("scores"));

       ppl_desc=({
        HIR"Ð°Ä§×ªÊÀ"NOR,
        HIR"¶ñ¹áÂúÓ¯"NOR,
        HIR"×ï´ó¶ñ¼«"NOR,
        HIM"É±ÈËÈçÂé"NOR,
        HIM"ÎÞ¶ñ²»×ö"NOR,
        HIC"¶ñÃûÕÑÕÃ"NOR,
        HIC"ÂÔ´øÐ°Æø"NOR,
        NOR"ÎÞÃûÐ¡×ä"NOR,
        HIG"ÐÄ´æÏòÉÆ"NOR,
        HIG"´È±¯Îª»³"NOR,
        HIG"ÂÔÓÐÏÀÃû"NOR,
        HIW"ÕÌÒåÎªÈË"NOR,
        HIW"ÔÙÊÀ¸ßÈË"NOR,
        HIY"ÏÀÃûÔ¶²¥"NOR,
        HIY"Ò»´ú´óÏÀ"NOR,
        });

        if(scores <= -6000 )
                return ppl_desc[0];
      else if(scores <= -5000)
                return ppl_desc[1];
      else if(scores <= -4000)
                return ppl_desc[2];
      else if(scores <= -3000)
                return ppl_desc[3];
      else if(scores <= -2000)
                return ppl_desc[4];
      else if(scores <= -1000)
                return ppl_desc[5];
      else if(scores <= -500)
                return ppl_desc[6];
      else if(scores <= 500)
                return ppl_desc[7];
      else if(scores <= 1000)
                return ppl_desc[8];
      else if(scores <= 2000)
                return ppl_desc[9];
      else if(scores <= 3000)
                return ppl_desc[10];
      else if(scores <= 4000)
                return ppl_desc[11];
      else if(scores <= 5000)
                return ppl_desc[12];
      else if(scores <= 6000)
                return ppl_desc[13];
      else return ppl_desc[14];

}
string hero_string(object ob)
{
  int exp;
  string *ppl_desc;
  exp=ob->query("combat_exp");
  ppl_desc=({
        RED"³õ¿úÃÅµÀ"NOR,
        HIR"ÐÄÁìÉñ»á"NOR,
        HIR"Ó¦ÓÃ×ÔÈç"NOR,
        BLU"Éí¾­°ÙÕ½"NOR,
        HIB"¼¼Ñ¹ÈºÐÛ"NOR,
        HIB"Íò·òÄªµÐ"NOR,
        MAG"ºêÔ¶ÎÞÙ±"NOR,
	HIM"ËæÐÄËùÓû"NOR,
	GRN"³öÉñÈë»¯"NOR,
	HIG"¾ªÊÀº§Ë×"NOR,
	YEL"ÎäµÀ´ó³É"NOR,
	HIY"³É×ÚÁ¢ÅÉ"NOR,
	CYN"µÇ·åÔì¼«"NOR,
	HIC"¾ÙÊÀÎÞË«"NOR,
	HIW"Ñ§¾¿ÌìÈË"NOR,
  });

        if(exp <= 100000)
                return ppl_desc[0];
   else if(exp <= 300000)
                return ppl_desc[1];
   else if(exp <= 600000)
                return ppl_desc[2];
   else if(exp <= 1000000)
                return ppl_desc[3];
   else if(exp <= 1500000)
                return ppl_desc[4];
   else if(exp <= 2000000)
                return ppl_desc[5];
   else if(exp <= 3000000)
                return ppl_desc[6];
   else if(exp <= 4000000)
                return ppl_desc[7];
   else if(exp <= 5000000)
                return ppl_desc[8];
   else if(exp <= 6000000)
                return ppl_desc[9];
   else if(exp <= 7000000)
                return ppl_desc[10];
   else if(exp <= 8000000)
                return ppl_desc[11];
   else if(exp <= 9000000)
                return ppl_desc[12];
   else if(exp <=10000000)
                return ppl_desc[13];
   else
                return ppl_desc[14];
}


int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ : hp
           hp <¶ÔÏóÃû³Æ>                   (Î×Ê¦×¨ÓÃ)
Ö¸ÁîËµÃ÷ :
           Õâ¸öÖ¸Áî¿ÉÒÔÏÔÊ¾Äã(Š…)»òÖ¸¶¨¶ÔÏó(º¬¹ÖÎï)µÄ
       ¾«£¬Æø£¬ÉñÊýÖµ»òÕßÆäËûÉíÌå×´¿ö¡£
ÆäËû²Î¿¼ :
           score
HELP
    );
    return 1;
}
