inherit NPC;

void create()
{
	set_name("柳若芙",({"ro fu","fu"}));
set("long","柳毅之女,年方十七,千骄百媚.为李逍遥之爱徒.\n");
	set("gender","女性");
	set("combat_exp",3613);
        set("attitude","heroism");
	set("age",17);
	set("class","swordsman");
	set("force",150);
	set("max_force",150);
	set("family/master_name","李逍遥");
	set("chat_chance",10);
       set_skill("shasword",10);
       set_skill("sha-steps",3);
       map_skill("sword","shasword");
       map_skill("dodge","sha-steps");
	set("chat_msg",({
  "柳若芙满面愁容道:都是我不好,使大师兄被师父责罚在私过崖面壁一个月，
  其实我只是想跟师兄玩个捉迷藏，看到前面有条小路，我就冲进去了，哪知 
  道师父会大发雷霆。\n",
  "柳若芙嘟着嘴道 : 跟你们说哦...那天听到我爹和掌门--郑士欣叔叔谈论什么‘仙剑
   后三式’的 ,好像神秘兮兮..还提到‘藏经阁’之类 ,真不知道他们在做什么..\n", 
  "柳若芙嘟着嘴道:那里面除了一些怪声音，和一堆动物的残骸之外，也不见有
  什么奇怪之处，不过小路尽头有个山洞感觉怪怪的，不过里面这么黑，我也不
  敢进去。\n"
	 }));
	set("force_factor",3);
	set("str",30);
        set("cor", 30);
	set("per",35);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",35);
	set_skill("dodge",35);
	set_skill("parry",35);
	setup();
	carry_object("/obj/longsword.c")->wield();
	carry_object("/open/gsword/obj/robe_1")->wear();
	add_money("silver",5);
	create_family("仙剑派",5,"弟子");
}

         
      
