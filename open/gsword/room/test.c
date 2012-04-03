#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "œ…Ω£≈…¥Û√≈");
        set("long", @LONG
 [44m                                                          [0m 
  [7m                                                          [44m   [0m
  [7m       ®X®a   ®U         ®X®[       ®U       ®X®a®X       [44m   [0m
  [7m     ®X®a     ®U       ®X®a®^®[     ®U   ®[  ®a®X®a       [44m   [0m
  [7m   ®X®a®U     ®U     ®X®a®T®T®^®[®U ®U   ®^               [44m   [0m
  [7m       ®U     ®U       ©§®Z ©§®Z ®U ®U   ®[ ®U ®U         [44m   [0m
  [7m       ®U     ®U      ®U ®U®U ®U    ®U   ®^ ®U ®U ®[ °Ò   [44m   [0m
  [7m       ®U ®U  ®U  ®U  ®]©§ ®]©§     ®U      ®U ®U ®^®[    [44m   [0m
  [7m       ®U ®^®T®m®T®a  ®X ®[®X ®[    ®U   ®X ®U ®U   ®^®[  [44m   [0m
  [7m                                    ®a   ®a ®a ®a         [0m®ä
  ®ä   ®ä                                              ®ä   ®ä
  ®ä   ®ä                                              ®ä   ®ä
  ®ä   ®ä                                              ®ä   ®ä
  ®ä   ®ä                                              ®ä   ®ä
  ®ä   ®ä                                              ®ä   ®ä
  ®ä   ®ä                                              ®ä   ®ä 
  ®ä   ®ä                                              ®ä   ®ä    
  ®ä   ®ä                                              ®ä   ®ä     
LONG
        );

        set("exits", ([
	    "enter":__DIR__"g1-1",
               "down":__DIR__"road8",
        ]) );
      set("light_up",1);
setup();

}
