#include <iostream>

// ��Ģ 1. ����(T)�� Ÿ���� ���̸� �Լ� ������ const, volatile, reference��
//			�����ϰ� Ÿ���� �����ȴ�.
template<typename T> void foo(T a)
{
	//a = 'a';
	//--a;
}

int main()
{
	int n = 10;
	int&r = n;
	const int c = n;
	const int& cr = c;

	foo(n);		// T : int
	foo(r);		// T : int
	foo(c);		// T : int
	foo(cr);	// T : int

	const char* s = "hello";
	foo(s);	// T : const char* ���� : ������ ������� ���ŵ�. �����͸� ���󰡸� �״�� ���

	const char* const s2 = "aaa";
	foo(s2);	// T : const char*
}