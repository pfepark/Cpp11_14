// ������ �ν��Ͻ�ȭ lazy instantiation

/*
class A
{
	int data;
public:
	void foo(int a)
	{
		*a = 10;	// error
	}
};
*/

// ������� ���� �Լ� ���ø��� ���� C++ �ڵ�� �������� �ʴ´�.
template<typename T>
class A
{
	T data;
public:
	void foo(T a)
	{
		*T = 10;	// error
	}
};

int main()
{
	A<int> a;		// why? template�� classƲ. foo�� ȣ���� ���� �����Ƿ� ���� ������ �ʾҴ�.
					// �ɹ����� data�� ���������. �޸� ũ�⸦ �˾ƾ��ϹǷ�..

	a.foo(0);		// ��������Ƿ� template���� ���� Ŭ������ ���鶧
					// foo�� ���Եȴ�.
}