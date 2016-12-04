#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) { }

// ��� : ������ �Ϻ��� ������ ���ؼ���

// 1. ���ڸ� ���� �� _T&&(forward reference)_�� �������.

// 2. �����Լ��� ���ڸ� ���� ��  _static_cast<T&&>(arg)_�� ĳ��������.

// ���� ���� : ���ڰ� 1�� �̻��϶� ó��..
//				���ϰ��� ������� �Ѵ�.
// forward<>�� ������ �� �־�� �Ѵ�. - �����غ�����;
template<typename F, typename T>
void logTime(F f, T&& arg)
{
	//f(static_cast<T&&>(arg));
	f(std::forward<T>(arg));	// forward()���� ��ó�� ĳ�����ϰ� �ִ�.
}

int main()
{
	int x = 0;

	logTime(foo, 10);
	logTime(goo, x);	// x : lvalue T : int& arg: int& && => int&
	logTime(hoo, 10);	// 10 : rvalue T:int arg: int&&


	std::cout << x << std::endl;
}