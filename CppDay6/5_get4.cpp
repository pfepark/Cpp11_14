#include <iostream>

template<typename T, typename ... Types> struct xtuple : public xtuple<Types...>
{
	typedef xtuple<Types...> baseType;
	T value;

	xtuple() {}
	xtuple(const T& a, const Types& ... args) : value(a), baseType(args...) {}

	static constexpr int N = baseType::N + 1;//xtuple<Types...>::N + 1;		// �θ𺸴� 1�� ����.
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
	typedef T type;							// 0��° ����� Ÿ��
	typedef xtuple<T, Types...> tupleType;	// 0��° ��Ҹ� �����ϰ� �ִ� Ʃ�� Ÿ��
};

// N != 0 �϶�
template<int N, typename T, typename ... Types>
struct xtuple_element_type<N, xtuple<T, Types...>>
{
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::type type;
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::tupleType tupleType;
};

//-------------------------------------------
template<typename T> void foo(T& tp)
{
	typename xtuple_element_type<1, T>::type n;		// 1��° ��� Ÿ��
	typename xtuple_element_type<1, T>::tupleType p;	// 1��° ��Ҹ� �����ϴ� �θ�Ÿ��

	std::cout << typeid(n).name() << std::endl;
	std::cout << typeid(p).name() << std::endl;
}

template<int N, typename T>
typename xtuple_element_type<N, T>::type& xget(T& tp)	// T�� �پ��� ����� Ʃ���� �˴ϴ�.
{
	return static_cast<typename xtuple_element_type<N, T>::tupleType&>(tp).value;	// ((N���� �θ� Ÿ��&)tp).value ĳ���� �ʿ�
}

int main()
{
	xtuple<int, double, short> t3(3, 3.4, 5);

	xget<0>(t3) = 20;

	int ret = xget<0>(t3);
	std::cout << ret << std::endl;

	std::cout << xget<1>(t3) << std::endl;
}

