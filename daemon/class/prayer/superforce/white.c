#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
skill=this_player()->query("functions/white/level");
        if(userp(me))
        return notify_fail("Çë¸ÄÓÃ mixforce¡£\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("°×ÔÆÑÌ±ØĞëÊ¹ÓÃ»ëÌìĞÄ·¨²ÅÄÜ·¢»ÓÍşÁ¦¡£\n");
        if( target != me ) return notify_fail("ÄãÖ»ÄÜÓÃ»ëÌìĞÄ·¨ÌáÉıÄÚÁ¦ÍşÁ¦¡£\n");
        if (me->query_skill("superforce",1) < 20)
            return notify_fail("ÄãµÄ»ëÌìĞÄ·¨µÈ¼¶²»×ã£¬ĞëÒª 20 ¼¶¡£\n");
        if (me->query("force") < skill*5)
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬ÎŞ·¨ÁìÎò°×ÔÆÑÌµÄ»ëÌìÄÚ¾¢¡£\n");
        if(me->query_temp("white")) return notify_fail("ÄãÒÑ¾­ÔÚÓÃÁË¡£\n");
        if(me->query_temp("purple")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[32m×ÏĞÇºÓĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("nine")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[35m¾Áµ´Ï¼ĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("gen")) return notify_fail("ÄãÒÑ¾­ÔÚÊ¹ÓÃ[35mÍÁÀ¥ÂØĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("ice")) return notify_fail("ÄãÒÑ¾­ÔÚÔË×ª[37m±ÌÑ©±ùĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("black")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[30mĞş»ìãç[0mÁË¡£\n");
        if(me->query_temp("bluesea")) return notify_fail("ÄãÒÑ¾­ÔÚ´ßÔË[34mµå²×º£[0mÄÚ¾¢ÁË¡£\n");
        if(me->query_temp("goldsun")) return notify_fail("ÄãÒÑ¾­ÔÚÇ¿ÔË[33m½ğ³¿êØ[0mÄÚ¾¢ÁË¡£\n");
        if(me->query_temp("blood")) return notify_fail("ÄãÒÑ¾­ÔÚ´ß¹Ä[31mÑªñ·²Ô[0mÄÚ¾¢ÁË¡£\n");
        if(me->query_temp("green")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[32mĞşÓîÖæ[0mÄÚ¾¢ÁË¡£\n");

        me->set_temp("white",1);
        message_vision(
        HIC "$NÔËÆğ»ëÌìĞÄ·¨µÚÒ»²ãµÄ"HIW"°×ÔÆÑÌ"HIC"£¬ÉíÉÏÓ¿³öÈçÔÆÆø°ãµÄÄÚ¾¢ĞÎ³ÉÎŞÊıµÄÆøĞı!!\n" NOR,me);

        me->add_temp("apply/force", 1);
        me->add_temp("apply/move", 1);
        me->add_temp("apply/stick", 1);
        me->add_temp("apply/parry", 1);
        me->add_temp("apply/dodge", 1);
        me->add_temp("apply/unarmed", 1);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return ;
        me->set_temp("white",0);
        me->add_temp("apply/force", -1);
        me->add_temp("apply/move", -1);
        me->add_temp("apply/stick", -1);
        me->add_temp("apply/parry", -1);
        me->add_temp("apply/dodge", -1);
        me->add_temp("apply/unarmed", -1);
        tell_object(me,"ÄãÉíÉÏµÄ°×ÔÆÑÌÆø¾¢ÂıÂıµÄÏûÍËÖĞ,ÆøĞıÒ²ËæÖ®±ÀÉ¢¡£\n");
        if(skill<50)
        function_improved("white",random(700));
}
