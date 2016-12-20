#include <iostream>
#include <thread>
#include <functional>
#include <vector>

void foo(int a, int& b)
{
	b = 20;
	std::cout << "foo" << std::endl;
}

class Test
{
public:
	Test() {}
	Test(int& a) { a = 20; }
};

int main()
{
	int n = 0;
	std::thread t(&foo, 10, std::ref(n));		// C++11 스레드 클래스, 이 순간 스레드가 생성됩니다.

	t.join();
	std::cout << n << std::endl;
	//---------------------------------------
	std::vector<Test> v;
	v.emplace_back(n);		// n? ref(n)
}