#include <iostream>
#include <functional>

using namespace std::placeholders;	// C++ bind() 사용하기 위해

void foo(int a, int& b)
{
	std::cout << a << " ";
	std::cout << "foo" << std::endl;
	b = 20;
}

int main()
{
	std::function<void(int)> f;
	
		int n = 0;
		//logTime(foo, 10, n);	// 이 코드의 수행이 종료 되면 이미 foo는 수행되었습니다.
								// foo 수행중 n이 파괴되지 않습니다.
		f = std::bind(&foo, _1, n); // _1 : f를 사용할때 1번째 인자
									// bind는 고정될 인자를 보관할대 값으로 보관하고 있습니다.
									// 그래서 n이 보관될때 값을 보관하고 있게 됩니다.
	
	

	f(10);		// foo(10, n)

	std::cout << n << std::endl;
}