// cland.c
//
//      我的建议是用 save() & restore() 的方法, 将所有帮派的资料
//      存在 query_save_file() 那
//
//                                                      Created by Arthur
//
//      如要防止巫师窜改资料, 可以在要防止的地方加上, 若限定只有 ROOT_UID 可以改
//      if( previous_object() && geteuid(previous_object()) != ROOT_UID )
//              return;
// 1999 05/09 为了新的系统重新改写                      By  Chan

#include <clan.h>

inherit F_SAVE;

int check_last_num(string,string,string);

mapping clans;
                        // 目前是暂定这些东西, 可以自行对照, 如有加新的,
                        // 也请加在下面, 这样比较好理解
                        // clans["帮派的 id"] = ([
                        //      "gold"          : 钱,
                        //      "members"       : ({ 帮众 id 的 array }),
                        //      "master"        : 帮主的 id,
                        //      "name"          : 帮派名称,
                        //      "level2"        : ({ array }),
                        //      "level3"        : ({ array }),
                        //      "level4"        : ({ array }),
                        //      "home"          : 帮派的家,
                        //      "develop"       : 帮派人材发展状况,
                        //      "weapon"        : 帮派武器发展状况,
                        //      "war"           : 帮派战争状态,
                        //      "tax"           : 税率
                        //      "alert"         : 警戒、备战状态
                        //      "ally"          : 同盟,
                        //      ]);

string *LEVEL   = ({ "level2", "level3", "level4" });

mapping query_clans()   { return clans; }
string query_save_file() { return DATA_DIR + "clan"; }

// 用来加减 clan 的钱
int add_money(string clan_id, int num)
{

       if( !mapp(clans[clan_id]) )
                return notify_fail("没有这个帮派。\n");
        clans[clan_id]["gold"] += num;
        return num;
}

// 用来加减某值 by Chan
int add_clanset(string clan_id,string what,int num)
{
        if( !mapp(clans[clan_id]) )
                return notify_fail("没有这个帮派。\n");
        clans[clan_id][what] += num;
        return num;
}

// 创新的 clan, master 是帮主 id,
int create_clan(string master, string clan_id, string clanname)
{

        int i;
        string npc_path,clannumber,clanename;
        if( mapp(clans) && mapp(clans[clan_id]))
                return 0;
        clans[clan_id] = ([
                "master"        : master,
                "name"          : clanname,
                "level2"        : ({}),
                "level3"        : ({}),
                "level4"        : ({}),
                "home"          : CLAN_HOME+clan_id+"/room/hall.c",
                "gold"          : 1000000,
                "members"       : ({ master }),
                "develop"       : 0,
                "weapon"        : 0,
                "armor_tech"    : 0,
                "board"         : 1,
                "prestige"      : 10000,
                "weapon_fund"   : 0,
                "armor_fund"    : 0,
                "war"           : 0,
                "tax"           : 5,
        ]);
        // 送他一间房间当开帮纪念
        assure_file( clans[clan_id]["home"] );
        CLAN_CMDS("c_room_make")->create_room(clans[clan_id]["home"]);
//建立npc的目录
        save();
        npc_path=CLAN_HOME+clan_id+"/npc";
        mkdir(npc_path);
        npc_path=CLAN_HOME+clan_id+"/weapon";
        mkdir(npc_path);
        npc_path=CLAN_HOME+clan_id+"/armor";
        mkdir(npc_path);
        npc_path=CLAN_HOME+clan_id+"/item";
        mkdir(npc_path);
        npc_path="/log/clan/"+clan_id;
        mkdir(npc_path);

        return 1;
}

void create()
{
        seteuid(getuid());
        restore();
        // 设定每个 level 的人数上限, 在这边设定才可以更改
        if( !mapp(clans) )
                clans = ([]);
        clans["limit"] = ([
                "level2" : LEVEL2_NUM,
                "level3" : LEVEL3_NUM,
                "level4" : LEVEL4_NUM,
        ]);
}

// 帮派位阶升降, 逐出帮众, return 0 表示额满或没该位阶
int clan_promote( string clan, string id, string level, int money )
{
        int i;
        if( !undefinedp(clans["limit"][level]) && sizeof(clans[clan][level]) > clans["limit"][level] -1 ) // 确定位阶
                return 0;
        i = sizeof(LEVEL); // 清掉原先的位阶
        while(i--)      {
                if( member_array( id, clans[clan][LEVEL[i]]) == -1 )
                        continue;
                clans[clan][LEVEL[i]] -= ({ id });
                break;
        }
        if( level == "banish" ) { // 将 id 逐出帮派
                clans[clan]["members"] -= ({ id });
                clans[clan]["member_gold"] -= money;
                return 1;
        }
        if( !undefinedp(clans["limit"][level]) ) // level(2~4)
                if( undefinedp(clans[clan][level]) ) // 加入该 level
                        clans[clan][level] = ({ id });
                else
                        clans[clan][level] += ({ id });
        save();
        return 1;
}

int change_clan_master(string clan, string new_master)
{
        // 先将新帮主的旧位址去掉
        clan_promote(clan, new_master, "",0);
        // 设定新帮主
        clans[clan]["master"] = new_master;
        return 1;
}

// 将 clan 帮派的 what 设定成 value, 这个可能对 array 不太好处理
mixed clan_set(string clan, string what, mixed value)
{
        if( undefinedp(clans[clan]) )
                return notify_fail("没有这个帮派。\n");
        clans[clan][what] = value;
        return value;
}

// 传回 clan 帮派的 what 值
// 增加可以传回阶级人数 by chan
mixed clan_query( string clan, string what )
{
        if(clan && what)
        return clans[clan][what];
        else
        return 0;
}

void dest_clan( string clan_id )
{
        map_delete( clans, clan_id );
        save();
}

// 传回该玩家帮派的目录所在
string get_clan_dir( object me )
{
        if( me->query("clan/id") )
                        return CLAN_HOME + me->query("clan/id") + "/";
        return "";
}

//传回玩家目前待在哪一帮派的地盘上 by ACKY
string what_clan_area(object me)
{
        int i;
        string path;
        path = file_name(environment(me));
        if( path[0..10]=="/open/clan/" )        {
                i = 11;
                while( i++ )
                        if( path[i] == '/' )
                                return path[11..i-1];
        }
        return "NULL";
}

// 确定该玩家所在的房间是他帮派所属的, return 1 是该玩家的帮派房间
int is_clan_room(object me)
{
        int i;
        string file,roomdir;
        roomdir=get_clan_dir(me)+"room/";

        file    = file_name(environment(me));
        i       = strlen(file);

        while(i--)
                if( file[i] == '/' )
                        break;

        if( file[0..i] == roomdir)
                return 1;
        return 0;
}

// 检查是否有此帮派 by ACKY
// 有 -> return 1
// 无 -> return 0
int have_clan( string clan_id )
{
        mixed *file;
        file = get_dir("/open/clan/"+clan_id+"/", -1);
        if( !sizeof(file) )
                return 0;
        if( clan_id == "area" || clan_id == "std" )
                return 0;
        return 1;
}

// 检查玩家 id 是否是 clan 帮派的一员, 是就传回 1,
// 如果没 flag 或 flag = 0, 则非帮众传回 0
// 如果有 flag 或 flag != 0, 非帮众则加入该帮派的 members
// return -1 : 如果没有这个帮派的资料
int is_member_or_add(string clan, string id, int flag)
{
        string *member_list;

        if( undefinedp(clans[clan]) )
                return -1;
        if( !flag )
                return 0;

        if( undefinedp(clans[clan]["members"]) )
                clans[clan]["members"] = ({ id });
        else
                clans[clan]["members"] += ({ id });
        return 1;
}

int clan_data( object me, string clan_name ) //传回帮派资料 by ACKY
{
        string *clan_id, *clan_data, clan_str;
        int o, sum;
        clan_id = sort_array( CLAN_D->query_all_clan(), "sort_keys", this_object() );
        sum = sizeof( clan_id );
        clan_str = sprintf("目前FS有%d个帮派 -\n", sum );
        for( o=0; o<sum; o++ )
                clan_str += sprintf("[%s] ", clan_id[o] );
        clan_str += "\n";
        me->start_more( clan_str );
        clan_str = sprintf("[%s]", clan_name );
        clan_data = sort_array( keys( clans[clan_name] ), "sort_keys", this_object() );
        sum = sizeof( clan_data );
        for( o=0; o<sum; o++)
                clan_str += sprintf("[%s] %-26O\n", clan_data[o], clans[clan_name][clan_data[o]] );
        me->start_more( clan_str );
        return 1;
}

int sort_keys( string key1, string key2 ) //排列资料 by ACKY
{
  return strcmp( key1, key2 );
}

string *query_all_clan() //传回帮派资料的关键字 by ACKY
{
        return keys(clans);
}

mapping query_all_clans() //传回帮派全部资料 by ACKY
{
        return clans;
}
// 传回档案的最大数字....帮weapon,eq,npc设计的...
// 因为如果没有的话,删掉eq时会乱掉....by acky...
// path:帮派的目录...
// type: "weapon/","armor/","npc/",这三类。..
// name: 就是档名..like unarmed24,finger23
// by avgirl
int check_last_num(string path,string type,string name)
{
mixed *file;
int i, j;
mixed k=({});
// 取得档案
        file = get_dir(path+type+name+"*", -1);
        if(!sizeof(file)) return 0;
// 把所有的数字粹取出来
        for(i=0;i<sizeof(file);i++){
if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("物件:%s\n",file[i][0]));
        sscanf(file[i][0],name+"-%d.c",j);
// 把数字加进k 中,会行成k=({1,2,3,4,......})
        k += ({j});
        }
if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("数字:%O\n",k));
// 把最后一个数值传会去...
 if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("数字:%d\n",sort_array(k,1)[sizeof(k)-1]));
        return sort_array(k,1)[sizeof(k)-1];
}
// 制作任务用item...
// by avgirl...
int list_item(object me )
{
        string *files,list,temp,dir,str,number,err;
        int i,k;

        files = get_dir(get_clan_dir(me) + "item/*.c");
        i = sizeof(files);

                if(i==0) {
                list = sprintf("帮内目前没有任何任务用物品。\n");
                write(list);
                return 1;
        }
        list = sprintf("帮内目前有%s个任务用物品：\n",CHINESE_D->chinese_number(i));
        write(list);
        for(k=1; k<i+1; k++ ) {
                number=sprintf("%d",k);
                temp = get_clan_dir(me)+"item/item-"+number+".c";
                if(file_size(temp) == -1)       {
                        str="摧毁的物品";
                       i++;
                }
                else {
                  err = catch(temp->query("name"));
                        if(!err)  str=temp->query("name");
                        else str="[1;31m损坏的物品[0m";
                }
                printf("[%2d]%-20s%s", k, str, (k%2 ? "" : "\n") );
        }
    write("\n");
    return 1;
}
