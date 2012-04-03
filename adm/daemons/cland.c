// cland.c
//
//      ÎÒµÄ½¨ÒéÊÇÓÃ save() & restore() µÄ·½·¨, ½«ËùÓĞ°ïÅÉµÄ×ÊÁÏ
//      ´æÔÚ query_save_file() ÄÇ
//
//                                                      Created by Arthur
//
//      ÈçÒª·ÀÖ¹Î×Ê¦´Ü¸Ä×ÊÁÏ, ¿ÉÒÔÔÚÒª·ÀÖ¹µÄµØ·½¼ÓÉÏ, ÈôÏŞ¶¨Ö»ÓĞ ROOT_UID ¿ÉÒÔ¸Ä
//      if( previous_object() && geteuid(previous_object()) != ROOT_UID )
//              return;
// 1999 05/09 ÎªÁËĞÂµÄÏµÍ³ÖØĞÂ¸ÄĞ´                      By  Chan

#include <clan.h>

inherit F_SAVE;

int check_last_num(string,string,string);

mapping clans;
                        // Ä¿Ç°ÊÇÔİ¶¨ÕâĞ©¶«Î÷, ¿ÉÒÔ×ÔĞĞ¶ÔÕÕ, ÈçÓĞ¼ÓĞÂµÄ,
                        // Ò²Çë¼ÓÔÚÏÂÃæ, ÕâÑù±È½ÏºÃÀí½â
                        // clans["°ïÅÉµÄ id"] = ([
                        //      "gold"          : Ç®,
                        //      "members"       : ({ °ïÖÚ id µÄ array }),
                        //      "master"        : °ïÖ÷µÄ id,
                        //      "name"          : °ïÅÉÃû³Æ,
                        //      "level2"        : ({ array }),
                        //      "level3"        : ({ array }),
                        //      "level4"        : ({ array }),
                        //      "home"          : °ïÅÉµÄ¼Ò,
                        //      "develop"       : °ïÅÉÈË²Ä·¢Õ¹×´¿ö,
                        //      "weapon"        : °ïÅÉÎäÆ÷·¢Õ¹×´¿ö,
                        //      "war"           : °ïÅÉÕ½Õù×´Ì¬,
                        //      "tax"           : Ë°ÂÊ
                        //      "alert"         : ¾¯½ä¡¢±¸Õ½×´Ì¬
                        //      "ally"          : Í¬ÃË,
                        //      ]);

string *LEVEL   = ({ "level2", "level3", "level4" });

mapping query_clans()   { return clans; }
string query_save_file() { return DATA_DIR + "clan"; }

// ÓÃÀ´¼Ó¼õ clan µÄÇ®
int add_money(string clan_id, int num)
{

       if( !mapp(clans[clan_id]) )
                return notify_fail("Ã»ÓĞÕâ¸ö°ïÅÉ¡£\n");
        clans[clan_id]["gold"] += num;
        return num;
}

// ÓÃÀ´¼Ó¼õÄ³Öµ by Chan
int add_clanset(string clan_id,string what,int num)
{
        if( !mapp(clans[clan_id]) )
                return notify_fail("Ã»ÓĞÕâ¸ö°ïÅÉ¡£\n");
        clans[clan_id][what] += num;
        return num;
}

// ´´ĞÂµÄ clan, master ÊÇ°ïÖ÷ id,
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
        // ËÍËûÒ»¼ä·¿¼äµ±¿ª°ï¼ÍÄî
        assure_file( clans[clan_id]["home"] );
        CLAN_CMDS("c_room_make")->create_room(clans[clan_id]["home"]);
//½¨Á¢npcµÄÄ¿Â¼
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
        // Éè¶¨Ã¿¸ö level µÄÈËÊıÉÏÏŞ, ÔÚÕâ±ßÉè¶¨²Å¿ÉÒÔ¸ü¸Ä
        if( !mapp(clans) )
                clans = ([]);
        clans["limit"] = ([
                "level2" : LEVEL2_NUM,
                "level3" : LEVEL3_NUM,
                "level4" : LEVEL4_NUM,
        ]);
}

// °ïÅÉÎ»½×Éı½µ, Öğ³ö°ïÖÚ, return 0 ±íÊ¾¶îÂú»òÃ»¸ÃÎ»½×
int clan_promote( string clan, string id, string level, int money )
{
        int i;
        if( !undefinedp(clans["limit"][level]) && sizeof(clans[clan][level]) > clans["limit"][level] -1 ) // È·¶¨Î»½×
                return 0;
        i = sizeof(LEVEL); // ÇåµôÔ­ÏÈµÄÎ»½×
        while(i--)      {
                if( member_array( id, clans[clan][LEVEL[i]]) == -1 )
                        continue;
                clans[clan][LEVEL[i]] -= ({ id });
                break;
        }
        if( level == "banish" ) { // ½« id Öğ³ö°ïÅÉ
                clans[clan]["members"] -= ({ id });
                clans[clan]["member_gold"] -= money;
                return 1;
        }
        if( !undefinedp(clans["limit"][level]) ) // level(2~4)
                if( undefinedp(clans[clan][level]) ) // ¼ÓÈë¸Ã level
                        clans[clan][level] = ({ id });
                else
                        clans[clan][level] += ({ id });
        save();
        return 1;
}

int change_clan_master(string clan, string new_master)
{
        // ÏÈ½«ĞÂ°ïÖ÷µÄ¾ÉÎ»Ö·È¥µô
        clan_promote(clan, new_master, "",0);
        // Éè¶¨ĞÂ°ïÖ÷
        clans[clan]["master"] = new_master;
        return 1;
}

// ½« clan °ïÅÉµÄ what Éè¶¨³É value, Õâ¸ö¿ÉÄÜ¶Ô array ²»Ì«ºÃ´¦Àí
mixed clan_set(string clan, string what, mixed value)
{
        if( undefinedp(clans[clan]) )
                return notify_fail("Ã»ÓĞÕâ¸ö°ïÅÉ¡£\n");
        clans[clan][what] = value;
        return value;
}

// ´«»Ø clan °ïÅÉµÄ what Öµ
// Ôö¼Ó¿ÉÒÔ´«»Ø½×¼¶ÈËÊı by chan
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

// ´«»Ø¸ÃÍæ¼Ò°ïÅÉµÄÄ¿Â¼ËùÔÚ
string get_clan_dir( object me )
{
        if( me->query("clan/id") )
                        return CLAN_HOME + me->query("clan/id") + "/";
        return "";
}

//´«»ØÍæ¼ÒÄ¿Ç°´ıÔÚÄÄÒ»°ïÅÉµÄµØÅÌÉÏ by ACKY
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

// È·¶¨¸ÃÍæ¼ÒËùÔÚµÄ·¿¼äÊÇËû°ïÅÉËùÊôµÄ, return 1 ÊÇ¸ÃÍæ¼ÒµÄ°ïÅÉ·¿¼ä
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

// ¼ì²éÊÇ·ñÓĞ´Ë°ïÅÉ by ACKY
// ÓĞ -> return 1
// ÎŞ -> return 0
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

// ¼ì²éÍæ¼Ò id ÊÇ·ñÊÇ clan °ïÅÉµÄÒ»Ô±, ÊÇ¾Í´«»Ø 1,
// Èç¹ûÃ» flag »ò flag = 0, Ôò·Ç°ïÖÚ´«»Ø 0
// Èç¹ûÓĞ flag »ò flag != 0, ·Ç°ïÖÚÔò¼ÓÈë¸Ã°ïÅÉµÄ members
// return -1 : Èç¹ûÃ»ÓĞÕâ¸ö°ïÅÉµÄ×ÊÁÏ
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

int clan_data( object me, string clan_name ) //´«»Ø°ïÅÉ×ÊÁÏ by ACKY
{
        string *clan_id, *clan_data, clan_str;
        int o, sum;
        clan_id = sort_array( CLAN_D->query_all_clan(), "sort_keys", this_object() );
        sum = sizeof( clan_id );
        clan_str = sprintf("Ä¿Ç°FSÓĞ%d¸ö°ïÅÉ -\n", sum );
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

int sort_keys( string key1, string key2 ) //ÅÅÁĞ×ÊÁÏ by ACKY
{
  return strcmp( key1, key2 );
}

string *query_all_clan() //´«»Ø°ïÅÉ×ÊÁÏµÄ¹Ø¼ü×Ö by ACKY
{
        return keys(clans);
}

mapping query_all_clans() //´«»Ø°ïÅÉÈ«²¿×ÊÁÏ by ACKY
{
        return clans;
}
// ´«»Øµµ°¸µÄ×î´óÊı×Ö....°ïweapon,eq,npcÉè¼ÆµÄ...
// ÒòÎªÈç¹ûÃ»ÓĞµÄ»°,É¾µôeqÊ±»áÂÒµô....by acky...
// path:°ïÅÉµÄÄ¿Â¼...
// type: "weapon/","armor/","npc/",ÕâÈıÀà¡£..
// name: ¾ÍÊÇµµÃû..like unarmed24,finger23
// by avgirl
int check_last_num(string path,string type,string name)
{
mixed *file;
int i, j;
mixed k=({});
// È¡µÃµµ°¸
        file = get_dir(path+type+name+"*", -1);
        if(!sizeof(file)) return 0;
// °ÑËùÓĞµÄÊı×Ö´âÈ¡³öÀ´
        for(i=0;i<sizeof(file);i++){
if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("Îï¼ş:%s\n",file[i][0]));
        sscanf(file[i][0],name+"-%d.c",j);
// °ÑÊı×Ö¼Ó½øk ÖĞ,»áĞĞ³Ék=({1,2,3,4,......})
        k += ({j});
        }
if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("Êı×Ö:%O\n",k));
// °Ñ×îºóÒ»¸öÊıÖµ´«»áÈ¥...
 if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("Êı×Ö:%d\n",sort_array(k,1)[sizeof(k)-1]));
        return sort_array(k,1)[sizeof(k)-1];
}
// ÖÆ×÷ÈÎÎñÓÃitem...
// by avgirl...
int list_item(object me )
{
        string *files,list,temp,dir,str,number,err;
        int i,k;

        files = get_dir(get_clan_dir(me) + "item/*.c");
        i = sizeof(files);

                if(i==0) {
                list = sprintf("°ïÄÚÄ¿Ç°Ã»ÓĞÈÎºÎÈÎÎñÓÃÎïÆ·¡£\n");
                write(list);
                return 1;
        }
        list = sprintf("°ïÄÚÄ¿Ç°ÓĞ%s¸öÈÎÎñÓÃÎïÆ·£º\n",CHINESE_D->chinese_number(i));
        write(list);
        for(k=1; k<i+1; k++ ) {
                number=sprintf("%d",k);
                temp = get_clan_dir(me)+"item/item-"+number+".c";
                if(file_size(temp) == -1)       {
                        str="´İ»ÙµÄÎïÆ·";
                       i++;
                }
                else {
                  err = catch(temp->query("name"));
                        if(!err)  str=temp->query("name");
                        else str="[1;31mËğ»µµÄÎïÆ·[0m";
                }
                printf("[%2d]%-20s%s", k, str, (k%2 ? "" : "\n") );
        }
    write("\n");
    return 1;
}
