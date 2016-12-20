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
	std::thread t(&foo, 10, std::ref(n));		// C++11 ������ Ŭ����, �� ���� �����尡 �����˴ϴ�.

	t.join();
	std::cout << n << std::endl;
	//---------------------------------------
	std::vector<Test> v;
	v.emplace_back(n);		// n? ref(n)
}