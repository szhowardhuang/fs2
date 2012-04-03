//Code by Hitler  1995.10.2
//More added by Fex ..

inherit ROOM;

object ob;
string *name=({"hitler","devils","norman","fary","datas","nsk","moi","boss","lys","stupid","oda"});
int number=11;

void create ()
{
  set ("short", "[1;32mÎäÕßÎ×Ê¦ÌÖÂÛÊÒ[0m");
  set ("long", @LONG
ÕâÀïÊÇÎäÕßÖÆ×÷Î×Ê¦µÄÌÖÂÛÊÒ, ÓĞÀäÆø¡¢±ùÏä, »¹ÓĞÉ³·¢µÈºÀ»ª¼Ò¾ß,
ÉĞÓĞ³ä×ãµÄ¹âÏß¼°ÓÅÑÅµÄ°ì¹«×À, Ìá¹©Î×Ê¦ÃÇ×îÊæÊÊµÄ»·¾³! ²¢ÇÒÉèÖÃÁË
Î×Ê¦×¨ÓÃµÄ²¼¸æÀ¸, ÈÃÎ×Ê¦ÃÇÄÜ½«ÎÊÌâÁôÑÔÓÚÉÏ, ¹²Í¬ÌÖÂÛ¡£
°ì¹«×ÀÉÏÓĞÒ»Ö§Âó¿Ë·ç(mac),ºÇ...¸ÕÂòµÄ..:>>
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "mac" : "ÕâÊÇÒ»Ö§¿É°®µÄÂó¿Ë·ç, Äã¿ÉÒÔÍ¸¹ıËüÀ´ÏòÄ¿Ç°
ÏßÉÏµÄÎä¹İÎ×Ê¦´«Ñ¶Ï¢..
ÓÃ·¨: mac ÄãÒªËµµÄ»° ...
",
]));

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/wu/room/school1",
  "down" : "/open/wiz/hall1",
]));

  set("no_fight", 1);

  set("no_magic", 1);

  set("no_clean_up", 0);

  set("valid_startroom", 1);


  setup();
        call_other("/obj/board/fexboard","???");
}

void init()
{
add_action("mac","mac");
}

int mac(string str)
{
int i,flag=0;

if(!str)
  {
   notify_fail("Äã×ÜÒªËµĞ©»°°¡!!, ²»È»ÆäËûwiz ÔõÃ´ÄÜÌıµÃµ½ÄØ?\n");
   flag=0;
   return 0;
  }
for(i=0;i<number;i++)
  {
    if(ob=find_player(name[i]))
    if(ob!=this_player())
    {
    tell_object(ob,"[1;37m[ÎäÕßÖÆ×÷][1;33m "+this_player()->query("id")+"[1;37m Ëµ: [0m"+str+"\n");
    flag++;
    }
  }
  if(flag!=0)
  {
  write("[36mÄã¸æËßÈ«²¿µÄÎäÕßÎ×Ê¦£º"+str+"[0m\n");
  }
  else
  {
  write("Ä¿Ç°Ã»ÓĞÆäËûÎäÕßÎ×Ê¦ÔÚÏßÉÏ, ËùÒÔÃ»ÈËÌıµ½ÄãËµµÄ»°¡£\n");
  }
  say(this_player()->query("name")+"("+this_player()->query("id")+")"+" ¶Ô×ÅÂó¿Ë·çß´ß´¹¾¹¾µØËµÁËĞ©»°..\n");
  flag=0;
  return 1;
}
