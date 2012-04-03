// Room : /open/clan/red_fire/room/room11.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "红莲教" );
	set( "light_up", 1 );
	set( "short", "$HIM$【$HIY$圣域 $HIC$八卦阵$HIM$】$NOR$" );
	set( "long", @LONG
    
                             $HIC$干 （天）
                      $HIB$兑     $WHT$________     $HIM$巽
                       $WHT$╱□  ________    ╲
               $HIB$（泽）$WHT$╱ ╱   ________   ╲   $HIM$（风）
                   $WHT$╱ ╱ ╱            ╲ ╲ ╲
                    $WHT$╱                   ╲ ╲
                     $WHT$╱     $HIW$╱◢██◣     $WHT$╲
                          $HIW$╱  ██●█◣      
            $HIR$离  $WHT$│││   $HIW$ ▏  ◥████    $WHT$│││  $BLU$坎
                $WHT$│  │   $HIW$ ▏    ◥███      $WHT$│ 
          $HIR$（火）$WHT$│││   $HIW$ ▏      ◥██    $WHT$│││$BLU$（水）
                          $HIW$＼  ●    █◤
                     $WHT$╲     $HIW$＼＿＿◢◤     $WHT$╱
                    $WHT$╲                   ╱ ╱
                   ╲  □╲  ___  ___  ╱    ╱
                $HIY$ 震  $WHT$╲ ╲   ___  ___   ╱     $MAG$艮
                       $WHT$╲    ___  ___    ╱
                   $HIY$（山）                $MAG$（雷）
                             $YEL$坤 （地）$NOR$

     哇！！这里是$HIR$禁地$NOR$吗？你感到一股压迫感，使你全身的神经都受
     到牵制......你感到全身无力，只有勉强着继续往前进，祈求能
     早一点离开这里......。


LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "up" : "/open/clan/red_fire/room/room12.c",
  "down" : "/open/clan/red_fire/room/room10.c",
]) );
	setup();

	}
