#include <ansi.h>
string line1(string);
string line2(string);
string line3(string);
string line4(string);
string paper(string arg)
{
        int j,i;
        string str="";
        
        for(j=0;j<strlen(arg);j++)
        {
        str += line1(arg[j..j]);
        }
        str += "\n";
        for(j=0;j<strlen(arg);j++)
        {
        str += line2(arg[j..j]);
        }
        str += "\n";
        for(j=0;j<strlen(arg);j++)
        {
        str += line3(arg[j..j]);
        }
        str += "\n";
        for(j=0;j<strlen(arg);j++)
        {
        str += line4(arg[j..j]);
        }
return  HIC + str+"\n"NOR;
}
string line1(string arg)
{
int i;
i=atoi(arg);
        switch(i){
        case 1:
        return "  ©°©´  ";
        break;
        case 2:
        return "¨q©¤©¤¨r";
        break;
        case 3:
        return "¨q©¤©¤¨r";
        break;
        case 4:
        return "©°©´©´  ";
        break;
        case 5:
        return "©°©¤©¤©´";
        break;
        case 6:
        return "¨q©¤©¤¨r";
        break;
        case 7:
        return "©°©¤©¤¨r";
        break;
        case 8:
        return "¨q©¤©¤¨r";
        break;
        case 9:
        return "¨q©¤©¤¨r";
        break;
        case 0:
        return "¨q©¤©¤¨r";
        break;
        }
}
string line2(string arg)
{
int i;
i=atoi(arg);
        switch(i){
        case 1:
        return "©°¨s©¦  ";
        break;
        case 2:
        return "¨t©¤¨r©¦";
        break;
        case 3:
        return "¨t©¤¨r©¦";
        break;
        case 4:
        return "©¦©¦©¦  ";
        break;
        case 5:
        return "©¦©°©¤©¼";
        break;
        case 6:
        return "©¦¨q©¤¨s";
        break;
        case 7:
        return "©¸©¤¨r©¦";
        break;
        case 8:
        return "©¦¨q¨r©¦";
        break;
        case 9:
        return "©¦¨q¨r©¦";
        break;
        case 0:
        return "©¦¨q¨r©¦";
        break;
        }
}
string line3(string arg)
{
int i;
i=atoi(arg);
        switch(i){
        case 1:
        return "  ©¦©¦  ";
        break;
        case 2:
        return "¨q¨q©¤¨s";
        break;
        case 3:
        return "¨t©¤¨r¨r";
        break;
        case 4:
        return "©¦©¦©¦  ";
        break;
        case 5:
        return "¨t©¤¨r¨r";
        break;
        case 6:
        return "©¦¨q¨r©¦";
        break;
        case 7:
        return "   £¯£¯ ";
        break;
        case 8:
        return "¨q¨q¨r¨r";
        break;
        case 9:
        return "¨t©¤¨r©¦";
        break;
        case 0:
        return "©¦©¦©¦©¦";
        break;
        }
}

string line4(string arg)
{
int i;
i=atoi(arg);
        switch(i){
        case 1:
        return "©¸©¤©¤©¼";
        break;
        case 2:
        return "¨t©¤©¤¨s";
        break;
        case 3:
        return "¨t©¤©¤¨s";
        break;
        case 4:
        return "©¸©´©°©¼";
        break;
        case 5:
        return "¨t©¤©¤¨s";
        break;
        case 6:
        return "¨t©¤©¤¨s";
        break;
        case 7:
        return "  ©¸©¼  ";
        break;
        case 8:
        return "¨t©¤©¤¨s";
        break;
        case 9:
        return "¨t©¤©¤¨s";
        break;
        case 0:
        return "¨t©¤©¤¨s";
        break;
        }
}
