inherit NPC;
#include <ansi.h>
string an01();
void create ()
{
set_name("左铜门",({"Copper door of left","door","left"}));
set("long","
自从试炼之塔搭建成之后，就一直守护着左边铜门的守门者，久而久之
身体便与铜门同化了，最后只剩下一张脸与四肢露在铜门外，你可以问
他有关进入塔内的‘条件’是什么。\n");
set("age",200);
set("gender","男性");
set("title","试炼塔守门者");
set("inquiry",([
"条件" : (: an01 :),
]));
set("chat_chance", 10);
set("chat_msg", ({
HIY"左铜门眼珠子咕噜咕噜的转着，看起来似乎很无聊。\n"NOR,
}));

setup();
}
string an01()
{
command("hmm");
command("say 你必须要先到东边的售票庭买一张入场券才能进入。\n");
return "再跟你多说一点...里面的人都很强喔\n";
}
