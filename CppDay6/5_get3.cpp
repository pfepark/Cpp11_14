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


// 1. 사용할 때의 모양을 참고해서 primary tempalte 만들기
template<int N, typename T> struct xtuple_element_type
{
	typedef T type;
};

// 2. T 라는 튜플 타입을 => xtuple<T, Types...>으로 분할해서 우리가 원하는 타입을 꺼내야한다.
//	 또한 N == 0일때로 한정해서 생각해야 한다.
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

template<typename T> void foo(T& tp)
{
	// T는 임의의 갯수를 가진 xtuple 입니다.
	typename xtuple_element_type<1, T>::type n;		// 1번째 요소 타입
	typename xtuple_element_type<1, T>::tupleType p;	// 1번째 요소를 저장하는 부모타입

	std::cout << typeid(n).name() << std::endl;
	std::cout << typeid(p).name() << std::endl;
}

int main()
{
	xtuple<int, double, short> t3(3, 3.4, 5);

	foo(t3);
}

