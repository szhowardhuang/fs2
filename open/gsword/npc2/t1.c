#include <ansi.h>
inherit NPC;
string ask_test();
string ask_train();

void create()
{
        set_name(HIW"µÚÒ»ÊÔÁ¶Õß"NOR, ({ "testman"}) );
        set("gender", "ÄÐÐÔ" );
        set("age", 63);
        set("int", 26);
set("long","´«ËµÖÐ×¨ÃÅ¶ÍÁ¶ÏÉ½£ÅÉÃÅÈËµÄÊØ»¤Õß..Äã¿ÉÒÔÎÊËûÓÐ¹ØÊÔÁ¶µÄÊÂ¡£\nÄãÒà¿ÉÒÔÑ¯ÎÊËûÄã»¹ÐèÒªÑµÁ·¶à¾Ã(ask testman about train)¡£\n");
        set("inquiry",([
        "ÊÔÁ¶":(:ask_test:),
        "train" : (:ask_train:),

        ]));
        set("combat_exp",50000);
        set("max_kee",500);
        set("max_gin",500);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("force",50);
        setup();
   }

string ask_test()
{
if (this_player()->query("quests/test")>199&& this_player()->query("quests/yan")==2)
 {
  this_player()->set("quests/yan",3);
  tell_object(this_player(),HIW"ÄãÒÑ¾­Í¨¹ýµÚÒ»ÊÔÑéÁË.ËùÒÔÎÒËÍÄãµ½µÚ¶þÊÔÁ¶ÇøÈ¥°É.\n"NOR);  
  message("system",this_player()->name()+HIW"Í¨¹ýÏÉ½£µÚÒ»ÊÔÁ¶¡£\n"NOR,users());
  this_player()->set("title","[1;36mÏÉ½£µÚÒ»ÊÔÁ¶½£ÏÀ[0m");
  this_player()->move("/open/gsword/room2/shaa1.c"); 
}
else if(this_player()->query("quests/yan")>2) {
  tell_object(this_player(),HIW"ÄãÒÑ¾­Í¨¹ýµÚÒ»ÊÔÑéÁË.ËùÒÔÎÒËÍÄãµ½µÚ¶þÊÔÁ¶ÇøÈ¥°É.
\n"NOR);
  this_player()->move("/open/gsword/room2/shaa1.c");
}
else
{
tell_object(this_player(),HIW"µÚÒ»ÊÔÑéµÄÄ¿µÄÔÚÓÚ¶ÍÁ¶Äã¶ÔÏÉ½£ÎäÊõµÄÈÏÖª¼°ÁË½â..\n"NOR);
 return (HIW"Òò´ËÄãµÃÍù±±·½Ç°½ø..²¢ÔÚÊÔÁ¶É½¹ÈÖÐ´òµ¹200¸öÊÔÁ¶ÎäÕß²ÅÐÐ\n"NOR);
 }

}
string ask_train()
{

 int num;
 num=this_player()->query("quests/test",1);
 if (num<200)
   return sprintf("¸óÏÂÄ¿Ç°´òµ¹ÁË%d¸öÊÔÁ¶ÎäÕß ,ÔÙ¼ÓÓÍ°É!\n",num);
 else 
 return sprintf("¸óÏÂÒÑ¾­¾ßÓÐÍ¨¹ýµÚÒ»ÊÔÁ¶µÄ×Ê¸ñÁË..Äã¿ÉÒÔÔÙÏòÎÒÑ¯ÎÊÒ»´ÎÓÐ¹ØÊÔÁ¶µÄÊÂ!");
 }
