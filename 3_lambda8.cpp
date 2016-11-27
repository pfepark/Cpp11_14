// 3_람다표현식8

#include <iostream>

int g = 0;

int main()
{
	int v1 = 10;
	int v2 = 10;

	auto f1 = [](int a) {return a + v1; };	// error

	auto f2 = [=](int a) {return a + v1; };	// ok.

	auto f3 = [=](int a) mutable {v1 = 30;  return a + v1; };	// ok.
						// 변경되지만, 복사본 변경

	// capture variable by reference
	auto f4 = [&](int a) {v1 = 30;  return a + v1; };	// ok.

	f4(0);	// 원본 변경

	std::cout << v1 << std::endl;
	/*
	class LambdaClass
	{
		int& v1;
		int& v2;

	public:
		LambdaClass(int& a, int& b) : v1(a), v2(b) {}
		inline int operator()(int a) const
		{
			return a + v1 + v2;
		}
	};
	*/
}
