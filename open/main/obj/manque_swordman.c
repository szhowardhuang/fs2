// 有关于 npc 的种种设定, 请到 /doc/build/npc 去参考
//	manque_swordman.c		designed by dos  95'12
inherit NPC;


void create()
{
	set_name("失意剑客", ({ "manque swordman", "swordman"}) );
	set("long", "你看到一位失意剑客, 脸上透漏出悲哀
的神情. 你或许可以问问他, 看看是否有
故事(story)可以听. \n");

	// 年龄
	// 由于系统将会依年龄而计算出, 该怪物之天赋及基本状态,
	// 故请务必设定怪物的年龄。
	set("age", 30);

	// 天赋, 请参考 help gift
	// set( "属性", 数值 );		<-- 数值范围: 10 - 30
	// 如果没有设定, 将由年龄计算
	set("str",22);
	set("cor", 18);
	set("per", 27);

	// 状态
	// 一般没有特殊技能的怪物, 其战斗经验(combat_exp)几乎决定了怪物的强度。
	// set( "combat_exp", 数值 );
	// set( "score", 数值 );
	set("combat_exp", 3000);

	// 种族
	// 种族会影响攻击方式, 请参考 /doc/build/npc 的第八项
	// 如果未指定种族, 系统将会自动选定人类。
	// 目前已知的有: 人类, 赛亚人, 妖魔, 野兽 
	set("race", "人类");

	// 性别
	// 依种族之不同, 有两种系统: 1.男性, 女性。
	//                           2.雄性, 雌性, 中性。
	// 设定方式: set( "gender", "性别" );
	set( "gender", "男性");

	// 设定 npc 攻击方式及受功击部位。
	// set( "limbs", ({ "受功部位1", "受功部位2", ...}) );
	set("limbs", ({ "头部", "身体", "手部", "脚跟", "喉咙" }) );
	// set( "verbs", ({ "攻击方式1", "攻击方式2", ...}) );
//	set("verbs", ({"bite", "claw" }) );

	// 暗语
	// 我们可以在怪物上设定某些暗语, 使得当玩家询问(ask)特定之
	// 关键字时, 怪物能自动做我们预设之动作。
	// 设定方式: set( "inquiry", ([
        //	          "暗语1" : "回应之语\n",
        //	          "暗语2" : (: this_object(), "呼叫副程式之名" :)
        //	        ]) );
	set("inquiry", ([
		"story"	:	"唉, 过去的事就不要再提了! \n",

		"故事" :	"我现在没有心情说故事... \n",
	]) );

        // attitude npc 的战斗行为请参考 /doc/help/attitude
	set("attitude", "heroism");

        set("chat_chance", 6);
        set("chat_msg", ({
        }) );


        setup();
	carry_object("/open/main/obj/manque_shield.c")->wear();
	carry_object("/open/main/obj/manque_sword.c")->wield();
//	carry_object("/open/main/obj/sword_cloth.c")->wear();
}
