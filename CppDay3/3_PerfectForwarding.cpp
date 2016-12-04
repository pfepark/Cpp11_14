#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }

// perfect forwarding : ���� �Լ��� ���� �� ���ڸ� �����Լ����� �Ϻ��ϰ� �����ϴ� ���
// Ư�� �Լ��� ����ð��� �����ϴ� �Լ�
template<typename F, typename A>
void logTime(F f, A& arg)
{
	// �ð� ���
	f(arg);
	// ���� �ð� ���
}

int main()
{
	int x = 0;

	logTime(foo, 10);	//foo(10);		// foo, goo �Լ��� ���� ������ ��Ȯ�ϰ� ó������ �ʴ´�...
	//logTime(goo, x);

	std::cout << x << std::endl;
}