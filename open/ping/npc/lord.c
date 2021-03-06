inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("段云",({"lord duan","lord","duan"}));
	set("long","段云便是当今皇上册封的平南王, 同时也是段家武学的第十代传人, "+
"虽然贵为王爷, 自有一肚子的墨水, 但其一身祖传的武学却也没忘, 可说是文武双全, "+
"也因为如此, 段云自是非常重视文学素养, 若想拜入段家武学的门下, 则非是一位书生不可。\n");
	set("gender","男性");
	set("class","scholar");
	set("nickname","平南王");
        set("combat_exp",1000000);
        set("attitude","heroism");
	set("age",50);
	set("str", 44);
	set("cor", 24);
	set("cps", 18);
	set("per", 24);
	set("int", 42);
	set("force",3000);
	set("max_force",3000);
        set_skill("literate",100);
        set_skill("force", 85);
        set_skill("dodge", 60);
        set_skill("move", 60);
        set_skill("parry", 40);
        set_skill("sunforce",100);
        set_skill("six-fingers",100);
        map_skill("force","sunforce");
        map_skill("unarmed","six-fingers");
	map_skill("dodge","six-fingers");
	set("force_factor",10);
	setup();
        add_money("gold",10);
        create_family("段家",10,"掌门人");
}
  void attempt_apprentice(object me)
{
        write("很好，" + RANK_D->query_respect(me) + "多加努力，"+
              "他日必定有成。\n");
        command("recruit " + me->query("id") );
}
