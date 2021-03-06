// stabber.c

inherit SKILL;

mapping *actions = ({
	([  "action"     :	"$N将$w往前一送，直刺$n$l",
	    "damage_type":	"刺伤",
	]),
	([  "action"     :	"$N挥舞$w，对准$n$l刺去",
	    "damage_type":	"刺伤",
	]),
	([  "action"     :	"$N高举手中$w，往$n$l挥了过去",
	    "damage_type":	"斲伤",
	]),
	([  "action"     :	"$N将$w一挥，往$n$l用力刺落",
	    "damage_type":	"刺伤",
	]),
	([  "action"     :	"$N寻着空隙，手中$w对准$n$l挥了过去",
	    "damage_type":	"割伤",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}

