#include </open/open.h>
#include <ansi.h>
inherit ROOM;
inherit F_MORE;
string look_shelf();
void add_book();
mapping *books;
void create ()
{
  set ("short", "书房");
  set ("long", @LONG
    这里是书房，房间四周的书架(shelf)上放满了各式各样的书。
架子上的书，有些是记载魔教的历史，有些是魔教武学的书，有些是
闲情逸致，调野性情的书。假若您是冥蛊教徒，您可以申请书籍。架
上则放了一本供魔教徒查阅用毒及制毒的古老书籍，墙上则贴了一张
申请办法(note)。
LONG);
 
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room12.c",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "note" : "架上有使毒之书(use_poison book)及制毒之书(make_poison book)\n"
           "请在此研读(read)。\n"
           "欲取架上书籍者，请向小童报备(report 书名)。\n",
   "shelf" : (: look_shelf :),
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/boy_b" : 1,
]));
  set("light_up", 1);
 
  setup();
  add_book();
}
 
void init()
{
        add_action("do_report", "report");
        add_action("do_take", "take");
        add_action("do_read", "read");
        add_action("do_put", "put");
}
int do_read(string book)
{
  object me = this_player();
  if(me->query("class") != "poisoner")
        return notify_fail("此地禁止非魔教徒在此研读。\n");
  if(book == "make_poison book") {
        me->start_more(read_file("/open/poison/obj/make_p_book"));
        return 1;
       }
  else if(book == "use_poison book") {
        me->start_more(read_file("/open/poison/obj/use_p_book"));
        return 1;
       }
  return 0;
}
int do_put(string arg)
{
  object book, me = this_player();
  mapping nnew;
   if(!arg) return 0;
  if (sscanf (arg, "%s onto shelf", arg) != 1)
     return 0;
   if( !objectp(book = present(arg,me)) || !mapp( book->query("skill") ))
	{
	 	tell_object(me,"你身上并没有这种可读之书。\n");
		return 1;
	}
  if( sizeof(books) > 20)
     return notify_fail("架子已经都放满书籍了。\n");
  nnew = allocate_mapping(3);
  nnew["name"] = book->query("name");
  nnew["id"] = book->query("id");
  nnew["file_name"] = base_name(book);
  if( !pointerp(books) || !sizeof(books) )
        books = ({ nnew});
  else
        books += ({ nnew });
  message_vision(HIC "$N把"+book->name()+"放到架子上。\n" NOR, me );
  destruct(book);
  return 1;
}
string look_shelf()
{
        object who = this_player();
        int i;
        if(!sizeof(books))
                return "这个架子上空空如也，没有任何书籍。\n" ;
        else  {
                   write("架子上放有：\n\n");
                for(i=0 ; i< sizeof(books) ; i++ )
                   printf("%20s(%s)\n",books[i]["name"],books[i]["id"]);
                   return "";
              }
}
 
int do_report(string book)
{
        object who = this_player();
        string id;
        int i, index, j=0;
 
        if( !present("boy", this_object()))
              return notify_fail("根本就没人你还报告啥啊？直接拿(take)啦！\n");
 
        if( who->query("family/family_name")!="冥蛊魔教" )
                return notify_fail("小书童说道：你不是魔教徒的人，少来烦我。\n");
 
        if(!books)
                return notify_fail("小书童说道：你要申请哪一种书？\n");
 
        if(sscanf(book, "%s %d", id, index) != 2) {
              id = book;
              index = 1;
             }
 
        for(i=0; i<sizeof(books); i++) {
              if(books[i]["id"] == id) j++;
              if(j == index) break;
             }
 
        if(!j)
              return notify_fail("小书童说道：报歉，书架上并没有你要的书。\n");
        else {
              message_vision("小书童拿起一本"+books[i]["name"]+"交给$N。\n", who);
              new(books[i]["file_name"])->move(who);
              books = books[0..i-1] + books[i+1..sizeof(books)-1];
             }
        return 1;
}
 
int do_take(string book)
{
        object who = this_player();
        string id;
        int i, index, j=0;
 
        if( present("boy",this_object()) )
                return notify_fail("小书童对你怒喝道：你要干什么！看不懂墙上的布告啊？\n");
 
        if(!book)
              return notify_fail("你到底要拿些什么东西? \n");
 
        if(sscanf(book, "%s %d", id, index) != 2) {
              id = book;
              index = 1;
             }
 
        for(i=0; i<sizeof(books); i++) {
              if(books[i]["id"] == id) j++;
              if(j == index) break;
             }
 
        if(!j)
              return notify_fail("你看清楚一点，有这种东西吗?\n");
        else {
              message_vision("$N从架上拿起"+books[i]["name"]+"。\n", who);
              new(books[i]["file_name"])->move(who);
              books = books[0..i-1] + books[i+1..sizeof(books)-1];
             }
        return 1;
}
void add_book()
{
   mapping nnew;
   int i,j;
  nnew =allocate_mapping(3);
   nnew["id"] = "poison book";
   nnew["name"] = "基本毒经";
   nnew["file_name"] = "/open/poison/obj/pbasebook.c";
 
   if( !pointerp(books) || !sizeof(books) ) {
       books = ({ nnew });
       return ;
      }
 
   for(i=0; i<sizeof(books); i++)
      if(books[i]["name"] == nnew["name"]) {
               j = 1;
               break;
             }
   if(!j) books += ({ nnew });
   return ;
}
 
void reset()
{
 :: reset();
 add_book();
}
