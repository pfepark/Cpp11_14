// traits 1번 복사..

#include <iostream>

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

//포인터의 경우와 포인터가 아닌 경우를 처리하는 함수
template<typename T>
void printv_pointer(T a)
{
	std::cout << a << " : " << *a << std::endl;
}

template<typename T>
void printv_not_pointer(T a)
{
	std::cout << a << std::endl;
}

template<typename T> void printv(T a)
{
	// 핵심 : 사용되지 않는 함수 템플릿은 진짜 함수가 되지 않으므로 컴파일 되지 않는다.. 코드를 안만든다.

	// 하지만 if 문은 실행시간 분기문이므로 if () 구문의 참거짓에 상관없이 
	// 아래 2개의 함수 템플릿이 모두 사용된다고 판단한다.

	// 결국 2개 함수 모두 실제 함수로 생성되므로 실패 - 컴파일 에러.
	if (IsPointer<T>::value)
		printv_pointer(a);
	else
		printv_not_pointer(a);
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}