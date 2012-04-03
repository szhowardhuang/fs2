inherit ITEM;

void create()
{
        set_name("test", ({ "test" }) );
        set("unit", "把");
        set("long", "一把专门给 sword 用的礼物，可以 full 三次\n");
}

void init ()
{
  add_action ("full", "full");
}


int full(string str)
{
  int max;
  object me;

  me=this_player();
  
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("force",me->query("max_force"));
  me->set("eff_kee",max);
  me->set("atman",me->query("max_atman"));
  me->set("mana",me->query("max_atman"));
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();
  me->set("water",max);

  me->clear_condition();

  message_vision( sprintf("$N唸起不死族回复咒文 撒拉 伊克 庵修姆  \n"),
                  this_player());

  if (me->query_temp("full") == 2)
    destruct( this_object());
  me->add_temp("full",1);

  return 1;
}
