// 1_�ζ����Լ�.cpp
// cl [���ϸ�] /FAs	/FAs �ɼ��� ����� �ҽ��� ������ �ɼ�. /Ob1 ����ȭ �ɼ�

// ���� : ������.
// ���� : �����ڵ尡 Ŀ����.
//		��, 1~2���� ���� �Լ��� ���� �ڵ带 ���̱⵵ �Ѵ�.

int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);
	int n2 = Add2(1, 2);
	return 0;
}