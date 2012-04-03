//edit by neverend   2000/11/09
#include <ansi.h>
inherit NPC;
void do_special();

void create()
{
        seteuid(getuid());
        set("long","
���������������ľ������������ǧ������У���Ȼ���������Σ���˿���
Ʈ�ݣ���Ȼ����ǧ��ȴҲ�ز�ס��������ĵ����Σ�ƽ���������뿪��ľ������
Ҳ�����뷲�˽Ӵ���һ���˶������ⶴ�й��������������ĵ����С�
");
        set("gender","Ů��");
        set("class","fighter");
        set("nickname",HIC"ǧ������"HIW"��"HIG"�������"NOR);
        set("title","ǧ������");
        set_name("�����",({"dance wind","wind"}));
        set("combat_exp",16500000);
        set("attitude","aggressive");
        set("score",1000000);
        set("bellicosity",10000);
        set("age",1000);
        set("max_force",15000);
        set("force",15000);
        set("max_kee",100000);
        set("kee",100000);
        set("max_mana",15000);
        set("mana",15000);
        set("max_atman",15000);
        set("atman",15000);
        set("max_gin",100000);
	set("gin",100000);
        set("max_sen",100000);
	set("sen",100000);
        set("str", 35);
        set("cor", 35);
        set("cps", 30);
        set("per", 99);
        set("int", 35);
        set("force_factor",15);
        set_skill("dodge",200);
        set_skill("force",250);
        set("clan_kill",1);
        set("no_mount",1);
        set("no_plan_follow",1);
        set_skill("move",100);
        set_skill("parry",100);
        set_skill("mogi-steps",100);
        set_skill("unarmed",100);
        set_skill("literate",100);
        set_skill("fiendforce",150);
	set_skill("dance-wind",100);
        set_temp("armor_vs_force",1000);
        map_skill("force","fiendforce");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("parry","dance-wind");
        map_skill("unarmed","dance-wind");
        set("functions/fight/level",100);
        set("quest/gold-fire",1);
        set("quest/new_gold_fire",1);
        set_temp("mount",1);
        set_temp("follow",1);
        set_temp("speed",1);
        set_temp("empty",1);
        set_temp("false",1);
        set_temp("lock-link",1);
        set_temp("ghost",1);
        set_temp("rob",1);  
        set_temp("no-plan",1);
        set_temp("no_die_soon",1);
        set_temp("apply/armor",120);
        set_temp("apply/attack",50);
        set_temp("apply/damage",50);
        set_temp("apply/defense", 200);
        set("chat_chance_combat",35);
        set("chat_msg_combat",({
        (: do_special :)
        }));

        setup();
        carry_object("/open/mon/obj/ghost-helmet")->wear();
        carry_object("/open/mon/obj/ghost-cloak")->wear();
        carry_object("/open/mon/obj/ghost-legging")->wear();
        carry_object("/open/mon/obj/ghost-claw");
        carry_object("/data/autoload/open-area/ghost-heart")->wear();
        add_money("cash",500);
}

void init()
{
	::init();
	this_object()->set_temp("ok_wield",1);
	add_action( "block_cmd", "" );
	add_action( "do_cmd","cmd" );
}

//��������Acky��fire king��do�Ĺ���

int block_cmd( string arg )
{
 if( (string)query_verb() == "do" ) {
 write( HIY"�������Ц˵������ҪͶ���������Ͷ�������ˣ���������!!��\n"NOR );
   if( is_fighting() )
   this_player()->start_busy(1);
 return 1;
        }
}

int do_cmd(string str)
{
 object who=this_player();
 object ob,wind;
 ob=this_object();
 wind=present( "wind",environment(ob) );

 if(str=="throw wind" || str=="throw dance wind"){
 write(HIY"�������Ц˵���������������õķ�������ɱ��!ȥ����!!��\n"NOR);
 command("perform fireforce.gold-fire");
 wind->kill_ob(who);
 who->start_busy(1);
 return 1;                                                 
                  }
 if(str=="askgod wind" || str=="askgod dance wind"){
 write(HIY"�������Ц˵��������ĵ��б��Ҹ�ʱ�������������ɡ����ǺǺ�!!\n"NOR);
 command("perform fireforce.gold-fire");
 wind->kill_ob(who);
 who->start_busy(1);
 return 1;                                                 
                  }
 if(str=="bak wind" || str=="bak dance wind"){
 write(HIY"�������Ц˵����������Щ���ˣ��밵ɱ�ң�ʵ����̫��Ц��!!\n"NOR);
 command("perform fireforce.gold-fire");
 wind->kill_ob(who);
 who->start_busy(1);
 return 1;
                  }
}

void greeting(object me)
{
 write(HIC"
�����˵������˭��ô�󵨣���Ȼ������������
���еĵط����������е�������̫�ɶ��ˣ�����
"NOR); 
// call_out("do_special",3);
}

int accept_fight(object who)
{
 write(HIY"����������˵�����ȴ������Ƿ��ܻ����뿪�ɣ��ߺߣ�����\n"NOR);
 return 0;
}

int accept_kill(object who)
{
 who = this_player();
 write(HIY"������ڿ�Ծ������������ƽ���С�\n"NOR);
 command("say ��֪��ƽ������ѽ���ݹ����ˣ��������ɣ�");
 command("wield all");
 command("perform force.fight");
 kill_ob(who);
 return 1;
}

void heart_beat()
{
	object me,*enemy;
	int i,j,count;

	count = random(20);
	me = this_object();
	enemy = me->query_enemy();
	i = sizeof(enemy);

 if( !me->query_temp("weapon") && me->query_temp("ok_wield") )
 {
 command( "wield all" );
 command( "wear all" );
 }

 if(count == 17 && me->is_fighting())
 {
  message_vision(HIW"
    ���������һ�"HIM"��"HIB"������ߣ��׵籼��"HIM"��"HIW"ֻ����������������
    ������ɲʱ����ɫ��䣬���������߷������ˣ���\n"NOR,me);
  for( j=0 ; j < i ; j++ )
   {
   if( !enemy[j] ) continue;
    if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
     {
      message_vision(HIR"$N���������ޱȵĿ��������ˣ�������Ų�ס����ѣ����\n"NOR,enemy[j]);
      enemy[j]->add("kee",-300);
      enemy[j]->apply_condition("burn",enemy[j]->query_condition("burn")+5);
      COMBAT_D->report_status(enemy[j]);
     }
   }
 }

 if(count == 5 && me->is_fighting())
 {
  message_vision(HIW"
    �Ͽ�ͻȻƮ��������Ҷ����������Ҷ��ΪƬƬɱ�˵�"HIM"��"HIG"Ҷ"HIM"��"HIW"����
    ���ޣ��������֣�գ��֮�䣬��������Ҷ���پۼ���˲��ת��Ϊ
    һʽ"HIM"��"HIG"Ҷ�����裭ҶɱƬƬ"HIM"��"HIW"�����ٵķɱ���ɱ����\n"NOR,me);
  for( j=0 ; j < i ; j++ )
   {
   if( !enemy[j] ) continue;
    if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
     {
      message_vision(HIR"Ϊ�˶�������Ҷɱ��������$N���ٵ���������\n"NOR,enemy[j]);
      enemy[j]->add("force",-((enemy[j]->query("force")/150))*8);
      enemy[j]->apply_condition("star-stial",enemy[j]->query_condition("star-stial")+5);
      COMBAT_D->report_status(enemy[j]);
     }
   }
 }

 if(count == 7 && me->is_fighting())
  {
  message_vision(HIW"
    �����һ��ŭ����������仯Ϊһʽ"HIM"��"HIR"ŭ��������һ�����"HIM"��"HIW"��
    ���޵��һ�����������Ľ�һ���վ����һ�Ѷ�ٵ������ţ���\n"NOR,me);
  for( j=0 ; j < i ; j++)
   {
   if( !enemy[j] ) continue;
    if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
     {
      message_vision(HIR"$N��������һ���������ţ���ʹ���˻���ţ���\n"NOR,enemy[j]);
      enemy[j]->receive_wound("kee",300);
      enemy[j]->apply_condition("hellfire",enemy[j]->query_condition("hellfire")+5);
      COMBAT_D->report_status(enemy[j]);
     }
   }
  }


 if(count == 10 && me->is_fighting())
  {
  message_vision(HIW"
    ����������ת�����Σ�������������Ѱ����ѵĹ���ʱ������
    ����������һ˲�䣬ʹ��"HIM"��"HIY"������ת����������"HIM"��"HIW"����������
    �ҵ���������ķɱ��δܣ���\n"NOR,me);
  for( j=0 ; j < i ; j++)
   {
   if( !enemy[j] ) continue;
    if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
     {
      message_vision(HIR"$N�����ҵ��������ˣ�ʹ��Ĳ����Լ��������������\n"NOR,enemy[j]);
      enemy[j]->receive_wound("kee",300);
      enemy[j]->apply_condition("hart",enemy[j]->query_condition("hart")+2);
      COMBAT_D->report_status(enemy[j]);
     }
   }
  }

 if(count == 15 && me->is_fighting())
  {
  message_vision(HIW"
    �����һ�������û���ת���ɾ������޵���Ů�ӣ�������������
    һ��������������ɢ��"HIM"��"NOR+MAG"�������䣭�����Ի�"HIM"��"HIW"��������Ŀ�Ľ�
    �������޷����ӣ���\n"NOR,me);
  for( j=0 ; j < i ; j++)
   {
   if( !enemy[j] ) continue;
    if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
     {
      message_vision(HIR"$N���������Ŀ����֮�£��Եô��ĵ���ȫ�޷�����������\n"NOR,enemy[j]);
      enemy[j]->receive_wound("kee",300);
      enemy[j]->apply_condition("no_power",enemy[j]->query_condition("no_power")+2);
      COMBAT_D->report_status(enemy[j]);
     }
   }
  }

 if(count == 3 && me->is_fighting())
  {
  message_vision(HIW"
    ��������λû������������ص������ܣ����ٻ���������������
    �������ѣ��������ޱ����������޷���������˲ʱ������һ����
    ��"HIM"��"HIC"ǧ�����裭�������"HIM"��"HIW"�����绯����������Ϯ��һ�У���\n"NOR,me);
  for( j=0 ; j < i ; j++)
   {
   if( !enemy[j] ) continue;
    if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
     {
      message_vision(HIR"$N��ƬƬ�ĵ��������ˣ������ҽв��ѣ���\n"NOR,enemy[j]);
      enemy[j]->receive_wound("kee",300);
      enemy[j]->apply_condition("cold",enemy[j]->query_condition("cold")+5);
      COMBAT_D->report_status(enemy[j]);
     }
   }
  }

 if( random(10) == 5 )
 {
  if( is_fighting() )
  {

   if( query("kee") < query("eff_kee") )
    message_vision(HIW"\n����������������"HIR"��"HIM"��"HIY"ɫ"HIC"��"HIG"ã"HIB"��"HIW"����ã��������ﾫ��Ϊ֮��ܣ�\n"NOR,me);
    me->delete_busy();
    me->clear_condition();
    command("perform force.fight");
  }
 }

 if( !is_fighting() ) 
 {
    if( query("force") < 15000 ) 
    command( "ex 270" );
    if( query("eff_kee") < query("max_kee") )
    {
    command( "10 exert heal" );
    }
    if( query("gin") < query("eff_gin") )
    command( "exert regenerate" );
    if( query("kee") < query("eff_kee") ) 
    command( "5 exert recover" );
    if( query("sen") < query("eff_gin") ) 
    command( "exert refresh" );
 }
	 if( !is_fighting() && !me->query_temp("fight") && me->query_temp("ok_wield") )
	 {
	 command( "perform force.fight" );
	 }
  set_heart_beat(1);
  ::heart_beat();
}

void do_special()
{
 object me,*enemy;
 int kee,i,j;

 me = this_object();
 enemy = me->query_enemy();
 i = sizeof(enemy);

 if(me->is_fighting())
 {
  message_vision(HIY"
    �����һ����ȣ�һ�����ɫ�������������İ�Χ�����ɫ
    ������������������һ˲�䣬�ƽ����ɢ����һ��ҫ�۹�ã��
    ͬһʱ�䣬����﷢������ǿ��һ�о�ѧ"HBRED"����B��B��B�ɡ�"NOR+HIY"��\n"NOR,me);
  for( j=0 ; j < i ; j++)
   {
   if( !enemy[j] ) continue;
    if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
     {
      message_vision(HIR"�ƽ���򱩷�����������$N�������Զ����Ϣ������������\n"NOR,enemy[j]);
      enemy[j]->receive_wound("kee",200);
      enemy[j]->apply_condition("power-down",enemy[j]->query_condition("power-down")+5);
        if(enemy[j]->query("class")=="fighter")
	{
        enemy[j]->set_temp("power-down",20);
	}else{
	enemy[j]->set_temp("power-down",10);
	}
      enemy[j]->start_busy(1);
      COMBAT_D->report_status(enemy[j]);
     }
   }
 }
}

void die()
{

	int i,j;
	object *enemy;
  
	object winner = query_temp("last_damage_from");
	string class1 = winner->query("family/family_name");
	string name = winner->query("name");

	log_file("kill_dance", sprintf("%s(%s) ��������� on %s\n"
	,name,winner->query("id"), ctime(time()) ));
	enemy = query_enemy();
	i=sizeof(enemy);

	if( class1 == 0 ) class1="��������";

        tell_object(users(),HIY"
���������̾����

"HIM"��"HIC" �� �� �� �� �� �� �� �� ��

     �� �� �� �� �� �� �� �� ɢ

       �� �� İ · �� �� �� �� ��

         ң �� �� �� �� �� �� �� ��"HIM"��"HIY"


û�뵽��ǧ��ĵ��о�Ȼ����"+HIC+class1+HIY"��"+HIC+name+HIY"���ϣ���

���Ⱑ����      ��̾������

        ���˰ɣ���      ���˰ɣ���\n"NOR);

	if( !present( "ghost heart", winner ) ) 
	{
	  if ( random(9) == 7 ) 
	  {
	    if( winner->query_temp("quests/magic-manor-02") == 4 )
	    {
	    new("/open/magic-manor/obj/leaf")->move(winner);
	    tell_room(environment(),sprintf(HIY"\nһƬҶ������Ʈ�䣬����������%s�����ϡ�\n"NOR,winner->name()));
	    winner->set_temp("quests/kill-dance",1);
	    log_file("open-area/get_heart", sprintf("%s(%s) �õ�����֮���� %s\n",name,winner->query("id"), ctime(time()) ));
	    new("/data/autoload/open-area/ghost-heart")->move(winner);
	    tell_room(environment(),sprintf(HIY"\n���������ǰ���������ǿ�⣬��ã��������֮�ķ���%s�������ӡ�������С�\n"NOR,winner->name()));
	    }else{
	    log_file("open-area/get_heart", sprintf("%s(%s) �õ�����֮���� %s\n",name,winner->query("id"), ctime(time()) ));
	    new("/data/autoload/open-area/ghost-heart")->move(winner);
	    tell_room(environment(),sprintf(HIY"\n���������ǰ���������ǿ�⣬��ã��������֮�ķ���%s�������ӡ�������С�\n"NOR,winner->name()));
	    }
	  }else{
	    if( winner->query_temp("quests/magic-manor-02") == 4 )
	    {
	    new("/open/magic-manor/obj/leaf")->move(winner);
	    tell_room(environment(),sprintf(HIY"\nһƬҶ������Ʈ�䣬����������%s�����ϡ�\n"NOR,winner->name()));
	    winner->set_temp("quests/kill-dance",1);
	    destruct( present("ghost heart",this_object()) );
	    tell_room(environment(),sprintf(HIY"\n�������Ϊ���ܹ�����ػ������ϵ�����֮�ı����ķ����ˡ�\n"NOR));
	    }else{
	    destruct( present("ghost heart",this_object()) );
	    tell_room(environment(),sprintf(HIY"\n�������Ϊ���ܹ�����ػ������ϵ�����֮�ı����ķ����ˡ�\n"NOR));
	    }
	  }
	}else{
	  if( winner->query_temp("quests/magic-manor-02") == 4 )
	  {
	  new("/open/magic-manor/obj/leaf")->move(winner);
	  tell_room(environment(),sprintf(HIY"\nһƬҶ������Ʈ�䣬����������%s�����ϡ�\n"NOR,winner->name()));
	  winner->set_temp("quests/kill-dance",1);
	  destruct( present("ghost heart",this_object()) );
	  tell_object(winner,HIY"\n����֮���ٶ�ӡ�����У�һ���������������������Ǳ��!!\n"NOR);
	  winner->add("combat_exp",1000);
	  winner->add("potential",200);
	  }else{
	  destruct( present("ghost heart",this_object()) );
	  tell_object(winner,HIY"\n����֮���ٶ�ӡ�����У�һ���������������������Ǳ��!!\n"NOR);
	  winner->add("combat_exp",1000);
	  winner->add("potential",200);
	  }
	}

        if( winner->query("clan/id") )
        CLAN_D->add_clanset( winner->query("clan/id"), "develop" , 20 );

	:: die();
}                    