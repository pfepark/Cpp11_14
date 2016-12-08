#include <iostream>

// 1. 해더 포함
#include <type_traits>

template<typename T> void foo_imp(T a, std::true_type)
{
	
}

template<typename T> void foo_imp(T a, std::false_type)
{

}

template<typename T> void foo(T a)
{
	// 2. T가 포인터인지 조사하려면
	// A. is_pointer<T>::value 조사

	if (std::is_pointer<T>::value)
	{
		// 단점 : *a = 10 이 표현은 사용할 수 없습니다.
	}

	// B. *a = 10을 하고 싶으면 함수오버로딩 사용
	foo_imp(a, std::is_pointer<T>());
}

// Loki 라이브러리 참조..

int main()
{
	int n = 0;
	foo(n);
}