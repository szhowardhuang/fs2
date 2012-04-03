#include <command.h>
#include <ansi.h> 

inherit NPC;
int start_check( object me )
{
remove_call_out("start_check");
if( !me ) return 0;
command("say ÄãÉíÉÏÉ¢·¢³öÒõÁéÖ®Æø£¬ÄÑµÀÄãµÃµ½Ñıµ¶¡®´åÓê¡¯£¿");
}
int start_blade(object who)
{
object wea;
remove_call_out("start_blade");
who=this_player();
if( !who ) return 0;
if(who->query_skill("fireforce",1)>=100&&who->query("get-evil-mblade")==0)
{
write("\n[1;33mÖı½³½«Ä§ÁúÁÛ¶ªÈëÈÛÂ¯ÈÛ»¯ºó£¬¼ÓÉÏÄã´¿Õı¼«»ğ¹¦Á¶½ğ£¬Ò»»á¶ù¾Í´òºÃÁËÑıµ¶£¡\n[0m");
command("say ²»¹ıÑıµ¶ÒªÑª¹â²ÅÄÜ·¢»ÓÆä¹¦ÓÃ(blood)£¡");
command("say ´«ËµÑıµ¶ÓĞÄ³ÖÖÉñÃØÁ¦Á¿(power)£¡");
wea=new("/data/autoload/blademan/evil-mblade.c");
wea->move(who);
who->set("get-evil-mblade",1);
message("system",HIC"Ìì¿ÕÍ»È»ÎÚÔÆÃÜ²¼£¬ö®ÄÇ¼ä´ÓÌì¿ÕÖĞĞÄ»÷ÂäÒ»µÀÉÁµç¡£\n"NOR,users());
message("system",HIC"\nÕâµÀÉÁµçö®ÓĞÁéĞÔ°ãµÄ»÷Ïò"+who->query("name")+"¡£\n"NOR,users());
message("system",HIY"\nÍ¬Ê±¼ä£¬´óµØÕğÁÑÎŞÊıÒõÁé·É³ö¾Û¼¯ÔÚ"+who->query("name")+"ÉíÉÏ¡£\n"NOR,users());
message("system",HIR"\nÖ»¼û"+who->query("name")+"ÑÛÂ¶ºì¹â¿ñĞ¦µÀ : \n\n\t\tÑıµ¶ÖÕÓÚÏÖÊÀ\n\n\t\tÎÒ³Æ°ÔÎäÁÖÖ®ÈÕ\n\n\t\t¼´½«µ½À´\n\n\t\t¹ş¹ş¹ş¹ş¹ş¹ş\n\n"NOR,users());
message("system",HIW"ÌìÀ×µØ¶¯¡«¡«"+who->query("name")+"×İÉù³¤Ğ¦ : \n\n\t\t¹ş¹ş¹ş¹ş¡«¡«"HIG"Ñıµ¶"HIW"ÏÖÊÀÁË¡£\n"NOR,users());
who->set("title","[1;32mÑı[1;37mµ¶[1;32m´«[1;37mÈË[0m");
return 1;
} else {
if(who->query_skill("fireforce",1)<100) command("say Äã¼«»ğ¹¦²»¹»´¿Õı(lv 100)£¡");
if(who->query("get-evil-mblade")==1) command("say ÄãÒÑ¾­ÓĞÑıµ¶ÁË£¡");
return 1;
}
}
int do_nod()
{
object me = this_player();
if(me->query("evil-mblade")!=1) return 0;
message_vision(HIY"$N¿´ÁË¿´$nÊÖÉÏµÄÑıµ¶¡£\n"NOR,this_object(),this_player());
command("sigh "+me->query("id"));
command("say ¿ÉÏ§µ¶ÉíÒÔ»Ù£¬²»¹ıÃ»¹ØÎ÷£¬ÎÒ¸¸Ç×½ÌÁËÎÒÒ»ÉíºÃ¹¦·ò¡£");
command("say Ö»ÒªÄãÄÜÄÃµ½Ä§ÁúÁÛºÍÁ·µÃ´¿Õı¼«»ğ¹¦ÎÒ¾ÍÄÜ°ïÄã¡£");
        return 1;
}
void create()
{
    set_name("¹¤½³",({"maker"}));
    set("title", "ÎäÆ÷ÖıÔìµÄ");
    set("gender", "ÄĞĞÔ");
    set("age",43);
    set("attitude","friendly");
    set("long",@LONG

        ËûÊÇÖıÔìÎäÆ÷µÄ¹¤½³, ×¨ÃÅÎªÎäÁÖÏÀ¿ÍÃÇÖıÔìË³ÊÖµÄ±øÆ÷, 
        ²»¹ıÕâĞ©±øÆ÷²»ÊÇËæ±ã¾ÍÄÜ´òÔì³öÀ´µÄ, ²ÄÁÏ·½Ãæ¿ÉµÃ·ÑĞÄ
        Ò»µãÈ¥ÊÕ¼¯........

LONG);
 
    set("combat_exp",2000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",50);
    set("kee",50);
    set("max_force",50);
    set("force_factor", 1);
    set("force",50);
    set("limbs",({"Í·","ÊÖ","½Å","±³","¸¹","Ñü"}));
    set("chat_chance",3);
    set("chat_msg", ({
        "[36mÎÒµÄË«ÊÖ°¡¡«×îÊÇÁéÇÉÁË¡«!!\n\n"
        "[36m¸÷ÖÖ³¤¶Ì±øÆ÷¡«¶¼ÄÜ×öµÄÈÃ¿Í¹ÙÄúÂúÒâµÄ¡«[0m!!\n\n",
        "[36mÖÁÓÚ[33m¹¤Ç®[36mÂï!! ¿ÉÊÇ²»ÄÜÂí»¢µÄÓ´![0m!\n\n",
    }) );
    set("inquiry",([
    "¹¤Ç®":"ÄÇ¾ÍÒª¿´¿Í¹ÙÄúÒª´òÔìºÎÖÖ±øÆ÷ÁË!!µ¶, ½£, ¹÷, ÉÈ, ×¦....¶¼µÃÒª¸¶Ç®Ó´!!\n",
    "µ¶":"Öıµ¶µÄ¼Û¸ñÂïÒ²²»»áºÜ¶àÀ²!!¾ÍËãÄú 10 Á½½ğ×ÓºÃÁË!!²»ºÃÒâË¼, Æ­¼ÓÆ­¼ÓÀ²\n",
    "½£":"´ò½£µÄÊ±¼ä»¨·Ñ×î¾ÃÁË!!ÊÕ¸ö 20 Á½½ğ×Ó¿É²»Ëã¹ı·İÄÄ!!²»ºÃÒâË¼, Æ­¼ÓÆ­¼ÓÀ²\n",
    "¹÷":"Ä¥¹÷Òª»¨µÄ¹¦·ò½Ï¶à!!×ÃÁ¿¸øÄúÊÕ¸ö 12 Á½½ğ×Ó!!²»ºÃÒâË¼, Æ­¼ÓÆ­¼ÓÀ²\n",
    "ÉÈ":"ÉÈ×ÓµÄÖÆ×÷½Ï·±ÔÓ!!¿ÉµÃÊÕ¸ö 15 Á½½ğ×ÓÄØ!!²»ºÃÒâË¼, Æ­¼ÓÆ­¼ÓÀ²\n",
    "×¦":"¿ÕÊÖÎäÆ÷µÄÔìĞÍ½Ï¼òµ¥!!¾ÍËãÄú 5 Á½½ğ×ÓºÃÁË!!²»ºÃÒâË¼, Æ­¼ÓÆ­¼ÓÀ²\n",
    ]));
    setup();
}

void init()
{
        object me = this_player();
        object ob;
if((ob=present("bad-evil-mblade",me))&&ob->name()=="ÊÜËğµÄÑıµ¶¡®´åÓê¡¯")
        {
                call_out("start_check",1,me);
                add_action("do_nod","nod");
        }
        add_action("do_select","select");
if(me->query_temp("sumblade")==1&&me->query_temp("bad-blade")==1) {
    call_out("start_blade",1,me); }
}

int accept_object(object who, object obj)
{
object wea;
who=this_player();
        if( obj->value() == 50000 )
        {
        write("[36mĞ¡µÄÂíÉÏÄÃÕâĞ©¹¤Ç®È¥×¼±¸Ò»ÏÂÖıÔì¿ÕÊÖÎäÆ÷µÄ¹¤¾ß!![0m\n");
        who->set_temp("money/unarmed",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 100000 )
        {
        write("[36mĞ¡µÄÂíÉÏÄÃÕâĞ©¹¤Ç®È¥×¼±¸Ò»ÏÂÖıµ¶ÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/blade",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 120000 )
        {
        write("[36mĞ¡µÄÂíÉÏÄÃÕâĞ©¹¤Ç®È¥×¼±¸Ò»ÏÂÖı¹÷ÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/stick",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 150000 )
        {
        write("[36mĞ¡µÄÂíÉÏÄÃÕâĞ©¹¤Ç®È¥×¼±¸Ò»ÏÂÖıÉÈÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/fan",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 200000 )
        {
        write("[36mĞ¡µÄÂíÉÏÄÃÕâĞ©¹¤Ç®È¥×¼±¸Ò»ÏÂ´ò½£ÓÃµÄ¹¤¾ß!![0m\n");
        who->set_temp("money/sword",1);
        destruct(obj);
        return 1;
        }
        if( obj->query_temp("name") == "[33m»Æ¼×½ğÁúµÄÑÛÖé[0m" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÄãÕæÀûº¦!!¾¹È»ÄÜ¹»ÄÃµ½»Æ¼×½ğÁúµÄÑÛÖé!!\n");
        who->set_temp("marks/dragon",1);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[33m»Æ¼×½ğÁúµÄÆ¤¸ï[0m" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÄãÕæÀûº¦!!¾¹È»ÄÜ¹»ÄÃµ½»Æ¼×½ğÁúµÄÆ¤¸ï!!\n");
        who->set_temp("marks/dragon",2);
        return 1;
        destruct(obj);
        }
        if( obj->query("name") == "[33m»Æ¼×½ğÁúµÄÁÛÆ¬[0m" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÄãÕæÀûº¦!!¾¹È»ÄÜ¹»ÄÃµ½»Æ¼×½ğÁúµÄÁÛÆ¬\n!!");
        who->set_temp("marks/dragon",3);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[33m»Æ¼×½ğÁúµÄÈñ³İ[0m" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÄãÕæÀûº¦!!¾¹È»ÄÜ¹»ÄÃµ½»Æ¼×½ğÁúµÄÑÀ³İ!!\n");
        who->set_temp("marks/dragon",4);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "[33m»Æ¼×½ğÁúµÄ¹Ç÷À[0m" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÄãÕæÀûº¦!!¾¹È»ÄÜ¹»ÄÃµ½»Æ¼×½ğÁúµÄ¹Ç÷À!!\n");
        who->set_temp("marks/dragon",5);
        destruct(obj);
        return 1;
        }
if(who->query("family/family_name")=="Ä§µ¶Äª²â"&&who->query("evil-mblade")==1)
{
if(obj->query("id")=="dragon scale"&&who->query_temp("sumblade")!=1)
        {
        command("say ¹ş¹ş£¡ÄãÄÃµ½Ä§ÁúÁÛÁË£¡Ñıµ¶ÏÖÊÀåëÈÕ¿É´ı£¡\n");
        who->set_temp("sumblade",1);
        destruct(obj);
 } else
if(obj->query("id")=="bad-evil-mblade"&&who->query_temp("bad-blade")!=1)
        {
        command("say ºÇºÇ£¡Ñıµ¶¾ÍÒªÏÖÊÀÀ²£¡\n");
        destruct(obj);
        who->set_temp("bad-blade",1);
        }
command("say °ÑÎÒĞëÒªµÄ¶«Î÷¸øÎÒ£¬µÈÒ»ÏÂÔÙÀ´£¡\n");
        return 1;
}
        if( obj->query("name") == "ÉúÌú" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÕâÊÇ¿éÉúÌúÄÄ!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!!\n");
        who->set_temp("marks/metal",1);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "»ÆÍ­" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÕâÊÇ¿é»ÆÍ­ÄÄ!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!!\n");
        who->set_temp("marks/metal",2);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "°×Òø" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÕâÊÇ¿é°×ÒøÄÄ!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!!\n");
        who->set_temp("marks/metal",3);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "½ğ×Ó" )
        {
        command("say ÕâÎ»¿Í¹Ù, ÕâÊÇ¿é»Æ½ğÄÄ!!Äú¿ÉÊÇÒª´òµã±øÆ÷°É!!\n");
        who->set_temp("marks/metal",4);
        destruct(obj);
        return 1;
        }
        else
        {
        command("say ÕâÎ»¿Í¹ÙÕæÊÇ´ó·½, ÄÇĞ¡µÄ¾Í¹§ºØ²»Èİ´ÓÃü†ª\n!!");
        return 0;
        }
}

int do_select(string arg)
{
        object who=this_player();
        object bl,sw,st,un,fa;

        if( ( arg == "blade") && who->query_temp("money/blade") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("Öı½³½«½ğÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆğÀ´ÁË......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            bl=new("data/autoload/prayer/bl2");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            bl=new("data/autoload/prayer/bl4");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            bl=new("data/autoload/prayer/bl6");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            bl=new("data/autoload/prayer/bl5");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            bl=new("data/autoload/prayer/bl3");
       else bl=new("data/autoload/prayer/bl1");
          }
          who->delete("marks/dragon");
          who->delete("money/blade");
          who->delete("marks/metal");
          bl->move(who);
          write(this_object()->query_temp("name")+"½«ÖıºÃµÄµ¶ÄÃ¸øÄã¿´ÁË¿´¡£\n\n"+
          "Äã¾õµÃÕâÒ»°Ñµ¶Òì³£µØ·æÀû, ÄÃÔÚÊÖÉÏ¶Ù¾õ×Ô¼ºµ¶·¨Òæ·¢³É³¤Ğí¶à¡£\n\n");
          return 1;
        }
    
        if( ( arg == "sword") && who->query_temp("money/sword") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("Öı½³½«½ğÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆğÀ´ÁË......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            sw=new("data/autoload/prayer/sw2");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            sw=new("data/autoload/prayer/sw4");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            sw=new("data/autoload/prayer/sw6");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            sw=new("data/autoload/prayer/sw5");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            sw=new("data/autoload/prayer/sw3");
       else sw=new("data/autoload/prayer/sw1");
          }
          who->delete("marks/dragon");
          who->delete("marks/metal");
          who->delete("money/sword");
          sw->move(who);
          write(this_object()->query_temp("name")+"½«´òºÃµÄ½£ÄÃ¸øÄã¿´ÁË¿´¡£\n\n"+
          "Äã¾õµÃÕâÒ»°Ñ½£ËùÉ¢·¢³öÀ´µÄ½£Æø¿ÉÒÔÊ¹×Ô¼º½£·¨Òæ·¢³É³¤Ğí¶à¡£\n\n");
          return 1;
        }

        if( ( arg == "stick") && who->query_temp("money/stick") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("Öı½³½«½ğÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆğÀ´ÁË......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            st=new("data/autoload/prayer/st4");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            st=new("data/autoload/prayer/st6");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            st=new("data/autoload/prayer/st2");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            st=new("data/autoload/prayer/st3");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            st=new("data/autoload/prayer/st5");
       else st=new("data/autoload/prayer/st1");
          }
          who->delete("marks/dragon");
          who->delete("marks/metal");
          who->delete("money/stick");
          st->move(who);
          write(this_object()->query_temp("name")+"½«´òºÃµÄ¹÷×ÓÄÃ¸øÄã¿´ÁË¿´¡£\n\n"+
          "Äã¾õµÃÕâÒ»¸ù¹÷×ÓÒì³£µØË³Áï, ÄÃÔÚÊÖÉÏ¶Ù¾õ×Ô¼º¹÷·¨±ÈÎäËÉÇ¿¶àÁË¡£\n\n");
          return 1;
        }

        if( ( arg == "unarmed") && who->query_temp("money/unarmed") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("Öı½³½«½ğÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆğÀ´ÁË......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            un=new("data/autoload/prayer/un4");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            un=new("data/autoload/prayer/un6");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            un=new("data/autoload/prayer/un3");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            un=new("data/autoload/prayer/un5");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            un=new("data/autoload/prayer/un2");
       else un=new("data/autoload/prayer/un1");
          }
          who->delete("marks/dragon");
          who->delete("marks/metal");
          who->delete("money/unarmed");
          un->move(who);
          write(this_object()->query_temp("name")+"½«´òºÃµÄÎäÆ÷ÄÃ¸øÄã¿´ÁË¿´¡£\n\n"+
          "Äã¾õµÃÕâÒ»°Ñ¿ÕÊÖÊ¹ÓÃµÄÎäÆ÷ºÜÌØ±ğ, ×°±¸ÔÚÊÖÉÏ¸øÄãÒ»¹ÉÁ¦Á¿¸Ğ¡£\n\n");
          return 1;
        }

        if( ( arg == "fan") && who->query_temp("money/fan") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("Öı½³½«½ğÊô¶ªÈëÈÛÂ¯ÈÛ»¯ºó, ¿ªÊ¼Æ¹Æ¹ÅÒÅÒµÄ´¸´òÆğÀ´ÁË......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            fa=new("data/autoload/prayer/fa5");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            fa=new("data/autoload/prayer/fa4");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            fa=new("data/autoload/prayer/fa2");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            fa=new("data/autoload/prayer/fa3");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            fa=new("data/autoload/prayer/fa6");
       else fa=new("data/autoload/prayer/fa1");
          }
          who->delete("marks/dragon");
          who->delete("marks/metal");
          who->delete("money/fan");
          fa->move(who);
          write(this_object()->query_temp("name")+"½«´òºÃµÄÎäÆ÷ÄÃ¸øÄã¿´ÁË¿´¡£\n\n"+
          "Äã¾õµÃÕâÒ»°ÑÉÈ×ÓºÜ³ÆÊÖ, ×°±¸ÔÚÊÖÉÏ¸øÄãÒ»¹É°²È«¸ĞÓëÍş·çÖ®Ì¬¡£\n\n");
          return 1;
        }

}

