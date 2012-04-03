inherit NPC;

string *word1 = ({
  "Íõ´óÂè", "Àî¶þÉô", "¹éÈýÄï", "ÁÖËÄÒÌ", "¸ÉÂè", "¾ËÂè",
  "ËÄÒÌÆÅ", "³¤Éà¸¾",
});

string *word2 = ({
  "³ÂÀÏÍ·", "¶¡´ó±û", "ËáÃ·³¬ÈË", "´óÐÛ", "¹ÖÒ½ÇØ²©Ê¿", "°¢¸Ê",
});

string hname, wname;
string long();

void create()
{
	set_name("Ç×ÆÝ",({"relative"}));
	set("long", (: long :) );
	set("no_kill",1);
	setup();
}

string long()
{
  object me=this_player();

  switch (random(3)) {
	case 0:
	  return word1[random(sizeof(word1))]+"\n";
	  break;
	case 1:
	  return word2[random(sizeof(word2))]+"\n";
	  break;
	case 2:
	  if (random(2))
	    return "ÐÂÀÉ"+hname+"µÄÇ×ÆÝ"+me->query("name")+"¡£\n";
	  else
	    return "ÐÂÄï"+wname+"µÄÇ×ÆÝ"+me->query("name")+"¡£\n";
  }
}

int start_marry(object husband, object wife)
{
  hname = husband->query("name");
  wname = wife->query("name");
} 
