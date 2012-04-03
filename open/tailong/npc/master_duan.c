// ¶Î¼Ò ÕÆÃÅÈË
#include </open/open.h>
int exert_sunforce();
inherit NPC;
inherit F_MASTER;
string do_thief();
string do_scar();
string do_chao();
string do_firecracker();
void create()
{
        set_name("¶ÎÔÆ",({"lord duan","lord","duan"}));
        set("long","¶ÎÔÆ±ãÊÇµ±½ñ»ÊÉÏ²á·âµÄÆ½ÄÏÍõ, Í¬Ê±Ò²ÊÇ¶Î¼ÒÎäÑ§µÄµÚÊ®´ú´«ÈË, "+
"ËäÈ»¹óÎªÍõÒ¯, ×ÔÓĞÒ»¶Ç×ÓµÄÄ«Ë®, µ«ÆäÒ»Éí×æ´«µÄÎäÑ§È´Ò²Ã»Íü, ¿ÉËµÊÇÎÄÎäË«È«, "+
"Ò²ÒòÎªÈç´Ë, ¶ÎÔÆ×ÔÊÇ·Ç³£ÖØÊÓÎÄÑ§ËØÑø, ÈôÏë°İÈë¶Î¼ÒÎäÑ§µÄÃÅÏÂ, Ôò·ÇÊÇÒ»Î»ÊéÉú²»¿É¡£\n");
        set("gender","ÄĞĞÔ");
        set("class","scholar");
        set("nickname","Æ½ÄÏÍõ");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",50);
        set("max_kee",3000);
        set("kee", 3000);
        set("str", 44);
        set("cor", 24);
        set("cps", 45);
        set("per", 30);
        set("int", 42);
        set("inquiry", ([
        "thief"         : (: do_thief :),
        "scar"          : (: do_scar :),
        "sad_story"     : "ÈôÄã²»ÖªµÀÆäÖĞÔµÓÉ,¾Í²»ÒªÔÙÎÊÁË¡£",
        "chao"          : (: do_chao :),
        "firecracker"   : (: do_firecracker :),
        "Ò»ÑôĞÄ·¨ÃØóÅ"  : "ÕâÒ»ÑôĞÄ·¨µÄÃØóÅÌıËµÒÑÓÉÁøÒã·çÑ°»ñ, Ö»ÊÇ²»ÖªËûºÎÊ±»ØÀ´¡£",
        ]));
        set("force",3000);
        set("max_force",3000);
        set("force_factor", 10);
        set_skill("cure", 60);
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
        set("functions/handwriting/level",50);
        set("marks/sun-finger",1);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
                (: this_object(),"exert_sunforce" :),
        }));
        setup();
        carry_object(PING_OBJ"neck0")->wear();
        carry_object(PING_OBJ"cloud_fan")->wield();
        add_money("gold",10);
        create_family("¶Î¼Ò",10,"ÕÆÃÅÈË");
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

string do_thief()
{
        object me=this_player();
        if( me->query_temp("thief") < 4 )
          return("¾©³ÇµÄ´óµÁ..àÅ..ÓëÎÒ¶Î¼ÒÓĞ¹ØÂğ£¿");
        else
        {
          command("sigh");
          return("°¦..Ã»Ïëµ½..Ëû..°¦..");  
        }
}
string do_scar()
{
        object me=this_player();
        if( me->query_temp("thief") >= 3 )
        {
        if( me->query_temp("thief") == 3 )      me->set_temp("thief",4);
          return("´óµÁµÄÓÒ¶úºóÓĞÒ»Ğ¡ÉËºÛ, ÇÒÊ¹µÄÊÇ¶Î¼ÒµÄ\Îä\¹¦Âğ£¿ÄÑµÀ..ÄÑµÀÊÇËû..\n\n"+
          "¶ÎÔÆÏİÈëÉîÉîµÄÉòË¼Ö®ÖĞ, ËÆºõÔÚ»ØÏë×ÅÊ²Ã´¡£\n\n"+
          "¶ÎÔÆ±§Ç¸µÄËµµÀ: ÎÒ²»ÏëÔÙÌáÆğÕâ¶ÎÉËĞÄÍùÊÂ(sad_story)ÁË¡£À´ÈË°¡,ËÍ¿Í..");
        }
        else
          return("É¶..Ë­µÄÉËºÛ£¿");
}
string do_chao()
{
        object me=this_player();
        object key=new(PING_OBJ"key0");
        if( me->query_temp("thief") >= 5 )
        {
          if( me->query_temp("thief") == 5 )    me->set_temp("thief",6);
          command("say °¦..ÄãÒ²ÖªµÀÁËÕâ¼şÊÂÁË°¡..ÊÇÁøÒã·ç¸úÄãËµµÄ°É..ÆäÊµ¹ıÁË"+
          "ÕâÃ´¶àÄê, ÎÒÒ²¸ÃÃæ¶ÔÏÖÊµÁË¡£ÕÔÇÙ·ç±ä³É¾©³Ç´óµÁ, Ò²ËãÊÇ¶Î¼Ò¹Ü"+
          "½Ì²»ÖÜËùÖÂ, ÏÖÔÚÒªÒı³öÕÔÇÙ·ç, Ö»ÓĞÒ»¸ö°ì·¨, ¾ÍÊÇÓÃÎÒÃÇ¶Î¼Ò¶À"+
          "ÃÅµÄÁªÂçÑÌ»ğ, Ëû¿´µ½ÁËÑÌ»ğ±Ø¶¨»á³öÏÖ¡£");
          message_vision("$N½»¸ø$nÒ»°ÑÌúÔ¿³×¡£\n",this_object(),me);
          key->move(me);
          return("ÕâÊÇÎÒÃÇ¶Î¼Ò´¢²ØÊÒµÄÔ¿³×, Äã¿ÉÒÔÔÚÄÇÕÒµ½ÁªÂçÓÃµÄÅÚÕÌ");
        }
}
string do_firecracker()
{
        object me=this_player();
        if( me->query_temp("thief") >= 6 )
        {
          if( me->query_temp("thief") == 6 )    me->set_temp("thief",7);
          return("°¡..±§Ç¸ÍüÁËËµÃ÷ÅÚÕÌµÄÊ¹ÓÃ·½·¨, ÕâÅÚÕÌĞèÒªÔÚ¸ßµØÈ¼·Å²ÅĞĞ, "
          +"ÇÒÔÚÈ¼·ÅÇ°ÒªÏÈ¦ä£¦£¥¦ä£ª£¦£À££....Ã÷°×ÁË°É¡£");
        }
        else
          return("ÒÉ..ÄãÔõ»áÖªµÀÕâÕâÅÚÕÌµÄÊÂ, ¸øÎÒÀÏÊµµÀÀ´!!");
}

int exert_sunforce()
{
        object ob=this_object();
        if( ob->query("kee") < ob->query("max_kee")/2 )
        if( !present("sunforce finger",ob) )
        {
          command("say ºÃ..ÀÏ·ò¾ÍÅãÄãÍæÍæ¡£");
          command("exert sun-finger");
          command("wield finger");
        }
        return 1;
}

int do_answer(string str)
{
        object me=this_player();
        string *answer = ({
        "ÓİÙâÓİÙâÄÎÈôºÎ",
        "È¥ÈÕ¿à¶à",
        "¶ÔÓ°³ÉÈıÈË",
        "ÓÆÈ»¼ûÄÏÉ½",
        "´º·ç²»¶ÈÓñÃÅ¹Ø",
        "Î÷³öÑô¹ØÎŞ¹ÊÈË",
        "¹²´ËµÆÖò¹â",
        "´ËºŞÃàÃàÎŞ¾øÆÚ",
        "À¯¾æ³É»ÒÀá\Ê¼¸É",
        "Ç§¹Å·çÁ÷ÈËÎï",
         "Ò»²½½­ºşÎŞ¾¡ÆÚ",
         "×Ç¾ÆÒ»±­Ğ¦ºì³¾",
         "ÇÔÇÔ°µĞ¦ÊÀÈË³Õ",
         "Éñ»úÃîËãÔŞ°×Á«"
        });
        if(me->query_temp("answer") < 0);
        else
        {
          if(str == answer[me->query_temp("answer")])
          {
            command("pat "+me->query("id"));
            write("ºÜºÃ£¬" + RANK_D->query_respect(me) + "µÄÎÄÑ§µ××Ó²»´í, ¶à¼ÓÅ¬Á¦, "+
            "ËûÈÕ±ØÄÜÎª¶Î¼Ò·¢Ñï¹â´ó, ÔÚ½­ºşÉÏÑïÃûÁ¢ĞÕ¡£\n");
            command("recruit " + me->query("id") );
            me->set("startroom",environment(me));
            write("àÅ..ÄãµÄÄÚ¹¦²»¹»´¿Õı, ÈÃÎªÊ¦µÄÖúÄãÒ»±ÛÖ®Á¦°É¡£\n");
            message_vision("¶ÎÔÆ»º»ºµÄÉì³öÓÒÊÖ, Íù$NÍ·¶¥µÄ°Ù»áÑ¨Ò»°´, Ë¿Ë¿µÄÕôÆø´Ó$NµÄÍ·ÉÏÃ°ÁË³öÀ´....¡£\n",me);
            me->improve_skill("sunforce",2);
            command("smile "+me->query("id"));
            write("ºÃÁË, ÎªÊ¦ÒÑ½«Ò»Ğ¡²¿·İµÄÒ»ÑôĞÄ·¨´«ÓëÄã, ÍûÄãÄÜÔÙ½ÓÔÙÀø, ÖÕÓÚ´ó³É¡£\n");
            CHANNEL_D->do_channel(this_object(), "chat",
            sprintf("%s³ÉÎª¶Î¼ÒµÄÒ»Ô±ÁË, Ï£Íû´ó¼ÒÄÜ±¾×Å½­ºş¾«ÉñÕÕ¹ËËû¡£",me->name(1)));
          }
          else
          {
            command("sigh "+me->query("id"));
            write(RANK_D->query_respect(me)+"ÄãµÄÎÄÑ§ËØÑøÌ«Ç³ÁË, Ò²ĞíÓ¦¸Ã¶àÈ¥Æ·‡ŸÊé¼®, "+
            "ÏÂ´ÎÓĞ°ÑÎÕÁËÔÙÀ´ÕÒÎÒ°É...\n");
          }
          me->delete_temp("answer");
        }
        return 1;
}               

void attempt_apprentice(object me)
{
        int which;
        string *question = ({
        "ÏîÓğ¡®ºËÏÂ¸è¡¯\n¡¸Á¦°ÎÉ½ÙâÆø¸Ç\ÊÀ! Ê±²»ÀûÙâæí²»ÊÅ! æí²»ÊÅÙâ¿ÉÄÎºÎ! .......¡±",
        "²Ü²Ù¡®¶Ì¸èĞĞ¡¯\n¡¸¶Ô¾Æµ±¸è, ÈËÉú¼¸ºÎ? Æ©Èç³¯Â¶, ....¡±",
        "Àî°×¡®ÔÂÏÂ¶À×Ã¡¯\n¡¸»¨¼äÒ»ºø¾Æ, ¶À×ÃÎŞÏàÇ×; ¾Ù±­ÑûÃ÷ÔÂ, .....¡±",
        "ÌÕÔ¨Ã÷¡®Òû¾Æ¡¯\n¡¸½áÂ¬ÔÚÈË¼ä, ¶øÎŞ³µÂíĞú¡£ÎÊ¾ıºÎÄÜ¶û, ĞÄÔ¶µØ×ÔÆ«¡£²É¾Õ¶«ÀëÏÂ, .....¡£¡±",
        "ÍõÖ®»Á¡®Á¹Öİ´Ê¡¯\n¡¸»ÆºÓÔ¶ÉÏ°×ÔÆ¼ä, Ò»Æ¬¹Â³ÇÍòØğÉ½¡£Ç¼µÑºÎĞëÔ¹ÑîÁø, .......¡£¡±",
        "ÍõÎ¬¡®Î¼³ÇÇú¡¯\n¡¸Î¼³Ç³¯Óê›ÅÇå³¾, ¿ÍÉáÇàÇàÁøÉ«ĞÂ¡£È°¾ı¸ü½øÒ»±­¾Æ, .......¡£",
        "¶Å¸¦¡®ÔùÎÀ°Ë´¦Ê¿¡¯\n¡¸ÈËÉú²»Ïà¼û, ¶¯Èç²ÎÓëÉÌ¡£½ñÏ¦¸´ºÎÏ¦, .....¡±",
        "°×¾ÓÒ×¡®³¤ºŞ¸è¡¯\n¡¸ÔÚÌìÔ¸×ö±ÈÒíÄñ, ÔÚµØÔ¸ÎªÁ¬ÀíÖ¦¡£Ìì³¤µØ¾ÃÓĞÊ±¾¡, .......!",
        "ÀîÉÌÒş¡®ÎŞÌâ¡¯\n¡¸Ïà¼ûÊ±ÄÑ±ğÒàÄÑ, ¶«·çÎŞÁ¦°Ù»¨²Ğ¡£´º²Ïµ½ËÀË¿·½¾¡; .......",
        "´ó½­¶«È¥, ÀËÌÔ¾¡, ......¡±",
            "½õÀğÓûÔ¾ÁúÃÅ³Ø, ±±·çÒ»¶¯ÀëË®Ê±, Õ½»ğÉÕ¶ÏåĞÒ£ÃÎ.......",
            "ÊÀÊÂÈçÆå¾Ö¾ÖĞÂ, ºÀ½ÜËÆÀË·­²»¾¡, ¹ÅÍù½ñÀ´¶àÉÙÊÂ.......",
            "»¹ÕæÎªÖğÇàÔÆÖ¾, Ò»ÉúÕæÎ±ÓĞË­Öª, ÌÃÌÃÂúÑÔÈÊÒåÇé.......",
            "Áé³µºÕºÕÌìÏÂ¾ª, ÑıÉùĞ°ÆøÃÖÂúÌì, ½ğÒ¶Ò»¶¯ÇåÏãÏÖ......."
        });
        which=random(sizeof(question));
        if(me->query_temp("have_apprentice"))
          write("ÔõÃ´ÕâÃ´¿ìÓÖ¼ûÃæÁË? ÏÂ´ÎÔÙÀ´°É¡£\n");
        else
        {
        write(" "+RANK_D->query_respect(me)+"Ïë°İÈëÎÒµÄÃÅÏÂÂğ? ÎÒÃÅµÄÄÚ¹¦Ê×ÖØÄÚĞÄĞŞÑø, "+
        "ÈôÑ§Ê¶Ã»ÓĞÒ»¶¨µÄ»ù´¡, ¶Ô×ÔÉí·´¶øÓĞº¦¡£ÀÏ·òÕâ¾ÍÀ´ÊÔÒ»ÊÔÄã, ÈôÕæĞÄÏëÑ§µÄ»°¾Í»Ø´ğ(answer)ÎÒµÄÎÊÌâ°É\n");
        write("¶ÎÔÆ»º»ºµÄÒ÷³ªµÀ: fl;[1;36m"+question[which]+"fc;[0m\n");
        write("¶ÎÔÆºÍ°ªµÄËµµÀ: ÄãÄÜËµËµ½ÓÏÂÀ´µÄ¾ä×ÓÂğ?\n");
        me->set_temp("have_apprentice",1);
        me->set_temp("answer",which);
        }
}
int accept_object(object me, object obj)
{
        if( obj->query("name") == "Ò»ÑôĞÄ·¨ÃØóÅ" )
        {
          command("pat "+getuid(me));
          command("say Ì«ºÃÁË, ÊÇÁøÒã·çÍĞÄãµÄÂğ£¿Ğ»ÁË¡£");
          if( me->query("family/family_name") == "¶Î¼Ò" && !me->query("marks/sun-finger") )
          {
            command("say ¼ÈÈ»Äã»¤ËÍÃØóÅÓĞ¹¦, ÎÒ±ã½«´ËÃØóÅÉÏ¼ÇÔØµÄ¾øÕĞ´«ÊÚÓëÄã°É¡£");
            write(this_object()->query("name")+"¿´×ÅÃØóÅËæÊÖÑİÁ·Ò»±é¡£\n\n"+
            "Äã¾õµÃĞÄÖĞÒÉÂÇ»íÈ»¹áÍ¨, È«ÉíÄÚÁ¦Ñ¸ËÙÁ÷×ªÒ»ÖÜÌì¡£\n\n"+
            "[36mÄãµÄÄÚÁ¦Öµ´ïµ½ÉÏÏŞÁË¡£\n\n"+
            "[1mÄãÑ§»áÁËÒ»ÑôĞÄ·¨ÖĞµÄ¾øÕĞ¡¸»¯ÆøÎª±Ê¡±¡£[0m\n\n");
            if( me->query("force") < me->query("max_force") )
              me->set("force",me->query("max_force"));
            me->set("marks/sun-finger",1);
          }
          destruct(obj);
        }
        else
          command("? "+getuid(me));
        return 1;
}
              
void unconcious()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),"\n\t[1m¡®[36mÌìÏÂ·çÔÆ³öÎÒ±²  Ò»Èë½­ºşËêÔÂ´İ\n\t\t»ÊÍ¼°ÔÒµÌ¸Ğ¦ÖĞ  ²»Ê¤ÈËÉúÒ»³¡×í[0m[1m¡¯[0m\n"+
        "\n\t[1mÏëÎÒ¶ÎÔÆ×İºá½­ºş, ½ñÈÕ°ÜÓÚ[33m"+winner->query("name")+"[0;1mÖ®ÊÖ\n\t¿ÉÎ½  [1;31mÊ±Ò²¡«  ÔËÒ²¡«  ÃüÒ²¡«[0m\n");
        :: unconcious();
}
void die()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),"\n\n[36mÄÏ·½Ìì¿Õ»­¹ıÒ»µÀ[5mÁ÷ĞÇ[0m¡£\n\n\t[1;31m¡¸Ìì»úĞÇÂä¡±[0m\n\n");
        :: die();
}                      
