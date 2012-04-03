// whoami.c

int main()
{
	write("ÄãµÄ User ID = " + getuid(this_player()) + "\n" );
	write("ÄãµÄ Effective User ID = " + geteuid(this_player()) + "\n" );
	return 1;
}
