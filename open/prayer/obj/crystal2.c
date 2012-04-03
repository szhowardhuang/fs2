//»ëÌìË®¾§(µÚÁù²ãÐþ»ìãçÐÄ·¨)

inherit ITEM;

void create()
{
        set_name("[30mºÚË®¾§[0m", ({ "black-crystal","crystal" }));
        set("title", "»ëÌìÐÄ·¨Ö®");
        set_weight(500);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¸ù");
          set("long","ÕâÊÇÒ»¸ù»á·¢¹âµÄ[30mºÚÉ«Ë®¾§[0m, ÀïÃæ¿ÌÓÐ[36m»ëÌì±¦¼øµÚÁù²ã[30mÐþ»ìãçÐÄ·¨[36mµÄÁ·¹¦¿Ú¾÷¡£[0m\n");
          set("value", 600);
          set("material", "gem");
          set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("no_give", 1);
          set("skill", ([
          "name" : "superforce",  // name of the skill
          "exp_required" :  150000,     // to learn this skill.
          "sen_cost" : 25,              // gin cost every time study this
          "difficulty" : 25,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill":  80
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="Ê¥»ð½Ì")
          return -1;
        return 1;
}
