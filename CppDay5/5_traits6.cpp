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

// 함수오버로딩시 함수 선택은 컴파일 시간에 결정된다!!
// 선택되지 않은 함수 템플릿은 인스턴스화 되지 않는다.

template<typename T>
void printv_imp(T a, YES)
{
	std::cout << a << " : " << *a << std::endl;
}

template<typename T>
void printv_imp(T a, NO)
{
	std::cout << a << std::endl;
}

template<typename T> void printv(T a)
{
	// 포인터 여부에 따라 오버로딩 함수 선택
	printv_imp(a, IsPointer<T>::value);		// 포인터라면 참 (1)
											//     아니면 거짓 (0)
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}