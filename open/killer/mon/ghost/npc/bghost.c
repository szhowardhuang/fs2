#include <ansi.h>

//inherit F_GUILDCMDS;
inherit NPC;

object ghost= this_object();

void do_meeting( object me)
{
   string str;
   object where;
   if( !me->query_temp("ghost") && me->query("class") == "killer" && !ghost->query_temp("followed"))
   {
      message_vision("[1;37m只见眼前白光一闪, 一道烟雾似慢实快的钻进了$N体内。\n[0m", me);
      command("say 带我去找绿云组长周八伯申冤吧...");
      command("follow "+ me->query("id"));
      ghost->set_temp("followed", me);
      me->set_temp("ghost", 1);
   }
   // 假如有 follow 但是那个人又不在的话...
   else if( ghost->query_temp("followed") && !present( (ghost->query_temp("followed"))->query("id"), environment( ghost)))
   {
      where= environment( ghost->query_temp("followed"));
      str=file_name( where);
      ghost->move( str);
   }
   return;
}
void create()
{
        object ob;
        set_name("任盈盈",({"ljen"}));
        set("long","一位退隐江湖的杀手, 现在则成了一位美丽的女鬼。\n");
        set("gender","女性");
        set("combat_exp",300000);
        set("attitude","heroism");
        set("age",18);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("per", 30);
        set("spi", 30);
        set("int", 30);
        set("force", 2000);
        set("max_force", 2000);
        set("kee", 1000);
        set("max_kee", 1000);
        set("force_factor",10);

        set_skill("move",60);
        set_skill("force",70);
        set_skill("dodge",80);
        set_skill("parry",60);
        set_skill("throwing",70);

        set_skill("blackforce",60);
        set_skill("ghost-steps",70);
        set_skill("rain-throwing",70);

        map_skill("force","blackforce");
        map_skill("dodge","ghost-steps");
        map_skill("throwing", "rain-throwing");

        set_temp("invis",1);

        set("chat_chance", 8);
        set("chat_msg", ({
"任盈盈说道:「我死的好惨ㄚ....”\n",
"任盈盈说道:「只有周八伯才能替我申冤。”\n",
"任盈盈说道:「谁能帮我报仇...”\n",
"任盈盈说道:「难道说人长的美丽也是一种错误吗?”\n",
"任盈盈说道:「谁能帮我报得大仇的, 我愿意以身相许...”\n",
        }));

        setup();
        ob=carry_object("/open/killer/obj/hate_knife");
        ob->set_amount(200);
        ob->wield();
}

void init ()
{
   object me= this_player();
   if( !me->query_temp("ghost"))
      call_out("do_meeting",1,me);
   add_action("do_waveto", "waveto");
   add_action("do_waveto", "wa");
}

int do_waveto(string arg)
{ 
    mixed count;
    int money,i,gmove;
    object me,roomm;
    object ghost;
    string room="";
    me = this_player();
    ghost= this_object();
    if( me->query_temp("unconcious") )          return 0;
    if( me->is_fighting() )
        return notify_fail("战斗中无法使用唤云扇。\n");
    if( me->query_temp("抢劫中") )
        return notify_fail("抢劫中无法使用唤云扇。\n");
    if( environment(me)->query("no_transmit") )
    {
       write("突然一阵能量从地底发出,击散了你招来的云朵,\n");
       write("似乎这里的大神不愿此地可以传送...\n");
       return 1;
    }  
    money = me->query("bank/coin");
    if( money < 500)
    {
       write(" 唤云扇说: 你的存款不足,无法支付费用.\n");
       return 1;
    }
    message_vision( HIB+"只见天上降下一朵云陇罩着$N\n"+NOR ,me);   
    switch(arg)
    {
       case "1":
         room="/open/capital/room/r70";         break;
       case "2":
         room="/open/gsword/room/su3";          break;
       case "3":
         room="/open/ping/room/road4";          break;
       case "4":
         room="/open/center/room/inn";          break;
       case "5":
         room="/open/start/room/s5";            break;
       case "10":
         room="/open/port/room/r3-1";           break;   
       case "6":
         room = me->query("startroom");         break;
       case "7":
         room = me->query_temp("fan/7");        break;
       case "8":
         room = me->query_temp("fan/8");        break;
       case "9":
         room = me->query_temp("fan/9");        break;
       default:
     }
     gmove = me->query_temp("gmove");
     if( gmove )
     {
       roomm = environment(this_player());
     }

     // 检查 room 是否存在, gmove on|off 都得用,故放此
     if( !me->move(room) )
     {
        write(" 唤云扇说: 无此地点...\n");
        return 1;
     }
     else
        ghost->move( room);
     
   if( gmove )
   {
     count = all_inventory( roomm );
     for( i=0;i < sizeof( count ) ;i++)
     {
       if( count[i]->is_character() &&
       ( count[i]->query_temp("id") == me->query("id")
          || count[i]->query_leader() == me ) )
             count[i]->move(room);
     }
   }
     
/*    no_transmit 一定无法 fanset,故一定无法传送,此处多余 ...ccat...9_12.96 
      if( environment(me)->query("no_transmit") ) {
        message_vision(HIB+"突然一阵能量从地底发出,将$N的云朵弹走。\n"+NOR,me);
        me->move("/open/common/room/inn");
     }
     else
 */    
     if( gmove )
     {
        message_vision(HIB+"一阵清风过后,$N带领大家从天而降.\n"+NOR,me);
     }else
        message_vision(HIB+"一阵清风过后,$N从天而降.\n"+NOR,me);

     me->set("bank/coin",money-500);
     return 1;
}

