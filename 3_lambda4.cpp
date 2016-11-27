#include <functional>

// 람다표현식을 담는 변수 - 31page
int main()
{
	auto f1				= [](int a, int b) { return a + b; };

	int(*f2)(int, int)	= [](int a, int b) { return a + b; };
						// class LambdaClass{}; LambdaClass();

	// 3. STL의 function
	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	// 아래 코드들의 인라인 치환성을 생각해보세요
	f1(1, 2);	// 인라인 치환
	f2(1, 2);	// 치환 안됨.
	f3(1, 2);	// 치환 안됨. 가르키는 것을 바꿀 수 있음
}