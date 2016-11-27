#include <algorithm>
#include <functional>	// less<>, greater<> 등의 함수객체가 있음

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// 1. 함수를 사용한 정책 변경
	std::sort(x, x + _countof(x), cmp1);

	// 2. 함수객체를 사용한 정책 변경
	std::less<int> f;
	std::sort(x, x + _countof(x), f);

	// 3. C++11의 람다 표현식을 사용한 정책 변경
	// [] : Lambda introducer
	std::sort(x, x + _countof(x), [](int a, int b) {return a < b; });

	// 위 한줄은 컴파일러가 아래 코드를 생성
	class LambdaClass
	{
	public:
		inline bool operator()(int a, int b) const	// 상수함수!!
		{
			return a < b;
		}
	};

	//LambdaClass closure;
	//std::sort(x, x + _countof(x), closure);
	std::sort(x, x + _countof(x), LambdaClass()); // ClassName() : 임시객체 생성
}
