// 段家 掌门人
#include </open/open.h>
int exert_sunforce();
inherit NPC;
inherit F_MASTER;
string do_thief();
string do_scar();
string do_chao();
string do_firecracker();
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
        set("max_kee",3000);
        set("kee", 3000);
        set("str", 44);
        set("cor", 24);
        set("cps", 45);
        set("per", 30);
        set("int", 42);
        set("inquiry", ([
        "thief"         : (: do_thief :),
        "scar"          : (: do_scar :),
        "sad_story"     : "若你不知道其中缘由,就不要再问了。",
        "chao"          : (: do_chao :),
        "firecracker"   : (: do_firecracker :),
        "一阳心法秘笈"  : "这一阳心法的秘笈听说已由柳毅风寻获, 只是不知他何时回来。",
        ]));
        set("force",3000);
        set("max_force",3000);
        set("force_factor", 10);
        set_skill("cure", 60);
        set_skill("dodge", 70);
        set_skill("force",80);
        set_skill("move", 70);
        set_skill("parry", 70);
        set_skill("stabber",120);
        set_skill("unarmed",20);
        set_skill("literate",120);
        set_skill("sunforce",80);
        set_skill("linpo-steps",100);
        set_skill("six-fingers",100);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");
        set("functions/handwriting/level",50);
        set("marks/sun-finger",1);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
                (: this_object(),"exert_sunforce" :),
        }));
        setup();
        carry_object(PING_OBJ"neck0")->wear();
        carry_object(PING_OBJ"cloud_fan")->wield();
        add_money("gold",10);
        create_family("段家",10,"掌门人");
}

void init()
{
        add_action("do_answer","answer");
        set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}       

string do_thief()
{
        object me=this_player();
        if( me->query_temp("thief") < 4 )
          return("京城的大盗..嗯..与我段家有关吗？");
        else
        {
          command("sigh");
          return("唉..没想到..他..唉..");  
        }
}
string do_scar()
{
        object me=this_player();
        if( me->query_temp("thief") >= 3 )
        {
        if( me->query_temp("thief") == 3 )      me->set_temp("thief",4);
          return("大盗的右耳后有一小伤痕, 且使的是段家的\武\功吗？难道..难道是他..\n\n"+
          "段云陷入深深的沈思之中, 似乎在回想着什么。\n\n"+
          "段云抱歉的说道: 我不想再提起这段伤心往事(sad_story)了。来人啊,送客..");
        }
        else
          return("啥..谁的伤痕？");
}
string do_chao()
{
        object me=this_player();
        object key=new(PING_OBJ"key0");
        if( me->query_temp("thief") >= 5 )
        {
          if( me->query_temp("thief") == 5 )    me->set_temp("thief",6);
          command("say 唉..你也知道了这件事了啊..是柳毅风跟你说的吧..其实过了"+
          "这么多年, 我也该面对现实了。赵琴风变成京城大盗, 也算是段家管"+
          "教不周所致, 现在要引出赵琴风, 只有一个办法, 就是用我们段家独"+
          "门的联络烟火, 他看到了烟火必定会出现。");
          message_vision("$N交给$n一把铁钥匙。\n",this_object(),me);
          key->move(me);
          return("这是我们段家储藏室的钥匙, 你可以在那找到联络用的炮仗");
        }
}
string do_firecracker()
{
        object me=this_player();
        if( me->query_temp("thief") >= 6 )
        {
          if( me->query_temp("thief") == 6 )    me->set_temp("thief",7);
          return("啊..抱歉忘了说明炮仗的使用方法, 这炮仗需要在高地燃放才行, "
          +"且在燃放前要先︿＆％︿＊＆＠＃....明白了吧。");
        }
        else
          return("疑..你怎会知道这这炮仗的事, 给我老实道来!!");
}

int exert_sunforce()
{
        object ob=this_object();
        if( ob->query("kee") < ob->query("max_kee")/2 )
        if( !present("sunforce finger",ob) )
        {
          command("say 好..老夫就陪你玩玩。");
          command("exert sun-finger");
          command("wield finger");
        }
        return 1;
}

int do_answer(string str)
{
        object me=this_player();
        string *answer = ({
        "虞兮虞兮奈若何",
        "去日苦多",
        "对影成三人",
        "悠然见南山",
        "春风不度玉门关",
        "西出阳关无故人",
        "共此灯烛光",
        "此恨绵绵无绝期",
        "蜡炬成灰泪\始干",
        "千古风流人物",
         "一步江湖无尽期",
         "浊酒一杯笑红尘",
         "窃窃暗笑世人痴",
         "神机妙算赞白莲"
        });
        if(me->query_temp("answer") < 0);
        else
        {
          if(str == answer[me->query_temp("answer")])
          {
            command("pat "+me->query("id"));
            write("很好，" + RANK_D->query_respect(me) + "的文学底子不错, 多加努力, "+
            "他日必能为段家发扬光大, 在江湖上扬名立姓。\n");
            command("recruit " + me->query("id") );
            me->set("startroom",environment(me));
            write("嗯..你的内功不够纯正, 让为师的助你一臂之力吧。\n");
            message_vision("段云缓缓的伸出右手, 往$N头顶的百会穴一按, 丝丝的蒸气从$N的头上冒了出来....。\n",me);
            me->improve_skill("sunforce",2);
            command("smile "+me->query("id"));
            write("好了, 为师已将一小部份的一阳心法传与你, 望你能再接再励, 终于大成。\n");
            CHANNEL_D->do_channel(this_object(), "chat",
            sprintf("%s成为段家的一员了, 希望大家能本着江湖精神照顾他。",me->name(1)));
          }
          else
          {
            command("sigh "+me->query("id"));
            write(RANK_D->query_respect(me)+"你的文学素养太浅了, 也许应该多去品嚐书籍, "+
            "下次有把握了再来找我吧...\n");
          }
          me->delete_temp("answer");
        }
        return 1;
}               

void attempt_apprentice(object me)
{
        int which;
        string *question = ({
        "项羽‘核下歌’\n「力拔山兮气盖\世! 时不利兮骓不逝! 骓不逝兮可奈何! .......”",
        "曹操‘短歌行’\n「对酒当歌, 人生几何? 譬如朝露, ....”",
        "李白‘月下独酌’\n「花间一壶酒, 独酌无相亲; 举杯邀明月, .....”",
        "陶渊明‘饮酒’\n「结卢在人间, 而无车马喧。问君何能尔, 心远地自偏。采菊东离下, .....。”",
        "王之涣‘凉州词’\n「黄河远上白云间, 一片孤城万仞山。羌笛何须怨杨柳, .......。”",
        "王维‘渭城曲’\n「渭城朝雨浥清尘, 客舍青青柳色新。劝君更进一杯酒, .......。",
        "杜甫‘赠卫八处士’\n「人生不相见, 动如参与商。今夕复何夕, .....”",
        "白居易‘长恨歌’\n「在天愿做比翼鸟, 在地愿为连理枝。天长地久有时尽, .......!",
        "李商隐‘无题’\n「相见时难别亦难, 东风无力百花残。春蚕到死丝方尽; .......",
        "大江东去, 浪淘尽, ......”",
            "锦鲤欲跃龙门池, 北风一动离水时, 战火烧断逍遥梦.......",
            "世事如棋局局新, 豪杰似浪翻不尽, 古往今来多少事.......",
            "还真为逐青云志, 一生真伪有谁知, 堂堂满言仁义情.......",
            "灵车赫赫天下惊, 妖声邪气弥满天, 金叶一动清香现......."
        });
        which=random(sizeof(question));
        if(me->query_temp("have_apprentice"))
          write("怎么这么快又见面了? 下次再来吧。\n");
        else
        {
        write(" "+RANK_D->query_respect(me)+"想拜入我的门下吗? 我门的内功首重内心修养, "+
        "若学识没有一定的基础, 对自身反而有害。老夫这就来试一试你, 若真心想学的话就回答(answer)我的问题吧\n");
        write("段云缓缓的吟唱道: fl;[1;36m"+question[which]+"fc;[0m\n");
        write("段云和蔼的说道: 你能说说接下来的句子吗?\n");
        me->set_temp("have_apprentice",1);
        me->set_temp("answer",which);
        }
}
int accept_object(object me, object obj)
{
        if( obj->query("name") == "一阳心法秘笈" )
        {
          command("pat "+getuid(me));
          command("say 太好了, 是柳毅风托你的吗？谢了。");
          if( me->query("family/family_name") == "段家" && !me->query("marks/sun-finger") )
          {
            command("say 既然你护送秘笈有功, 我便将此秘笈上记载的绝招传授与你吧。");
            write(this_object()->query("name")+"看着秘笈随手演练一遍。\n\n"+
            "你觉得心中疑虑豁然贯通, 全身内力迅速流转一周天。\n\n"+
            "[36m你的内力值达到上限了。\n\n"+
            "[1m你学会了一阳心法中的绝招「化气为笔”。[0m\n\n");
            if( me->query("force") < me->query("max_force") )
              me->set("force",me->query("max_force"));
            me->set("marks/sun-finger",1);
          }
          destruct(obj);
        }
        else
          command("? "+getuid(me));
        return 1;
}
              
void unconcious()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),"\n\t[1m‘[36m天下风云出我辈  一入江湖岁月摧\n\t\t皇图霸业谈笑中  不胜人生一场醉[0m[1m’[0m\n"+
        "\n\t[1m想我段云纵横江湖, 今日败于[33m"+winner->query("name")+"[0;1m之手\n\t可谓  [1;31m时也～  运也～  命也～[0m\n");
        :: unconcious();
}
void die()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),"\n\n[36m南方天空画过一道[5m流星[0m。\n\n\t[1;31m「天机星落”[0m\n\n");
        :: die();
}                      
