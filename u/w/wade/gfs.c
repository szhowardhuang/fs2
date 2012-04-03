// Room: /u/w/wade/grapic_room.c
inherit ROOM;

string record, record_file;

void create ()
{
  set ("short", "[1;32mÍ¼ÐÎ»¯MUDÌÖÂÛÊÒ[0m");
  set ("long", @LONG
ÕâÊÇÒ»¼äÓÃÀ´ÈÃ·¢Õ¹Í¼ÐÎMUDµÄÐ¡×éÓÃÀ´ÌÖÂÛ¡¢ÑÐ¾¿¡¢½»»»ÐÄµÃµÄ·¿¼ä
    ÔÚÕâÀï¿ÉÒÔÓÃ record À´Â¼Òô£¬Ä¿Ç°Ö»Â¼Òô "say" ÃüÁî¡£
    ¡¸record¡±¿É¿´Â¼Òô×´¿ö£¬¡¸record stop¡±¿ÉÍ£Ö¹Â¼Òô£¬
    ¡¸record µµÃû¡± ¿É½«ÔÚ±¾·¿¼äËùÓÐÓÃ¡¸say¡±µÄÑ¶Ï¢Â¼ÏÂÀ´¡£

[1;32mÐ¡×éÕÙ¼¯ÈË¼°Ö÷µ¼:Wade[0m
[1;32mServer×é:Wade¡¢Chan¡¢Fir[0m
[1;32mClient×é:Lum¡¢[0m
Ï£ÍûÄÜÒ»²½Ò»²½µÄÑÐ·¢¡¢ÔçÈÕ½«FSÍê³ÉÍ¼ÐÎ»¯¡£
LONG);

  set("exits", ([ /* sizeof() == 7 */
  "lum" : "/u/l/lum/workroom.c",
  "anmy" : "/u/a/anmy/workroom.c",
  "fir" : "/u/f/fir/workroom.c",
  "wade" : __DIR__"workroom.c",
  "chan" : "/u/c/chan/workroom.c",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);

  record = "Í£Ö¹Â¼Òô¡£";
  record_file = "";

  setup();
  call_other("/obj/board/gfs_b.c","???");
}

void init ()
{
  add_action ("record", "record");
  add_action ("do_say", "say");
}

int record (string arg)
{
  int write_ok;

  if (!wizardp (this_player()))
    return notify_fail (">> Î×Ê¦²Å¿ÉÂ¼Òô£¡£¡\n");
  if (!arg) {
    write (">> ÒªÂ¼ÒôµÄ»°£¬ÇëÔÙÃüÁîºóÃæ¼Ó¡¸µµÃû¡±µ±²ÎÊý¡£\n");
    write (">> ÏÖÔÚÂ¼Òô×´¿öÊÇ£º"+ record + "\n");
  }
  else if (arg == "stop")
    record = "Í£Ö¹Â¼Òô¡£";
  else {
    arg = resolve_path(this_player()->query("cwd"), arg);
    write_ok = write_file (arg,
	this_player()->query("id")+ " Æô¶¯Â¼ÒôÓÚ£º"+
	(string)ctime (time()) + "\n", 1);
    if (!write_ok)
      return notify_fail (">> Â¼ÒôÊ§°Ü£¡£¡\n");
    else {
      record_file = arg;
      record = "Â¼ÒôÖÐ¡­";
    }
  }
  return 1;
}

int do_say (string arg)
{
  if (record == "Â¼ÒôÖÐ¡­")
    write_file (record_file, this_player()->query("id")+"ËµµÀ£º"+arg+"\n", 0);
  return 0;
}
