inherit NPC;
#include <combat.h>
#include </open/open.h>
string do_thief();
string do_help();
void create()
{
        set_name("¼ÍÎŞ³¾", ({ "chi wu-cheng","chi", "cheng" }) );
        set("title", "×ÜÀíÖ´ÊÂ");
        //set("nickname", "[1;34m¡õ[36m¡õ[34m¡õ[36m¡õ[34m¡õ[36m¡õ[34m¡õ[36m¡õ[0m NOR");
        set("class","officer");
        set("gender", "ÄĞĞÔ" );
        set_max_encumbrance(1000000);
        set("age", 46);
        set("str", 20);
        set("cor", 20);
        set("cps", 20);
        set("int", 30);
        set("spi", 20);
        set("kar", 26);
        set("per", 20);
        set("con", 30);

        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 5);

        set("long", @LONG
    ÈË³Æ¡®¾©³ÇÖ®¹â¡¯£¬ÈËËµÆä¶Ï°¸ÈçÉñ£¬¾ö²»áßË½ÆˆÇÒ¡£ËùÒÔÕâÀïµÄ
°ÙĞÕ¶¼ºÜ¾´°®Ëû¡£Ò²ÒòÎªËûµÄ¹¦¼¨»Ô»Í£¬ÏÈ»ÊÌØ´ÍÆäÒ»±úÉĞ·½±¦½££¬×¼
Æä½«¶ñ¹ßÂúÓ¯Ö®ÈË£¬ÏÈÕ¶ºó×à!!
LONG);

        set("combat_exp",500000);
        set("score", 30000);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        "ÎŞ³¾´óÈËºÈµÀ£º´óµ¨¿ñÍ½!!  ÄÃÏÂ!!\n",
        "ÎŞ³¾´óÈËºÈµÀ£º¹«ÌÃÖ®ÉÏ¾¹¸ÒÈöÒ°!!  ¸øÎÒÑÏ³Í!!\n"
        }) );

        set_skill("unarmed", 30);
        set_skill("force",  20);
        set_skill("parry",  20);
        set_skill("dodge",  20);
        set_skill("sword",  20);
        set_skill("literate", 90);

        set("inquiry", ([
          "»úÆ÷ÈË" : "ºß!! Ë­±»ÎÒ×¥µ½ÊÇ»úÆ÷ÈËµÄ»°£¬Õ¶Á¢¾ö!!",
          "accuse" : "Ïë¼©²¶»úÆ÷ÈËµÄ»°£¬ÇëÏÈµ½ÃÅ¿Ú»÷¹ÄÉêÔ©(accuse)¡£",
          "thief"  : (: do_thief :),
          "²âÊÔ"   : "Ïë×¥Ôô(thief)¾ÍµÃÏÈ¾­¹ıÎÒ²âÊÔ, ÈôÄÜÁ¬½ÓÎÒÎåÕĞ±ãËã¹ı¹ØÁË¡£",
          "test"   : "Ïë×¥Ôô(thief)¾ÍµÃÏÈ¾­¹ıÎÒ²âÊÔ, ÈôÄÜÁ¬½ÓÎÒÎåÕĞ±ãËã¹ı¹ØÁË¡£",
          "accept" : "Òª½ÓÊÜ²âÊÔÂğ? ÄÇ¾Í´ò(accept test)¡£",
          "°ïÃ¦"   : (: do_help :),
        ]) );

        setup();
        carry_object(HALL_NPC"obj/god_sword")->wield();
        carry_object(HALL_NPC"obj/o_cloth")->wear();
}

int accept_object(object me,object ob)
{
        string letter_id;
        letter_id=ob->query("id");
        if(letter_id=="chi_letter")
        {
                destruct(ob);
                command("say ß×!ÎÒµÄĞÅ£¬àÅ......¶àĞ»ÄãÀ²");
                command("bow"+me->query("id"));
                me->add("taigan_exp",10);
                me->delete_temp("working");
                switch(random(3)){
                        case 1:
                        me->set("taigan_work",1);
                        break;
                        case 2:
                        me->set("taigan_work",2);
                        break;
                        case 3:
                        me->set("taigan_work",3);
                        break;
                        }
        }
        else{
                command("say àÅ???ÕâĞÅ²»ÊÇ¸øÎÒµÄ£¬Äã¸ã´í†ª!!!");
                command("give"+ob->query("id")+me->query("id"));
            }
}
string do_help()
{
        int work,i,j,k;
        object me,ob,letter;
        me=this_player();
        ob=this_object();
        work=me->query("taigan_work");
        if(work!=1 || me->query_temp("working") ||me->query("class")!="taigan")
                return "ÎÒÏÖÔÚÃ»Ê²Ã´ÊÂĞèÒªÄã°ïÃ¦£¬È¥¿´¿´±ğÈËĞè²»ĞèÒª°É¡£\n";
        else
        {
        switch(random(3))
        {
                case 1:
                new("/open/capital/room/sroom/obj/yen_letter")->move(me);
                me->set_temp("working",1);
                message_vision("¸øÁË$NÒ»·âĞÅ¡£\n",me);
                return "ÄãÀ´µÄÕıºÃ£¬ÎÒÕâÀïÓĞ·âĞÅÒª½»¸øÄÚÎñ¼àµÄÑÏ¹«¹«£¬Äã°ïÎÒÅÜÒ»ÌË°É¡£\n";
                break;
                case 2:
                new("/open/capital/room/sroom/obj/chang_letter")->move(me);
                me->set_temp("working",1);
                message_vision("¸øÁË$NÒ»·âĞÅ¡£\n",me);
                return "ÄãÀ´µÄÕıºÃ£¬ÎÒÕâÀïÓĞ·âĞÅÒª½»¸øÉÅÊ³¼àµÄÕÅ¹«¹«£¬Äã°ïÎÒÅÜÒ»ÌË°É¡£\n";
                break;
                case 3:
                new("/open/capital/room/sroom/obj/chan_letter")->move(me);
                me->set_temp("working",1);
                message_vision("¸øÁË$NÒ»·âĞÅ¡£\n",me);
                return "ÄãÀ´µÄÕıºÃ£¬ÎÒÕâÀïÓĞ·âĞÅÒª½»¸ø¹ÜÊÂ¼àµÄ³Â¹«¹«£¬Äã°ïÎÒÅÜÒ»ÌË°É¡£\n";
                break;
        }
        }
}
string do_thief()
{
        object me=this_player();
        if( me->query("quests/catch_thief") == 0 )
        {
          if( me->query_temp("thief") == 0 )
            me->set_temp("thief",1);
          return (RANK_D->query_respect(me)+"ÊÇÓĞÒâ°ïÃ¦×¥¾©³Ç´óµÁµÄÂğ? "+
                "Ö»ÊÇ×î½üÓĞĞí¶àÃ»±¾ÊÂµÄÈËÇ°À´Ó¦Õ÷\n, "+RANK_D->query_respect(me)+
                "ÈôÓĞ±¾ÊÂµÄ»°ÇëÏÈ½ÓÊÜ²âÊÔ°É(accept test)¡£");
        }
        else
        {
          command("smile");
          command("pat "+me->query("id"));
          return ("Õâ¼şÊÂÕæÊÇ¶à¿÷ÁËÄã, Èç½ñ¾©³ÇÓÖ»Ö¸´Æ½¾²ÁË¡£");
        }
}
void init()
{
        add_action("do_accept","accept");
}
int do_accept(string str)
{
        int i;
        object ob=this_object();
        object me=this_player();
        object mark=new(CAPITAL_OBJ"mark");
        if( me->query_temp("thief") == 0)
          command("say ÏÈÎÊÎÊÎªºÎÒª²âÊÔ°É¡£");
        if( me->query_temp("thief") > 1)
          command("say ²»ÊÇ²âÊÔ¹ıÁËÂğ?");
        if( me->query_temp("thief") == 1)
        {
        if( str=="test")
        {
          command("say ºÃ! ´ıÀÏ·òÀ´ÊÔÊÔÄã! Ğ¡ĞÄÁË");
          for(i=0;i<5;i++)
            COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), TYPE_QUICK);
          if( me->query("kee") > 1 )
          {
            command("say ¹ûÈ»²»\À¢\Îª\ÕæÓ¢ĞÛ, ÄÇÎÒ¾Í½«Õâ¼şÊÂÔ­Ô­±¾±¾µÄËµÓëÄãÌıÁË");
            command("thank "+me->query("id"));
            command("say Õâ¾©³Ç´óµÁÄ¿Ç°ÎªÖ¹ÒÑµÃÊÖ²»ÏÂÊı´Î, Á¬¾©³ÇÊ×¸»¸ÉÍ¨ÌìµÄÕ¬µÚÒ²\n"+
            "            ÔâÑêÁË, Òò´ËÕâ²Å¾ª¶¯»ÊÉÏÏÂÁîÒ»¸öÔÂÖ®ÄÚ±ØĞëÆÆ°¸, ¼ÈÈ»"+RANK_D->query_respect(me)+
            "\n            ×Ô¸æ·ÜÓÂ, ÄÇÕâ¼şÊÂ¾Í°İÍĞÄãÁË¡£½«´ËÃû´óµÁ´ş²¶¹é°¸, Ôò±Ø¶¨ÖØÖØÓĞÉÍ¡£");
            message_vision("$N½»¸ø$nÒ»Ãæ¡¸ÑÃÃÅÁîÅÆ¡±¡£\n",ob,me);
            mark->move(me);
            command("say Ï£ÍûÕâÃæÁîÅÆ¶ÔÄã°ì°¸ÄÜÓĞËùÖúÒæ¡£");
            me->set_temp("thief",2);
          }
          else
          {
            command("say °ÕÁË°ÕÁË, ÎÒ»¹ÊÇ¼ÌĞøµÈÕæÓ¢ĞÛÀ´°É");
            command("sigh");
          }
        }
        else
          write("½ÓÊÜÊ²Ã´?!\n");
        }
        return 1;
}

int accept_object(object me, object man)
{
        string target = "ÕÔÇÙ·ç";
        object ob=this_object();
        object reward;
        if( me->query_temp("thief") < 2 )
          return notify_fail(ob->query("name")+"ËµµÀ£ºÒÉ..ÎÒºÃÏñÃ»ÓĞÍĞÄã°ìÕâ¼şÊÂÂï¡£¼ÈÈ»ÄãÕâÃ´ÈÈĞÄ, ÄÇ¾ÍĞ»†ª¡£\n");
        if( man->query("victim_name") == target || man->query("name") == target )
        {
          command("say ÕæÊÇÌ«ºÃÁË, ÎÒÍĞ¸¶ÄãµÄÊÂÖÕÓÚË³ÀûµÄ´ï³ÉÁË¡£");
          if( man->query("name") == target )
          {
            command("say °´ÕÕÔ¼¶¨, Õâ¾ÍÊÇÄãÓ¦µÃµÄÉÍ½ğ¡£\n");
            reward = new("/obj/money/gold");
            reward->set_amount(5);
            reward->move(me);
            message_vision("$N´Í¸ø$nÎåÁ½»Æ½ğ¡£\n",ob,me);
          }
          else
          {
            command("say ¿ÉÏ§Õâ¾©³Ç´óµÁÒÑËÀ, Òò´ËÉÍ½ğÖ»ÓĞÒ»°ëÁË¡£");
            reward = new("/obj/money/gold");
            reward->set_amount(2);
            reward->move(me);
            message_vision("$N´Í¸ø$n¶şÁ½»Æ½ğ¡£\n",ob,me);
          }
          if( !me->query("quests/catch_thief") )
          {
            write("\n\n[1;36m**Íê³É¾©³Ç´óµÁÖ®ÃÕ***[0m\nÄãµÃµ½ÊµÕ½¾­Ñé 200¡£\n");
            me->add("combat_exp",200);
            if( me->query("class") == "officer" )
            {
              write("ÄãµÃµ½ÕşÖÎÈ¨Á¦ 20¡£\n");
              me->add("max_officer_power",20);
            }
            me->set("quests/catch_thief",1);
            me->delete_temp("thief");
          }
          destruct(man);
        }
        return 1;
}
