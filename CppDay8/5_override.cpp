#include <iostream>

/*
int n = 0;
const int* p1 = &n;	// p1을 따라가면 const가 있다. p1은 const가 아니다.
int* const p2 = &n; // p2가 const이다.
int const* p3 = &n; // p1과 동일.
*/
// 핵심 : 가상함수 재정의시 실수를 막기 위해서 override를 표시하자.
template<typename T> class Base
{
public:
	// 아래 코드는 'a가 const이다.
	//virtual void foo(const T a)
	virtual void foo(T const a)		// 위 아래 같은 코드인데 아래 재정의시 int*만 붙이면 되니... const를 뒤에 붙이자는 의견도 있음.
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Dericed : public Base<int*>
{
public:
	// foo 재정의 해서 Derived foo 출력해보세요.
	// a를 따라가면 const이다.
	//virtual void foo(const int* a) override
	virtual void foo(int* const a) override
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Dericed;
	p->foo(0);		// "Derived foo" 나오게 해보세요.
}