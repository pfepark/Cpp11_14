#include <iostream>
#include <set>
#include <functional>
#include <type_traits>

// C++14 std::remove_point_t 라고 이미 있음.
template<typename T>
using remove_point__t = typename std::remove_pointer<T>::type;

template<typename T> 
void foo(T a)
{
	// T에서 포인터를 제거한 타입의 변수 n을 만들어 보세요.
	//typename std::remove_pointer<T>::type n;

	remove_point__t<T> n;
}


int main()
{
	int n = 0;
	foo(&n);
}