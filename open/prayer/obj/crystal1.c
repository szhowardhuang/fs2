//»ëÌìË®¾§(1~5²ã»ù±¾ĞÄ·¨)
#include <command.h>

inherit ITEM;

void create()
{
        set_name("°×Ë®¾§", ({ "white-crystal","crystal" }));
        set("title", "»ëÌìĞÄ·¨Ö®");
        set_weight(400);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¸ù");
          set("long","ÕâÊÇÒ»¸ù»á·¢¹âµÄË®¾§, ÀïÃæ¿ÌÓĞ[36m»ëÌì±¦¼ø»ù´¡ĞÄ·¨[0mµÄÁ·¹¦¿Ú¾÷¡£\n");
          set("value", 500);
          set("material", "gem");
          set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("no_give", 1);
          set("skill", ([
          "name" : "superforce",    // name of the skill
          "exp_required" :  5000,  // to learn this skill.
          "sen_cost" : 25,              // gin cost every time study this
          "difficulty" : 10,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill":  50
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="Ê¥»ğ½Ì")
          return -1;
        return 1;
}
