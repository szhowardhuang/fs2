inherit ITEM;

void create()
{
        set_name( "古文书",({"papyrus"}));
        set_weight(400);
        if( clonep() )
          set_default_object(__FILE__);
        else {
          set("unit", "本");
          set("long","
尘封的书皮，泛黄的纸页，一眼便可想见其年代之久远。
古文书上写着：
ΩΘ○⊙☆■◇....●★▽ΓΞζη￡....ψ◆....
你看了半天，却连一个字也看不懂....。
非得找个人翻译不行 。\n");
}
        setup();
}
