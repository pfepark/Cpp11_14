// 1_�ζ����Լ�2.cpp

// 1. �ζ��� �Լ��� ������ �ð� �����̴�.
// 2. �ζ��� �Լ��� �Լ������Ϳ� ��Ƽ� ȣ���ϸ� �ζ��� ġȯ�� �� ����. 
//		(�Լ������ͷ� ����Ű�� ���� ���氡���ϹǷ� ������ Ÿ�ӿ� �� �� ����)

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);		// ȣ��
	int n2 = Add2(1, 2);		// ġȯ

	int(*f)(int, int);

	f = &Add2;
	int n3 = f(1, 2);	// ȣ��? ġȯ?

	return 0;
}