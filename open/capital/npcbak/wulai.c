// wulai.c by bigcat

inherit NPC;

string do_ask1();
string do_ask2();

void create()
{
	set_name("无赖", ({ "wulai", "human" }) );
	set("race", "人类");
	set("age", 30);
	set("long", "。\n");
	
	set("str", 26);
	set("cor", 25);
	set("combat_exp",300);

	
	set("chat_chance_combat",5);
	set("chat_msg_combat", ({
		"无赖大叫一声:大爷来收保护费了,不想死的就乖乖的交出来!\n",
		"无赖大剌剌的走过来,向你吐了一口脓痰。\n"
	}) );
		
	set("chat_chance", 5);
	set("chat_msg", ({
	    "无赖说道: 听说移花宫有一个宫女潜藏在妓院，可是就不知妓院在哪。\n",
	    "无赖说道: 听说有个水仙姑娘倾城倾国，真想一亲芳泽。\n",
	    "无赖说道: 能看到传说中的水仙姑娘，死也瞑目了。\n",
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	set("inquiry", ([
	    "燕南天"	:	"啊，快躲起来，我最怕他了。",
	    "水仙姑娘"	:	(: do_ask1 :),
	    "丽春院"	:	"是听我兄弟说过那儿，不过没逛过，可惜。\n",
	    "移花宫"	:	(: do_ask2 :),
	]) );

	setup();
       add_money("coin",100);
}

string do_ask1()
{
  int	query;
  object me=this_player();

  query=me->query_temp("quests/help_water_god");

  if (!query || query != 1  || me->query("quests/help_water_god"))
  {
      switch (random(5)) {
	case 0:
	  return "水仙姑娘是你的老相好吗? 介绍给我吧。\n";
	  break;
	case 1:
	  return "请问你知道水仙姑娘在哪一家窑子? 带我去见识见识。\n";
	  break;
	case 2:
	  return "我又不是水仙姑娘，问我这干嘛。\n";
	  break;
	case 3:
	  return "我不认识什么水仙杜鹃的，去去去。\n";
	  break;
	default:
	  return "谁知道谁是谁啊。\n";
      }
  }
  else {
    me->set_temp("quests/help_water_god", 2);
    if (random(2))
      return "水仙姑娘听说正在逃亡当中，全部的希望就靠大侠燕南天了。\n";
    else
      return "水仙姑娘犯了移花宫的大忌，现在正在被追杀哩。"+
	     "无赖叹了口气，说道: 不知燕南天会不会出手解救。\n";
  }
}

string do_ask2()
{
  if (random(2))
    return "移花宫? 又有谁知道在哪儿了，只不过是谣传罢了。\n";
  else
    return "我还种树宫咧，去你Ｘ的宫啦，别来烦人。\n";
}
