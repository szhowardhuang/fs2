// apprentice.c
// Modify By Oda 96/6/5 将叛师对于技能之影响改写到 /feature/apprentice.c 中
//                      避免在玩家拜 NPC 为师时有无法扣到的情形

#include <ansi.h>
#define LEAST_RELATIONSHIP 100

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_app;
        mapping family;
        mapping guild=([]),master=([]);

        seteuid(getuid());

        guild=GUILD_D->query_translate();
        if( !arg ) return notify_fail("指令格式：apprentice [cancel]|<对象>\n");
        arg = lower_case(arg);

        if( arg=="cancel" ) {
                old_app = me->query_temp("pending/apprentice");
                if( !objectp(old_app) )
                        return notify_fail("你现在并没有拜任何人为师的意思。\n");
                write("你改变主意不想拜" + old_app->name() + "为师了。\n");
                tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
                me->delete_temp("pending/apprentice");
                return 1;
        }

        if( !(ob = present(arg, environment(me))) )
                return notify_fail("你想拜谁为师？\n");

        if( ob==me ) return notify_fail("拜自己为师？好主意....不过没有用。\n");
  if(me->query("horse")==1)
return notify_fail("马不能拜师。\n");
if((me->query("family/family_name")=="魔刀门" || me->query("family/family_name")=="魔刀莫测") && ob->query("family/family_name")=="金刀门")
return notify_fail("你是魔刀人不能拜金刀为师！\n");

        if( me->is_apprentice_of(ob) ) {
                message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！”\n", me, ob);
                return 1;
        }

        if( userp(ob) ) {
        if( me->query("人际关系/"+ob->query("id")) < LEAST_RELATIONSHIP )
                return notify_fail("你跟"+ob->name()+"的关系不够好，你不能拜他为师。\n");
        //加入圣火的弟子不能拜玩家
        if(ob->query("class")=="prayer")
                return notify_fail("你是圣火教的弟子不能私下收授弟子\n");
        }

        if( !mapp( ob->query("family") ) )
                return notify_fail(ob->name() + "既不属于任何门派，也没有开山立派，不能拜师。\n");

        //增加可以限制某些人不能再收弟子
        if( ob->query("no_recruit")==1 )
                return notify_fail(ob->name()+"所属的门派不准私下收授弟子。\n");

        if( me->query("class") != ob->query("class")
        || !me->query("class") || !ob->query("class") )
                return notify_fail("你的职业和他不同，他不愿意收你。\n");

        // If the target is willing to recruit us already, we do it.
        if( (object)ob->query_temp("pending/recruit") == me ) {

                if( !living(ob) ) {
                        message_vision(
                                "$N决定拜$n为师？\n\n"
                                "$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！”\n\n"
                                "但是看样子$n并不知道有人跟他磕头。\n",
                                me, ob);
                        return 1;
                }

                if( me->query("family") ) {
                        message_vision(
                                "$N决定背叛师门，改投入$n门下！！\n\n" 
                                "$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！”\n\n",
                                me, ob);
                   me->set("secondapp",1);
                } else
                        message_vision(
                                "$N决定拜$n为师。\n\n"
                                "$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！”\n\n",
                                me, ob);

                ob->recruit_apprentice(me);
                ob->delete_temp("pending/recruit");

                tell_object(ob, "恭喜你新收了一名弟子！\n");
                family = me->query("family");
                printf("恭喜您成为%s的第%s代弟子。\n", me->query("family/family_name"), chinese_number( me->query("family/generation")));

                return 1;
        
        } else {

                old_app = me->query_temp("pending/apprentice");
                if( ob==old_app )
                        return notify_fail("你想拜" + ob->name() + "为师，但是对方还没有答应。\n");
                else if( objectp(old_app) ) {
                        write("你改变主意不想拜" + old_app->name() + "为师了。\n");
                        tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
                }

                message_vision("$N想要拜$n为师。\n", me, ob);
                me->set_temp("pending/apprentice", ob );
                if( userp(ob) ) {
                        tell_object(ob, YEL "如果你愿意收" + me->name() + "为弟子，用 recruit 指令。\n" NOR);
                } else
                        ob->attempt_apprentice(me);
        
                return 1;
        }
}


int help(object me)
{
        write(@HELP
指令格式 : apprentice [cancel]|<对象>
指令说明 :
           这个指令能让你拜某人为师，如果对方也答应要收你为徒的
         话，就会立即行拜师之礼，否则要等到对方用 recruit  指令
         收你为弟子才能正式拜师。
           如果对你的师父使用这个指令，会变成向师父请安。
特别注意 :
           请注意你已经有了师父，又背叛师门投入别人门下，所有技
         能会减半，并且评价会降到零。
 
请参考相关指令 expell、recruit
HELP
        );
        return 1;
}
