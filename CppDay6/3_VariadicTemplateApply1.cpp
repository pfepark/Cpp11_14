// 3_가변인자 템플릿 활용
#include <iostream>

// 숙제 답
template<typename T> struct xremove_pointer
{
	typedef T type;
};

template<typename T> struct xremove_pointer<T*>
{
	//typedef T type;

	typedef typename xremove_pointer<T>::type type;
};

int main()
{
	xremove_pointer<int***>::type n;

	std::cout << typeid(n).name() << std::endl;
}