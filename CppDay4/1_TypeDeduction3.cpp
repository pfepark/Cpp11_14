#include <iostream>
#include "boost\type_index.hpp"

using namespace boost;
using namespace boost::typeindex;

// ��Ģ 2. ����(T)�� Ÿ���� ���� Ÿ���̸� �Լ� ���ڰ� ������ �ִ� ���� �Ӽ��� ���ŵȴ�.
template<typename T> void foo(T& a)
{
	//a = 'a';
	//--a;
	// C++ǥ�� RTTI�� ����ؼ� Ÿ�� ���ϱ�. (��Ȯ���� ����)
	//std::cout << typeid(T).name() << ", a : " << typeid(a).name() << std::endl;

	//boost�� type index�� Ȱ���ؼ� Ÿ���� Ȯ������.
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