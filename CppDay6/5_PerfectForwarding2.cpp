#include <iostream>

int foo(int a, double& d, char c)
{
	std::cout << "foo" << std::endl;
	return 10;
}

template<typename F, typename ... Types> 
decltype(auto) logTime(F&& f, Types&& ... args)
{
	//stop_watch sw;	// �����ڿ��� �ð� ��� �� �Ҹ��ڿ��� �ҿ�� �ð� ���.
	return f(std::forward<Types>(args)...);
}

int main()
{
	double d = 3.4;
	logTime(foo, 5, d, 'A');
}