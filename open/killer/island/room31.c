inherit ROOM;

void create()
{
        seteuid(getuid());
        set( "short", "‘碧绿石道’" );
        set( "cmkroom", 1 );
        set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/orient/room/room34.c",
  "east" : "/open/clan/orient/room/room29.c",
]) );
        set( "clan_room", "烟雨江南" );
        set( "light_up", 1 );
        set( "no_transmit", 1 );
        set( "outdoor", "/open/clan" );
        set( "long", "青石板铺成的街道向两侧绵延过去，天空中时时飘着轻盈如飞花的细细
雨丝，沾得路面润着青青的苔绿；行走至此人迹渐少，但闻汤汤流水如奏宫
商，更有那两岸杨柳绿袖相招，枝头莺燕穿梭啁啾，聊慰寂寥之情。
" );
        set( "no_clean_up", 0 );
        setup();
        replace_program(ROOM);
        }
