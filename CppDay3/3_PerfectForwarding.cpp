#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }

// perfect forwarding : 래퍼 함수를 만들 때 인자를 원본함수에게 완벽하게 전달하는 기술
// 특정 함수의 수행시간을 측정하는 함수
template<typename F, typename A>
void logTime(F f, A& arg)
{
	// 시간 기록
	f(arg);
	// 수행 시간 출력
}

int main()
{
	int x = 0;

	logTime(foo, 10);	//foo(10);		// foo, goo 함수가 인자 전달이 정확하게 처리되지 않는다...
	//logTime(goo, x);

	std::cout << x << std::endl;
}