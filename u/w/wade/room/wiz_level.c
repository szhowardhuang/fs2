inherit ROOM;

void create ()
{
  set ("short", "��ʦ������");
  set("long", @LONG
Խ�ߵȼ�����ʦ����������Խ��, Ҳӵ�нϴ��Ȩ��, ������Ȩ������
��֮��, ���ײ����ʦ֮���ǻ���ƽ�ȵ�, ��Ϊ, ���Ǽٶ����˵��˶�ֻ��
������Ȥ, ��˿�����������������������. ����˵˵��ʦ�ĵȼ�,
  immortal	�˼�ֻҪ���뼴��, ����ְ������ѧϰ����ʦ, �����Ǵ�
		���ļ���ʼ, ��ߵ��ļ���ָ /doc �µĵ�.
  apprentice	����ְ��Ҳ����ѧϰ����ʦ, ���ǿ�ʼѧϰ��������, Ҫ
		���� apprentice ����Ҫ�и߼���ʦ�����ϰ�, �����ҵ�
		�ϰ忪ʼ, �����Ǩ��ѧϰҲ�����ϰ帺��.
  wizard	����ÿ��������������ʦ, Ӧ����������Ĵ���ʦ��
		ָ����׫д����, ����, ���������. Ҫ�����ɱ��ȼ���
		��ʦ, һ��Ҫ���������.
  arch		���ǹ��� MUD  ����Ҫ�Ĳ㼶, ���Ǹ��������׫д��ά
		��, �����������, ����Ĵ���ʦӵ�����Ȩ��, ������
		����ƽ����, ����Ĵ���ʦ�ľ���ȨӦ�ñȴ��񼶵���
		ʦ����. Ҫ���ɱ��ȼ���ʦ, ����Ҫ����������, ��һ��
		�����Ե���, ��Ȼ, Ӧ��Ҫ���� wizard.
  admin		�׳ƵĴ���, �������������ƽ��, ��ϵͳ�ķ���.
  guest		���ǿʹ���æ��, �����������ط��Ѿ��Ǵ�������, ��
		�˴����ǻ��ڽ���, ���, û��ʲô��������.
  manager	ϵͳ������, Ȩ���� admin  ��ȫ��ͬ, ����ӵ�б�վ��
		���ʺ�����, �����ڵ���ʱ����ϵͳ.
LONG);

  set("exits", ([
	"back"	: __DIR__"wiz",
  ]) );

  set("light_up",1);
  setup();
}