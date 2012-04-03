// doctor专用可以make出雪创膏...
inherit COMBINED_ITEM;
void create()
{
        seteuid(getuid());
        set_name("百年人蔘",({"seng item","item"}) );
        set("long",
        "此物乃是银针门门主远赴泰山所采来之神药,可以对于外伤有其显著功效.\n"+
        "此物须经医者炼制(make),方可发挥其药效.\n");
        set("unit", "棵");
        set("base_unit", "棵");
        set("no_sell",1);
        set("value",2500);
        set("base_weight", 50);
        set_amount(1);
        setup();
}

void init()
{
        if( this_player()==environment() )
         add_action("make_item","make");
}

int make_item(string arg)
{
     int cure;
     if( (arg=="item" || arg=="seng item") && (query("unit") == "棵") )
     {
        object user,ob;
        user = this_player();
       if(user->query("class")!="doctor")
        return notify_fail("你职业不是医者无法药株制成膏药!!\n");
       cure = user->query_skill("cure");
       cure = cure /4;
        if( cure > 10)
        {
          message_vision("$N试着将百年人参制成雪创膏.\n", user);
          ob=new("/open/common/obj/plaster1");
          ob->move(this_player());
          ob->add_amount((int)cure);
          add_amount(-1);
        }else
          message_vision("$N的医术太低,无法将人参制成雪创膏.\n", user);
        return 1;
     }
     return 0;
}
