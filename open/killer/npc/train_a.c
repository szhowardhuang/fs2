#include </open/open.h>
inherit NPC;
void create()
{
    set_name("末位生",({"trainee"}) );
    set("title", "黑牙联成员");
    set("gender", "男性");
    set("age",21);
    set("attitude", "killer");
    set("long", "他是用来给杀手练习的NPC \n");
    set("max_force",200);
    set("force",200);
    set("max_kee",1200);
    set("kee",1200);
    set("combat_exp",25000);
    setup();
}