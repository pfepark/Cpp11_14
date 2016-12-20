//1_begin.cpp
#include <iostream>
#include <vector>
#include <type_traits>

// 멤버가 아닌 일반함수 begin(), end()
template<typename T> auto xbegin(T& c)
{
	return c.begin();
}

template<typename T> auto xend(T& c)
{
	return c.end();
}

// 배열 버전
template<typename T, int N> auto xbegin(T(&c)[N])
{
	return c;
}

template<typename T, int N> auto xend(T(&c)[N])
{
	return c + N;
}

template<typename T> void show(T& c)
{
	/*
	auto p = xbegin(c);

	while (p != xend(c))
	{
		std::cout << *p << " ";
		++p;
	}
	std::cout << std::endl;
	*/
	for (auto n : c)
		std::cout << n << " ";
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	show(v);

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	show(x);
}