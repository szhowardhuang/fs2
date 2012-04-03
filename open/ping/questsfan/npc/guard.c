//守卫  by dhk 2000.5.5
#include <ansi.h>
inherit NPC;
#include </open/open.h>
inherit F_MASTER;

void create()
{
        set_name("山庄守卫",({"leespace guard","guard"}));
        set("gender","男性");
        set("age",205);
        set("class","blademan");
        set("force_factor",15);
        set("long","宏禧山庄看门守卫武士 ,过滤闲杂人物进入宏禧山庄内。\n");
        set("combat_exp",3000000);
        set_skill("blade",100);
        set_skill("dodge",90);
        set_skill("parry",90);
        set_skill("gold-blade",100);
        set_skill("fast-blade",100);
        set_skill("fly-steps",900);
        set_skill("sixforce",100);
        map_skill("blade","fast-blade");
        map_skill("parry","gold-blade");
        map_skill("dodge","fly-steps");
        map_skill("move","fly-steps");
        map_skill("force","sixforce");
        setup();
        //carry_object("/open/gblade/obj/gold-boots")->wear();
        //carry_object("/open/gblade/obj/gold-robe")->wear();
        //carry_object("/open/gblade/obj/gold-armor")->wear();
        add_money("cash",5);
}


void init()
{
        object ob;
        ::init();
        if(interactive(ob =this_player()) && !is_fighting() )
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        add_action("do_nod","nod");
        }
}

int accept_fight(object who)
{
return notify_fail("山庄守卫说道 : 对不起 , 我没空陪你磨菇。\n");
}

void greeting(object ob)
{
if(!ob->query("family/family_name")&&ob->query("class")=="blademan")
{
command("say 你是来拜师的吗？\n");
}
        if( ob->query("family/family_name")=="金刀门")
        {
        command("smile "+ob->query("id"));
        }
        if( ob->query("class")=="poisoner" )
        kill_ob(ob);
        if( ob->query("class")=="killer" )
        kill_ob(ob);
}

 int do_nod()
 {
 object ob;
 ob=this_player();
        if(!ob->query("family/family_name")&&ob->query("class")=="blademan")
        call_out("do_act1",4,ob);
  return 0;
 }
int do_act1(object ob)
{

command("say 原来你是仰慕老爷而来拜会参观的呀！很抱歉你不能进去。\n");
ob->set_temp("allow-enter",1);

}

