#include <iostream>

// 문제점 : data를 한개만 보관한다.
template<typename T, typename ... Types> struct xtuple : public xtuple<Types...>
{
	typedef xtuple<Types...> baseType;
	T value;

	xtuple() {}
	xtuple(const T& a, const Types& ... args) : value(a), baseType(args...) {}

	static constexpr int N = baseType::N + 1;//xtuple<Types...>::N + 1;		// 부모보다 1개 많다.
};

// 인자가 한개인 경우는 아래 템플릿을 사용하게 하자.
template<typename T> struct xtuple<T>
{
	T value;
	xtuple() {}
	xtuple(const T& a) : value(a) {}
	static constexpr int N = 1;
};

int main()
{
	xtuple<int, double, short> t3(3, 3.4, 1);

	int a = t3.value;
}