#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[31m[1m»ðÁú»Ã½ç[0m[1m--[32mÂÌÉ«½á½ç[0m");
  set ("long", @LONG
À´µ½´ËµØ, ÄãÍùËÄÖÜÌ½ÁËÌ½, ÕâÀïµÄ»·¾³¸ú¸Õ²ÅÄã¿´µ½µÄµØ·½²»Ì«Ò»Ñù
. µØÉÏ»­ÁËÐí¶àÆæÐÎ¹Ö×´µÄÍ¼°¸, ¸üÆæÌØµÄÊÇ, ÉÏ·½¾¹ÓÐÒ»µÀÂÌÉ«¹âÃ¢ÕÕÉä
×ÅÕâÀï, Äã²»½û¸Ðµ½¾ªÆæ, ÔÚÈç´ËµÄµØ·½¾¹ÓÐÀàËÆ¼«¹âµÄ¾°Ïó, ÕæÁîÄã´ó¿ª
ÑÛ½ç¡£
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"f-5.c",
  "southeast" : __DIR__"f-17.c",
  "west" : __DIR__"f-8.c",
  "east" : __DIR__"f-9.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/dragon-g.c" : 1,
]));

  setup();
}
int valid_leave(object who, string dir)
{  
        int exp,kar,cps,cor,intt,factor; 
        object ob2;  
        if (dir == "west" || dir == "east" || dir == "northwest" || dir == "southeast")  
        {        
                if (present("green dragon",environment(who)) && 
                    who->is_fighting())  //¼ì²éÂÌ¹â»ðÁúÊÇ·ñ»¹ÔÚÓëÒÆ¶¯ÕßÊÇ·ñÔÚÕ½¶·ÖÐ   
                {                   
                  if(who->query_temp("flee")==1)
                  {
                    return notify_fail(HIR"ÂÌ¹â»ðÁúÈÔÈ»µ²×¡ÁËÈ¥Â·\n"NOR);                    
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
                  if(!exp)
                    factor=0;  
                  else if(exp<80000000)
                    factor=10;
                  else if(exp<10000000)
                    factor=20;
                  else if(exp<13000000)
                    factor=30;
                  else if(exp<15000000)
                    factor=35;      
                  else
                    factor=40;           
                  if(random(180)>(factor+kar+cps+cor+intt))
                  {                                      
                    who->set_temp("flee",1);
                    if(who->query("class")=="fighter" && who->query_temp("keeup")==1)
                      call_out("remove_flee",2,who);
                    else
                      call_out("remove_flee",1,who);
                    return notify_fail(HIR"\nÂÌ¹â»ðÁú¾Þ´óµÄÉíÌåµ²×¡ÁËÍËÂ·\n"NOR); 
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
