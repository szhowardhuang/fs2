//by sueplan Öî¸ğÒØÕÑ ×îÄÑ´ò
//ĞŞ¸Äjuka_jone.c ÓÚ 90 8/28 by sueplan
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
int done=0;


void create() {
        set_name("[1;32mÖî¸ğÒØÕÑ[0m",({"juka jone","juka","jone"}));
        set("class","scholar");
        set("nickname","$HIW$¼¯ÌìÏÂ¼ÆÄ±Ö®´ó³É$NOR$");
        set("title","[1;33mÖÇ[1;31mÂú[1;33m¸É[1;31mÀ¤[0m");
        set("long",
        "\nÖî¸ğÒØÕÑÊÇÖî¸ğ¿×Ã÷µÄËï×Ó£¬Öî¸ğ¿×Ã÷µÄËùÓĞ¼¼·¨Ëû
¶¼»á£¬Ëû¿ÉÒÔËãÊÇÖî¸ğÒ»×åÖĞ×îÎªÓĞ´ÏÃ÷µÄÒ»¸öÈË
È»¶øËûÈ´ÃÔÊ§ÁË×Ô¼º£¬ÀûÓÃ¼ÆÄ±¿ªÆğÕ½ÊÂ£¬²Ğº¦ÉúÁé
³ÉÎªÖî¸ğÒ»×åÖĞ×î°ÜÃûÉùÖ®ÈË¡£\n");
        set("str",40);
        set("cor",40);
        set("cps",40);
        set("gender","ÄĞĞÔ");
        set("attitude","heroism");
        set("family/family_name","ÈåÃÅ");
        set("quest/gold-fire","1");
        set("max_gin",20000);
        set("max_kee",25000);
        set("max_sen",20000);
        set("max_force",20000);
        set("force",20000);
        set("age",93);
        set("force_factor",25);
        set("combat_exp",8000000);
        set("score",9000000);
        set_skill("stabber",130);
        set_skill("dodge",150);
        set_skill("move",120);
        set_skill("parry",120);
        set_skill("knowpen",120);
        set_skill("god-plan",100);
        set_skill("plan",120);
        set_skill("force",200);
        set_skill("fireforce",200);
        set_skill("winter-steps",100);
        map_skill("plan","god-plan");
        map_skill("dodge","winter-steps");
        map_skill("move","winter-steps");
        map_skill("stabber","knowpen");
        map_skill("parry","knowpen");
        map_skill("force","fireforce");
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);

        set("functions/movedown/level",100);
        set("functions/finger/level",100);
        set("functions/gold-fire/level",90);
set("chat_chance_combat", 100);
set("chat_msg_combat",({
(: perform_action("stabber.movedown") :),
(: perform_action("stabber.finger") :),
}));
        set("chat_chance",50);
        set("chat_msg",({
        }));
setup();
        carry_object(START_OBJ"ten_pen")->wield();
        carry_object(START_OBJ"k_cloth")->wear();
        carry_object(PING_OBJ"neck0")->wear();
        carry_object("/open/scholar/room/newplan/obj/s-shield")->wear();
        add_money("diamond",10);
 }
void init()
{
add_action("do_action","",1);
        set_heart_beat(1);
}
int do_action(string str)
  {
        object who=this_player();
        if(str)
        {
        if(strsrch(str,"plan.speed")!=-1)
        {
          command("say ÓŞ´ÀÑ½!!ÄÑµ½Äã²»ÖªµÀÆæÏ®Ö®¼ÆÊÇÎÒËù´´µÄÂğ?!\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.hole")!=-1)
        {
          command("say ¸ÒÔÚÎÒÃæÇ°ÍÚÏİÚå??ÉÙÂôÅªÕâÖÖĞ¡´ÏÃ÷ÁË!!\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.wait")!=-1)
        {
          command("say ÏëÓÃ·ü±øÍæÎÒ?!ÄãÒÔÎªÎÒ»á±¿µ½ÕâÖÖµØ²½Âğ??\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.rob")!=-1)
        {
          command("say ³Ã»ğ´ò½Ù?!ÓŞ´À!!ÄÑµÀÄã²»ÖªµÀ´Ë¼ÆÎªÎÒËù´´Âğ??\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.false")!=-1)
        {
          command("say Ğé±øÖ®¼ÆÊÇ×î»ù±¾µÄ¼ÆÄ±, ÎÒ»áÓĞ²»¶®Ö®Àí??\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.mount")!=-1)
        {
          command("say Ïë¸ÏÎÒ×ß??ÄãÏëµÃÌ«ÃÀÁË°É!\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"lock-link")!=-1)
        {
          command("say ÌúËøÁ¬»·ÎÒÑĞ¾¿µÄ·½·¨¿É±ÈÄã¶à×ÅÄØ!!¸Ò¶ÔÎÒÓÃ?\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.ghost")!=-1)
        {
          command("say ÆÛµĞ??ÎÒ¿É²»»á±¿µ½ÕâÖÖµØ²½à¸!!\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.getweapon")!=-1)
        {
          command("say ÁùèºÆæÂÔ??ÄãÕæÊÇ±¿µÄ¿ÉÒÔÑ½!!\n");
          write("\nÄã¼ûÖî¸ğÒØÕÑÉñÌ¬×ÔÈô, ¾ÍÆÆ½âÁËÑÛÇ°µÄ¼ÆÄ±!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        }
return 0;
}
int accept_kill(object who,object me)
{
        who=this_player();
        me=this_object();
        command("wield pen");
        command("say ¾ÍÈÃÄã¿´¿´Ê²Ã´ÊÇÌìÏÂµÚÒ»¾üÊ¦µÄ¼ÆÄ±°É!!ÊÜËÀ!!");
        command("kill "+who->query("id"));
        command("perform stabber.movedown");
        return 1;
}
int accept_fight(object who)
{
        who=this_player();
        command("say Èç¹û²»¸ÒºÍÎÒ½ÏÁ¿, ÄÇ¾Í±ğÀ´Õâ±ßËÍËÀ!!");
          return 0;
}

void heart_beat()
{
 mixed all;
object me,room,*target,victim,obj;
int i,k,a,b;
a=random(100);
me=this_object();
room=environment(me);
 all = all_inventory(room);
target=me->query_enemy(room);
if(i=sizeof(target)) 
  {
        if(a <= 10) {
        victim=target[random(i)];
        if(environment(me)==environment(victim)) {
        for(k=0;k<5;k++)
        {
        message_vision(HIR"Öî¸ğÒØÕÑÈ¡³öÖî¸ğ¿×Ã÷Ëù´´Ö®Á¬åó£¬Ïò$N¾ø·¢¶ø³ö!!\n"NOR,victim);
        victim->add("kee",-800);
        COMBAT_D->report_status(victim);
        }
        }
        }
        if(a<=50&&a>=30) {
    message_vision(HIB"

Öî¸ğÒØÕÑÈ¡³ö×Ô×æ¸¸Ëù´«µÄµÀ¾ß - ³åÄ¾Á÷Âí!!

Ğ°¶ñµÄ¿ñºğ£º¿´ÎÒµÄ¡®×ª±øÄæ¿öÖ®¼Æ¡¯ ÑÛÇ°µÄµĞÈËÒ»Ò»µ¹ÏÂ!!

"NOR,me);
for(b=0;b<i;b++) {
if(userp(target[b])) continue;
target[b]->die();
me->add("force",-b*5);
        }
        }
        if(a<85&&a>65) {
message_vision(HIW"\nÖî¸ğÒØÕÑÔËÆğÖî¸ğÒ»ÃÅÖ®»¤ÉíÄÚ¾¢£¬Ò»Õó°×ÑÌ´ÓÍ·¶¥ÉÏÃ±³ö\n"NOR,me);
        me->delete_busy();
        me->add("force",300);
        me->receive_curing("kee",500);
        me->receive_heal("kee",500);
          me->receive_heal("sen",100);
          me->receive_heal("gin",100);
        }
        if(a<30&&a>=20) {
          message_vision(HIW"\nÖî¸ğÒØÕÑÄÃÆğµÀ¾ß¡®Áù¼×ÌìÊé¡¯£¬¿ÚÖĞÄî³öÖäÎÄ£¬ÈÃÄãÉíĞÄÊÜµ½¼«´óµÄÉËº¦!!!\n"NOR,me);
        target[b]->start_busy(1);
        target->add("kee",-500);
        }
        if(a >97  && me->is_fighting())
        {
        message_vision(HIY"
	       Öî¸ğÒØÕÑ½«ÆæÊéÁùèºÖÃÕÆÉÏ£¬ÉíÉÏÆø¾¢ÔÌ²Ø×ÅÖî¸ğ¼ÒÎäÑ§
           Ö®áÛ£¬Öî¸ğºêÒØß³ºÈ»Øµ´"HIR"¡®ÔË³ïá¡á¢ Õ½ÎŞ²»Ê¤¡¯"HIW"²»¶ÏÏòËÄÖÜÎüÒıÆø¾¢\n"NOR,me);
        for( i = 0 ; i < sizeof(all) ; i++)
	   {
    obj = all[i];
	    if( obj->is_character() && !obj->is_corpse() && living(obj)
	    && obj->query("id")!="juka jone")
	      {
message_vision(HIR"½á¹ûËùÓĞÈËÄÚÁ¦È«ÊÜÁùèºÎüÒı£¬Ğ¹ÏòËÄÖÜ!!\n"NOR,obj);
	      obj->add("force",-((obj->query("force")/5))*4);
	      COMBAT_D->report_status(obj, 1);
	      }
	   }
	 }
  }
        :: heart_beat();
}
void die()
{
object winner = query_temp("last_damage_from");
object item;
item=new("/u/s/sueplan/newplan/obj/qbook.c");
//µÈÉıµ½archºó»á¸Ä
item->move(winner);
tell_room(environment(),sprintf("%s´ÓÖî¸ğÒØÕÑÉíÉÏËÑµ½Ò»±¾ÁùèºÆæÂÔ¡£\n",winner->name()));
tell_object(users(),"
[1;37mÖî¸ğÒØÕÑËµµÀ : 
        [1;37mÏëÖî¸ğÁÁ³öÊ¦Î´½İÉíÏÈËÀ  ³£Ê¹Ó¢ĞÛÀá\¡«Âú¡«½ó¡«\n
                    [1;33m"+winner->query("name")+"[1;37mÑ½£¡£¡\n
           [1;37mÄÑµÀÎÒÌìÏÂµÚÒ»¾üÊ¦µÄ¼ÆÄ±²»¼°ÄãÂğ£¡£¿[0m");
winner->set_temp("ko_jone",1);
:: die();
}
