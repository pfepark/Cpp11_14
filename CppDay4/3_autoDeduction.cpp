#include <iostream>

int main()
{
	int n = 10;
	int& r = n;
	const int c = n;

	// T a  = 함수인자
	auto a1 = n;	// auto : int, a1 : int
	auto a2 = r;	// auto : int, a2 : int
	auto a3 = c;	// auto : int, a3 : int
	a3 = 10;	// ok

	auto& a4 = n;	// auto : int, a4 : int&
	auto& a5 = r;	// auto : int, a5 : int&
	auto& a6 = c;	// auto : const int, a6 : const int&
	//a6 = 10;	// error

	int x[3] = { 1,2,3 };
	auto a7 = x;
	auto& a8 = x;

	std::cout << typeid(a7).name() << std::endl;	// int*
	std::cout << typeid(a8).name() << std::endl;	// int(&)[3] C++ RTTI로는 &가 안보임.
}