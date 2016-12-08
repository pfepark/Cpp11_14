#include <iostream>

// T가 포인터인지 조사하는 기술

// traits : T의 타양한 특성을 조사하는 기술

// 1. primary template : false 리턴(value = false 라는 의미)
// 2. 부분 전문화		: true 리턴(value = true 라는 의미)
template<typename T>
struct IsPointer
{
	//enum { value = false };				// 예전 스타일
	static constexpr bool value = false;	// 최신 스타일
};

template<typename T>
struct IsPointer<T*>
{
	//enum { value = true };				// 예전 스타일
	static constexpr bool value = true;		// 최신 스타일
};

template<typename T> void foo(T a)
{
	if (IsPointer<T>::value)
		std::cout << "Pointer" << std::endl;
	else
		std::cout << "not Pointer" << std::endl;
}

int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}