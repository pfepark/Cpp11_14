#include <iostream>

// C++11에서는 int2type을 발전시킨 아래 템플릿이 있습니다.
//template<typename T, T N> struct integral_constant
//{
//	static constexpr T value = N;
//};

//integral_constant<int, 0> t0;
//integral_constant<int, 1> t1;
//integral_constant<short, 0> s0;
//integral_constant<short, 0> s1;

// true/false			: 참 거짓을 나타내는 값, 같은 타입
// true_type/false_type : 참 거짓을 나타내는 타입, 다른 타입
//typedef integral_constant<bool, true> true_type;
//typedef integral_constant<bool, false> false_type;

#include <type_traits>

// 표준에 있는 is_pointer는 아래 처럼 구현됩니다. 부모가 value를 가지고 있음.
//template<typename T>
//struct is_pointer : false_type		// 상속
//{
//};
//
//template<typename T>
//struct is_pointer<T*> : true_type {};


template<typename T>
void printv_imp(T a, std::true_type)
{
	std::cout << a << " : " << *a << std::endl;
}

template<typename T>
void printv_imp(T a, std::false_type)
{
	std::cout << a << std::endl;
}

template<typename T> void printv(T a)
{
	// 포인터 여부에 따라 오버로딩 함수 선택
	printv_imp(a, std::is_pointer<T>());
}

int main()
{
	int n = 10;

	printv(n);
}