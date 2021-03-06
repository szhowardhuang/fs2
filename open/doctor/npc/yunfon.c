#include <ansi.h>
inherit NPC;

string ask_fon();
string ask_but();
string ask_baby();

void create()
{
    set_name("华云峰", ({"hwa yun fon","hwa","fon","yun"}) );
    set("long", "
他就是目前世上唯一身负「不传之技”的银针门前辈，
听说当年其灸功堪称天下一绝！\n");
    set("gender", "男性");
    set("title", HIC"面壁十年"NOR);
    set("age", 65);
    set("inquiry",([
         "不传之技"     :  (: ask_fon :),
         "条件"     :  (: ask_but :),
         "宇内五禽"     :  (: ask_baby :),
    ]));
    set("attitude", "peaceful");
    setup();
}
string ask_fon()
{
    object me=this_player();

    if(me->query("doctor/get_mark") == 1  && !me->query("doctor/save_die") 
    && me->query("class")=="doctor")
{
    if(!me->query("doctor/ask_fon"))
        {command("shake "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 1)
        {command("think "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 2)
        {command("hmm "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 3)
        {command("arc "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 4)
        {command("stare "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 5)
        {command("dunno "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else
{
        command("tsk "+me->query("id"));
        command("say 没想到你竟然这么有耐性！");
        command("say 好吧！既然你我如此有缘分...");
        command("say 我就把‘灵天还魂术’传授给你！");
        command("say 但在这之前有个条件...");
        command("grin "+me->query("id"));
        me->delete("doctor/get_mark");
        me->set("doctor/ask_fon",1);
        return "";
    }
  }
}
string ask_but()
{
    object me=this_player();

    if(me->query("doctor/ask_fon") == 1)
{
        command("wa "+me->query("id"));
        command("say 好极了！你跟你的憋脚师父果然不同...");
        command("cac "+me->query("id"));
        command("say 我这个人平常除了练功就只有蒐集宝物这个嗜好...");
        command("say 如今「宇内五禽”我已得其三...");
        command("say 不知你能否帮我找到其余的两样咧？");
        me->delete("doctor/ask_fon");
        me->set("doctor/ask_but",1);
        return "";
  }
}
string ask_baby()
{
    object me=this_player();

    if(me->query("doctor/ask_but") == 1)
{
        command("say 宇内五禽是指「魔龙鳞”、「火凤羽”、「真龟血晶”、「麒麟圣爪”以及「天山鹰翅”...");
        command("say 我现在只差两样尚未蒐集到手...");
        command("say 其一便是魔界守护者炎龙的鳞片...世称「魔龙鳞”");
        command("say 而其二则是泷山之镇派圣兽火凤的羽毛...世称「火凤羽”");
        command("say 魔龙鳞之取得不难，但若欲向任正晴索得火凤羽，恐怕就不是件易事了...");
        command("say 不过...我听说任正晴的大儿子相当贪杯，你不妨就由此下手...");
        command("say 我言尽于此...接下来就看你自己的了...");
        command("addoil "+me->query("id"));
        me->delete("doctor/ask_but");
        me->set("doctor/ask_baby",1);
        return "";
  }
}
int accept_object(object me, object ob)
{
    string obj;
    int force = (int)me->query_skill("force",1);
    obj = ob->query("name");

    if(me->query("doctor/ask_baby") == 1)
{
    if(obj == HIY"魔龙鳞"NOR)
{
        command("tsk");
        command("say 好极了！原来这就是真正的"+ obj +"！");
        me->set("doctor/give_baby1", 1);
        destruct(ob);
    if(!me->query("doctor/give_baby2") == 1)
{
        command("say 咦...还有一个火凤羽咧？");
        return 1;
}
        command("spank "+me->query("id"));
        command("say 你的表现真是令我刮目相看...");
        command("say 想不到...都十年了...终于让我等到你了...");
        command("say 这两样宝物...哈哈！鬼才蒐集....");
        command("say 嗯...现在我便信守诺言，传授你‘灵天还魂术’！");
        message_vision("只见华云峰双掌贴于你的背心，将其体内的「天灵罡\气”缓缓的输入$N的体内...\n", me, ob);
        message_vision("$N的背心感到一股暖流慢慢流入，功力似乎有所大进！\n", me);
        me->set("doctor/save_die", 1);
        me->set_skill("force",force+5);
        log_file("quest_savedie", sprintf("%s(%s) 解开灵天还魂术 on %s\n"
        ,me->query("name"),me->query("id"), ctime(time()) ));
        me->delete("doctor/ask_baby");
        me->delete("doctor/give_baby1");
        me->delete("doctor/give_baby2");
        call_out("fon_die",2,me);
        return 1;
}
    if(obj == HIR"火凤羽"NOR)
{
        command("tsk");
        command("say 好极了！原来这就是真正的"+ obj +"！");
        me->set("doctor/give_baby2", 1);
        destruct(ob);
    if( !me->query("doctor/give_baby1") == 1)
{
        command("say 咦...还有一个魔龙鳞咧？");
        return 1;
}
        command("spank "+me->query("id"));
        command("say 你的表现真是令我刮目相看...");
        command("say 想不到...都十年了...终于让我等到你了...");
        command("say 这两样宝物...哈哈！鬼才蒐集....");
        command("say 嗯...现在我便信守诺言，传授你‘灵天还魂术’！");
        message_vision("只见华云峰双掌贴于你的背心，将其体内的「天灵罡\气”缓缓的输入$N的体内...\n", me, ob);
        message_vision("$N的背心感到一股暖流慢慢流入，功力似乎有所大进！\n", me);
        me->set("doctor/save_die", 1);
        me->set_skill("force",force+5);
        log_file("quest_savedie", sprintf("%s(%s) 解开灵天还魂术 on %s\n"
        ,me->query("name"),me->query("id"), ctime(time()) ));
        me->delete("doctor/ask_baby");
        me->delete("doctor/give_baby1");
        me->delete("doctor/give_baby2");
        call_out("fon_die",2,me);
        return 1;
} else {
        command("arc "+me->query("id"));
        command("say 你给我的这是啥鬼东西？");
        ob->move(me);
        message_vision("华云峰将"+ obj +"交还给$N...\n", me);
        return 1;
    }
  }
}
int fon_die(object me)
{
        write(HIY"华云峰突然急撤双手，一时头晕目眩，口吐鲜血...\n"NOR,me);
        call_out("fon_die2",1,me);
}
int fon_die2(object me)
{
        write(HIY"你赶紧为他把把脉，并按摩其各大脉穴...\n"NOR,me);
        call_out("fon_die3",5,me);
}
int fon_die3(object me)
{
        write(HIY"须臾...华云峰总算是醒了过来...\n"NOR,me);
        call_out("fon_die4",2,me);
}
int fon_die4(object me)
{
        write(HIY"华云峰吃力的说道：如...如今...我...已将...此技传...传...受予你.....望你好好善用...造福世人...\n"NOR,me);
        call_out("fon_die5",2,me);
}
int fon_die5(object me)
{
        write(HIY"说完此话，华云峰便因气力用尽而撒手人寰，与世长辞了...\n"NOR,me);
        this_object()->die();
        return 1;
}
