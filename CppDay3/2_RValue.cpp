#include <iostream>

int x = 10;
int	 foo() { return x; }
int& goo() { return x; }

// lvalue : =�� ���ʰ� �����ʿ� ��ο� �� �ִ�. 
//			�̸��� �ִ�. ���Ͻ��� �Ѿ �޸𸮿� ����.
//			������ �����ϴ� �Լ�
//			�ּҿ����ڷ� �ּҸ� ���� �� �ִ�.

// rvalue : =�� �����ʿ��� �� �� �ִ�.
//			�̸��� ����. ���ϽĿ����� ���.
//			���� �����ϴ� �Լ�
//			�ּҿ����ڷ� �ּҸ� ���� �� ����.
//			�ӽð�ü, literal
int main()
{
	int v1 = 10;
	int v2 = 20;

	v1 = 10;
	//10 = v2;	// error
	v2 = v1;

	//foo() = 20;	// error
	goo() = 20;	// ok.
	std::cout << &v1 << std::endl;
	//std::cout << &10 << std::endl;

	const int c = 10;
	//c = 20;		// error. c�� nonmodified lvalue.

	// rvalue�� ����̴�. ?
	Point(1, 2).x = 10;		// error
	Point(1, 2).Set(10, 20)	// ok. �ӽð�ü�� ��� �Լ��� ȣ���ؼ� ���� ���� �� �� �ִ�.
							// �׷��Ƿ� rvalue�� ��� ����� ���� �ƴϴ�.
}