#include <iostream>

// ������ : data�� �Ѱ��� �����Ѵ�.
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

int main()
{
	// 2�� �θ� : xtuple<short>			// 5����
	// 1�� �θ� : xtuple<double, short> // 3.4����
	xtuple<int, double, short> t3(3, 3.4, 5);

	std::cout << t3.value << std::endl;
	std::cout << (static_cast<xtuple<double, short>&>(t3)).value << std::endl;
	std::cout << (static_cast<xtuple<short>&>(t3)).value << std::endl;

	// ��ǥ
	double ret = xget<1>(t3);
	std::cout << ret << std::endl;	// 3.4
}

template<int N, typename T> Ʃ���� N��° ����� Ÿ��& xget(T& tp)	// T�� �پ��� ����� Ʃ���� �˴ϴ�.
{
	return tp.value;	// ((N���� �θ� Ÿ��&)tp).value ĳ���� �ʿ�
}