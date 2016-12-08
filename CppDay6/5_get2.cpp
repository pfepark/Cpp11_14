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

template<typename T> struct xtuple<T>
{
	T value;
	xtuple() {}
	xtuple(const T& a) : value(a) {}
	static constexpr int N = 1;
};

int main()
{
	// 2차 부모 : xtuple<short>			// 5보관
	// 1차 부모 : xtuple<double, short> // 3.4보관
	xtuple<int, double, short> t3(3, 3.4, 5);

	std::cout << t3.value << std::endl;
	std::cout << (static_cast<xtuple<double, short>&>(t3)).value << std::endl;
	std::cout << (static_cast<xtuple<short>&>(t3)).value << std::endl;

	// 목표
	double ret = xget<1>(t3);
	std::cout << ret << std::endl;	// 3.4
}

template<int N, typename T> 튜플의 N번째 요소의 타입& xget(T& tp)	// T는 다양한 모양의 튜플이 됩니다.
{
	return tp.value;	// ((N번재 부모 타입&)tp).value 캐스팅 필요
}