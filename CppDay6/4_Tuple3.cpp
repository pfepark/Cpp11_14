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

// ���ڰ� �Ѱ��� ���� �Ʒ� ���ø��� ����ϰ� ����.
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