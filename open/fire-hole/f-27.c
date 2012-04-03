#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[0;1;31m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m");
  set ("long", @LONG
»ð¹âËÄÉä, ÁÒÑæÖ±³åÌì¶¥, Ê¹µÃÕâÀïµÄÆøºòÊ®·ÖÑ×ÈÈ, ËÄÖÜ¶¼ÊÇ»ð¹â,
Õâ´ó¸ÅÊÇÍ³ÖÎ×ÅÕâÀïµÄ¹ÖÎïÒÔÎÞÇîµÄÁ¦Á¿ËùÔì³ÉµÄ»ðÖ®½á½ç, µ±ÄãÀ´µ½ÁËÕâ
Ê±, Í¬Ê±±»ËüµÄ»ð¹âÃÔ»ó, ÕÒ²»µ½ÕýÈ·µÄ³öÂ·¡£
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"f-24.c",
  "southeast" : __DIR__"f-31.c",
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
        if (dir == "northwest" || dir == "southeast")  
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