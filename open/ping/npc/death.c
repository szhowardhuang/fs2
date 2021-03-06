// master_death.c by babe

#include <ansi.h>

inherit NPC;

string spiritism();

void create()
{
	set_name( "老不死", ({ "master death", "master", "death" }) );
	set( "title", "坟场老者" );
	set( "nickname", HIB"太岁"NOR );
	set( "gender", "男性" );
	set( "age", 1000 );
	set( "attitude", "hero");
	set( "long",
		"    老不死的脸容枯\瘦凹陷, 比铁更加冰冷坚硬, 而且\n"
		"没有眼珠, 但眼眶内却黑沉沉, 似隐藏着无尽凶恶, 散\n"
		"发着无比浓烈的死亡气息。\n"
		"    老不死当年以一招「御魂术”称霸武林, 并得以长\n"
		"生不老, 但现在不知为何隐居于此。\n\n" );
	set( "combat_exp"  , 20000000 );
	set( "max_kee"     , 15000 );
	set( "max_force"   , 10000);
	set( "force"       , 10000);
	set( "force_factor", 10 );
	set( "no_lyssa", 1 );
	set( "chat_chance" , 10 );
	set( "chat_msg", ({
		(: command ("say 闲杂人等快滚吧!") :),
		(: command ("say 看什么看!") :),
		(: command ("say 走开走开!") :),
		(: command ("say 给我滚!") :),
		(: command ("say 滚开!") :),
		(: command ("say 滚!") :),
		(: command ("say 叫你滚还不滚?") :), 
		(: command ("say 正道人士都是一群乌龟王八蛋!") :), 
		(: command ("say 叫你滚还不滚?") :), 
		(: command ("spit") :),
		(: command ("yawn") :),
		}) );
        set("inquiry",([
		]));
	setup();
}

void init()
{
	if( !query_heart_beat(this_object()) )
		set_heart_beat(1);
	::init();
}

int accept_fight( object who )
{
	object me = this_object();
	command( "say 找死!!!\n" );
	message_vision( HIR"$N祭起顶级"RED"御魂术"HIR", 脸孔陡变透明, 地底不断窜出无数邪灵。\n\n"NOR, me );
	message_vision( HIR"霎时间怒吼与狂啸声不绝, 震得人耳鼓欲破。\n\n"NOR, me );
	message_vision( HIR"$N被邪灵团团围住, 瞬间便被啃蚀殆尽, 恐怖骇人。\n\n"NOR, who );
	tell_object( who , "你的眼前一片黑暗......\n" );
        who->remove_all_killer();
        who->unconcious();
        load_object( "/open/center/room/inn" );                 
        who->move( "/open/center/room/inn" );                     
        return 1;                                
}

int accept_kill( object who )
{
	object me = this_object();
	command( "say 找死!!!\n" );
	message_vision( HIR"$N祭起顶级"RED"御魂术"HIR", 脸孔陡变透明, 地底不断窜出无数邪灵。\n\n"NOR, me );
	message_vision( HIR"霎时间怒吼与狂啸声不绝, 震得人耳鼓欲破。\n\n"NOR, me );
	message_vision( HIR"$N被邪灵团团围住, 瞬间便被啃蚀殆尽, 恐怖骇人。\n\n"NOR, who );
	tell_object( who , "你的眼前一片黑暗......\n" );
        who->remove_all_killer();
        who->unconcious();
        load_object( "/open/center/room/inn" );                    
        who->move( "/open/center/room/inn" );                       
        return 1;                                
}

string spiritism()
{
	object	me, who;
	string	g, respect;

	me	= this_object();
	who	= this_player();
	g	= who->query("gender")=="男性" ? "你": "妳";
	respect	= RANK_D->query_respect(who);

	if( !who->query("pker") ) {
		if( who->query("spiritism/0")==1 ) {
			command( "say 嘿, 徒儿这回带些什么好东西来孝敬为师啊?" );
			return "";
		}
		if( who->query_temp("spiritism")==1 ) {
			switch( random(5) ) {
			case  0 :
				command( "say 快滚!" );
				break;
			case  1 :
				command( "say " + respect + "还死赖在这里干嘛?" );
				break;
			case  2 :
				command( "say 滚开!" );
				break;
			case  3 :
				command( "say " + respect + "若再不快滚, 休怪老夫不客气了!" );
				break;
			default :
				command( "say 滚!" );
			}
			return "";
		}
		command( "look "+who->query("id") );
		if( who->query("cor")< 20 ) {
			switch( random(2) ) {
			case  0 :
				who->do_command("cower");
				command( "say 哼! 老夫只瞧得起有胆识的人。" );
				who->do_command("cower");
				command( "say " + g + "好好看看" + g + "自己! 现在都已吓成什么样子了。" );
				command( "say 还是快滚吧。" );
				who->do_command("flee");
				break;
			default :
				who->do_command("cower");
				me ->do_command("? "+who->query("id"));
				command( "say 哼! 就凭" + g + "这种货色也想修习此术? 哈!" );
				who->do_command("cower");
				command( "say " + g + "好好看看" + g + "自己! 现在都已吓成什么样子了。" );
				command( "say 还是快滚吧。" );
				who->do_command("flee");
			}
			who->set_temp( "spiritism", 1 );
			return "";
		}
		if( who->query("cor") > 34 ) {
			me ->do_command("hmm");
			command( "say " + respect + "乃难得的奇才。" );
			command( "say 不过还是得证明" + g + "的能力让老夫瞧瞧。" );
			who->set_temp( "spiritism", 1 );
			return "";
		}
		switch( random(2) ) {
		case  0 :
			command( "say 老夫只看得起有胆识的人。" );
			command( "say 等" + respect + "敢杀人时再来找我吧。" );
			break;
		default :
			command( "say 修习此术需有过人胆识。");
			command( "say 老夫瞧" + respect + "并不适合修习此术。" );
			command( "say 还是滚一边凉快去吧。" );
		}
		who->set_temp( "spiritism", 1 );
                return "";
        }
	if( !who->query_temp("spiritism") ) {
		command( "say 杀人凶手来墓地作什么?" );
		command( "say 不怕死者找你报仇吗?" );
		command( "say 快夹着尾巴逃吧! 哈!" );
		return "";
        }        
	message_vision( HIY"\n$N一阵狂笑。\n\n"NOR, me );
	command( "say 很好, 老夫很欣赏" + respect + "。" );
	command( "say 这就传" + respect + "此术心法, 以免后世无知小辈无幸观此惊世绝学。" );
	command( "say 老夫先以内力助" + g + "通过此术最为凶险的关卡。" );
	command( "say 当心了!" );
	tell_room( environment(me), HIM + me->query("name") + "运起至阴"RED"御魂术"HIM", 散发出阵阵浓烈的死亡气息。\n"NOR, who );
	who->set( "spiritism/0", 1 );
	who->unconcious();
	return "";
}

void die()
{
	object	who = query_temp("last_damage_from");
	object	me  = this_object();
	command( "say 找死!!!\n" );
	message_vision( HIR"$N祭起顶级"RED"御魂术"HIR", 脸孔陡变透明, 地底不断窜出无数邪灵。\n\n"NOR, me );
	message_vision( HIR"霎时间怒吼与狂啸声不绝, 震得人耳鼓欲破。\n\n"NOR, me );
	message_vision( HIR"$N被邪灵团团围住, 瞬间便被啃蚀殆尽, 恐怖骇人。\n\n"NOR, who );
	tell_object( who , "你的眼前一片黑暗......\n" );
        who->remove_all_killer();
        who->die();
	:: die();
}

