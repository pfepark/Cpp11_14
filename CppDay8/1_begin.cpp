//1_begin.cpp
#include <iostream>
#include <vector>
#include <type_traits>

template<typename T> void show_imp(T& c, std::false_type)
{
	auto p = c.begin();

	while (p != c.end())
	{
		std::cout << *p << std::endl;
		++p;
	}
}

template<typename T> void show_imp(T& c, std::true_type)
{
	auto p = c;

	while (p != c + std::extent<T, 0>::value)
	{
		std::cout << *p << std::endl;
		++p;
	}
}

template<typename T> void show(T& c)
{
	show_imp(c, std::is_array<T>());
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	show(v);

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	show(x);
}