#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_man()
{
        object ob=this_player();
        if( ob->query_temp("high-man") >= 3 )
        {
        ob->set_temp("high-man", 4);
        return("ËûĞÔÇé¼«ÎªÎÂºÍ, ºÃ´ò±§²»Æ½, ÎÒÔÚ 3 ÄêÇ°·î½ÌÖ÷Ö®ÃüÇ°ÍùÖĞÔ­°ìÊÂ, »ØÍ¾ÊÜÏ®, ĞÒ¿÷´ËÎ»¸ßÈË´î¾È²ÅĞÒÃâÓÚÄÑ!!ËûËÄ´¦ÔÆÓÎ, Õæ²»ÖªµÀÒªÈçºÎ²ÅÄÜÓöµ½Ëû??
²»¹ıÀÏ·òÏàĞÅ, Ö»ÒªÓĞÈËÓöµ½Î£ÄÑÊ±, ËûÓ¦¸Ã»áÍ¦Éí¶ø³ö°É!!\n");
        }
        else
        {
        return("àÅ, ÄãÎÊÕâĞ©Òª×öÉ¶ÄØ??\n");
        }
}        

void create()
{
        set_name("´«¹¦³¤ÀÏ", ({"gonfu_elder","gonfu","elder"}));
        set("long",@LONG

        Ê¥»ğ½Ì»¤½Ì³¤ÀÏÖ®Ò»µÄ´«¹¦³¤ÀÏ£¬ÏÈÌìÇ¬À¤¹¦µÄÔìÒè
        ÒÑÊÇÈçÍ¬ÉñÒ»°ãµÄÄª²â£¬¾ÍÁ¬½ÌÖ÷Ò²×ÔÌ¾¸¥Èç£¡·Ç³£
        Ï²°®ÎäÑ§·½ÃæµÄ±ÈÊÔ£¬¶øÇÒ¶ÔÓÚ¸÷¼ÒµÄÎäÑ§¾ùÄÜÂÔÊö
        Ò»¶ş£¬ÊÇ½ÌÄÚµÄÎäÑ§Í¨£®Óë¸±½ÌÖ÷ÎäĞÇ¾ıÊÇ°İ°ÑĞÖµÜ£®

LONG);
        set("gender","ÄĞĞÔ");
        set("class","prayer");
        set("nickname","Îä³Õ");
        set("family/master_name","ÁÖºêÉı");
        set("combat_exp",1500000);
        set("attitude","heroism");
        set("age",58);
        set("title","Ê¥»ğ½Ì");
        set("kee",5500);
        set("max_kee",5500);
        set("force",10000);
        set("max_force",10000);
        set("force_factor",15);
        set("max_gin",2800);
        set("max_sen",2800);
        set_skill("superforce", 90);
        set_skill("dodge", 60);
        set_skill("cure",65);
        set_skill("literate",65);
        set_skill("force",90);
        set_skill("holy-force",85);
        set_skill("move", 70);
        set_skill("canon",90);
        set_skill("parry", 70);
        set_skill("universe",95);
        set_skill("unarmed", 90);
        set_skill("shift-steps",85);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("inquiry",([
        "ÒşÊÀ¸ßÈË":(: ask_man :),
        ]));
        set("functions/goldsun/level",60);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("goldsun") :),
        }));
        setup();
        create_family("Ê¥»ğ½Ì",4,"³¤ÀÏ");
    carry_object("/open/prayer/obj/dragon-robe")->wear();
    carry_object("/open/prayer/obj/dragon-hat")->wear();
    carry_object("/open/prayer/obj/dragon-hands")->wear();
    carry_object("/open/prayer/obj/dragon-icer")->wield();
    carry_object("/open/prayer/obj/dragon-legging")->wear();
    add_money("gold",10);
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_9"))
        {
        command("say Ã»ÓĞ½ÌÖ÷µÄÍ¬Òâ,ÎÒ²»¸ÒÉÃ×Ô×öÖ÷ÊÕÄãÎªÈëÊÒµÜ×Ó!");
        return 0;
        }
        command("smile");
        command("say ¼ÈÈ»ÊÇ½ÌÖ÷µÄÒâË¼,ÒÔºóÄã¾Í¸úÎÒºÃºÃÑ§°É!");
        command("recruit "+ob->query("id"));
        ob->set("marks/Ê¥»ğÈı³¤ÀÏ",1);
        }
int accept_kill(object ob)
{
        int i,j;
        object ob1, hu_fa, *enemy;
        ob1 = this_object();
        add_temp("kill_me",1);
        if(query_temp("kill_me")>5)
        {          
          message_vision( HIY"\n$NÊÜ²»ÁËµĞÈËµÄÉ§ÈÅ¶ø·¢¿ñÁË!!\n"NOR,ob1);
          set("title",HIR"¡´·¢¿ñ¡µ"NOR);         
          enemy = all_inventory( environment(ob1) );
          j=sizeof(enemy);
          for(i=0;i<j;i++)
          {
            if(userp(enemy[i]) && !enemy[i]->is_fighting() && living(ob1))
              kill_ob(enemy[i]);
          }
        }
        if( !present("hu-fa", environment(ob)) && living(ob1)) {
        tell_room(environment(ob),HIW"\nÍ»È»£¡³å³öÁ½Î»»¤·¨!!\n\n"NOR);
        for(i=0;i<2;i++)
        {
        hu_fa = new("/open/prayer/npc/hu_fa");
        hu_fa->move(environment(ob));
        hu_fa->command("guard behavior_elder");
        hu_fa->command("follow "+ob->query("id"));        
        hu_fa->kill_ob(ob);        
        }}
        write("»¤·¨×İÉí·ÉÆË¹ıÀ´½ĞµÀ£º´óµ¨¿ñÍ½£¡³¤ÀÏÄãÒ²¸Ò¶¯£¡£¡\n");
        return 1;
}

void init()
{
        object ob;
        ::init();
        if(interactive(ob =this_player()) && !is_fighting() )
        {
        remove_call_out("greeting");
        call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
        if(!ob) return ;
        if (ob->query_temp("high-man") == 2 )
        {
        write("\n[36mºÇºÇ, ÎÒÄÇÎ»Îä³ÕÒåĞÖ¶ÔÄãËµÁËĞ©Ê²Ã´Âğ??àÅ, ÄãµÄ×ÊÖÊÆÄ¼Ñ, ÄÑ¹ÖËû»á¸æËßÄãÕâ¼şÊÂÇé!![0m\n");
        write("\n[36mÄÇÎ»[ÒşÊÀ¸ßÈË]ÎäÑ§ÕæµÄ·Ç³£Éîºñ, ÓÈÆäÊÇÔÚ½£, µ¶, Óë±ŞµÄÔìÒèÉÏ, ¸üÊÇÁîÈË°İ·ş!!ÎÒÓëËûÔøÓĞÒ»ÃæÖ®ÔµÄØ!![0m\n");
        ob->delete_temp("high-man");
        ob->set_temp("high-man", 3);
        return;
        }

        if (ob->query_skill("coldpoison", 1))
        {
        command("say ½ÌÖ÷ÓĞÁî£¡£¡·²ÊÇÑ§ÓĞ¶¾ÊõÖ®ÈË£¬É±ÎŞë·£¡£¡");
        kill_ob(ob);
        }
        if( ob->query("class")=="dancer")
        {
        command("say ½ÌÖ÷ÓĞÁî£¬¼ûµ½ÎèÕß-----¸ñÉ±ÎğÂÛ£¡£¡");
        kill_ob(ob);
        }
    return;
}
