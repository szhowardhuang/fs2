// sun_jen.c
// 加入银针解谜物件-by nike-
#include <ansi.h>
inherit NPC;

string ask_pnx();
string ask_wine();

void create()
{
        set_name("任朝阳", ({ "trainer jen", "jen" }) );
        set("title", "泷山派第八代奥义任家传人");
        set("nickname", "酒狂");
        set("gender", "男性" );
        set("age",30);
        set("str", 30);
        set("int", 24);
        set("inquiry",([
             "买酒"     :  (: ask_wine :),
             "火凤羽"     :  (: ask_pnx :),
        ]));
        set("long",
                 "任朝扬是泷山派奥义的任家传人, 亦是任家的长子, 他所使用的‘泷山\n" +
                 "绝学’(Lungshan)是其父正晴馆主亲授之绝学, 由于身为长子必须以发\n" +
                 "扬泷山派为己任, 因此自小勤于习武, 其拳术与其父不分轩冕, 但是他\n" +
                 "嗜酒如命, 却不至沈醉, 将醉步溶入绝学中, 使其更胜一筹, 有青胜蓝\n" +
                 "之势, 同时曾获得城中武术冠军, 所以大家都称他为‘ 酒狂 ’！\n");
        set("attitude", "heroism");
        set("env/狂击","YES");
        set("combat_exp", 500000);
        set("force",2800);
        set("max_force", 2800);
        set("force_factor", 15);
        set("inquiry", ([
                "here": "这里是任家正晴武馆, 请问有何事指教?\n",
                "name": "在下姓任, 名朝阳, 是本馆的副馆主。",
                "lungshan": "喔....此为本馆绝学, 在下对此颇有研究,承蒙家父栽培!\n",
        ]) );
        set("super_fire",1);
        set_skill("lungshan", 90);
        set_skill("dodge"   , 50);
        set_skill("haoforce", 60);
        set_skill("force"   , 70);
        set_skill("unarmed", 70);
        set_skill("parry", 70);
        set_skill("henma-steps",60);
        set_skill("fire-kee",50);
        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        set("chat_chance_combat",65);
        set("chat_msg_combat",({
            (: perform_action, "force.kang_kee"   :),
        }));
        setup();
         carry_object(__DIR__"obj/fight_robe")->wear();
         carry_object("/open/wu/npc/obj/fireclaw.c")->wield();
         carry_object(__DIR__"obj/armband")->wear();
}
int accept_object(object me, object ob)
{
    string name = ob->query("name");

    if(me->query("get_wine") == 1)
{
    if(name == HIR"<满>"HIC"十锦珐琅杯"NOR)
{
        command("snort "+me->query("id"));
        command("say 你...你搞啥啊...现...现在才来！");
        command("drinking");
        call_out("say_pnx",3,me);
        return 1;
    }
  }
}
int say_pnx(object me)
{
    object ob;

        write(HIY"任朝阳恍恍惚惚的说道：mmm...说到我们泷山派的镇派圣兽－赤羽火凤呐！\n"NOR,me);
        write(HIY"任朝阳恍恍惚惚的说道：不...不是我在臭屁的...ㄜ！...牠的羽...羽毛，真是绝世美物...\n"NOR,me);
        write(HIY"任朝阳恍恍惚惚的说道：我看...ㄜ！看在你..你帮我买酒的份上...就给你机会去...ㄜ！去拔看看...\n"NOR,me);
        write(HIY"任朝阳恍恍惚惚的说道：ㄜ！藏经阁之钥在这...这儿...嗯...但我可不...不保证你...ㄜ！你能成功的...拿到羽毛唷...\n"NOR,me);
        ob=new("/open/doctor/obj/key");
        ob->move(me);
        me->set("get_key",1);
        me->delete("get_wine");
        destruct(ob);
        return 1;
}
string ask_pnx()
{
    object me=this_player();

    if(me->query("ask_baby")==1)
{
        command("arc "+me->query("id"));
        command("say 啥咪...火...火凤羽ㄚ？ㄜ！嗯...听某啦！");
        command("say 咦？你...你是哪ㄜ！..位ㄚ？别在这妨碍我喝....喝酒，闪开！");
        command("drinking");
        command("cow");
        command("say 可恶！又没酒了...ㄜ！喂！那个谁...帮我去买酒...快！");
        me->delete("ask_baby");
        me->set("ask_wine");
  }
}
string ask_wine()
{
    object me=this_player();

    if(me->query("ask_wine")==1)
{
        command("slap "+me->query("id"));
        command("say 猪头啊你！当然是到...风...的...嗯....zｚZＺ");
        command("sleep");
        write(HIY"任朝阳模模糊糊的说着梦话：酒...冰清冽酒...给我..冰清冽酒...mmm...\n"NOR);
        me->delete("ask_wine");
        me->set("ask_flor");
  }
}