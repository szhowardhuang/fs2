
#include <command.h>
 
inherit NPC;
string ask_kylin()
{
    object who=this_player();
    if(who->query("marks/ʥ�������",1) && who->query_temp("can_pass"))
    {
    return("��..��..��..��..��..ˮ..��..��..��..��..��..��..��..��..��..��..\n");
    who->set_temp("ask_hurted",1);
    }
    else
    {
    return(" ��..��..��..��..��..��..��..��..��..��... \n");
    }
}

void create()
{
    set_name("����",({"hurter"}));
    set("title", "�����ڵ�");
    set("gender", "����");
    set("age",46);
    set("attitude","friendly");
    set("long",@LONG
	���ڵ��ϵ���λ����, ���˷ǳ������ض����Ѿ�����һϢ, ��Ȼ
	����Ҫ����, ����ȴ��֪����û���������..�������ϵ��·���
	��, ��Ӧ����ʥ��̵�������! ������ӡ����, �����ǹ�������
	������...........
LONG);
 
    set("combat_exp",32000);
    set("str",16);
    set("con",14);
    set("int",12);
    set("max_kee",50);
    set("kee",50);
    set("max_force",500);
    set("force",500);
    set("limbs",({"ͷ","��","��","��","��","��"}));
    set("chat_chance",30);
    set("chat_msg", ({
    "΢����������:...��.....��......��.......!!\n",
    "......��.......��........��..........!!\n", 
    }) );
    set("inquiry",([
    "��":"��������ŵ�ȭʦ, ��Ϊ����Ҫ��.����.��.��һ.��..��...��\n",
    "����":"��...��...��...ˮ...��..��...��..��...\n",
    "����":"��........Ѫ.......��.........��.........��...........\n",
    "Ѫ����":(: ask_kylin :),
 ]));
    setup();
}

int accept_fight(object who)
{
    return notify_fail("ֻ��������������������...........................");
}