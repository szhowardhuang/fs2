
inherit ROOM;

int do_climb(string str);
string show_ring();

void create()
{
    set("short", "йВ╠зио");
    set("long", @LONG
дЦуЩ╧ртзйВ╠зж╝жпё╛мЫоб©╢х╔╥╒ождЦюК╣ьцФспр╩╤н╬ЮюКакё╛мЫио
©╢х╔ё╛дг©Им╩фП╣дйВ╦ир╡╡╩йг╨эт╤акё╛тздЦиМ╠ъ╤╓вер╩╦ЖлЗ╩╥(ring)║ё

LONG
        );
    set("item_desc", ([
    "ring" : (: show_ring :)
    ]) );
     set("outdoors",1);

        setup();
}

void init()
{
    reset();
    add_action("re_route_cmd","",1);
    add_action("do_climb", "climb");
}

int re_route_cmd(string str)
{
    string cmd;
    int i;
    string *invalid_cmds;
    cmd = query_verb();
    invalid_cmds = ({"enforce", "meditate", "practice", "study", "wield", 
"exercise", "learn", "scribe", "conjure", "enchant", "exert", "perform", 
"respirate","drop"});
    i = member_array(cmd, invalid_cmds);
    if (i == -1) return 0;
    else write("[1;37mртдЦд©г╟╣д╢╕╬Ёю╢©╢ё╛р╙вЖуБ╪Чйб╨эдя║ё[0m\n");
    return 1;
}

int do_climb(string str)
{
    int chance;
    if (this_player()->query_temp("looked_ring")) chance = 10;
    else chance = random(10);
    if (!str) return notify_fail("[1;32mмЫдгею? еюдгюО?!?йгр╙мЫио╩╧обею??[0m\n");
    if ((str != "up") && (str != "down"))
        return notify_fail("[1;32mЮе.... уБюОц╩спуБяЫ╤╚нВхцдЦею.[0m\n");
    write("[1;37mдЦиНиН╣ьнЭакр╩©зфЬё╛©╢в╪╥╫н╩ё╛бЩбЩ╣д©╙й╪ею...[0m\n");
    if ((str == "up" ) && (chance >= 8)) {
        this_player()->move(__DIR__"make7");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"фЬ╢╜пЙпЙ╣ьеюакиою╢.\n",
        this_player());
    return 1;
    }
    else {
        if ((str == "down" ) && (chance >= 8)) {
        this_player()->move(__DIR__"make5");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"╨эп║пд╣ь╢сиоцФеюобю╢.\n",
        this_player());
        return 1;
        }
        else {
            write("[1;37mр╩╡╩п║пдц╩в╔╨ц.... ╣Такобх╔... к╓╣цдЦм╥╩Хяш╩╗.[0m\n");
            this_player()->receive_damage("kee", 50);
            this_player()->move(__DIR__"make5");
            tell_room(environment(this_player()),
            "дЦлЩ╣╫р╩иЫ╡р╫п, "+(string)this_player()->name()+"╢сиоцФк╓ак"+
            "обю╢.\n",
            this_player());
        }
    }
    return 1;
}

string show_ring()
{
    this_player()->set_temp("looked_ring",1);
    return "р╩╦ЖиЗпБ╣длЗ╩╥ё╛т╪спйжуф╟Ц╢Сё╛иоцФ╩╧спр╩╫ь╤о╣Т╣диЧвсё╛╡╩ж╙йгдг╦Ж╣╧\n"+
    "ц╧╧МаТобю╢╣д. дЦйтакйтлЗ╩╥... ╬Ж╤╗╩╧йгц╟╦Жоу╟и. п║пд╣Ц╬мйгак.\n";
}



