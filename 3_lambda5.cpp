// 람다표현식을 함수에서 받는 방법
#include <functional>

void foo( int(*f)(int, int) )	// 1. 함수 포인터, 인라인 치환 안됨.
{

}

void foo(std::function<int(int, int)> f)	// 2. STL function 인라인 치환 안됨.
{

}

// 주의 auto는 함수 인자 타입으로 사용될 수 없다.
void foo(auto f)
{

}

template<typename T>		//3.ok 인라인 치환됨
void foo(T f)
{

}

int main()
{
	foo([](int a, int b) {return a + b; });
}