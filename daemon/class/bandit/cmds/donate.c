// donate.c by Anmy

#include <ansi.h>

inherit F_GUILDCMDS;

void pre_donate();
void do_donate(object ,object);

int main(object me, string arg)
{
        object env;
        object *inv;
        int i;
        env = environment(me);

        if( arg=="cancel" ) {
                if( !me->query_temp("募捐中") )
                        return notify_fail("怎啦,你还没准备好募捐吧..\n");
                tell_object(me, HIW"你开始收起破碗公,离开这里。\n"NOR);
                me->delete("greeting_msg");
                me->set("id", me->query("old_id"));
                me->set("name", me->query("old_name"));
                me->set("nickname", me->query("old_nick"));
                me->set("title", me->query("old_title"));
                me->delete("old_id");
                me->delete("old_name");
                me->delete("old_nick");
                me->delete("old_title");
                me->delete_temp("募捐中");
                me->delete_temp("不准走");
                return 1;
        }
        if( me->query_temp("募捐中") )
                return notify_fail("你已经把破碗公准备好收钱了...\n");
        if( me->is_fighting() )
                return notify_fail("把敌人打死了钱自然是你的，抢什么抢。\n");
        inv = all_inventory(env);
/*
        for( i=0; i<sizeof(inv); i++ ) {
                if( userp(inv[i]) && inv[i]!=me )
                        return notify_fail("这里还有别人在，现在蒙面会被发现吧。\n");
        }
*/
        tell_object(me,"你把破碗公放到地上,等待人来施舍..\n");
        if( !me->query("old_id") ) {
                me->set("old_id", me->query("id"));
                me->set("old_name", me->query("name"));
                me->set("old_nick", me->query("nickname"));
                me->set("old_title", me->query("title"));
                me->set("id", "buddha");
                me->set("name", "佛陀");
                me->set("title", HIY"传道．授业．解惑也"NOR);
                me->delete("nickname");
        }
        me->set_temp("募捐中", 1);
        me->set_temp("不准走", 1);
        me->set("greeting_msg", ({
        (:call_other,file_name(this_object()),"pre_donate":),
        }) );
        return 1;
}

void pre_donate()
{
        int i;
        object *inv, bandit;
        object ob = this_player();

//        if( wizardp(ob) ) return;

        inv = all_inventory(environment(ob));
        for( i=0; i<sizeof(inv); i++ ) {
                if( inv[i]->query_temp("募捐中") )
                        bandit = inv[i];
        }

        if( ob->query_temp("已捐钱") )
return;
        ob->set_temp("不准走", 1);
        call_out("do_donate", 1, bandit, ob);
}

void do_donate(object bandit, object ob)
{
        int face, money, kee;

        tell_object(bandit,HIW"\n 你正盘坐在地上, 微笑的对着"+ob->name()+"说：\n\n‘阿弥陀佛, 我佛慈悲, 施主是否能施舍点钱, 以便重建天龙寺’\n\n"NOR);

        face =( bandit->query_skill("change",1)+bandit->query("kar") < random(ob->query("combat_exp")/10000)+ob->query("int") );
        if( face )  tell_object(bandit,HIW"啊, 对方已看穿以是假冒的。\n"NOR);


        tell_object(ob,HIC"\n你往下一看，"+(face?bandit->query("old_name"):"一个和尚")+"正微笑的看着你说：\n\n‘阿弥陀佛, 我佛慈悲, 施主是否能施舍点钱, 以便重建天龙寺’\n\n"NOR);

        money = ( ob->query("combat_exp")/5000 + 1 ) * 100;

        if( bandit->query("kar")*bandit->query("combat_exp")/10 > ob->query("cor")*ob->query("combat_exp")/20 ) {
                tell_object(bandit,"于是你对"+ob->name()+"叙说着种种道理，"+ob->name()+"似乎有开悟的感受，所以"+ob->name()+"毫不客气的捐了点钱给你。\n");
tell_object(ob,"于是和尚对你叙说着种种道理，你似乎有开悟的感受，所以你毫不客气的捐了点钱给和尚\n");
                if( ob->can_afford(money) ) {
                        ob->pay_money(money);
                        bandit->pay_player(money);
                        tell_object(ob,HIC"你捐给"+(face?bandit->query("old_name"):"和尚")+"一些心意。\n"NOR);
                        tell_object(bandit,HIC""+ob->name()+"捐给一点心意。\n"NOR);
                        tell_object(ob,HIW""+(face?bandit->query("old_name"):"和尚")+"微笑的说道：施主此行大恩大德, 改日另行感谢\n"NOR);
                        tell_object(bandit,HIW"你微笑的说道：施主此行大恩大德,改日另行感谢\n"NOR);
                } else {
                        tell_object(ob,(face?bandit->query("old_name"):"和尚")+"看你身上好似没钱，微笑的说: 让和尚我为您强健身筋吧。\n");
                        tell_object(bandit,"你看着"+ob->name()+"身上好似没钱，微笑的说: 和尚我来教你点强身之道吧。\n");
                        kee = ob->query("eff_kee")*3/4;
                        ob->set("eff_kee", kee);

tell_object(ob,HIC""+(face?bandit->query("old_name"):"和尚")+"教了你一些基本基础的功夫, 你发觉快累垮了。\n"NOR);
                        tell_object(bandit,HIC"你教了"+ob->name()+"一点基本的功夫。\n"NOR);
                        tell_object(ob,HIY""+(face?bandit->query("old_name"):"和尚")+"对着你微笑：行走江湖要小心点, 以免受伤\n"NOR);
tell_object(bandit,HIY"你对着"+ob->name()+"微笑: 行走江湖要小心点\n"NOR);
                }
        } else {
                if( bandit->can_afford(money) ) {
tell_object(ob,"和尚说着种种道理,你丝毫没有听进去,只看着和尚的碗公有钱,于是你就心存邪念,抢了可怜和尚的钱。\n");
tell_object(bandit,"你说着种种道理,"+ob->name()+"丝毫没有听进去,只看着你的碗公有钱,于是"+ob->name()+"就心存邪念,抢了你的钱。\n");
                        bandit->pay_money(money);
                        ob->pay_player(money);
tell_object(ob,HIY""+bandit->query("old_name")+"施舍了点钱给你。\n"NOR);

tell_object(bandit,HIY"你施舍了"+ob->name()+"一些钱。\n"NOR);
                } else {
tell_object(ob,"和尚说着种种道理,你丝毫没有听进去,只看着和尚的碗公有钱,于是你就心存邪念,抢了可怜和尚的钱。\n");
tell_object(bandit,"你说着种种道理,"+ob->name()+"丝毫没有听进去,只看着你的碗公有钱,于是"+ob->name()+"就心存邪念,抢了你的钱。\n");
                        kee = bandit->query("eff_kee")*3/4;
                        bandit->set("eff_kee", kee);
                        tell_object(ob,HIC"你将"+bandit->query("old_name")+"的钱狠狠的全拿光。\n"NOR);
                        tell_object(bandit,HIC""+ob->name()+"将你的钱拿光了。\n"NOR);
                }
                tell_object(ob,HIC"你仰天长笑说："+bandit->query("old_name")+"算你倒霉,本大人信耶稣不信佛\n"NOR);
                tell_object(bandit,HIC""+ob->name()+"仰天长笑着说："+bandit->query("old_name")+"算你倒霉, 本大人信耶稣不信佛的啦, 哇哈哈哈哈哈哈哈哈..\n"NOR);
        }

        ob->delete_temp("不准走");
        ob->set_temp("被抢过", 1);
}

int help(object me)
{
        write(@HELP

指令格式： cmd donate [cancel]

说明：此指令能让你就地对路人募钱
      自己不能移动。
      加上 cancel 参数会停止募捐。

HELP);
        return 1;
}
