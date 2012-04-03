//»ëÌìË®¾§(µÚ°Ë²ã½ð³¿êØÐÄ·¨)

inherit ITEM;

void create()
{
        set_name("[33m»ÆË®¾§[0m", ({ "yellow-crystal","crystal" }));
        set("title", "»ëÌìÐÄ·¨Ö®");
        set_weight(700);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¸ù");
          set("long","ÕâÊÇÒ»¸ù»á·¢³ö[33m½ð¹âµÄË®¾§[0m, ÀïÃæ¿ÌÓÐ[36m»ëÌì±¦¼øµÚ°Ë²ã[33m½ð³¿êØÐÄ·¨[0mµÄÁ·¹¦¿Ú¾÷¡£\n");
          set("value", 700);
          set("material", "gem");
           set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("no_give", 1);
          set("skill", ([
          "name" : "superforce",  // name of the skill
          "exp_required" :  1300000,     // to learn this skill.
          "sen_cost" : 40,      // gin cost every time study this
          "difficulty" : 25,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill": 150
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="Ê¥»ð½Ì")
          return -1;
        return 1;
}
