#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit SWORD;
object ob;
void create()
{
set_name("[1;31mÁ¬ÑôÕæ½£[0m",({"sevensun_sword","sword"}) );
set_weight(9000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "°Ñ");
set("long",
"¾ÝËµ´Ë½£ÎªÐùÔ¯½£ÏÉµÄÅä½££¬Æä½£Éí³ÉÍ¸Ã÷£¬Ö»¼û½£ÉíÉÏÏâÓÐÆßÉ«±¦Öé
²¢ÓÐºìÉ«Ö®Ê¥ºÛÎÄ×Ö£¬½«´Ë½£µÄÉñÃØÐÔÓÖÔö¼ÓÁËÒ»³É¡£\n");
set("value",10);
set("material", "crimsonsteel");
set("rigidity",200);
       set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
       set("no_drop",1);
        set("no_get",1);
set("wield_msg", "$N°Î³ö$n,£¬Ë²Ê±½£ÉíÉÏµÄÆßÉ«±¦ÖéÍ»È»·¢³öÆßÉ«¹â»ª£¬Ê¹ÈË¾«ÉñÎªÖ®Ò»Õñ¡£\n");
set("unwield_msg", "$N½«ÊÖÖÐ$nÊÕ»ØÉíºó½£ÇÊ£¬¶ÙÊ±ÆßÉ«Áé¹âÏûÊ§ÎÞ×Ù¡£\n");
set("weapon_prop/sword",10);
}
init_sword(99);
setup();
}
void init()
{
     add_action("do_wield","wield");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
  {
 ::wield();
   if(query("equipped"))
{
ob=this_player();
message_vision("$NÊÖÎÕ[1;37mÏÉ½£[1;31mÁ¬Ñô[0m£¬Ö»¼ûÆßÉ«Ê¥¹â»·ÈÆÔÚ$NÉí±ß¡£\n",this_player());
       set_heart_beat(1);
     }
}
int do_unwield(string str)
{
if(query("equipped")) {
message_vision("$N½«ÏÉ½£Á¬Ñô·ÅÏÂ£¬ÆßÉ«Ê¥¹â¶ÙÊ±ÏûÊ§ÎÞ×Ù....\n",this_player());
        set_heart_beat(0);
}
}
void heart_beat()
{
  object *enemy;
object victim;
  int i,j,sword;
  sword=ob->query_skill("sword",1)/5;
if ( !objectp(ob) )
        {
        set_heart_beat(0);
        return;
        }

if( ob->is_fighting() && query("equipped") )
{
if( sword > random(100) ) {
message_vision(HIW"ÓÉÓÚÊÜµ½$NÄÚÁ¦µÄÕÙ»½£¬²ØÉíÓÚÊ¥½£ÆßÉ«±¦ÖéÖÐÖ®Æß½£½£Áé·Ö±ðÓÉ½£ÖÐ±¦Öé´Ü³ö\n²¢ÒÀ$NµÄ¾«Éñ¶ø°Ú\³öÏÉ½£½£ÕóÖ®½û¶Ï°ËØÔÓÎÁúÕóÖ»¼û\n"HIR"$NÑöÌì³¤Ð¥£¬´ß¶¯°ËØÔÓÎÁúÕóÊ¹³ö¾ªÊÀº§Ë×µÄÏÉ½£½£ÕóÖÁ¼«¾øÕÐ\n"NOR,ob);
message_vision(HIW"\n\t\t¡®"HIR"¡«½û¡«¶Ï¡«Á¬¡«Ñô¡«Æß¡«¾÷¡«Õ¶"HIW"¡¯\n\n"NOR,ob);
message_vision(HIR"´ËÕÐÒ»³ö£¬¾ªÌì¶¯µØ£¬´«Ëµ×ÔÏÉ½£´´ÅÉÒÔÀ´´ÓÎ´±»Ê¹ÓÃ¹ý!!\n"NOR,ob);
message_vision(HIB"\nÁÒÑô½£Áé¿ñÐÔÖèÆð£¬¿ÚÖÐà«à«ÓÐ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÒ»Ê½"HIW"¡®"HIB"ÁÒÑô"HIW"¡¯"HIB"!!\n"NOR ,ob);
message_vision(HIR"\n²ÐÑô½£Áé¿ñÐÔÖèÆð£¬¿ÚÖÐà«à«ÓÐ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚ¶þÊ½"HIW"¡®"HIR"²ÐÑô"HIW"¡¯"HIR"!!\n"NOR ,ob);
message_vision(HIW"\nÑÞÑô½£Áé¿ñÐÔÖèÆð£¬¿ÚÖÐà«à«ÓÐ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÈýÊ½"HIW"¡®ÑÞÑô¡¯!!\n"NOR,ob);
message_vision(HIM"\nÅ¯Ñô½£Áé¿ñÐÔÖèÆð£¬¿ÚÖÐà«à«ÓÐ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚËÄÊ½"HIW"¡®"HIM"Å¯Ñô"HIW"¡¯"HIM"!!\n"NOR ,ob);
message_vision(HIC"\n¶¬Ñô½£Áé¿ñÐÔÖèÆð£¬¿ÚÖÐà«à«ÓÐ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÎåÊ½"HIW"¡®"HIC"¶¬Ñô"HIW"¡¯"HIC"!!\n"NOR ,ob);
message_vision(HIG"\n³¯Ñô½£Áé¿ñÐÔÖèÆð£¬¿ÚÖÐà«à«ÓÐ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÁùÊ½"HIW"¡®"HIG"³¯Ñô"HIW"¡¯"HIG"!!\n"NOR ,ob);
message_vision(HIY"\nÏ¦Ñô½£Áé¿ñÐÔÖèÆð£¬¿ÚÖÐà«à«ÓÐ´Ç£¬Ê¹³öÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÚÆßÊ½"HIW"¡®"HIY"Ï¦Ñô"HIW"¡¯"HIY"!!\n"NOR ,ob);
message_vision(HIW"\nÆßµÀ½£ºçÍ¬Ê±¼¤¿Õ¶ø³ö£¬¡¸ÆßÑôÁ¬Ìì¡±ÔÚ¿ÕÖÐÖ¯³ÉÒ»µÀºçÍø£¡\n"HIG"¶øÖ÷ÕóµÄ$N×ÝÉíÒ»Ô¾£¬ÄýÆø×¼±¸·¢³ö×îºóÒ»Ê½ÒÔÍê³ÉÕâ¾ªÌìµØ¶¯µÄÒ»»÷£¡\n"NOR,ob);
message_vision(HIW"\nÖ»¼û$N¿ñÐÔÖèÆð ,´óºÈÒ»Éù¡®"HIR"½£Ó°Á¬Ñô£¬ÆßÑôÁ¬Ìì¡¯!!\n"NOR,ob);
message_vision(HIW"$NµÄÆßÑôÁ¬ÌìÆøÊÆÅìíç£¬¼¤·¢ÁËÏÈÇ°ÏÉ½£½û¶ÏÖ®Á¬ÑôÆß¾÷µÄÆß¹É¸ÕÈá²¢¼ÃµÄ½£ºç\nÖ»¼ûºçÆøÐ¥Ìì£¬ÂúÌì½£Ó°£¬ÕóÄÚµÐÈË½ÔÊÜÖØ´´\n"NOR,ob);

enemy=ob->query_enemy();
i=sizeof(enemy);
for(j=0;j<i;j++){
 enemy[j]->receive_damage("kee",500);
 enemy[j]->start_busy(2);

COMBAT_D->report_status(enemy[j],0);
}
}
}
return;
}
