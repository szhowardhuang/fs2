// who.c
// rewrited by wade
// ÎÒ´ÓÍ·µ½Î²¸ÄĞ´¹ı, ÀíÂÛÉÏ»á¿ìÉÏÒ»µãµã.
// ÈÃÎ×Ê¦¿ÉÒÔÒşĞÎ, Íæ¼ÒÔò²»ĞĞ, ±£ÁôÒÔÇ°µÄ class, guild µÈµÄÑ¡Ïî
// ÖØĞÂ¸ÄĞ´ by Chan Ìá¸ßÊ¹ÓÃ²ÎÊıµÄÏŞÖÆ Ö»´òwho²»¿ÛÈÎºÎ¾«¡¢Éñ
#include <net/dns.h>
inherit F_CLEAN_UP;

string age_string(int);
int sort_age(object ob1, object ob2);
int sort_ip(object ob1, object ob2);
int sort_exp(object ob1, object ob2);
int sort_g(object ob1, object ob2);
int sort_c(object ob1, object ob2);
int help();

mixed main(object me, string arg, int remote)
{
  string  str;
  string  *option, tmp;
  object  *list, *list_tmp;
  int     j, ppl_cnt, count;
  int     opt_long, opt_id, opt_ip;
  int     opt_c, opt_g, opt_age, opt_exp;
  int     wiz;

  seteuid(getuid());

  if(!me) return 0;
  wiz = wiz_level(me);
  //Ìá¸ßÊ¹ÓÃ²ÎÊıµÄÏŞÖÆ by chan
  if (!wiz && (me->query("sen") < 21 || me->query("gin") < 21))
    return notify_fail ("ÄãµÄ¾«ÉñÌ«²îÁË, ÎŞ·¨Ê¹ÓÃ who.\n");
  if ( arg ) {
    if (wiz && arg[0]=='@') {
      RWHO_Q->send_rwho_q(option[j][1..sizeof(option[j])], me, 0);
      write("ÍøÂ·Ñ¶Ï¢ÒÑËÍ³ö£¬ÇëÉÔºò¡£\n");
      return 1;
    }
    option = explode(arg, " ");
    j = sizeof(option);
    while ( j-- )
      switch (option[j]) {
        case "-l"  :    opt_long = 1; break;
        case "-i"  :    opt_id   = 1; break;
        case "-ip" :    opt_ip   = 1; break;
        case "-c"  :    opt_c    = 1; break;
        case "-g"  :    opt_g    = 1; break;
        case "-age":    opt_age  = 1; break;
        case "-exp":    opt_exp  = 1; break;
      }
  }

  // ËùÓĞÍæ¼Ò.
  list = children("/obj/user");
  ppl_cnt = sizeof(list);
  list_tmp = ({});
  count = 0;

  // ¹ıÂËÊÇ·ñ³öÏÖÔÚÃûµ¥ÉÏ, Î×Ê¦Ëù¼û¸úÍæ¼Ò²»Í¬
  // Íæ¼Ò¿´²»µ½Î×Ê¦.
  j = ppl_cnt;
  while( j-- ) {
        // ÕıÔÚÔì½ÇÉ«µÄÎÒÃÇÃ»±ØÒª¹Ü
        if (!environment(list[j]) || !list[j]->query("id")) continue;
        // ÒşÉíµÄ´¦Àí
        if (list[j]->query("env/ÒşÉí") &&               // ¿ÉÒÔÉè¶¨ÒşÉí
            wiz < 7 &&                                  // ²»ÄÜ¶Ô manager ÒşÉí
            wiz_level(list[j]) &&                       // Íæ¼Ò²»ÄÜÉèÒşÉí
            wiz_level(list[j]) > wiz )                  // µ«ÊÇ²»¿É¶ÔÉÏ¼¶ÒşÉí
        {
          continue;
        }
        list_tmp += ({ list[j] });
        if (wizardp(list[j])) count++;                  // count ¼ÇÂ¼Î×Ê¦¸öÊı
  }

  // ÅÅÁĞË³Ğò
  list = list_tmp;
  if (opt_ip)
    list = sort_array(list_tmp, "sort_ip", this_object());
  else if (opt_age)
    list = sort_array(list_tmp, "sort_age", this_object());
  else if (opt_exp)
    list = sort_array(list_tmp, "sort_exp", this_object());
  else if (opt_g)
    list = sort_array(list_tmp, "sort_guild", this_object());
  else if (opt_c)
    list = sort_array(list_tmp, "sort_class", this_object());
  else if (wiz)
    list = sort_array(list_tmp, "sort_ip", this_object());
//Èô¶¼Ã»ÓĞÖ¸ÁîÒª¿´µÄÒ»ÂÉ²»ÅÅĞò by Chan
  // ÏÔÊ¾Ñ¶Ï¢
  str = ("¡ò " + MUD_NAME + "\n");
  str += ("©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"
          "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");
  str = sprintf ("%s¹²ÓĞ %d Î»Î×Ê¦£¬ %d Î»Íæ¼Ò£¬ÏµÍ³¸ºµ££º%s\n",
          str, count, sizeof(list)-count,
          query_load_average()
         );
  str += ("©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"
         "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");

	if( opt_age || opt_id || opt_exp || opt_g || opt_c ) {
		for( j=0; j<sizeof(list); j++ ) {// to list clan name & check margin by babe
			tmp = sprintf( "%s%s(%s)",
				( list[j]->query("title") ?
					list[j]->query("title") : "" )+
				( list[j]->query("nickname") ?
					"¡¸"+list[j]->query("nickname")+"¡±" : " " ),
				list[j]->query("name"),
				list[j]->query("id")
				);
			if( strlen(tmp)>270 )
				tmp = tmp[0..53-strlen(tmp)];
			str = sprintf("%s%12s[1;36m¦Î[1;37m%|10s[1;36m¦Î[0m %-s\n",
				str,
				RANK_D->query_rank(list[j]),
				list[j]->query("clan/name") ?
					list[j]->query("clan/name") :
					"¶À´³½­ºş",
				tmp );
		}
	if( !wiz ) {
		me->receive_damage("sen", 20);
		me->receive_damage("gin", 20);
	}
	str += "--\n  ÓÉÓÚÄã×¨ĞÄµØ²éÔÄ\ÆäËûÈËµÄ×ÊÁÏ£¬ºÄ·Ñ²»ÉÙ¾«Éñ¡£\n";
  }
  else if(!wiz) { //Ã»ÓĞÖ¸ÁîÅÅĞòÊ±,³öÏÖµÄÑ¶Ï¢,¸ÄÓÃwhile±ÈforºÃÒ»µã by chan
        ppl_cnt = 0;
        j = sizeof(list);     //½èÓÃes2µÄËã·¨ÈçÏÂ....by chan
        while( j-- ) {
         if( !environment(list[j]) ) continue;
         if( me && !me->visible(list[j]) ) continue;
         str = sprintf("%s%-15s%s",
          str,
          opt_id ? capitalize(list[j]->query("id")): list[j]->name(1),
          (ppl_cnt%5==4? "\n": ""));
          ppl_cnt++;
       }//¼ÓÉÏµ×Ïß»áºÃÒ»µã
        if( ppl_cnt%5 ) str += "\n";
       str += "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n";
       str = sprintf("%s\n", str);
  }
  else //Î×Ê¦µÄ²¿·İ
    for (j=0; j<sizeof(list); j++)
        str = sprintf ("%s%12s %14s%-12s %8s %-15s %2s%2s%2s%2s%s\n",
                 str,
                 RANK_D->query_rank(list[j]),
                 list[j]->name(1),
                 "("+(list[j]->query("id"))+")",
                 age_string ((int)list[j]->query("mud_age")),
                 list[j]->query("last_from"),
                 list[j]->query_temp("netdead")?"¶Ï":"",
                 environment(list[j])?"":"Ğé",
                 in_edit(list[j])?"±à":"",
                 in_input(list[j])?"¶Á":"",
                 (interactive(list[j]) && query_idle(list[j]) > 120)?
                        "´ô"+query_idle(list[j])/60+"·Ö":""
                );

  str=trans_color(str);
  if (remote) return str;
  me->start_more (str);
  return 1;
}

int sort_c(object ob1, object ob2)
{
  int  level;

  level = wiz_level(ob1) - wiz_level(ob2);
  if (level != 0)
    return -level;
  else
    return strcmp(ob1->query("class"),
                  ob2->query("class"));
}

int sort_g(object ob1, object ob2)
{
  int  level;

  level = wiz_level(ob1) - wiz_level(ob2);
  if (level != 0)
    return -level;
  else
    return strcmp(ob1->query("family/family_name"),
                  ob2->query("family/family_name"));
}

int sort_exp(object ob1, object ob2)
{
  int  level;

  level = wiz_level(ob1) - wiz_level(ob2);
  if (level != 0)
    return -level;
  else
    return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int sort_age(object ob1, object ob2)
{
  int  level;

  level = wiz_level(ob1) - wiz_level(ob2);
  if (level != 0)
    return -level;
  else
    return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}

int sort_ip(object ob1, object ob2)
{
  int  level;

  if (!interactive(ob1) || !interactive(ob2)) return 0;

  level = wiz_level(ob1) - wiz_level(ob2);
  if (level != 0)
    return -level;
  else if (stringp(ob1->query("last_from")) &&
     stringp(ob2->query("last_from")))
    return -strcmp(ob1->query("last_from"), ob2->query("last_from"));
}

string age_string(int time)
{
  int month, day, hour;

  time /= 3600;
  hour = time % 24;
  time /= 24;
  day = time % 30;
  month = time / 30;
  return (month?month + "m":"") + (day?day + "d":"") + hour + "h";
}

int help()
{
write(@HELP
Ö¸Áî¸ñÊ½ : who [-l | -i | -ip | -c | -g | -age | -exp ]

Ê¹ÓÃËµÃ÷ :
        Õâ¸öÖ¸Áî¿ÉÒÔÁĞ³öËùÓĞÔÚÏßÉÏµÄÍæ¼Ò¼°ÆäµÈ¼¶µ«ÊÇ»á¿ÛÉñ¼°¾«¡£

        -l Ñ¡ÏîÁĞ³ö½Ï³¤µÄÑ¶Ï¢¡£
        -i Ö»ÁĞ³öÍæ¼ÒµÄÓ¢ÎÄ´úºÅ¡£
        -ip ÒÔ ip ÅÅÁĞË³Ğò <Î×Ê¦Ô¤Éè>
        -age ÒÔÄêÁäÅÅ
        -exp ÒÔÕ½¶·¾­ÑéÖµÅÅ
        -c <Ö°Òµ´úºÅ> ÁĞ³ö¸ÃÖ°ÒµËùÓĞÍæÕß¡£
        -g <ÃÅÅÉÃû³Æ> ÁĞ³ö¸ÃÃÅÅÉµÄËùÓĞÍæÕß¡£

Ïà¹ØÖ¸Áî£º finger
HELP
    );
    return 1;
}
