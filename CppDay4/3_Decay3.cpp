#include <iostream>
#include "boost\type_index.hpp"

using namespace boost;
using namespace boost::typeindex;

template<typename T> void foo(T a)	// T : int[3] int a[3] = x�� �Ǿ�� �ϴµ�.. �ȵ�. �׷��� T : int*
{
	std::cout << "T : " << type_id_with_cvr<T>().pretty_name() << ", ";
	std::cout << "a : " << type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;
}

template<typename T> void goo(T& a)	// T : int[3] ��� int(&a)[3] = x �̴�.. ok. �׷��� T�� int[3]
{
	std::cout << "T : " << type_id_with_cvr<T>().pretty_name() << ", ";
	std::cout << "a : " << type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;
}

int main()
{
	int x[3] = { 0, 1, 2 };

	foo(x);		// T :
	goo(x);
}