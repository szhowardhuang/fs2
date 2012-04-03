inherit BANK;

void create ()
{
  set ("short", "钱庄");
  set ("long", @LONG
这是一个由木板组贴成的小屋子，你走进里面，可以看到一个人
，正隔着木窗与你对望，其中，你也可以看到一些人正在这里提领着
金钱。
    右边墙角贴着一张说明书(sign)。
LONG);

set("item_desc",([
  "sign" : "这里是钱庄，目前我们提供的服务有：

balance         查钱庄有多少存款
withdraw        领取存在钱庄的钱
deposit         把钱存进钱庄
convert         兑换钱币。
lend            向钱庄借钱
relend          还钱给钱庄


balance
withdraw <数量> <种类>
deposit <数量> <种类> || deposit all
convert <数量> <货币> to <货币>

lend <数量> coin
relend <数量> coin


范例:       convert 10 silver to coin

钱币种类有  1 gold == 100 silver == 10000 coin

",
]));
	set("evil_area",1);
	set("no_transmit",1);
	set("exits", ([ /* sizeof() == 1 */
"east" : __DIR__"a-04",
]));
	set("light_up", 1);
setup();
}
