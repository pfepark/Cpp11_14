#include <iostream>
#include <set>
#include <functional>
#include <type_traits>

// C++14 std::remove_point_t ��� �̹� ����.
template<typename T>
using remove_point__t = typename std::remove_pointer<T>::type;

template<typename T> 
void foo(T a)
{
	// T���� �����͸� ������ Ÿ���� ���� n�� ����� ������.
	//typename std::remove_pointer<T>::type n;

	remove_point__t<T> n;
}


int main()
{
	int n = 0;
	foo(&n);
}