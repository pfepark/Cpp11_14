#include <iostream>

template<typename T> void foo(T a)
{
	while (a--) {}	// 임의의 작업을 수행.
}

int main()
{
	int n = 5;
	foo(n);		// T는 int

	int& r = n;
	foo(r);		// T는 ?

	const int c = n;
	foo(c);		// T는 ?
}