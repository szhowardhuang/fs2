// Room: /u/o/onion/room/hell.c

inherit ROOM;

void create()
{
	set("short", "地牢");
	set("long", @LONG
一座暗无天日的地牢,只有一点微弱的光线由墙角缝渗透进来,勉强可以分辨四周的
景物,整个墙壁是由坚硬的花岗石所筑成,凭你的功力连挖点灰下来都不可能,硬想破墙
而出更是难如登天.想到自己要被困在这儿,不能去玩MUD,就觉得欲哭无泪,～哇～....

LONG
	);
        set("item_desc", ([
	"corner" :
"你睁大双眼,仔细的往角落瞧,可是实在是太暗了,什么都看不到咧...\n",	
        "plate" : 
"上头似乎刻着一些甲骨文,凭着你优异的国学知识,你辨识出这些句子的意思是 :\n"+
"\n			[1;36mIloveOnion[0m\n\n"+
"疑..难道这就是密码?\n"
	]));
	
	setup();
}

        void init()
        {
        	add_action("do_search","search");
                add_action("do_say","'");
                add_action("do_say","say");
        }
        
        int do_say(string str)
        {
        	if (str!="IloveOnion")
        	return 0;
        	else
        	{
        	write("恭喜你!!你答对了password,可以出去了.\n");
        	tell_room(environment(this_player()),
        	(string)this_player()->query("name")+
        	"忽然消失不见了,哇...没带我出去...\n",
                ({this_object(),this_player()}));
                this_player()->move(__DIR__"room3");
                write("碰～的一声,你终于掉到地上了,疑...这不是原本的地方吗?\n");
                tell_room(environment(this_player()),"碰～的一声,你看到"+
                (string)this_player()->query("name")+"不知道从那掉了下来...\n",
                ({this_object(),this_player()}));
        	return 1;
        	}
        }	
        int do_search(string str)
        {
        	if (str!="corner")
        	{
        	write("你闲着无聊到处摸一摸...\n"+
       		      "吓!!一只死猫从角落(corner)跑出来\n");
		return 1;
		}
		else
		{
		write(
"角落里似乎有一块石板(plate)凹凹凸凸的,和其他墙壁特别不一样,难道这是机关?\n");
		return 1;
		}
       	}         
