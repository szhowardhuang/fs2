// 段家 掌门人
//新增奥义之迷 by xboy
#include </open/open.h>
#include <ansi.h>
int exert_sunforce();
inherit NPC;
inherit F_MASTER;
string do_thief();
string do_scar();
string do_chao();
string do_firecracker();
string do_sixfingers();
string do_tailong();
string do_trouble();
string do_chun();
string do_help();
string do_mark();
string do_mime();
string do_fan();
string do_linpo();
void add_record(string arg);
string bad_man,record;
void create()
{
        set_name("段云",({"lord duan","lord","duan"}));
        set("long","段云便是当今皇上册封的平南王, 同时也是段家武学的第十代传人, "+
        "虽然贵为王爷, 自有一肚子的墨水, 但其一身祖传的武学却也没忘, 可说是文武双全, "+
        "也因为如此, 段云自是非常重视文学素养, 若想拜入段家武学的门下, 则非是一位书生不可。\n");
        set("gender","男性");
        set("class","scholar");
        set("nickname","平南王");
        set("combat_exp",3000000);
        set("attitude","heroism");
        set("age",50);
        set("max_kee",10000);
        set("kee",10000);
        set("max_gin",10000);
        set("gin",10000);
        set("sen",10000);
        set("max_sen",10000);
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
        "六脉神剑"      : (: do_sixfingers :),
        "天龙寺"        : (: do_tailong :),
        "乱子"          : (: do_trouble :),
        "延庆太子"      : (: do_chun :),
        "急事"          : (: do_help :),
        "本因方丈"      : (: do_mark :),
        "六脉神剑经"    : "为本派武功‘六脉神剑’精要所在之武学宝典, 里面纪载了连我都不知的‘奥义’绝学。",
        "飘阳扇"        : (: do_fan :),
        "段霾"          : (: do_mime :),
        "凌波微步"      : "是段家的奇才「段誉”学会的奇门步法，我记得他有拿一本秘笈给我。",
        "凌波微步秘笈"  : (: do_linpo :),
        ]));
        set("force",5000);
        set("max_force",5000);
        set("six_spsp",1);
        set("force_factor", 20);
        set_skill("cure", 60);
        set("no_lyssa",1);
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
        set("functions/handwriting/level",100);
        set("marks/sun-finger",1);
        set("marks/six_sp",3);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
        }));
        setup();
        carry_object(PING_OBJ"neck0")->wear();
        carry_object(PING_OBJ"cloud_fan");
        add_money("gold",10);
        create_family("段家",10,"掌门人");
}

void init()
{
        add_action("do_answer","answer");
       add_action("do_title","show_fan_to_duan");
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
          return("大盗的右耳后有一小伤痕, 且使的是段家的\\武\\功吗？难道..难道是他..\n\n"+
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

string do_linpo()
{
        object me=this_player();

        if(me->query("family/family_name")!="段家")
          return "你问太多了吧，这不关你的事!!";
        if(me->query_skill("linpo-steps",1)!=100){
          command("slap "+me->query("id"));
          return "你基本的都还没学好，就在想什么秘笈???";
        }

        if(!me->query("quests/catch_thief"))
          tell_object(me,"段云小声的告诉你:唉，家丑不可外扬，你还是别再问了!!\n");
        else
          tell_object(me,"段云生气的说:哼，还不是被赵琴风那个叛徒给偷走了!!\n");
        me->set("marks/ask_linpo",1);
        return "";
}

//新增飘阳扇..........by dhk
string do_fan()
{
        object me=this_player();
        if( me->query_temp("buy_ok") == 1 )
        {
        if( me->query("family/family_name") == "段家" )      me->set_temp("fan",1);
          return("嗯!!你怎么会知到飘阳扇？\n\n"+
          "段云陷入深深的沈思之中，他说道：既然你问了那我就告诉你吧!\n\n"+
          "段云接着说道：飘阳扇乃当年一位武器大师～北胜天大师替我们大理段氏\n"+
          "              所打造的一把传说中的武器，因为其威力强大，所以向来\n"+
          "              只有段氏直系族人且品行优良者方能知晓，而在我们这一\n"+
          "              辈的，就是大师兄〔段霾〕了。\n");
        }
        else
          return("？");
}

//新增段霾.......by dhk
string do_mime()
{
        object me=this_player();
        object letter=new("/open/ping/questsfan/obj/letter1.c");
        if( me->query_temp("fan") == 1 && me->query_temp("letter_ok")==0)
        {
          if( me->query("family/family_name") == "段家" )     me->set_temp("mime",1);
          command("say 唉!!!.......自从二十年前大师兄出走之后，就音讯全无。我曾数次派\n"+
          "          人去寻找，但全都无功而返。这样吧!!!!现下我就派你去寻找大师兄。\n"+
          "          而有关飘阳扇的事你也可以自己问他。但我怕大师兄会因事关武林安危\n"+
          "          而不告知。我这有一张拜帖，你拿给师兄，我想他应会回答你的问题。\n"+
          "\n");
          message_vision("$N交给$n一张拜帖。\n",this_object(),me);
          letter->move(me);
          me->set_temp("letter_ok",1);
          return("你这次去寻大师兄，可得自己照顾自己。\n");
        }
        else
         return("?");
}

string do_sixfingers()
{
        object me=this_player();
        if( me->query("family/family_name")=="段家" && me->query("marks/six_sp")<=2)
        {
          me->set_temp("six_sp_quest",1);
          return("
              我大理段氏向来以一阳指与六脉神剑闻名, 那一阳指固然难练,
              六脉神剑更是百年难得有一人能尽得真传, 因此‘天龙寺’的高
              僧为延续此一神功, 撰写了一部‘六脉神剑经’。");
        }
        else
        {
          command("kick"+me->query("id"));
          return("笨蛋!!玩那么久的狂想还不知道六脉神剑, 去死算了!!");
        }
}

string do_tailong()
{
        object me=this_player();
        if( me->query_temp("six_sp_quest")==1)
        {
          me->set_temp("six_sp_quest",2);
          return("
              乃是我大理段氏的武学重镇, 过去许多的‘乱子’都是有天龙寺
              高僧相助, 才得以渡过难关。");
        }
        else
          return("你问那么多干嘛...");
}

string do_trouble()
{
        object me=this_player();
        if( me->query_temp("six_sp_quest")==2)
        {
          me->set_temp("six_sp_quest",3);
          return("
              莫过于百余年前的那场皇宫内乱, 当时‘延庆太子’遭人围攻,
              后来一度失踪, 我先祖得到天龙寺众高僧协助, 才得以平乱。");
        }
        else
          return("现在乃是太平盛世, 哪来的乱子??");
}

string do_chun()
{
        object me=this_player();
        if( me->query_temp("six_sp_quest")==3)
        {
          me->set_temp("six_sp_quest",4);
          return("
              此人原为我段家出类拔萃的人物, 奈何当年那场大乱, 竟
              使他投入邪派, 后来更成为四大恶人之首, 危害武林, 其
              武功身兼正邪, 真的当者披靡, 不过这十多年来, 未再听
              到其消息, 想是已不在人世才是。");
        }
        else
          return("什么‘盐浸太久’??拜托你说国语好不好!");
}

string do_help()
{
        object me=this_player();
        if( me->query_temp("six_sp_quest")==5)
        {
          me->set_temp("six_sp_quest",6);
          return("
              延庆太子原来还在人间, 这次更闯进天龙寺, 盗走六脉神剑经,
              徒儿, 为师派你去天龙寺相助‘本因方丈’, 务必把宝经夺回!!");
        }
        else
          return("啥?你尿急喔?出门左转第二间就是厕所, 不用谢我了。");
}

string do_mark()
{
        object me=this_player();
        object mark=new(PING_OBJ"tai_mark");
        if( me->query_temp("six_sp_quest")==6)
        {
          me->set_temp("six_sp_quest",7);
          command("say 本因方丈主持天龙寺多年, 你此去相见, 只须交给他信物, 他便知道了。");
          message_vision("$N交给$n一只天龙令。\n",this_object(),me);
          mark->move(me);
          return("快去吧!");
        }
        else
          return("本因坊是下围棋的, 跟我没有关系。");
}

int exert_sunforce()
{
        object ob=this_object();
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
write("段云缓缓的吟唱道:[1;36m"+question[which]+"[0m\n");
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
        else if(obj->query("name")=="凌波微步卷轴" && obj->query("linpo_quest"))
        {
          if(me->query("marks/ask_linpo")!=3){
            write("段云看了看手上的东西，觉得一点用处也没有，于是运功把"+
                  obj->query("name")+"捏个粉碎!!\n");
            destruct(obj);
          }
          else{
            command("say 没错，就是这本秘笈");
            command("think");
            command("hmm");
            command("say 如果我没记错的话，这东西少了几页，前面所记载的这些我都已经教过你了!!\n");
            command("give "+obj->query("id")+" to "+me->query("id"));
            me->set("marks/ask_linpo",4);
            command("say 如果你真的想把凌波微步的精华学会，就去找段誉吧!!\n");
          }
        }
        else
        {
        command("? "+getuid(me));
        record="";
        record=getuid(me)+"给了段云一个"+obj->query("name")+"在"+ctime(time())+"。";
        add_record(record);
        bad_man=getuid(me);
        }
        return 1;
}

void add_record(string arg)
{
        write_file("/u/b/bss/duan_record", arg);
        return ;
}

void die()
{
        object winner = query_temp("last_damage_from");
        int j;
        if(!winner)
        {
          ::die();
        return ;
        }
        if(!wizardp(winner)){
        tell_object(users(),"\n\t[1m‘[36m天下风云出我辈  一入江湖岁月摧\n\t\t皇图霸业谈笑中  不胜人生一场醉[0m[1m’[0m\n"+
        "\n\t[1m想我段云纵横江湖, 今日败于[33m"+winner->query("name")+"[0;1m之手\n\t可谓  [1;31m时也～  运也～  命也～[0m\n");
        tell_object(users(),"\n\n[36m南方天空画过一道[5m流星[0m。\n\n\t[1;31m「□[35m□[31m□[35m□[31m□[35mP[31m□[35m□[31m”[0m\n\n");
        }

        if ( winner->query_temp("bless")==1 )
        {
        j=random(6000);
          if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
          {
          new("/open/sky/obj2/peace_stone")->move(environment(winner));
          message_vision(HIM"\n从段云的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/peace_stone",sprintf("%s(%s) 让段云掉下了和平石于 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }else{
        j=random(12000);
          if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
          {
          new("/open/sky/obj2/peace_stone")->move(environment(winner));
          message_vision(HIM"\n从段云的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/peace_stone",sprintf("%s(%s) 让段云掉下了和平石于 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }
        :: die();
}

int accept_kill(object who)
{

        who=this_player();
        if(who->query("id")==bad_man)
        {
        record="";
        record=getuid(who)+"可能利用作弊的方法杀死段云在"+ctime(time())+"。";
        add_record(record);
        }
        command("unwield all");
        command("wield fan");
        command("kill "+who->query("id"));
        command("exert sun-finger");
        command("perform unarmed.handwriting");
        command("wield finger");
        return 1;
}
int accept_fight(object who)
{
        who=this_player();
        if(who->query("id")==bad_man)
        {
        record="";
        record=getuid(who)+"可能利用作弊的方法杀死段云在"+ctime(time())+"。";
        add_record(record);
        }
        command("unwield all");
        command("wield fan");
        command("exert sun-finger");
        fight_ob(who);
        command("perform unarmed.handwriting");
        command("wield finger");
        return 1;
}
int do_title()
{
  object me=this_player();
  if(!me->query("marks/fan-finger")) return 0;
  if(!me->query("make_ok"))
  {
if(me->query("gender")=="男性")
{
me->set("title",""HIY"文凌驾"NOR"‘"HIC"飘"NOR"阳"HIC"灵"NOR"帝’");
  me->set("make_ok",1);
tell_object(me,"你做的不错，好扇、好扇呀！...哈哈哈　!!!\n");
}
else
{
me->set("title",""HIM"文翎羽"NOR"‘"HIY"玄"NOR"天"HIY"灵"NOR"后’");
  me->set("make_ok",1);
tell_object(me,"你做的不错，好扇、好扇呀！...哈哈哈　!!!\n");
}
}
else
tell_object(me,"阁下已经改过title了。\n");
  return 1;
}
