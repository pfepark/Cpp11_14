#include <iostream>

template<typename T>
void print(const T& a)
{
	std::cout << T::N << std::endl;
}

template<typename T, typename U>
struct Duo
{
	T v1;
	U v2;

	enum { N = 2};
};

// 2��° ���ڰ� Duo�϶��� ���� �κ�����ȭ	������� �κ�����ȭ
template<typename A, typename B, typename C>
struct Duo<A, Duo<B, C>>
{
	A			v1;
	Duo<B,C>	v2;

	enum { N = 1 + Duo<B, C>::N };
};


template<typename A, typename B, typename C>
struct Duo<Duo<A, B>, C>
{
	Duo<A, B>	v1;
	C			v2;

	enum { N = 1 + Duo<A, B>::N };
};

template<typename A, typename B, typename C, typename D>
struct Duo<Duo<A, B>, Duo<C, D>>
{
	Duo<A, B>	v1;
	Duo<C, D>	v2;

	enum { N = Duo<A, B>::N + Duo<C, D>::N };
};

int main()
{
	Duo<Duo<int, int>, Duo<int, int>> d4;
	print(d4);		// 4 ������ ���;� �Ѵ�..
}

/*
int main()
{
	Duo<int, int> d2;
	Duo<Duo<int, int>, int> d3;			// ������ Ÿ���� 3�� �ʿ�
	Duo<Duo<Duo<int, int>, int>, int> d4;
	print(d2);		// 2 
	print(d3);		// 3
	print(d4);		// 4 ������ ���;� �Ѵ�..
}
*/
/*
int main()
{
	Duo<int, int> d2;
	Duo<int, Duo<int, int>> d3;			// ������ Ÿ���� 3�� �ʿ�
	Duo<int, Duo<int, Duo<int, int>>> d4;
	print(d2);		// 2
	print(d3);		// 3
	print(d4);		// 4 �� ���;� �Ѵ�..
}
*/