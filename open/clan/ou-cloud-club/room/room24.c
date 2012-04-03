// Room : /open/clan/ou-cloud-club/room/room24.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
ÄãÀ´µ½Ò»¸ö¿Õ¼ä¼«¶ÈÒì³£µÄÇøÓò£®£®£®Ö»¼ûÖÜÎ§ÓĞ×Å
°Ë¸ö¹°ĞÍµÄ¶´£¬²¢ÇÒÍ¸·¢³öÆß²Ê¹âÃ¢£¬ÄÑµÀÕâÀï¾ÍÊÇ±¾×¯
µÄÆæÏóÖ®Ò»¡¾$HBBLU$°Ë$HBYEL$·½$HBRED$É±$HBCYN$Áé$HBGRN$µÀ$NOR$¡¿£¬¾İËµÕâÀïÊÇÎªÁËÈÃ°ïÖÚ¸üÊÜ
Ò»²ãµÄÊÔÁ¶£¬ËùÒÔ±¾×¯×¯Ö÷±ãÒÔÈÎÁî¿Õ¼äÇĞ¸îµÄ¹¦Á¦£¬½«
´ËÇøÓò·ÖÎª°Ë¸ö¿Õ¼ä£¬²¢Í¨Íù°Ë¸öÉñÃØµÄÊÀ½ç£¬³ı´ËÖ®Íâ
£¬ÀÏÒ»±²µÄ³¤ÀÏ»¹Ëµ£¬°Ë¸öÍ¨µÀ×îºó»áµ½´ïÒ»¸ö×îÖÕµÄÇø
Óò£¬¶øÇÒ¾¹È»Á¬×¯Ö÷±¾ÈËÒ²Î´µ½´ï£¬¶øÄÇ¸öÉñÃØµÄÇøÓò¿É
ÒÔÁîÈÎºÎÈËµÃµ½[0;1;5;33m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mb[1;5m¡õ[1;5mU[1;5m¡õ[1;5mB[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mU[0mµÄÄÜÁ¦£®£®£®


                    $HIY$Ìì½ç$NOR$
                 
              $HIC$Áú½ç$NOR$         $HIM$»Ã½ç$NOR$       
         
        $YEL$ÌìóÃ$NOR$     $HBBLU$°Ë$HBYEL$·½$HBRED$É±$HBCYN$Áé$HBGRN$µÀ$NOR$      $CYN$³¯ÏÊ$NOR$

              $HIB$Áé½ç$NOR$         $HIG$Ñı½ç$NOR$  

                    $HIR$µØÓü$NOR$



LONG);
	set( "short", "$HBBLU$°Ë$HBYEL$·½$HBRED$É±$HBCYN$Áé$HBGRN$µÀ$NOR$" );
	set( "build", 10030 );
	set( "clan_room", "°ÁÔÆÉ½×¯" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 3 */
		"west"      : "/open/clan/ou-cloud-club/room/room25.c",
		"down"      : "/open/clan/ou-cloud-club/room/room22",
		"north"     : "/open/clan/ou-cloud-club/room/room12.c",
]) );
	set( "light_up", 1 );
	setup();

	}
