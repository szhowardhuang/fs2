inherit NPC;
void create()
{
        set_name("项少龙",({"shun-shou long","long",}));
        set("gender","男性");
        set("age",30);
        set("str",45);
        set("bellicosity", 1000);
        set("title","刀君");
        set("long","一位英气逼人的壮汉 ,手拿宝刀 ,一看就知道 ,是一个绝不好惹的人 !\n");
        set("combat_exp",600000);
        set("max_kee",2500);
        set("kee",2500);
        set("max_force",2000);
        set("force",2000);
        set_skill("blade",90);
        set_skill("parry",80);
        set_skill("dodge",40);
        set_skill("force",70);
        set_skill("dragon-blade",90);
        set_skill("fly-steps",60);
        set_skill("powerforce",80);
        map_skill("blade","dragon-blade");
        map_skill("parry","dragon-blade");
        map_skill("dodge","fly-steps");
        map_skill("force","powerforce");
        
        set("chat_chance",10);
        set("chat_msg",({
                "项少龙说道 : 哈哈 ,谁的女人比我多 ?\n",
                "项少龙难过的说 : 可是现在只剩一个啰 :~~~\n"
                }));
        setup();
}

