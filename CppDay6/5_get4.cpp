#include <iostream>

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


template<int N, typename T> struct xtuple_element_type
{
	typedef T type;
};

template<typename T, typename ... Types>
struct xtuple_element_type<0, xtuple<T, Types...>>
{
	typedef T type;							// 0번째 요소의 타입
	typedef xtuple<T, Types...> tupleType;	// 0번째 요소를 저장하고 있는 튜플 타입
};

// N != 0 일때
template<int N, typename T, typename ... Types>
struct xtuple_element_type<N, xtuple<T, Types...>>
{
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::type type;
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::tupleType tupleType;
};

//-------------------------------------------
template<typename T> void foo(T& tp)
{
	typename xtuple_element_type<1, T>::type n;		// 1번째 요소 타입
	typename xtuple_element_type<1, T>::tupleType p;	// 1번째 요소를 저장하는 부모타입

	std::cout << typeid(n).name() << std::endl;
	std::cout << typeid(p).name() << std::endl;
}

template<int N, typename T>
typename xtuple_element_type<N, T>::type& xget(T& tp)	// T는 다양한 모양의 튜플이 됩니다.
{
	return static_cast<typename xtuple_element_type<N, T>::tupleType&>(tp).value;	// ((N번재 부모 타입&)tp).value 캐스팅 필요
}

int main()
{
	xtuple<int, double, short> t3(3, 3.4, 5);

	xget<0>(t3) = 20;

	int ret = xget<0>(t3);
	std::cout << ret << std::endl;

	std::cout << xget<1>(t3) << std::endl;
}

