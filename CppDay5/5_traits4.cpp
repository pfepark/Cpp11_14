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

template<typename T> void printv(T a)
{
	if (IsPointer<T>::value)
		std::cout << a << " : " << *a << std::endl;
	else
		std::cout << a << std::endl;
}

int main()
{
	int n = 10;

	printv(n);		// error인데...int 역참조에서 문법오류가 남. 컴파일 타임에 if (false)여서 아래 구문이 삭제 될 것 같지만.. 문법오류 부터 확인하고 최적화를 수행하므로 오류가 난다.
	printv(&n);
}