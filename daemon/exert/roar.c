// roar.c Õð»è by Onion
//¼ÓÈë,Ö»ÒªÍæ¼Òset no_roar_player,¾Í¿ÉÒÔ±ÜµôÔÚÍ¬Ò»¸ñµÄÍæ¼Òby bss
int exert(object me,object target)
{

        object *enemy;
        int force_cost = me->query("max_force")/4+30;
        int valid,i;

        string *ATT_MESSAGE=({
        "µ«$NËÆºõÔçÓÐ×¼±¸£¬Ó²ÊÜ$nÒ»»÷È´»ÐÈ»ÎÞÊÂµÄÑù×Ó¡£",
        "µ«$NÖ»ÊÇÊÜµ½Ò»µã¾ªÏÅ±ã»Ö¸´Õý³£¡£",
        "½á¹û$NËÆºõ±»$nÏÅµÄÄ¿µÉ¿Ú´ô, Ò»Ê±ÎÞ·¨ÑÔÓï¡£",
        "$N¾õµÃÍ·»èÑÛ»¨£¬·Ö²»Çå³þ¶«ÄÏÎ÷±±¡£",
        "½á¹û$N±»$nµÄºÈÉù¾ªµÄµø×øÔÚµØÉÏ, ¿ÚÍÂ°×Ä­, ¾Ã¾ÃÎÞ·¨¶¯×÷¡£",
        "[1;31mÖ»¼ûµÃ$NË«ÊÖ““¶ú, ²Ò½ÐÒ»Éù, »èØÊÁË¹ýÈ¥¡£[0m"
        });
        if( me->query("class") != "fighter" )
          return notify_fail("Ö»ÓÐÎäÕß²ÅÄÜÊ¹³ö¡£\n");
        if( environment(me)->query("no_fight")==1 )
          return notify_fail("ÕâÀï²»×¼Õ½¶·¡£\n");
        if( force_cost > me->query("force") )
          return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");

        message_vision("\n[1;36m$N´óºÈÒ»Éù, ½«È«ÉíÄÚÁ¦¹á×¢µ¤Ìï, ºöÈ»¼äÒ»¹ÉÕð¶úÓûÁûµÄÉùÒôØèÈôÆ½µØ½¹À×°ãµÄ°ë¿Õ±¬¿ª£¡[0m\n",me);
        me->add("force",-force_cost);
        enemy = all_inventory( environment(me) );
        for( i=0; i<sizeof(enemy); i++ )
        if( enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) &&
            !enemy[i]->query_temp("roared") && !enemy[i]->query("no_kill") && enemy[i]!=me &&
            !in_edit(enemy[i]) && !in_input(enemy[i]) && !enemy[i]->query_temp("netdead") &&
  !wizardp(enemy[i]) && !enemy[i]->query("horse"))
        {
// ¼ÓÈë ¶Ô 16ËêÒÔÏÂµÄÈË roarÎÞÐ§ by anmy
        if(!(me->query("env/no_roar_player") && userp(enemy[i]))){
        if(enemy[i]->query("age")>=16)
        {
                if( me->query("max_force") > enemy[i]->query("max_force") )
                        valid=random(sizeof(ATT_MESSAGE)-1)+1;
                else
                        valid=random(sizeof(ATT_MESSAGE)-1);
                message_vision("[36m"+ATT_MESSAGE[valid]+"[0m\n",enemy[i],me);
                if( valid == sizeof(ATT_MESSAGE)-1 )
                        enemy[i]->unconcious();
                else
                {
                        enemy[i]->kill_ob(me);
                        me->kill_ob(enemy[i]);
                        enemy[i]->start_busy(valid);
                        enemy[i]->receive_damage("kee", force_cost/4);
                        COMBAT_D->report_status(enemy[i],1);
                }
                if(enemy[i])
                enemy[i]->set_temp("roared",1);
        }
        }
        }
        return 1;
}
