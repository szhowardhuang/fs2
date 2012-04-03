inherit NPC;

void create()
{
	set_name("方罗",({"fun lo","lo"}));
	set("long","范松的得意弟子 ,剑法已有相当造诣 .\n");
	set("gender","男性");
	set("combat_exp",6106);
        set("attitude","heroism");
	set("age",22);
	set("class","swordsman");
	set("score",1000);
	set("force",300);
        set("max_force",300);
        set("family/master_name","范松");
	set("force_factor",3);
	set("str",30);
        set("cor", 30);
	set("per", 25);
        set_skill("shasword",10);
	set_skill("sha-steps",3);
	map_skill("sword","shasword");
	map_skill("dodge","sha-steps");
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",40);
	set_skill("dodge",40);
	set_skill("parry",40);
	setup();
	carry_object("/obj/longsword.c")->wield();
	carry_object("/open/gsword/obj/robe_1")->wear();
	// carry_object("/open/gsword/obj/pill")->set_amount(1);
	create_family("仙剑派",5,"弟子");
}

         
      
