inherit NPC;

void create()
{
	set_name("ÊØËþ½£Ê¿", ({"swordsman"}));
	set("long","ÆßÐÇËþÖÐÊØËþ½£Ê¿,Õý¶ñºÝºÝµÄµÉ×Å´³Â¥Õß.\n");
	set("gender","ÄÐÐÔ");
	set("combat_exp",250000);
        set("attitude","heroism");
	set("age",42);
	set("class","swordsman");
	set("score",1000);
        set("attitude","aggressive");
	set("force",800);
	set("max_force",800);
	set("force_factor",5);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
        set("max_kee",900);
        set("kee",900);
	set_skill("sword",70);
	set_skill("dodge",70);
	set_skill("parry",70);
        set_skill("shasword",70);
        set_skill("sha-steps",70);
        set_skill("shaforce",70);
        set_skill("force",70);
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        map_skill("dodge","sha-steps");
	setup();
	carry_object("/obj/longsword.c")->wield();
}
         
      
