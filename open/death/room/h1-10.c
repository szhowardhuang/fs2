// Room: /open/death/room/h1-10
inherit ROOM;

void create ()
{
  set ("short", "第一殿--关卡");
  set ("long", @LONG
一座高大的城门耸立在你的面前，你想通过这儿就可以到达第二殿
；你看到门前的守卫个个长得高头大马，且面目极其狰狞，要通过此处
似乎十分不易。正当你苦恼要如何通过这里时，你注意到这里的守卫似
乎和其他地方有些不同....
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"h1-9",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/guard1-10.c" : 2,
  __DIR__"action/a1-10.c" : 1,
]));
  set("no_magic", 1);

  setup();
}

        
void init() {
        add_action("do_bribe","bribe");
        }

int do_bribe(string str)
{
    if(str!="guard") 
       return notify_fail("你要把钱给谁啊!!\n");
    else {
      tell_object(this_player(),"守卫对你笑了笑说：「大爷慢走啊!”\n");
      this_player()->move(__DIR__"h2-1");  
    }
}

/*  int valid_leave(object me, string dir)
 {
        if(dir=="enter"&&present("guard",environment(me))) {
        command("kick");
        return 0;
        }
        else tell_object(this_player(),"没有守卫的带领，你似乎走不出这。\n");
        return 1;
}  */
