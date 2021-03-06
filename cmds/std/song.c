// /cmds/std/song.c
//
// wade 在当兵前写来自娱娱人的, 7/6/1996
// 
// 另一个重要的档在 /obj/example/song.c
// 对写歌的时候做了修正, 超过 100 首之后会自动把最不常唱的歌曲拿掉
// by wade 10/27/1996

#include <ansi.h>
 
int help (object);

int main(object me, string str)
{
  string        name, arg, *songs;
  object        song;

  if (!str) return help (me);

  if (sscanf (str, "%s %s", arg, name) != 2) arg = str;

  if (!arg) return help (me);

  if (catch (song = load_object ("/obj/example/song.c")))
    return notify_fail ("对不起, 点唱金榜坏了.\n");

  if (arg == "-e") {            // 编辑歌曲
    if (song->query_exist (name, me)) {
      write ("你要写的歌曲别人已经写了啊.\n");
      return 1;
    }
    me->set_temp ("song/歌名", name);
    write ("原唱者: ");
    input_to ("set_songer", me);
  }
  else if (arg == "-d") {       // 清除歌曲
    song->delete_song (name, me);
    write ("删除好了.\n");
    return 1;
  }
  else if (arg == "-c") {       // 点歌
    if (song->play (name, me))
      write ("开始演唱了.\n");
    else
      write ("没有这首歌, 请选别首.\n");
    return 1;
  }
  else if (arg == "-l") {       // 列出所有歌曲
    if (!name) {        // -l 没加歌名参数
      if (songs = song->query_top (3, 0))
        me->start_more (sprintf ("你要的歌曲是: %O\n", songs));
      else
        write ("对不起喔! 没查到符合的.\n");
    }
    else {              // -l 有加歌名参数, 只列出该歌名
      if (song->query_songs (name))
        me->start_more (sprintf ("%O\n", song->query_songs (name)));
      else
        write ("没有你要的这首曲子耶.\n");
      return 1;
    }
  }
  else if (arg == "-t") {       // 金曲龙虎榜
    if (songs = song->query_top (1, name))
      me->start_more (sprintf ("前十名的金排歌曲是: %O\n", songs));
    else
      write ("对不起喔! 现在没有排行金曲奖.\n");
  }
  else if (arg == "-n") {       // 照歌名字数排
    if (songs = song->query_top (2, name))
      me->start_more (sprintf ("你要的歌曲是: %O\n", songs));
    else
      write ("对不起喔! 没查到符合的.\n");
  }
  else if (arg == "-a") {       // 照原唱者字数排
    if (songs = song->query_top (3, name))
      me->start_more (sprintf ("你要的歌曲是: %O\n", songs));
    else
      write ("对不起喔! 没查到符合的.\n");
  }
  else if (arg == "-s" && name) {       // 照歌名字数排
    if (songs = song->query_top (4, name))
      me->start_more (sprintf ("你要的歌曲是: %O\n", songs));
    else
      write ("对不起喔! 没查到符合的.\n");
  }
  else return help (me);

  return 1;
}
 
// me 把歌曲 str 加入歌曲列表中. 要进入 edit() 中编写
// 总歌曲数为 100, 超过的话, 会把使用次数低的踢掉.
void set_songer (string str, object me)
{
  if (!str) {
    me->delete_temp ("song");
    return;
  }
  me->set_temp ("song/原唱者", str);
  write ("底下开始输入歌词, 每句歌词中间预设是停留两秒, \n"
         "要更改停留时间, 请在两句歌词之间写数字.\n");

  me->edit ( (: call_other,__FILE__, "set_song", me :) );
}

// 输入完毕. 做适当的设定.
void set_song (object me, string str)
{
  string songer, name;
  object song;

  if (catch (song = load_object ("/obj/example/song.c"))) {
    me->delete_temp ("song");
    return;
  }

  if (song->song_number() >= 100)
    song->adjust();
  songer = me->query_temp ("song/原唱者");
  name   = me->query_temp ("song/歌名");
  song->add_song (name, me, songer, str);

  write ("你的歌曲 -- "+name+" 已经录制好了.\n");
}

int help(object me)
{
  write(@HELP
命令语法: song -e 歌名          <-- 编辑一首曲子, 并且存档
          song -d 歌名          <-- 只能砍掉自己写的曲子
          song -c 歌名          <-- 点歌
          song -l [歌名]        <-- 列出目前的歌曲清单, 不加歌名则 == song -a
          song -t [N]           <-- 列出前Ｎ名的排行榜, 预设是前十名
          song -a [原唱者]      <-- 列出属于该原唱者的歌, 不加的话照原唱者排
          song -s 字            <-- 搜寻含有该字的所有歌曲清单.
注意事项:
          song -n 4     <-- 只列出歌名长度是四个英文字或两个中文字的
          song -n 4+    <-- 只列出歌名长度比四个英文字或两个中文字长的
          song -n 4-    <-- 只列出歌名长度比四个英文字或两个中文字短的
          song -n 4-10  <-- 只列出歌名长度在 4 到 10 个英文字之间的.
          使用 song -l 可以不加参数, 或者你要查询详细资料也可以.
          为了免去别人的打扰, 可以 set wait_edit
          使用 song -e 在写歌曲的时候, 每句歌词之前应该有 delay 项目
          delay 单位是秒, 不过, delay 可以省略, 省略的话, 系统预设是 3 秒
        底下列举一个例子:
        2
        哥哥爸爸真伟大
        ....
        3
        只要我长大!
HELP
    );
    return 1;
}
