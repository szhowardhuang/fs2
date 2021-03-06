// liquid.c

#include <dbase.h>
#include <name.h>

varargs string long(int raw)
{
	int amount, max;
	string str;

	if( amount = query("liquid_remaining") ) {
		str = query("long");
		max = query("liquid_maximum");
		if( amount == max )
			str += "里面装满了" + query("liquid_name") + "\n";
		else if( amount > max/2 )
			str += "里面装了七、八分满的" + query("liquid_name") + "\n";
		else if( amount >= max/3 )
			str += "里面装了五、六分满的" + query("liquid_name") + "\n";
		else if( amount > max/4 )
			str += "里面装了少许的" + query("liquid_name") + "\n";
		return str;
	}
	else return query("long");
}
