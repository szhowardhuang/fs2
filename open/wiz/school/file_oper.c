'����, ��������ص�����.........������ help wiz_cmds ��õ�
'pwd, ls, cd, cp, rm, more, cat, tail, ..... 
'���ǵļ������� help file_oper ��
'�����г�����λ����
'=====================================================================
'  pwd   :       �鿴����������Ŀ¼
'  ls    :       �鿴����Ŀ¼�����е���, �����������Ǻ�
'		 �Ĵ����Ѿ���ϵͳ���뵽����������
'  cat   :       һ����ʾ��������������
'  more  :       һ��һҳ��ʾ��������
'  tail  :       ��ʾ����� (Լ��ʮ��) �ĵ�������
'  cd    :       ���Ŀ¼, ������һ������ʱ, ��ῴ����
'		 һ�л��и÷����Ŀ¼, ������� cat here
'		 ����÷�������ôд��, Ҳ���� cd  ����
'		 Ŀ¼ȥ, ͨ����������ص� npc, eqs ����
'		 ���ڸ�������, Ҫ�ص��Լ��ĸ�Ŀ¼�Ļ�,
'		 cd �Ϳ��Ի�ȥ�Լ��ĸ�Ŀ¼
'  cp    :       ��������, ���Ҳ�Ǻ���Ҫ��, �����ڴ��ر�
'		 ���Ѹ�λ, ���������б�Ҫ����, ��Ҫ�����
'		 ����, Ҳ��Ҫ�ѱ𴦵� mob  ����Լ���Ŀ¼,
'		 ��Ϊ����Ҫռ���౶�Ĵŵ��ռ�, ��Ȼ, ����
'                ���޳��� ftp  ץ���Լ��ĵ����о���ʽ��.
'		 ftp ����һ������, ��һ���ݺ�����.
'  rm    :       ɾ������, �� cp ��ȻҲҪ��ɾ��, �԰�?!
'		 �ڴ�Ҫ���Ѹ�λ, �Լ���Ŀ¼����һ����, 
'		 log,  ����������������õ�, ��λ������
'		 ����������, ����, ɾ��֮ǰ���Ҳȷ��һ
'		 ���Ƿ���Ĳ�������
'  mv    :       �ᶯ���� (���� cp ���µ� + rm ���ɵ�  һ��),
'		 ����ĵ���, �ڴ�Ҫ���Ѹ�λ, �ʵ��ĵ������Լ��ļ�
'		 ���а���. ������Ҳ����������Ŀ¼����
'  mkdir :       ����һ������Ŀ¼, �ѵ������չ��ܷ���ŵ�
'		 �ʵ�����Ŀ¼Ӧ������Ҫ����, ͨ������ room,
'		 obj, npc, item, weapon ����Ŀ¼, ����һ��
'		 ��֪���Ǹ����.
'  rmdir :       ɾ�����е���Ŀ¼, �� rm ��һ��, rm  ��ɾ��
'  edit  :       �༭����, �ݺ�����
'  grep	 :	 ������ �ؼ��� ���ֵĵ���, ������Ҫ��ĳ�ؼ�
'		 �ֵ��׳����� ��һ����ʱ, �������Ǻ����õ�
' =========================================================
���Ͽ��Էֳɼ���, һ��һ�㵵������, ��ߵ�ϵͳҪ�ο� unix ������
  ��λ������ unix ���鿴��, �� mv, ls, cp, rm, mkdir, pwd �ȵ�
  �ڴ˲������˷Ѵ���, ���ǲ�˵����ʾ����Ҫ, �෴��, ����Ϊ����
  ����Ҫ��, ����ϣ����λ���鿴, �����Ƚ���ϸ��ȷ.

  ����, ���� edit...ͨ��, edit �������������������Ҫ��, 
  ��������� edit �� line editor, ���� unix �� ed ����
  ��Ҫ��һ��Ҫ��Ϥ��, ���������� ftp �Ļ�, 
  ������������� ftp, �ǲ��� edit �ͺ�����, ��˵, edit ��ʵ����
  ��ǿ, ����Ҫ��Ϥȴ��Ҫ����Ŭ��....
  ����, Ҫ����� edit, ���� edit <file>, �� edit test.c �ȵ�
  ���, Ҫ֪�� edit �ֳ�����ģʽ, һ���� ����ģʽ, �ֳ�Ϊ ð��ģʽ
  Ҳ������������ʱ���и� ð�� ����ͷ����ʾ��Ԫ, Ҫȡ����������,
  ������ð��ģʽ�°� h �ٰ� enter, ���κ�����, ��֪���÷�, ��
  ��ð��ģʽ�°� h<����>, �� hp <-- ע��, û�пո�

  ������, ��γ� edit, ������ x, ������ q �ȵ�, 
  ����, Ҫ֪�� edit ������һ��ģʽ, ������ģʽ,
  ������ help edit_file, ������ help edit

  һ����˵, edit ��Ҫ�������� p/q/a/i/d ����
  ���Լ�����һ��

==========================================================================
help ftp
==========================================================================
  ftp ��Ҫ�ӹ���վ����ʹ�õ�����, �����ڹ���վ��ʹ��
  һ����һ���û�и�Ŀ¼����ʦ���������з��� ftp, ֻ��ץ, ���ܷ�
  ftp 140.122.77.123 4321
  name: anonymous
  password: ��Ĺ���վ�ʺ�, ���������Ļ�, ��������ֹ�Ӹû��� ftp

  ���Լ��ĸ�Ŀ¼����ʦ���������з��� ftp,
  ftp 140.122.77.123 4321
  name: �����ʦ����
  password: �����ʦ������
  ����:
    ftp 140.122.77.123 4321
    name: wade
    password: gotodiebah

  ϣ��ѧ���� edit ���˿������� ftp
  ������� ftp ���˾ͺú�ѧѧ edit �����..

  ftp ����:
    get                 <-- ץ��һ����, ����: get workroom.c
    put                 <-- ��һ������ MUD,  ����: put my_npc.c
    mget                <-- һ��ץȡ�����, ������� prompt off
    mput                <-- һ���Ͷ����, ������� prompt off
    promot off/on       <-- prompt off �ڶ൵��ȡʱ����Ҫ���Ӧ yes/no
                        <-- prompt on  �ڶ൵��ȡʱ��Ҫ���Ӧ yes/no
    binary              <-- ��λԪ��ʽ, ����ѹ�������������ָ�ʽ