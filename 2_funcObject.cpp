// 2_�Լ���ü.cpp
#include <iostream>
using namespace std;

// �Լ� ��ü : ()�� �������ؼ� �Լ� ó�� ��밡���� ��ü
struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p;
	int n = p(1, 2);	// p.operator()(1,2)�� �����Դϴ�.
	cout << n << endl;

	// a + b;	// a.operator+(b)
	// a - b;	// a.operator-(b)
	// a();		// a.operator()()
	// a(1, 2);	// a.operator()(1,2)
}