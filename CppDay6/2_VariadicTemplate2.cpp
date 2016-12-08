#include <iostream>

void goo(int a, double d, const char* s)
{
	std::cout << "goo" << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : parameter pack �̶�� �θ��ϴ�.
	std::cout << sizeof...(args) << std::endl;
	std::cout << sizeof...(Types) << std::endl;

	// pack expansion : parameter pack�� Ǯ���� �ٸ� �Լ��� ������ ���
	goo(args...);		// ... ��ġ ����� �μ���.
						// goo(3, 4.5, "hello")
}

int main()
{
	foo(3, 4.5, "hello");
}