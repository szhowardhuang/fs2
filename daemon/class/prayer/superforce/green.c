#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
skill=this_player()->query("functions/green/level");
        if(userp(me))
        return notify_fail("Çë¸ÄÓÃ mixforce¡£\n");
if(me->query("class")!="prayer")
          return notify_fail("ÄãµÄÖ°ÒµÎŞ·¨Ê¹ÓÃ´Ë¼¼ÄÜ¡£\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("ĞşÓîÖæ±ØĞëÊ¹ÓÃ»ëÌìĞÄ·¨²ÅÄÜ·¢»ÓÍşÁ¦¡£\n");
        if( target != me ) return notify_fail("ÄãÖ»ÄÜÓÃ»ëÌìĞÄ·¨ÌáÉıÄÚÁ¦ÍşÁ¦¡£\n");
        if (me->query_skill("superforce",1) < 250)
            return notify_fail("ÄãµÄ»ëÌìĞÄ·¨µÈ¼¶²»×ã£¬ĞëÒª 250 ¼¶¡£\n");
        if (me->query("force") < 750+skill*5)
            return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬ÎŞ·¨Ê¹ÓÃĞşÓîÖæ¡£\n");
        if( (int)me->query("max_force") < 2500 )
        return notify_fail("ÄãµÄÄÚÁ¦¸ù»ù²»×ã,ÎŞ·¨¿ØÖÆĞşÓîÖæÆø¾¢¡£\n");
        if(me->query_temp("green")) return notify_fail("ÄãÒÑ¾­ÔÚÓÃÁË¡£\n");
        if(me->query_temp("purple")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[32m×ÏĞÇºÓĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("white")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[37m°×ÔÆÑÌĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("nine")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[35m¾Áµ´Ï¼ĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("gen")) return notify_fail("ÄãÒÑ¾­ÔÚÊ¹ÓÃ[35mÍÁÀ¥ÂØĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("ice")) return notify_fail("ÄãÒÑ¾­ÔÚÔË×ª[37m±ÌÑ©±ùĞÄ·¨[0mÁË¡£\n");
        if(me->query_temp("black")) return notify_fail("ÄãÒÑ¾­ÔÚÔËĞĞ[30mĞş»ìãç[0mÁË¡£\n");
        if(me->query_temp("bluesea")) return notify_fail("ÄãÒÑ¾­ÔÚ´ßÔË[34mµå²×º£[0mÄÚ¾¢ÁË¡£\n");
        if(me->query_temp("goldsun")) return notify_fail("ÄãÒÑ¾­ÔÚÇ¿ÔË[33m½ğ³¿êØ[0mÄÚ¾¢ÁË¡£\n");
        if(me->query_temp("blood")) return notify_fail("ÄãÒÑ¾­ÔÚ´ß¹Ä[31mÑªñ·²Ô[0mÄÚ¾¢ÁË¡£\n");

        me->set_temp("green",1);
        message_vision(
        HIC "$NÔËÆğ»ëÌìĞÄ·¨µÚÊ®²ã"HIG"[ĞşÓîÖæ]"HIC"£¬É²Ê±Ìì¿Õ»è°µ£¬ÍòĞÇ·±¶¯£¬È«Éí¸÷Ìõ¾­Âö¾ù³äÂúÁËĞÇ³¿Ëù¸¶ÓèµÄÆø¾¢!!\n" NOR,me);
        me->add_temp("apply/force", 100);
        me->add_temp("apply/unarmed", 100);
        me->add_temp("apply/parry", 100);
        me->add_temp("apply/stick", 100);
        me->add_temp("apply/move", -50);
        me->add_temp("apply/dodge", -50);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return ;
        me->set_temp("green",0);
        me->add_temp("apply/force", -100);
        me->add_temp("apply/parry", -100);
        me->add_temp("apply/unarmed", -100);
        me->add_temp("apply/stick", -100);
        me->add_temp("apply/move", 50);
        me->add_temp("apply/dodge", 50);
        tell_object(me,"ÄãÉíÉÏµÄ[32mĞşÓîÖæ[0mÆø¾¢»Ø¹éÌìÏó£¬Ìì¿ÕÖğ½¥»Ö¸´ÎµÀ¶¡£\n");
        if(skill<250)
        function_improved("green",random(1200));
}
