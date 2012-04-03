//»ëÌìË®¾§(µÚ¾Å²ãÑªñ·²ÔÐÄ·¨)

inherit ITEM;

void create()
{
        set_name("[31mºìË®¾§[0m", ({ "red-crystal","crystal" }));
        set("title", "»ëÌìÐÄ·¨Ö®");
        set_weight(750);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¸ù");
          set("long","ÕâÊÇÒ»¸ù»á·¢³ö[31m¹îÒìºì¹âµÄË®¾§[0m, ÀïÃæ¿ÌÓÐ[36m»ëÌì±¦¼øµÚ¾Å²ã[31mÑªñ·²ÔÐÄ·¨[0mµÄÁ·¹¦¿Ú¾÷¡£\n");
          set("value", 800);
          set("material", "gem");
          set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("no_give", 1);
          set("skill", ([
          "name" : "superforce",  // name of the skill
          "exp_required" : 1800000,     // to learn this skill.
          "sen_cost" : 50,         // gin cost every time study this
          "difficulty" : 25,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill":  200
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="Ê¥»ð½Ì")
          return -1;
        return 1;
}
