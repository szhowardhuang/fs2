// trainer.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("任朝阳", ({ "trainer jen", "jen" }) );
        set("title", "泷山派第八代奥义任家传人");
        set("nickname", "酒狂");
        set("gender", "男性" );
        set("age",30);
        set("str", 30);
        set("int", 24);

        set("long",
                 "任朝扬是泷山派奥义的任家传人, 亦是任家的长子, 他所使用的‘泷山\n" +
                 "绝学’(Lungshan)是其父正晴馆主亲授之绝学, 由于身为长子必须以发\n" +
                 "扬泷山派为己任, 因此自小勤于习武, 其拳术与其父不分轩冕, 但是他\n" +
                 "嗜酒如命, 却不至沈醉, 将醉步溶入绝学中, 使其更胜一筹, 有青胜蓝\n" +
                 "之势, 同时曾获得城中武术冠军, 所以大家都称他为‘ 酒狂 ’！\n");

        set("attitude", "heroism");

        set("combat_exp", 300000);
        set("force",800);
        set("max_force", 800);
        set("force_factor", 10);

        set("inquiry", ([
                "here": "这里是任家正晴武馆, 请问有何事指教?\n",
                "name": "在下姓任, 名朝阳, 是本馆的副馆主。",
                "lungshan": "喔....此为本馆绝学, 在下对此颇有研究,承蒙家父栽培!\n",
        ]) );

        set_skill("unarmed" , 80);
        set_skill("lungshan", 90);
        set_skill("dodge"   , 60);
        set_skill("force"   , 60);

        map_skill("unarmed", "lungshan");
        map_skill("dodge"  , "lungshan");
        map_skill("force"  , "haoforce");

        setup();
         carry_object(__DIR__"obj/fight_robe")->wear();
carry_object("/open/wu/npc/obj/fireclaw.c")->wield();
         carry_object(__DIR__"obj/armband")->wear();
}

int recognize_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="泷山派" ) return 1;

        command("say 对不起，这位" + RANK_D->query_respect(ob) + "，您不是我们武馆的弟子。");
        return notify_fail( "任朝阳不愿意教你拳法。\n");
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="泷山派" ) {
                command("nod");
                command("say 来吧!");
                return 1;
        }
        command("say 馆主吩咐过，不许和来这里的客人过招。");
        return 0;
}
