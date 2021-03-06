//setquests.c

inherit F_SAVE;

mapping quests_list = ([ ]);
mapping quest_long = ([ ]);

void create() {seteuid(getuid());}
int main(object me, string arg)
{
	if( !arg )
	  return notify_fail("使用格式：delquests 中文任务名\n");

	restore();

	map_delete (quests_list, arg);
	map_delete (quest_long, arg);
	save();

	log_file ("quests", sprintf("%s删除任务 %s 于%s\n",
	  me->short(), arg, CHINESE_D->chinese_time(time()))
	);

	return 1;
}

string query_save_file()
{ return "/data/questlist" ; }
