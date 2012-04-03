inherit NPC;
object ob1=this_object();
object ob2=this_player();
int done=0;
void create()
{
	set_name("ÂÌÃ«ÀÏ×æ",({"ru mou","ru"}));
	set("long","´ËÈËÉí³¤Ê®³ß ,È«ÉíÂúÊÇÂÌÉ«µÄÃ«·¢ ,ÉíÉÏµÄ¼¡ÈâÒòÁ·¹¦Ö®¹Ê
ÒÑ¾À½á²»Çå ,³¤³öÀàËÆÐëÐëÖ®ÀàµÄÈâ¸ù ,¿´ÆðÀ´Ê®·ÖµÄ¹îÒì¡£ .\n");
	set("gender","ÄÐÐÔ");
       set("combat_exp",100000);
        set("attitude","aggressive");
	set("age",51);
	set("title","ÑªÄ§");
	set("force",1000);
	set("max_gin",1000);
        set("max_kee",4000);
	set("max_force",1000);
        set("force_factor",15);
        set("str",50);
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
        (: this_object(),"special_attack" :),
        }));
        set("cor", 40);
	set("per", 10);
	set("int", 30);
	set("cps",40);
	set("con", 30);
	set("spi", 15);
	set("kar", 40);
        set_skill("unarmed",100);
        set_skill("dodge",60);
       set_skill("parry",60);
	set_skill("move",50);
	set_skill("force",50);
	setup();
}

         
void init()
{
add_action("do_show","show");
}

int do_show(string str)
{
 if(!this_player()->query_temp("allow_read",1))
   {
    write("ÄãÒª×÷Ê²Ã´??\n");
    return 1;
    }
 if(str!="blood_sword")
    {
    write("ÄãÒª×÷Ê²Ã´??\n");
    return 1;
    } 
 else
  {
    write("ÂÌÃ«ÀÏ×æµÀ : µÈµÈ......Õâ°Ñ½£ÄãÊÇ´òÄÄÀ´µÄ??´ÏÃ÷µÄ»° ,¹Ô¹ÔµÄ°Ñ½£
    ¸øÎÒ ,ÎÒ»¹¿ÉÈÄÄã²»ËÀ \n");
    this_player()->set_temp("have_show",1);
   return 1;
   }
 }   
    
       
 int special_attack()
 {
   object ob;
   ob=this_object()->query_enemy();
   message_vision("[1;34mÂÌÃ«ÀÏ×æÑÛÂ¶Çà¹â ,ÊÖ±Û±©³¤ÏòÄã¶øÀ´ ,ÔÚÄãÉíÉÏÁôÏÂÒ»µÀÄª´óµÄÉË¿Ú.\n[0m",this_object());
   ob->add("kee",-50);
  return 1;
  }
     
 void greeting(object ob)
 {
  if( !ob || environment(ob) != environment() ) return;
  if(ob->query("family/family_name","ÏÉ½£ÅÉ") )
     say("ÂÌÃ«ÀÏ×æµÀ:¹þ!¹þ!ÏÉ½£ÅÉ×ÓµÜÀ´µÄºÃ ,ÈÃÎÒËÍÄãÉÏÎ÷Ìì°É.\n ");
  else
    say("ÀÏ×æ²»ÄÍ·³µÄËµ:ÕâÊÇÎÒ¸úÏÉ½£ÅÉÖ®¼äµÄ¶÷Ô¹ ,Ð¡×ÓÉÙ¹ÜÏÐÊÂ.\n");
  }
  
 int accept_object(object who,object ob)
 {
if( ob->query("id")!="blood_sword"||!who->query_temp("have_show",1) )
    {
      write("ÂÌÃ«ÀÏ×æµÀ :¶àÐ»ÄãµÄÀñÎï°¡....ÕâËãÊÇÇóÈÄÂð??ÎÒ¿ÉÊÇ²»»áÊÖÏÂÁôÇéµÄ\n");
      return 0;
    }
   else
     {
      who->remove_all_killer();
      set_heart_beat(1);
      write("ÀÏ×æµÀ:¶àÐ»Äã½«Õâ°Ñ½£»¹¸øÎÒ,ÄãÈç´òÓ®ÎÒµÄ»°ÎÒ¿É¸æËßÄãÒ»¸öÃØÃÜ ,À´°É.\n");
      who->set_temp("have_fight",1);
      write("ÀÏ×æËµ°Õ ,½«ÊÖÖÐ³à÷ëÒ»ÎÕ ,²»ÖªÊÇ²»ÊÇ´í¾õ ,Äã¸Ðµ½ÀÏ×æÆøÊÆÒÑºÍ¸Õ¸Õ
      ´ó²»ÏàÍ¬ ,Äã¸Ðµ½Ð©ÐíµÄ¿Ö¾å\n");
      ob1->set("combat_exp",500000);
      ob1->set_skill("shasword",80);
      ob1->set_skill("sword",80);
      ob1->map_skill("sword","shasword");
      command("wield blood_sword");
      ob2->set_temp("have_give",1);
      return 0;
      }
 }         
          
         
 void die()
  {
   object me;
   me = this_object()->query_temp("last_damage_from");
   if (me && userp(me))  {
     me->add("bounds",100); 
     tell_room(environment(),sprintf("%s´ÓÀÏ×æÉíÉÏ³ýÏÂ100¸ùÂÌÃ«.\n",me->name()));
   }
   ::die(); 
  }
       
  void heart_beat()
   {
     if(query("kee") <0)
        die();
        if(!ob2) return ;
     if(ob2->query_temp("have_give",1))
     if(done==0)
     if( ob1->query("kee") < ob1->query("max_kee")*0.2)
       {
         ob2->remove_all_killer();
         message_vision("Ð¡×Ó...Äã±¾ÊÂ²»´íÂé....,¾¹È»ÄÜ´òÓ®ÎÒ ,½ñÌì ,ÎÒ¾ÍÆÆÀý×÷¸öºÃÈË ,
         ¸úÄãËµÒ»¸öÌì´óµÄÃØÃÜ°É\n",ob2);
         tell_object(ob2,"ÂÌÃ«ÀÏ×æÒÔ¸¹Óï¸æËßÄã : ÃØÃÜ¾ÍÔÚÇ°É½µÄÑÒÑ¨ÖÐ,ÄãÈçÓÐÔµµÄ»°×ÔÈ»»á·¢ÏÖ\n");
         message_vision("¹þ....ÕâÊÇ»Ø±¨Äã»¹½£Ö®Çé ,ÏÂ´Î¼ûÃæ ,¿É±ð¹ÖÎÒÊÖÏÂ²»ÁôÇé°¡..\n",ob2);
         done++;
         ob2->set_temp("have_win",1);
        }
     ::heart_beat();
   }               
