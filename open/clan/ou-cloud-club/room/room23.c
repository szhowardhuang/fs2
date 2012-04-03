inherit ROOM;
void create() {
	set( "short", "ÎÔÁú¾Ó" );
	set( "object", ([
		"file10"   : "/open/killer/obj/kill_yar_head",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/prayer/obj/boris-boots",
		"file5"    : "/open/killer/weapon/k_head3",
		"file1"    : "/open/killer/weapon/k_torch",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file2"    : "/open/gsword/obj/no_tax",
		"amount5"  : 1,
		"file7"    : "/open/killer/obj/kill_yar_head",
		"amount2"  : 1,
		"file8"    : "/open/killer/obj/kill_yar_head",
		"file4"    : "/open/dancer/obj/yuawaist",
	]) );
	set( "build", 10405 );
	set( "light_up", 1 );
	set( "owner", "dico" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room181",
	]) );
	set( "long", @LONG
ÕâÀï¾ÍÊÇ¡¸[57mÁ½¹ã×Ü¶½[0m¡±µÏ¿ËµÄÎÔ·¿ÁË£¬
·ÅÑÛÍûÈ¥ËÆºõÃ»ÓĞÌ«¶àµÄ¶«Î÷ÔÚÕâÀï£¬¿ÉÄÜ
ÊÇÒòÎªµÏ¿Ë¸Õ°áÀ´µÄ¹ØÏµ°É¡£µ«ÊÇ£¬Äã»¹ÊÇ
¿ÉÒÔÔÚÇ½ÉÏ¿´µ½µÏ¿ËµÄÕ½ÀûÆ·£¬ÏñÊÇãñÉ½ÅÉ
ÕÆÃÅµÄ[53m¿ñÁúÏèÌìÆÆ[0m£¬ÉßÕ¯Õ¯Ö÷µÄ[52mÇàÉßÍ·¿ø[0m¸ú
[52mÉßĞÍÏîÁ¶[0m£¬¡¸[56mĞ¡¶«Ğ°[0m¡±¹ùÏåÊÖÉÏµÄĞÒÔË²İ»·
£¬»¹ÓĞÉñ½çÀïµÄ[53mÉñÁú½ğ»·[0m£¬ÕâĞ©¶¼ÊÇµÏ¿ËµÄ
Õ½ÀûÆ·à¸£¡£¡
LONG);
	setup();
	replace_program(ROOM);
}
