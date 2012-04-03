inherit ROOM;
void create() {
	set( "short", "$HIY$【$HIR$红莲 $HIC$大道 $HIB$云海$HIY$】$NOR$" );
	set( "exits", ([
		"down"      : "/open/clan/red_fire/room/hall",
	]) );
	set( "outdoors", "/open/clan/red_fire" );
	set( "long", @LONG

  $HIR$﹋﹋﹋﹋﹋﹋        ﹋﹋﹋﹋﹋﹋
      $YEL$﹋﹋﹋﹋﹋﹋        ﹋﹋﹋﹋﹋﹋
          $HIY$﹋﹋﹋﹋﹋﹋        ﹋﹋﹋﹋﹋﹋
              $HIG$﹋﹋﹋﹋﹋﹋        ﹋﹋﹋﹋﹋﹋
                  $HIC$﹋﹋﹋﹋﹋﹋        ﹋﹋﹋﹋﹋﹋
                      $HIB$﹋﹋﹋﹋﹋﹋        ﹋﹋﹋﹋﹋﹋
                          $HIM$﹋﹋﹋﹋﹋﹋        ﹋﹋﹋﹋﹋﹋

$NOR$你跃入一片$HIM$七彩$HIB$云海$NOR$之中......

伸手不见$HIY$五指$NOR$......完全找不到方向......

你只有随风$HIC$飘啊飘$NOR$......$HIC$飘啊飘$NOR$......

终于......慢慢的向下降落...... 


LONG);
	setup();
	replace_program(ROOM);
}
