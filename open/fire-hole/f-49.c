#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[0;1;31m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mt[0m");
  set ("long", @LONG
ÕâÀïÊÇ½á½çµÄ±ßÔµ, ÕâÀïµÄÄ§·¨Á¦¾ÍÃ»ÄÇÃ´µÄÇ¿ÁÒÁË, ÌìºòÎÂ¶È¸úÆ½
³£Ò»Ñù, µ«»¹Î´Àë¿ª»Ã½çµÄ¿ØÖÆ·¶Î§, ÕâÀïÓÐÒ»¸ùÖ±´ïÔÆ¼Ê, Ê®·ÖÆæ¹ÖµÄ
¾ÞÊ¯, Õâ¸öÒ²ÊÇÄÃÀ´¹®¹Ì½á½çÓÃµÄ°É! 
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"f-47.c",
  "northeast" : __DIR__"f-48.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/small-dragon.c" : 1,
]));

  setup();
}
int valid_leave(object who, string dir)
{  
        int exp,kar,cps,cor,intt,factor=50; 
        object ob2;  
        if (dir == "northwest" || dir == "northeast")  
        {        
                if (present("small dragon",environment(who)) && 
                    who->is_fighting())  //¼ì²éÐ¡»ðÁúÊÇ·ñ»¹ÔÚÓëÒÆ¶¯ÕßÊÇ·ñÔÚÕ½¶·ÖÐ   
                {                   
                  if(who->query_temp("flee")==1)
                  {
                    return notify_fail(HIR"Ð¡»ðÁúÈÔÈ»µ²×¡ÁËÈ¥Â·\n"NOR);                    
                  }
                  exp=who->query("combat_exp");
                  kar=who->query("kar");
                  cps=who->query("cps");
                  cor=who->query("cor");
                  intt=who->query("int");
                  if(kar>30)
                    kar=30;
                  if(cps>30)
                    cps=30;
                  if(cor>30)
                    cor=30;
                  if(intt>35)
                    intt=35;
                  if(who->query("setgift-mk")==1)
                  {
                    kar=who->query("setgift/kar");
                    cps=who->query("setgift/cps");
                    cps=who->query("setgift/cor");
                    intt=who->query("setgift/int");
                  }   
                  if(exp<60000000)
                  factor=10;
                  else if(exp<8000000)
                  factor=20;
                  else if(exp<10000000)
                  factor=30;
                  else if(exp<12000000)
                  factor=40;                 
                  if(random(190)>(factor+kar+cps+cor+intt))
                  {                                      
                    who->set_temp("flee",1);
                    call_out("remove_flee",1,who);
                    return notify_fail(HIR"\nÐ¡»ðÁúµÄÉíÌåµ²×¡ÁËÍËÂ·\n"NOR); 
                  }                    
                 }                    
        }
        return :: valid_leave(who,dir);
}
int remove_flee(object who)
{
   if(who)
   who->delete_temp("flee",1);
   return 1;
}