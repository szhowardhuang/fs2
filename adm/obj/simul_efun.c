//#pragma optimize all

#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/color.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/wizard.c"
#include "/adm/simul_efun/system.c"

// This must be after gender.c
#include "/adm/simul_efun/message.c"

void create()
{
	seteuid(getuid());
	write("simul_efun loaded successfully.\n");
}

string ob_path(mixed ob)
{
	string file;
	string *dir;
	int	i;

	if (objectp(ob))
	  file = base_name(ob);
	else if (stringp(ob)) file = ob;
	else return "/";
	dir = explode(file, "/");
	file = "/";
	for (i=0; i<sizeof(dir)-1; i++)
	  file += dir[i]+"/";
	return file;
}
