// made by ccat
// ����,����������call һ�����ι��޵�ȱ��,ʹ�õı���Ҳ��Ϊ��.

#include <ansi.h>
#include <armor.h>
inherit EQUIP;
inherit SSERVER;
object user;
int kar;
void create()
{
     set_name( "��ѩ���",({"ice_ring"}) );
     set_weight(2500);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","һֻ���ڱ�������������ʯָ��,��˸�Ź��������.\n");
            set("unit", "��");             
            set("value",5000);
            set("material","steal");
            set("no_sell", 1);         //��Ȼ�͵ö��� action sell
            set("armor_type","finger");            
            set("armor_prop/armor",7);
           }         
        setup();
}

void init()
{
     add_action("do_drop","drop"); 
     add_action("do_auc","auc"); 
     add_action("do_wear","wear");
     add_action("do_give","give");
     add_action("do_remove","remove");
}

int do_wear(string str)
{ 

     ::wear(); 
     if ( query("equipped") ) 
     {
        user = this_player();     // ȡ��ʹ����
        kar = user->query("kar");
        message_vision("$N�����˱�ѩ���,���������˵�������.\n",user);
        set_heart_beat(1);
     } 
}
int do_drop(string str)
{  
   if (str=="ice_ring" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N�����˱�ѩ���,��ѩ������������Ҳ��֮����.\n",user);
        set_heart_beat(0);
     }    
}
int do_give(string str)
{  
  if (str=="ice_ring" || str=="all")
     if( query("equipped") )
     { 
        message_vision("$N�����˱�ѩ���,��ѩ������������Ҳ��֮����.\n",user); 
        set_heart_beat(0);
     }
}
int do_remove(string str)
{
   if (str=="ice_ring" || str=="all")
     if( query("equipped") )
     {
        if(user)
        message_vision("$N�����˱�ѩ���,��ѩ������������Ҳ��֮����.\n",user);
        set_heart_beat(0);
     }
}                       
int do_auc(string str)
{
  if (str=="ice_ring" || str=="all")
     if( query("equipped") )
     { 
        message_vision("$N�����˱�ѩ���,��ѩ������������Ҳ��֮����.\n",user);
        set_heart_beat(0);
     }
}     
void heart_beat()
{
  object *enemy,who,target;
  int i,dodge;

  if( !objectp(user) ) 
  { set_heart_beat(0);
     return;
  }
  if( user->is_fighting() && query("equipped") )
  {
    if( random(kar+70) > 70)  // ������,���ʸ�
    {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
      target=offensive_target(user);
      if(!target){
        return ;
      }
     dodge = target->query_skill("dodge");
     if( random(180) > dodge) 
     {
      message_vision(HIC+"һ�󺮷��Ա�ѩ������,˲���$N������!!!\n"+NOR,target);
      target->start_busy(2);
     }else{
message_vision(HIC+"һ�󺮷��Ա�ѩ������,����$N���һ��\,�����ȥ...\n"+NOR,target);
     }
    }
  }
  return;
}
