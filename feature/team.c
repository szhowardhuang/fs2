// team.c
// 改写过  follow 的部份, 应该比较快速一点
// rewrited by wade in 1/4/1996
// 把 gage 写在这儿

#include <command.h>
#include <dbase.h>
#include <origin.h>

static object leader, *team;
static string *gage=({});

int set_leader(object ob)
{
  if( ob==this_object() )
    error("set_leader: "+ob->short()+"企图设自己为 leader.\n");
  leader = ob;
}

object query_leader() { return leader; }

int follow_me(object ob, string dir)
{
  object	me=this_object();

  // 死人是不会走路的, 当然, 自己也不必跟着自己走, 否则会陷入无穷回圈
  // 被 gage 的人也不会跟来, 以免  pker 利用 follow K 玩家
  if ( !living(me) || ob==me || ob->gage(me))
  {
    return 0;
  }

  // 假如是 leader 走路, 我们应该是马上跟着走的
  if (ob == leader)
    return GO_CMD->main(me, dir);

  return 0;
}

int add_team_member(object ob)
{
  if( ob==this_object() ) return 0;

  if( arrayp(team) ) {
    if( member_array(ob, team)==-1 ) {
      team += ({ ob });
      for(int i=sizeof(team)-1; i>=0; i--)
        team[i]->set_team(team);
    } else
      return 0;
  } else {
    team = ({ this_object(), ob });
    ob->set_team(team);
  }
  return 1;
}

int is_team_leader()
{
  return arrayp(team) && team[0]==this_object();
}

int set_team(object *t)
{
  team = t;
}

varargs int dismiss_team(object ob)
{
  int i;

  if( !arrayp(team) ) return 0;
  
  if( !ob ) {
    if( team[0]==this_object() ) {
      for(i=1; i<sizeof(team); i++)
	if( team[i] )
        team[i]->set_team(0);
    } else {
      for(i=0; i<sizeof(team); i++)
        if(team[i])
        team[i]->dismiss_team( this_object() );
    }
    team = 0;
  } else
    team -= ({ ob });

  return 1;
}

object *query_team()
{
  return team;
}

int add_gage(mixed ob)
{
  string	uid;

  if (objectp(ob)) uid = getuid(ob);
  else if (stringp(ob)) uid = ob;
  else return 0;

  gage += ({ uid });
  return 1;
}

int delete_gage(mixed ob)
{
  string	uid;

  if (objectp(ob)) uid = getuid(ob);
  else if (stringp(ob)) uid = ob;
  else return 0;

  if (gage != ({}) && member_array(uid, gage) != -1) {
    gage -= ({ uid });
    return 1;
  }
  else
    return 0;
}

string *query_gage()
{
  return gage;
}

int gage(mixed ob)
{
  string	uid;

  if (!ob) return 0;
  if( !interactive(ob) ) return 0;
  else if (objectp(ob)) uid = getuid(ob);
  else if (stringp(ob)) uid = ob;
  else return 0;
  
  if (gage != ({}) && member_array(uid, gage) != -1)
    return 1;
  else
    return 0;
}
