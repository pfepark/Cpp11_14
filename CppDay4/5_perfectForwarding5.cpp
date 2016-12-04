#include <iostream>

int foo(int a) { return a; }
void goo(int& a) {}
void hoo(int&& a) {}


// 람다도 받으려면 F도 F&&로 해야 한다. (람다는 임시객체 rvalue이므로..)
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