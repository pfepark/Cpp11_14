#include <iostream>

// 가변인자 템플릿을 사용한 C++11 표준인 튜플 만들기
// 문제점 : 모든 인자가 가변인자 이므로 전달된 타입을 꺼낼 수 없다.!
template<typename ... Types> class xtuple
{

};

template<typename T, typename ... Types> class xtuple
{

};

int main()
{
	xtuple<int, double, short> t3;
}