#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
skill=this_player()->query("functions/gen/level");
        if(userp(me))
        return notify_fail("Çë¸ÄÓÃ mixforce¡£\n");
if(me->query("class")!="prayer")
          return notify_fail("ÄãµÄÖ°ÒµÎŞ·¨Ê¹ÓÃ´Ë¼¼ÄÜ¡£\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("ÍÁÀ¥ÂØ±ØĞëÊ¹ÓÃ»ëÌìĞÄ·¨²ÅÄÜ·¢»ÓÍşÁ¦¡£\n");
        if( target != me ) return notify_fail("ÄãÖ»ÄÜÓÃ»ëÌìĞÄ·¨ÌáÉıÄÚÁ¦ÍşÁ¦¡£\n");
        if (me->query_skill("superforce",1) < 40)
            return notify_fail("ÄãµÄ»ëÌìĞÄ·¨µÈ¼¶²»×ã£¬ĞëÒª 40 ¼¶¡£\n");
        if (me->query("force") < skill*5)
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬ÎŞ·¨ÁìÎòÍÁÀ¥ÂØµÄ»ëÌìÄÚ¾¢¡£\n");
        if( (int)me->query("max_force") < 400 )
        return notify_fail("ÄãµÄÄÚÁ¦¸ù»ù²»×ã,ÎŞ·¨ÍêÈ«·¢»Ó³öÍÁÀ¥ÂØĞÛ»ëµÄÄÚ¾¢¡£\n");

        if(me->query_temp("gen")) return notify_fail("ÄãÒÑ¾­ÔÚÓÃÁË¡£\n");
        if(me->query_temp("purple")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[32m×ÏĞÇºÓĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("white")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[37m°×ÔÆÑÌĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("nine")) return notify_fail("ÄãÒÑ¾­ÔÚÊ¹ÓÃ[35mÃµµ´Ï¼ĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("ice")) return notify_fail("ÄãÒÑ¾­ÔÚÔË×ª[37m±ÌÑ©±ùĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("black")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[30mĞş»ìãç[0mÁË¡£\n");
        if(me->query_temp("bluesea")) return notify_fail("ÄãÒÑ¾­ÔÚ´ßÔË[34mµå²×º£[0mÄÚ¾¢ÁË¡£\n");
        if(me->query_temp("goldsun")) return notify_fail("ÄãÒÑ¾­ÔÚÇ¿ÔË[33m½ğ³¿êØ[0mÄÚ¾¢ÁË¡£\n");
        if(me->query_temp("blood")) return notify_fail("ÄãÒÑ¾­ÔÚ´ß¹Ä[31mÑªñ·²Ô[0mÄÚ¾¢ÁË¡£\n");
        if(me->query_temp("green")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[32mĞşÓîÖæ[0mÄÚ¾¢ÁË¡£\n");

        me->set_temp("gen",1);
        message_vision(
        HIC "$NÔËÆğ»ëÌìĞÄ·¨µÚÈı²ãµÄ"YEL"ÍÁÀ¥ÂØ"HIC"£¬ÉíÉÏ·¢³öÈç´óµØ°ãµÄÆÈÁ¦,ĞÎ³ÉÎŞÊıµÄÆøÁ÷!!\n" NOR,me);

        me->add_temp("apply/force", 4);
        me->add_temp("apply/move", 4);
        me->add_temp("apply/stick", 4);
        me->add_temp("apply/parry", 4);
        me->add_temp("apply/dodge", 4);
        me->add_temp("apply/unarmed", 4);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->set_temp("gen",0);
        me->add_temp("apply/force", -4);
        me->add_temp("apply/move", -4);
        me->add_temp("apply/stick", -4);
        me->add_temp("apply/parry", -4);
        me->add_temp("apply/dodge", -4);
        me->add_temp("apply/unarmed", -4);
        tell_object(me,"ÄãÉíÉÏµÄÍÁÀ¥ÂØÆø¾¢ÂıÂıµÄÏûÍËÖĞ,Ñ¹Á¦Ò²ËæÖ®ÏûÉ¢¡£\n");
        if(skill < 50)
        function_improved("gen",random(700));
}
