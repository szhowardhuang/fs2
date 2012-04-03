
//made in hide :P 
#include "/open/open.h" 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("李察鸡饵", ({ "lin di", "lin", "di" }) );
        set("nickname", HIR"魔鬼上将"NOR);
        set("title", "帝国反乱军");
        set("gender", "男性");
        set("age", 42);
        set("class", "soldier");
        set("guild_master", 1);
       set("bellicosity",3000);
        set("attitude", "heroism");
        set("combat_exp", 1200000);
 set("long","
    这个人身高七丈，留两道小胡子，一席红色的军服更显的他的神秘。
  仔细一看，你发现他的脸上有一条刀疤，而在他背上那把枪更是耀眼。
  他就是百战不败最令人畏惧的李察鸡饵。
         ");
        set("str", 40);
        set("cor", 40);
        set("int", 34);
  set("spi", 33);
        set("cps", 30);
        set("con", 30);
        set("per", 30);
        set("max_force", 4000);
        set("force", 4000);
        set("force_factor", 15);
        set("max_kee",5500);
        set("kee",5500);
        set("max_sen",2500);
        set("sen",2500);
        set("max_gin",2500);
        set("gin",2500);
        set_skill("literate",50);
        set_skill("lance", 100);
        set_skill("power-lance", 100);
        set_skill("cure", 60);
        set_skill("dodge", 70);
        set_skill("force", 100);
        set_skill("move", 90);
        set_skill("parry", 90);
        set_skill("spforce", 90);
        set_skill("unarmed", 50);
        set_skill("eagle-steps",70);
        map_skill("lance", "power-lance");
        map_skill("parry", "power-lance");
        map_skill("force", "spforce");
        map_skill("dodge", "eagle-steps");
        map_skill("move","eagle-steps");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        

        }) );

        setup();
carry_object("/open/soldier/obj/blood")->wield ();
        create_family("帝国反乱军",1,HIR"魔鬼上将"NOR);
        set("family/next_title", "魔鬼佣兵");
        add_money("gold", 30);
        }

int accept_fight(object who)
{
        message_vision("李察鸡饵朝$N冷冷笑了一下。\n", who);
        command("say 夭寿小孩!!!老子就跟你较量较量 。\n");
        return 1;
}

void attempt_apprentice(object who)
{
        if( !who->query("class") ) {
                command("hmm");
                command("shake "+who->query("id"));
                command("say 等你加入职业军人这一个行业再说吧。");
                return;
        }
        if( who->query("class")!="soldier" ) {
                command("sigh "+who->query("id"));
                command("say 本国的规矩是很严肃的，你们这些老百姓还是滚边去吧！");
                return;
        }
        command("nod "+who->query("id"));
        command("say 好！既然你肯学我就收你。");
        command("recruit "+who->query("id"));
        command("say 靠夭咧!拜我以后不会敬礼ㄚ!!没大没小!!。");
        command("hehe ");
}

int do_join()
{
        object who;
        who = this_player();

        if( who->query("class") )
                return notify_fail("你已经加入其他工会了。\n");
        who->set("class", "soldier");
        message("system", HIR"拿起麦克风大吼：帝国反乱军又多了一条米虫了-"HIY+who->query("name")+HIR"\n大家要多多操他啦！哇哈哈！\n"NOR, users());

        return 1;
}

void die()
{
        object me;
        me=query_temp("last_damage_from");
 me->set_temp("blood", 1);
        message_vision("\n",me);
        message_vision(HIM "你看见李察鸡饵应声倒地。\n" NOR,me);
        message_vision(" 从李察鸡饵身上掉出了一个徽章，你顺势捡了起来。\n",me);
        tell_room(me,HIR"李察鸡饵吼道: 你等死吧～～!!!哈哈哈。\n");
	call_out("msg2",1,me);
}
 void msg2(object me)
{	 
	message_vision("\n",me);
message_vision(HIY "千里不留行吼道: 顺我者生～逆我者亡～!!!纳命来～～!!\n" NOR,me);

message_vision(HIG "阿诺啥米碗糕喊道：给我围起来!!!一个也别跑出去!!!\n" NOR,me);
        tell_room(me,"你心想:完了～这次玩完了～莫非会葬身于此吗。\n");
        new("/open/soldier/npc/alo.c")->move("/open/soldier/room/r33.c");
  new("/open/soldier/npc/chan1.c")->move("/open/soldier/room/r36.c");
        ::die();
    return 0;

}

 
 
