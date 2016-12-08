#include <iostream>

// ������ : data�� �Ѱ��� �����Ѵ�.
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