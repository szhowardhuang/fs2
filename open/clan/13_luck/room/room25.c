inherit ROOM;
void create() {
	set( "short", "ÆëÌìµî" );
	set( "owner", "mad" );
	set( "object", ([
		"file10"   : "/daemon/class/fighter/armband",
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount9"  : 5,
		"file9"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/daemon/class/fighter/armband",
		"amount2"  : 2,
		"amount10" : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/fire-hole/obj/k-pill",
		"file6"    : "/open/wu/npc/obj/armband",
		"amount5"  : 5,
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount1"  : 6,
		"amount6"  : 1,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 2,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 6,
		"file3"    : "/open/fire-hole/obj/y-pill",
	]) );
	set( "build", 10552 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room24",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

                 ¨Š¨p¨T¨p¨T¨p¨T¨p¨T¨p¨T¨p¨T¨p¨T¨p¨T¨p¨‡
            ¨¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¨Ž
         ¨Š¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨T¨‡
          ¨‰¨€ÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌï¨€¨‰
             ¨€|ÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌïÌï|¨€
              ¨€©¦¡¬¡¬ ¡¬¡¬ ¡¬¡¬ ¡¬¡¬ ¡¬¡¬ ¡¬¡¬ ¡¬¡¬©¦¨€
             _¨€©¦¨U¨U ¨U¨U ¨U¨U ¨U¨U ¨U¨U ¨U¨U ¨U¨U©¦¨€_
              ¨€©¦¨U¨U ¨¨ ¨U¨U ¨¨ ¨U¨U ¨¨ ¨U¨U©¦¨€
   ¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰
LONG);
	setup();
	replace_program(ROOM);
}
