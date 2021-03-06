inherit ROOM;
void create() {
	set( "short", "建国千年祭广场" );
	set( "item_desc", ([
		"statue" : @ITEM
冰焰雕像居然缓缓活动了起来... 
[0;1;33m□[1mB[1m□[1mK[1m□[1mN[1m□[1m□[1m□[1mD[1m:[1m [1m□[1mu[1m□[1m□[1m□[1mA[1m□[1mo[1m□[1mo[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mN[1m□[1m□[1m□[1mO[1m□[1m□[1m□[1m□[1m□[1mZ[1m□[1m□[1m,[1m [1m□[1m][1m□[1mQ[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m,[1m [0m[0;1;33m□[1mo[1m□[1mN[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1m□[1m□[1m□[1m□[1ma[1m□[1mC[1m□[1mv[0m

[0;1;31m□[1m□[1m□[1m□[1m□[1mB[1m□[1mK[1m□[1mQ[1m□[1m□[1m□[1m□[1m□[1mA[1m□[1mT[0m

冰焰吼道:是你逼我使用 [31m穹苍无悔[0m的!!去见阎王吧!!

你避无可避，霎时被高速而来的[31m血龙卷风[0m卷成一团，被旋风拉扯的痛楚有如撕肝裂肺！
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[31m「穹苍无悔”[0m使出后，冰焰大耗内力、[36m天阙穴[0m骤然疼痛，颓然跪倒在地
[0;1;33m□[1m@[1m□[1mD[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m][1m□[1mE[1m□[1mg[1m□[1m□[1m□[1mX[1m□[1mA[1m [1m□[1m□[1m□[1m□[1m□[1mg[1m□[1mJ[1m□[1mA[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1;33m□[1mU[1m□[1mD[1m□[1mB[1m□[1mb[1m□[1m□[1m□[1mH[1m□[1mB[1m□[1mE[1m□[1mg[1m□[1m□[1m□[1mX[1m□[1mA[1m□[1mg[1m□[1mJ[1m□[1mA[1m□[1mU[1m□[1mj[1m□[1mn[1m□[1m□[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )

[0;1;31m□[1mA[1m□[1m□[1m□[1m□[1m□[1me[1m□[1m@[1m□[1m□[1m□[1mM[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m][1m□[1m□[1m□[1m□[1m□[1mD[1m□[1mF[1m.[1m.[1m.[1m.[1m [0m
 
你死了

[31m阴曹入口  [0m-
    你已经来到了阴间的入口。虽然距离地府还有一段距离，但是你已经
感受到阵阵刺骨的阴风。四周一片荒凉，但是却鬼影幢幢，看来这边的夜
总会蛮热闹的，应该不愁没伴。南边和上面好像是和人世间相通的管道，
不过好像有一股无形的力量隔开这两个不同的世界，看来要从这两个方向
回去不是那么简单的事情。

    这里明显的出口是 [0;1;37mn[1mo[1mr[1mt[1mh[0m
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10216 );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/water-ball",
		"amount5"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-ball",
		"amount3"  : 1,
		"file9"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/fire-hole/obj/p-pill",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount8"  : 25,
		"file3"    : "/open/magic-manor/obj/soil-ball",
		"file5"    : "/open/magic-manor/obj/wood-ball",
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/obj/golden-ball",
	]) );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room118.c",
		"north"     : "/open/clan/ou-cloud-club/room/room109.c",
		"enter"     : "/open/clan/ou-cloud-club/room/room155",
		"south"     : "/open/clan/ou-cloud-club/room/room121.c",
		"down"      : "/open/clan/ou-cloud-club/room/room96.c",
	]) );
	set( "long", @LONG
广场响起一阵钟声.温暖的阳光,透过茂密的松林,像格子般洒在地上,
建国千年祭典在这里热闹的举行了,在这边你可以看到各式各样别富文化
特色的展示摊位,两个小孩与一只小黄狗在你面前追逐而过,在如此和平的
时代中,许多关于世界过去的战争,灾难等仿佛已遥远的被遗忘了,但在这
广场上,却依晰能够见到那些曾经被人津津乐道歌颂着的古老神话,然而谁
知,就在广场的某一角落,隐藏着联系过去与未来世界命运的亘古谜团...,
广场正中央是个巨大石像(statue),纪念着一位曾舍身入魔,只为消弥入侵
者的千古英魂

   [0;1;33m [1m□[1ma[1;37m□[1m□[1m□[1mK[1m□[1mZ[1m□[1m□[1;33m□[1ma[0m「[0;1;31m□[1m□[1m□[1m□[1m□[1mJ[1m□[1m][0m”冰焰纪念雕像(statue) 
LONG);
	setup();
	replace_program(ROOM);
}
