#include <ansi.h>
#include <combat.h>
#include </open/open.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("[1;34mÄ§µ¶Äª²â[0m",({"oldman"}));
set("long", "Ò»¸ö¿´ÆğÀ´È«ÉíÔà±_±_µÄÀÏÈË£¬½ÅÉÏ»¹ÓĞÒ»¸ö½Åîí£¬¿´ÆğÀ´ÏñÊÇ±»¹ØÔÚÕâÀïµÄ¡£\n");
        set("gender", "ÄĞĞÔ" );
        create_family("Ä§µ¶Äª²â",1,"¿ª´´Ê¼×æ");
        set("family/family_name","Ä§µ¶Äª²â");
        set("have_book",1);
        set("title","Ä§ÏÉÑ©¡«µ¶½£²Ô");
        set("age",70);
        set("env/Ä§ĞÔÁùÕ¶","YES");
      set("mpower",2);
        set("str",45);
        set("class","blademan");
        set("guild_class","blademan");
        set("cor", 30);
        set("cps", 30);
        set("int", 25);
        set("max_gin",1000);
        set("max_sen",1000);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",30);
        set("kee",5000);
        set("score",100000);
        set("max_kee",5000);
        set("bellicosity",3000);
        set_skill("cure",60);
        set_skill("riding",100);
        set_skill("force", 100);
        set_skill("blade",120);
        set_skill("dodge", 70);
        set_skill("move", 70);
        set_skill("powerforce", 100);
        set_skill("dragon-blade", 120);
        set_skill("parry", 100);
        map_skill("parry","dragon-blade");
        map_skill("blade","dragon-blade");
        map_skill("force","powerforce");
        set("combat_exp",1500000);
        set("chat_chance_combat",50);
        set_temp("apply/armor",100);
        set("chat_msg_combat",({
        (: perform_action, "blade.swy" :),
      }));
        set("inquiry", ([
"½Åîí":"Õâ¸ö½ÅîíÊÇÓÃÇ§Äêº®Ê¯´òÔìµÄ£¬Ò»°ã±øÆ÷ÊÇ¿³²»¶ÏµÄ¡£\n",
"Ç§Äêº®Ê¯":"ÕâÊÇ¾­¹ıÇ§ÄêÔĞÓı¶ø³ÉµÄ¼áÓ²Ê¯¿é£¬³ı·ÇÓĞÉñ±øÀûÆ÷£¬²»È»ÎŞ·¨¿³¶Ï¡£\n",
"Éñ±øÀûÆ÷":"ÌıËµÈË¼äÖÁ±¦¡¸½ğÁÛòşĞ°¡±ÅäÉÏ¡¸ÌìĞ°Ê¯¡±¿ÉÒÔ»ÙÃğÇ§Äêº®Ê¯¡£\n",
"½ğÁÛòşĞ°":"ÌıËµ½ğÁÛòşĞ°ºÃÏñÂäÔÚÃ©É½ÅÉÊÖÉÏ¡£\n",
"ÌìĞ°Ê¯":"ÌìĞ°Ê¯ÔÚ¶À¹Â³î´«ÈËµÄÊÖÀï¡£\n",
"Ê§´«°ÂÒå":"ÄÇÕĞÊÇ¿ñÁúµ¶·¨×îºóÒ»ÕĞ£¬¿ÉÏ§µ¶Æ×ÒÑ±»ÄªÎŞÀÖ¸ø¶á×ßÁË£¬
¡¡¡¡¡¡¡¡¡¡¡¡Èç¹ûÄãÄÜ¶á»ØÀ´£¬ÎÒ¾Í´«ÄãÄÇÊ§´«°ÂÒå¡£",
"ÄªÎŞÀÖ":"ÊÇÎÒ×îÏ²°®µÄÍ½µÜ£¬¿ÉÏ§ĞÄÊõ²»ÕıÏë´ÛÎÒÃÅ£¬ÓÖ¶áÈ¡ÎÒµ¶·¨×îºóÒ»Ê½£¬
¡¡¡¡¡¡¡¡¡¡×îºó±»ÎÒ¶ù×Ó´ò°Ü£¬¾Í²»ÖªÈ¥ÏòÁË£¬²»¹ı£®£®£®£®",
"²»¹ı":"²»¹ı£¬ÌıËµËûÈ¥Í¶¿¿ÊÀ³ğÑ©²ÔÅÉÈ¥ÁË£¬Ä¿Ç°Õ¼¾İÄ§ÁúËşµ±×÷ÒªÈû¡£",
"Ä§ÁúËş":"ÔÚÄ§µ¶ÃÅÄÚ£¬×Ô¼ºÈ¥ÕÒ°É£¡",
"Õò½ÌÖ®±¦":"¹ş¹ş......ÄÇÊÇÎÒµ±ÄêÍşÕğÎäÁÖÊ±ËùÓÃµÄÅäµ¶¡£\n",
"Åäµ¶":"ÄÇ°Ñµ¶ÊÇÎÒ¸Õ´³µ´½­ºş£¬¶øÎ´´´Á¢Ä§µ¶Ê±ÇÉÓö¹óÈË£¬µ«ÄÇÊ±ËûÒÑ¾­ÑÙÑÙÒ»Ï¢£¬´ÓËû¿ÚÖĞµÃÖªµ¶Ú£Î»ÖÃÖ®ºó£¬Ò²ÖªµÀ×îºÃµÄµ¶Ãû½Ğ¡®Ñıµ¶´åÓê¡¯¡£\n",
"Ñıµ¶´åÓê":"ÔÚ¶şÊ®ÄêÇ°Óë¶À¹Â³îÔÚÑ©²ÔÉ½Ò»Õ½ºó£¬ÄÇ°Ñµ¶¾ÍÊÜËğÁË£¬´Ëµ¶ÒÔ±»Ôá»Øµ¶Ú£¡£\n",
"µ¶Ú£":"àÅ...¿ÖÅÂÄã²»¹»×Ê¸ñµ½ÄÇ°É¡£\n",
"×Ê¸ñ":"Ö»ÒªÄãÄÜ½Ó×¡ÎÒÆßÕĞ£¬ÎÒ¾Í°Ñµ¶Ú£Î»ÖÃ¸úÄãËµ(test ×Ê¸ñ)¡£\n",
"ÄªÔÆ":"²»¹ıËûÏÉÓÎÒÑ¾Ã£¬²»¹ıÌıËµÓĞ´«ÈË£¬´«ÈËºÃÏñÒ»Ö±´ıÔÚÎ÷Óò°É£¡\n",
        ]));
        add_temp("apply/dodge",30);
        setup();
        carry_object("/daemon/class/blademan/obj/iceblade")->wield();
}
void attempt_apprentice(object ob)
{
if(this_player()->query_skill("dragon-blade",1)<105)
{
command("say ¿ñÁúµ¶·¨¶¼Ñ§²»ºÃÁË£¡»¹Ïë°İÎÒ£¡¹ö£¡Äã¸øÎÒ¹ö¿ª£¡\n");
return ;
}
if(this_player()->query("have_book")!=1)
{
command("say ËäÈ»Äã¿ñÁúµ¶·¨ÒÑµ½´ïÒ»¶¨Ë®×¼£¡µ«ÊÇÉĞÈ±ÉÏ³Ë°ÂÒå£¡");
command("say ¿ÉÏ§£¡ÎÒ±ÏÉúËù×êÑĞµÄµ¶Æ×£¡È´±»ÄªÎŞÀÖ¸øµÁ×ßÁË£¡");
command("say Èç¹ûÄãÄÜ×·»ØµÄ»°£¡ÎÒ¾ÍÊÕÄãÎªÍ½£¡¸ü´«ÄãÄ§µ¶×îºóÊ§´«°ÂÒå£¡");
return ;
}
        command("smile");
        command("say àÅ£¬¹ûÈ»Çà³öÓÚÀ¶£¬´Ó½ñºóÀÏ·òÇ××Ô´«ÊÚÓÚÄã¡£");
        command("say µ«ÊÇÄ§µ¶ÎäÑ§²»ÄÜÍâ´«£¬ÇĞ¼Ç£¬ÇĞ¼Ç¡£");
        ob->delete("family");
        command("recruit "+this_player()->query("id"));
if(this_player()->query("m_blade")==1) {
this_player()->set("title","[1;31mÄ§µ¶[1;37m¡®ÈıÕ¶¹éÔª¡¯[1;35m´«ÈË[0m"); } else {
        this_player()->set("title",HIC"Ä§µ¶¾øÊÀ´«ÈË"NOR);
}
        this_player()->set("no_recruit", 1);
        message("system",HIB"Ä§µ¶Äª²â×İÉù¿ñĞ¦:
\n¹ş¹ş¹ş¹ş¡«¡«Ä§µ¶Ò»³ö¡«¡«ÑªÁ÷³ÉºÓ¡«¡«ÎŞËùÆ¥µĞ¡£\n"NOR,users());
        return ;
        }
int accept_object(object who,object ob)
{
string ob_id;
ob_id=ob->query("id");
if(who->query("quests/blade_out")==0||who->query_skill("dragon-blade",1)>=105)
{
if(who->query("evil-mblade")==1) {
if(ob_id=="bad-evil-mblade") {
command("say Ì«ºÃÁË£¬ÕâÕıÊÇÎÒÖ®Ç°µÄÅäµ¶£¡");
command("say ¿ÉÏ§µ¶ÉíÒÔ»Ù£¬µ±½ñÊÀÉÏÖ»ÓĞ¡®ÄªÔÆ¡¯»áĞŞ£¡");
command("say ÄãÈ¥ÕÒËû°É£¡");
command("give "+this_player()->query("id")+" bad-evil-mblade");
}}
if(ob->query("id")=="dragon-blade book"&&who->query("family/family_name")=="Ä§µ¶ÃÅ")
{
if(who->query("have_book")==0)
{
destruct(ob);
command("say Äã¾¹ÄÜ½«µ¶Æ××·»Ø£¬¹ûÈ»ÊÇ¸ö¿ÉÔìÖ®²Å£¡");
command("say ºÃ£¬ÎÒ¾Í½«¿ñÁúµ¶·¨¡®Ê§´«°ÂÒå¡¯´«¸øÄã£¡\n");
who->set("have_book",1);
}
}
if(ob_id=="stone"&&who->query_temp("give_1")==0)
{
destruct(ob);
command("say ÎÒÃ»¿´´í°É£¬Äã¾¹È»ÄÜ½«ÌìĞ°Ê¯ÄÃµ½ÊÖ£¡");
this_player()->set_temp("give_1",1);
}
if(ob_id=="snake sword"&&who->query_temp("give_2")==0)
{
destruct(ob);
command("say Ì«ºÃÁË£¬ÕâÕıÊÇÎÒĞèÒªµÄ¶«Î÷£¡");
this_player()->set_temp("give_2",1);
}
if(who->query_temp("give_1")==1&&who->query_temp("give_2")==1&&who->query("quest/blade_out/get_force")==0)
{
    command("say Ì«ºÃÁË£¡");
    message_vision(
             HIY
"$n½«ÌìĞ°Ê¯µÄÉñÁ¦×¢Èë½ğÁÛòşĞ°Ö®ÖĞ£¬È»ºóÔË¾¢Ò»¿³£¬½«½Åîí¿³¶Ï¡£\n" NOR,this_player(),this_object());
    CHANNEL_D->do_channel(this_object(),"mud",HIR
"Ô¶´¦´«À´Ä§µ¶Äª²âµÄ´óºÈ:\nÎÒ×ÔÓÉÁË£¡¹ş¹ş¹ş¹ş£¡\n¶À¹Â³î£¡ÄãÕâ¸öÀÏÔôµÈ×Å°É£¡ÎÒÒªÒ»Ñ©ÕâÊ®¼¸Äê½ûïÀÖ®ºŞ£¡\n"NOR);
           command("say ¸ĞĞ»ÄãÊÍ·ÅÁËÎÒ£¬ÎÒÕâ¾ÍÈ¥Ô×ÁË¶À¹ÂÀÏÔô¡£");
           command("say ²»¹ı¿´ÔÚÄãÔø°ïÎÒ£¬ºÃ°É£¬ÎÒ½«²¿·ÖÄÚÁ¦´«¸øÄã¡£");
           this_player()->add("max_force",100);
           this_player()->add("force",100);
           who->set("quests/blade_out",1);
           who->set("quest/blade_out/get_force",1);
           return 1;
}
}
}
void init()
{
   add_action("do_test","test");
}
int do_test(string str)
{
        int i;
        object ob=this_object();
        object me=this_player();
if(me->query_temp("sublade")==1)
return notify_fail("µ¶Ú£µÄÂ·¾ÍÔÚŞµÀóÂÜÁÖÄÚ£¡\n");
if(me->query("m_blade")!=1)
return notify_fail("ÒÀÄãÄ¿Ç°ÄÜÁ¦Ã»×Ê¸ñ½ÓÎÒÆßÕĞ£¬µÈÄãÓĞÈıÕ¶ÔÙÀ´°É£¡\n");
    if(str=="×Ê¸ñ")
        {
          command("say ºÃ! ´ıÀÏ·òÀ´ÊÔÊÔÄã! Ğ¡ĞÄÁË");
     for(i=0;i<7;i++)
COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), TYPE_QUICK);

          if( me->query("kee") > 500 )
          {
 command("say ¹ûÈ»ÕæÓĞ±¾ÊÂ£¡ÈçÄãÄÜ°ïÎÒ°ÑÅäµ¶È¡»Ø£¬ÎÒ¾Í´«Äã´Ëµ¶£¡");
     command("say µ¶Ú£µÄÂ·¾ÍÔÚŞµÀóÂÜÁÖÄÚ£¡×ÔĞĞÕÒ°É¡£");
            me->set_temp("sublade",1);
          }
          else
          {
            command("say ÄãÔÙ¼ÓÇ¿×Ô¼º±¾ÊÂ°É£¡");
          }}
        else {
          write("½ÓÊÜÊ²Ã´?!\n");
        }
return 1;
}
void heart_beat()
{
object me,room,*target;
int i,j;
me=this_object();
if( me->is_fighting() && random(100) > 60 && !me->query_temp("fast-dest") ) 
{
message_vision(HIC"\nÄ§µ¶Äª²â³ÔÆğÒ©Íè²¹³äÑªÆø¡£\n"NOR,me);
me->receive_curing("kee",1500);
me->receive_heal("kee",1500);
me->delete_busy();
me->clear_condition();
   }
  ::heart_beat();
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
   if (winner && userp(winner))  {
tell_object(users(),HIR"\n\nÄ§µ¶Äª²âÑöÌìÅ­ºğ£º\n\n\tÏëµ±ÄêÀÏ·òµ¶·¨ÃûÕğÎäÁÖÈ´°ÜÓÚ"+winner->name()+HIR"ÊÖÉÏ£¡
\n\tÃ»Ïëµ½¾¹È»ÓĞ±È¶À¹ÂÀÏÔô¸üÀûº¦µÃÈËÎï£¡°ÕÁË°ÕÁË£¡\n\n"NOR);
   }
        :: die();
}

