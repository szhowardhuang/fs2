inherit ITEM;
void create()
{
      set_name("¾Å×ª[1;33m½ð[0mµ¤",({"gold_pill"}) );
      set_weight(100);
      if( clonep() )
           set_default_object(__FILE__);
      else {
           set("unit","¿Å");
           set("long","ÕâÊÇÕâÊÇÒ»¿Å·Ç³£Õä¹óµÄµ¤Ò©, ÔËÓÃÄÚ\¹¦·þ\»¯(adhibit)ºó¿ÉÒÔÔö¼ÓÄÚÁ¦¡£\n");
           set("value",100000);
           }
      setup();
}

void init()
{
	add_action("do_adhibit","adhibit");
}

int do_adhibit(string str)
{
	object me=this_player();
	object ob=this_object();
	if( str != "gold_pill" )
        {
	write("·þ»¯Ê²Ã´?\n");
        return 1;
	}
if(me->query("quest/catch_thief/gold_pill")==1)
{
write("ÄãÒÑ¾­³Ô¹ýÁË¡£\n");
return 1;
}
	  message_vision("$N½«$n·þÏÂ, Ëæ¼´×øÏÂ\ÔË\¹¦¡£\n",me,ob);
	  write("Äã¸Ð¾õµ½µ¤ÌïÒ»¹ÉÈÈÆø»º»ºÉÏÉý, Õâ¹ÉÈÈÆøËæ×ÅÄãµÄÄÚÁ¦ÔËÐÐÆæ¾­°Ë"+
	  "ÂöÒ»ÖÜ, Ö®ºó±ãÏûÊÅÎÞ×ÙÁË¡£\n");
	  me->add("max_force",20);
          me->set("quest/catch_thief/gold_pill",1);
	  destruct(ob);
          return 1;
}
