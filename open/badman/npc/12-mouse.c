#include <ansi.h>
#include </open/open.h>
inherit NPC;

object ob=this_object();
string do_mention(object who);
int j=0 ,k=1;
void create()
{      object ob;
        set_name("ÎºÎŞÑÀ", ({ "wei wu-ya","wei","ya"}) );
        set("gender", "ÄĞĞÔ" );
        set("title","[35mÊ®¶ş[1;37mĞÇÏó[0m");
        set("nickname","[35mÊó[0m");
        set("age",59);
        set("str",30);
        set("cps",30);
        set("cor",30);
        set("per",30);
        set("int",30);
        set("spi",30);
        set("con",30);
        set("kar",30);
        set("force",3000);
        set("max_kee",3000);
        set("sen",3000);
        set("max_sen",3000);
        set("kee",3000);
        set("max_gin",3000);
        set("gin",3000);
        set_skill("rain-throwing",100);
        set_skill("blackforce",100);
        set_skill("shade-steps",100);
        set("max_force",3000);
        set_skill("move",100);
        set_skill("force",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("throwing",120);
        map_skill("dodge","shade-steps");
        map_skill("move","shade-steps");
        map_skill("force","blackforce");
        map_skill("throwing","rain-throwing");
        set_skill("unarmed",200);
        map_skill("parry","rain-throwing");
        set("force_factor",20);
        set("chat_chance",10);
        set("chat_chance_combat", 75),
        set("chat_msg_combat", ({
                (: this_object(), "special_att2" :),
                (: this_object(), "special_att" :),
                (: this_object(), "special_att3" :),
                "ÎºÎŞÑÀÈ«ÉíÉ¢·¢³öÍ¸¹ÇµÄº®Æø !\n",
                               })); 
        set("combat_exp", 2000000);
        set("attitude", "heroism");
       
        setup();
        add_money("gold",10);
       ob=carry_object("/open/badman/obj/mouse_bite.c");
       ob->set_amount(600);
       ob->wield();

}

int special_att()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
       message_vision("[31;1mÎºÎŞÑÀ×Ô²Ğ¼ºÉí,ÒÔÉ±Òâ»»³ÉÄ§Æø¡£[0m\n
            [32m¡­¡­ÎºÎŞÑÀÉíÉÏ·¢³öÒ»¹ÉÇ¿´óµÄÄ§Æø¡­¡­[0m\n
    [32;1m¡öÎºÎŞÑÀÉíÉÏÄ§ÆøÖğ½¥µØ¾Û¼¯ÔÚË«ÊÖ,ÔÚË«ÊÖÉÏĞÎ³ÉÁ½ÍÅÉ±Æø¡ö\n[0m
            ÎºÎŞÑÀÙ¿µØ´óºÈÒ»Éù£­£­[36;1m¡®Ä§ÆøÉ±¡¯[0m£­£­\n\n",one);
      message_vision("[31mÎºÎŞÑÀÍ»È»ºíÍ·Ò»¶¯¡«¡«¡¡[35mÖ»¼ûÎºÎŞÑÀ¿ÚÖĞÅç³öÒ»µÀÑªÖùÍù$NÉäÈ¥¡«¡«[0m\n
[34;1mÎºÎŞÑÀÊ¹µÄÄËÄ§ÆøÉ±Ö®[0m
              [34mÖÕ¼«¡«±ØÉ±°ÂÒå[0m ¡®[33;1;5mÄ§ÑªÆøÉ±[0m¡¯\n
[32;4mÖ»¼û$N²ÒÔâÃğ¶¥,¶øÎºÎŞÑÀÒàÉíÊÜÖØ´´¡£[0m\n",one);
        after = me->query("kee");
        one->receive_wound("kee",50+random(120));
         COMBAT_D->report_status(one);
        one->start_busy(2);

        return 1;
}
int special_att2()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
       message_vision("[31;1mÎºÎŞÑÀ×Ô²Ğ¼ºÉí,ÒÔÉ±Òâ»»³ÉÄ§Æø¡£[0m\n
            [32m¡­¡­ÎºÎŞÑÀÉíÉÏ·¢³öÒ»¹ÉÇ¿´óµÄÄ§Æø¡­¡­[0m\n
    [32;1m¡öÎºÎŞÑÀÉíÉÏÄ§ÆøÖğ½¥µØ¾Û¼¯ÔÚË«ÊÖ,ÔÚË«ÊÖÉÏĞÎ³ÉÁ½ÍÅÉ±Æø¡ö\n[0m
            $NÙ¿µØ´óºÈÒ»Éù£­£­[36;1m¡®Ä§ÆøÉ±¡¯[0m£­£­\n\n",one);
      message_vision("
              [34mµÚ¾Å²ã[0m ¡®[33;1m·çÄ§¿ñ×ªÒµ[0m¡¯\n
[32;4m½á¹û¶Ô$NÔì³É¼«ÆäÑÏÖØµÄ´´ÉË¡£[0m\n",one);



        after = me->query("kee");
        one->receive_wound("kee",60+random(70));
         COMBAT_D->report_status(one);
        one->start_busy(1);

        return 1;
}
int special_att3()
{
        object *me,one;
        int i;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
       message_vision("[31;1mÎºÎŞÑÀ×Ô²Ğ¼ºÉí,ÒÔÉ±Òâ»»³ÉÄ§Æø¡£[0m\n
            [32m¡­¡­ÎºÎŞÑÀÉíÉÏ·¢³öÒ»¹ÉÇ¿´óµÄÄ§Æø¡­¡­[0m\n
    [32;1m¡öÎºÎŞÑÀÉíÉÏÄ§ÆøÖğ½¥µØ¾Û¼¯ÔÚË«ÊÖ,ÔÚË«ÊÖÉÏĞÎ³ÉÁ½ÍÅÉ±Æø¡ö\n[0m
            $NÙ¿µØ´óºÈÒ»Éù£­£­[36;1m¡®Ä§ÆøÉ±¡¯[0m£­£­\n\n",one);
      message_vision("
              [34mµÚ°Ë²ã[0m ¡®[33;1m¶·Ä§ÎŞÉú»ê[0m¡¯\n
[32;4m½á¹û¶Ô$NÔì³É¼«ÆäÑÏÖØµÄ´´ÉË¡£[0m\n",one);


        one->receive_wound("kee",40+random(70));
        one->apply_condition("bleeding",10);
        one->start_busy(1);
        COMBAT_D->report_status(one);
        return 1;
}













