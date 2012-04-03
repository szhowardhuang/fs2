inherit ROOM;
void create() {
	set( "short", "���������" );
	set( "object", ([
		"amount8"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_neck",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_cloth",
		"file5"    : "/open/firedancer/npc/eq/r_belt",
		"file7"    : "/open/firedancer/npc/eq/r_head",
		"file8"    : "/open/firedancer/npc/eq/r_leg",
		"file6"    : "/open/firedancer/npc/eq/r_pants",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_boots",
		"file1"    : "/open/firedancer/npc/eq/r_hands",
	]) );
	set( "owner", "mil" );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room85.c",
		"north"     : "/open/clan/13_luck/room/room83.c",
	]) );
	set( "build", 10156 );
	set( "long", @LONG
             ��           ��       [34m��[0m                          
                  �}         �}     [34;42m��[0m��������                     
         �����������}       �}    [34;42m��[0m��������[33m��[0m     ����������      
     [33m��--��--��--��-[0m�} ----�}---[34;42m��[0m������[33m���� �s----��--��--��----��[0m
     ��[41m  ------------[43m��[41m---��--[34;42m��[0m������[33m����[0m [33m�s[41m----------------��[37m  [0m��
     ��[41m��             [0;1;33;40m��[1m��[1m [1m��[1m��[0m��������[33m���� �s[0m [41m                  ��  [0m��
     ��[41m��          [0;1;31;40m��[1m~[0m������[0;1;31m��[1m��[0;37;41m    [33;40m�������s[37;41m                    ��  [0m��
     ��[41m��     [0;1;5;36;40m��[1;5mg[0;37m     [0m�t--�s[41m   [0;1;5;36;40m��[1;5ms[0;37m             [0;1;5;36m��[1;5m~[0;37m              ��  [0m��
     ��[41m��           [0m��    ��[41m                                 ��  [0m��  
     ��[41m���ߣߣߣߣ�__[0m��  ��[41m�ߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߩ�  [0m��
     ��������������--����������������������������������������������          
    [33m��Į��������ԭΨһ�Ĳ�ԭ�ϣ���һ����˵�еķ�ˈۣ�������˵����[0m
[33m���ɿ�����ˣ���ס��һ�������Ծ����µ�����[0;1;35m��[1mg[1m��[1ms[0;33m��~~~~~~��[0m�㲻֪Ϊ��
�ߵ����ͻȻɽ��������һ������[31mѪ����[0m���������˹���������һ��ԭ
����һ����بɽ���������������ͷ����̫���ˣ����ð˳��ж���������
������һ�����ݲ�����ѣ�[36m������ſ��һ��������ɵ���ɽ�Ҷ����[0m
[36mд�Ŷ����������--[0;1;33m��[1mg[1m��[1ms[1m��[1m~[0;36m--��������������ʾ����ʷ�ľ�Զ�����ҿ��ԭ[0m
[36m��ɫ�������ǿ����ӵ����[0m
        
LONG);
	setup();
	replace_program(ROOM);
}