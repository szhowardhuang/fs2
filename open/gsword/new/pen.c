#include <weapon.h>
#include <ansi.h>
inherit STABBER;
object ob;
object *target;
object ob1=this_object();
int sp_value;
int sp_hit;
void create()
{
        set_name("[1;34mÀöÓñµûÀ¼[0m",({"liyu_pen","pen"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long","Áé±ÊÀöÓñµûÀ¼ÓëÁé½£Á¬Ñô£¬ Áéµ¶Ò¹Ç§Äñ²¢³Æ¡¸¿ªÌìÈıÁéÆ÷¡±£¬±ÊÉí³ÊÁÁÀöµÄÀ¶É«£¬ËÆºõ´ú±í×ÅÎŞ±ÈµÄÖÇ»Û¡£");
        set("unit","¼ş");
        set("value", 1000);
        set("material","blacksteel");
        set("no_auc", 1);
	set("no_save",1);
        set("no_sell", 1);
        }
      init_stabber(80);
        setup();
}

void init()
{
     add_action("do_drop","drop");
     add_action("do_wield","wield");
     add_action("do_sps","sps");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}

int do_wield(string str)
{
    int max_sp_hit;
    max_sp_hit=350;
    ob=this_player();
    sp_value=(ob->query("spi")+ob->query("int"))*2+ob->query("bounds")/100+ ob->query("combat_exp")/1000;
    sp_hit=ob->query("MKS")/1000+random(80);
    if( sp_hit >max_sp_hit)
       sp_hit=max_sp_hit;
     ::wield();
{
    if(query("equipped"))
      message_vision("[1;36m$N°Î³öÀöÓñµûÀ¼£¬Ö»¼û[0m$N[1;36mÈ«ÉíÁıÕÖÔÚÀöÓñµûÀ¼µÄÀ¶¹âÀï[0m\n",this_player());
      set_heart_beat(1);
//    return 0;
}

}
int do_drop(string str)
{
    if(str == "liyu_pen" || str=="all")
    {
      set_heart_beat(0);
       message_vision("$N·ÅÏÂÀöÓñµûÀ¼ ,ÉíÉÏµÄÁéÆøÏûÊ§ÎŞ´æ.\n",this_player());
    }
}
int do_sps(string str)
{
 object user;
  user = this_player();   
  write("ÕÒËÀ...Á¬Õâ¸öÄãÒ²¸ÒÄÃÀ´·âÓ¡....\n");
  user->add("kee",-2000);
return 0;
  
}
int do_give(string str)
{
    if(str == "liyu_pen" || str=="all")
    {
      set_heart_beat(0);
       message_vision("$N·ÅÏÂÀöÓñµûÀ¼ ,ÉíÉÏµÄÁéÆøÏûÊ§ÎŞ´æ.\n",this_player());
     }
}
int do_unwield(string str)
{
    if(str == "liyu_pen" || str=="all")
    {
       set_heart_beat(0);

       message_vision("$N·ÅÏÂÀöÓñµûÀ¼ ,ÉíÉÏµÄÁéÆøÏûÊ§ÎŞ´æ.\n",this_player());
     }
}

void heart_beat()
{
  int *target,i;
  target=ob->query_enemy();
  i=random(sizeof(target));
  if( ob1->query("equipped") )
  if( ob->is_fighting() )
 if( sp_value > random(3000) && 40 > random(100) ) 

    {
     message_vision("[1;37mÀöÓñµûÀ¼»Ã»¯³ÉÎŞÊı»Ãµû£¬ÎŞÇéµÄÍÌÊÉ×Å[0m$N\n ",target[i]);
     target[i]->receive_damage("kee",sp_hit);
     COMBAT_D->report_status(target[i],0);
     }
  return;
 }


