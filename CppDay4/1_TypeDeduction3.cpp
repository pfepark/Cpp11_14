#include <iostream>
#include "boost\type_index.hpp"

using namespace boost;
using namespace boost::typeindex;

// 규칙 2. 인자(T)의 타입이 참조 타입이면 함수 인자가 가지고 있는 참조 속성만 제거된다.
template<typename T> void foo(T& a)
{
	//a = 'a';
	//--a;
	// C++표준 RTTI를 사용해서 타입 구하기. (정확하지 않음)
	//std::cout << typeid(T).name() << ", a : " << typeid(a).name() << std::endl;

	//boost의 type index를 활용해서 타입을 확인하자.
	std::cout << "T : " << type_id_with_cvr<T>().pretty_name() << ", ";
	std::cout << "a : " << type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;
}

template<typename T> void goo(const T& a)
{
	std::cout << "T : " << type_id_with_cvr<T>().pretty_name() << ", ";
	std::cout << "a : " << type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;
}

int main()
{
	int n = 10;
	int&r = n;
	const int c = n;
	const int& cr = c;

	//foo(n);		// T : int			a : int&
	//foo(r);		// T : int			a : int&
	//foo(c);		// T : const int	a : const int&
	//foo(cr);	// T : const int	a : cosnt int&


	goo(n);		// T : 	int		a : const int&
	goo(r);		// T : 	int		a : const int&
	goo(c);		// T : 	int		a : const int&
	goo(cr);	// T : 	int		a : const int&
}