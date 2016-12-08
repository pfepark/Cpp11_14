#include <iostream>

int foo(int a, double& d, char c)
{
	std::cout << "foo" << std::endl;
	return 10;
}

template<typename F, typename ... Types> 
decltype(auto) logTime(F&& f, Types&& ... args)
{
	//stop_watch sw;	// 생성자에서 시간 기록 후 소멸자에서 소요된 시간 출력.
	return f(std::forward<Types>(args)...);
}

int main()
{
	double d = 3.4;
	logTime(foo, 5, d, 'A');
}