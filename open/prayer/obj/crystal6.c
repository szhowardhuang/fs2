//»ëÌìË®¾§(µÚÊ®²ãÐþÓîÖæÐÄ·¨)

inherit ITEM;

void create()
{
        set_name("[32mÂÌË®¾§[0m", ({ "green-crystal","crystal" }));
        set("title", "»ëÌìÐÄ·¨Ö®");
        set_weight(750);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¸ù");
          set("long","ÕâÊÇÒ»¸ù»á·º³ö[32mµ­ÂÌ¹âÃ¢µÄË®¾§[0m, ÀïÃæ¿ÌÓÐ[36m»ëÌì±¦¼øµÚÊ®²ã[32mÐþÓîÖæÐÄ·¨[0mµÄÁ·¹¦¿Ú¾÷¡£\n");
          set("value", 800);
          set("material", "gem");
          set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("no_give", 1);
          set("skill", ([
          "name" : "superforce",  // name of the skill
          "exp_required" :  2400000,     // to learn this skill.
          "sen_cost" : 60,              // gin cost every time study this
          "difficulty" : 25,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill":  250
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="Ê¥»ð½Ì")
          return -1;
        return 1;
}
