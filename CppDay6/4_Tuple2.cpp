#include <iostream>

// 문제점 : data를 한개만 보관한다.
template<typename T, typename ... Types> struct xtuple
{
	T value;

	xtuple() {}
	xtuple(const T& a) : value(a) {}

	static constexpr int N = 1;
};

int main()
{
	xtuple<int, double, short> t3(3);
}