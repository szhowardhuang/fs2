
// by airke
#include <ansi.h>
inherit F_SPELL;

void create() { seteuid(getuid());}
int conjure(object me, object target)
{
  object light;
  if( !me->query_spell("lightfire") )
       return 0;
  if( me->query("atman") < 3 )
       return notify_fail ("你的法力不足!!\n");
  me->add("atman",-3);
  light = new("/daemon/class/taoist/gmagic/obj/lightfire");
  light->move(me);
  message_vision ("$N两指一比，造出了一枚星光之火飘在空中。\n",me);
  return 1;
}

