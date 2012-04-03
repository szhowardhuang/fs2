// ¶Î¼Ò ÃÅÈË made by onion
#include </open/open.h>
inherit NPC;
string do_duan();
string do_thief();
string do_linpo();
int do_gone();
object ob=this_object();
void create()
{
        set_name("¾©³Ç´óµÁ",({"great thief","thief"}));
        set("long","ËäÈ»ËûÊÇÒ»Ãû±»Í¨¼©µÄ´óµÁ, µ«Ã¼Ä¿¼äÈ´ÒşÒşÓĞÒ»¹É²»·²µÄÆøÖÊ¡£\n"+
            "ËÆºõÏòÀ´ÓëÁ÷Ë®ĞĞÔÆÍ¬¶É, ¸úÂäÏ¼¹ÂæğÆë·É¡£\n");
        set("gender","ÄĞĞÔ");
        set("class","scholar");
        set("combat_exp", 100000);
        set("attitude","heroism");
        set("age",44);
        set("inquiry", ([
        "duan" : (: do_duan :),
        "¶Î¼Ò" : (: do_duan :),
        "chao" : (: do_duan :),
        "thief" : (: do_thief :),
        "Áè²¨Î¢²½ÃØóÅ" : (: do_linpo :),
        "Ğ¡Ê¦µÜ" : "ÄãÒÔÎªÎÒ»á¸úÄãËµÂğ!ºß£¬Ïë¶¼±ğÏë!!",
        ]));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: this_object(),"do_gone" :),
        }));
        set("force",1000);
        set("max_force",1000);
        set("force_factor", 20);
        set_skill("force",40);
        set_skill("dodge",70);
        set_skill("unarmed",30);
        set_skill("sunforce",40);
        set_skill("linpo-steps",60);
        set_skill("six-fingers",71);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");
        set_temp("apply/dodge",50);
        set_temp("apply/damage",50);
        set_temp("apply/armor",100);
        setup();
        carry_object(CAPITAL_OBJ"cloth1")->wear();
        carry_object(CAPITAL_OBJ"pen0")->wield();
        carry_object(CAPITAL_OBJ"pen0")->wield();
        add_money("silver",10);
}

void init()
{
        add_action("do_forgive","forgive");
        add_action("do_want","want");
}
string do_duan()
{
        set_name("ÕÔÇÙ·ç",({"chao"}));
        return("Ô­À´ÄãÒÑ¾­ÖªµÀÎÒÊÇ¶Î¼ÒµÄÈËÁË¡£\n");
}
string do_thief()
{
        object me=this_player();
        if( !this_object()->queyr_temp("lost") )
        {
        me->set_temp("thief",9);
        remove_call_out("do_flee");
        call_out("do_flee",3);
        set_name("ÕÔÇÙ·ç",({"chao"}));
        return("²»´í, ÎÒ±ãÊÇÕÔÇÙ·ç, ¾©³ÇµÄ°¸×Ó¶¼ÊÇÎÒ×öµÄ, µ«ÎÒËùÍµµÄÊÇÄÇĞ©ÎÄ³¼Îä¹ÙÔÚÃñ¼äËÑÀ¨¡¢"+
        "Ç¿Õ÷µÃÀ´µÄÇ®²Æ¹ÅÍæ, ÕË¼ÃµÄÊÇ¸øËÑÀ¨Ò»¿ÕµÄÆ¶ÖÚ, ËäÎ¥Àí, È´ºÏÇé¡£ÕâµÈÊÂ, "+
        "±ğÈË²»¸Ò×ö, ÎÒÆ«Æ«Òª×ö, Ö»ÒªÊÇºÏÓÚÎÒĞÄ, ÓÖÓĞÊ²Ã´²»¿ÉÒÔ¡£\n");
        }
        else
        return("Õâ²»¹ØÄãµÄÊÂ¡£\n");
}
string do_linpo()
{
        object me=this_player();

        if(this_object()->query("name")!="ÕÔÇÙ·ç")
          return 0;
        if(me->query("family/family_name")!="¶Î¼Ò")
          return "ÎÒ²»¶®ÄãÔÚËµÊ²Ã´¡£";
        if(me->query("marks/ask_linpo")!=1)
          return "Äã±ğÂÒËµ£¬´òËÀÎÒÒ²²»»á×÷³ö¶ÔÊ¦ÃÅ²»¾´µÄÊÂ!!\n";
        me->set("marks/ask_linpo",2);
        command("hmm");
        return "ÕæÃ»Ïëµ½Äã¾¹È»ÖªµÀÕâ¼şÊÂ£¬²»¹ıÄãÕÒÎÒÒ²Ã»ÓÃ£¬ÒòÎªÎÒÒÑ¾­°ÑÃØóÅËÍ¸øÎÒµÄĞ¡Ê¦µÜÁË¡£";
}
void do_flee()
{
        object me=this_player();
        tell_room(environment(ob),query("name")+"ÉíĞÎÒ»ÍË, ËÆºõÏëÒªÌÓ×ß, µ«ÄãÑÛÃ÷ÊÖ¿ìµÄ°ÑËûµ²ÁËÏÂÀ´¡£\n");
        message_vision("$NºÍ$n´òÁËÆğÀ´¡£\n",me,ob);
        ob->fight_ob(me);
}

int do_gone()
{
        object *me;
        me=ob->query_enemy();
        if( me[random(sizeof(me))]->query_temp("thief") != 9 )
        {
          command("say Á¬»°¶¼²»ËµÃ÷°×ÊÇ°É..¸æ´ÇÁË¡£");
          tell_room(environment(ob),query("name")+"ÉíĞÎÒ»¶¯, ÈËÓ°Ò»»Î, ±ã²»ÖªËù×ÙÁË¡£\n");
          destruct(ob);
        }
        return 1;
}

void unconcious()
{
        object winner = query_temp("last_damage_from");
        if( !query_temp("lost") )
        {
          message_vision("$N´Ó¼±¼±Ã¦Ã¦µÄ´Ó»³ÀïÌÍ³öÒ»¿ÅĞ¡»¹µ¤ÔË¹¦·ş»¯¡£\n",ob);
          command("say ¼ÈÈ»ÎÒ¼¼²»ÈçÈË  ÄÇ¾ÍÈÎÆ¾Äã´¦ÖÃ°É");
          tell_object(winner,"[1;36mÄãÒªÔ­ÁÂ(forgive)ËûÂğ?[0m\n");
          set_temp("lost",getuid(winner));
          ob->remove_all_enemy();
          set("kee",100);
        }
        else
        {
          ob->delete_temp("undead");
          :: unconcious();
        }
}

int do_forgive(string str)
{
        object me=this_player();
        if(ob->query_temp("lost") == getuid(me) || !me->query("quests/catch_thief") )
        {
          command("say ºÃ, ³ĞÃÉ"+RANK_D->query_respect(me)+"¿´µÄÆğÎÒ, ¸øÎÒÕâ"+
          "Ò»´Î»ú»á, ÎÒÕâ¾ÍÏ´ÊÖ²»¸ÉÁË¡£");
          if( !ob->query_temp("get_reward") )
          {
            message_vision("$N´Ó»³ÖĞÌÍ³öÁ½¼ş¶«Î÷¡£\n",ob);
            command("say ÕâÁ½¼ş±¦ÎïÊÇÎÒ¶àÄêÇ°ÎŞÒâÖĞµÃÀ´µÄ, Ò»ÊÇÒ»¿Å¾Å×ª½ğµ¤(pi"+
            "ll), ¶şÊÇÒ»°ÑÉñ±øÀûÆ÷(weapon), ÎªÁË¸ĞĞ»Äã, ¾ÍËÍÄãÆäÖĞÒ»¼ş°É, ÄãÏë"+
            "Òª(want)Ê²Ã´ÄØ?");
            if( !me->query("quests/catch_thief") )
            {
            write("\n\n[1;36***Íê³É¾©³Ç´óµÁÖ®ÃÕ***[0m\nµÃµ½ÊµÕ½¾­Ñé 200¡£\n");
            me->set("quests/catch_thief",1);
            me->set_temp("can_get_reward",1);
            me->add("combat_exp",200);
            me->delete_temp("thief");
            }
          }
          else
          {
            command("say Õâ¾Í¸æ´ÇÁË¡£");
            destruct(ob);
          }
          return 1;
        }
        return 0;
}
int do_want(string str)
{
        object me=this_player();
        object reward;
        int kind;
        if( me->query("quests/catch_thief") || !ob->query_temp("get_reward") || me->query_temp("can_get_reward") )
        {
          if( str == "pill" || str == "weapon")
          {
            if( str == "weapon" )
            {
              if( me->query("class") == "blademan" || me->query("class") == "swordsman" )
              {
              if( me->query("class") == "blademan" )
                kind=random(2)+3;
              if( me->query("class") == "swordsman" )
                kind=random(2)+1;
              }
              else
                kind=random(4)+1;
              switch(kind)
              {
              case 1 :
              reward=new(CAPITAL_OBJ"4-1");                     break;
              case 2 :
              reward=new(CAPITAL_OBJ"4-4");                     break;
              case 3 :
              reward=new(CAPITAL_OBJ"4-3");                     break;
              case 4 :
              reward=new(CAPITAL_OBJ"4-2");                     break;
              }
            }
            if( str == "pill" )
              reward=new(CAPITAL_OBJ"gold_pill");
            message_vision("$N½«ÊÖÉÏµÄ"+reward->query("name")+"½»¸ø$n¡£\n",ob,me);
            if( me->query_max_encumbrance() - me->query_encumbrance() > reward->query_weight() )
              reward->move(me);
            else
            {
              message_vision("$NÉíÉÏÌ«ÖØÁË, ¹Ê$n½«"+reward->query("name")+"ÖÃÓÚµØÉÏ¡£\n",me,ob);
              reward->move(environment(me));
            }
            if( str == "weapon" )
              command("say ´Ë°ÑÎäÆ÷ÒµÒÑ·â³¾¶àÄê, ±ØĞëÒªÒÔ×ÔÉí¾«ÆøÉñÏÈ¿ª¹â(blood)ºó²ÅÓĞÍşÁ¦¡£");
            ob->set_temp("get_reward",1);
            me->delete_temp("can_get_reward");
            command("say "+RANK_D->query_respect(me)+"¸æ´ÇÁË, ¾Í´Ë°İ±ğ¡£");
            tell_room(environment(ob),ob->query("name")+"×ª¶¯Ê¯×Àºó, ÉÏÍ·Â¶³ö"+
            "Ò»¸ö´ó¶´, Ëû±ã´Ó´Ë¶´ÅÀÁË³öÈ¥, Ö®ºóÕâ¸ö´ó¶´ÓÖ»º»ºµÄ¹Ø±Õ¡£\n");
            destruct(ob);
          }
          else
            command("say Ê²Ã´?");
          return 1;
        }
        else
          return 0;
}
