#include <iostream>

// 중요함. 전설의 레전드.
template<int N> struct int2type
{
	enum { value = N};
};

template<typename T>
struct IsPointer
{
	static constexpr bool value = false;
};

template<typename T>
struct IsPointer<T*>
{
	static constexpr bool value = true;
};
/*
int main()
{
	foo(0);
	foo(1);	// 0, 1은 같은 타입. 그러므로 foo(0), foo(1)은 같은 foo 함수를 호출한다.

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1);	// t0, t1은 다른 타입이므로 foo(t0), foo(t1)은 다른 함수 호출
}
*/

template<typename T>
void printv_imp(T a, int2type<1>)
{
	std::cout << a << " : " << *a << std::endl;
}

template<typename T>
void printv_imp(T a, int2type<0>)
{
	std::cout << a << std::endl;
}

template<typename T> void printv(T a)
{
	// 포인터 여부에 따라 오버로딩 함수 선택
	printv_imp(a, int2type<IsPointer<T>::value>() );		
}

void func1(int2type<1> a)
{
	std::cout << "int2type<1>" << std::endl;
}

int main()
{
	int n = 10;

	printv(n);

	int2type<1> a1;
	int2type<1> a2;

	func1(a1);
	func1(a2);

	
}