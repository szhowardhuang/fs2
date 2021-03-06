#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
  object obj;
  int i,done,flag;
  if (!str)                         //不加参数时为查询
  {
    if (!sizeof(me->query_temp("defend"))&&!sizeof(me->query_temp("defend_by"))) 
    {
      write("你现在没有保护任何人\n");
      return 1;
    }
    if ( !sizeof(me->query_temp("defend_by")) )
    {  
      write("你现在掩护着：\n");
      for(i=0;i < sizeof(me->query_temp("defend"));i++)
      {                        //先滤掉己经不存在的人,如己经离线者
                               //或是己经被做了的NPC
                               //实际上这个应该写成函数的因为这在程式中
                               //时常出现，几乎只要下defend命令就会先过滤
                               //一次，不过因为当初写的时侯没注意到所以
                               //在程式中有好几个类似这样的过滤程式
                               //不过功能都一样
        if(!find_living(me->query_temp("defend/"+(string)i)))
        {
          me->set_temp("defend/"+(string)i,
          me->query_temp("defend/"+(string)(sizeof(me->query_temp("defend"))-1)));
          me->delete_temp("defend/"+(string)(sizeof(me->query_temp("defend"))-1));
          i--;                
        }       
      }
      for (i=0;i < sizeof(me->query_temp("defend"));i++) 
        write((me->query_temp("defend/"+(string)i))+"\n"); 
      return 1;
    }
    else
    {
      write("现在掩护你的人有：\n");
      for(i=0;i < sizeof(me->query_temp("defend_by"));i++)
      {                               //过滤程式
        if(!find_living(me->query_temp("defend_by/"+(string)i)))
        {
          me->set_temp("defend_by/"+(string)i,
          me->query_temp("defend_by/"+(string)(sizeof(me->query_temp("defend_by"))-1)));
          me->delete_temp("defend_by/"+(string)(sizeof(me->query_temp("defend_by"))-1));
          i--;                
        }       
      }
      for (i=0;i < sizeof(me->query_temp("defend_by"));i++) 
        write((me->query_temp("defend_by/"+(string)i))+"\n");
      return 1;
    }   
  }
           //以下为判断是否为有效的保护关系.
           //保护关系成立的基本设定:
           //1.保护者与被保护者必需同时在场且均active
           //2.被保护者不能是自己或是非生物
           //3.保护关系只能有两层，意即如果自己已经被保护则不能再保护他人
           //  而且也不能保护已经保护他人的使用者
           //4.死亡后保护关系自动解除
  if (!objectp(obj = present(lower_case(str), environment(me))))
    return notify_fail("这里没这个人。\n");
  str = lower_case(str);
  if( !obj->is_character() )
    return notify_fail("那不是生物不需要掩护。\n");
  if(obj==me) return notify_fail("要保护自己就赶快练功吧^_^.\n");
  if(1 || userp(obj)) 
  {
    if (sizeof(me->query_temp("defend_by"))) 
      return notify_fail("你自己都被人保护了还想保护别人？\n");
    if (sizeof(obj->query_temp("defend")))
      return notify_fail("他似乎不需要你的保护。\n");
    for(i=0;i < sizeof(me->query_temp("defend"));i++)
    {
      if(str == me->query_temp("defend/"+(string)i)) done++;
      if(!find_living(me->query_temp("defend/"+(string)i)))
      {                      //过滤程式
        me->set_temp("defend/"+(string)i,
        me->query_temp("defend/"+(string)(sizeof(me->query_temp("defend"))-1)));
        me->delete_temp("defend/"+(string)(sizeof(me->query_temp("defend"))-1));
        i--;                
      }
    }
    if (!done) me->set_temp("defend/"+(string)i,str);
    else flag=1;
    for(i=0,done=0;i < sizeof(obj->query_temp("defend_by"));i++)
    {
      if(me->query("id") == obj->query_temp("defend_by/"+(string)i)) done++;    
      if(!find_living(obj->query_temp("defend_by/"+(string)i)))
      {                      //过滤程式
        obj->set_temp("defend_by/"+(string)i,
        obj->query_temp("defend_by/"+(string)(sizeof(obj->query_temp("defend_by"))-1)));
        obj->delete_temp("defend_by/"+(string)(sizeof(obj->query_temp("defend_by"))-1));
        i--;                
      }       
    }
    if (done && flag) return notify_fail("你己经在保护他了不是吗？\n"); 
    if (!done) obj->set_temp("defend_by/"+(string)i,me->query("id"));
    message_vision("\n$N移动到$n前面掩护$p。\n", me, obj ,obj);
  }
  return 1;
}

int help(object me)
{
  write(@HELP
  指令格式 : defend <人物>
  
      这个指令让你在战斗中掩护他人，掩护的效果决定于你的胆识(cor)与
  基本拆招卸力(parry)的技巧。当掩护成功的时，所有对于被掩护者的攻击
  都将转嫁到你身上。在战斗中掩护他人时，你的闪躲空间将会受到大幅的影
  响，阻挡的能力也有些许的限制。所以如果你的技巧不够成熟而强行硬挡的
  话，将可能使自己在战斗中陷入险境。不过老练的武者却常以保护他人来训
  练自己，在艰难战斗中获得更多的实战经验。
      另外，defend只能掩护战术上的攻击。对于战略上的攻击：如咒语，法
  术，特殊招式......等等效果不彰。
  
  其他相关指令: undefend
  
HELP);
  return 1;
}
              