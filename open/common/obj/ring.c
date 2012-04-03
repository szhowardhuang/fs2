inherit EQUIP;

void create()
{
        set_name("[1m[37m½á»é½äÖ¸[0m", ({ "wedding ring", "ring"  }) );
        set("unit", "Ö»");
        set("long", "ÏóÕ÷ÓÀºã¼á¶¨µÄ½á»é½äÖ¸£¬Ï×¸øÕâÊÜÉÏÌì×£¸£µÄÁ½ÈË¡£\n");
	set("armor_type", "finger");
	set("armor_prop/armor", 5 );
	set("material", "pearl");// Ïàµ±ÓÚ ??, ¶ÔÖØÁ¿¸ú¼ÛÖµÓĞÓÃ
	set("no_drop",1);
	set("no_sell",1);
//	set("thunder",100);//ÊÜÉÏÌì×£¸£,Ôõ¿ÉÈÃÀ×ÅüÄØ....:p
	set("no_put",1);
	set("light_up",-1);
	set_weight(1200);
	set("value",999);
	setup();
}

int query_autoload()
{
  return 1;
}
