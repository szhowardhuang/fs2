#define WADE_HOME "/u/w/wade/workroom"

inherit ROOM;

void create ()
{
  set ("short", "LPC 讲座 -- 整数");
  set ("long", @LONG
整数是最常常用到的资料型态, 你可以见到像 i++; 这是把变数 i 加一的意思,
另外, i += 10; 跟 i = i + 10; 是一样的意思, 此外, i = j = 0; 则是把两个叙
述合并, 即 i = 0; j = 0; 这两个跟 i = j = 0; 是一样的.
    记住, 几乎所有的机器, 整数运算总是最快的, 所以底下的叙述:
        if (value > hp * 0.5) .....   可以改写如下, 速度会比较快
        if (value * 2 > hp) .......   因为用的是整数的运算
LONG);

  set("exits", ([
        "back"  :       __DIR__"lpc",
  ]) );

  set("light",1);
  setup();
}
