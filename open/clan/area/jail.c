#include <ansi.h>
inherit ROOM;
int leave(object me);
void create()
{
  set("short", HIY"ÊÀ½çµÄ½ÇÂä"NOR);
  set("long", @LONG
    Õâ±ßÊÇÊÀ½çµÄ½ÇÂä£¬Õâ±ßÓĞĞí¶àµÄÀËÈËÔÚ´ËÁ÷ÀË×Å£¬Á÷ÀËÔÚ´Ë
µÄÈË£¬»úºõÊÇÎŞ¶ñ²»×÷µÄ´ó»µµ°£¬±»³¯Í¢·ÅÖğµ½´ËµÄ×ïÈË£¬Í¨³£Èç
¹ûÉĞÎ´¹ØÂúĞÌÆÚµÄ»°£¬ÊÇ²»»áÊÍ·ÅµÄ¡£
        [1;31m´ò "check"¿ÉÒÔ¼ì²é¿´¿´ÊÇ·ñÄÜ»Øµ½ÖĞÔ­¡£[0m
LONG
       );
set("light",1);
  set("no_fanset", 1);
  set("valid_startroom", 1);
  set("have_reborn", 1);
  set("no_chome", 1);
  set("light_up", 1);
  set("no_fight", 1);
  set("pkgame", 1);
  set("no_clean_up", 1);
  set("no_sac", 1);


   setup();
}
void init(){

        add_action("block_cmd","");
}
int block_cmd(string arg)
{
if((string)query_verb() == "check") return leave(this_player());
// ÒÔÏÂÊÇ¿ÉÒÔÏÂµÄÖ¸Áî
if((string)query_verb() == "look") return 0;
if((string)query_verb() == "ans")  return 0;
if((string)query_verb() == "say")  return 0;
if((string)query_verb() == "tell")  return 0;
if((string)query_verb() == "quit")  return 0;
if((string)query_verb() == "home")  return 0;

write("½ĞÄã²»ÒªËæ±ãÂÒ¶¯,»¹ÂÒ¶¯....\n");
return 1;
}
int leave(object me)
{
        int outtime;
        string msg="";
        if(me->query("mud_age")>me->query("jail_time"))
        {
        write(HIY"ÇëºÃºÃÖØĞÂ×÷ÈË£¬±ğÔÙ·¸ÁË¡£\n"NOR);
        me->delete("jail_time");
        me->move("/open/common/room/inn.c",1);
        }
        else 
        {
        outtime=me->query("jail_time")-me->query("mud_age");
        if ( outtime/3600 ){
                  msg=msg+HIR+outtime/3600+"Ğ¡Ê±"+NOR;
                  outtime=outtime%3600;
        }
        if ( outtime/60 ){
                  msg=msg+HIW+outtime/60+"·ÖÖÓ"+NOR;
        }
        if ( outtime%60 ){
                  msg=msg+HIW+outtime%60+"Ãë"+NOR;
        }
        write("Äã»¹ÓĞ"+msg+"ĞÌÆÚ²ÅÂú¡£\n");
        }
return 1;
}
