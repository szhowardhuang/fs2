// c_create.c

#include <clan.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help( object me )
{
        write(@HELP

指令格式: c_create <帮主ID> <帮派中文名称> <帮派英文名称>
指令说明: 于狂想空间创立新的帮派。

HELP
    );
        return 1;
}

int main( object me, string str )
{
	object  ob;
	string  id, cname, cid;

	if( !me->query("clan") || wiz_level(me)<5 )
		return 0;
	if( !str || sscanf( str, "%s %s %s", id, cname, cid ) != 3 )
		return help(me);
        if( !ob = find_player(lower_case(id)) )
                return notify_fail("没有这个人。\n");
        if( !CLAN_D->create_clan( id, cid, cname ) )
		return notify_fail("这个帮派已经存在了。\n");
        if(CLANV_D->create_clanv(cid))
        ob->set( "clan/name", cname );
        ob->set( "clan/id", cid );
        ob->set( "clan/rank", 1 );
        ob->set( "clan/passwd", "0" );
        ob->set( "clan/title", "帮派老大" );
	CHANNEL_D->do_channel( me, "mud",
		"\n快报!!快报!!"+ob->query("name")+"在狂想大陆上成立了"+cname+"这个帮派。\n");

        return 1;
}

