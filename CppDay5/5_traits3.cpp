#include <iostream>

int a;	// int
int* p;	// int*
int x[3];	// int[3] type, 	int[] -> unknow size array type

template<typename T>
struct IsArray
{
	static constexpr bool value = false;
	static constexpr int size = -1;
};

template<typename T, int N>
struct IsArray<T[N]>
{
	static constexpr bool value = true;	
	static constexpr int size = N;
};

template<typename T> void foo(T& a)
{
	if (IsArray<T>::value)
		std::cout << "Array : " << IsArray<T>::size << std::endl;
	else
		std::cout << "not Array" << std::endl;
}

int main()
{
	int x[] = { 12,3,4 };
	foo(x);
}