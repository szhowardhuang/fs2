//by sueplan -������3
//���lotch����ץplan
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
int done=0;


void create() {
        set_name("˾ͽ���w",({"scholar yea","yea","scholar"}));   
        set("class","scholar");
        set("nickname","$HIC$�˳���$NOR$");
        set("title","����֮��");
        set("long",
        "\n��Ϊ������������˾ͽ����֮ʦ�����˼�ʹ��
����������˾ͽһ�ҹ��Ե����ſ��Ϸ���֮����
��·��֮���ŷ��Ƚ���\n");
        set("inquiry", ([
"��·" : "��ʦ��·Ϊ��һ��֮��ʦ, �������۵�, �û���, ����֮�ơ�����֪ŷ��һ��֮��ı!!",
        ]));
        set("str",40);
        set("cor",25);
        set("gender","����");
        set("attitude","heroism");
        set("family/family_name","����");
        set("quests/lotch","1");
        set("max_gin",15000);
        set("max_kee",12000);
        set("max_sen",15000);
        set("max_force",8000);
        set("age",93);
        set("force",8000);
        set("force_factor",20);
        set("combat_exp",8000000);
        set_skill("dodge",150);
        set_skill("stabber",150);
        set_skill("move",120);
        set_skill("parry",120);
        set("score",9000000);
        set_skill("knowpen",100);
        set_skill("god-plan",100);
        set_skill("plan",120);
        set_skill("force",200);
        set_skill("poetforce",150);
        set_skill("winter-steps",100);
        map_skill("plan","god-plan");
        map_skill("dodge","winter-steps");
        map_skill("move","winter-steps");
        map_skill("stabber","knowpen");
        map_skill("force","poetforce");
        map_skill("parry","knowpen");
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);

        set("functions/movedown/level",100);
        set("functions/finger/level",100);
set("chat_chance_combat", 100);
set("chat_msg_combat",({
(: perform_action("stabber.movedown") :),
(: perform_action("stabber.finger") :),
(: perform_action("plan.ghost") :),
(: perform_action("plan.false") :),
(: perform_action("plan.lock-link") :),
}));
        set("chat_chance",50);
        set("chat_msg",({
        }));
setup();
     carry_object("/open/scholar/room/newplan/obj/test");
          carry_object("/open/scholar/room/newplan/obj/pen")->wield();
        add_money("gold",50);
 }
void init()
{
add_action("do_action","",1);
        set_heart_beat(1);
}
int do_action(string str)
  {
        object who=this_player();
        if(str)
        {
        if(strsrch(str,"plan.speed")!=-1)
        {
          command("say �޴�ѽ!!�ѵ��㲻֪����Ϯ֮��������������?!\n");
          write("\n���˾ͽ���w��̬����, ���ƽ�����ǰ�ļ�ı!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.hole")!=-1)
        {
          command("say ��������ǰ������??����Ū����С������!!\n");
          write("\n���˾ͽ���w��̬����, ���ƽ�����ǰ�ļ�ı!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.rob")!=-1)
        {
          command("say �û���?!�޴�!!�ѵ��㲻֪���˼�Ϊ��������??\n");
          write("\n���˾ͽ���w��̬����, ���ƽ�����ǰ�ļ�ı!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.false")!=-1)
        {
          command("say ���֮����������ļ�ı, �һ��в���֮��??\n");
          write("\n���˾ͽ���w��̬����, ���ƽ�����ǰ�ļ�ı!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"lock-link")!=-1)
        {
          command("say �����������о��ķ����ɱ��������!!�Ҷ�����?\n");
          write("\n���˾ͽ���w��̬����, ���ƽ�����ǰ�ļ�ı!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.ghost")!=-1)
        {
          command("say �۵�??�ҿɲ��᱿�����ֵز��!!\n");
          write("\n���˾ͽ���w��̬����, ���ƽ�����ǰ�ļ�ı!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        }
return 0;
}
int accept_kill(object who,object me)
{
        who=this_player();
        me=this_object();
        command("wield pen");
        command("say �޴�!!����Ϊ�һ�һ���˶Ը�����?");
        command("kill "+who->query("id"));
        command("use lotch");
        command("use lotch");
        command("use lotch");
        command("use lotch");
        command("use lotch");
        me->add("sen",200);
        command("perform stabber.movedown");
        return 1;
}
int accept_fight(object who)
{
        who=this_player();
        command("say ������Һ��ҽ���, �Ǿͱ����������!!");
          return 0;
}

void heart_beat()
{
        object ob=this_object();
        if( is_fighting() ){
        if( random(20) < 5 )
        {
message_vision(HIC"\n˾ͽ���w�������š�������Ȼ��������ɢ�������Ϲ⡣\n"NOR,ob);
          ob->delete_busy();
          ob->add("kee",500);
          ob->add("force",500);
          ob->receive_heal("sen",100);
          ob->receive_heal("gin",100);
        }
        }
        :: heart_beat();
}
void die()
{
object winner = query_temp("last_damage_from");
winner->set_temp("ko_yea",1);
:: die();
}