#include <iostream>

template<typename T> void printv(T a)
{
	if (T is Pointer)
		std::cout << a << " : " << *a << std::endl;
	else
		std::cout << a << std::endl;
}

int main()
{
	int n = 10;
	double d = 3.3;

	printv(n);
	printv(d);
	printv(&n);
}