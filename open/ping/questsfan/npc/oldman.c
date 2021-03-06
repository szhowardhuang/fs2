inherit NPC;     //无心老人 2000.4.2 by dhk
#include <ansi.h>
#include </open/open.h>
inherit F_MASTER;
string do_god();
string do_glaze();

void create()
{
  set_name("无心老人",({"noheart oldman","noheart","oldman"}));
  set("long","    昔有神农嚐百草，今有无心老人以一身贯古绝今的制药学术\n"
            +"，救济天下。他就是当今世上独一无二的‘"HIY"药神"NOR"’─\n"
            +"无心，他一肚子神奇的药剂知识，据说至今还未有他老人家配不\n"
            +"出的药。但是他个性孤僻，崇尚缘份说，故要找他老人家配药者\n"
            +"数千，但是得药者不出十人呀！\n");
  set("gender","男性"); 
  set("class","doctor");
  set("title",""HIR"毒神"HIY"药圣"NOR"");
  set("attitude","heroism");
  set("age",435);
  set("max_kee",10000);
  set("kee",10000);
  set("max_force",10000);
  set("force",10000);
  set("force_factor",10);
  set("combat_exp",3500000);
  set("inquiry",([
  "药神" : (:do_god:),
  "双麒麟火琉璃" : (:do_glaze:),
  ]));
  setup();
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
string do_god()
{
        object me=this_player();
        if(me->query("family/family_name")=="段家")
        {
         me->set_temp("dhk_glaze",1);
               return("哈哈哈！！！\n"+"最近我的运气真不错，不但配出一帖奇药，还无意间得到一样珍宝\n"+"‘"HIC"双麒麟"HIR"火琉璃"CYN"’真是幸运呀！哈哈哈！！！"NOR"\n");
}
else
{
command("?");
return("我只是一名孤苦伶仃的老人呀！");
}
}

int do_answer(string str)
{
  object me=this_player();
  object glaze=new("/open/ping/questsfan/obj/glaze.c");
  string *answer = ({
        "金创药",
        "越橘药",
        "三味甘露丹",
        "九转金丹",
        "黄莲解毒散",
        "二龙补心丹",
        "神龙百足散",
        "牛黄活窍散",
        "白云紫心丹",
        "六合反精散",
        "回生续命丹",
        "九转熊蛇丸",
        "生生造化丹"
  });
//已经修复会一直给东西的bug
   if(!me->query_temp("answer"));
  else
  {
   if(str == answer[me->query_temp("answer")])
    {
     command("pat "+me->query("id"));
     write(""HIY"很好"NOR"，" + RANK_D->query_respect(me) + ""CYN"的药学常识不错, 值得嘉许他日必能在江湖上扬名立姓。"NOR"\n");
     command("recruit " + me->query("id") );
     write(""CYN"嗯..既然你我有缘那我就把日前得到的‘"HIC"双麒麟"HIR"火琉璃"CYN"’赠与你吧！"NOR"\n");
//_________送物________//
    glaze->move(me);
command("smile "+me->query("id"));
      }
          else
          {
            command("sigh "+me->query("id"));
            write(RANK_D->query_respect(me)+""CYN"你的药学常识太肤浅了, 也许应该多去研究研究医理,下次有缘了再见吧！！！"NOR"\n");
          }
          me->delete_temp("answer");
        }
        return 1;
}

string do_glaze()
{
       object me=this_player();
        int which;
        string *question = ({
      ""WHT"硼砂"NOR"┼"YEL"蒲黄"NOR"",
      "大蒜┼"HIB"陈皮"NOR"",
      ""RED"当归"NOR"┼"HIR"红花"NOR"┼"HIC"人蔘"NOR"",
      ""RED"当归"NOR"┼"HIC"人蔘"NOR"┼"HIG"冬虫夏草"NOR"",
      ""HIY"黄莲"NOR"┼"HIY"黄笒"NOR"",
      ""HIY"九转熊蛇丸"NOR"┼"HIC"顺气丹"NOR"",
      ""HIM"田七"NOR"┼"RED"蜈蚣"NOR"",
      ""HIY"牛黄"NOR"┼"RED"蜈蚣"NOR"",
      ""HIM"紫背天葵"NOR"┼昙花",
      ""HIY"牛黄"NOR"┼"HIY"黄莲"NOR"┼樟脑",
      ""RED"当归"NOR"┼"HIC"人蔘"NOR"┼珍珠",
      ""HIY"九叶金兰"NOR"┼"CYN"熊胆"NOR"┼"HIG"龙舌草"NOR"",
      ""HIG"长生草"NOR"┼"HIR"化气红莲"NOR"┼长白山雪水"
        });
        if(me->query_temp("dhk_glaze")==1)
       {
        which=random(sizeof(question));
        if(me->query_temp("have_med"))
          write("怎么这么快又见面了? 下次再来吧。\n");
        else
        {
        write(" "+RANK_D->query_respect(me)+""CYN"想要双麒麟火琉璃吗？\n"+"若我们没有一定的缘份, 那就抱歉了。\n"+"老夫这就来试一试你, 看看你我是否有缘，准备回答("HIW"answer"CYN")我的问题吧！"NOR"\n");
write("无心老人缓缓的说道:"+question[which]+"\n");
        write(""CYN"无心老人和蔼的说道: 你能说说这些药材所能配出的药名吗?"NOR"\n");
        me->set_temp("have_med",1);
       me->set_temp("answer",which);
        }
        }
        else
        return("你问那么多干嘛….?");
}

