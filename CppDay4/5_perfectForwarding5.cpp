#include <iostream>

int foo(int a) { return a; }
void goo(int& a) {}
void hoo(int&& a) {}


// ���ٵ� �������� F�� F&&�� �ؾ� �Ѵ�. (���ٴ� �ӽð�ü rvalue�̹Ƿ�..)
template<typename F, typename T> decltype(auto) logTime(F&& f, T&& a)
{
	return f(std::forward<T>(a));
}

int main()
{
	int n;
	//logTime(foo, 10);	// rvalue
	logTime(goo, n);
						

	logTime([](int a) { return a; }, 10);


	std::less<int> f;
	logTime(f, 10);
}