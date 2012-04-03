//炼妖壶

#include <ansi.h>
inherit ITEM;
int exp=0;
void create()
{
        set_name(HIB"炼妖壶" NOR, ({"lotch"}));
        set("long",
                "上古神物 -- 炼妖壶 . 可用 help lotch 查询用法 \n");
        set("unit", "个");
        /*
        set("value", 10000000);
        */
        set("weight",500);
        setup();
}

void init()
{
        if( this_player()==environment() )
                add_action("catch_enemy","catch");
                add_action("use_lotch","use");
                add_action("check_exp","check");
        add_action("help_lotch","help");
}


int catch_enemy(string str)
{
        object ob;
        int i, exp1 , exp2;

        if(!this_player()->query("quests/lotch") )
        return notify_fail("你还不会使用炼妖壶 !\n");
        if(!str)
                return notify_fail("你要抓什 ?\n");
        if( (int)this_player()->query("sen")<15)
                return notify_fail("你没有足够精神力用炼妖壶 \n");
        str=lower_case(str);
        if(!objectp(ob=present(str,environment(this_player()))))
                return notify_fail("没这种生物 !\n");
        if(userp(ob))
                return notify_fail("哇哩勒 , 连 player 也要抓 ?\n");
// 为了避免 no heart 出现修正不能战斗中用 by swy
if( this_player()->is_fighting() )
return notify_fail("你在战斗中不能使用。\n");
//modify by Rong 85.4.6 使炼妖壶不能收非生物
if(!ob->is_character())
        return notify_fail("炼妖壶传出一阵声音: 很抱歉,这东西没有生命力!!\n");
        
        if( (int) ob->query("max_kee")/2< (int) ob->query("kee"))
        {
                this_player()->add("sen",-1);
                return notify_fail("敌人仍然生命力旺盛 , 你无机可趁 !\n");
        }
        message_vision( sprintf(HIW"$N拿出炼妖壶 ,念了几句咒语 \n"NOR),this_player());
        exp1= (int)ob->query("combat_exp");
        exp2=(int)this_player()->query("combat_exp");
        if( random(exp2) > random(exp1)/2 )
        {
        exp = exp + exp1/2;
        message_vision( sprintf(HIC"结果成功的把$N收进壶中\n"NOR),ob);
        destruct(ob);
        this_player()->add("sen",-15);
        return 1;
        }
        message_vision( sprintf(HIB"结果$N在千钧一发之际 , 躲了开去\n"NOR),ob);
        this_player()->add("sen",-1);
        return 1;
       
}
int check_exp(string str)
{
string line;
        if(!str || str!="lotch")
        return notify_fail("你要干麻 ?\n");
        if(!this_player()->query("quests/lotch") )
        return notify_fail("你还不会使用炼妖壶 !\n");
        line=sprintf("炼妖壶现有能量%d点\n",exp);
        write(line);
        return 1;
}
int use_lotch(string str)
{
        int exp3;
        object ob;
        if(!str || str!="lotch")
        return notify_fail("你要使用什么东西 ?\n");
        if(!this_player()->query("quests/lotch"))
        return notify_fail("你还不会使用炼妖壶 \n");
        if(!this_player()->is_fighting())
        return notify_fail("只有在战斗中才能放出妖魔 !\n");
 if(environment(this_player())->query("no_scale")==1)
return notify_fail("此处是 pkla 场不能使用。\n");
        if(exp==0)
        return notify_fail("现在壶内无任何能量 !\n");
        if(exp < 300)
        return notify_fail("壶内的能量不够!!!无法放出妖魔\n");
        if((int)this_player()->query("sen")<30)
                return notify_fail("你的经神力不足 !\n");
        message_vision(sprintf(HIW"$N拿出了炼妖壶 , 将壶内妖魔释出 \n\n"NOR),this_player());
        exp3=this_player()->query("combat_exp");
        this_player()->add("sen",-30);

      if(exp/5 > exp3)
        {
        if(exp3*5<500)
            { ob=new("/open/gblade/mob/test1.c");
            exp=exp-300; }
        if(exp3*5<2000&&exp3*5>=500)
            { ob=new("/open/gblade/mob/test2.c");
            exp=exp-500; }
        if(exp3*5<5000&&exp3*5>=2000)
            { ob=new("/open/gblade/mob/test3.c");
            exp=exp-2000; }
        if(exp3*5<10000&&exp3*5>=5000)
           {  ob=new("/open/gblade/mob/test4.c");
            exp=exp-5000; }
        if(exp3*5<15000&&exp3*5>=10000)
           { ob=new("/open/gblade/mob/test5.c");
            exp=exp-10000;}
        if(exp3*5<20000&&exp3*5>=15000)
           { ob=new("/open/gblade/mob/test6.c");
            exp=exp-15000;}
        if(exp3*5<30000&&exp3*5>=20000)
           { ob=new("/open/gblade/mob/test7.c");
            exp=exp-20000 ;}
        if(exp3*5<40000&&exp3*5>=30000)
           { ob=new("/open/gblade/mob/test8.c");
            exp=exp-30000 ;}
        if(exp3*5<50000&&exp3*5>=40000)
           { ob=new("/open/gblade/mob/test9.c");
            exp=exp-40000;}
        if(exp3*5<100000&&exp3*5>=50000)
           { ob=new("/open/gblade/mob/test10.c");
            exp=exp-50000;}
        if(exp3*5<150000&&exp3*5>=100000)
           { ob=new("/open/gblade/mob/test11.c");
            exp=exp-100000;}
        if(exp3*5<200000&&exp3*5>=150000)
           { ob=new("/open/gblade/mob/test12.c");
            exp=exp-150000;}
        if(exp3*5<250000&&exp3*5>=200000)
           { ob=new("/open/gblade/mob/test13.c");
            exp=exp-200000;}
        if(exp3*5<300000&&exp3*5>=250000)
           { ob=new("/open/gblade/mob/test14.c");
            exp=exp-250000;}
        if(exp3*5<350000&&exp3*5>=300000)
           { ob=new("/open/gblade/mob/test15.c");
            exp=exp-300000;}
        if(exp3*5<400000&&exp3*5>=350000)
           { ob=new("/open/gblade/mob/test16.c");
            exp=exp-350000;}
        if(exp3*5<450000&&exp3*5>=400000)
           { ob=new("/open/gblade/mob/test17.c");
            exp=exp-400000;}
        if(exp3*5<500000&&exp3*5>=450000)
           { ob=new("/open/gblade/mob/test18.c");
            exp=exp-450000;}
        if(exp3*5<750000&&exp3*5>=500000)
           { ob=new("/open/gblade/mob/test19.c");
            exp=exp-500000;}
        if(exp3*5<1000000&&exp3*5>=750000)
           { ob=new("/open/gblade/mob/test20.c");
            exp=exp-750000;}
        if(exp3*5<1250000&&exp3*5>=1000000)
           { ob=new("/open/gblade/mob/test21.c");
            exp=exp-1000000;}
        if(exp3*5<1500000&&exp3*5>=1250000)
           { ob=new("/open/gblade/mob/test22.c");
            exp=exp-1250000;}
        if(exp3*5<2000000&&exp3*5>=1500000)
           { ob=new("/open/gblade/mob/test23.c");
            exp=exp-1500000;}
        if(exp3*5<2500000&&exp3*5>=2000000)
           { ob=new("/open/gblade/mob/test24.c");
            exp=exp-2000000;}
        if(exp3*5>=2500000)
           { ob=new("/open/gblade/mob/test25.c");
            exp=exp-2500000;}

        }
       else
        {
          if(exp<500) 
            { ob=new("/open/gblade/mob/test1.c");
             exp=exp-300;}
        if(exp<2000&&exp>=500)
            { ob=new("/open/gblade/mob/test2.c");
             exp=exp-500;}
        if(exp<5000&&exp>=2000)
            { ob=new("/open/gblade/mob/test3.c");
             exp=exp-2000;}
        if(exp<10000&&exp>=5000)
            { ob=new("/open/gblade/mob/test4.c");
             exp=exp-5000;}
        if(exp<15000&&exp>=10000)
            { ob=new("/open/gblade/mob/test5.c");
             exp=exp-10000;}
        if(exp<20000&&exp>=15000)
            { ob=new("/open/gblade/mob/test6.c");
             exp=exp-15000;}
        if(exp<30000&&exp>=20000)
            { ob=new("/open/gblade/mob/test7.c");
             exp=exp-20000;}
        if(exp<40000&&exp>=30000)
            { ob=new("/open/gblade/mob/test8.c");
             exp=exp-30000;}
        if(exp<50000&&exp>=40000)
            { ob=new("/open/gblade/mob/test9.c");
             exp=exp-40000;}
        if(exp<100000&&exp>=50000)
            { ob=new("/open/gblade/mob/test10.c");
             exp=exp-50000;}
        if(exp<150000&&exp>=100000)
            { ob=new("/open/gblade/mob/test11.c");
             exp=exp-100000;}
        if(exp<200000&&exp>=150000)
            { ob=new("/open/gblade/mob/test12.c");
             exp=exp-150000;}
        if(exp<250000&&exp>=200000)
            { ob=new("/open/gblade/mob/test13.c");
             exp=exp-200000;}
        if(exp<300000&&exp>=250000)
            { ob=new("/open/gblade/mob/test14.c");
             exp=exp-250000;}
        if(exp<350000&&exp>=300000)
            { ob=new("/open/gblade/mob/test15.c");
             exp=exp-300000;}
        if(exp<400000&&exp>=350000)
            { ob=new("/open/gblade/mob/test16.c");
             exp=exp-350000;}
        if(exp<450000&&exp>=400000)
            { ob=new("/open/gblade/mob/test17.c");
             exp=exp-400000;}
        if(exp<500000&&exp>=450000)
            { ob=new("/open/gblade/mob/test18.c");
             exp=exp-450000;}
        if(exp<750000&&exp>=500000)
            { ob=new("/open/gblade/mob/test19.c");
             exp=exp-500000;}
        if(exp<1000000&&exp>=750000)
            { ob=new("/open/gblade/mob/test20.c");
             exp=exp-750000;}
        if(exp<1250000&&exp>=1000000)
            { ob=new("/open/gblade/mob/test21.c");
             exp=exp-1000000;}
        if(exp<1500000&&exp>=1250000)
            { ob=new("/open/gblade/mob/test22.c");
             exp=exp-1250000;}
        if(exp<2000000&&exp>=1500000)
            { ob=new("/open/gblade/mob/test23.c");
             exp=exp-1500000;}
        if(exp<2500000&&exp>=2000000)      
            { ob=new("/open/gblade/mob/test24.c");
             exp=exp-2000000;}
        if(exp>=2500000)
            { ob=new("/open/gblade/mob/test25.c");
             exp=exp-2500000;}

       }

        ob->move(environment(this_player()));
        ob->invocation(this_player());
        return 1;
}

int help_lotch(string str)
{
        if(str!="lotch")  return 0;
        write(@HELP
炼妖壶可将对战中生命力薄弱之敌人吸入壶中 , 化为能量
在对战时又可将壶内能量释出 , 以为己助 , 但妖魔仅能
助己一回 , 壶内能量可一直累积 , 当壶内拥有能量 , 即
可放出妖魔 , 可放出之妖魔能力最多为使用者之五倍 , 随
着本身之成长 , 所能炼出之妖魔将有所不同 !

指令:
        catch xxx  :将作战中之敌人吸入壶中
        check lotch:查询壶内能量
        use lotch  :放出妖魔 , 以为己助
HELP
        );
        return 1;
}
