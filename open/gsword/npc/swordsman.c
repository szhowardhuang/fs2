inherit NPC;

void create()
{
	set_name("ÊØµî½£Ê¿", ({"swordsman"}));
	set("long","ÏÉ½£ÅÉÊØµî½£Ê¿,Õý¹§¹§¾´¾´µÄÕ¾ÔÚÁ½ÅÔ.\n");
	set("gender","ÄÐÐÔ");
	set("combat_exp",12775);
        set("attitude","heroism");
	set("age",31);
	set("class","swordsman");
	set("score",1000);
	set("force",300);
	set("max_force",300);
	set("force_factor",4);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",50);
	set_skill("dodge",50);
	set_skill("parry",50);
	setup();
	carry_object("/obj/longsword.c")->wield();
}
 int accept_fight(object me)
  {
  if((int)me->query("combat_exp")<=2000)
  {
   command("say È¥ÍâÃæ´ò¶¯ÎïÀ²!");
   return 0;
  }
  command("say ÁÁ½£°É!");
  return 1;
  }
         
      
