//master of cure

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("慈恩圣僧",({"Master of bonze","master","bonze"}) );
        set("long",@LONG
        少林寺现任方丈，为一位慈蔼的僧人，度化无数误入
        歧途的边缘人，故得此圣僧的称号。
LONG );
        set("gender", "男性" );

        set("class","bonze");
        set("guild_master",1);

        set("combat_exp",2000000);
        set("force",3000); 
        set("max_force",3000);
        set("force_factor",10);
        set("max_kee",3000);
        set("mana",200);
        set("max_mana",200);
        set("max_atman",200);
        set("atman",200);
        set_skill("array",80);
        set_skill("blade",80);
        set_skill("sword",80);
        set_skill("cure",60);
        set_skill("force",80);
        set_skill("spells",20);
        set_skill("magic",20);
        set_skill("move",60);
        set_skill("parry",80);
        set_skill("staff",120);
        set_skill("stick",120);
        set_skill("literate",40);
        set_skill("unarmed",80);
        set_skill("dodge",60);
        set_skill("buddhism",100);
        set_skill("rulai",100);
        set_skill("fumostaff",100);
        set_skill("yu-steps",100);
        set_skill("ejinforce",100);
        map_skill("force","ejinforce");
        map_skill("unarmed","rulai");
        map_skill("dodge","yu-steps");
        map_skill("move","yu-steps");
        map_skill("staff","fumostaff");

        
        create_family("少林派", 42, "掌门人");
 
        setup();
        carry_object(__DIR__"buddha_staff")->wield();
        carry_object(__DIR__"puty_pullium")->wear();

}

/*
void init()
{
        add_action("do_join","join");
}

int do_join(string str)
{
        object me;
        me = this_player();
        if(str!=0)
          return notify_fail("请打\"join\"即可。\n");
        if(me->query("class") == "bonze" )
        return notify_fail("你不要开玩笑了，你不是早就加入了吗？\n");
        if(me->query("gender") == "女性")
          return notify_fail("这位女施主请回吧,少林寺是不收女性的。\n");
        if( me->query("class") )
          return notify_fail("你已经加入了别的工会了\n");
        command("say 阿弥陀佛！欢迎施主加入和尚的行列。\n");
        me->set("class","bonze");
        return 1;
}
void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="bonze")
        {
                command("sigh");
                command("say 你未入空门，恕老衲无德,不能收你为徒。\n");
                return;
        }else{
        command(":)");
        command("recruit "+ob->query("id"));
        }
}
*/
