#include <ansi.h>
inherit NPC;
string do_game();
void create()
{
        seteuid(getuid());
        set_name("Ğ¡Å®º¢",({"little girl","girl"}));
        set("long",@LONG
Ò»¸öĞ¡Å®º¢£¬¶À×ÔÒ»¸öÈËÔÚÍæÓÎÏ·£¬¿´ÆğÀ´ºÃ¹Â¶À£¬ºÃ¿ÉÁ¯à¸!!
LONG);
        set("gender","Å®ĞÔ");
        set("combat_exp", 1000);
        set("attitude","friendly");
        set("age",12);
        set("force",5000);
        set("max_force",5000);
        set("kee",1000);
        set("max_kee",1000);
        set("force_factor",30);
        set("inquiry", ([
        "ÍæÓÎÏ·" : (: do_game :),
        ]));
        set("chat_chance", 5);
        set("chat_msg", ({
        "Ğ¡Å®º¢µÀ: °¦!Ò»¸öÈËÍæÓÎÏ·ÕæÎŞÁÄ£¬¶¼Ã»ÓĞÈË¿ÉÒÔÅãÎÒÍæ¡£\n",
        }));
        setup();
}
void init()
{
  object ob;
    add_action("do_answer","answer");
  if(interactive(ob =this_player())) {
  call_out("greeting",1,ob);
  }
}
void greeting(object me)
{
if(!me) return;
if(me->query("get-evil-mblade") && me->query("title")=="[1;32mÑı[1;37mµ¶[1;32m´«[1;37mÈË[0m") return;
if(me->query("mk-blade")) {
if(me->query("gender")=="ÄĞĞÔ" && me->query("title")!="[1;37mäöÓğ[1;33mµ¶»Ê[0m")
{
me->set("title",HIW"äöÓğ"HIY"µ¶»Ê"NOR);
message_vision(HIW"\n°×¹âÉ¢È¥$NµÄ³ÆºÅĞŞÕıÍê±Ï¡£\n"NOR,me); 
}
else if(me->query("gender")=="Å®ĞÔ" && me->query("title")!="[1;34mµ¶»ê[1;36mÓÄ¼§[0m")
{
me->set("title",HIB"µ¶»ê"HIC"ÓÄ¼§"NOR);
message_vision(HIW"\n°×¹âÉ¢È¥$NµÄ³ÆºÅĞŞÕıÍê±Ï¡£\n"NOR,me);
}
}
}
int set_number()
{
    int i,s,j,flag,num,sub,temp,k;

    num=0;
    for(i=0;i<4;i++){
      s=random(10);
      sub=1;
      for(j=0;j<i;j++)
        sub*=10;
      if(i){
        flag=0;
        temp=sub;
        k=num;
        do{
          temp/=10;
          if((k/temp)==s)
            flag=1;
          else
            k=k%temp;
        }while(temp>1);
        if(flag){
         i--;
         continue;
        }
      }
      num+=s*sub;
    }
    return num;
}
string do_game()
{
    object ppl=this_player();
    int num;
    string number;

    if(ppl->query_temp("number_quest"))
      return "ÄãÕıÔÚ¸úÎÒÍæ°¢!!!\n";

    number="";
    num=set_number();
    if(num<1000)
      number+="0";
    number+=sprintf("%d",num);
    ppl->set_temp("number_quest/number",number);
    tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:ÄãÒª¸úÎÒÍæÓÎÏ·Âğ£¬ÕæÊÇÌ«ºÃÁË!!!\n");
    tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:ÄÇÎÒÃÇÏÖÔÚÀ´Íæ²ÂÊı×ÖÓÎÏ·¡£\n");
    tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:ÎÒ»á´Ó"HIY"£°¡«£¹"NOR"Ñ¡ËÄ¸ö²»ÖØ¸²µÄÊı×ÖÈÃÄã²Â?\n");
    tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:Èç¹ûÄã²ÂµÄÊı×ÖÖĞÓĞÒ»¸öÎ»ÖÃÊÇÕıÈ·µÄ£¬ÎÒ»áËµ["HIR"Ò»Ñô"NOR"]¡£\n");
    tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:Èç¹ûÓĞÒ»¸öÄã²ÂµÄÊı×Ö¶Ô£¬µ«ÊÇÎ»ÖÃ²»ÕıÈ·£¬ÎÒ»áËµ["HIC"Ò»Òõ"NOR"]¡£\n");
    tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:ÕâÑù·´¸²ÈÃÄã²Â£¬Èç¹ûÊÇ["HIR"ËÄÑô"NOR"]£¬ÍêÈ«²ÂÖĞÁË£¬ÎÒ»áËÍÄãÒ»¸öĞ¡ÀñÎï¡£\n");
    tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:ÄãÏë²»Ïë¸úÎÒÍæÄØ"HIG"(answer yes/no)"NOR"?\n");
    return "";
}
int do_answer(string arg)
{
    object ppl=this_player();
    int num,i,a,b,s,sub,temp,k,j,time;
    string ans,txt;
    string out="";

    if(!arg) return 0;
    if(!ppl->query_temp("number_quest")) return 0;
    if(!ppl->query_temp("number_quest/time")){
      if(arg=="yes"){
        tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:ÄãÒª¸úÎÒÍæ?!Ì«ºÃÁË¡£\n");
        tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:ÎÒÒÑ¾­ÏëºÃÊı×ÖÁË£¬Äã¿ªÊ¼²Â°É(answer Êı×Ö)¡£\n");
        ppl->add_temp("number_quest/time",1);
        return 1;
      }
      else if(arg=="no"){
        tell_object(ppl,"Ğ¡Å®º¢ËµµÀ:Ô­À´Äã²»ÏëÍæ......ÎÒ¶®ÁË¡£\n");
        ppl->delete_temp("number_quest");
        command("cry");
        return 1;
      }
      else return 0;
    }
    else{
      tell_object(ppl,HIG"ÄãËµ:ÎÒ²Â"+arg+"¡£\n"NOR);
      ppl->add_temp("number_quest/time",1);
      if(sizeof(arg)!=4){
        tell_object(ppl,"ÄãÒª»Ø´ğµÄÊÇËÄÎ»Êı×ÖÀ²!!\n");
        return 1;
      }
      for(i=0;i<4;i++){
        txt=arg[i..i];
        sscanf(txt,"%d",num);
        if(num< 0 || num > 9){
          tell_object(ppl,"ÄãÒª»Ø´ğµÄÊÇËÄÎ»Êı×ÖÀ²!!\n");
          return 1;
        }
      }
      for(i=0;i<3;i++)
        for(j=i+1;j<4;j++)
          if(arg[i]==arg[j]){
            tell_object(ppl,"ÊÇÒª²ÂËÄ¸ö²»ÖØ¸²µÄÊı×Öà¸!!\n");
            return 1;
          }
      ans=ppl->query_temp("number_quest/number");
      a=0;
      for(i=0;i<4;i++)
        if(ans[i]==arg[i]) a++;
      b=0;
      for(i=0;i<4;i++)
        for(j=0;j<4;j++)
          if(i==j) continue;
          else if(ans[i]==arg[j]) b++;
      if(!a && !b) out="¶¼Ã»²Âµ½";
      else{
       if(a) out+=HIR+CHINESE_D->chinese_number(a)+"Ñô"+NOR;
       if(b) out+=HIC+CHINESE_D->chinese_number(b)+"Òõ"+NOR;
      }
      tell_object(ppl,"["+out+"]¡£\n");
      if(a==4){
        command("say "+ppl->query("name")+"ºÃÀ÷º¦à¸£¬²Âµ½ÁË¡£");
        command("say ¸Õ¸Õ°ïÄãËãÁËÒ»ÏÂ£¬Äã×Ü¹²²ÂÁË"+
          CHINESE_D->chinese_number(ppl->query_temp("number_quest/time")-1)+"´Î¡£");
        time=ppl->query_temp("number_quest/time")-1;
        if(time<=7){
          command("say ¿´ÔÚÄãÄÇÃ´À÷º¦µÄ·İÉÏ£¬ÈÃÄã¿ÉÒÔÊ¹ÓÃ»½ÔÆÉÈµÄfanset¹¦ÄÜ!!");
          ppl->set_temp("can_fanset",1);
        }
        else{
          command("say ¸øÄã½±Æ·£¬kiss Ò»¸ö¡£");
          command("lkiss "+ppl->query("id"));
        }
        command("smile");
        ppl->delete_temp("number_quest");
      }
      return 1;
    }
    return 0;
}
